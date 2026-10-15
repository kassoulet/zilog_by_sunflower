// GFX: image loader, port of FUN_00015a48 (asm @0x15a48).
// Header (22 bytes): 'GFX:' u32 w, u32 h, u8 bpp(8|0x18|0x20), u8 flags, u32 dataLen, u32 palLen
// flags: 1 = RLE (sparse 32bpp, zero = transparent) 2 = delta coded bytes 4 = planar channels.
// Result: {w,h,bpp,pal,px}. 32bpp -> px Uint32Array (dword = 0x00RRGGBB in *memory order B,G,R,0*), 8bpp -> px Uint8Array.
export function loadGfx(buf) {
  const dv = new DataView(buf.buffer, buf.byteOffset, buf.byteLength);
  if (String.fromCharCode(...buf.subarray(0, 4)) !== 'GFX:') throw Error('not GFX');
  const w = dv.getUint32(4, true), h = dv.getUint32(8, true), bpp = buf[12];
  let flags = buf[13]; const len = dv.getUint32(14, true), palLen = dv.getUint32(18, true);
  const pal = buf.slice(22, 22 + palLen);
  let data = buf.slice(22 + palLen, 22 + palLen + len);
  if (flags & 2) { let c = 0; for (let i = 0; i < len; i++) data[i] = c = (c + data[i]) & 255; }
  const bytes = (bpp + 1) >> 3;
  if ((flags & 4) && bytes > 1) {                                   // planar -> interleaved
    const t = new Uint8Array(len);
    for (let i = 0; i < len; i += bytes) for (let j = 0; j < bytes; j++) t[i + j] = data[Math.trunc((j * len + i) / bytes)];
    data = t;
  }
  if (bpp === 0x18) {                                               // 3 -> 4 bytes
    const t = new Uint8Array(len / 3 * 4);
    for (let i = 0, n = len / 3; i < n; i++) { t[i * 4] = data[i * 3]; t[i * 4 + 1] = data[i * 3 + 1]; t[i * 4 + 2] = data[i * 3 + 2]; }
    data = t;
  }
  const px = (bpp === 8) ? data : new Uint32Array(data.buffer, 0, data.length >> 2);
  if ((flags & 1) && bpp === 0x20) {
    // 'sparse' RLE variant is only an in-memory acceleration in the original (runs of zero pixels / literal pixels);
    // the decoded array is already plain dwords here, with 0 = transparent.
  }
  return { w, h, bpp: bpp === 0x18 ? 0x20 : bpp, pal, flags, px };
}
