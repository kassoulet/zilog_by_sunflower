# Port notes: the 3D engine core ("mobutil.c" 3dlib)

JS: `site/js/lib/mesh3d.js` (mesh, transforms, dispatcher) and `site/js/lib/mesh3d-raster.js` (clipper, polygon
scan converter + span loops, lines, sprites). Tests: `tools/test/3d_gen.py` (original under Unicorn -> vectors),
`tools/test/3d.test.mjs`, `tools/test/run_3d.sh`.

## Validation (differential, original under Unicorn)

`tools/test/run_3d.sh` (python `3d_gen.py` runs the ORIGINAL functions from `re/image.bin` on real MOB files / textures from the data container,
`3d.test.mjs` replays the same inputs through the JS port). 206 checks, all passing:

* `load`: 7 meshes (zilog1, hexp_on2, sph1024, cyl, cones3, cub_tun2, 3b_2): counts, vertex->face lists, edge->faces identical.
* `xform`: rotate (modes 9 and in-place 0), faceNormals, vertexNormals, rotateNormals, project, with and without vertex mask: **bit identical** floats.
* `render`: 95 cases, every (mode, sub) used by main() (0/0, 1/0, 2/0, 4/0, 4/4, 5/3, 6/0, 6/5, 7, 8, 9/0, 9/3) plus 1/1, 3/0, 4/2 and
  close-up variants where polygons, lines and sprites are clipped by the screen border. Whole 320x200 buffer compared (real background image or noise):
  `[inj]` = JS starts from the original's own projected arrays (isolates the rasterizers), `[full]` = JS runs the whole pipeline.
  Both are **pixel exact** (0 differing pixels) and the face sort order (qsort ties included) is identical.
* Vector generation takes ~5 min; `tools/out/3d_vectors.json` (53 MB) is the cached output.

**Harness warning (affects every float-heavy differential test):** Unicorn starts with x87 control word 0 = *24 bit precision control* and exceptions
unmasked; the real program runs with `fninit` (0x37f, 64 bit mantissa). With CW=0 each x87 intermediate is rounded to float32 and e.g. the sort key
`trunc((z0+z1+z2)*100)` differs by 1 for some faces (58721 vs 58722). `3d_gen.py` runs `fldcw 0x37f` once after creating the `Orig()`
(`fpu_init`); `re/harness/orig.py` should do the same.

## Function map

| original | JS | what |
|---|---|---|
| 0x16478 | `loadMesh(bytes)` | MOB loader: `PNTS` (x,y,z floats), `FACE` (3 u32), `EDGE` (2 u32) chunks -> 0x54-byte mesh struct |
| 0x160a9 | inside `loadMesh` (`vf`, `vfIdx`) | vertex -> faces lists, -1 terminated, built by *prepending* (faces of a vertex come out in decreasing order) |
| 0x162e7 | inside `loadMesh` (`edgeFaces`) | for each edge the first two faces common to both end points (0,0 if none) |
| 0x17e5e | `rotate(obj, ax, ay, az)` | euler rotation of `pts` -> `xpts`; **source is `xpts` itself (cumulative, in place) when `obj.mode` is 0 or 2**, else `pts`; honours the vertex mask |
| 0x18144 | `rotateNormals(mesh, ax, ay, az)` | same rotation for `nrm` -> `xnrm` (takes the *mesh*, not the object) |
| 0x1841d | `faceNormals(obj)` | unnormalised cross product per face; source `xpts` for mode 0/2, otherwise the *source* `pts` (object space) |
| 0x185d4 | `vertexNormals(mesh)` | normalised sum of the adjacent face normals (needs `vf`) |
| 0x1870b | `project(obj)` | `invz = 1/(z/focal + dist)`, `x' = x*invz + cx`, `y' = cy + (y*invz)*0.83` (double constant) -> `p2d`, `invz` |
| 0x189a5 | `faceAreas(mesh)` | trunc((x0-x1)(y2-y1) - (x2-x1)(y0-y1)) of the projected face; **< 0 = front facing** |
| 0x18ab4 | `sortFaces(mesh)` | front facing faces, key = trunc((z0+z1+z2)*100) of `xpts`, sorted *descending* (far first) |
| 0x25f04 / 0x25f13 | `qsort` (private) | the demo's own Hoare quicksort with payload swap, descending, not stable. Ported literally so equal keys keep the same order |
| 0x18beb | `render(obj, ctx)` | dispatcher, modes 0..9 (below) |
| 0x25f70 | `outcode()` | 4-bit clip code (y<0, y>200, x<0, x>320) |
| 0x2ad90 / 0x2b634 / 0x2b1c8 | `clipPoly(L, na)` | Sutherland-Hodgman against x=0, x=320, y=0, y=200 (in that order) for vertices with 2 / 1 / 4 interpolated attributes |
| 0x25fc0 | `tri_25fc0` | affine textured triangle (x,y,u,v) -> setup, clip, `fillPoly` + `spanTex` (asm 0x2bbec, edge steppers 0x2b9c0/0x2ba8c) |
| 0x26308 | `tri_26308` | same, but 50% blended with the screen (asm 0x2be3c) |
| 0x26b90 | `tri_26b90` | (x,y,u): 1-D lookup `tex[u]` (asm 0x2c7ec, steppers 0x2c600/0x2c6cc, clipper 0x2b634) |
| 0x266a0 | `tri_266a0` | (x,y,eu,ev,tu,tv): env map texel + surface texel, added (asm 0x2c35c, span 0x2f2b4, steppers 0x2c0a0/0x2c16c, clipper 0x2b1c8) |
| 0x26e28 | `tri_26e28` | (x,y,u,v) addressing a texture with an arbitrary pitch (0x140): screen-space warp (asm 0x2cc2c, steppers 0x2ca00/0x2cacc) |
| 0x21b70 (+0x21d1c) | `line_21b70` | clipped AA line, constant grey colour, "screen" blend |
| 0x21f3b (+0x221fc) | `line_21f3b` | clipped AA line, colour ramp c0 -> c1 (both 0..255), screen blend |
| 0x22463 (+0x2271c) | `line_22463` | same, but multiplicative (darkening) blend |
| 0x1efbc | `sprite_1efbc` | additive point sprite (256x256 byte intensity table scaled onto a (2r)x(2r) box, saturating per byte) |
| 0x1febc | `sprite_1febc` | coloured version: adds `(colourByte * t) >> 8` |
| 0x14834 | `makeLuts()` | the two 64K tables DAT_000402f4/f8 used by the line drawers |
| 0x1c48f | (typed array `set`/`slice`) | memcpy, no JS function needed |

`render()` modes (`obj.mode` = byte +0x1c, `obj.sub` = byte +0x1d). "Used by main" = set by the scenes in re/decomp/100d3.c.

| mode | draws | sub | main uses (mode/sub) |
|---|---|---|---|
| 0 / 1 | faces, env mapped from vertex normals (`nrm` for 0, `xnrm` for 1): u=nx*127+127, v=ny*127+127 | 0: `tri_25fc0`, 1: `tri_26b90` (ramp), else nothing | 0/0, 1/0 |
| 2 / 3 | faces, env map + surface texture (`uv`), additive (`tri_266a0`); texture block = 2 textures | ignored | 2/0 |
| 4 | faces with `uv` as texture coords | 2: blended `tri_26308`, 4: `tri_26e28` with pitch 0x140, else `tri_25fc0` | 4/4, 4/0 |
| 5 | contour/silhouette edges (one adjacent face front, one back), colour 255 (`line_21b70`) | - | 5/3 |
| 6 | the same edges, colour = `uv[v].x` of both end points (`line_21f3b`) | 5: darkening `line_22463` | 6/5, 6/0 |
| 7 | all edges, 255 | - | 7 |
| 8 | all edges, colours from `uv[v].x` (`line_21f3b`) | - | 8 |
| 9 | point sprite per vertex, radius = invz*26 px (only when > 1) | 3: coloured from `obj.colors[i]` (`sprite_1febc`) else `sprite_1efbc` | 9/0, 9/3, 9/6 |

## Structs

### Mesh (0x54 bytes in the original; JS `Mesh` object, dword index -> field)

```
0x00 npts        0x01 pts*        0x02 xpts*       0x03 mask* (byte/vertex, NULL = all)   0x04 nrm*   0x05 xnrm*
0x06 nfaces      0x07 faces*      0x08 fnrm*       0x09 sort keys*  0x0a sorted face idx*  0x0b nvisible faces
0x0c vf list*    0x0d vfIdx*      0x0e edgeFaces*  0x0f nedges      0x10 edges*   0x11 p2d* (x,y float)
0x12 uv*  (byte +0x48, 2 floats / vertex, filled by *scene code*: texture coords or colour byte)
0x13 area* (byte +0x4c, int per face)   0x14 invz* (byte +0x50, float / vertex)
```
`xnrm`, `nrm`, `fnrm`, `key`, `order`, `invz` are allocated lazily by the function that fills them. Scenes also poke `npts`
(first dword) to reveal points progressively (`*mesh = n` before a mode-9 render) and set `mask` for per-point enable.

### Object instance (stack struct in main, passed as `&obj`; JS `Obj3D`)

```
+0x00 mesh*   +0x04 cx (float)   +0x08 cy   +0x0c dist   +0x10 focal   +0x14 texture*   +0x18 (unused)
+0x1c mode (byte)   +0x1d sub (byte)             (struct is 0x20 bytes; main keeps 3 of them on the stack)
```
`texture` is: a 256x256 dword table (modes 0,1,4) / a block of two 256x256 dword tables 0x40000 bytes apart
(modes 2,3: env map first, surface texture second; JS: one `Uint32Array(131072)`) / any dword image with 320 pixel pitch
(mode 4 sub 4, the demo passes a copy of the screen) / a 256x256 *byte* intensity table (mode 9). Mode 9 sub 3 reads colour dwords from
the global `DAT_00040308` (JS: `obj.colors`).

### Calling sequence used by the scenes (re/decomp/100d3.c)

```
rotate(obj, ax, ay, az)                       // 17e5e   (mode byte decides the source, see above)
[rotateNormals(mesh, ax, ay, az)]             // 18144
[faceNormals(obj); vertexNormals(mesh)]       // 1841d / 185d4  (once, for env mapped objects)
project(obj)                                  // 1870b
obj.mode = 5; render(obj, ctx)                // 18beb   (a scene often renders the same object twice with different modes)
```
`ctx = makeRenderContext(target)`: `target` (DAT_00040304[2]) polygons and sprites draw to it (320 px pitch), `screen` (DAT_000402f0, the buffer
the line drawers use, normally the same array), `lut1/lut2` (DAT_000402f4/f8).

## Interesting inner loops (for the explainer)

1. **Texture span with the loop counter hidden in the fractional register** (0x2bbec, `tex1` 8.16 fixed point).
   The 16-bit fractional part of u lives in the high half of `ecx`, the pixel count in `cx`; the carry of the fractional
   add is folded into the integer coordinate with `adc`. u and v are 8-bit integers in `bl`/`bh`, so they wrap at 256 texels
   for free and `[ebx*4]` is the texel address (texture base in the high half of `ebx`, hence 256 KB aligned textures).
   ```
   2bd35: rol ecx, 0x10 / 2bd38: mov cx, ax / 2bd3b: rol ecx, 0x10   ; ecx = (u_frac<<16) | count
   2bd44: mov bl, al / 2bd46: mov bh, dl                              ; bl=u int, bh=v int
   2bd66: mov eax, dword ptr [ebx*4]                                  ; texel = tex[v<<8|u]
   2bd6f: adc bh, dh  (after add edx, ebp)                            ; v frac carry -> v
   2bd73: adc bl, dl  (after add ecx, esi)                            ; u frac carry -> u, count in cx untouched
   2bd77: add edi, 4 / 2bd7a: dec cx / 2bd7c: jne 0x2bd66
   ```
2. **Self-modifying env+texture span** (0x2f2b4, used by 0x266a0): four 8.16 coordinates (env u,v and texture u,v) with four
   different gradients. The gradient immediates are *patched into the loop* before it runs (`mov byte ptr [0x2f35c], al` ...),
   so the loop is just two loads, one add and four add/adc pairs. The second texture is addressed as `(T+0x10000)*4`, i.e.
   exactly 256 KB behind the first. Result pixel = plain 32 bit `add` of two texels (no saturation).
   ```
   2f341: mov eax, dword ptr [ebx*4]        2f348: add eax, dword ptr [edx*4]     2f34f: mov dword ptr [edi], eax
   2f354: add ecx, 0x11111111 / adc bl, 0x11    2f35d: add ebp, 0x11111111 / adc bh, 0x11   (0x11.. = patched)
   2f366: add esi, 0x11111111 / adc dl, 0x11    2f36f: add bp, 0x1111 / adc dh, 0x11
   2f377: dec cx / 2f379: jne 0x2f341
   ```
3. **Free 50% blend** (0x2be3c): average of texel and destination per channel with `add`+`rcr` (the carry out of the byte add is rotated back in):
   `2bfbd: add al, byte ptr [edi] / 2bfbf: rcr al, 1 / 2bfc1: add ah, byte ptr [edi+1] / 2bfc4: rcr ah, 1 / 2bfc6: ror eax, 8 / 2bfc9: add ah, byte ptr [edi+2] / 2bfcc: rcr ah, 1`.
4. **Linear addressing with a two-way step table** (0x2cc2c, screen-space warp): the texel address is a single dword index; the carry of
   the v fraction selects between `step` and `step+pitch` through a 2-entry table, the carry of the u fraction is absorbed by `adc`:
   `2cdd4: add ebx, [0x41430] / 2cdda: sbb ebp, ebp ... 2cde5: add ecx, edx / 2cde7: adc esi, dword ptr [ebp*4 + 0x41438]`
   (`[0x41438]` = du_int + dv_int*pitch, `[0x41434]` = that + pitch).
5. **Anti-aliased line through a 64K lookup table** (0x21d1c): two pixels per step, weights `(0xffff-frac)>>8` and `frac>>8`. `I = W*C>>8` and the
   screen blend `1-(1-I)(1-D)` are *table lookups*: `lut1[a<<8|b] = 255-((255-a)(255-b)>>8)` is indexed with the colour in `ax` (low word of the
   register whose high word holds the table pointer, hence 64 KB alignment):
   `21e3d: not ax / 21e40: mov ah, byte ptr [eax] / 21e42: not ah / 21e44: mov al, dl / 21e46: mov dl, byte ptr [eax] / 21e48: mov al, dh / 21e4a: mov dh, byte ptr [eax] / 21e4c: ror edx, 8 ...`
   The `0x2271c` variant works on the inverted pixel (`not edx`) with the second table: a multiplicative shadow line.
6. **Point sprites** (0x1efbc/0x1febc): one 256x256 byte table scaled onto a (2r)x(2r) box with 8.8 fixed point and the same `adc` coordinate trick
   (`1f0de: mov dh, byte ptr [ebx]`, `1f101: add eax, ebp / 1f103: adc bl, dl`), the pixel is a per-byte saturating add
   (`1f0e6: add cl, dh / 1f0e8: jae / 1f0ea: mov cl, 0xff`, bswap to reach the 3rd byte). The coloured version patches the three
   colour bytes into the loop and uses `lut2` to compute `colour*t>>8`.
7. **Winograd-style rotation** (0x17e5e): rows of the matrix and the products `m0*m1` of each row are precomputed once; each output coordinate needs
   one multiply for `(m0 + y)*(m1 + x)` and one for `z*m2` instead of three (`x'=(m0+y)(m1+x)+z*m2-(m0*m1+x*y)`; `x*y` is shared by the 3 rows):
   `17fc9: fld [ebp-0x68] / fmul [ebp-0x64] / fstp [ebp-0x6c]` (x*y once), then per coordinate `17fd2: fld [ebp-0x50] / fadd [ebp-0x64] / fld [ebp-0x4c] / fadd [ebp-0x68] / fmulp / fld [ebp-0x60] / fmul [ebp-0x48] / faddp / fld [ebp-0x2c] / fadd [ebp-0x6c] / fsubp`.
8. **Edge stepper special case** for 1-scanline edges (0x2ba62): instead of an `idiv` per attribute it computes one reciprocal
   `0x40000000/dy` and scales every delta with `imul`+`shrd 14`. Beware: for tiny dy this overflows exactly like the original (ported literally, with 64-bit intermediates).
9. **Painter's algorithm quicksort** (0x25f13): descending Hoare partition, sorts keys and payload together:
   `25f21: cmp eax,[ebp+ebx*4] / jge / inc ebx` ... `25f3c: xchg [ebp+esi*4], eax` + the same swap on the index array.

## Uncertain points / deviations

* **x87 precision**: the original keeps intermediates in 80 bit registers and rounds to float32 only on `fstp dword`; JS uses doubles and `Math.fround`
  at the same stores. On the test vectors loader, rotation, normals, projection **and every rendered pixel are bit identical** (see Validation).
  In principle the gradient setup (`setup()` in mesh3d-raster.js: `fistp` of `(..)*(65536/det)`) can differ in the last unit for a near-tie.
  The scene code will call `Math.sin/cos` through `rotate()`: results are rounded to float32 so engine differences in the last double ulp almost never show.
* **Vertex record order** in the dispatcher: the decompiler's names hide that the three vertices are stored in memory as (v0, v2, v1); the filler
  needs this winding (front facing = negative screen area). Ported as such.
* `fistp` rounds to nearest-even (used for 16.16 conversions) while `ftrunc` truncates (used for `+0x4c` area, sort keys, line/sprite coordinates):
  `rne()` and `trunc32()`; out of range -> 0x80000000 like the FPU.
* **Out of bounds texture reads** (mode 4 sub 4 with uv outside the 320x200 source, or any non wrapping addressing): the original reads neighbouring heap memory,
  JS reads `undefined` -> 0. Not reproducible, not used meaningfully by the scenes.
* **Texture alignment**: the original needs 256 KB aligned texture blocks (texture pointer lives in the high half of a register); the JS API takes plain typed arrays.
* `0x21f3b`/`0x22463` with `c0 == c1 == 0` draw nothing (`or ax,ax; je`); the colour interpolation drops the fraction at clip points (`al = int byte` is re-read before 0x221fc).
* The line drawers use the clip window [1,318]x[1,198] (initialised data at 0x3ee64..0x3ee70) and draw into DAT_000402f0, not into the 0x40304 target.
* Faces with `det == 0` (degenerate on screen) are skipped by the triangle setup, as in the original.
* `+0x18` of the object struct is never read by the engine (unknown/padding).
* Mode 5/6 silhouette test uses `<= 0 / >= 0` on the integer areas, so exactly edge-on faces (area 0) count as both front and back.
* Not ported (not part of this task, but called around the engine by scenes): 0x1a21b/0x1a7df/0x19f57/0x1ac25/0x1aa02 (effects on projected points), 0x1b* (uv generators that fill `uv`), 0x20b94 etc.
