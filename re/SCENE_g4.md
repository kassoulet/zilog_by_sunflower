# Scenes 6 and 7 (group g4)

JS: `site/js/scenes/scene6.js`, `scene7.js`; helpers `_g4fx.js` (5 scene-specific functions), `_g4common.js` (lazy LUTs / ray tables / fonts, scene clock).
Test: `tools/test/run_g4.sh` (`g4_gen.py` runs the ORIGINAL functions under Unicorn, `g4.test.mjs` compares): **all 17 vectors bit identical**.
Pictures: `site/img/scene6.png`, `scene7.png`. Both scenes are 3D wire/shaded objects over 2D post-processed plasma backgrounds; no fades, the only
"time" input is the music-independent clock `t = ticks*0.25 - base` (base re-set at scene start) plus `st.dt` (fade ramps) and `st.pos` (scene 7 ramp).

## Scene 6 - orders 31..34 (109.0-122.9 s): "brown blob over the swirl"
What the viewer sees: the orange/black/white swirl picture `fullpics/circles.gfx` with a polar warped plasma strip lighten-blended over it
(white rays radiating from a wandering centre that fade in over ~14 s), and a chocolate-brown metallic blob (`3d/k_1.mob`) that slides in from the top, bulging and
rippling, tumbling, drawn env mapped (`textures/env1.gfx` halved, 50% darker) + `textures/cityscap.gfx` (halved) as surface texture (render mode 2, additive `tri_266a0`),
then drawn a second time as white contour lines (mode 5, dist 5.2 instead of 6.0 -> the outline floats slightly larger than the body).
Per frame (loop 0x12b67..0x12ec2):
1. `0x1c4b4 blitCopy` circles.gfx -> screen.  2. 256 bytes of `plzm.gfx` row `int(t)&255` -> `d8` (the strip texture changes once per time unit).
3. `0x22c39 warpMeshA(nodes,t,fade)`, `0x1e941 gridWarpStrip8Inv` -> 8 bit image, `0x1c91e blitLighten` onto the screen (fade = 0x40338 += dt*0.001, clamp 1).
4. `0x20b94 rippleSphere(mesh,t,amp)` pts -> xpts, amp = 200 sin^2(cos(.1t)+.01t)+200; `rotate` (mode 2: in place on xpts), `faceNormals`, `vertexNormals`,
angles `sin(cos(.008t)+.009t)*3` etc.; cx = 8(10 sin(..)+20.5), cy = 6.64(10 sin(..)+12.5) + slide (slide -200 -> 0 at 2 px/tick).
5. `project`, `render` mode 2; mode 5, dist 5.2, `project`, `render`.
Init (0x12a9c): env1/cityscap pixels copied into the 2-texture block and halved (`0x1478a`), `0x1b04f planarUV(mesh,256,256)` (planar uv = bbox of x,y).

## Scene 7 - orders 35..40 (122.9-143.7 s): "wire lattice falling into a black hole"
What the viewer sees: green/teal/red radial streaks with a glowing white core (colourised blurred plasma strip), Hamlet quote
("thence to a lightness / and, by this declension / into the madness wherein he raves", Verdana-small, alpha 90) top left,
and a 10x10x6 lattice of 3D lines whose points are sucked/bent around a wandering singularity; edges are white near the hole and fade to black away from it
(ramp factor 0.6, then growing by dt*0.01 per frame once `pos > 0xa30`, i.e. in the last 16 rows, so the lattice fades out before the next scene).
Per frame (0x12f51..0x1310e):
1. plzm row -> d8; `0x22e0e warpMeshB`, `0x1e62e gridWarpStrip8` -> `bufA` (palette-index image).  2. `0x1743b radialPathBlur(6, rays, bufA -> bufB, pairs)` (64-sample radial blur from screen centre).
3. `0x22b9c lutLookup2D(screen, lo=bufB, hi=bufA, shadeLut)`: colour = pal[bufA] * bufB/64 (palette LUT `0x15168` from pal.sc).  bufB starts as `other/dummy.gfx` pixels (kept where no ray lands).
4. `0x17641 printText`.  5. `0x20a10 blackHole` pts -> xpts, `0x1b533 distanceColours` -> uv.x, `rotate` (mode 0, angles 0.5 sin(.01t/.02t/.03t)), mode 8, `project`, `render` (colour ramp lines, `line_21f3b`).
Init: `0x1bf97 makeLattice(10,10,6,50.0)` (600 points, 3160 edges, no faces), obj cx160 cy100 dist 3.5 focal 140, memset of the second half of the strip buffer (never used).

## Function map (orig -> JS)
| orig | JS | note |
|---|---|---|
| 0x1b04f | `planarUV` (_g4fx) | uv = ((x-minx)*w/dx, h-(y-miny)*h/dy); the second line is *not* rounded before `fsubr` (x87) |
| 0x1bf97 | `makeLattice` | float32 accumulation of the grid, edges: x runs, y runs, z runs |
| 0x20b94 | `rippleSphere` | spherical ripple r' = r + amp*sin(ax+d)sin(by+e)sin(cz+f); `x*x+y*y` is rounded to float32 once (`fst dword [esp+0x20]`) before the second sqrt |
| 0x20a10 | `blackHole` | r' = sqrt(|p-c|^2+200000)-200 around a Lissajous centre c(t) (amplitude 200) |
| 0x1b533 | `distanceColours` | uv.x = 255 - min(255, k|xpt-c|) |
| 0x22c39 / 0x22e0e / 0x1e941 / 0x1e62e / 0x1743b / 0x22b9c / 0x1c4b4 / 0x1c91e / 0x1478a / 0x17641 / 3D engine | lib/fx2d, lib/mesh3d | see PORT_2d / PORT_3d |

## Interesting inner loops (for the explainer)
1. **A 2-D palette lookup in three instructions** - `0x22b9c` (screen = LUT[(strip_idx<<8)|blur]): the 64000-pixel loop runs `ecx` from -64000 to 0 with base registers pre-biased
   (`22ba4: lea edi,[edi+ecx*4]` ... `22bad: xor ecx,-1 / inc ecx` = negate), then
   `22bb1: mov al,[ebx+ecx]` / `22bb4: mov ah,[esi+ecx]` / `22bb7: mov ebp,[edx+eax*4]` / `22bba: mov [edi+ecx*4],ebp` / `inc ecx / jne`.
   Two 8-bit images are concatenated by writing `al` and `ah`; the LUT (v*pal[i]/64, `0x15168`) does the colourisation *and* the multiplication, no arithmetic at all.
2. **Float compare as integer** - `0x1b533`: `1b656: cmp dword [ebp-8],0x437f0000 / jle` clamps a float to 255.0 by comparing its IEEE bits (0x437f0000 = 255.0) as a signed int: valid for any float (positive ordering = integer ordering), no FPU compare / `fnstsw`.
3. **Polar warp of every vertex** - `0x20b94 / 0x20a10`: `fpatan` twice gives azimuth `atan2(y,x)` and polar angle `atan2(sqrt(x²+y²), z)`, the radius is modified, then x,y,z are rebuilt with `fsin/fcos`
   (`20cc7: fld [esp+0x3c] / fsin / fmul [esp+0x40]` ... `20cd5: fcos` ...). The ripple factor is a product of three sines of linear coordinates: a cheap 3D standing wave.
   The black-hole radius map `sqrt(r²+200000)-200` is ~r far away but ~0 inside (|r|<<447): points near the centre collapse onto it, a smooth singularity.
4. **Lattice generated with float loops** - `0x1bf97`: `for (z=-n*s/2; z< n*s/2; z+=s)` with the loop bounds recomputed through `fild/fmul/fcomp` each iteration; edge lists use index arithmetic `k*nx*ny + j*nx + i`.
5. **Radial blur as a running sum** (`0x1743b`, see PORT_2d #2) with the 2^6 window applied to the 512-ray path list built by `0x14d0b`: the glowing star-burst at the lattice centre.
6. **Shared time base** - `fcos/fsin` chains `sin(cos(a t)+b t)` give pseudo-random but smooth Lissajous paths for rotation angles and the swirl/singularity centres, all from one float `DAT_00040310`.

## Status / known deviations
* Verified: 5 helpers bit-exact (Unicorn). Whole frames compared by eye with the reference video: structure, motion style and colours (after R/B swap) match.
* Not verified pixel-for-pixel: full frames (engine pieces were validated in PORT_2d/3d). Original reads a few words beyond the 0x17800-entry ray list for the radial blur (neighbouring heap); JS pads with 0.
* `time` base is taken at the first frame of the scene (the original's `DAT_00040314 = ticks*0.25` at scene start), so the first frame is t=0.
