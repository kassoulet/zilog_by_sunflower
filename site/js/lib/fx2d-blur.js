// fx2d-blur: box blur family of ZILOG.EXE (running sum + division lookup table, self-modifying code in the original).
//
// Original trick: for width w a 256*w byte table holds T[s] = floor(s/w) (built by func_16b44 / func_16c93: for v in 0..255
// write v w times).  Each colour channel keeps a *pointer* (table base + running sum of the window) in a register
// (eax = byte0, edi = byte1, ebp = byte2); the blurred byte is simply `mov bl,[eax]`.  The sliding window add/sub is
// done on the pointers; strides, radius and src->dst distance are patched into the code as immediates (0x11111111).
// Byte3 of the pixel is *not* blurred: it comes from the last pixel loaded (see comments), kept for exactness.
//
// Window of output p covers source pixels [p-half, p+n-1] with n = r-half, half = r>>1, zero padded outside the
// line, always divided by r (so the borders fade towards black).  Needs r >= 3 (r=1,2 make the do-while end loops wrap 2^32 times in the original).

/** divTable(w): the table of func_16b44 -> Uint8Array(256*w), T[s]=floor(s/w) (build, for tests / reference). */
export function divTable(w) {
  const t = new Uint8Array(256 * w);
  for (let v = 0, o = 0; v < 256; v++) for (let k = 0; k < w; k++) t[o++] = v;
  return t;
}
export const f_16b44 = divTable;

/**
 * One line of the box blur (shared body of f_16cdd / f_16e53 / f_16ffb / vertical): generic strided.
 * @param {Uint32Array} dst @param {Uint32Array} src  (may be the same array: the original reads src live)
 * @param {number} so first src index @param {number} dO first dst index @param {number} step index stride
 * @param {number} len line length (320 or 200) @param {number} r radius (width of the box, 3..255)
 */
export function blurLine(dst, src, so, dO, step, len, r) {
  const half = r >> 1, n = r - half;
  let s0 = 0, s1 = 0, s2 = 0, hi = 0;
  const ld = (i) => { const v = src[so + i * step]; hi = v >>> 24; return v; };
  const add = (i) => { const v = ld(i); s0 += v & 255; s1 += (v >>> 8) & 255; s2 += (v >>> 16) & 255; };
  const sub = (i) => { const v = ld(i); s0 -= v & 255; s1 -= (v >>> 8) & 255; s2 -= (v >>> 16) & 255; };
  const out = (p) => { dst[dO + p * step] = ((hi << 24) | (((s2 / r) | 0) << 16) | (((s1 / r) | 0) << 8) | ((s0 / r) | 0)) >>> 0; };
  for (let i = n - 1; i >= 0; i--) add(i);                  // window of pixel 0: pixels 0..n-1
  out(0);
  let p = 1;
  for (let k = -half; k < 0; k++, p++) { add(r + k); out(p); }          // grow: pixels n..r-1
  for (let k = len - r; k > 0; k--, p++) { add(p + n - 1); sub(p - half - 1); out(p); }  // slide
  for (let k = n - 1; k > 0; k--, p++) { sub(p - half - 1); out(p); }   // shrink at the end
}

/**
 * ported from func_16cdd (0x16cdd): horizontal box blur of a whole 320x200 dword image, radius r (eax), src esi, dst edi.
 * @param {Uint32Array} dst @param {Uint32Array} src @param {number} r  3..255 (division table width; the demo uses < 64 and the
 * big-table path of func_16b44 for larger ones)
 */
export function boxBlurH(dst, src, r) {
  for (let y = 0; y < 200; y++) blurLine(dst, src, y * 320, y * 320, 1, 320, r);
}
export const f_16cdd = boxBlurH;

/** ported from func_16e53 (0x16e53): vertical box blur of 320x200 (stride 0x500 bytes), radius r. */
export function boxBlurV(dst, src, r) {
  for (let x = 0; x < 320; x++) blurLine(dst, src, x, x, 320, 200, r);
}
export const f_16e53 = boxBlurV;

/**
 * ported from func_16ffb (0x16ffb): horizontal blur with a per-scanline radius (200 int32 radii).
 * radius < 3: scanline copied unchanged; radius clamped to 63.
 */
export function boxBlurHVar(dst, src, radii) {
  for (let y = 0; y < 200; y++) {
    let r = radii[y] | 0;
    if (r < 3) { for (let x = 0; x < 320; x++) dst[y * 320 + x] = src[y * 320 + x]; continue; }
    if (r >= 0x40) r = 0x3f;
    blurLine(dst, src, y * 320, y * 320, 1, 320, r);
  }
}
export const f_16ffb = boxBlurHVar;

/**
 * ported from func_1743b (0x1743b): "radial / path blur" on an 8-bit image.
 * `path` is a list of pixel offsets (uint16) with 0x17800 + 2^n entries (the ray table of func_14d0b: 512 rays x 188 steps).
 * out[path[k]] = (sum over window path[k+1..k+2^n] ... ) >> n  : a running 16-bit sum of src[path[j]], j = k..k+2^n-1,
 * written to `out` at path[k] (the average of the next 2^n pixels along the ray).  Afterwards holes are filled with
 * out[dst] = out[src] for each (src,dst) pair (uint16 pairs from func_14d0b).
 * @param {number} n log2 of the window (<=8) @param {Uint16Array} path @param {Uint8Array} src @param {Uint8Array} out
 * @param {Uint16Array} pairs @param {number} npairs
 */
export function radialPathBlur(n, path, src, out, pairs, npairs) {
  const W = 1 << n;
  let ax = 0;
  for (let k = 0; k < W; k++) ax = (ax + src[path[k]]) & 0xffff;
  for (let k = 0; k < 0x17800; k++) {
    out[path[k]] = (((ax >>> n) | (ax << (16 - n))) & 255);      // ror ax,n ; al   (== (ax>>n)&255)
    ax = (ax - src[path[k]]) & 0xffff;
    ax = (ax + src[path[k + W]]) & 0xffff;
  }
  for (let i = 0; i < npairs; i++) out[pairs[2 * i + 1]] = out[pairs[2 * i]];
}
export const f_1743b = radialPathBlur;
