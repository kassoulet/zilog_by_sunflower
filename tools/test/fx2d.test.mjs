// node tools/test/fx2d.test.mjs vectors.json   (vectors from fx2d_gen.py = outputs of the original code under Unicorn)
import fs from 'fs';
import * as X from '../../site/js/lib/fx2d.js';
const tests = JSON.parse(fs.readFileSync(process.argv[2], 'utf8'));
const B = (s) => new Uint8Array(Buffer.from(s, 'base64'));
const U32 = (u8) => new Uint32Array(u8.buffer.slice(u8.byteOffset, u8.byteOffset + u8.length));
const U16 = (u8) => new Uint16Array(u8.buffer.slice(u8.byteOffset, u8.byteOffset + u8.length));
const I32 = (u8) => new Int32Array(u8.buffer.slice(u8.byteOffset, u8.byteOffset + u8.length));
const raw = (a) => new Uint8Array(a.buffer, a.byteOffset, a.byteLength);
const gfxOf = (p, i) => ({ w: p.w, h: p.h, bpp: p.bpp, flags: p.flags, px: p.bpp === 8 ? i.px : U32(i.px) });

const R = {
  radialCosSpot: () => { const d = new Uint8Array(65536); X.radialCosSpot(d); return { dst: d }; },
  radialDiscMask: () => { const d = new Uint8Array(65536); X.radialDiscMask(d); return { dst: d }; },
  screenBlendTables: () => { const a = new Uint8Array(65536), b = new Uint8Array(65536); X.screenBlendTables(a, b); return { t1: a, t2: b }; },
  colorMatrixTables: () => { const d = new Int32Array(2304); X.colorMatrixTables(d); return { dst: raw(d) }; },
  bumpDisplacementMap: (p, i) => { const d = new Uint16Array(65536); X.bumpDisplacementMap(d, i.h); return { dst: raw(d) }; },
  cosCosPlasma: () => { const d = new Uint8Array(65536); X.cosCosPlasma(d); return { dst: d }; },
  radialRayTables: (p) => { const r = new Uint16Array(0x17800), pr = new Uint16Array(0x13880 * 2), t = new Uint8Array(64000); const n = X.radialRayTables(r, pr, t); if (n !== p.n) throw Error('count ' + n + ' vs ' + p.n); return { rays: raw(r), pairs: raw(pr).subarray(0, n * 4), tmp: t }; },
  paletteShadeLut: (p, i) => { const d = new Uint32Array(65536); X.paletteShadeLut(d, i.pal); return { dst: raw(d) }; },
  halveDwords: (p, i) => { const d = U32(i.src); X.halveDwords(d); return { dst: raw(d) }; },
  invertDwords: (p, i) => { const d = U32(i.src); X.invertDwords(d); return { dst: raw(d) }; },
  colourRampLut: () => { const d = new Uint32Array(65536); X.colourRampLut(d); return { dst: raw(d) }; },
  boxBlurH: (p, i) => { const s = U32(i.src), d = p.inplace ? s : new Uint32Array(64000); X.boxBlurH(d, s, p.r); return { dst: raw(d) }; },
  boxBlurV: (p, i) => { const s = U32(i.src), d = p.inplace ? s : new Uint32Array(64000); X.boxBlurV(d, s, p.r); return { dst: raw(d) }; },
  boxBlurHVar: (p, i) => { const d = new Uint32Array(64000); X.boxBlurHVar(d, U32(i.src), I32(i.radii)); return { dst: raw(d) }; },
  radialPathBlur: (p, i) => { const o = i.out0.slice(); X.radialPathBlur(p.n, U16(i.rays), i.src, o, U16(i.pairs), p.npairs); return { out: o }; },
  memcpy: (p, i) => { const d = i.dst0.slice(); X.memcpy(d, p.d, i.src, p.s, p.n); return { dst: d }; },
  memset: (p, i) => { const d = i.dst0.slice(); X.memset(d, p.off, p.val, p.n); return { dst: d }; },
  blitAdd: null, blitDifference: null, blitLighten: null,
  blitCopy: (p, i) => { const s = U32(i.scr); X.blitCopy(s, 0, gfxOf(p, i)); return { scr: raw(s) }; },
  projectedBBox: (p, i) => ({ bbox: raw(X.projectedBBox(new Float32Array(i.xy.buffer.slice(0)), p.n)) }),
  maskFadeToBlack: (p, i) => { const s = U32(i.scr); X.maskFadeToBlack(s, i.mask, p.thr, i.T); return { scr: raw(s) }; },
  maskWipeCrossfade: (p, i) => { const s = U32(i.scr); X.maskWipeCrossfade(s, i.mask, U32(i.b), p.thr, i.T); return { scr: raw(s) }; },
  alphaMaskCrossfade: (p, i) => { const s = U32(i.scr); X.alphaMaskCrossfade(s, i.mask, U32(i.b), i.T); return { scr: raw(s) }; },
  maskInvert: (p, i) => { const s = U32(i.scr); X.maskInvert(s, i.mask, i.T); return { scr: raw(s) }; },
  lightMapAdd: (p, i) => { const d = new Uint32Array(65536); X.lightMapAdd(d, U32(i.src), U16(i.disp), i.map, p.dx); return { dst: raw(d) }; },
  lutLookup2D: (p, i) => { const d = new Uint32Array(64000); X.lutLookup2D(d, i.lo, i.hi, U32(i.lut)); return { dst: raw(d) }; },
  colorMatrixRect: (p, i) => { const s = U32(i.scr); X.colorMatrixRect(s, ...p.r, I32(i.tab)); return { scr: raw(s) }; },
  warpMeshB: (p) => { const d = new Int32Array(26 * 41 * 3); X.warpMeshB(d, Math.fround(p.t)); return { dst: raw(d) }; },
  warpMeshA: (p) => { const d = new Int32Array(26 * 41 * 3); X.warpMeshA(d, Math.fround(p.t), Math.fround(p.mix)); return { dst: raw(d) }; },
  buildFont: (p, i) => {
    const g = fontGfx(p, i); const f = X.buildFont(g, p.first, p.n);
    return { offs: raw(f.offs), wid: f.wid, hdr: raw(new Uint32Array([g.w, g.h, p.n, p.first])) };
  },
  printText: (p, i) => {
    const f = X.buildFont(fontGfx(p, i), p.first, p.n); const s = U32(i.scr);
    X.printText(s, p.txt, p.x, p.y, f, i.t1, i.t2); return { scr: raw(s) };
  },
};
R.vesaFramebuffer = (p, i) => ({ fb: X.vesaFramebuffer(U32(i.scr), p.bpp) });
const gfxCache = {};
const fontGfx = (p, i) => ({ w: p.name.includes('sysf') ? 356 : p.name.includes('verdana') ? 1008 : 609, h: p.name.includes('sysf') ? 7 : p.name.includes('verdana') ? 16 : 12, px: i.px });
for (const n of ['blitAdd', 'blitDifference', 'blitLighten']) R[n] = (p, i) => { const s = U32(i.scr); X[n](s, p.y * 320 + p.x, gfxOf(p, i)); return { scr: raw(s) }; };
const warp = (n, T8) => (p, i) => { const sc = T8 ? i.scr0.slice() : U32(i.scr0); X[n](sc, 0, T8 ? i.tex : U32(i.tex), I32(i.nodes), i.T); return { scr: raw(sc) }; };
R.gridWarpTex32 = warp('gridWarpTex32', false); R.gridWarpTex8 = warp('gridWarpTex8', true);
R.gridWarpStrip8 = warp('gridWarpStrip8', true); R.gridWarpStrip8Inv = warp('gridWarpStrip8Inv', true);
R.spriteSubtract = (p, i) => { const s = U32(i.scr0); X.spriteSubtract(s, p.X, p.Y, p.R, i.mask); return { scr: raw(s) }; };
R.spriteAddAlpha = (p, i) => { const s = U32(i.scr0); X.spriteAddAlpha(s, p.X, p.Y, p.R, i.mask, p.alpha, i.T); return { scr: raw(s) }; };
R.spriteSubtractAlpha = (p, i) => { const s = U32(i.scr0); X.spriteSubtractAlpha(s, p.X, p.Y, p.R, i.mask, p.alpha, i.T); return { scr: raw(s) }; };
// presentToRGBA: dword 0x00RRGGBB -> R=byte2 (VESA B,G,R memory order); 565 quantisation
{
  const sc = new Uint32Array(64000).fill(0x00112233), o = new Uint8Array(256000);
  X.presentToRGBA(sc, o, 32); if (o[0] !== 0x11 || o[1] !== 0x22 || o[2] !== 0x33 || o[3] !== 255) throw Error('presentToRGBA 32');
  sc.fill(0x00ff8040); X.presentToRGBA(sc, o, 16); if (o[0] !== 255 || o[1] !== 0x82 || o[2] !== 0x42) throw Error('presentToRGBA 16 ' + [...o.subarray(0, 3)]);
}
let ok = 0, bad = 0, skipped = new Set();
for (const t of tests) {
  const f = R[t.fn];
  if (!f) { skipped.add(t.fn); continue; }
  const ins = {}; for (const k in t.in) ins[k] = B(t.in[k]);
  let got; try { got = f(t.p, ins); } catch (e) { console.log('FAIL', t.fn, JSON.stringify(t.p).slice(0, 80), 'threw', e.message); bad++; continue; }
  let diffs = [];
  for (const k in t.out) {
    const exp = B(t.out[k]), g = got[k], gb = g && new Uint8Array(g.buffer, g.byteOffset, g.byteLength);
    if (!gb || gb.length !== exp.length) { diffs.push(`${k}: length ${gb && gb.length} vs ${exp.length}`); continue; }
    let n = 0, first = -1; for (let j = 0; j < exp.length; j++) if (gb[j] !== exp[j]) { if (first < 0) first = j; n++; }
    if (n) diffs.push(`${k}: ${n} bytes differ, first at ${first} (got ${gb[first]} exp ${exp[first]})`);
  }
  if (diffs.length) { bad++; console.log('FAIL', t.fn, JSON.stringify(t.p).slice(0, 100), diffs.join('; ')); } else ok++;
}
console.log(`fx2d: ${ok} ok, ${bad} failed` + (skipped.size ? `, skipped (no JS test yet): ${[...skipped].join(',')}` : ''));
process.exit(bad ? 1 : 0);
