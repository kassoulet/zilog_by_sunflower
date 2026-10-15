// _g5draw.js -- scene-specific drawing helpers (scenes 8/9/credits): vertex sprite loops 0x19f57 / 0x1a415 / 0x1a5ea and the
// grey additive Gouraud face filler 0x1ac25 (+ triangle 0x27128 / span 0x2d0bc).  Tested in tools/test/g5.test.mjs.
import { trunc32, rne, fillPoly, clipPoly, faceAreas, sortFaces, sprite_1efbc, sprite_1febc } from '../lib/mesh3d.js';
import { spriteAddAlpha, spriteSubtract } from '../lib/fx2d.js';
const f32 = Math.fround;
const mulsh = (a, b, s) => { const p = a * b; return Math.abs(p) < 9007199254740992 ? Math.floor(p / 2 ** s) | 0 : Number(BigInt.asIntN(32, (BigInt(a) * BigInt(b)) >> BigInt(s))); };

// sprites at the projected vertices: radius = p * invz (in px, only when > 1), position/radius in 8.8 fixed point
const spriteArgs = (m, i, f) => [trunc32(m.p2d[i * 2] * 256), trunc32(m.p2d[i * 2 + 1] * 256), trunc32(f * 256)];   // x8,y8,r8
/** ported from func_19f57 (0x19f57): additive spot sprite (obj.tex = 256x256 byte table) on every enabled vertex of a mode-9 object;
 *  sub 3 = coloured sprite (obj.colors).  p scales the radius. */
export function f_19f57(obj, p, ctx) {
  if (obj.mode !== 9) return;
  const m = obj.mesh;
  for (let i = 0; i < m.npts; i++) {
    if (m.mask && !m.mask[i]) continue;
    const f = f32(p * m.invz[i]); if (!(f > 1)) continue;
    const [x8, y8, r8] = spriteArgs(m, i, f);
    if (obj.sub === 3) { const c = obj.colors[i] & 0xffffff; sprite_1febc(ctx.target, obj.tex, x8, y8, r8, [c & 255, (c >>> 8) & 255, (c >>> 16) & 255]); }
    else sprite_1efbc(ctx.target, obj.tex, x8, y8, r8);
  }
}
/** ported from func_1a415 (0x1a415): sprites on the vertices in FRONT (xpts.z > 0), hidden by an 8-bit 320x200 mask picture:
 *  mask 0 = full additive sprite, 255 = none, else additive with alpha = mask (table lut2). */
export function f_1a415(obj, mask, p, ctx) {
  if (obj.mode !== 9) return;
  const m = obj.mesh;
  for (let i = 0; i < m.npts; i++) {
    if (!(m.xpts[i * 3 + 2] > 0)) continue;
    const f = f32(p * m.invz[i]); if (!(f > 1)) continue;
    const x = m.p2d[i * 2], y = m.p2d[i * 2 + 1];
    const mv = mask[(trunc32(y) << 6) + trunc32(x) + trunc32(y) * 256] ?? 0;     // y*320 + x (out of range: garbage in the original)
    const [x8, y8, r8] = spriteArgs(m, i, f);
    if (mv === 0) sprite_1efbc(ctx.target, obj.tex, x8, y8, r8);
    else if (mv !== 255) spriteAddAlpha(ctx.target, x8, y8, r8, obj.tex, mv, ctx.lut2);
  }
}
/** ported from func_1a5ea (0x1a5ea): sprites on the vertices BEHIND (xpts.z < 0): additive; sub 3 also draws a coloured one, sub 6 subtracts. */
export function f_1a5ea(obj, p, ctx) {
  if (obj.mode !== 9) return;
  const m = obj.mesh;
  for (let i = 0; i < m.npts; i++) {
    if (!(m.xpts[i * 3 + 2] < 0)) continue;
    const f = f32(p * m.invz[i]); if (!(f > 1)) continue;
    const [x8, y8, r8] = spriteArgs(m, i, f);
    if (obj.sub === 3) { const c = obj.colors[i] & 0xffffff; sprite_1febc(ctx.target, obj.tex, x8, y8, r8, [c & 255, (c >>> 8) & 255, (c >>> 16) & 255]); }
    if (obj.sub === 6) spriteSubtract(ctx.target, x8, y8, r8, obj.tex); else sprite_1efbc(ctx.target, obj.tex, x8, y8, r8);
  }
}

// ---- 0x2d0bc span: add a byte intensity (8.16 interpolated u, integer byte wraps at 256) to all three channels, saturating
const M24 = 0xffffff;
const spanAdd = (buf, g) => (dst, n, pre, a) => {
  let u = ((a[0] + mulsh(pre, g, 16)) | 0) & M24; const du = g & M24;
  for (let i = 0; i < n; i++) {
    const v = u >>> 16, d = buf[dst + i];
    const r = Math.min(255, (d & 255) + v) | (Math.min(255, ((d >>> 8) & 255) + v) << 8) | (Math.min(255, ((d >>> 16) & 255) + v) << 16);
    buf[dst + i] = ((d & 0xff000000) | r) >>> 0;
    u = (u + du) & M24;
  }
};
const outcode = (v) => (v[1] < 0 ? 1 : 0) | (v[1] > 200 ? 2 : 0) | (v[0] < 0 ? 4 : 0) | (v[0] > 320 ? 8 : 0);
/** ported from func_27128 (0x27128): grey additive Gouraud triangle; vertices a,b,c = (x,y,u) in the dispatcher's memory order (v0,v2,v1). */
export function tri_27128(ctx, a, b, c) {
  const v = [a, b, c].map((p) => Float32Array.of(p[0], p[1], p[2], 0)), oc = v.map(outcode);
  if (oc[0] & oc[1] & oc[2]) return;
  const dy1 = f32(v[1][1] - v[2][1]), dy2 = f32(v[0][1] - v[2][1]);
  const det = (v[0][0] - v[2][0]) * dy1 - (v[1][0] - v[2][0]) * dy2;
  if (det === 0) return;
  const g = rne(((v[0][2] - v[2][2]) * dy1 - (v[1][2] - v[2][2]) * dy2) / det * 65536);
  let L = v;
  if ((oc[0] | oc[1] | oc[2]) & 15) { L = clipPoly(v, 2); if (L.length < 3) return; }
  const P = new Int32Array(L.length * 3);
  for (let i = 0; i < L.length; i++) for (let k = 0; k < 3; k++) P[i * 3 + k] = rne(L[i][k] * 65536);
  fillPoly(P, L.length, 3, 1, ctx.pitch, spanAdd(ctx.target, g));
}
/** ported from func_1ac25 (0x1ac25): paint the visible faces (painter order) as additive grey Gouraud triangles, intensity = mesh.uv[v].x. */
export function f_1ac25(obj, ctx) {
  const m = obj.mesh; faceAreas(m); sortFaces(m);
  const P = m.p2d, U = m.uv;
  for (let i = 0; i < m.nvis; i++) {
    const f = m.order[i], v = (k) => { const q = m.faces[f * 3 + k]; return [P[q * 2], P[q * 2 + 1], U[q * 2]]; };
    tri_27128(ctx, v(0), v(2), v(1));          // memory order of the three vertex records: v0, v2, v1
  }
}
