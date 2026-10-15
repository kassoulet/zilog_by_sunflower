// _g3.js: scene-specific helpers of scenes 4 and 5 (main() loops `<0x1b` and `<0x1f`).
const f32 = Math.fround;

/**
 * ported from func_21290 (0x21290): "cone swirl" point animator of scene 5.  The cones3 mesh has groups of 9 points
 * (a ring); per group k = trunc(z0 - 500) (z of the group's first point) drives a time dependent rotation angle / centre /
 * scale, every point of the group is then scaled about the centre, rotated in the XY plane and gets z = 200*cos(0.04 t + 0.008 k).
 * Reads mesh.pts, writes mesh.xpts.  `t` = DAT_00040310 (float32 time).  Intermediates are x87 80-bit in the original,
 * doubles here; stores to the stack are float32 (f32).
 * @param {{npts:number, pts:Float32Array, xpts:Float32Array}} m  @param {number} t
 */
export function coneWarp(m, t) {
  const { pts, xpts } = m, n = m.npts;
  for (let g = 0; g < n; g += 9) {
    const k = Math.trunc(pts[g * 3 + 2] - 500);                         // fadd -500, ftrunc, fistp
    const ang = f32(Math.cos(Math.sin(t * 0.032) + t * 0.02) + Math.sin(t * 0.01) * k * 0.01);   // fst dword [esp+2c]: float32, but fsin of the 80-bit value
    const angx = Math.cos(Math.sin(t * 0.032) + t * 0.02) + Math.sin(t * 0.01) * k * 0.01;
    const sa = f32(Math.sin(angx)), ca = f32(Math.cos(ang));
    const f2 = f32(Math.sin(t * 0.13) * (Math.cos(t * 0.01) * 10 * k * 0.004));
    const f3 = f32(Math.sin(t * 0.07) * 10 * k * 0.004);
    const q = k * 0.0001;
    const w1 = f32(Math.sin(t * 0.033 - q) * 0.7 * k * 0.01);
    const w2 = f32(Math.cos(t * 0.014 - q) * 0.7 * k * 0.01);
    const z = f32(Math.cos(t * 0.04 + k * 0.008) * 200);
    for (let i = g; i < g + 9 && i < n; i++) {
      const fx = f32((pts[i * 3] - f2) * w1), fy = f32((pts[i * 3 + 1] - f3) * w2);
      xpts[i * 3] = f32(fx * ca + f2 + fy * sa);
      xpts[i * 3 + 2] = z;
      xpts[i * 3 + 1] = f32((fx * sa + f3) - fy * ca);
    }
  }
}
export const f_21290 = coneWarp;

import { loadMesh, makeLuts } from '../lib/mesh3d.js';
import { buildFont, colorMatrixTables, radialCosSpot } from '../lib/fx2d.js';
/** lazily built things shared by scene 4/5 (cached on env.shared.g3). */
export function shared(env) {
  const s = (env.shared ??= {});
  if (s.g3) return s.g3;
  const g = (s.g3 = { luts: s.luts ?? (s.luts = makeLuts()) });
  g.font = buildFont(env.gfx('fonts/cupertin.gfx'), 0x21, 0x5e);       // uStack_9c
  g.matrix = new Int32Array(9 * 256); colorMatrixTables(g.matrix);       // uStack_4c (0x148c4)
  g.spot = new Uint8Array(65536); radialCosSpot(g.spot);                  // puStack_dc (0x14639)
  g.mesh = (n) => loadMesh(env.files.get(n));
  return g;
}
/** sprintf("%x") of a 32 bit two's complement int */
export const hex32 = (v) => (v >>> 0).toString(16);
/** float32 time like func_10061: DAT_00040310 = ticks*0.25 - DAT_00040314 */
export const timeOf = (ticks, base) => f32(ticks * 0.25 - base);
