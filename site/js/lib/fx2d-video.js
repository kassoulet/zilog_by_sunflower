// fx2d-video: the frame flip of ZILOG.EXE (func_17c11) for the web: dword screen -> RGBA bytes of a canvas.
//
// Original flip: tries VESA modes 32,24,16,15,(12,11 fake),8 bpp at 320x200 (func_251e7 = set mode). In DOSBox the 32bpp
// LFB mode (VBE 0x10F) is available, so the screen buffer is copied 1:1 (func_1c48f, 0x3e800 bytes) to the framebuffer
// (or banked: 0x254ba).  A VESA 32bpp pixel in memory is B,G,R,x, i.e. screen dword = 0x00RRGGBB (byte0 = BLUE, byte2 = RED).
// => displayed colour: R = byte2, G = byte1, B = byte0.   (Writing the dword unchanged into a canvas Uint32Array, which expects
// bytes R,G,B,A, would swap red and blue - that is the "R/B swapped" effect seen in the first comparisons.)
// 24bpp (0x257bb) is the same bytes without the 4th.  16bpp (0x25649, RGB565) and 15bpp (0x2570c, RGB555) quantise:
//   565: (b0>>3) | (b1>>2)<<5 | (b2>>3)<<11      555: (b0>>3) | (b1>>3)<<5 | (b2>>3)<<10      (b0=blue, b2=red)

/**
 * Reproduces what the DOSBox reference shows.
 * @param {Uint32Array} scr 64000 dwords @param {Uint8ClampedArray|Uint8Array} out 64000*4 RGBA
 * @param {32|24|16|15} [bpp=32] mode the original selected (32 in DOSBox); 16/15 quantise like the converters and expand with c<<3|c>>2 (c<<2|c>>4 for green)
 */
export function presentToRGBA(scr, out, bpp = 32) {
  if (bpp >= 24) {
    for (let i = 0, o = 0; i < 64000; i++, o += 4) { const d = scr[i]; out[o] = (d >>> 16) & 255; out[o + 1] = (d >>> 8) & 255; out[o + 2] = d & 255; out[o + 3] = 255; /* masks: canvas ImageData is a Uint8ClampedArray (clamps, does not wrap) */ }
    return out;
  }
  for (let i = 0, o = 0; i < 64000; i++, o += 4) {
    const d = scr[i], b = d & 255, g = (d >>> 8) & 255, r = (d >>> 16) & 255;
    let r5 = r >> 3, b5 = b >> 3, g6, gb;
    if (bpp === 16) { g6 = g >> 2; gb = (g6 << 2) | (g6 >> 4); } else { g6 = g >> 3; gb = (g6 << 3) | (g6 >> 2); }
    out[o] = (r5 << 3) | (r5 >> 2); out[o + 1] = gb; out[o + 2] = (b5 << 3) | (b5 >> 2); out[o + 3] = 255;
  }
  return out;
}

/** the 16bit VGA word written by func_25649 (16bpp, RGB565) or func_2570c (15bpp, RGB555) for one screen dword. */
export function packRGB16(d, bpp = 16) {
  const b = d & 255, g = (d >>> 8) & 255, r = (d >>> 16) & 255;
  return bpp === 16 ? ((b >> 3) | ((g >> 2) << 5) | ((r >> 3) << 11)) : ((b >> 3) | ((g >> 3) << 5) | ((r >> 3) << 10));
}

/**
 * ported from func_17c11 (0x17c11) debug overlay (shown while the space key (scancode 0x39) is held): three printText calls
 * at y = 0 / 10 / 20 with the strings "Video mode: ..", "Audio device: %s, port %xh, irq %d, dma %d" and "fps: %d\norder: %02xh\nrow: %02xh".
 * Returns the (text, y) list; the caller prints them with printText(scr, text, 0, y, font, tabA, tabB).
 */
export function debugOverlayLines(videoMode, audioDesc, fps, order, row) {
  const h = (v) => v.toString(16).padStart(2, '0');
  return [[`Video mode: ${videoMode}`, 0], [audioDesc, 10], [`fps: ${fps}\norder: ${h(order)}h\nrow: ${h(row)}h`, 20]];
}

/**
 * The bytes the original flip writes to the VESA framebuffer, in order (func_254ba 32bpp, func_257bb 24bpp, func_25649 16bpp, func_2570c 15bpp).
 * @param {Uint32Array} scr @param {32|24|16|15} bpp @returns {Uint8Array}
 */
export function vesaFramebuffer(scr, bpp = 32) {
  const n = scr.length, bytes = bpp === 32 ? 4 : bpp === 24 ? 3 : 2, out = new Uint8Array(n * bytes);
  for (let i = 0, o = 0; i < n; i++) {
    const d = scr[i];
    if (bpp === 32) { out[o++] = d; out[o++] = d >>> 8; out[o++] = d >>> 16; out[o++] = d >>> 24; }
    else if (bpp === 24) { out[o++] = d; out[o++] = d >>> 8; out[o++] = d >>> 16; }
    else { const w = packRGB16(d, bpp); out[o++] = w; out[o++] = w >>> 8; }
  }
  return out;
}
