// Scene 2 (main loop `while (order < 19)`, music orders 14..18, 48.5 .. 67.5 s): a wobbling "organic" environment-mapped blob (b2.mob) in front of the
// spot.gfx light burst, wrapped by dark soft-blob sphere points (sph1024), a pulsating wireframe of concentric rings (ring mesh from 0x1bdb0), an additive
// light sprite and a crosshair of fading lines through its centre; flash (jp09) on sync marker 1, fade-in from black through mask2.
import { blitCopy, blitAdd, maskFadeToBlack } from '../lib/fx2d.js';
import { Obj3D, rotate, faceNormals, vertexNormals, project, render, makeRenderContext, sprite_1efbc, line_21f3b, trunc32 } from '../lib/mesh3d.js';
import { F, g2Shared, mesh, makeClock, ringMesh, wobbleMesh, renderFacesHalf, spritesHalf } from './_g2fx.js';
const S = Math.sin, C = Math.cos;

export function createScene(env) {
  const g = g2Shared(env), scr = env.scr, clock = makeClock(), ctx = makeRenderContext(scr, g.luts);
  let spotBg, mask2, jp09, o1, o2, o3, v2c;
  return {
    name: 'scene2', orderStart: 14, orderEnd: 19,
    init() {
      spotBg = env.gfx('fullpics/spot.gfx'); mask2 = env.gfx('fullpics/mask2.gfx').px; jp09 = env.gfx('smalpics/jp09.gfx');
      const tex1 = new Uint32Array(env.gfx('textures/max_t2.gfx').px);                    // memcpy(tex1, max_t2, 0x40000)
      o1 = new Obj3D(mesh(env, 'b2.mob'), { cx: 220, cy: 100, dist: 6, focal: 140, tex: tex1, mode: 0, sub: 0 });
      o2 = new Obj3D(mesh(env, 'sph1024.mob'), { cx: 220, cy: 100, dist: 6, focal: 100, tex: g.spot, mode: 9, sub: 6 });
      o3 = new Obj3D(ringMesh(26, 5, 800), { cx: 220, cy: 100, dist: 6, focal: 100, mode: 7 });
      v2c = -32;
    },
    frame(st) {
      const T = clock(st);
      blitCopy(scr, 0, spotBg);
      v2c = F(st.dt + v2c);
      const ax = F(S(C(T * 0.008) + T * 0.009) * 3), ay = F(S(C(T * 0.007) + T * 0.018) * 3), az = F(S(C(T * 0.006) + T * 0.017) * 3);
      wobbleMesh(o1.mesh, T); rotate(o1, ax, ay, az); faceNormals(o1); vertexNormals(o1.mesh);       // mode 0: rotates the wobbled xpts in place
      const cx = F(S(T * 0.0151 - S(T * 0.05)) * 50 + 160), cy = F(C(T * 0.0123 - S(T * 0.043)) * 50 + 100);
      o1.cx = cx; o1.cy = cy;
      rotate(o2, ax, ay, az);                                                                         // (the wobble of the sphere is overwritten by this rotate)
      o2.cx = o3.cx = cx; o2.cy = o3.cy = cy;
      project(o1); project(o2);
      wobbleMesh(o3.mesh, T); project(o3);
      spritesHalf(o2, ctx, F(17), true);                         // far half of the sphere: dark blobs
      renderFacesHalf(o1, ctx, 1);                               // far half of the blob (z-key > 0)
      sprite_1efbc(scr, g.spot, trunc32(cx * 256), trunc32(cy * 256), 0x4600);   // additive 70 px light sprite on the centre
      render(o3, ctx);                                           // ring wireframe (mode 7)
      const X = trunc32(cx * 65536), Y = trunc32(cy * 65536);    // crosshair: 4 fading lines from the centre to the screen borders (0x221fc)
      line_21f3b(ctx, 0, 255, 0, Y, X, Y); line_21f3b(ctx, 255, 0, X, Y, 0x13f0000, Y);
      line_21f3b(ctx, 0, 255, X, 0, X, Y); line_21f3b(ctx, 255, 0, X, Y, X, 0xc70000);
      renderFacesHalf(o1, ctx, -1);                              // near half of the blob
      spritesHalf(o2, ctx, F(17), false);                        // near half of the sphere points
      if (st.sync === 1) blitAdd(scr, 0, jp09);                  // flash on the sync marker
      if (v2c < 260) maskFadeToBlack(scr, mask2, trunc32(v2c), g.lut2);   // fade-in from black through mask2
    },
  };
}
