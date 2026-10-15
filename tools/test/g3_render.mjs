// node g3_render.mjs <scene4|scene5> <outDir> [saveEverySec=1]  -- runs a whole scene with the music timeline (order/row/sync) at 20 fps, saves PNGs
import fs from 'fs'; import path from 'path';
import { makeEnv, setFrame } from '../../site/js/env.js';
import { parseContainer } from '../../site/js/core/assets.js';
import { UsmPlayer } from '../../site/js/music/usm.js';
const [name, outDir, every = '1'] = process.argv.slice(2); process.argv.length = 2;   // render-scene.mjs runs its CLI when argv has args
const { screenToPng } = await import('../render-scene.mjs');
const data = new Uint8Array(fs.readFileSync(new URL('../../site/data/data.dat', import.meta.url)));
const env = makeEnv(data), tl = new UsmPlayer(parseContainer(data).get('music/ana.u'), 44100).timeline();
const sc = (await import(`../../site/js/scenes/${name}.js`)).createScene(env); await sc.init();
fs.mkdirSync(outDir, { recursive: true });
const t0 = tl.orderStart(sc.orderStart), t1 = tl.orderStart(sc.orderEnd);
let n = 0, ticks0 = Math.round(t0 * 70), nextSave = t0;
for (let s = t0; s < t1; s += 0.05, n++) {
  const p = tl.positionAt(s), sy = tl.syncAt(s);
  setFrame(env, Math.round(s * 70), p.order, p.row, sy.value, sy.count);
  sc.frame(env.st);
  if (s >= nextSave) { nextSave += +every; fs.writeFileSync(path.join(outDir, `${name}_${s.toFixed(1)}.png`), screenToPng(env.scr)); }
}
console.log('done', n, 'frames', t0, t1);
