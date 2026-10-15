// Host: loads the asset container, builds env, runs the ported scenes from the music timeline, drives audio.
import { makeEnv, setFrame } from './env.js';
import { UsmPlayer } from './music/usm.js';
import { presentToRGBA } from './lib/fx2d-video.js';
import { SCENES } from './scenes-info.js';

const bytes = new Uint8Array(await (await fetch('data/data.dat')).arrayBuffer());
const env = makeEnv(bytes);
const ana = env.files.get('music/ana.u');
const tl = new UsmPlayer(ana, 44100).timeline();
const END = tl.duration;                             // last loop runs until the end of the song (order 60 / end-of-song flag)
const mods = await Promise.all(SCENES.map((_, i) => import(i === 10 ? './scenes/_g5final.js' : `./scenes/scene${i}.js`).then(m => m.createScene(env)).catch(e => { console.warn('scene', i, 'unavailable:', e.message); return null; })));

let cur = -1, startTick = 0;
function enter(i, tick) { cur = i; startTick = tick; env.st.ticks = tick - 1; /* first frame of a scene sees dt = 1 */ try { mods[i]?.init?.(); } catch (e) { console.error('init scene', i, e); } }

export const demo = {
  duration: END,
  scenes: SCENES,
  secOf: o => tl.orderStart(o),
  positionAt: t => tl.positionAt(t),
  reset(t) { cur = -1; },
  frame(rgba, s) {
    const pos = tl.positionAt(s.t), si = SCENES.findIndex(x => pos.order >= x.start && pos.order < x.end);
    const ticks = Math.floor(s.t * 70), sy = tl.syncAt ? tl.syncAt(s.t) : { value: 0, count: 0 };
    if (si !== cur && si >= 0) enter(si, ticks);
    setFrame(env, ticks, pos.order, pos.row, sy.value, sy.count);
    try { if (si >= 0) mods[si]?.frame(env.st); } catch (e) { console.error('frame scene', si, e); }
    presentToRGBA(env.scr, rgba, 32);
  },
  async audio() {
    const a = { ready: false, time: 0, ctx: null, node: null, base: 0, async init() {
      const ctx = this.ctx = new AudioContext({ sampleRate: 44100 });
      await ctx.audioWorklet.addModule(new URL('./music/usm-worklet.js', import.meta.url));
      const node = this.node = new AudioWorkletNode(ctx, 'usm', { outputChannelCount: [2] }); node.connect(ctx.destination);
      node.port.postMessage({ bytes: ana }); this.ready = true; this.base = 0;
    },
      get time() { return this.ready ? Math.min(END, this.base + this.ctx.currentTime) : 0; },
      resume(t = 0) { if (!this.ready) return this.init().then(() => { this.seek(t); this.resume(t); }); this.node.port.postMessage({ playing: true }); this.ctx.resume(); },
      suspend() { this.node?.port.postMessage({ playing: false }); this.ctx?.suspend(); },
      seek(t) { if (!this.ready) return; const p = tl.positionAt(t); this.node.port.postMessage({ seek: { order: p.order, row: p.row } }); this.base = t - this.ctx.currentTime; } };
    return a;
  },
};
