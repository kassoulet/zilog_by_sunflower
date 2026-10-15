// Scene 8 (orders 41..48, music 143.7-171.3 s): "hand drawn" picture assembled from flying hexagon tiles over a plasma/blur intro,
// then a pulsing wire/sprite cylinder; from order 47 a wipe (hand drawn mask) to a twisted cube tunnel.  See re/SCENE_g5.md.
import { Obj3D, rotate, project, render } from '../lib/mesh3d.js';
import { blitCopy, blitAdd, memcpy, warpMeshB, gridWarpStrip8, radialPathBlur, lutLookup2D, printText, maskWipeCrossfade } from '../lib/fx2d.js';
import { f_1b687, f_1b04f, f_1b1b4, f_21664, f_2112c, f_20a10 } from './_g5mesh.js';
import { f_19f57, f_1a415, f_1a5ea, f_1ac25 } from './_g5draw.js';
import { f32, mesh, shared, introTables, timeOf, BASE7, ctxFor } from './_g5common.js';

const TEXT = '\x08Z\x0c.thence to a lightness\nand, by this declension\ninto the madness wherein he raves';   // DAT_0003da44

export function createScene(env) {
  const g = introTables(env);
  const hexM = mesh(env, 'hexp_on2'), cylM = mesh(env, 'cyl'), cubM = mesh(env, 'cub_tun2');
  const hand = env.gfx('fullpics/handdraw.gfx'), stripe = env.gfx('fullpics/stripe.gfx'), hmask = env.gfx('fullpics/hmask2.gfx').px;
  const plzm = env.gfx('textures/plzm.gfx').px, aph = [1, 2, 3, 4].map((i) => env.gfx(`smalpics/aph${i}.gfx`));
  const screen2 = new Uint32Array(64000), s2b = new Uint8Array(screen2.buffer, 0, 64000), blurOut = new Uint8Array(64000), strip = new Uint8Array(256);
  const nodes = new Int32Array(26 * 41 * 3);
  const ctx = ctxFor(env.scr, g), ctx2 = ctxFor(screen2, g);
  let objA, objB, objC, A, B, P, wipe;
  return {
    name: 'scene8', orderStart: 41, orderEnd: 49,
    init() {
      f_1b687(hexM); f_1b04f(hexM, 320, 200); f_1b1b4(cubM);
      objA = new Obj3D(hexM, { cx: 160, cy: 99, dist: f32(0.666), focal: 180, tex: hand.px, mode: 4, sub: 4 });   // hexagon tiles textured with the picture (screen-space warp)
      objB = new Obj3D(cylM, { cx: 90, cy: 100, dist: 4.5, focal: 180, tex: g.spot, mode: 9, sub: 0 });          // cylinder of glow sprites
      objC = new Obj3D(cubM, { cx: 90, cy: 100, dist: 3.5, focal: 140, tex: hand.px, mode: 6, sub: 5 });         // cube tunnel (darkening lines)
      wipe = 260; A = 20; B = 2; P = 0;                                                                         // DAT_0004032c / 40348 / 4034c / 40338
    },
    frame(st) {
      const t = timeOf(st, BASE7), dt = st.dt;
      A = f32(A - dt * 0.08); if (A < 0) A = 0;
      if (A < 2) { B = f32(B - dt * 0.006); if (B < 0) B = 0; }
      if (B > 0) {                                           // ---- intro: plasma strip -> swirl warp -> radial blur -> colour LUT, text, flying hexagon tiles
        strip.set(plzm.subarray((Math.trunc(t) & 255) * 256, (Math.trunc(t) & 255) * 256 + 256));
        warpMeshB(nodes, t);
        gridWarpStrip8(s2b, 0, strip, nodes, g.lut1);
        radialPathBlur(6, g.rays, s2b, blurOut, g.pairs, g.npairs);
        lutLookup2D(env.scr, blurOut, s2b, g.pal);
        printText(env.scr, TEXT, 10, 10, g.vsm, g.lut1, g.lut2);
        const c = Math.cos(B), t1 = f32(t - 353);
        f_21664(hexM, f32((1 - c) * 2), f32(1 - c), f32(12 - 11 * Math.cos(A * 0.15)), t1);
        project(objA);
        objA.tex = g.spot; objA.mode = 9; objA.sub = 0; f_19f57(objA, f32(B * 3), ctx);
        objA.tex = hand.px; objA.mode = 4; objA.sub = 4; render(objA, ctx);
      } else {                                               // ---- picture + cylinder of sprites (+ wipe to the cube tunnel from order 47)
        blitCopy(env.scr, 0, hand);
        if (st.order >= 47) {
          blitCopy(screen2, 0, stripe);
          const ax = f32(Math.sin(t * 0.01) * 0.3), ay = f32(Math.sin(t * 0.02) * 0.3), az = f32(Math.sin(t * 0.03) * 0.3 + 1.5);
          f_2112c(cubM, t); objC.mode = 0; rotate(objC, ax, ay, az); objC.mode = 6; project(objC);
          f_1ac25(objC, ctx2); render(objC, ctx2);
          wipe = f32(wipe - dt * 0.9);
          maskWipeCrossfade(env.scr, hmask, screen2, Math.trunc(wipe), g.lut2);
        }
        f_20a10(cylM, t); project(objB);
        if (st.order < 47) { P = f32(P + dt * 0.1); if (P > 26) P = 26; } else { P = f32(P - dt * 0.1); if (P < 0) P = 0; }
        f_1a415(objB, hmask, P, ctx); f_1a5ea(objB, P, ctx);
      }
      if (st.pos > 0xac4 && st.pos < 0xac9) blitAdd(env.scr, 0, aph[(st.row - 5) & 3]);   // 4 frame flash on order 43 rows 5..8
    },
  };
}
