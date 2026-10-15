// Differential test of site/js/scenes/_g5mesh.js + _g5draw.js against the ORIGINAL code (vectors from g5_gen.py).   node tools/test/g5.test.mjs [vectors.json]
import fs from 'fs';
import { loadMesh, Obj3D, rotate, project, makeRenderContext } from '../../site/js/lib/mesh3d.js';
import * as M from '../../site/js/scenes/_g5mesh.js';
import { makeEnv } from '../../site/js/env.js';
import * as D from '../../site/js/scenes/_g5draw.js';
const V = JSON.parse(fs.readFileSync(process.argv[2] || new URL('../out/g5_vectors.json', import.meta.url).pathname));
const raw = (n) => new Uint8Array(fs.readFileSync(new URL('../../raw/3d/' + n, import.meta.url)));
const B = (s) => new Uint8Array(Buffer.from(s, 'base64'));
const F32 = (s) => { const b = B(s); return new Float32Array(b.buffer, 0, b.length >> 2); };
const I32 = (s) => { const b = B(s); return new Int32Array(b.buffer, 0, b.length >> 2); };
const U32 = (s) => { const b = B(s); return new Uint32Array(b.buffer, 0, b.length >> 2); };
const rel = (a, e) => { let m = 0, ex = 0; for (let i = 0; i < e.length; i++) { const d = Math.abs(a[i] - e[i]); if (d) ex++; m = Math.max(m, d / Math.max(1, Math.abs(e[i]))); } return [m, ex]; };
const env = makeEnv(new Uint8Array(fs.readFileSync(new URL('../../site/data/data.dat', import.meta.url))));
let fails = 0; const rep = (ok, s) => { console.log((ok ? 'ok   ' : 'FAIL ') + s); if (!ok) fails++; };
const same = (a, b) => a.length === b.length && a.every((v, i) => v === b[i]);
const fr = Math.fround;
for (const c of V.cases) {
  if (c.kind === 'prep') {
    const m = loadMesh(raw(c.mob)), fn = c.fn;
    if (fn === '0x1b687') M.f_1b687(m); else if (fn === '0x1b04f') M.f_1b04f(m, c.args.edx, c.args.ebx);
    else if (fn === '0x1b1b4') M.f_1b1b4(m); else if (fn === '0x1b7e3') M.f_1b7e3(m);
    else if (fn === '0x1b854') { const t = M.f_1b854(m); rep(same(t, I32(c.ret)), `prep ${fn} ${c.mob} table`); continue; }
    const o = c.out; let ok = same(m.faces, I32(o.faces)) && same(m.pts, F32(o.pts)); let info = '';
    if (o.uv) { const [e, n] = rel(m.uv, F32(o.uv)); if (fn === '0x1b1b4') { for (let i = 1; i < m.uv.length; i += 2) {} } info = ` uv maxrel ${e.toExponential(1)} diff ${n}`; ok = ok && e < 1e-6; }
    rep(ok, `prep ${fn} ${c.mob}${info}`);
  } else if (c.kind === 'grid') {
    const g = M.f_1b960(20, 20, 50); M.f_1b2a4(g);
    rep(same(g.pts, F32(c.pts)) && same(g.edges, I32(c.edges)) && same(g.uv, F32(c.uv)) && g.nedges === c.nedges, 'grid 1b960 + 1b2a4');
  } else if (c.kind === 'deform') {
    let m = c.mob === 'grid' ? M.f_1b960(20, 20, 50) : loadMesh(raw(c.mob)); m.xpts = new Float32Array(m.npts * 3);
    const t = fr(c.t);
    if (c.name === '20a10') M.f_20a10(m, t); else if (c.name === '2112c') M.f_2112c(m, t);
    else if (c.name === '21664') M.f_21664(m, fr(c.p[1]), fr(c.p[2]), fr(c.p[0]), t);
    else if (c.name === '206e0') M.f_206e0(m, t);
    else if (c.name === '219e8') { M.f_1b7e3; M.f_219e8(m, I32(c.pair), fr(c.pv), t); }
    const [e, n] = rel(m.xpts, F32(c.out));
    rep(e < 2e-5, `deform ${c.name} ${c.mob} t=${c.t} maxrel ${e.toExponential(1)} (${n}/${m.xpts.length} differ)`);
  } else if (c.kind === 'draw') {
    const m = loadMesh(raw(c.mob)); m.xpts = F32(c.inj.xpts).slice(); m.p2d = F32(c.inj.p2d).slice(); m.invz = F32(c.inj.invz).slice();
    if (c.uvsrc) m.uv = F32(c.uvsrc).slice();
    const ctx = makeRenderContext(new Uint32Array(U32(c.bg)));
    const o = new Obj3D(m, { cx: c.cam.cx, cy: c.cam.cy, dist: c.cam.dist, focal: c.cam.focal, tex: B(c.tex), mode: c.mode, sub: c.sub });
    const mask = env.gfx('fullpics/hmask2.gfx').px;
    if (c.draw === 'tri') D.f_1ac25(o, ctx); else if (c.draw === 'spr_front') D.f_1a415(o, mask, fr(c.p), ctx);
    else if (c.draw === 'spr_back') D.f_1a5ea(o, fr(c.p), ctx); else D.f_19f57(o, fr(c.p), ctx);
    const want = U32(c.out), bg = U32(c.bg); let bad = 0, chg = 0; for (let i = 0; i < 64000; i++) { if (ctx.target[i] !== want[i]) bad++; if (want[i] !== bg[i]) chg++; }
    const oob = c.name === 'spr_front_b' ? 8 : 0;   // sprites left of the screen read the mask at a negative index: heap garbage in the original
    rep(bad <= oob && chg > 0, `draw ${c.name} (${c.draw}) changed px ${chg}, differing px ${bad}`);
  }
}
console.log(fails ? fails + ' FAILED' : 'all ok'); process.exit(fails ? 1 : 0);
