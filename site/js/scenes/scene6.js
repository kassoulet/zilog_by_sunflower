// Scene 6 (main loop `while (order < 35)`, orders 31..34, 109.0-122.9 s): the "morphing blob" - a k_1.mob mesh, deformed every frame by a
// spherical sine ripple (func_20b94), drawn env-mapped + city texture (mode 2) then a second time as contour wireframe (mode 5, slightly closer),
// over a background made of circles.gfx plus an 8-bit plasma-warp strip (plzm.gfx row cycling, polar swirl mesh warp 22c39+1e941) blended with "lighten".
import { loadMesh, Obj3D, rotate, faceNormals, vertexNormals, project, render, makeRenderContext } from '../lib/mesh3d.js';
import { blitCopy, blitLighten, warpMeshA, gridWarpStrip8Inv, halveDwords } from '../lib/fx2d.js';
import { planarUV, rippleSphere } from './_g4fx.js';
import { shared, makeClock } from './_g4common.js';
const F = Math.fround, sin = Math.sin, cos = Math.cos;

export function createScene(env) {
  const clock = makeClock();
  let mesh, obj, ctx, tex, nodes, d8, buf8, bg, plzm, fade, slide, luts, grey;
  return {
    name: 'scene6', orderStart: 31, orderEnd: 35,
    init() {
      luts = shared(env).luts;
      tex = new Uint32Array(131072);                                    // d4 (env1) + d0 (cityscap): 2 textures 0x40000 bytes apart
      tex.set(env.gfx('textures/env1.gfx').px.subarray(0, 65536), 0); tex.set(env.gfx('textures/cityscap.gfx').px.subarray(0, 65536), 65536);
      halveDwords(tex.subarray(0, 65536)); halveDwords(tex.subarray(65536));
      mesh = loadMesh(env.files.get('3d/k_1.mob'));
      obj = new Obj3D(mesh, { cx: 220, cy: 100, dist: 6.0, focal: 140, tex, mode: 2, sub: 0 });
      planarUV(mesh, 0x100, 0x100);
      ctx = makeRenderContext(env.scr, luts);
      bg = env.gfx('fullpics/circles.gfx'); plzm = env.gfx('textures/plzm.gfx').px;
      nodes = new Int32Array(26 * 41 * 3); d8 = new Uint8Array(256); buf8 = new Uint8Array(64000);
      grey = { w: 320, h: 200, bpp: 8, flags: 0, px: buf8 };
      fade = 0; slide = -200; clock.reset();
    },
    frame(st) {
      const t = clock.time(st), dt = st.dt;
      fade = F(dt * 0.001 + fade); if (fade > 1) fade = 1;               // 0x40338: swirl cross-fade 0 -> 1 over 1000 ticks
      slide = F(dt * 2 + slide); if (!(slide < 0)) slide = 0;           // [ebp-0xc]: object slides down from y-200
      const scr = env.scr;
      blitCopy(scr, 0, bg);
      d8.set(plzm.subarray((Math.trunc(t) & 0xff) << 8, ((Math.trunc(t) & 0xff) << 8) + 256));
      warpMeshA(nodes, t, fade);
      gridWarpStrip8Inv(buf8, 0, d8, nodes, luts.lut2);
      blitLighten(scr, 0, grey);
      const ax = F(sin(cos(t * 0.008) + t * 0.009) * 3), ay = F(sin(cos(sin(t * 0.01) + t * 0.007) + t * 0.038) * 3), az = F(sin(cos(t * 0.006) + t * 0.027) * 3);
      const s = sin(cos(t * 0.1) + t * 0.01);
      rippleSphere(mesh, t, F(s * s * 200 + 200));
      rotate(obj, ax, ay, az); faceNormals(obj); vertexNormals(mesh);
      obj.cx = F((sin(cos(t * 0.03 - cos(t * 0.025)) + t * 0.02456) * 10 + 20.5) * 8);
      obj.cy = F(F((sin(sin(t * 0.04 - sin(t * 0.035)) + t * 0.012543) * 10 + 12.5) * 6.64) + slide);
      obj.dist = 6.0; project(obj); render(obj, ctx);                   // mode 2: env map + city texture
      obj.mode = 5; obj.dist = F(5.2); project(obj); render(obj, ctx);   // contour lines, slightly closer
      obj.mode = 2;
    },
  };
}
