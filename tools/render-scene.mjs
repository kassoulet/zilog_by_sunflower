// Render frames of a scene module to PNG for visual comparison with the reference video.
// usage: node tools/render-scene.mjs <scene.js path> <startTick> <endTick> <stepTicks> <outDir> [order row]
//   The scene module must export createScene(env) -> {init?(), frame(st)}. Music position is fed from args (default: order from scene.orderStart).
import fs from 'fs'; import path from 'path'; import zlib from 'zlib';
import { makeEnv, setFrame } from '../site/js/env.js';
const [scenePath, t0, t1, step, outDir, order0, row0] = process.argv.slice(2);
function crc32(b) { let c, crc = ~0; for (let i = 0; i < b.length; i++) { c = (crc ^ b[i]) & 255; for (let k = 0; k < 8; k++) c = c & 1 ? 0xedb88320 ^ (c >>> 1) : c >>> 1; crc = (crc >>> 8) ^ c; } return ~crc >>> 0; }
export function png(rgb, w, h) {
  const raw = Buffer.alloc((w * 3 + 1) * h); for (let y = 0; y < h; y++) { raw[y * (w * 3 + 1)] = 0; rgb.copy(raw, y * (w * 3 + 1) + 1, y * w * 3, (y + 1) * w * 3); }
  const chunk = (t, d) => { const l = Buffer.alloc(4); l.writeUInt32BE(d.length); const td = Buffer.concat([Buffer.from(t), d]); const c = Buffer.alloc(4); c.writeUInt32BE(crc32(td)); return Buffer.concat([l, td, c]); };
  const ih = Buffer.alloc(13); ih.writeUInt32BE(w, 0); ih.writeUInt32BE(h, 4); ih[8] = 8; ih[9] = 2;
  return Buffer.concat([Buffer.from([137, 80, 78, 71, 13, 10, 26, 10]), chunk('IHDR', ih), chunk('IDAT', zlib.deflateSync(raw)), chunk('IEND', Buffer.alloc(0))]);
}
export function screenToPng(scr) {   // dword 0x00RRGGBB -> R=byte2
  const rgb = Buffer.alloc(320 * 200 * 3); for (let i = 0; i < 64000; i++) { const v = scr[i]; rgb[i * 3] = v >> 16 & 255; rgb[i * 3 + 1] = v >> 8 & 255; rgb[i * 3 + 2] = v & 255; }
  return png(rgb, 320, 200);
}
if (scenePath) {
  const env = makeEnv(new Uint8Array(fs.readFileSync(new URL('../site/data/data.dat', import.meta.url))));
  const mod = await import(path.resolve(scenePath)); const sc = mod.createScene(env); await sc.init?.();
  fs.mkdirSync(outDir, { recursive: true });
  let order = +(order0 ?? sc.orderStart ?? 0), row = +(row0 ?? 0);
  for (let t = +t0; t <= +t1; t += +step) {
    setFrame(env, t, order, row, 0, 0, +t0 * 0.25 * 0);
    sc.frame(env.st);
    fs.writeFileSync(path.join(outDir, `f${String(t).padStart(6, '0')}.png`), screenToPng(env.scr));
  }
  console.log('rendered to', outDir);
}
