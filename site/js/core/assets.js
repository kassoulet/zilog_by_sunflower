// Asset container of ZILOG.EXE ("DATA?" + 63 x [u32 size, char name[32], 'LZW:' u32 outLen, bits...]).
// The demo's own GIF-style LZW (asm @0x24568): LSB-first, 9..12 bit codes, 0x100=clear, 0x101=end.
export function lzw(src, outLen) {
  const out = new Uint8Array(outLen), pre = new Uint16Array(4096), suf = new Uint8Array(4096), stack = new Uint8Array(4096);
  let o = 0, bit = 0, w = 9, next = 0x102, old = -1, first = 0;
  while (o < outLen) {
    const p = bit >> 3, v = ((src[p] | src[p + 1] << 8 | src[p + 2] << 16) >> (bit & 7)) & ((1 << w) - 1); bit += w;
    if (v === 0x101) break;
    if (v === 0x100) { w = 9; next = 0x102; old = -1; continue; }
    if (old < 0) { out[o++] = first = v; old = v; continue; }
    let c = v, sp = 0;
    if (v >= next) { stack[sp++] = first; c = old; }          // KwKwK case
    while (c > 255) { stack[sp++] = suf[c]; c = pre[c]; }
    stack[sp++] = first = c;
    while (sp && o < outLen) out[o++] = stack[--sp];
    pre[next] = old; suf[next] = first; next++;
    if (next >= (1 << w) && w < 12) w++;
    old = v;
  }
  return out;
}

/** @param {Uint8Array} dat the "DATA?" container (starting at the 'DATA' magic) -> Map<name, Uint8Array> */
export function parseContainer(dat) {
  const dv = new DataView(dat.buffer, dat.byteOffset, dat.byteLength);
  if (String.fromCharCode(...dat.subarray(0, 4)) !== 'DATA') throw Error('not a DATA container');
  const n = dv.getUint32(4, true), files = new Map(); let p = 8;
  for (let i = 0; i < n; i++) {
    const sz = dv.getUint32(p, true);
    let name = ''; for (let k = 0; k < 32 && dat[p + 4 + k]; k++) name += String.fromCharCode(dat[p + 4 + k]);
    const d = dat.subarray(p + 36, p + 36 + sz);
    if (String.fromCharCode(...d.subarray(0, 4)) !== 'LZW:') throw Error('bad LZW ' + name);
    files.set(name.replace(/\\/g, '/'), lzw(d.subarray(8), new DataView(d.buffer, d.byteOffset).getUint32(4, true)));
    p += 36 + sz;
  }
  return files;
}
