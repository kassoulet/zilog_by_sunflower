// Scene 3 (main loop `while (order < 23)`, music orders 19..22, 67.5 .. 81.4 s): full-screen "pipes" texture lit by a moving light map through a bump displacement,
// refracted by a three-lens grid warp (0x1ce90 nodes + 0x1d6a4 warp); columns of dark dithered dots; a wobbling chrome blob (kph2.mob, env1 environment map) drawn
// as shaded faces + darkening ramp-coloured silhouette lines; jp flashes on sync bits 0-3, a colour-matrix window on sync bit 4, and from order 21 a growing
// per-scanline horizontal blur (radius follows a cosine across the screen height).
import { blitAdd, gridWarpTex32, lightMapAdd, bumpDisplacementMap, spriteSubtractAlpha, colorMatrixRect, boxBlurHVar } from '../lib/fx2d.js';
import { Obj3D, rotate, faceNormals, vertexNormals, project, render, makeRenderContext, trunc32 } from '../lib/mesh3d.js';
import { F, g2Shared, mesh, makeClock, sineBlobMesh, waveColours, lensNodes } from './_g2fx.js';
import { fistp32 } from '../lib/fx2d-tables.js';
const S = Math.sin, C = Math.cos;
const JP = ['01', '02', '03', '05', '08', '10', '11', '13'];

export function createScene(env) {
  const g = g2Shared(env), scr = env.scr, clock = makeClock(), ctx = makeRenderContext(scr, g.luts);
  const nodes = new Int32Array(41 * 26 * 3), radii = new Int32Array(200), tex1 = new Uint32Array(65536), blurBuf = new Uint32Array(64000);
  let disp, pipesd, lites, zil, o1, jp, blur;
  return {
    name: 'scene3', orderStart: 19, orderEnd: 23,
    init() {
      disp = new Uint16Array(65536); bumpDisplacementMap(disp, env.gfx('textures/pip_h.gfx').px);       // 0x14b3d (once, before the loop)
      pipesd = env.gfx('textures/pipesd.gfx').px; lites = env.gfx('textures/lites2.gfx').px; zil = env.gfx('textures/zilog2.gfx').px;
      o1 = new Obj3D(mesh(env, 'kph2.mob'), { cx: 30, cy: 100, dist: 4, focal: 140, tex: new Uint32Array(env.gfx('textures/env1.gfx').px), mode: 0, sub: 0 });
      jp = JP.map((n) => env.gfx('smalpics/jp' + n + '.gfx'));
      blur = 0;
    },
    frame(st) {
      const T = clock(st), dt = st.dt;
      // animated light over the pipes texture through the bump map -> the warp source texture
      const a = Math.trunc(C(T * 0.074) * 120) << 8;
      lightMapAdd(tex1, pipesd, disp, lites, Math.trunc(S(T * 0.061) * 120 + a));
      lensNodes(nodes, T); gridWarpTex32(scr, 0, tex1, nodes, g.lut1);
      // dither dots: 0xff in zilog2 = none, otherwise a dark soft dot (subtractive sprite) wobbling around its grid slot
      for (let y = -2; y < 42; y += 2) for (let x = 0; x < 20; x += 3) {
        const v = zil[((Math.trunc(y + T) & 0x7f) * 20) + x];
        if (v === 0xff) continue;
        const R = trunc32(((v * 0.04 + 2) * 0.3 + 2) * 256);
        const Y = trunc32((S(S(T * 0.032 + y * 0.1) + (T * 0.06 + x * 0.1)) * 10 + y * 5 + 2) * 256);
        const X = trunc32((S(S(T * 0.072 + y * 0.1) + (T * 0.05 + x * 0.1)) * 10 + 2 + 220 + x * 2.5) * 256);
        spriteSubtractAlpha(scr, X, Y, R, g.spot, v, g.lut2);
      }
      const ax = F(S(C(T * 0.06) + T * 0.01) * 0.2), ay = F(S(T * 0.006) * 0.3), az = F(S(S(T * 0.05) + T * 0.03) * 0.2 + 1.5);
      sineBlobMesh(o1.mesh, T, F(60)); rotate(o1, ax, ay, az); faceNormals(o1); vertexNormals(o1.mesh); project(o1);
      o1.mode = 0; o1.sub = 0; render(o1, ctx);
      waveColours(o1.mesh, T, F(0.1)); o1.mode = 6; o1.sub = 5; render(o1, ctx); o1.mode = 0; o1.sub = 0;
      if (st.sync & 0xf) blitAdd(scr, 0, jp[st.sync & 7]);
      if (st.sync & 0x10) {
        const e = F(S(T * 2) * 7), f = F(S(T * 1.3) * 7);
        colorMatrixRect(scr, Math.trunc(st.order * 10 - e), Math.trunc(100 - f), Math.trunc(st.order * 10 + 60 + e), Math.trunc(f + 160), g.cm);
      }
      if (st.order >= 21) {                                   // blur grows (cap 1) and is modulated by a slow plasma-ish sine; radius profile cos over the height
        blur = F(dt * 0.01 + blur); if (blur > 1) blur = 1;
        for (let i = 0; i < 200; i++) {
          const k = blur * (S(T * 0.09 - S(T * 0.12)) * 0.5 + 0.5);
          radii[i] = fistp32((28 - C(i * Math.PI / 100) * 35) * k);
        }
        boxBlurHVar(blurBuf, scr, radii); scr.set(blurBuf);
      }
    },
  };
}
