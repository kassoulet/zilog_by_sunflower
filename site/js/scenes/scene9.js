// Scene 9 (orders 49..50, music 171.3-178.3 s): purple cube tunnel (stripe.gfx background + twisted cub_tun2 drawn as additive grey
// Gouraud faces + dark contour lines) overlaid with a 42x19 wobbling wire grid whose line brightness is read from the scrolling
// zilog2.gfx picture.  The credits loop (orders 51..59) that follows main()'s scene 9 is in _g5final.js (exported here as createFinalScene).
import { Obj3D, rotate, project, render, trunc32 } from '../lib/mesh3d.js';
import { blitCopy } from '../lib/fx2d.js';
import { line_21f3b } from '../lib/mesh3d-raster.js';
import { f_1b1b4, f_2112c } from './_g5mesh.js';
import { f_1ac25 } from './_g5draw.js';
import { f32, mesh, shared, timeOf, BASE7, ctxFor } from './_g5common.js';
export { createScene as createFinalScene } from './_g5final.js';
const { sin } = Math;

export function createScene(env) {
  const g = shared(env), cubM = mesh(env, 'cub_tun2'), stripe = env.gfx('fullpics/stripe.gfx'), tex = env.gfx('textures/zilog2.gfx').px;   // 20 x 128 bytes
  const ctx = ctxFor(env.scr, g);
  let obj, off, k;
  return {
    name: 'scene9', orderStart: 49, orderEnd: 51,
    init() { f_1b1b4(cubM); obj = new Obj3D(cubM, { cx: 90, cy: 100, dist: 3.5, focal: 140, mode: 6, sub: 5 }); off = 0; k = 0; },
    frame(st) {
      const t = timeOf(st, BASE7), dt = st.dt, pos = st.pos;
      blitCopy(env.scr, 0, stripe);
      if (pos > 0xc80) off = f32(off - dt * 0.9);                 // tunnel slides left
      obj.cx = f32(off + 90);
      if (!(pos > 0xc60)) { k = f32(k + 0.05); if (k > 1) k = 1; } // grid fades in until pos 0xc60, out from 0xca0
      if (pos >= 0xca0) { k = f32(k - 0.05); if (k < 0) k = 0; }
      const ax = f32(sin(t * 0.01) * 0.3), ay = f32(sin(t * 0.02) * 0.3), az = f32(sin(t * 0.03) * 0.3 + 1.5);
      f_2112c(cubM, t); obj.mode = 0; rotate(obj, ax, ay, az); obj.mode = 6; project(obj);
      f_1ac25(obj, ctx); render(obj, ctx);
      // ---- wire grid: point (i,j) -> screen (220+5j + wobble, 5i + wobble) in 16.16; two lines per cell (to j+1 and to i+1)
      const X = (i, j) => trunc32((10 * sin(sin(t * 0.072 + i * 0.1) + (t * 0.05 + j * 0.1)) + 220 + 5 * j) * 65536);
      const Y = (i, j) => trunc32((10 * sin(sin(t * 0.032 + i * 0.1) + (t * 0.06 + j * 0.1)) + 5 * i) * 65536);
      const px = (r, c) => Math.trunc((tex[(r & 0x7f) * 20 + c] ?? 0) * k);
      for (let i = -2; i < 42; i++) {
        const r = Math.trunc(i + t), r1 = Math.trunc(i + t + 1);
        for (let j = 0; j < 19; j++) {
          const a = px(r, j), b = px(r, j + 1), c = px(r1, j);
          const x0 = X(i, j), y0 = Y(i, j);
          line_21f3b(ctx, a, b, x0, y0, X(i, j + 1), Y(i, j + 1));
          line_21f3b(ctx, a, c, x0, y0, X(i + 1, j), Y(i + 1, j));
        }
      }
    },
  };
}
