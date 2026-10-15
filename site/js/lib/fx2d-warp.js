// fx2d-warp: grid-warp texture renderers (func_1d6a4 / 1e266 / 1e62e / 1e941) and scaled-mask sprite blitters
// (func_1f337 / 1f6b2 / 1fab7).  Both are heavily self-modifying in the original (immediates patched with the interpolation steps).
//
// ---- grid warp: the 320x200 screen is 40x25 cells of 8x8 pixels.  A mesh of 41x26 nodes (3 int32 each, row stride 41 nodes
// = 0x1ec bytes; made by func_22c39 / 22e0e, see fx2d-mesh.js) holds three 8.16 fixed point attributes per node
//   A (+0): texture u (bits 0..23; bits 24..31 = texture page)    B (+4): texture v      C (+8): shade (light level)
// For every cell the 4 corner nodes n0 (this), n1 (right), n2 (below), n3 (below right) give a bilinear interpolation:
//   per-pixel step  d  = sext24(n1-n0)>>3            (shl 8, sar 11)       [C: (n1-n0)>>3]
//   per-row  start += l = sext24(n2-n0)>>3
//   per-row  step  += dd = ((sext24(n3-n2)>>3) - d) >> 3
// and a pixel is texel(u,v) (u,v = integer byte of the 24-bit accumulators, so the texture wraps every 256) shaded by the integer
// byte of the C accumulator through the 64K blend table T (T[shade<<8 | texel_byte], DAT_000402f4 "screen" or 402f8 "inverse").
// The accumulators are a byte register (integer part) + the top 16 bits of a dword (fraction): `add edx,<step<<16>` / `adc bl,dl` -
// the carry flag does the fixed point carry.  Here all three are plain mod 2^24 integers.
// Per cell shortcuts: OR of the 4 corner shade bytes == 0 -> unshaded, AND == 0xff -> solid.
const sx = (v) => ((v << 8) >> 11) & 0xffffff;   // low 24 bits of sext24(v)>>3
const lk = (tab, hi, v) => ((v & 0xff000000) | (tab[(hi << 8) | ((v >>> 16) & 255)] << 16) | (tab[(hi << 8) | ((v >>> 8) & 255)] << 8) | tab[(hi << 8) | (v & 255)]) >>> 0;

/**
 * @param {Int32Array} nodes mesh (26 rows x 41 nodes x 3 int32) @param {number} bpp32 write dwords (else bytes)
 * @param {function(number,number,number,number,number,number):void} px callback(outIndex, page, u8, v8, shade, mode) mode: 0 shaded, 1 unshaded, 2 solid
 */
function warpCells(nodes, hasV, off, px) {
  for (let row = 0; row < 25; row++) for (let col = 0; col < 40; col++) {
    const i0 = (row * 41 + col) * 3, i1 = i0 + 3, i2 = i0 + 123, i3 = i2 + 3;
    const page = nodes[i0] >>> 24;
    let or = 0, and = 0xff;
    for (const i of [i0, i1, i2, i3]) { const b = (nodes[i + 2] >>> 16) & 255; or |= b; and &= b; }
    // (the original reads C bytes at +0xa,+0x16,+0x1f6,+0x202 = n0,n1,n2,n3)
    const mode = or === 0 ? 1 : and === 0xff ? 2 : 0;
    let u = nodes[i0] & 0xffffff, v = nodes[i0 + 1] & 0xffffff, s = nodes[i0 + 2] & 0xffffff;
    let du = sx(nodes[i1] - nodes[i0]), dv = sx(nodes[i1 + 1] - nodes[i0 + 1]), ds = ((nodes[i1 + 2] - nodes[i0 + 2]) >> 3) & 0xffffff;
    const lu = sx(nodes[i2] - nodes[i0]), lv = sx(nodes[i2 + 1] - nodes[i0 + 1]), ls = ((nodes[i2 + 2] - nodes[i0 + 2]) >> 3) & 0xffffff;
    const ddu = (((((nodes[i3] - nodes[i2]) << 8) >> 11) - ((((nodes[i1] - nodes[i0]) << 8) >> 11))) >> 3) & 0xffffff;
    const ddv = (((((nodes[i3 + 1] - nodes[i2 + 1]) << 8) >> 11) - ((((nodes[i1 + 1] - nodes[i0 + 1]) << 8) >> 11))) >> 3) & 0xffffff;
    const dds = ((((nodes[i3 + 2] - nodes[i2 + 2]) >> 3) - ((nodes[i1 + 2] - nodes[i0 + 2]) >> 3)) >> 3) & 0xffffff;
    for (let r = 0; r < 8; r++) {
      let uu = u, vv = v, ss = s;
      const o = off + (row * 8 + r) * 320 + col * 8;
      for (let x = 0; x < 8; x++) {
        px(o + x, page, (uu >>> 16) & 255, hasV ? (vv >>> 16) & 255 : 0, (ss >>> 16) & 255, mode);
        uu = (uu + du) & 0xffffff; vv = (vv + dv) & 0xffffff; ss = (ss + ds) & 0xffffff;
      }
      u = (u + lu) & 0xffffff; v = (v + lv) & 0xffffff; s = (s + ls) & 0xffffff;
      du = (du + ddu) & 0xffffff; dv = (dv + ddv) & 0xffffff; ds = (ds + dds) & 0xffffff;
    }
  }
}

/**
 * ported from func_1d6a4 (0x1d6a4): grid warp, 32bpp texture (Uint32Array, 65536 dwords per page) -> 32bpp screen, T = DAT_000402f4
 * (screen blend: a light level brightens the texel).  Unshaded cells copy the texel dword, solid cells write 0x00ffffff.
 * @param {Uint32Array} scr @param {number} off dest index of the top-left pixel (eax) @param {Uint32Array} tex @param {Int32Array} nodes @param {Uint8Array} T
 */
export function gridWarpTex32(scr, off, tex, nodes, T) {
  warpCells(nodes, true, off, (o, page, u, v, s, mode) => {
    scr[o] = mode === 2 ? 0xffffff : mode === 1 ? tex[(page << 16) | (v << 8) | u] : lk(T, s, tex[(page << 16) | (v << 8) | u]);
  });
}
export const f_1d6a4 = gridWarpTex32;

/**
 * ported from func_1e266 (0x1e266): grid warp, 8bpp texture (one 256x256 page, the page byte of the nodes is ignored here) -> 8bpp screen (Uint8Array),
 * T = DAT_000402f8 (inverse blend): shaded T[s<<8|t], unshaded ~t, solid 0.
 */
export function gridWarpTex8(scr, off, tex, nodes, T) {
  warpCells(nodes, true, off, (o, page, u, v, s, mode) => {
    const t = tex[(v << 8) | u];       // (the node's page byte is computed but never added to the base in the 8bpp versions)
    scr[o] = mode === 2 ? 0 : mode === 1 ? ~t & 255 : T[(s << 8) | t];
  });
}
export const f_1e266 = gridWarpTex8;

/**
 * ported from func_1e62e (0x1e62e): like 1e266 but only u and the shade are interpolated (v stays 0: a 256 texel strip),
 * T = DAT_000402f4: shaded T[s<<8|t], unshaded t, solid 0xff.
 */
export function gridWarpStrip8(scr, off, tex, nodes, T) {
  warpCells(nodes, false, off, (o, page, u, v, s, mode) => {
    const t = tex[u];
    scr[o] = mode === 2 ? 255 : mode === 1 ? t : T[(s << 8) | t];
  });
}
export const f_1e62e = gridWarpStrip8;

/** ported from func_1e941 (0x1e941): gridWarpStrip8 with the inverse table DAT_000402f8: shaded T[s<<8|t], unshaded ~t, solid 0. */
export function gridWarpStrip8Inv(scr, off, tex, nodes, T) {
  warpCells(nodes, false, off, (o, page, u, v, s, mode) => {
    const t = tex[u];
    scr[o] = mode === 2 ? 0 : mode === 1 ? ~t & 255 : T[(s << 8) | t];
  });
}
export const f_1e941 = gridWarpStrip8Inv;

// ---- scaled mask sprites.  X,Y,R are 24.8 fixed point (centre and radius in pixels); the sprite is a 256x256 byte mask sampled with
// a 8.8 step 2^24/(2R) (=2^15/R) so that it covers the 2R x 2R pixel square; sub-pixel phase = 0x7f - frac(X) + frac(R).
// pix(dest, maskValue) -> new dest dword (mask 0 never reaches it).
function sprite(scr, X, Y, R, mask, pix) {
  const x = X >> 8, y = Y >> 8, r = R >> 8;
  let n = 2 * r, cols, rows, x0 = x - r, y0 = y - r;
  const step = Math.trunc(0x1000000 / (2 * R)) | 0;
  let u0 = Math.imul(0x7f - (X & 255) + (R & 255), step) >>> 8, v0 = Math.imul(0x7f - (Y & 255) + (R & 255), step) >>> 8;
  if (x0 >= 0 && x + r < 0x13f && y0 >= 0 && y + r < 0xc7) { cols = rows = n; }
  else {
    if (x0 >= 0x13f || x + r < 0 || y0 >= 0xc7 || y + r < 0) return;
    cols = rows = n; let uo = 0, vo = 0;
    if (x0 < 0) { cols = n + x0; uo = Math.imul(-x0, step); x0 = 0; }
    if (x0 + cols >= 0x13f) cols = 0x140 - x0;
    if (y0 < 0) { rows = n + y0; vo = Math.imul(-y0, step); y0 = 0; }
    if (y0 + rows >= 0xc7) rows = 0xc8 - y0;
    if (cols < 2) cols = 2;
    u0 = (u0 + uo) | 0; v0 = (v0 + vo) | 0;
    if (rows >= 250) rows = 250; if (rows < 2) rows = 2;
  }
  const s16 = step & 0xffff;
  let v16 = (v0 >>> 0) & 0xffff;
  for (let ry = 0; ry < rows; ry++) {
    let u16 = (u0 >>> 0) & 0xffff;
    let di = (y0 + ry) * 320 + x0;
    for (let rx = 0; rx < cols; rx++, di++) {
      const m = mask[((v16 >>> 8) << 8) | (u16 >>> 8)];
      if (m) scr[di] = pix(scr[di], m);
      u16 = (u16 + s16) & 0xffff;
    }
    v16 = (v16 + s16) & 0xffff;
  }
}
const subSat3 = (d, m) => ((d & 0xff000000) | (Math.max(0, ((d >>> 16) & 255) - m) << 16) | (Math.max(0, ((d >>> 8) & 255) - m) << 8) | Math.max(0, (d & 255) - m)) >>> 0;
const addSat3 = (d, m) => ((d & 0xff000000) | (Math.min(255, ((d >>> 16) & 255) + m) << 16) | (Math.min(255, ((d >>> 8) & 255) + m) << 8) | Math.min(255, (d & 255) + m)) >>> 0;

/** ported from func_1f337 (0x1f337): scaled mask sprite subtracted (darkens, saturating) from the 32bpp screen: a soft shadow/blob. */
export function spriteSubtract(scr, X, Y, R, mask) { sprite(scr, X, Y, R, mask, subSat3); }
export const f_1f337 = spriteSubtract;
/**
 * ported from func_1f6b2 (0x1f6b2): scaled mask sprite ADDED with an alpha: per pixel m' = T[alpha<<8 | ~m] (T = DAT_000402f8), saturating add (glow). alpha 0xff draws nothing.
 */
export function spriteAddAlpha(scr, X, Y, R, mask, alpha, T) { if (alpha === 0xff) return; sprite(scr, X, Y, R, mask, (d, m) => addSat3(d, T[(alpha << 8) | (~m & 255)])); }
export const f_1f6b2 = spriteAddAlpha;
/** ported from func_1fab7 (0x1fab7): like spriteAddAlpha but subtracting. */
export function spriteSubtractAlpha(scr, X, Y, R, mask, alpha, T) { if (alpha === 0xff) return; sprite(scr, X, Y, R, mask, (d, m) => subSat3(d, T[(alpha << 8) | (~m & 255)])); }
export const f_1fab7 = spriteSubtractAlpha;
