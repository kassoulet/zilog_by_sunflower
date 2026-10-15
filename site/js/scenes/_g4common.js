// Lazily built global resources shared by scenes 6 and 7 (main() builds them once before scene 0: 0x14834 LUTs, 0x14d0b ray tables, 0x15168 palette LUT, fonts).
import { makeLuts } from '../lib/mesh3d.js';
import { radialRayTables, paletteShadeLut, buildFont } from '../lib/fx2d.js';
export function shared(env) {
  const s = env.shared || (env.shared = {});
  s.luts ||= makeLuts();                                   // DAT_000402f4 / 402f8
  return s;
}
export function rays(env) {                                // DAT_? uStack_30 (ray path list), DAT_000402fc (pairs), DAT_00040300 (count)
  const s = shared(env);
  if (!s.rays) {
    const r = new Uint16Array(0x17800 + 64), pairs = new Uint16Array(0x13880 * 2), tmp = new Uint8Array(64000);
    const n = radialRayTables(r, pairs, tmp); s.rays = { rays: r, pairs, npairs: n };
  }
  return s.rays;
}
export function shadeLut(env) {                            // uStack_2c: 256x256 dword LUT from pal.sc (func_15168(…, pal+10))
  const s = shared(env);
  if (!s.shadeLut) { s.shadeLut = new Uint32Array(65536); paletteShadeLut(s.shadeLut, env.files.get('pal.sc').subarray(10, 10 + 768)); }
  return s.shadeLut;
}
export function font(env, name, first = 0x21, n = 0x5e) {
  const s = shared(env); s.fonts ||= {};
  return s.fonts[name] ||= buildFont(env.gfx(name), first, n);
}
/** time variable of the scene: DAT_00040310 = float32(ticks*0.25 - DAT_00040314), DAT_00040314 := ticks*0.25 at the scene start (first frame). */
export function makeClock() {
  let base = null;
  return { reset() { base = null; }, time(st) { if (base === null) base = Math.fround(st.ticks * 0.25); return Math.fround(st.ticks * 0.25 - base); } };
}
