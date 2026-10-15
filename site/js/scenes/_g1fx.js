// _g1fx: scene-specific helpers of scene 0/1: the two plasma-wipe warp-mesh generators (0x1d200, 0x1d3d8).
// Both fill the 26x41 node table (3 dwords/node: u*2^19, v*2^19 (24 bit), 0) consumed by gridWarpTex8 (fx2d 0x1e266).
import { rint } from '../lib/fx2d-mesh.js';
const F = Math.fround, S = Math.sin, C = Math.cos;

/** ported from func_1d200 (0x1d200): wobbling inverse-distance "fisheye" lens mesh (the plasma texture is sampled through a rotating, breathing lens).
 *  x87 detail: the rotation angle `a` is stored as float (for sin) but its cosine is taken from the unrounded 80-bit value. */
export function warpMeshLens(out, T) {
  const a = S(S(T * 0.013) + T * 0.012) * 3, c = F(C(a)), s = F(S(F(a)));
  const k38 = F(S(T * 0.12) * 0.01 + 0.09);
  const k30 = F(S(T * 0.05 - S(T * 0.02)) * 6), k34 = F(C(T * 0.063 - S(T * 0.026)) * 6);
  const k40 = F(S(T * 0.09) * 0.9 + 1), k3c = F(S(T * 0.07) * 0.9 + 1);
  let o = 0;
  for (let iy = -13; iy < 13; iy++) for (let ix = -20; ix < 21; ix++) {
    const A = iy * 1.2, B = ix + k30, Ap = A + k34, Af = F(Ap);
    const x32 = F(B * c - Ap * s), y32 = F(B * s + Af * c);
    const r = 1 / ((Af * Af * k3c + B * B * k40) * 0.001 + k38);
    out[o++] = rint(F(x32 * r) * 524288) & 0xffffff; out[o++] = rint(F(r * y32) * 524288) & 0xffffff; out[o++] = 0;
  }
}
export const f_1d200 = warpMeshLens;

/** ported from func_1d3d8 (0x1d3d8): same idea with two independent lenses (one for u, one for v) and u scrolling by T*0.1: used for the inverting plasma mask. */
export function warpMeshLens2(out, T) {
  const a = S(S(T * 0.013) + T * 0.012) * 3, c = F(C(a)), s = F(S(F(a)));
  const k48 = F(S(T * 0.12) * 0.01 + 0.3), k38 = k48;
  const k58 = F(S(T * 0.02 - S(T * 0.02)) * 16), k50 = F(C(T * 0.033 - S(T * 0.026)) * 16);
  const k3c = F(S(T * 0.09) * 0.9 + 1), k40 = F(S(T * 0.07) * 0.1 + 0.5);
  const k54 = F(S(T * 0.03 - S(T * 0.04)) * 16), k4c = F(C(T * 0.023 - S(T * 0.016)) * 16);
  const k44 = F(S(T * 0.04) * 0.9 + 1), k5c = F(S(T * 0.05) * 0.1 + 0.5);
  let o = 0;
  for (let iy = -13; iy < 13; iy++) for (let ix = -20; ix < 21; ix++) {
    const A32 = F(iy * 1.2), B = ix + k58, Bc = B * c, App = A32 + k50, Af = F(App);
    const X32 = F(Bc - App * s), Y32 = F(B * s + Af * c);
    const r1 = F(1 / ((B * B * k3c + Af * Af * k40) * 0.001 + k48));
    const B2 = ix + k54, A2 = A32 + k4c;
    const r2 = 1 / ((B2 * B2 * k44 + A2 * A2 * k5c) * 0.001 + k38);
    const xo = F(X32 * r1 + T * 0.1), yo = F(r2 * Y32);
    out[o++] = rint(xo * 524288) & 0xffffff; out[o++] = rint(yo * 524288) & 0xffffff; out[o++] = 0;
  }
}
export const f_1d3d8 = warpMeshLens2;
