// fx2d-text: bitmap font object + text printer of ZILOG.EXE (320x200 dword screen).

/**
 * ported from func_17e46 (0x17e46 -> 0x25e60): memset(ptr, byte, n)  (byte replicated to a dword, aligned fill).
 * @param {Uint8Array} a @param {number} off @param {number} val @param {number} n
 */
export function memset(a, off, val, n) { a.fill(val & 255, off, off + n); }
export const f_17e46 = memset;
/** ported from func_1c48f (0x1c48f): memcpy(dst, src, n) (repne movsd + movsb tail). */
export function memcpy(dst, dOff, src, sOff, n) { dst.set(src.subarray(sOff, sOff + n), dOff); }
export const f_1c48f = memcpy;

/**
 * ported from func_174fe (0x174fe): font object from an 8-bit GFX strip (all glyphs side by side).
 * A glyph boundary is any pixel column that is entirely 0.  For the k-th boundary found at column x (cur = columns
 * since the previous boundary, the counter is reset to 1 *after* a boundary, so boundary columns belong to the
 * start of the next glyph): offs[k] = x - cur, wid[k] = cur.
 * @param {{w:number,h:number,px:Uint8Array}} gfx 8-bit image  @param {number} first char code of glyph 0  @param {number} nchars
 */
export function buildFont(gfx, first, nchars) {
  const offs = new Uint16Array(nchars), wid = new Uint8Array(nchars);
  let n = 0, cur = 0;
  for (let x = 0; x < gfx.w; x++) {
    let or = 0;
    for (let y = 0; y < gfx.h; y++) or |= gfx.px[y * gfx.w + x];
    if (or === 0) { offs[n] = (x - cur) & 0xffff; wid[n] = cur; n++; cur = 0; }
    cur++;
  }
  return { px: gfx.px, w: gfx.w, h: gfx.h, nchars, first: first & 255, offs, wid };
}
export const f_174fe = buildFont;

/**
 * ported from func_24cf0 (0x24cf0): draw one glyph, "screen" blend.  For each non-zero glyph pixel g:
 *   cov = ~tab[(~alpha)<<8 | ~g]   (== coverage a*g/256 with the screen table 0x402f4)
 *   dest_channel = tab[cov<<8 | dest_channel]   for the 3 colour bytes, byte 3 untouched.
 * (Original: `mov eax,ebp; mov al,[esi]; ...; mov ah,0x11(patched: ~alpha); mov ah,[eax]` - a 64 KB aligned table pointer
 * is used as a base and its low 16 bits replaced by the two indices.)
 * @param {Uint32Array} scr @param {number} di dest index (y*320+x) @param {object} font @param {number} ch @param {Uint8Array} tab 64K blend table @param {number} alpha 0..255
 */
export function glyphBlend(scr, di, font, ch, tab, alpha) {
  const gi = ((ch - font.first) & 0xffffffff) >>> 0;
  const gw = font.wid[gi], so = font.offs[gi], na = ~alpha & 255;
  for (let y = 0; y < font.h; y++) {
    for (let x = 0; x < gw; x++, di++) {
      const g = font.px[y * font.w + so + x];
      if (g === 0) continue;
      const cov = ~tab[(na << 8) | (~g & 255)] & 255, d = scr[di];
      scr[di] = ((d & 0xff000000) | (tab[(cov << 8) | ((d >>> 16) & 255)] << 16) | (tab[(cov << 8) | ((d >>> 8) & 255)] << 8) | tab[(cov << 8) | (d & 255)]) >>> 0;
    }
    di += 320 - gw;
  }
}
export const f_24cf0 = glyphBlend;

/**
 * ported from func_24d79 (0x24d79): draw one glyph, "darken" variant (used with the inverted blend table 0x402f8):
 *   cov = tab[(~alpha)<<8 | ~g];  dest = ~dest;  dest_channel' = tab[cov<<8 | dest_channel]   (colour bytes);  byte 3 comes out inverted.
 */
export function glyphDarken(scr, di, font, ch, tab, alpha) {
  const gi = ((ch - font.first) & 0xffffffff) >>> 0;
  const gw = font.wid[gi], so = font.offs[gi], na = ~alpha & 255;
  for (let y = 0; y < font.h; y++) {
    for (let x = 0; x < gw; x++, di++) {
      const g = font.px[y * font.w + so + x];
      if (g === 0) continue;
      const cov = tab[(na << 8) | (~g & 255)], d = ~scr[di] >>> 0;
      scr[di] = ((d & 0xff000000) | (tab[(cov << 8) | ((d >>> 16) & 255)] << 16) | (tab[(cov << 8) | ((d >>> 8) & 255)] << 8) | tab[(cov << 8) | (d & 255)]) >>> 0;
    }
    di += 320 - gw;
  }
}
export const f_24d79 = glyphDarken;

/**
 * ported from func_17641 (0x17641): text printer.  Control codes: 0x20 space (advance 5+spacing), 0x0a newline
 * (y += font.h + lineExtra, x back to start), 0x0b toggle blend mode (screen / darken), 0x08 <b> set alpha b,
 * 0x07 <c> letter spacing = c-'0', 0x0c <c> extra line spacing = c-'0'.  Any other byte is a glyph (no clipping!).
 * @param {Uint32Array} scr 320x200 @param {string|Uint8Array} str @param {number} x @param {number} y @param {object} font
 * @param {Uint8Array} tabScreen table of ctx+0xc (screen blend, DAT_000402f4) @param {Uint8Array} tabDark DAT_000402f8
 */
export function printText(scr, str, x, y, font, tabScreen, tabDark) {
  const s = typeof str === 'string' ? Uint8Array.from(str, (c) => c.charCodeAt(0) & 255) : str;
  let mode = 0, alpha = 0xff, spacing = 0, lineExtra = 0, cx = x, cy = y;
  for (let i = 0; i < s.length; i++) {
    const c = s[i];
    if (c === 0x20) { cx += spacing + 5; continue; }
    if (c === 0x0a) { cy += font.h + lineExtra; cx = x; continue; }
    if (c === 0x0b) { mode = 1 - mode; continue; }
    if (c === 8) { alpha = s[++i]; continue; }
    if (c === 7) { spacing = s[++i] - 0x30; continue; }
    if (c === 0x0c) { lineExtra = s[++i] - 0x30; continue; }
    const di = cy * 320 + cx;
    if (mode === 0) glyphBlend(scr, di, font, c, tabScreen, alpha); else glyphDarken(scr, di, font, c, tabDark, alpha);
    cx += font.wid[(c - font.first) & 0xffffffff] + spacing;
  }
}
export const f_17641 = printText;
