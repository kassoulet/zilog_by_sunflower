// _g5final.js -- the last loop of main() (orders 51..59 or until the song ends, music 178.3-209.4 s): the 3D "zilog" logo, extruded
// radially, textured with city lights, inside a rippling wire grid, plus the credits (mrock / falcon / visualize / voomie) printed
// from song position 0xe18 on, each line fading out.  Not one of the 10 `while (order < N)` loops of the Scene API (N = 0x3c, also stops on DAT_000314f5).
import { Obj3D, rotate, rotateNormals, faceNormals, vertexNormals, project, render } from '../lib/mesh3d.js';
import { blitCopy, printText } from '../lib/fx2d.js';
import { f_1b04f, f_1b1b4, f_1b2a4, f_1b7e3, f_1b854, f_1b960, f_219e8, f_206e0 } from './_g5mesh.js';
import { f_1ac25 } from './_g5draw.js';
import { f32, mesh, shared, ctxFor } from './_g5common.js';
const { sin, cos } = Math;
const NAMES = ['\x08\xff mrock', '\x08\xff falcon', '\x08\xff visualize', '\x08\xff voomie'];   // 0x3db84.. (str[1] = alpha byte, patched every frame)
const START = [0xe18, 0xe1e, 0xe24, 0xe2a];                                                      // song positions at which each name appears

export function createScene(env) {
  const g = shared(env), zil = mesh(env, 'zilog1'), zilo = mesh(env, 'zilog1_o'), stripe = env.gfx('fullpics/stripe.gfx');
  const city = env.gfx('textures/cityligh.gfx').px, grid = f_1b960(20, 20, 50);
  const ctx = ctxFor(env.scr, g);
  let objF, objT, objG, pair, base, fade, glow;
  return {
    name: 'scene10 (credits)', orderStart: 51, orderEnd: 60,
    init() {
      f_1b7e3(zil);                                                                                  // flip the winding of the logo
      objF = new Obj3D(zil, { cx: 160, cy: 100, dist: 3.5, focal: 140, tex: city, mode: 6, sub: 5 });     // extruded logo: face fill + coloured edges
      objT = new Obj3D(zilo, { cx: 160, cy: 100, dist: 3.5, focal: 140, tex: city, mode: 4, sub: 0 });    // original outline mesh, textured with the city lights
      objG = new Obj3D(grid, { cx: 160, cy: 100, dist: 3.5, focal: 140, mode: 8, sub: 0 });               // rippling wire grid
      f_1b2a4(grid); f_1b04f(zilo, 256, 256); faceNormals(objT); vertexNormals(zilo); f_1b1b4(zil); pair = f_1b854(zil);
      fade = [255, 255, 255, 255]; glow = 0; base = null;                                              // DAT_00040338..4033c..40344, 40348
    },
    frame(st) {
      base ??= st.ticks * 0.25;                                                                      // DAT_00040314 re-based at the start of this loop
      const t = f32(st.ticks * 0.25 - base), dt = st.dt, pos = st.pos;
      blitCopy(env.scr, 0, stripe);
      const ax = f32(sin(t * 0.01) * 0.5), ay = f32(sin(t * 0.02) * 0.5), az = f32(sin(t * 0.03) * 0.5);
      rotate(objT, ax, ay, az); rotateNormals(zilo, ax, ay, az);
      objT.dist = 3.5; objT.mode = 4; project(objT); render(objT, ctx);        // textured logo
      objT.dist = f32(3.2); objT.mode = 5; project(objT); render(objT, ctx);   // + white silhouette lines slightly nearer
      if (st.sync === 1) glow = 50;                                            // module sync marker: kick the extrusion
      glow = f32(glow - dt); if (glow < 0) glow = 0;
      const p = f32(sin(cos(t * 0.05) + t * 0.1) * 100 + 150 + glow);
      f_219e8(zil, pair, p, t);
      objF.mode = 0; rotate(objF, ax, ay, az); objF.mode = 6; objF.sub = 0; project(objF);
      f_1ac25(objF, ctx); render(objF, ctx);
      f_206e0(grid, t); objG.mode = 0; rotate(objG, ax, ay, az); objG.mode = 8; project(objG); render(objG, ctx);
      for (let k = 0; k < 4; k++) if (pos > START[k]) {                                                 // credits: print, then fade out 0.9/tick
        const s = NAMES[k].split(''); s[1] = String.fromCharCode(Math.trunc(fade[k]) & 255);
        printText(env.scr, s.join(''), 10, 10 + 20 * k, g.verdana, g.lut1, g.lut2);
        fade[k] = f32(fade[k] - dt * 0.9); if (fade[k] < 0) fade[k] = 0;
      }
    },
  };
}
