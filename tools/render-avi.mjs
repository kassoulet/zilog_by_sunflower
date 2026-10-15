// Offline render of the whole demo -> ZMBV AVI (lossless 32bpp, 70 fps = original timer rate) + PCM audio.
// usage: node tools/render-avi.mjs [out.avi] [fps=70]
import fs from 'fs'; import os from 'os'; import path from 'path'; import { spawn } from 'child_process';
import { makeEnv, setFrame } from '../site/js/env.js';
import { UsmPlayer } from '../site/js/music/usm.js';
import { SCENES } from '../site/js/scenes-info.js';
const out = process.argv[2] || 'zilog.avi', FPS = +(process.argv[3] || 70), TICK = 70;
const env = makeEnv(new Uint8Array(fs.readFileSync(new URL('../site/data/data.dat', import.meta.url))));
const ana = env.files.get('music/ana.u'), tl = new UsmPlayer(ana, 44100).timeline(), END = tl.duration;
const scenes = await Promise.all(SCENES.map((_, i) => import(i === 10 ? '../site/js/scenes/_g5final.js' : `../site/js/scenes/scene${i}.js`).then(m => m.createScene(env))));
// audio: whole song as 16-bit stereo WAV
const wav = path.join(os.tmpdir(), 'zilog_audio.wav'), pl = new UsmPlayer(ana, 44100), N = Math.ceil(END * 44100), pcm = Buffer.alloc(N * 4);
for (let done = 0; done < N;) { const n = Math.min(4096, N - done), { left, right } = pl.render(n);
  for (let i = 0; i < n; i++) { pcm.writeInt16LE(Math.max(-32768, Math.min(32767, Math.round(left[i] * 32767))), (done + i) * 4); pcm.writeInt16LE(Math.max(-32768, Math.min(32767, Math.round(right[i] * 32767))), (done + i) * 4 + 2); } done += n; }
const h = Buffer.alloc(44); h.write('RIFF', 0); h.writeUInt32LE(36 + pcm.length, 4); h.write('WAVEfmt ', 8); h.writeUInt32LE(16, 16); h.writeUInt16LE(1, 20); h.writeUInt16LE(2, 22);
h.writeUInt32LE(44100, 24); h.writeUInt32LE(44100 * 4, 28); h.writeUInt16LE(4, 32); h.writeUInt16LE(16, 34); h.write('data', 36); h.writeUInt32LE(pcm.length, 40);
fs.writeFileSync(wav, Buffer.concat([h, pcm]));
const ff = spawn('ffmpeg', ['-loglevel', 'error', '-y', '-f', 'rawvideo', '-pix_fmt', 'bgr0', '-s', '320x200', '-framerate', String(FPS), '-i', '-', '-i', wav,
  '-c:v', 'zmbv', '-c:a', 'pcm_s16le', '-shortest', out], { stdio: ['pipe', 'inherit', 'inherit'] });
let cur = -1; const frames = Math.floor(END * FPS);
for (let n = 0; n < frames; n++) {
  const t = n / FPS, pos = tl.positionAt(t), si = SCENES.findIndex(x => pos.order >= x.start && pos.order < x.end), ticks = Math.floor(t * TICK), sy = tl.syncAt(t);
  if (si !== cur && si >= 0) { cur = si; env.st.ticks = ticks - 1; scenes[si].init?.(); }
  setFrame(env, ticks, pos.order, pos.row, sy.value, sy.count);
  if (si >= 0) scenes[si].frame(env.st);
  if (!ff.stdin.write(Buffer.from(env.scr.buffer.slice(0)))) await new Promise(r => ff.stdin.once('drain', r));
  if (n % 1400 === 0) console.log(`${(t).toFixed(0)}s / ${END.toFixed(0)}s  scene ${si}`);
}
ff.stdin.end(); await new Promise(r => ff.on('close', r)); fs.unlinkSync(wav); console.log('wrote', out, frames, 'frames');
