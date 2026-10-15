// Scene 1 (main loop `while (order < 14)`, music 17.3 .. 48.5 s): "simulcra" picture revealed through a warped plasma mask, spiral of glow sprites,
// text, then a plasma-driven colour inversion and a final wipe to black through mask5.
import { blitCopy, gridWarpTex8, maskFadeToBlack, maskInvert, spriteAddAlpha, printText } from '../lib/fx2d.js';
import { warpMeshLens, warpMeshLens2 } from './_g1fx.js';
import { g1Shared, makeClock, F } from './_g1common.js';
const S = Math.sin, C = Math.cos;
const TXT = { 1: 'art is not', 2: 'what you see' };

export function createScene(env) {
  const g = g1Shared(env), scr = env.scr, buf8 = new Uint8Array(64000), nodes = new Int32Array(26 * 41 * 3), clock = makeClock();
  let sim, mask5, v2c, v30, v34, v38, v48, txt = null;
  const textBuf = (s) => Uint8Array.from('\x08\xff \x074\x0b' + s, (c) => c.charCodeAt(0));
  return {
    name: 'scene1', orderStart: 5, orderEnd: 14,
    init() { sim = env.gfx('fullpics/simulcra.gfx'); mask5 = env.gfx('fullpics/mask5.gfx').px; v2c = -32; v30 = 255; v34 = 270; v38 = 0; v48 = 0; },
    frame(st) {
      const T = clock(st), dt = st.dt;
      v2c = F(dt * 0.7 + v2c);
      if (st.order < 7) { v48 = F(dt * 0.02 + v48); if (v48 > 21) v48 = 21; }
      if (st.order >= 9) { v48 = F(v48 - dt * 0.01); if (v48 < 0) v48 = 0; }
      blitCopy(scr, 0, sim);
      if (v2c < 260) {                                               // reveal wipe: plasma seen through the lens mesh is the mask
        warpMeshLens(nodes, T); gridWarpTex8(buf8, 0, g.plasma, nodes, g.lut2);
        maskFadeToBlack(scr, buf8, Math.trunc(v2c), g.lut2);
      }
      if (v48 > 0) {                                                 // 16 rings of ~105 glow sprites on Lissajous curves
        let fs = 1;
        for (let i = 0x1400; i < 0x10000; i += 0xf00) {
          for (let ang = 0; ang < 6.28; ang = F(ang + F(0.06))) {
            const s = F(((Math.trunc(T * 130 + i)) & 0xffff) * 0.003);
            const x = F(S(i * 0.2 + T * 0.02 - C(i - T * 0.01)) * 60 + 160 + C(ang) * (s * s * 0.01));
            const y = F(S(ang) * s + (S(i * 0.3 + T * 0.013) * 60 + 100));
            const sz = F(S(fs * T * 0.14 + ang + i) * 4 + 5);
            const alpha = Math.trunc(255 - v48 * 12 + v48 * sz);
            spriteAddAlpha(scr, Math.trunc(x * 256), Math.trunc(y * 256), Math.trunc(sz * 256), g.spot, alpha, g.lut2);
          }
          fs = -fs;
        }
      }
      if (st.sync === 1 || st.sync === 2) { txt = textBuf(TXT[st.sync]); v38 = 255; }
      v38 = F(v38 - dt * 3);
      if (v38 > 0) { txt[1] = Math.trunc(v38); printText(scr, txt, 2, 10, g.font, g.lut1, g.lut2); }
      if (st.order > 9) {                                            // plasma-driven inversion fading out
        v30 = F(v30 - dt * 0.9);
        warpMeshLens2(nodes, T);
        if (v30 > 0) for (let i = 0; i < 26 * 41; i++) nodes[i * 3 + 2] = Math.trunc(v30 * 65536);
        gridWarpTex8(buf8, 0, g.plasma, nodes, g.lut2);
        maskInvert(scr, buf8, g.lut2);
      }
      if (st.pos >= 0x340) { v34 = F(v34 - dt * 1.2); maskFadeToBlack(scr, mask5, Math.trunc(v34), g.lut2); }   // final fade through mask5
    },
  };
}
