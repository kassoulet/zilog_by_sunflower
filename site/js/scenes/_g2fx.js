// _g2fx: scene-specific FPU effect objects of scenes 2 and 3 (main() loops `order < 19` and `order < 23`).
// x87 intermediates are doubles, every `fstp dword` is Math.fround. `t` = DAT_00040310 (float32 scene time).
// Differentially tested against the original under Unicorn: tools/test/g2_gen.py / g2.test.mjs.
import { trunc32, tri_25fc0, sprite_1efbc, faceAreas, sortFaces } from '../lib/mesh3d.js';
import { fistp32 } from '../lib/fx2d-tables.js';
import { spriteSubtract as spriteSub } from '../lib/fx2d-warp.js';
export const F = Math.fround;
const S = Math.sin, C = Math.cos, A2 = Math.atan2;

/** ported from func_1bdb0 (0x1bdb0): concentric polygon rings mesh (w points per ring, h rings, radii R/h .. R), z = 0, edges ring[k]->ring[k+1 mod w]. */
export function ringMesh(w, h, R) {
  const n = w * h, pts = new Float32Array(n * 3), edges = new Int32Array(n * 2);
  let k = 0;
  for (let r = F(R / h); !(r > R); r = F(F(R / h) + r)) {
    for (let j = 0; j < w; j++, k++) {
      const a = F(j * 2) * Math.PI / w;
      pts[k * 3] = F(C(a) * r); pts[k * 3 + 1] = F(S(a) * r); pts[k * 3 + 2] = 0;
    }
  }
  for (let j = 0, e = 0; j < h; j++) for (let i = 0; i < w; i++, e++) { edges[e * 2] = j * w + i; edges[e * 2 + 1] = j * w + (i + 1) % w; }
  return {
    npts: n, pts, xpts: new Float32Array(n * 3), mask: null, nrm: null, xnrm: null, nfaces: 0, faces: new Int32Array(0), fnrm: null, key: null, order: null,
    nvis: 0, vf: null, vfIdx: null, edgeFaces: null, nedges: n, edges, p2d: new Float32Array(n * 2), uv: null, area: new Int32Array(0), invz: null,
  };
}
export const f_1bdb0 = ringMesh;

/** ported from func_206e0 (0x206e0): spherical radial wobble pts -> xpts: r' = r + 140 sin(cos(B r - e) + A r + d) with time dependent A,B,d,e. */
export function wobbleMesh(m, t) {
  const A = F(S(t * 0.03) * 0.01), B = F(C(S(t * 0.1) + t * 0.04) * 0.01), d = F(t * 0.0041), e = F(t * 0.0062);
  const P = m.pts, O = m.xpts;
  for (let i = 0; i < m.npts; i++) {
    const x = P[i * 3], y = P[i * 3 + 1], z = P[i * 3 + 2];
    const phi = F(A2(y, x)), theta = F(A2(Math.sqrt(y * y + x * x), z)), r = F(Math.sqrt(z * z + (y * y + x * x)));
    const r2 = F(S(C(B * r - e) + (A * r + d)) * 140 + r);
    const st = S(theta) * r2;
    O[i * 3] = F(C(phi) * st); O[i * 3 + 1] = F(S(phi) * st); O[i * 3 + 2] = F(C(theta) * r2);
  }
}
export const f_206e0 = wobbleMesh;

/** ported from func_20b94 (0x20b94): spherical radial displacement by a product of three sines of x,y,z: r' = r + R sin(a x+d) sin(b y+e) sin(c z+g). */
export function sineBlobMesh(m, t, R) {
  const a = F(S(t * 0.05) * 0.0061), b = F(C(S(t * 0.02) + t * 0.06) * 0.0061), c = F(C(t * 0.01) * 0.0061);
  const d = F(t * 0.031), e = F(t * 0.042), g = F(t * 0.051);
  const P = m.pts, O = m.xpts;
  for (let i = 0; i < m.npts; i++) {
    const x = P[i * 3], y = P[i * 3 + 1], z = P[i * 3 + 2];
    const phi = F(A2(y, x)), rho2 = F(x * x + y * y), theta = F(A2(Math.sqrt(y * y + x * x), z));
    const r = F(Math.sqrt(z * z + rho2));
    const k = S(c * z + g) * (S(b * y + e) * S(a * x + d));
    const r2 = F(k * R + r);
    const st = S(theta) * r2;
    O[i * 3] = F(C(phi) * st); O[i * 3 + 1] = F(S(phi) * st); O[i * 3 + 2] = F(C(theta) * r2);
  }
}
export const f_20b94 = sineBlobMesh;

/** ported from func_1b446 (0x1b446): per vertex colour byte (uv[i].x, float) = 127 + 127-ish sin(k x + .01t) sin(k y + .02t) sin(k z + .015t) (used by line mode 6). */
export function waveColours(m, t, k) {
  if (!m.uv) m.uv = new Float32Array(m.npts * 2);
  const P = m.pts;
  for (let i = 0; i < m.npts; i++) {
    let A = S(k * P[i * 3] + t * 0.01) * 127;
    A = S(k * P[i * 3 + 1] + t * 0.02) * A;
    m.uv[i * 2] = F(S(k * P[i * 3 + 2] + t * 0.015) * A + 127);
  }
}
export const f_1b446 = waveColours;

/**
 * ported from func_1ce90 (0x1ce90): fills the 41x26 node table (u,v 24 bit 8.16 coords, third dword 0) of the grid warp with a "three lens" field:
 * three moving centres, each contributes 1/(0.001(a^2 w1 + b^2 w2)+0.2); the signed sum scales a rotated (x,y) coordinate.
 */
export function lensNodes(nodes, t) {
  const s = F(3 * S(S(t * 0.013) + t * 0.012)) , cs = F(C(3 * S(S(t * 0.013) + t * 0.012))), sn = F(S(s));
  const d1x = F(S(t * 0.01 - S(t * 0.02)) * 14), d1y = F(C(t * 0.013 - S(t * 0.026)) * 11);
  const w1a = F(1 + S(t * 0.09) * 0.5), w1b = F(1 + S(t * 0.07) * 0.5);
  const d2x = F(S((t * 0.01 + 0.3) - S(t * 0.02)) * 14), d2y = F(C((t * 0.013 + 0.3) - S(t * 0.026)) * 11);
  const w2a = F(1 + S(t * 0.05) * 0.5), w2b = F(1 + S(t * 0.03) * 0.5);
  const d3x = F(S((t * 0.02 + 0.3) - S(t * 0.01)) * 14), d3y = F(C((t * 0.033 + 0.3) - S(t * 0.036)) * 11);
  const w3a = F(1 + S(t * 0.07) * 0.5), w3b = F(1 + S(t * 0.05) * 0.5);
  let o = 0;
  for (let yy = -13; yy < 13; yy++) for (let xx = -20; xx < 21; xx++) {
    const Y = F(yy * 1.2);
    const a1 = xx + d1x, b1 = Y + d1y, b1f = F(b1);
    const rx = F(a1 * cs - b1 * sn), ry = F(sn * a1 + cs * b1f);
    const g1 = F(1 / ((a1 * a1 * w1a + b1f * b1f * w1b) * 0.001 + 0.2));
    const u2 = xx + d2x, v2 = Y + d2y;
    const g2 = F(1 / ((u2 * u2 * w2a + v2 * v2 * w2b) * 0.001 + 0.2));
    const u3 = xx + d3x, v3 = Y + d3y;
    const g3 = 1 / ((u3 * u3 * w3a + v3 * v3 * w3b) * 0.001 + 0.2);
    const H = F((g1 - g2) - g3);
    nodes[o++] = fistp32(F(H * rx) * 196608) & 0xffffff; nodes[o++] = fistp32(F(H * ry) * 196608) & 0xffffff; nodes[o++] = 0;
  }
}
export const f_1ce90 = lensNodes;

/**
 * ported from func_1a7df (half = +1, far half: sort key > 0) / func_1aa02 (half = -1, near half: key < 0): environment mapped faces
 * (mode 0 sub 0 / mode 1) like the dispatcher but only the faces on one side of the z = 0 plane (keys are trunc(sum z * 100)).
 */
export function renderFacesHalf(obj, ctx, half) {
  const m = obj.mesh, P = m.p2d, mode = obj.mode;
  if (mode > 1) return;
  faceAreas(m); sortFaces(m);
  const N = mode === 0 ? m.nrm : m.xnrm, V = new Float32Array(15);
  for (let i = 0; i < m.nvis; i++) {
    if (half > 0 ? !(m.key[i] > 0) : !(m.key[i] < 0)) continue;
    const f = m.order[i];
    for (let k = 0; k < 3; k++) {
      const v = m.faces[f * 3 + (k === 0 ? 0 : 3 - k)], o = k * 5;
      V[o] = P[v * 2]; V[o + 1] = P[v * 2 + 1]; V[o + 2] = F(N[v * 3] * 127 + 127); V[o + 3] = F(N[v * 3 + 1] * 127 + 127);
    }
    if (obj.sub === 0) tri_25fc0(ctx, V, obj.tex);
  }
}
export const f_1a7df = (o, c) => renderFacesHalf(o, c, 1), f_1aa02 = (o, c) => renderFacesHalf(o, c, -1);

/**
 * ported from func_1a21b (front = true: points with z > 0) / func_1a5ea (front = false: z < 0): mode 9 point sprites sized scale*invz (> 1 px).
 * sub 6 = subtracting soft blobs (spriteSubtract with the obj texture as mask), otherwise additive 1efbc.
 */
export function spritesHalf(obj, ctx, scale, farHalf) {
  const m = obj.mesh, tgt = ctx.target;
  if (obj.mode !== 9) return;
  for (let i = 0; i < m.npts; i++) {
    const z = m.xpts[i * 3 + 2];
    if (farHalf ? !(z > 0) : !(z < 0)) continue;
    const size = F(scale * m.invz[i]);
    if (!(size > 1)) continue;
    const r8 = trunc32(size * 256), y8 = trunc32(m.p2d[i * 2 + 1] * 256), x8 = trunc32(m.p2d[i * 2] * 256);
    if (obj.sub === 6) spriteSub(tgt, x8, y8, r8, obj.tex); else sprite_1efbc(tgt, obj.tex, x8, y8, r8);
  }
}
export const f_1a21b = (o, c, s) => spritesHalf(o, c, s, true), f_1a5ea = (o, c, s) => spritesHalf(o, c, s, false);

// ---------------------------------------------------------------------------------------------------------------------------------
// shared set-up (what main() builds before its first loop and scenes 2/3 use), cached in env.shared
import { radialCosSpot, bumpDisplacementMap, colorMatrixTables } from '../lib/fx2d.js';
import { makeLuts, loadMesh } from '../lib/mesh3d.js';
export function g2Shared(env) {
  const sh = (env.shared ??= {});
  if (!sh.g2) {
    const luts = makeLuts();                                                    // DAT_402f4 / 402f8 (0x14834)
    const spot = new Uint8Array(65536); radialCosSpot(spot);                    // LUT+0x20000 (0x14639)
    const cm = new Int32Array(9 * 256); colorMatrixTables(cm);                  // 0x148c4
    sh.g2 = { lut1: luts.lut1, lut2: luts.lut2, luts, spot, cm };
  }
  return sh.g2;
}
export const mesh = (env, name) => loadMesh(env.files.get('3d/' + name));
/** time like the prologue: DAT_00040310 = ticks*0.25 - DAT_00040314 (float32), base latched at the scene's first frame */
export function makeClock() {
  let base = null;
  return (st) => { if (base === null) base = F(st.ticks * 0.25); return F(st.ticks * 0.25 - base); };
}
