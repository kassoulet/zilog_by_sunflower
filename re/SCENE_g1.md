# Scenes 0 and 1 (main loops `while (order < 5)` and `while (order < 14)` of func_100d3)

JS: `site/js/scenes/scene0.js`, `scene1.js`, helpers `_g1common.js` (tables/fonts/clock), `_g1fx.js` (0x1d200, 0x1d3d8).
Test: `tools/test/run_g1.sh` (original 0x1d200/0x1d3d8 under Unicorn vs JS), visual: `node tools/test/g1render.mjs sceneN outDir [stepSec]`
(drives the scene with the real music timeline: order/row/sync from `UsmPlayer.timeline()`, dt = 4 ticks/frame). Pictures: `site/img/scene0.png`, `scene1.png`.
Compared with the DOSBox reference (R/B swapped) frame by frame on contact sheets: structure, timing, colours match.

## Scene 0 (music 0 - 17.3 s, orders 0..4): "the knot"
What you see: black screen, a tangled wire-frame sphere-knot (`3d/3b_2.mob`) rises from below the screen to the centre-right, wobbling on a
Lissajous path (cx = 220 + 50 sin(..), cy = 100 + 50 cos(..) + fly-in offset 240 decaying at 0.7/tick); after order 4 row 32 it drifts to the right and out.
Drawn with the 3D engine (`render` mode 5: anti-aliased silhouette lines, grey 255 through the "screen" LUT), then mode 9/3: one additive soft sprite
(`fullpics`-style radial cosine spot made by 0x14639) per vertex, size 26/z, colour of vertex i = i-th pixel of `textures/silh_kol.gfx` (DAT_00040308, a 45x45 gold gradient).
The number of vertices drawn is `min(order*64+row, npts)`: points appear one per music row (mesh->npts is poked, restored afterwards).
Post: vertical box blur 0x16e53 with radius `int(3 sin(cos(0.5t)+0.1t)+7)` (breathing 4..10) from the screen to a second buffer (the "motion smear");
on music sync markers 2/3 a horizontal blur (0x16cdd) of radius 50 decaying by 3/tick (min 3) is added: the object explodes into a smear on the beat.
Marker 1 prints "ugly, discrete jumps" (font `fonts/cupertin.gfx`, 10,175, with the glyph blend of 0x17641).  All time functions use t = ticks*0.25 - base (float32).
Rotation angles: `a = 3 sin(cos(0.008t)+0.009t)`, `3 sin(cos(0.007t)+0.018t)`, `3 sin(cos(0.006t)+0.017t)`.
Not 2D-library new code: everything is lib (mesh3d + fx2d). `rotateNormals` (0x18144) is called by the original but its output is unused by modes 5/9 (mesh has no normals): skipped.

## Scene 1 (17.3 - 48.5 s, orders 5..13): "simulcra"
What you see: the full screen picture `fullpics/simulcra.gfx` (orange glass tubes, "SUNFLOWER's ZILOG") is copied to the screen each frame (0x1c4b4), then
1. **Reveal** (first ~6 s, `thr = -32 + 0.7*ticks` until 260): an 8-bit plasma (`cosCosPlasma`, 0x14c51: 16+56(1+cos)(1+cos)) is rendered through a 41x26 *lens mesh*
   built by 0x1d200 into an 8-bit mask (0x1e266 grid warp, 8x8 cells bilinear) and `maskFadeToBlack` (0x1ec58) darkens every pixel whose mask > thr
   (31-step soft edge): the picture emerges from black through a swirling plasma pattern.
2. **Glow spirals**: 16 curves x ~105 sprites (`spriteAddAlpha` 0x1f6b2, radial spot, additive with alpha) on Lissajous paths
   `x = 160 + 60 sin(0.2 i + 0.02t - cos(i - 0.01t)) + s^2*0.01*cos(a)`, `y = 100 + 60 sin(0.3 i + 0.013t) + s sin(a)`, `s = ((130t + i) & 0xffff)*0.003`,
   radius `5 + 4 sin(+-0.14 t + a + i)`, alpha `255 - 12k + k*radius` with k = DAT_00040348 (grows to 21 during orders 5,6, decays after order 9). Odd/even rings counter-rotate (sign flip).
3. **Text** (sync marker 1 / 2): "art is not" / "what you see" (cupertin font, darken mode `\x0b`, at 2,10); the alpha byte of the string is patched
   (buf[1] = DAT_00040338, 255 -> 0 at 3/tick) so the text fades in/out.  (The original builds the string with sprintf 0x206b4 -> 0x273c5, no formatting.)
4. **Plasma inversion** (order > 9): second lens mesh (0x1d3d8, two independent lenses + scroll 0.1t), node shade = 255*65536 decaying 0.9/tick; the 8-bit result is used as the
   per-pixel invert amount (`maskInvert` 0x1eeb4): blue/ink colours, smooth blobs.
5. **Exit** (pos >= 0x340): `maskFadeToBlack` with `fullpics/mask5.gfx` as the mask, threshold 270 - 1.2*ticks: wipe to black along the mask shape.
Scene end is music driven (order 14).

## Function map (orig -> JS)
| orig | JS |
|---|---|
| 0x17e46 memset screen | `scr.fill(0)` |
| 0x17e5e / 0x1870b / 0x18beb | mesh3d `rotate` / `project` / `render` |
| 0x16e53 / 0x16cdd | fx2d `boxBlurV` / `boxBlurH` |
| 0x17641 | fx2d `printText` |
| 0x1c4b4 | `blitCopy` |
| 0x1d200 | `_g1fx.warpMeshLens` (new) |
| 0x1d3d8 | `_g1fx.warpMeshLens2` (new) |
| 0x1e266 | `gridWarpTex8` |
| 0x1ec58 / 0x1eeb4 | `maskFadeToBlack` / `maskInvert` |
| 0x1f6b2 | `spriteAddAlpha` (T = DAT_402f8) |
| 0x206b4 (sprintf) | string constant with patched alpha byte |
| 0x14639 / 0x14834 / 0x14c51 | `radialCosSpot` / `screenBlendTables` / `cosCosPlasma` (built lazily in `_g1common`) |

Validation of new code: 16 vectors, original vs JS: 15 bit-identical; 0x1d200 at T=2600 (far beyond the ~540 s of scene time) differs in 27 of 1066 nodes by <=2 (x87 `fsin` of large args vs libm).

## Interesting inner loops
* **Lens mesh, 1/r^2 fisheye in 3 dwords per node** (`0x1d2fb..0x1d3bd`): per node a rotation of (x,y) by an angle that is itself wobbling (`fsin` of `fsin`), scaled by `1/(0.001*(a x^2 + b y^2) + c)`:
  `1d345: fmul st(0)` (square) / `1d347: fmul [esp+0x40]` / `1d35b: fmul [0x3e348] (0.001)` / `1d365: fld1` / `1d367: fdivrp st(1)`; the result times 524288 goes through `fistp`
  and `& 0xffffff` (`1d37f: fmul [0x3e350]` `1d389: fistp`, `1d3a2: and eax,edi`) => 8.19 fixed point texture coordinates that the 8x8 cell warp interpolates: only 1066 nodes (41x26) cost trig, the 64000 pixels are interpolated.
  Trick: the angle is stored as float for `sin` but `fcos` is taken from the unrounded register (`1d230: fst dword [esp+0x28]` then `1d234: fcos` on st0).
* **Plasma as a mask-driven fade**: `0x1ec87: shl ebx,0xb / mov bl,al / mov al,[ebp+ebx]` index = (k<<11)|channel through the inverse screen table: a 31-step soft fade band per channel by one lookup (see PORT_2d #5).
* **Partial invert by a mask** (0x1eed8..0x1ef1c): `m*(1-c)` and `(1-m)*c` are two table lookups each (`1eef3: mov al,[ebx]`, `1ef08: not bh` flips the table row to 255-m), the two results are added in one 32-bit `add eax,ebp`.
* **Glow sprite storm**: ~1700 `spriteAddAlpha` (alpha through the inverse blend table, `T[alpha<<8|~m]`, adc-stepped 8.8 texture coords) per frame at 70 Hz-class speed.
* **Scene 0 "reveal by npts"**: the mode-9 renderer iterates `for i < mesh->npts`; main just stores `min(order*64+row, npts)` into the first dword of the mesh before the call.

## Notes / open points
* `st.sync` must persist (last marker value, as in the original); frames with sync==1 reset the text alpha every frame (text visible until the next marker, then fades).
* `rotateNormals` not called (see above). No lib bugs found.
