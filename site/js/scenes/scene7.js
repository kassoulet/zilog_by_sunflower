// Scene 7 (main loop `while (order < 41)`, orders 35..40, 122.9-143.7 s): "lattice in a black hole" - a 10x10x6 wire lattice (func_1bf97)
// pulled around a wandering singularity (func_20a10), edges drawn with colour ramps (mode 8) that fade with the distance to it (func_1b533),
// over a plasma strip warped by a swirl mesh (22e0e+1e62e), radially blurred along 512 rays (1743b, 2^6 window) and colourised through the
// palette LUT (22b9c: lut[strip_index<<8 | blurred]).  Text (Hamlet) top left.
import { Obj3D, rotate, project, render, makeRenderContext } from '../lib/mesh3d.js';
import { warpMeshB, gridWarpStrip8, radialPathBlur, lutLookup2D, printText } from '../lib/fx2d.js';
import { makeLattice, blackHole, distanceColours } from './_g4fx.js';
import { shared, rays, shadeLut, font, makeClock } from './_g4common.js';
const F = Math.fround, sin = Math.sin;
const TEXT = Uint8Array.from('\x08Z\x0c.thence to a lightness\nand, by this declension\ninto the madness wherein he raves', (c) => c.charCodeAt(0));

export function createScene(env) {
  const clock = makeClock();
  let mesh, obj, ctx, nodes, d8, bufA, bufB, plzm, fade, luts, R, lut, fnt;
  return {
    name: 'scene7', orderStart: 35, orderEnd: 41,
    init() {
      luts = shared(env).luts; R = rays(env); lut = shadeLut(env); fnt = font(env, 'fonts/verd_sm.gfx');
      mesh = makeLattice(10, 10, 6, 50);
      obj = new Obj3D(mesh, { cx: 160, cy: 100, dist: 3.5, focal: 140, mode: 8 });
      ctx = makeRenderContext(env.scr, luts);
      plzm = env.gfx('textures/plzm.gfx').px;
      nodes = new Int32Array(26 * 41 * 3); d8 = new Uint8Array(256);
      bufA = new Uint8Array(64000); bufB = env.gfx('other/dummy.gfx').px.slice();    // blur target = dummy.gfx pixels (keeps its content where no ray lands)
      fade = F(0.6); clock.reset();
    },
    frame(st) {
      const t = clock.time(st), scr = env.scr;
      d8.set(plzm.subarray((Math.trunc(t) & 0xff) << 8, ((Math.trunc(t) & 0xff) << 8) + 256));
      warpMeshB(nodes, t);
      gridWarpStrip8(bufA, 0, d8, nodes, luts.lut1);
      radialPathBlur(6, R.rays, bufA, bufB, R.pairs, R.npairs);
      lutLookup2D(scr, bufB, bufA, lut);
      printText(scr, TEXT, 10, 10, fnt, luts.lut1, luts.lut2);
      const ax = F(sin(t * 0.01) * 0.5), ay = F(sin(t * 0.02) * 0.5), az = F(sin(t * 0.03) * 0.5);
      blackHole(mesh, t);
      if (st.pos > 0xa30) fade = F(st.dt * 0.01 + fade);
      distanceColours(mesh, t, fade);
      obj.mode = 0; rotate(obj, ax, ay, az);
      obj.mode = 8; project(obj); render(obj, ctx);
    },
  };
}
