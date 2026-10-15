// node tools/test/g4.test.mjs vectors.json : compare _g4fx.js with the original (g4_gen.py)
import fs from 'fs';
import { planarUV, makeLattice, rippleSphere, blackHole, distanceColours } from '../../site/js/scenes/_g4fx.js';
import { loadMesh } from '../../site/js/lib/mesh3d.js';
const V = JSON.parse(fs.readFileSync(process.argv[2]));
const f32 = (s) => { const b = Buffer.from(s, 'base64'); return new Float32Array(b.buffer.slice(b.byteOffset, b.byteOffset + b.length)); };
const i32 = (s) => { const b = Buffer.from(s, 'base64'); return new Int32Array(b.buffer.slice(b.byteOffset, b.byteOffset + b.length)); };
const mob = new Uint8Array(fs.readFileSync(new URL('../../raw/3d/k_1.mob', import.meta.url)));
const cmp = (a, e) => { let bad = 0, mx = 0; for (let i = 0; i < e.length; i++) if (a[i] !== e[i]) { bad++; mx = Math.max(mx, Math.abs(a[i] - e[i]) / Math.max(1, Math.abs(e[i]))); } return `${bad}/${e.length} differ, max rel ${mx.toExponential(2)}`; };
let fails = 0;
const rep = (n, a, e) => { const r = cmp(a, e); const ok = r.startsWith('0/'); if (!ok) fails++; console.log(ok ? 'ok  ' : 'DIFF', n, r); };
for (const c of V) {
  if (c.fn === 'planarUV') { const m = loadMesh(mob); planarUV(m, c.w, c.h); rep(`planarUV ${c.w}x${c.h}`, m.uv, f32(c.uv)); }
  else if (c.fn === 'rippleSphere') { const m = loadMesh(mob); rippleSphere(m, Math.fround(c.t), c.amp); rep(`rippleSphere t=${c.t}`, m.xpts, f32(c.xpts)); }
  else if (c.fn === 'makeLattice') { const [a, b, d, s] = c.dims || [10, 10, 6, 50]; const m = makeLattice(a, b, d, s); if (m.npts !== c.npts || m.nedges !== c.nedges) { fails++; console.log('DIFF counts'); } rep(`lattice ${a}x${b}x${d} pts`, m.pts, f32(c.pts)); rep('lattice edges', m.edges, i32(c.edges)); }
  else if (c.fn === 'blackHole') { const m = makeLattice(10, 10, 6, 50), t = Math.fround(c.t); blackHole(m, t); rep(`blackHole t=${c.t}`, m.xpts, f32(c.xpts)); distanceColours(m, t, Math.fround(c.k)); rep('distanceColours', m.uv, f32(c.uv)); }
}
console.log(fails ? 'FAILED' : 'ALL OK'); process.exit(fails ? 1 : 0);
