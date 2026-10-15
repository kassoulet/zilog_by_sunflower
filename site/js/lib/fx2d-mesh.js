// fx2d-mesh: generators of the 41x26 warp-mesh node tables consumed by the grid renderers of fx2d-warp.js.
const F = Math.fround;
const PI = 3.141592653589793;
/** fistp with the default x87 rounding (nearest, ties to even). */
export const rint = (x) => { const r = Math.round(x); return (Math.abs(x % 1) === 0.5 && (r & 1)) ? r - 1 : r; };

function meshNodes(out, t, cx, cy, mix) {
  let o = 0;
  for (let i = 0; i < 26; i++) for (let j = 0; j < 41; j++) {
    const A = i * 1.2 - cy, B = j - cx;
    const ang = F(Math.atan2(A, B) * 6 * 128 / PI);
    const d2 = B * B;
    let v = F(600 - Math.sqrt(A * A + d2) * 50);
    if (mix !== undefined) v = F((1 - mix) * 256 + mix * v);
    if (v > 255) v = 255;
    if (0 > v) v = 0;
    out[o++] = rint(ang * 65536) & 0xffffff; out[o++] = 0; out[o++] = rint(v * 65536) & 0xffffff;
  }
}

/**
 * ported from func_22c39 (0x22c39): mesh node table for the polar "swirl" warp, animated by time t (float, DAT_00040310), cross-faded
 * with the flat value 256 by `mix`.  3 dwords per node (angle*65536 & 0xffffff, 0, brightness*65536 & 0xffffff), 26 rows x 41 columns.
 * The centre of the swirl wanders on a Lissajous-like path.
 * @param {Int32Array|Uint32Array} out 26*41*3 @param {number} t @param {number} mix
 */
export function warpMeshA(out, t, mix) {
  const cx = F(Math.sin(t * 0.02456 + Math.cos(t * 0.03 - Math.cos(t * 0.025))) * 10 + 20.5);
  const cy = F(Math.sin(t * 0.012543 + Math.sin(t * 0.04 - Math.sin(t * 0.035))) * 10 + 12.5);
  meshNodes(out, t, cx, cy, mix);
}
export const f_22c39 = warpMeshA;

/** ported from func_22e0e (0x22e0e): like warpMeshA with a simpler centre path (sin only) and no mix. */
export function warpMeshB(out, t) {
  const cx = F(Math.sin(t * 0.02456) * 20 + 20.5), cy = F(Math.sin(t * 0.012543) * 10 + 12.5);
  meshNodes(out, t, cx, cy, undefined);
}
export const f_22e0e = warpMeshB;
