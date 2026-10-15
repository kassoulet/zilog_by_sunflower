# Scenes 2 and 3 (main loops `while (order < 19)` and `while (order < 23)`)

JS: `site/js/scenes/scene2.js`, `scene3.js`, helpers `_g2fx.js`. Tests: `tools/test/run_g2.sh` (`g2_gen.py` runs the ORIGINAL under Unicorn, `g2.test.mjs` compares; ~5 min to regenerate, vectors in `tools/out/g2_vectors.json`).
Representative frames: `site/img/scene2.png`, `scene3.png`. Both scenes were compared with the reference video (R/B swapped): structure, motion style and colours match.

## Scene 2 (orders 14..18, 48.5-67.5 s): "spiky chrome star in a bubble field"

What the viewer sees: a bright purple/green blurred photo (`fullpics/spot.gfx`, the light-burst) with 3D on top: a large environment-mapped
organic blob (`3d/b2.mob`, env map = `textures/max_t2.gfx`, shows as dark blue chrome; orange-gold in the R/B swapped video) that is wobbling radially so
violently it looks like a spiky star, moving on a Lissajous path (cx = 160 +-50, cy = 100 +-50). Around it 1024 dark glossy bubbles (`3d/sph1024.mob`, rotating
sphere, every vertex drawn as a *subtractive* soft blob from the radial cosine spot), a ring wireframe (5 concentric 26-gons, 800 units max radius, also wobbled
and perspective projected, drawn as anti-aliased "screen" lines), a 70 px additive light sprite in the centre and a crosshair of four lines (255 at the centre,
fading to 0 at the screen border, drawn with the unclipped `0x221fc`). Sync marker 1 flashes `smalpics/jp09.gfx` (additive blit). The scene starts with a
fade-in from black through `fullpics/mask2.gfx` (threshold `DAT_0004032c` = -32 + dt per frame, until 260).

Layering = painter's order around the z = 0 plane: far sphere blobs (z > 0) -> far faces of the blob (sort key > 0) -> light sprite -> ring wireframe -> crosshair ->
near faces (key < 0) -> near blobs (z < 0). Everything is drawn into the screen after `blitCopy(spot.gfx)`; no post effect.

Per frame (`t` = `DAT_00040310`): ax = 3 sin(cos(.008t)+.009t), ay = 3 sin(cos(.007t)+.018t), az = 3 sin(cos(.006t)+.017t);
blob: `206e0` (wobble pts->xpts) -> `rotate` in place (mode 0 = cumulative source xpts) -> face normals -> vertex normals; sphere: rotate from pts (so the wobble that the
original also applies to the sphere is overwritten: dead work reproduced as nothing); rings: wobble then project only.
Objects: blob {cx,cy animated, dist 6, focal 140, tex max_t2, mode 0/0}, sphere {dist 6, focal 100, tex = spot table, mode 9/6}, rings {dist 6, focal 100, mode 7}.

## Scene 3 (orders 19..22, 67.5-81.4 s): "refracted pipes + chrome gadget"

What the viewer sees: full screen warm/teal metallic pipes (`textures/pipesd.gfx`) with moving light streaks (`lites2.gfx` pushed through a bump displacement
map made from `pip_h.gfx`), refracted by a 40x25 grid warp driven by three moving "lenses" (the picture swirls and stretches). On the right a 15x22 raster of dark
dots (`textures/zilog2.gfx` 20x128 bytes scrolled by `t`, each non-0xff byte = a subtractive dot sprite, wobbling) and on the left a brown metal blob with tentacles
(`3d/kph2.mob`, env map `textures/env1.gfx`, deformed by `20b94`) drawn twice: shaded env-mapped faces (mode 0) and darkening silhouette lines (mode 6/5) whose
per-vertex intensity comes from `1b446` (product of three sines). Music sync: `sync & 15` -> additive flash of `smalpics/jp01,02,03,05,08,10,11,13` (index `sync & 7`);
`sync & 16` -> a colour-matrix (YCbCr-like) rectangle that jitters around (order*10 .. order*10+60, 100..160). From order 21 a per-scanline horizontal box blur fades in
(radius = (28 - 35 cos(pi y/100)) * blend * (.5+.5 sin(.09t - sin(.12t))), blend += .01*dt up to 1): the screen smears into horizontal streaks at the end.

## Function map orig -> JS

| orig | JS | notes |
|---|---|---|
| 0x1bdb0 | `ringMesh(26,5,800)` | ring mesh struct (pts, edges only), bit exact |
| 0x206e0 | `wobbleMesh(mesh,t)` | pts -> xpts spherical radial wobble r' = r + 140 sin(cos(B r - e) + A r + d); bit exact |
| 0x20b94 | `sineBlobMesh(mesh,t,R)` | r' = r + R sin(ax+d) sin(by+e) sin(cz+g); bit exact |
| 0x1b446 | `waveColours(mesh,t,k)` | uv[i].x colour bytes for mode 6 lines |
| 0x1ce90 | `lensNodes(nodes,t)` | 41x26 node table (u,v,0), three lenses; +-1 LSB differences (x87 extended) |
| 0x1a7df / 0x1aa02 | `renderFacesHalf(obj,ctx,+1/-1)` | mode-0 faces with key > 0 / key < 0; pixel exact |
| 0x1a21b / 0x1a5ea | `spritesHalf(obj,ctx,17,far)` | mode 9/6 points with z > 0 / z < 0 (1a5ea skips z >= 0); pixel exact |
| 0x1efbc, 0x18beb, 0x21f3b (for 0x221fc), 0x1c4b4/1c4f6/1ec58 | lib (`sprite_1efbc`, `render`, `line_21f3b`, `blitCopy/blitAdd/maskFadeToBlack`) | `0x221fc` = the unclipped line core; `line_21f3b` clips to [1,318]x[1,198], differs only in the border columns |
| 0x22b43, 0x1d6a4, 0x1fab7, 0x22990, 0x16ffb, 0x14b3d | lib (`lightMapAdd`, `gridWarpTex32`, `spriteSubtractAlpha`, `colorMatrixRect`, `boxBlurHVar`, `bumpDisplacementMap`) | |
| 0x17846 (key poll) / 0x17c11 (flip) / 0x10061 | host | |

Test status (`tools/test/run_g2.sh`): ring, wobble, sineBlob (5 time values x 4 meshes), uv: bit identical; lens: 22386 values, 71% identical, rest +-1; far/near faces
(4+4 cases) and sphere sprites (3+3) pixel exact given the same projected arrays.

## Inner loops worth showing

1. **Spherical-coordinate wobble with `fpatan`** (0x206e0): every vertex is converted to (phi, theta, r) with two `fpatan`, r is modulated and converted back.
   ```
   20775: fld [esp+4] / 2077c: fld [esp] / 20783: fpatan          ; phi = atan2(y, x)
   2078e..2079c: x*x + y*y, fsqrt / 2079e: fld [esp+8] / 207a2: fpatan ; theta = atan2(sqrt(x^2+y^2), z)
   207eb: fcos / 207ed: fadd / 207f1: fsin / 207f3: fmul 140.0 / 207f9: fadd r   ; r' = r + 140 sin(cos(B r - e) + A r + d)
   20813: fmul / 2081d: fmul cos(phi) / 20821: fstp [edx]          ; x = cos(phi) sin(theta) r'
   ```
   Only 4 time constants per frame (sines hoisted out of the loop), per vertex 2 fpatan + 2 sqrt + 3 sin/cos + 5 for the back conversion: the wobble is a function of the
   radius only, so it looks like shock waves running through the shape. In scene 2 the same code also bends the flat ring mesh into a bowl-like shape.
2. **Free front/back split with the sort keys** (0x1a7df vs 0x1aa02, identical except one opcode): the painter's-algorithm key `trunc((z0+z1+z2)*100)` is
   sorted far to near, so one `cmp dword ptr [eax], 0 / jle` (`1a8a9`/`1a8ac`) vs `jge` (`1aacf`) selects the half behind / in front of z = 0 and lets the scene
   interleave other draws (light sprite, wireframe, lines) *between* the two halves of the same mesh and the same sphere (0x1a21b `fldz / fcomp [z] / jae` vs 0x1a5ea `jbe`):
   fake depth interleaving without a z-buffer.
3. **Three-lens refraction field** (0x1ce90): per node `H = 1/(.001(a^2 w1 + b^2 w2)+.2) - 1/(..)_2 - 1/(..)_3` (three moving anisotropic Lorentzian bumps), the rotated
   coordinates are scaled by H and stored as 8.16 texture coordinates: `1d1a2: fld [esp+0x70] / fmul 196608.0 / fistp / and eax, 0xffffff`
   (`196608 = 3 * 65536`: a texture shift of up to 3 texels per unit field), so the 41x26 table feeds the carry-chained grid warp (0x1d6a4, see PORT_2d.md).
   The 1/x blobs of the three lenses are summed with alternating sign (`1d182: fsub / 1d186: fsubrp`), which creates the characteristic swirl.
4. **Pipe texture lit by a displaced light map** (scene 3 `22b43`): `22b5e: mov bp,[ecx*2+X] / add bp,dx / mov bl,[ebp+Y]`: the bump map (from `pip_h`) gives, for every texel,
   where to read a 256x256 light texture; the 16 bit add of `dx` (= `120 cos(.074 t) << 8 + 120 sin(.061 t)`) wraps around both axes at once, so scrolling the light
   map by one number makes the highlights slide over the pipes *as if refracted by the relief*.
5. **Wireframe ring field from 7 lines of arithmetic** (0x1bdb0): 5 rings x 26 points, radii R/5 .. R (`fdivr`), edges `(j*26+i, j*26+(i+1) % 26)`; the ring mesh is a legitimate
   MOB-like struct so the whole mesh pipeline (wobble, project, mode 7 edges) is reused. 0x206e0 then lifts the flat rings to waves.
6. **Four-line crosshair with a colour ramp** (`0x11683..0x1185a`): the unclipped line routine 0x221fc takes colours in `al`/`ah` and 16.16 endpoints in `ebx,ecx,esi,edi`;
   `mov eax, 0xff00` = ramp 0 -> 255 along the line, `mov eax, 0xff` = 255 -> 0: lines that glow at the burst centre and fade to the borders.
