// Scene 4 (orders 23..26, music 81.4-95.2 s): "q1" env-mapped blob flying left over the truesimu picture, silhouette lines
// cross-faded through mask7, bouncing text, difference-flash pictures and a colour-matrix strip on sync markers, and from
// order 26 row 32 a growing vertical box blur (DAT_00040348 = radius).  See re/SCENE_g3.md.
import { Obj3D, rotate, rotateNormals, faceNormals, vertexNormals, project, render, makeRenderContext } from '../lib/mesh3d.js';
import { blitCopy, blitDifference, alphaMaskCrossfade, colorMatrixRect, boxBlurV, printText } from '../lib/fx2d.js';
import { shared, hex32, timeOf } from './_g3.js';
const f32 = Math.fround;

export function createScene(env) {
  const g = shared(env), scr = env.scr, B = new Uint32Array(64000);   // B = puStack_34 (second buffer)
  const bg = env.gfx('fullpics/truesimu.gfx'), mask = env.gfx('fullpics/mask7.gfx').px;
  const jp = ['13', '14', '15', '16', '17', '18', '19', '20'].map((n) => env.gfx(`smalpics/jp${n}.gfx`));
  const ctx = makeRenderContext(scr, g.luts), ctxB = makeRenderContext(B, g.luts);
  let obj, base, blur;
  return {
    name: 'scene4', orderStart: 23, orderEnd: 27,
    init() {
      const mesh = g.mesh('3d/q1_.mob'), env1 = env.gfx('textures/env1.gfx').px;
      obj = new Obj3D(mesh, { cx: 160, cy: 130, dist: 6, focal: 140, tex: new Uint32Array(env1.subarray(0, 65536)), mode: 1, sub: 0 });
      faceNormals(obj); vertexNormals(mesh);
      blur = 0; base = null;
    },
    frame(st) {
      if (base === null) base = f32(st.ticks * 0.25);            // _DAT_00040314 = ticks*0.25 at scene start
      const t = timeOf(st.ticks, base);
      blitCopy(scr, 0, bg); blitCopy(B, 0, bg);
      const ax = f32(3 * Math.sin(Math.cos(t * 0.008) + t * 0.009)), ay = f32(3 * Math.sin(Math.cos(t * 0.007) + t * 0.018)), az = f32(3 * Math.sin(Math.cos(t * 0.006) + t * 0.017));
      obj.mode = 1;
      rotate(obj, ax, ay, az); rotateNormals(obj.mesh, ax, ay, az);
      obj.cx = f32(320 - t); project(obj);
      render(obj, ctx);                       // env mapped faces on the screen
      obj.mode = 5; render(obj, ctxB);        // silhouette edges drawn into B (DAT_000402f0 temporarily = B)
      // sprintf(buf, "\x08\x80 lypho%x\nacid%x\nni\x0bs\x0bse%x", order*row, order-row, order+row); buf[1] = alpha
      const a = Math.trunc(Math.sin(t) * 120 + 128) & 255, o = st.order, r = st.row;
      const txt = '\x08' + String.fromCharCode(a) + ' lypho' + hex32(o * r) + '\nacid' + hex32(o - r) + '\nni\x0bs\x0bse' + hex32(o + r);
      printText(scr, txt, 2, 10, g.font, g.luts.lut1, g.luts.lut2);
      alphaMaskCrossfade(scr, mask, B, g.luts.lut2);
      if (st.pos > 0x6a0) blur = f32(st.dt + blur);
      if (blur > 90) blur = 90;
      if (st.sync & 0xf) blitDifference(scr, 0, jp[st.sync & 7]);
      const s2 = f32(Math.sin(t * 2) * 7), s13 = f32(Math.sin(t * 1.3) * 7);
      if (st.sync & 0x10) colorMatrixRect(scr, Math.trunc(20 - s2), Math.trunc(20 - s13), Math.trunc(s2 + 300), Math.trunc(s13 + 40), g.matrix);
      if (blur > 3) { boxBlurV(B, scr, Math.trunc(blur)); scr.set(B); }   // flips B instead of the screen
    },
  };
}
