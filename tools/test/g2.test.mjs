// Differential test of site/js/scenes/_g2fx.js against the original (vectors from g2_gen.py).  node tools/test/g2.test.mjs [vectors.json]
import fs from 'fs';
import { loadMesh, Obj3D, makeRenderContext, makeLuts } from '../../site/js/lib/mesh3d.js';
import { ringMesh, wobbleMesh, sineBlobMesh, waveColours, lensNodes, renderFacesHalf, spritesHalf } from '../../site/js/scenes/_g2fx.js';
const V = JSON.parse(fs.readFileSync(process.argv[2] || new URL('../out/g2_vectors.json', import.meta.url).pathname));
const bytes = (n) => new Uint8Array(Buffer.from(V.blobs[n], 'base64'));
const f32 = (n) => { const b = bytes(n); return new Float32Array(b.buffer, b.byteOffset, b.length >> 2); };
const i32 = (n) => { const b = bytes(n); return new Int32Array(b.buffer, b.byteOffset, b.length >> 2); };
const u32 = (n) => { const b = bytes(n); return new Uint32Array(b.buffer, b.byteOffset, b.length >> 2); };
const raw = (n) => new Uint8Array(fs.readFileSync(new URL('../../raw/3d/' + n, import.meta.url)));
const luts = makeLuts(); let fails = 0; const agg = {};
const note = (k, ok, info) => { const a = agg[k] ??= { n: 0, bad: 0, worst: 0, info: '' }; a.n++; if (!ok) { a.bad++; a.info = info; fails++; } };
const rel = (a, e) => { let m = 0, ex = 0; for (let i = 0; i < e.length; i++) { const d = Math.abs(a[i] - e[i]) / Math.max(1, Math.abs(e[i])); if (d > m) m = d; if (a[i] === e[i]) ex++; } return [m, ex / e.length]; };
const mk = (c) => { let m; if (c.mob === 'ring') m = ringMesh(26, 5, 800); else m = loadMesh(raw(c.mob)); m.pts = f32(c.pts).slice(); return m; };
for (const c of V.cases) {
  if (c.k === 'ring') {
    const m = ringMesh(26, 5, 800), [e] = rel(m.pts, f32(c.pts));
    note('ring', e < 1e-6 && m.edges.every((v, i) => v === i32(c.edges)[i]) && m.npts === c.n, 'err ' + e);
  } else if (c.k === 'wobble' || c.k === 'blob') {
    const m = mk(c); (c.k === 'wobble' ? wobbleMesh(m, Math.fround(c.t)) : sineBlobMesh(m, Math.fround(c.t), 60));
    const [e, ex] = rel(m.xpts, f32(c.out)); const a = agg[c.k + ' ' + c.mob]; note(c.k + ' ' + c.mob, e < 2e-4, `t=${c.t} err ${e}`);
    agg[c.k + ' ' + c.mob].worst = Math.max(agg[c.k + ' ' + c.mob].worst, e); agg[c.k + ' ' + c.mob].exact = Math.min(agg[c.k + ' ' + c.mob].exact ?? 1, ex);
  } else if (c.k === 'uv') {
    const m = mk(c); waveColours(m, Math.fround(c.t), Math.fround(0.1));
    const want = f32(c.out), got = m.uv, k = 'uv ' + c.mob; let e = 0; for (let i = 0; i < c.n; i++) e = Math.max(e, Math.abs(got[i * 2] - want[i * 2]));
    note(k, e < 0.01, `t=${c.t} err ${e}`); agg[k].worst = Math.max(agg[k].worst, e);
  } else if (c.k === 'lens') {
    const n = new Int32Array(41 * 26 * 3); lensNodes(n, Math.fround(c.t)); const w = i32(c.out); let bad = 0, big = 0;
    for (let i = 0; i < n.length; i++) if (n[i] !== w[i]) { bad++; if (Math.abs(n[i] - w[i]) > 4) big++; }
    note('lens', big === 0, `t=${c.t} diff ${bad} big ${big}`); agg.lens.worst += bad; agg.lens.exact = 0;
  } else if (c.k === 'half' || c.k === 'sprites') {
    const m = loadMesh(raw(c.k === 'half' ? c.mob : '3d/sph1024.mob'.slice(3)));
    m.xpts = f32(c.inj.xpts).slice(); m.nrm = f32(c.inj.nrm).slice(); m.p2d = f32(c.inj.p2d).slice(); m.invz = f32(c.inj.invz).slice(); m.fnrm = f32(c.inj.fnrm).slice();
    const bg = u32(c.bg), want = u32(c.out), ctx = makeRenderContext(new Uint32Array(bg), luts);
    if (c.k === 'half') { const o = new Obj3D(m, { tex: u32(c.tex), mode: 0, sub: 0 }); renderFacesHalf(o, ctx, c.fn === 'far' ? 1 : -1); }
    else { const o = new Obj3D(m, { tex: bytes(c.spot), mode: 9, sub: 6 }); spritesHalf(o, ctx, Math.fround(17), c.far); }
    let bad = 0; for (let i = 0; i < 64000; i++) if (ctx.target[i] !== want[i]) bad++;
    const changed = want.reduce((s, v, i) => s + (v !== bg[i] ? 1 : 0), 0);
    note(c.k + (c.fn ?? c.far), bad === 0 && changed > 0, `diff px ${bad} changed ${changed}`);
  }
}
for (const [k, a] of Object.entries(agg)) console.log(a.bad ? 'FAIL' : 'ok  ', k.padEnd(18), `${a.n - a.bad}/${a.n}`, a.worst ? 'worst ' + a.worst.toExponential(1) : '', a.exact != null ? 'exact frac ' + a.exact.toFixed(3) : '', a.bad ? a.info : '');
console.log(fails ? fails + ' FAILED' : 'all ok'); process.exit(fails ? 1 : 0);
