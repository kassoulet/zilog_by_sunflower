// helper for 3d_gen.py: dump decoded GFX textures + MOB files used by the 3D differential tests (JSON, base64)
import fs from 'fs';
import { loadGfx } from '../../site/js/core/gfx.js';
const out = process.argv[2], root = new URL('../../raw/', import.meta.url).pathname;
const res = {};
for (const n of ['textures/env1.gfx', 'textures/max_t2.gfx', 'textures/cityscap.gfx', 'textures/plzm.gfx', 'fullpics/simulcra.gfx']) {
  const g = loadGfx(new Uint8Array(fs.readFileSync(root + n)));
  res[n] = { w: g.w, h: g.h, bpp: g.bpp, px: Buffer.from(g.px.buffer, g.px.byteOffset, g.px.byteLength).toString('base64') };
}
for (const n of ['3d/zilog1.mob', '3d/3b_2.mob', '3d/sph1024.mob', '3d/cyl.mob', '3d/hexp_on2.mob', '3d/cones3.mob', '3d/cub_tun2.mob'])
  res[n] = { px: fs.readFileSync(root + n).toString('base64') };
fs.writeFileSync(out, JSON.stringify(res));
