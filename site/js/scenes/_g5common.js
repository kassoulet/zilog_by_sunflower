// _g5common.js -- shared setup for scenes 8, 9 and the credits loop (main() = func_100d3, orders 41..59).
// Everything main() builds before its first loop that these scenes need (luts, fonts, spot sprite table, ray tables, colour LUT)
// is built lazily once and cached in env.shared.g5.
import { loadMesh, makeLuts, makeRenderContext, Obj3D } from '../lib/mesh3d.js';
import { radialCosSpot, radialRayTables, paletteShadeLut, buildFont } from '../lib/fx2d.js';
export const f32 = Math.fround;
export const mesh = (env, name) => loadMesh(env.files.get('3d/' + name + '.mob'));
export function shared(env) {
  env.shared ??= {};
  if (env.shared.g5) return env.shared.g5;
  const g = env.shared.g5 = {};
  Object.assign(g, makeLuts());                                       // DAT_000402f4 / 402f8 (0x14834)
  g.spot = new Uint8Array(65536); radialCosSpot(g.spot);              // 0x14639: soft round sprite (DAT at ebp-0xc8)
  g.vsm = buildFont(env.gfx('fonts/verd_sm.gfx'), 0x21, 0x5e);       // ebp-0x8c
  g.verdana = buildFont(env.gfx('fonts/verdana.gfx'), 0x21, 0x5e);   // ebp-0x90
  return g;
}
/** ray tables of 0x14d0b (needed for the radial blur of scene 8's intro) and the pal.sc colour LUT of 0x15168 */
export function introTables(env) {
  const g = shared(env);
  if (g.rays) return g;
  g.rays = new Uint16Array(0x17800 + 256); g.pairs = new Uint16Array(0x13880 * 2);
  g.npairs = radialRayTables(g.rays, g.pairs, new Uint8Array(64000));
  g.pal = new Uint32Array(65536); paletteShadeLut(g.pal, env.files.get('pal.sc').subarray(10, 10 + 768));
  return g;
}
/** demo time DAT_00040310 as the float the original holds: ticks*0.25 - base */
export const timeOf = (st, base) => f32(st.ticks * 0.25 - base);
/** DAT_00040314 as set by scene 7 (`_DAT_00040314 = ticks*0.25` at the start of its loop, music order 35 = 122.898 s, 70 Hz ticks); scenes 8 and 9 do not re-base */
export const BASE7 = 122.898 * 70 * 0.25;
export const ctxFor = (target, g) => { const c = makeRenderContext(target, { lut1: g.lut1, lut2: g.lut2 }); return c; };
export { Obj3D };
/** x87 compare-and-clamp helpers used all over main(): value = max(0, v) */
export const ftrunc = (x) => Math.trunc(x);
