// fx2d-blit: GFX blits with per-channel operators, mask driven fades and cross-fades, colour matrix, light-map add,
// all on 320x200 dword screens (Uint32Array(64000), dword = bytes B,G,R,x with byte3 an unused "alpha" that is carried along).
//
// "gfx" arguments are loadGfx() results ({w,h,bpp,flags,px}).  The original blits take the in-memory GFX image; a 24/32bpp GFX with
// flags&1 has been converted by func_15a48 into an RLE stream (skip count | 0x80000000+literal run, 0xffffffff end) over the
// LINEAR dword array: zero pixels are the skipped ones.  (8bpp flags&1 images, smalpics/jp*.gfx, are RLE streams in the file itself,
// see expandRle8.)  Here the plain px array is used instead, which is identical for every
// operator below (a skipped pixel is left alone, or written as 0 by func_1c4b4) but the blit is then LINEAR (width ignored,
// dest index = di + k), exactly like the original RLE path.  Non-RLE images are drawn w pixels per row, 320 per dest row.

const sat = (a, b) => (a + b > 255 ? 255 : a + b);
/** per-channel saturated add of the 3 colour bytes of s and d, byte3 taken from `hi`. */
const addSat = (s, d, hi) => ((hi & 0xff000000) | (sat((s >>> 16) & 255, (d >>> 16) & 255) << 16) | (sat((s >>> 8) & 255, (d >>> 8) & 255) << 8) | sat(s & 255, d & 255)) >>> 0;
const absDiff = (s, d) => ((d & 0xff000000) | (Math.abs(((s >>> 16) & 255) - ((d >>> 16) & 255)) << 16) | (Math.abs(((s >>> 8) & 255) - ((d >>> 8) & 255)) << 8) | Math.abs((s & 255) - (d & 255))) >>> 0;
const maxCh = (s, d) => ((d & 0xff000000) | (Math.max((s >>> 16) & 255, (d >>> 16) & 255) << 16) | (Math.max((s >>> 8) & 255, (d >>> 8) & 255) << 8) | Math.max(s & 255, d & 255)) >>> 0;
const grey = (g) => (g << 16) | (g << 8) | g;

/**
 * Expand the 8bpp RLE stream of a flags==1 8-bit GFX (smalpics/jp*.gfx, kept as-is by the loader) into a plain grey byte array.
 * Stream: u32 count (unaligned, little endian); 0xffffffff = end; top bit set = literal run of (count&0x7fffffff) BYTES follow;
 * else skip `count` pixels (zero).  A literal 0 is the same as a skip for every operator of this file.
 */
export function expandRle8(px) {
  const dv = new DataView(px.buffer, px.byteOffset, px.byteLength);
  let p = 0, n = 0;
  for (;;) { const c = dv.getUint32(p, true); p += 4; if (c === 0xffffffff) break; if (c & 0x80000000) { const l = c & 0x7fffffff; p += l; n += l; } else n += c; }
  const out = new Uint8Array(n);
  p = 0; n = 0;
  for (;;) { const c = dv.getUint32(p, true); p += 4; if (c === 0xffffffff) break; if (c & 0x80000000) { const l = c & 0x7fffffff; out.set(px.subarray(p, p + l), n); p += l; n += l; } else n += c; }
  return out;
}

/** shared driver of func_1c4f6/1c7a6/1c91e: op32(src,dst) for 32bpp pixels, op8(grey,dst) for 8bpp images. */
function blitOp(scr, di, g, op32, op8) {
  let px = g.px;
  if (g.flags & 1) {                      // RLE image: linear, zero pixels skipped
    const op = g.bpp === 0x20 ? op32 : op8;
    if (g.bpp !== 0x20) px = expandRle8(px);
    for (let k = 0; k < px.length; k++) if (px[k] !== 0) scr[di + k] = op(px[k], scr[di + k]);
  } else if (g.bpp === 0x20) {
    for (let y = 0, k = 0; y < g.h; y++, di += 320) for (let x = 0; x < g.w; x++, k++) scr[di + x] = op32(px[k], scr[di + x]);
  } else {
    for (let y = 0, k = 0; y < g.h; y++, di += 320) for (let x = 0; x < g.w; x++, k++) scr[di + x] = op8(px[k], scr[di + x]);
  }
}

/** ported from func_1c4f6 (0x1c4f6): additive blit with per-channel saturation (glow / light sprite). 32bpp byte3 comes from the sprite. */
export function blitAdd(scr, di, g) { blitOp(scr, di, g, (s, d) => addSat(s, d, s), (s, d) => addSat(grey(s), d, d)); }
export const f_1c4f6 = blitAdd;
/** ported from func_1c7a6 (0x1c7a6): |src-dst| per channel blit ("difference" blend). */
export function blitDifference(scr, di, g) { blitOp(scr, di, g, absDiff, (s, d) => absDiff(grey(s), d)); }
export const f_1c7a6 = blitDifference;
/** ported from func_1c91e (0x1c91e): max(src,dst) per channel blit ("lighten"). */
export function blitLighten(scr, di, g) { blitOp(scr, di, g, maxCh, (s, d) => maxCh(grey(s), d)); }
export const f_1c91e = blitLighten;

/**
 * ported from func_1c4b4 (0x1c4b4): copy a 32bpp full screen GFX to the screen (64000 dwords, ignoring w/h); the RLE
 * variant writes 0 for the skipped runs, so it is the same copy.  8bpp non RLE images are ignored.
 */
export function blitCopy(scr, di, g) {
  if (!(g.flags & 1) && g.bpp !== 0x20) return;
  const n = (g.flags & 1) ? g.px.length : 64000;
  for (let k = 0; k < n; k++) scr[di + k] = g.px[k];
}
export const f_1c4b4 = blitCopy;

/**
 * ported from func_1c34e (0x1c34e): screen bounding box of the projected points of a 3D object, clamped to the screen.
 * @param {Float32Array} xy interleaved projected points (x,y float32) @param {number} n  @returns {Float32Array} [minX, maxX, minY, maxY]
 * (stored by the original in DAT_00040358..00040364), x clamped to [0,319], y to [0,199].
 */
export function projectedBBox(xy, n) {
  let x0 = xy[0], x1 = xy[0], y0 = xy[1], y1 = xy[1];
  for (let i = 0; i < n; i++) {
    const x = xy[2 * i], y = xy[2 * i + 1];
    if (!(x >= x0)) x0 = x;       // fcomp/sahf/jae : taken when x >= min (not when unordered)
    if (x > x1) x1 = x;
    if (!(y >= y0)) y0 = y;
    if (y > y1) y1 = y;
  }
  if (0 > x0) x0 = 0; if (x1 > 319) x1 = 319; if (0 > y0) y0 = 0; if (y1 > 199) y1 = 199;
  return new Float32Array([x0, x1, y0, y1]);
}
export const f_1c34e = projectedBBox;

// look up the three colour bytes of dword v in tab[hi<<8 | byte]; byte3 is kept (original: ror/rol trick with the table pointer as base)
const lk = (tab, hi, v) => ((v & 0xff000000) | (tab[(hi << 8) | ((v >>> 16) & 255)] << 16) | (tab[(hi << 8) | ((v >>> 8) & 255)] << 8) | tab[(hi << 8) | (v & 255)]) >>> 0;

/**
 * ported from func_1ec58 (0x1ec58): fade-to-black wipe driven by an 8-bit mask.  k = mask[i] - thr:
 * k<=0 pixel kept, k>31 black, else every colour byte c -> T[(k<<3)<<8 | ~c] with T = inverse blend table DAT_000402f8
 * (= c*(1-8k/256) approx.; byte3 inverted).
 * @param {Uint32Array} scr @param {Uint8Array} mask 64000 @param {number} thr @param {Uint8Array} T 64K table (0x402f8)
 */
export function maskFadeToBlack(scr, mask, thr, T) {
  for (let i = 0; i < 64000; i++) {
    const k = mask[i] - thr;
    if (k <= 0) continue;
    scr[i] = k > 0x1f ? 0 : lk(T, k << 3, ~scr[i] >>> 0);
  }
}
export const f_1ec58 = maskFadeToBlack;

/**
 * ported from func_1ecaa (0x1ecaa): wipe cross-fade from scr to image b, mask driven: k = mask[i]-thr (16 bit signed);
 * k<=0 keep scr, k>31 take b, else T[(k<<3)<<8|~scr_c] + T[((255-8k))<<8 | ~b_c] (dword add, carries between bytes included).
 */
export function maskWipeCrossfade(scr, mask, b, thr, T) {
  for (let i = 0; i < 64000; i++) {
    const k = ((mask[i] - thr) << 16) >> 16;
    if (k <= 0) continue;
    if (k > 0x1f) { scr[i] = b[i]; continue; }
    const a = lk(T, k << 3, ~scr[i] >>> 0);
    const c = lk(T, (~(k << 3)) & 255, ~b[i] >>> 0);
    scr[i] = (a + c) >>> 0;
  }
}
export const f_1ecaa = maskWipeCrossfade;

/**
 * ported from func_1ee44 (0x1ee44): per-pixel alpha cross-fade of scr towards image b by an 8-bit alpha mask
 * (0 keep, >=255 take b, else T[m<<8|~a_c] + T[(~m)<<8|~b_c]).
 */
export function alphaMaskCrossfade(scr, mask, b, T) {
  for (let i = 0; i < 64000; i++) {
    const m = mask[i];
    if (m === 0) continue;
    if (m >= 255) { scr[i] = b[i]; continue; }
    const a = lk(T, m, ~scr[i] >>> 0);
    const c = lk(T, ~m & 255, ~b[i] >>> 0);
    scr[i] = (a + c) >>> 0;
  }
}
export const f_1ee44 = alphaMaskCrossfade;

/**
 * ported from func_1eeb4 (0x1eeb4): partial invert by an 8-bit mask: m=0 keep, m>=255 -> ~scr & 0xffffff,
 * else T[m<<8|~c] + T[(~m)<<8|c]  (= c*(1-m) + (255-c)*m approx.).
 */
export function maskInvert(scr, mask, T) {
  for (let i = 0; i < 64000; i++) {
    const m = mask[i];
    if (m === 0) continue;
    if (m >= 255) { scr[i] = ~scr[i] & 0xffffff; continue; }
    const d = scr[i];
    scr[i] = (lk(T, m, ~d >>> 0) + lk(T, ~m & 255, d)) >>> 0;
  }
}
export const f_1eeb4 = maskInvert;

/**
 * ported from func_22b43 (0x22b43): add a 256x256 8-bit "light map" through a displacement table:
 * dst[i] = satAdd3(src[i], lightmap[(disp[i] + dx) & 0xffff])  for i < 65536 (byte3 from src).
 * @param {Uint32Array} dst @param {Uint32Array} src @param {Uint16Array} disp @param {Uint8Array} map @param {number} dx
 */
export function lightMapAdd(dst, src, disp, map, dx) {
  for (let i = 0; i < 0x10000; i++) {
    const l = map[(disp[i] + dx) & 0xffff], s = src[i];
    dst[i] = addSat(grey(l), s, s);
  }
}
export const f_22b43 = lightMapAdd;

/** ported from func_22b9c (0x22b9c): 2D palette lookup, dst[i] = lut[(hi[i]<<8) | lo[i]] (lut: Uint32Array 65536, e.g. func_15168 output), 64000 pixels. */
export function lutLookup2D(dst, lo, hi, lut) {
  for (let i = 0; i < 64000; i++) dst[i] = lut[(hi[i] << 8) | lo[i]];
}
export const f_22b9c = lutLookup2D;

/**
 * ported from func_22990 (0x22990): 3x3 colour matrix on a screen rectangle with the 9x256 int32 tables of func_148c4:
 * out_c = ((T[3c][b0] + T[3c+1][b1] + T[3c+2][b2]) >>> 24) + 0x70 (byte store, no clamping), byte3 untouched.
 * Rectangle: x in [x0, x1), y in [y0, y1); x0>=0, y1<=199 and (original quirk) y0<=319 are clamped.
 * @param {Uint32Array} scr @param {Int32Array} T 9*256
 */
export function colorMatrixRect(scr, x0, y0, x1, y1, T) {
  if (x0 < 0) x0 = 0; if (y0 > 0x13f) y0 = 0x13f; if (x1 < 0) x1 = 0; if (y1 > 199) y1 = 199;
  const w = x1 - x0, h = y1 - y0;
  for (let y = 0; y < h; y++) for (let x = 0; x < w; x++) {
    const i = (y0 + y) * 320 + x0 + x, d = scr[i];
    const b0 = d & 255, b1 = (d >>> 8) & 255, b2 = (d >>> 16) & 255;
    const o0 = (((T[b0] + T[256 + b1] + T[512 + b2]) | 0) >>> 24) + 0x70;
    const o1 = (((T[768 + b0] + T[1024 + b1] + T[1280 + b2]) | 0) >>> 24) + 0x70;
    const o2 = (((T[1536 + b0] + T[1792 + b1] + T[2048 + b2]) | 0) >>> 24) + 0x70;
    scr[i] = ((d & 0xff000000) | ((o2 & 255) << 16) | ((o1 & 255) << 8) | (o0 & 255)) >>> 0;
  }
}
export const f_22990 = colorMatrixRect;
