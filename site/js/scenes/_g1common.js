// _g1common: lazily built tables/assets shared by scene0/scene1 (what main() builds before its first loop), cached in env.shared.
import { screenBlendTables, radialCosSpot, cosCosPlasma, buildFont } from '../lib/fx2d.js';
export const F = Math.fround;
export function g1Shared(env) {
  const sh = (env.shared ??= {});
  if (!sh.g1) {
    const lut1 = new Uint8Array(65536), lut2 = new Uint8Array(65536); screenBlendTables(lut1, lut2);   // DAT_402f4 / DAT_402f8  (0x14834)
    const spot = new Uint8Array(65536); radialCosSpot(spot);                                          // LUT+0x20000 soft spot (0x14639)
    const plasma = new Uint8Array(65536); cosCosPlasma(plasma);                                       // 0x14c51 egg-box plasma
    sh.g1 = { lut1, lut2, spot, plasma, font: buildFont(env.gfx('fonts/cupertin.gfx'), 0x21, 0x5e) }; // font #4 (cupertino)
  }
  return sh.g1;
}
/** time like the prologue: DAT_00040310 = ticks*0.25 - DAT_00040314 (float32); the base is latched at the first frame of the scene */
export function makeClock() {
  let base = null;
  return (st) => { if (base === null) base = F(st.ticks * 0.25); return F(st.ticks * 0.25 - base); };
}
