# SCENE_g3: scenes 4 and 5 of main() (`func_100d3`)

Files: `site/js/scenes/scene4.js`, `scene5.js`, helper `_g3.js` (`coneWarp` = func_21290, shared tables/fonts), tests `tools/test/g3_gen.py` + `g3.test.mjs`
(`python g3_gen.py tools/out/g3_vectors.json; node g3.test.mjs tools/out/g3_vectors.json` -> 15 cases bit exact), whole-scene renderer `tools/test/g3_render.mjs <scene4|scene5> outDir [everySec]`
(runs the scene at 20 fps over the music timeline: order/row/sync). Images: `site/img/scene4.png`, `scene5.png`.
Everything else is lib code (fx2d.js / mesh3d.js); all calls were identified in `re/asm2.txt` 0x1202d..0x12a97.

## Scene 4 (order 23..26, 81.4 - 95.2 s, loop `while (DAT_00031514 < 0x1b)` asm 0x1202d)

**What you see.** Pink/chrome tubes picture (`fullpics/truesimu.gfx`, "SIMULCRA" caption) with a big liquid-bronze blob (`3d/q1_.mob`, env mapped with
`textures/env1.gfx`) that flies in from the right edge to the left (centre x = 320 - time) tumbling slowly. White silhouette lines of the same mesh are drawn on a second copy of the
picture and cross-faded in through a mask (`fullpics/mask7.gfx`): the outline shows through only where the mask is non zero (soft white halo). A small text
("lypho.. / acid.. / ni's'se..", the music order/row printed as hex, alpha pulsing with sin(t)) sits at (2,10) in the `fonts/cupertin.gfx` font.
On music sync markers: `sync&0xf` != 0 -> a small picture `smalpics/jp13..jp20` (selected by `sync&7`, vertical Japanese text) is blended with **difference** over the frame (`func_1c7a6`);
`sync&0x10` -> a grey/green strip (colour matrix, `func_22990`, rect (20-7sin2t, 20-7sin1.3t)-(300+.., 40+..)) pulses.
From order 26 row 32 (pos > 0x6a0) the vertical box blur radius `DAT_00040348` grows by dt per frame up to 90: the frame dissolves into vertical streaks (end of the scene, the last frames are shown through the blur buffer).
Reference comparison: matches the video (structure, motion, colours after R/B swap).

Per frame (asm 0x1203e..0x123c4):
```
blitCopy(screen, truesimu); blitCopy(B, truesimu)                       1c4b4 x2 (esi=[ebp-0x64], edi = 402f0 / puStack_34)
ax=3 sin(cos(.008t)+.009t)  ay=3 sin(cos(.007t)+.018t)  az=3 sin(cos(.006t)+.017t)     (t = DAT_40310, float32 stores)
rotate(obj mode 1) ; rotateNormals ; cx = 320 - t ; project ; render mode 1 on screen   17e5e 18144 1870b 18beb
DAT_402f0 := B ; render mode 5 (silhouette) ; DAT_402f0 := screen                       lines go to B
sprintf(buf,"\x08\x80 lypho%x\nacid%x\nni\x0bs\x0bse%x", order*row, order-row, order+row); buf[1]=trunc(120 sin t+128)   206b4 -> 273c5 (vsprintf)
printText(buf, x=2, y=10, cupertino)                                                    17641 (edx=x, ebx=y, ecx=font)
alphaMaskCrossfade(screen <- B, mask7+0x16, table 402f8)                                1ee44
if pos>0x6a0: blur += dt ; blur=min(blur,90)
if sync&0xf: blitDifference(screen, jp13+(sync&7))                                      1c7a6
if sync&0x10: colorMatrixRect(...)                                                      22990
if blur>3: boxBlurV(screen -> B, trunc(blur)); flip B   else flip screen               16e53 / 17c11
```
Init (asm 0x11fa.. -> 0x12029): `memcpy(d4, env1+0x16, 0x40000)` (env texture), obj = {q1_, cx=160, cy=130, dist=6, focal=140, tex=d4, mode 1, sub 0}, faceNormals+vertexNormals once, `DAT_00040348=0`, time base = ticks*0.25.
Notes: `sync` is the *sticky* last marker value (DAT_000314f4 is never cleared by main), so the difference picture is blended on every frame until the next marker sets a value with low nibble 0.
The text buffer's first bytes are the printText control code 8 (alpha) and its parameter, which main overwrites after sprintf with the pulsing alpha.

## Scene 5 (order 27..30, 95.2 - 109.0 s, loop `while (DAT_00031514 < 0x1f)` asm 0x1245e)

**What you see.** The 8-bit-looking swirl picture `fullpics/circles.gfx` (concentric ring patterns, orange/black/white) with a swirling cloud of 909 additive glow sprites
(mesh `3d/cones3.mob`, 101 rings of 9 points; point sprites = `radialCosSpot` soft disc, coloured per point from `textures/cone_kol.gfx`, size by 1/z) twisting like a tornado.
A thin frame (inset 5 px from the cloud's screen bounding box) and 4 chamfer-ish diagonals (8 `func_21f3b` lighten lines, each with a colour ramp 0 -> fade, fade = 255) follow the cloud. From order 30 row 48 (pos > 0x7b0) the cloud
falls/flies upwards (cy = 100 - f^2, f += dt/2) and the frame fades out (fade -= 4*dt).
Matches the reference (white glow tornado over the circles, frame lines, and the ending lift-off).

Per frame (asm 0x1246f..0x12a97):
```
if pos>0x7b0: f += dt*0.5; fade = max(0, fade - 4 dt)
blitCopy(screen, circles)                       1c4b4 (esi=[ebp-0x6c] = circles.gfx)
cy = 100 - f*f ; angles 0.5 sin(0.01t), 0.5 sin(0.02t), 0.5 sin(0.03t)
coneWarp(mesh, t)        21290: pts -> xpts (the animation), mode 0 rotate in place (17e5e reads xpts), mode 9: project 1870b, render 18beb (sprites, sub 3 = coloured)
bbox = projectedBBox(p2d)  1c34e -> DAT_40358..64 = minX,maxX,minY,maxY
8 x line_21f3b(ctx, c0, c1, ..) coordinates trunc((bbox +- k)*65536); k = 5 (frame edges), 4/12 (diagonals); colour byte pair ax=fade or fade<<8
```
Lines (a=minX b=maxX c=minY d=maxY; A -> B; fade at A or B): top (a+5,c+5)-(b-5,c+5) fade at B; bottom (a+5,d-5)-(b-5,d-5) A; left (a+5,c+5)-(a+5,d-5) B; right (b-5,c+5)-(b-5,d-5) A;
diagonals (a+12,c+4)-(b-4,c+12) A, (a+4,d-12)-(b-12,d-4) B, (a+12,c+4)-(a+4,d-12) A, (b-4,c+12)-(b-12,d-4) B.
Init: obj = {cones3, cx=160, cy=100, dist=3, focal=140, tex=spot (DAT_402f4+0x20000), mode 9, sub 3}, `DAT_00040308 = cone_kol+0x16`, f=0, fade=255, time base.

## Function map (orig -> JS)

| orig | JS | |
|---|---|---|
| 0x21290 | `_g3.js coneWarp` (`f_21290`) | per 9-point ring animator (new, differential tested, bit exact on 15 times x 909 points) |
| 0x1c4b4 / 0x1c7a6 / 0x1ee44 / 0x22990 / 0x16e53 / 0x17641 / 0x1c34e | fx2d `blitCopy / blitDifference / alphaMaskCrossfade / colorMatrixRect / boxBlurV / printText / projectedBBox` | lib |
| 0x17e5e 0x18144 0x1870b 0x18beb 0x1841d 0x185d4 | mesh3d `rotate rotateNormals project render faceNormals vertexNormals` | lib |
| 0x21f3b | mesh3d `line_21f3b` | lib; register map: ebx=x_a ecx=y_a esi=x_b edi=y_b (16.16), ax = c_a | c_b<<8 |
| 0x206b4 -> 0x273c5 | inline `'\x08'+..+hex32()` in scene4.js | `sprintf` (varargs): `%x` of 32-bit two's complement |
| 0x14639 / 0x148c4 / 0x174fe | `radialCosSpot / colorMatrixTables / buildFont` | built once in `shared(env)` |

## Interesting inner loops / tricks

1. **x87 stack as register file** - `func_21290` inner loop 0x2143c..0x2147e. The 5 per-ring constants (sin a, cos a, centre y, centre x, scale) are pushed on the FPU stack once and
   every point is `fld/fsub st(n)/fmul st(n)` against them, no memory operands: a 2-D rotate+scale of a point about a moving centre in 17 instructions:
   ```
   2143c: fld [eax] / 2143e: fsub st(2) / 21440: fmul st(1) / 21442: fstp [esp]      ; fx = (x - cx) * sx
   21445: fld [eax+4] / 21448: fsub st(3) / 2144a: fmul [esp+0x40] / 2144e: fstp [esp+4]   ; fy = (y - cy) * sy
   21452: fld [esp] / 21455: fmul st(4) / 21457: fadd st(2) / 2145d: fmul st(6) / 2145f: faddp   ; x' = fx*cos + cx + fy*sin
   21466: fmul st(5) / 21468: fadd st(3) ... 21471: fmul st(5) / 21476: fsubp st(1)            ; y' = fx*sin + cy - fy*cos
   ```
   The ring index `k = trunc(z0 - 500)` (0x212c1..0x212cf) is the only thing that differs between rings: every ring gets a phase `0.01*k*sin(.01t)`, scale `0.007*k*..` etc. so the cone twists into a vortex. z = 200 cos(.04t + .008k) (0x21403) makes the rings breathe in depth.
2. **Alpha cross-fade with a table pointer as base register** - `func_1ee44` (0x1ee5d..0x1eeb0): `xor bx,bx / mov bl,[esi+ecx]` builds `ebx = table | mask`;
   `shl bx,8 / mov bl,al / mov al,[ebx]` indexes the 64 KB table with (alpha<<8 | channel) so `c*alpha/255` is one load per channel; `ror eax,8 ... rol eax,8` reaches the third channel;
   the second half uses `not bh` (= 255-alpha) for the other image, `add eax,ebp` sums both. Early outs for alpha 0 (`or bx,bx / jle`) and 255 (`cmp bx,0xff` -> plain copy of the other image). The loop counter runs from -0xfa00*... up to 0 (`xor ecx,-1 / inc ecx`, `jne`): no cmp.
3. **Free vertical blur radius ramp** - the end of scene 4 is simply `DAT_00040348 += dt` fed to `func_16e53` (self-modifying box blur, see PORT_2d #1) from a float counter; the blur result is flipped from the second buffer.
4. **Text as sprintf + control codes** - the on-screen string is built by `vsprintf` (0x273c5) from the music position, with the font engine's in-band control bytes (`0x08 alpha`, `0x0b` toggle darken) embedded in the format string;
   two bytes are patched after the print to animate alpha.
5. **Wireframe cage from the projected bounding box** - `func_1c34e` (min/max with `fcomp/sahf/jae`, clamp to 319/199 = `0x439f8000`, `0x43470000`) then 8 AA lines with 16.16 coordinates; the colour pair in `ax` makes each line fade along its length, and `fade<<8` swaps which end is bright.
