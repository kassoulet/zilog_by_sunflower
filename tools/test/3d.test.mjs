// Differential test of site/js/lib/mesh3d*.js against the ORIGINAL engine (vectors made by 3d_gen.py under Unicorn).
//   node tools/test/3d.test.mjs [vectors.json]      (run_3d.sh regenerates the vectors first)
import fs from 'fs';
import { loadMesh, Obj3D, rotate, rotateNormals, faceNormals, vertexNormals, project, render, makeRenderContext, makeLuts } from '../../site/js/lib/mesh3d.js';

const file = process.argv[2] || new URL('../out/3d_vectors.json', import.meta.url).pathname;
const V = JSON.parse(fs.readFileSync(file));
const bytes = (n) => new Uint8Array(Buffer.from(V.blobs[n], 'base64'));
const f32 = (n) => { const b = bytes(n); return new Float32Array(b.buffer, b.byteOffset, b.length >> 2); };
const i32 = (n) => { const b = bytes(n); return new Int32Array(b.buffer, b.byteOffset, b.length >> 2); };
const u32 = (n) => { const b = bytes(n); return new Uint32Array(b.buffer, b.byteOffset, b.length >> 2); };
const luts = makeLuts();
let fails = 0; const rows = [];
const fr = Math.fround;
const same = (a, b) => a.length === b.length && a.every((v, i) => v === b[i]);
/** max abs error relative to max(1,|expected|) */
const relErr = (a, e) => { let m = 0; for (let i = 0; i < e.length; i++) m = Math.max(m, Math.abs(a[i] - e[i]) / Math.max(1, Math.abs(e[i]))); return m; };
const rep = (name, ok, info) => { rows.push(`${ok ? 'ok  ' : 'FAIL'} ${name} ${info}`); if (!ok) fails++; };

for (const c of V.cases) {
  if (c.kind === 'load') {
    const m = loadMesh(bytes(c.blob));
    const ok = m.npts === c.npts && m.nfaces === c.nfaces && m.nedges === c.nedges && same(m.vf, i32(c.vf)) && same(m.vfIdx, i32(c.vfIdx))
      && (!c.nedges || same(m.edgeFaces, i32(c.ef)));
    rep('load ' + c.mob, ok, `pts=${c.npts} faces=${c.nfaces} edges=${c.nedges}`);
  } else if (c.kind === 'xform') {
    const m = loadMesh(bytes(c.blob)); if (c.mask) m.mask = bytes(c.mask);
    const o = new Obj3D(m, { cx: c.cx, cy: c.cy, dist: c.dist, focal: c.focal, mode: 9 });
    rotate(o, fr(c.ang[0]), fr(c.ang[1]), fr(c.ang[2])); faceNormals(o); vertexNormals(m); rotateNormals(m, fr(c.ang2[0]), fr(c.ang2[1]), fr(c.ang2[2])); project(o);
    const errs = { xpts: relErr(m.xpts, f32(c.xpts)), fnrm: relErr(m.fnrm, f32(c.fnrm)), nrm: relErr(m.nrm, f32(c.nrm)), xnrm: relErr(m.xnrm, f32(c.xnrm)), p2d: relErr(m.p2d, f32(c.p2d)), invz: relErr(m.invz, f32(c.invz)) };
    o.mode = 0; rotate(o, fr(c.ang3[0]), fr(c.ang3[1]), fr(c.ang3[2])); errs.cum = relErr(m.xpts, f32(c.xpts_cum));
    const worst = Math.max(...Object.values(errs));
    rep('xform ' + c.mob + (c.mask ? ' (masked)' : ''), worst < 2e-3, 'max rel err ' + Object.entries(errs).map(([k, v]) => k + ':' + v.toExponential(1)).join(' '));
  } else if (c.kind === 'render') {
    const texB = c.tex && bytes(c.tex);
    const mkTex = () => !texB ? null : (c.mode === 9 ? texB.slice() : new Uint32Array(texB.slice().buffer));
    const bg = u32(c.bg), want = u32(c.out);
    for (const flavour of ['inj', 'full']) {
      const m = loadMesh(bytes(c.blob));
      if (c.uv) m.uv = f32(c.uv).slice();
      if (c.mask) m.mask = bytes(c.mask);
      if (c.npts_limit) m.npts = Math.min(m.npts, c.npts_limit);
      const tex = mkTex();
      const o = new Obj3D(m, { cx: c.cx, cy: c.cy, dist: c.dist, focal: c.focal, tex: c.mode === 4 && c.sub === 4 ? new Uint32Array(bg) : tex, mode: 9, sub: c.sub });
      if (c.colors) o.colors = u32(c.colors);
      const ctx = makeRenderContext(new Uint32Array(bg), luts);
      if (flavour === 'inj') {
        const n = loadMesh(bytes(c.blob)).npts;
        m.xpts = f32(c.inj.xpts).slice(); m.nrm = f32(c.inj.nrm).slice(); m.xnrm = f32(c.inj.xnrm).slice(); m.p2d = f32(c.inj.p2d).slice(); m.invz = f32(c.inj.invz).slice(); m.fnrm = f32(c.inj.fnrm).slice();
      } else {
        rotate(o, fr(c.ang[0]), fr(c.ang[1]), fr(c.ang[2])); faceNormals(o); vertexNormals(m); rotateNormals(m, fr(c.nang[0]), fr(c.nang[1]), fr(c.nang[2])); project(o);
      }
      o.mode = c.mode; o.sub = c.sub;
      render(o, ctx);
      let bad = 0, big = 0;
      for (let i = 0; i < 64000; i++) if (ctx.target[i] !== want[i]) { bad++; const a = ctx.target[i], b = want[i]; if (Math.abs((a & 255) - (b & 255)) > 8 || Math.abs(((a >> 8) & 255) - ((b >> 8) & 255)) > 8) big++; }
      const changed = want.reduce((s, v, i) => s + (v !== bg[i] ? 1 : 0), 0);
      // inj must be bit exact; full may differ by float rounding at polygon edges
      let sortInfo = '';
      if (c.order) { const wo = i32(c.order), wk = i32(c.keys); const so = same(m.order.slice(0, m.nvis), wo), sk = same(m.key.slice(0, m.nvis), wk); sortInfo = ` sort[order ${so ? 'ok' : 'DIFF'} keys ${sk ? 'ok' : 'DIFF'}]`; }
      // inj: must be bit exact; full: allow a few pixels (Math.sin/cos of other JS engines may differ in the last ulp)
      const ok = flavour === 'inj' ? bad === 0 : bad <= 20;
      rep(`render ${c.name} [${flavour}]`, ok, `mode ${c.mode}/${c.sub} changed px ${changed}, mismatching ${bad} (>8: ${big})${sortInfo}`);
    }
  }
}
console.log(rows.join('\n'));
console.log(fails ? `\n${fails} FAILED of ${rows.length}` : `\nall ${rows.length} passed`);
process.exit(fails ? 1 : 0);
