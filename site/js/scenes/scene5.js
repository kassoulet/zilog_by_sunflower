// Scene 5 (orders 27..30, music 95.2-109.0 s): the cones3 point cloud (909 sprite points, coloured by cone_kol.gfx) swirling over circles.gfx,
// inside a gradient frame / corner brackets drawn from the screen bbox of the points; from order 30 row 48 the cloud flies up and the frame fades.
import { Obj3D, rotate, project, render, makeRenderContext, line_21f3b, trunc32 } from '../lib/mesh3d.js';
import { blitCopy, projectedBBox } from '../lib/fx2d.js';
import { shared, coneWarp, timeOf } from './_g3.js';
const f32 = Math.fround;

export function createScene(env) {
  const g = shared(env), scr = env.scr, bg = env.gfx('fullpics/circles.gfx'), ctx = makeRenderContext(scr, g.luts);
  let obj, base, fy, fade;
  // (x0,y0,x1,y1 as bbox corner + offset; which end gets the fade) for the 8 calls of func_21f3b @0x1265e..0x12a88
  // bbox: a=minX b=maxX c=minY d=maxY ; [xa,ya,xb,yb], flag 1 = colour in the high byte (ah: fade at B) else al (fade at A)
  const L = [
    ['a+5', 'c+5', 'b-5', 'c+5', 1], ['a+5', 'd-5', 'b-5', 'd-5', 0], ['a+5', 'c+5', 'a+5', 'd-5', 1], ['b-5', 'c+5', 'b-5', 'd-5', 0],
    ['a+12', 'c+4', 'b-4', 'c+12', 0], ['a+4', 'd-12', 'b-12', 'd-4', 1], ['a+12', 'c+4', 'a+4', 'd-12', 0], ['b-4', 'c+12', 'b-12', 'd-4', 1],
  ].map(([xa, ya, xb, yb, h]) => [xa, ya, xb, yb].map((s) => (v) => v[s[0]] + +s.slice(1)).concat([h]));
  return {
    name: 'scene5', orderStart: 27, orderEnd: 31,
    init() {
      const mesh = g.mesh('3d/cones3.mob');
      obj = new Obj3D(mesh, { cx: 160, cy: 100, dist: 3, focal: 140, tex: g.spot, mode: 9, sub: 3, colors: env.gfx('textures/cone_kol.gfx').px });
      fy = 0; fade = 255; base = null;
    },
    frame(st) {
      if (base === null) base = f32(st.ticks * 0.25);
      const t = timeOf(st.ticks, base), m = obj.mesh;
      if (st.pos > 0x7b0) { fy = f32(st.dt * 0.5 + fy); fade = f32(fade - st.dt * 4); if (fade < 0) fade = 0; }
      blitCopy(scr, 0, bg);
      obj.cy = f32(100 - fy * fy);
      const ax = f32(Math.sin(t * 0.01) * 0.5), ay = f32(Math.sin(t * 0.02) * 0.5), az = f32(Math.sin(t * 0.03) * 0.5);
      coneWarp(m, t);
      obj.mode = 0; rotate(obj, ax, ay, az);      // mode 0: in place on the points just written by coneWarp
      obj.mode = 9; project(obj); render(obj, ctx);
      const [a, b, c, d] = projectedBBox(m.p2d, m.npts), v = { a, b, c, d }, fi = trunc32(fade) & 255;
      for (const [xa, ya, xb, yb, hi] of L) {
        const P = (f) => trunc32(f(v) * 65536);
        line_21f3b(ctx, hi ? 0 : fi, hi ? fi : 0, P(xa), P(ya), P(xb), P(yb));
      }
    },
  };
}
