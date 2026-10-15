// fx2d-tables: texture / lookup-table generators of ZILOG.EXE (all run once at start-up in the original).
// All FPU maths is x87: doubles for the computation, `fstp dword` -> Math.fround, `ftrunc+fistp` -> truncate.
const F = Math.fround;
const PI = 3.141592653589793;

/** fistp dword after ftrunc: truncate toward zero, x87 "integer indefinite" 0x80000000 on overflow/NaN. */
export function fistp32(x) {
  const t = Math.trunc(x);
  return (t >= 2147483648 || t < -2147483648 || t !== t) ? -2147483648 : t;
}

/**
 * ported from func_14639 (0x14639): 256x256 byte "soft spot" : 255*(0.5+0.5*cos(r/40.4)), r = distance to the centre
 * with the outer-loop axis (rows) stretched by 1.17, r clamped to 127.  dst: Uint8Array(65536).
 */
export function radialCosSpot(dst) {
  let o = 0;
  for (let y = -128; y < 128; y++) for (let x = -128; x < 128; x++) {
    const yy = y * 1.17;
    let r = F(Math.sqrt(yy * yy + x * x));
    if (r > 127) r = 127;
    const c = F(Math.cos(r / 40.4) * 0.5 + 0.5);
    dst[o++] = fistp32(c * 255) & 255;
  }
}
export const f_14639 = radialCosSpot;

/** ported from func_146f9 (0x146f9): 256x256 byte hard disc mask (0xff inside stretched radius < 120, else 0). */
export function radialDiscMask(dst) {
  let o = 0;
  for (let y = -128; y < 128; y++) for (let x = -128; x < 128; x++) {
    const yy = y * 1.17;
    const r = F(Math.sqrt(yy * yy + x * x));
    dst[o++] = (r < 120) ? 0xff : 0;
  }
}
export const f_146f9 = radialDiscMask;

/**
 * ported from func_14834 (0x14834): two 64K screen-blend tables (DAT_000402f4 / DAT_000402f8).
 * T[y*256+x] = 255 - ((255-y)*(255-x) >> 8)  ("screen" / inverse multiply), T2 = ~T.
 * @param {Uint8Array} t1 @param {Uint8Array} t2  both 65536 bytes
 */
export function screenBlendTables(t1, t2) {
  let o = 0;
  for (let y = 0; y < 256; y++) for (let x = 0; x < 256; x++, o++) {
    t1[o] = (255 - (((255 - y) * (255 - x)) >>> 8)) & 255;
    t2[o] = ~t1[o] & 255;
  }
}
export const f_14834 = screenBlendTables;

const fl = (bits) => { const u = new Uint32Array([bits]); return new Float32Array(u.buffer)[0]; };
// the 14 float constants stored on the stack by func_148c4 (YCbCr-ish conversion matrix)
const C = { 38: fl(0x3e991687), 34: fl(0x3f1645a2), 30: fl(0x3de978d5), '2c': fl(0xbe2cca2e), 28: fl(0xbea99ae9), 24: fl(0x3f000000),
  20: fl(0x3f000000), '1c': fl(0xbed65e89), 18: fl(0xbda685db), 14: fl(0x3fb374bc), 10: fl(0xbeb0331e), c: fl(0xbf36d1e1),
  8: fl(0x3fe2d0e5), 4: fl(0x3d800000) };

/**
 * ported from func_148c4 (0x148c4): 9 x 256 int32 fixed-point (8.24) colour-matrix tables used by func_22990.
 * dst: Int32Array(9*256); table k at dst[k*256 + i] = trunc(i * 2^24 * coefficient_k).
 */
export function colorMatrixTables(dst) {
  const c = C;
  for (let i = 0; i < 256; i++) {
    const s = i * 16777216;
    const co = [
      c[38] * c[4] + c[14] * c[20], c[34] * c[4] + c[14] * c['1c'], c[30] * c[4] + c[14] * c[18],
      c[38] * c[4] + c[10] * c['2c'] + c.c * c[20], c[34] * c[4] + c[10] * c[28] + c.c * c['1c'], c[30] * c[4] + c[10] * c[24] + c.c * c[18],
      c[38] * c[4] + c[8] * c['2c'], c[34] * c[4] + c[8] * c[28], c[30] * c[4] + c[8] * c[24]];
    for (let k = 0; k < 9; k++) dst[k * 256 + i] = fistp32(co[k] * s);
  }
}
export const f_148c4 = colorMatrixTables;

/**
 * ported from func_14b3d (0x14b3d): turn a 256x256 height field into a 256x256 uint16 displacement map
 * (high byte = y + dh/dy, low byte = x + dh/dx, central differences over 3 texels, wrap-around) -> fake bump/refraction.
 * @param {Uint16Array} dst 65536  @param {Uint8Array} h 65536 signed(char) heights
 */
export function bumpDisplacementMap(dst, h) {
  const s = (v) => (v << 24) >> 24;
  for (let i = 0; i < 256; i++) for (let j = 0; j < 256; j++) {
    const a = s(h[((i - 1) & 255) * 256 + j]) - s(h[((i + 2) & 255) * 256 + j]);
    const b = s(h[i * 256 + ((j - 1) & 255)]) - s(h[i * 256 + ((j + 2) & 255)]);
    dst[i * 256 + j] = (((i + a) & 255) << 8) + ((j + b) & 255);
  }
}
export const f_14b3d = bumpDisplacementMap;

/** ported from func_14c51 (0x14c51): 256x256 byte plasma/"egg-box" 16 + 56(1+cos)(1+cos) (range 16..240) with x,y over one period. */
export function cosCosPlasma(dst) {
  let o = 0;
  for (let y = 0; y < 256; y++) for (let x = 0; x < 256; x++) {
    const a = (1 + Math.cos(x * PI * 0.0078125 + PI)) * 56;
    dst[o++] = fistp32((1 + Math.cos(y * PI * 0.0078125 + PI)) * a + 16) & 255;
  }
}
export const f_14c51 = cosCosPlasma;

/**
 * trunc(r*c + K) as the x87 computes it: r*c is exact in the 64-bit extended mantissa and the sum is kept with 64 bits, while a
 * double would round r*c + K to K when |r*c| is tiny (sin/cos of multiples of pi/2 leave residues like -1.8e-16: 100 - 1.8e-16 -> 99, not 100).
 * Exact residual via Veltkamp split + TwoSum.  r: small integer.
 */
function truncSum(r, c, K) {
  const t = 134217729 * c, ch = t - (t - c), cl = c - ch;
  const ph = r * c, pl = (r * ch - ph) + r * cl;
  const s = K + ph, bb = s - K, e = (K - (s - bb)) + (ph - bb), res = e + pl;
  if (Number.isInteger(s) && s > 0 && res < 0) return s - 1;
  return Math.trunc(s);
}

/**
 * ported from func_14d0b (0x14d0b): tables for the radial blur (func_1743b).
 * rays: Uint16Array(0xbc*0x200): ray a (512 angles), step r (0..187) -> screen offset y*320+x of (160+r sin, 100+r cos), clamped.
 * Builds a 320x200 mask in `tmp` (64000 bytes, 0xff where a ray point lands), then lists every EMPTY pixel
 * with the orthogonal neighbour that is lit into `pairs` (Uint16 pairs [src, dst]) so holes can be filled.
 * Note: like the original, an empty pixel without lit neighbours still consumes a slot (previous content kept).
 * @returns {number} number of pairs
 */
export function radialRayTables(rays, pairs, tmp) {
  for (let r = 0; r < 0xbc; r++) for (let a = 0; a < 0x200; a++) {
    let x = truncSum(r, Math.sin(a * PI * 0.00390625), 160);
    let y = truncSum(r, Math.cos(a * PI * 0.00390625), 100);
    if (y < 0) y = 0; if (y > 199) y = 199;
    if (x < 0) x = 0; if (x > 0x13f) x = 0x13f;
    rays[a * 0xbc + r] = (x + y * 320) & 0xffff;
  }
  tmp.fill(0, 0, 64000);
  for (let i = 0; i < 0x17800; i++) tmp[rays[i]] = 0xff;
  let n = 0;
  for (let p = 0x140; p < 0xf8c0; p++) {
    if (tmp[p] === 0) {
      if (tmp[p - 0x140]) { pairs[n] = p - 0x140; pairs[n + 1] = p; }
      if (tmp[p + 0x140]) { pairs[n] = p + 0x140; pairs[n + 1] = p; }
      if (tmp[p - 1]) { pairs[n] = p - 1; pairs[n + 1] = p; }
      if (tmp[p + 1]) { pairs[n] = p + 1; pairs[n + 1] = p; }
      n += 2;
    }
  }
  return n >> 1;
}
export const f_14d0b = radialRayTables;

/**
 * ported from func_15168 (0x15168): 256x256 dword shading LUT from a 256-entry 6-bit RGB palette (pal.sc 'RIX3' data, 3 bytes/entry).
 * dst[(idx*256+v)] = bytes (B,G,R,0) = v * pal[idx] / 64 (per channel, float32 multiplier, truncated).
 * Note byte0 (blue) uses pal[idx*3+2], i.e. dword = 0x00RRGGBB with the palette order R,G,B.
 * @param {Uint32Array} dst 65536 @param {Uint8Array} pal 768 bytes
 */
export function paletteShadeLut(dst, pal) {
  const d8 = new Uint8Array(dst.buffer, dst.byteOffset, 65536 * 4);
  for (let i = 0; i < 256; i++) {
    const m0 = F(pal[i * 3 + 2] * 0.015625), m1 = F(pal[i * 3 + 1] * 0.015625), m2 = F(pal[i * 3] * 0.015625);
    for (let v = 0; v < 256; v++) {
      const o = (i * 256 + v) * 4;
      d8[o] = Math.trunc(v * m0) & 255; d8[o + 1] = Math.trunc(v * m1) & 255; d8[o + 2] = Math.trunc(v * m2) & 255; d8[o + 3] = 0;
    }
  }
}
export const f_15168 = paletteShadeLut;

/** ported from func_1478a (0x1478a): in place halve every channel of 65536 dwords ((d>>1)&0x7f7f7f). */
export function halveDwords(a) { for (let i = 0; i < 0x10000; i++) a[i] = (a[i] >>> 1) & 0x7f7f7f; }
export const f_1478a = halveDwords;
/** ported from func_147df (0x147df): in place invert the 24 colour bits of 65536 dwords. */
export function invertDwords(a) { for (let i = 0; i < 0x10000; i++) a[i] = ~a[i] & 0xffffff; }
export const f_147df = invertDwords;

/**
 * ported from func_14f53 (0x14f53): 256x256 dword "colour ramp" LUT (dword = (idx<<8)+v): three channel multipliers
 * that depend on idx, a 3-segment ramp:  idx<128: (B,G,R)=(v*(128-idx)/128, v*idx/256, v*idx/128);
 * idx>=128: (v*(idx-128)/128, v*idx/256, v*(256-idx)/128).  dst: Uint32Array(65536).
 */
export function colourRampLut(dst) {
  const d8 = new Uint8Array(dst.buffer, dst.byteOffset, 65536 * 4);
  for (let i = 0; i < 256; i++) {
    const m0 = i < 128 ? F((128 - i) * 0.0078125) : F((i - 128) * 0.0078125);
    const m1 = F(i * 0.00390625);
    const m2 = i < 128 ? F(i * 0.0078125) : F((256 - i) * 0.0078125);
    for (let v = 0; v < 256; v++) {
      const o = (i * 256 + v) * 4;
      d8[o] = Math.trunc(v * m0) & 255; d8[o + 1] = Math.trunc(v * m1) & 255; d8[o + 2] = Math.trunc(v * m2) & 255; d8[o + 3] = 0;
    }
  }
}
export const f_14f53 = colourRampLut;
