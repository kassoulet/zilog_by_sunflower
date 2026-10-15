// Scene 0 (main loop `while (order < 5)`, music 0 .. 17.3 s): the "3b_2" wire-frame object flies in, points appear with the music, blur breathes.
import { loadMesh, Obj3D, rotate, project, render, makeRenderContext } from '../lib/mesh3d.js';
import { boxBlurV, boxBlurH, printText } from '../lib/fx2d.js';
import { g1Shared, makeClock, F } from './_g1common.js';
const S = Math.sin, C = Math.cos;

export function createScene(env) {
  const g = g1Shared(env), scr = env.scr, buf2 = new Uint32Array(64000), clock = makeClock();
  let mesh, obj, ctx, nOrig, v20, v1c, v48;
  return {
    name: 'scene0', orderStart: 0, orderEnd: 5,
    init() {
      mesh = loadMesh(env.files.get('3d/3b_2.mob'));
      ctx = makeRenderContext(scr, { lut1: g.lut1, lut2: g.lut2 });
      obj = new Obj3D(mesh, { cx: 160, cy: 100, dist: 6.5, focal: 140, tex: g.spot, mode: 5, sub: 3, colors: env.gfx('textures/silh_kol.gfx').px });   // DAT_00040308 = silh_kol.gfx pixels: per-point colours
      nOrig = mesh.npts; v20 = 240; v1c = 0; v48 = 0;
    },
    frame(st) {
      const T = clock(st), dt = st.dt;
      // three slowly wandering euler angles (nested sin/cos LFOs)
      const ax = F(S(C(T * 0.008) + T * 0.009) * 3), ay = F(S(C(T * 0.007) + T * 0.018) * 3), az = F(S(C(T * 0.006) + T * 0.017) * 3);
      scr.fill(0);                                                   // 17e46: memset(screen, 0, 0x3e800)
      rotate(obj, ax, ay, az);                                       // (0x18144 rotateNormals result is unused by modes 5/9)
      v20 = F(Math.max(0, v20 - dt * 0.7));                          // fly-in from below
      if (st.pos > 0x120) v1c = F(dt * 0.9 + v1c);                   // then drifts right
      obj.cx = F(S(T * 0.0251 - S(T * 0.01)) * 50 + (v1c + 220));
      obj.cy = F(C(T * 0.0151 - S(T * 0.02)) * 50 + (v20 + 100));
      project(obj);
      obj.mode = 5; render(obj, ctx);                                // silhouette edges (anti-aliased "screen" lines)
      mesh.npts = Math.min(st.pos, nOrig);                           // points are revealed one per music row
      obj.mode = 9; render(obj, ctx);                                // additive soft point sprites
      mesh.npts = nOrig;
      if (st.sync === 1) printText(scr, 'ugly, discrete jumps', 10, 175, g.font, g.lut1, g.lut2);
      boxBlurV(buf2, scr, Math.trunc(S(C(T * 0.5) + T * 0.1) * 3 + 7));   // vertical blur, radius 4..10 breathing
      if (st.sync === 2) v48 = 50;
      if (st.sync === 3) v48 = F(v48 - dt * 3);
      if (v48 < 3) v48 = 3;
      if (st.sync === 2 || st.sync === 3) boxBlurH(scr, buf2, Math.trunc(v48));   // + horizontal blur (strong, decaying) on the beat
      else scr.set(buf2);                                            // (original flips buf2 directly)
    },
  };
}
