// helper for fx2d_gen.py: dump a few decoded GFX images (JSON: w,h,bpp,flags,px as base64) from raw/ using site/js/core/gfx.js
import fs from 'fs';
import { loadGfx } from '../../site/js/core/gfx.js';
const out = process.argv[2], root = new URL('../../raw/', import.meta.url).pathname;
const names = ['fullpics/simulcra.gfx', 'fullpics/mask5.gfx', 'fullpics/truesimu.gfx', 'smalpics/jp05.gfx', 'smalpics/jp01.gfx', 'fonts/sysf.gfx', 'fonts/verdana.gfx', 'fonts/verd_sm.gfx', 'textures/lites2.gfx', 'textures/env1.gfx', 'fullpics/spot.gfx', 'textures/plzm.gfx'];
const res = {};
for (const n of names) {
  const g = loadGfx(new Uint8Array(fs.readFileSync(root + n)));
  res[n] = { w: g.w, h: g.h, bpp: g.bpp, flags: g.flags, px: Buffer.from(g.px.buffer, g.px.byteOffset, g.px.byteLength).toString('base64') };
}
fs.writeFileSync(out, JSON.stringify(res));
