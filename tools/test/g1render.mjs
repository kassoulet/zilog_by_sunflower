// node tools/test/g1render.mjs <sceneN> <outDir> [stepSec=1] [dtTicks=4]   render scene frames driven by the real music timeline
import fs from 'fs'; import path from 'path';
import { makeEnv, setFrame } from '../../site/js/env.js';
import { UsmPlayer } from '../../site/js/music/usm.js';
const [name, out, stepS = '1', dtT = '4'] = process.argv.slice(2);
process.argv.length = 2;   // render-scene.mjs runs its CLI when argv[2] is set
const { screenToPng } = await import('../render-scene.mjs');
const env = makeEnv(new Uint8Array(fs.readFileSync(new URL('../../site/data/data.dat', import.meta.url))));
const tl = new UsmPlayer(env.files.get('music/ana.u'), 44100).timeline();
const sc = (await import(`../../site/js/scenes/${name}.js`)).createScene(env); await sc.init();
const t0 = tl.orderStart(sc.orderStart) || 0, t1 = tl.orderStart(sc.orderEnd), dt = +dtT, step = +stepS;
fs.mkdirSync(out, { recursive: true });
let next = t0, ticks = Math.round(t0 * 70), n = 0; env.st.ticks = ticks - dt;
const ms0 = Date.now();
for (let t = t0; t < t1; ticks += dt, t = t0 + (ticks - Math.round(t0 * 70)) / 70) {
  const p = tl.positionAt(t), s = tl.syncAt(t);
  setFrame(env, ticks, p.order, p.row, s.value, s.count); sc.frame(env.st); n++;
  if (t >= next) { fs.writeFileSync(path.join(out, `t${(t - t0).toFixed(1).padStart(5, '0')}.png`), screenToPng(env.scr)); next += step; }
}
console.log(name, 'frames', n, 'ms/frame', ((Date.now() - ms0) / n).toFixed(1));
