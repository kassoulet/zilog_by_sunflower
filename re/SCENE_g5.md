# Scenes 8, 9 and the credits loop (group g5)

Files: `site/js/scenes/scene8.js`, `scene9.js`, `_g5final.js` (credits, re-exported from scene9.js as `createFinalScene`), helpers `_g5common.js`
(shared tables/fonts), `_g5mesh.js` (mesh prep + point deformers), `_g5draw.js` (vertex sprites + grey Gouraud filler).
Tests: `tools/test/g5_gen.py` (ORIGINAL code under Unicorn -> `tools/out/g5_vectors.json`), `g5.test.mjs`, `run_g5.sh` (48 vectors, all pass).
Pictures: `site/img/scene8.png`, `scene8_intro.png`, `scene9.png`, `scene9_credits.png`.

**Loop numbering (important).** main() has 11 loops, not 10. After the `while (order < 0x33)` loop (scene 9, orders 49..50) comes one more,
`while (order < 0x3c && DAT_000314f5 == 0)` (asm 0x14135, orders 51..59, 178.3 s .. end of song 209.4 s). That one is the *credits* loop with the
text prints (pos > 0xe18...). The task text mixed the two: scene9.js = the 0x33 loop (grid of lines over the cube tunnel); the credits are
`_g5final.js` (`createScene` there, `name: 'scene10 (credits)'`, orderStart 51, orderEnd 60; the host must run it after scene 9 and stop at the song end).
Decompiler variable names (`iStack_48`...) do NOT match the asm frame offsets of main; always use `[ebp-X]` from asm (map: -0x34 handdraw.gfx, -0x30 hmask2.gfx,
-0x28 stripe.gfx, -0x20 second screen, -0x1c ray table, -0x18 pal LUT, -0x90 verdana font, -0x8c verd_sm font, -0x7c zilog2.gfx, -0xc8 spot sprite table,
-0xc0 256K scratch texture, objects at -0x1f8/-0x1d8/-0x198).

Common: time `t = DAT_00040310 = ticks*0.25 - DAT_00040314`. Scenes 8 and 9 do not re-base (scene 7 set it at order 35, 122.898 s: `BASE7`),
the credits loop re-bases at its first frame. Mesh files: hexp_on2, cyl, cub_tun2, zilog1, zilog1_o (3d/*.mob); everything is drawn with the library
(mesh3d.js render modes) plus the g5 helpers.

## Scene 8 (orders 41..48, 143.7-171.3 s)   `scene8.js`
Globals: `A`=DAT_00040348 (starts 20, -0.08*dt), `B`=DAT_0004034c (starts 2.0, -0.006*dt once A < 2), `P`=DAT_00040338 (sprite size), `wipe`=DAT_0004032c (260).
**Phase 1 (B > 0, about 8 s): 2D plasma intro + flying hexagon tiles.**
* background: 256 byte row of `plzm.gfx` (row = trunc(t) & 255) -> `gridWarpStrip8` with the 41x26 swirl mesh `warpMeshB(t)` into the second screen (8 bit) ->
  `radialPathBlur(6, rays)` (the 512-ray table of 0x14d0b) -> `lutLookup2D` through the `pal.sc` colour LUT (0x15168) => teal/red radial "rays" around a white blob.
* text "thence to a lightness / and, by this declension / into the madness wherein he raves" (verd_sm font, alpha 0x5a, line spacing -2) at (10,10).
* hexagon plane `hexp_on2` (7 points per hexagon): `0x1b687` fixes the winding and stretches y by 1.03, `0x1b04f` gives planar uv = picture coordinates (320x200).
  `0x21664` (time shifted by -353) scatters every tile with its own 3 rotation angles (from the tile's integer centre and t), zoom `12-11cos(0.15A)` and a z wave;
  amplitude `1-cos B` (tiles fly in and settle as A,B -> 0). Drawn twice: spot sprites on all tile vertices (mode 9, radius 3B*invz) and the tiles as mode 4/sub 4
  (`tri_26e28`, the picture `handdraw.gfx` used as a 320 wide screen-space texture, so the tiles reveal the drawing exactly where they land).
**Phase 2:** `handdraw.gfx` (a hand-drawn woman, 32 bit) blitted; the cylinder `cyl.mob` is deformed by `0x20a10` (radial lens with a wandering centre) and drawn only as glow
sprites: `0x1a415` for points in front of the centre (alpha-modulated by the picture `hmask2.gfx`, so sprites vanish behind the hand-drawn hair) and `0x1a5ea`
for the back ones; `P` grows to 26 (order < 47) then shrinks. A 4 frame add-blit flash of `aph1..4.gfx` at order 43 rows 5..8 (`pos` 0xac5..0xac8).
From order 47: second screen = `stripe.gfx` + twisted `cub_tun2` (`0x2112c` ring twist; faces `0x1ac25` grey additive Gouraud with intensity = depth uv, then
dark contour lines mode 6/sub 5) and `maskWipeCrossfade(hmask2, threshold 260 - 0.9*dt per tick)`: the drawing is replaced by the purple tunnel through the hand-drawn mask.

## Scene 9 (orders 49..50, 171.3-178.3 s)   `scene9.js`
`stripe.gfx` background + the same twisted cube tunnel (x offset slides left after pos 0xc80, `0.9*dt`/tick) + **a 42 x 19 wire grid**: the point (i,j) is at
`(220+5j+10 sin(sin(.072t+.1i)+.05t+.1j), 5i+10 sin(sin(.032t+.1i)+.06t+.1j))`, two anti-aliased lines per cell (to j+1 and i+1) whose end brightness is
`zilog2.gfx[(trunc(i+t)&127)*20 + j] * k` (20x128 byte picture scrolling by one row per time unit => the grid cells light up in the shape of the picture), `k` fades in until
pos 0xc60 and out from 0xca0. Matches the reference (bright tiles/cubes at the left, thin mesh at the right).

## Credits loop (orders 51..59, 178.3 s - end)   `_g5final.js`
Background `stripe.gfx`; `zilog1_o` (outline copy of the logo) textured with `cityligh.gfx` (mode 4, `tri_25fc0`, planar uv 256x256) plus white silhouette lines (mode 5, dist 3.2);
the extruded logo `zilog1` (`0x1b854` pairs every front vertex with its back vertex; `0x219e8` pushes the back vertices radially away from a wandering point by
`150+100 sin(...)+glow`, glow = 50 on every module sync marker `DAT_000314f4==1`, decaying 1/tick => the light-ray burst on the beat) drawn as grey additive faces (`0x1ac25`) and
depth coloured edges (mode 6/0); finally the 20x20 wire grid (`0x1b960`, z=-50, `0x1b2a4` brightness) rippled by `0x206e0`. Credits "mrock, falcon, visualize, voomie"
(verdana, alpha byte patched into the string, `\x08<alpha>`): line k starts when pos > 0xe18+6k (order 56), alpha 255 -> 0 at 0.9/tick.

## Function map (orig -> JS)
| orig | JS | |
|---|---|---|
| 0x1b687 | `_g5mesh.f_1b687` | face winding fix by xy area, y*1.03 (hexp_on2) |
| 0x1b04f | `f_1b04f(m,w,h)` | planar uv = bbox normalised to w x h, y flipped |
| 0x1b1b4 | `f_1b1b4` | uv.x = depth normalised to 1..255 (colour for lines/Gouraud) |
| 0x1b2a4 | `f_1b2a4` | uv.x = max(0, 255 - 0.51 r) (needs the x87 64-bit residue, see below) |
| 0x1b7e3 | `f_1b7e3` | swap v0,v1 of every face |
| 0x1b854 | `f_1b854` | front/back vertex pairing of zilog1 |
| 0x1b960 | `f_1b960(w,h,spacing)` | wire grid mesh (npts, edges) |
| 0x20a10 / 0x2112c / 0x21664 / 0x206e0 / 0x219e8 | `f_20a10 f_2112c f_21664 f_206e0 f_219e8` | per frame point deformers (pts -> xpts), all take t explicitly |
| 0x19f57 / 0x1a415 / 0x1a5ea | `_g5draw.f_19f57 f_1a415 f_1a5ea` | vertex sprite loops |
| 0x1ac25 + 0x27128 + 0x2d0bc | `f_1ac25`, `tri_27128` | additive grey Gouraud faces (painter order) |
| 0x206b4 | not ported | sprintf of the credit strings (constants in `_g5final.js`) |
| 0x22e0e 0x1e62e 0x1743b 0x22b9c 0x17641 0x1ecaa 0x1c4b4 0x1c4f6 0x14d0b 0x15168 0x14639 | library (fx2d) | |
Validation: `deform`: 2112c, 206e0 bit identical; 21664/20a10/219e8 within 1 float ulp-ish (rel < 2e-5 worst, 20a10 only because x87 sin/cos vs libm);
prep functions identical; 1ac25/19f57/1a415/1a5ea render pixel exact (0 differing pixels on all 8 cases incl. clipped ones; one case has 6 px of mask garbage:
sprites at x<0,y~0 read the mask at a negative index = heap memory in the original).

## Interesting inner loops (for the explainer)
1. **Grey Gouraud span with a byte that wraps - 0x2d0bc** (triangle = `0x27128`). Intensity is an 8.16 fixed value kept as `bl` (integer, wraps at 256) with the fraction in the top half of the same register after `rol ebx,16`;
   `adc al,ah` folds the carry of the fractional add into the integer; the pixel is a saturating add of `al` to all three channels using `jae` tricks:
   ```
   2d1db: rol ebx, 0x10            ; fraction -> high half
   2d1e4: mov al, bl / 2d1e6: mov ah, [0x41474]   ; al = integer intensity, ah = integer step
   2d1ec: mov edx,[edi] / add dl,al / jae / mov dl,0xff      ; blue  += al, saturate
   2d1f4: add dh,al / jae / mov dh,0xff                       ; green
   2d1fa: ror edx,8 / add dh,al / jae / mov dh,0xff / rol edx,8   ; red (reached by rotating the dword)
   2d208: add ebx, ebp / adc al, ah   ; fractional step, carry into the integer
   ```
   Because it only *adds*, overlapping faces glow brighter: the "light tunnel" look comes from a plain painter loop with no z-buffer.
2. **Radial lens with fpatan - 0x20a10**: convert to spherical coordinates around a wandering centre, compress r by `sqrt(r^2+200000)-200`, convert back:
   `20ac5: fld [esp+0x10] / fld [esp+0xc] / fpatan` (atan2), `20ae3: fadd qword / fsqrt / fld [esp+0x14] / fpatan` (polar angle), `20b1b: fsqrt / fadd -200`,
   `20b2b: fsin ... 20b41: fcos / fmul / fadd centre`. 0x206e0 uses the same skeleton with `r += 140 sin(c1 r - ... )` (ripple), 0x219e8 with `r += p` (extrusion).
3. **Depth map as a wipe mask**: the unusual use of ordinary parts - `0x1b1b4` stores depth as the uv.x "colour" of each vertex, the same field the line drawers (modes 6/8) read as colour,
   and `0x1ac25` reads as intensity: one number drives the lines, the Gouraud fill and (in scene 8) the cross-fade mask threshold `0x1ecaa`.
4. **x87 64-bit residue changes an integer**: `0x1b2a4` computes `trunc(255 - r*0.51)`; for r=400 the exact product is 204.0000000000000036 which survives in the 64 bit mantissa
   (-> 50) but rounds to exactly 204 in a double (-> 51). Emulated with a Veltkamp split in `trunc255()`. Same family as the `truncSum` of the library.
5. **Scrolling picture lights a deformed grid** (scene 9): the grid has no data of its own; `zilog2.gfx` is read with a `& 0x7f` row wrap from `trunc(i+t)`, so time shifts the picture one row per time unit,
   the three samples per cell give the colours of two lines at once (`ax = (b<<8)|a` is the packed (end, start) colour argument of `0x21f3b`).

## Known differences / uncertain
* Time base of scenes 8/9 (`BASE7`) is derived from the music time of order 35, not the real tick of the scene 7 start; it only phases the swirl centre/wave positions (not their look).
* Reference timeline is non-linear, the sequences were matched by eye (intro swirl+text -> tiles -> face + sprite spiral -> tunnel wipe -> grid -> logo credits all match in structure, motion and colours with R/B swapped).
* Float deformers use doubles for x87 extended intermediates (max rel error vs original 2e-5, a few ulp of float32 visually irrelevant).
* Intro (`B>0`) radial blur reads the ray table 256 entries past its end (zeros here, heap in the original).
* The host must call the credits scene after scene 9 and feed `st.sync` (DAT_000314f4 == 1) for the beat kick; without it the extrusion pulses only with the sine term.
