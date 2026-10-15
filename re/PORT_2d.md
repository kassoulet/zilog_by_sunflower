# PORT_2d: 2D / post-processing / table generation library (`site/js/lib/fx2d*.js`)

Files: `fx2d.js` (re-exports all) = `fx2d-tables.js`, `fx2d-blur.js`, `fx2d-text.js`, `fx2d-blit.js`, `fx2d-mesh.js`, `fx2d-warp.js`, `fx2d-video.js`.
Every function has `f_<addr>` aliases and a JSDoc with the original address.  Screens are `Uint32Array(64000)` (dword = bytes B,G,R,x),
tables are `Uint8Array(65536)` etc.  No globals: DAT_000402f4/402f8 (blend tables), screen pointer, font etc. are explicit arguments.

Validation: `tools/test/run_fx2d.sh` (`--regen` to rebuild vectors, ~1 min). `tools/test/fx2d_gen.py` runs the ORIGINAL functions under
Unicorn (re/harness/orig.py) on real data (GFX from raw/, real tables made by the original table builders) and random data and dumps
inputs+outputs; `fx2d.test.mjs` runs the JS port and compares byte for byte. **212 vectors + 4 flip-converter streams, all identical.**
Harness notes (needed to reproduce): the stock harness starts with x87 CW=0 (24-bit precision!) - set `FPCW=0x37f` (a DOS program runs with
64-bit precision), and Unicorn has no usable ES (`mov es,eax`) so strlen 0x24cd6 / memcpy 0x1c48f are hooked in `fx2d_gen.py`
(its `Orig` subclass also installs code hooks only on the few intercepted addresses: ~20x faster than the stock per-instruction hook).

## Colour channel order / presentation (open question answered)

* A screen dword is `0x00RRGGBB`: **byte0 = blue, byte1 = green, byte2 = red**. Evidence in the code: the converters (below) and the palette LUT
  builder func_15168 (`dst byte0 <- pal[idx*3+2]`, i.e. byte0 takes the *third* (B) component of the R,G,B palette entry), `func_22990` etc.
* The flip (func_17c11) copies the buffer 1:1 to a VESA 32bpp framebuffer (LFB: `0x1c48f` memcpy of 0x3e800 bytes; banked: 0x254ba;
  24bpp 0x257bb writes bytes 0,1,2 of each dword; 16bpp 0x25649 = RGB565 `b0>>3 | (b1>>2)<<5 | (b2>>3)<<11`; 15bpp 0x2570c = RGB555).
  VESA 24/32bpp memory order is B,G,R(,x) and 565 has blue in the low bits, so the display shows **R = byte2, G = byte1, B = byte0**.
  `presentToRGBA(scr, rgba, 32)` does exactly that (alpha forced to 255); 16/15bpp variants quantise like the converters and expand 5/6 bit with
  `c<<3|c>>2` (DOSBox's own expansion is not verified; irrelevant for the 32bpp path the demo takes in DOSBox, ref frames have all 256 levels).
* Why the reference capture looks swapped: **the js-dos capture (`scratchpad/emu`) swaps R and B for every direct-colour VESA mode.**
  Verified with a 29-byte .COM in the same emulator: VBE mode 0x10F, dword `0x00FF0000` (R=0xff in B,G,R order) is reported as rgb=(0,0,255);
  mode 0x10E with word `0xF800` (pure red in 565) is reported as (0,0,248); VGA 13h palette entries are reported correctly.  So the ref video
  shows R<->B swapped relative to real DOSBox/hardware; a naive decode of GFX images with R=byte2 (e.g. `simulcra.gfx`: warm orange/gold tubes,
  "Sunflower's"!) is the correct appearance, and the video is the one to swap (`R=byte0`) when comparing colours.
  (Do NOT write the dword straight into a canvas `Uint32Array`: that gives R=byte0.)

## Function map

| orig | JS (file) | what it does |
|---|---|---|
| 0x14639 | `radialCosSpot` (tables) | 256x256 byte soft spot, 255*(0.5+0.5cos(r/40.4)), r clamped to 127, rows stretched x1.17 |
| 0x146f9 | `radialDiscMask` | 256x256 byte disc mask 0xff inside r<120 (same distance), else 0 |
| 0x14834 | `screenBlendTables` | the two 64K blend tables DAT_402f4 `T[a<<8\|b]=255-((255-a)(255-b)>>8)` ("screen") and DAT_402f8 = ~T |
| 0x148c4 | `colorMatrixTables` | 9x256 int32 (8.24) tables for a 3x3 YCbCr-like colour matrix; products can overflow int32 -> 0x80000000 like `fistp` |
| 0x14b3d | `bumpDisplacementMap` | 256x256 height field -> u16 (y+dh/dy)<<8\|(x+dh/dx) refraction/bump displacement map, central differences, wrapping |
| 0x14c51 | `cosCosPlasma` | 256x256 byte 16+56(1+cos)(1+cos) "egg box" |
| 0x14d0b | `radialRayTables` | 512 rays x 188 steps of screen offsets (160+r sin, 100+r cos) clamped; marks them in a 320x200 mask; list of (lit neighbour -> empty pixel) pairs to fill the holes; returns count. Needs x87 extended accumulation for `r*cos+100` (see `truncSum`) |
| 0x15168 | `paletteShadeLut` | 256x256 dword LUT `v*pal[idx]/64` per channel from pal.sc (file+10, 768 bytes, 6-bit RGB) |
| 0x1478a / 0x147df | `halveDwords` / `invertDwords` | `(d>>1)&0x7f7f7f` / `~d&0xffffff` over 65536 dwords |
| 0x14f53 | `colourRampLut` | 256x256 dword LUT: three channel gains depending on idx (blue->green->red ramp), `v*gain` |
| 0x16b44/0x16c93 | `divTable` (reference) | division tables T_w[s]=floor(s/w) (v repeated w times) - not needed in JS, `s/r\|0` |
| 0x16cdd | `boxBlurH` | horizontal box blur 320x200, radius r (>=3), zero padded, always divided by r |
| 0x16e53 | `boxBlurV` | vertical version (stride 0x500) |
| 0x16ffb | `boxBlurHVar` | per-scanline radius from a 200 dword array (r<3: copy, r clamped to 63) |
| 0x1743b | `radialPathBlur` | running-sum blur along a path of offsets (the ray table): `out[path[k]] = avg of src over path[k..k+2^n-1]`, then fill holes with the pairs |
| 0x174fe | `buildFont` | font object from an 8-bit strip: glyph boundary = all-zero pixel column |
| 0x17641 | `printText` | text printer with control codes (see JSDoc), no clipping |
| 0x24cf0 / 0x24d79 | `glyphBlend` / `glyphDarken` | glyph blitters: coverage = table[(~alpha)<<8\|~g], screen blend (24cf0) or darkening with the inverted table (24d79) |
| 0x17e46/0x25e60, 0x1c48f | `memset`, `memcpy` | trivial |
| 0x1c34e | `projectedBBox` | screen bbox (floats, clamped to 0..319 / 0..199) of projected points -> DAT_40358..64 |
| 0x1c4b4 | `blitCopy` | copy a full screen GFX (RLE: skips write 0) |
| 0x1c4f6 / 0x1c7a6 / 0x1c91e | `blitAdd` / `blitDifference` / `blitLighten` | GFX blit (32bpp, 32bpp RLE, 8bpp grey, 8bpp RLE) with saturated add / \|s-d\| / max per channel |
| 0x1ec58 | `maskFadeToBlack` | wipe: `k=mask-thr`; k<=0 keep, k>31 black, else darken by 8k/256 through the inverse blend table |
| 0x1ecaa | `maskWipeCrossfade` | wipe from the screen to a second image, 31-step cross-fade band driven by an 8-bit mask |
| 0x1ee44 | `alphaMaskCrossfade` | per pixel alpha cross-fade of two images, alpha = 8-bit map |
| 0x1eeb4 | `maskInvert` | partial colour inversion by an 8-bit map (255 = full invert) |
| 0x22990 | `colorMatrixRect` | apply the 0x148c4 tables on a rectangle (3x3 matrix, `>>24`, `+0x70`, no clamp); y0 clamped at 319 (original quirk) |
| 0x22b43 | `lightMapAdd` | `dst = satadd(src, lightmap[(disp[i]+dx)&0xffff])`, 65536 pixels |
| 0x22b9c | `lutLookup2D` | `dst[i] = lut[(hi[i]<<8)\|lo[i]]` (e.g. the 0x15168 LUT) |
| 0x22c39 / 0x22e0e | `warpMeshA` / `warpMeshB` (mesh) | animated 41x26 node table (angle, 0, brightness; 8.16) for the polar swirl warp; A cross-fades with `mix` |
| 0x1d6a4 | `gridWarpTex32` (warp) | 40x25 cells of 8x8, bilinear (u,v,shade) from the mesh, 32bpp texture, screen-blend shading |
| 0x1e266 | `gridWarpTex8` | same for 8bpp texture/screen, inverse blend table (page byte ignored) |
| 0x1e62e / 0x1e941 | `gridWarpStrip8` / `gridWarpStrip8Inv` | only u + shade (v=0 strip), tables 402f4 / 402f8 |
| 0x1f337 | `spriteSubtract` | scaled 256x256 mask sprite (24.8 position/radius) subtracted from the screen |
| 0x1f6b2 / 0x1fab7 | `spriteAddAlpha` / `spriteSubtractAlpha` | same with alpha through the blend table, add / subtract (alpha 255 = nothing) |
| 0x17c11 | `presentToRGBA`, `vesaFramebuffer`, `packRGB16`, `debugOverlayLines` | the flip; see colour section. Space-key debug overlay = 3 text calls |
| 0x254ba/0x257bb/0x25649/0x2570c | `vesaFramebuffer(scr,bpp)` | 32/24/16/15 bpp framebuffer bytes (verified against the real converters' VRAM write stream) |
| 0x15a48 | (core/gfx.js) | loader; for the blits note its in-memory result: flags&1 + 32bpp => RLE stream (u32 skip count / `count\|0x80000000` + dword literals / 0xffffffff); `jp*.gfx` (8bpp flags=1) are RLE streams *in the file* (`expandRle8`) |
| 0x23774 | not ported | C++ iostream (`ostream::operator<<`), not 2D |
| 0x1efbc / 0x1febc | not mine (3D core) | |

## Uncertain points / quirks reproduced

* x87: JS doubles reproduce the original bit-exactly on all tables (tested with CW=0x37f); the one place where double precision is NOT enough is the
  `trunc(r*cos+100)` of 0x14d0b (residue -1.8e-16 at 3pi/2) - handled by `truncSum` (exact residual). Other near-integer cases may exist in
  scene code (not in this library).  sin/cos: QEMU uses host double libm, real x87 is equally accurate; same results for these arguments.
* Blurs: radius must be >= 3 (r=1,2 make a `dec ecx` loop wrap 2^32 times, never used); in-place (src==dst) use is not reproducible (table underflow reads
  neighbouring tables for negative running sums); byte3 of a pixel is not blurred but taken from the last loaded pixel (kept).
* Division tables for w>=64 live in DAT_00016b38 (rebuilt per call when the width changes); JS needs no tables.
* 8bpp RLE (`jp*.gfx`) and 32bpp RLE are both expanded to a linear plain array: identical for the three operators because 0 is neutral for add/max/|diff|.
* `printText`/glyph blitters assume valid char codes (original reads garbage otherwise). Font table pointers must be 64 KB aligned in the original (the
  table base is used as a pointer whose low 16 bits are replaced by the two indices); in JS plain `tab[hi<<8|lo]`.
* Warp renderers rely on never-written memory words (DAT_0003edf0 ... = 0): the `mov ebx,[0x3edf2]` loads pick up 16 junk bits that must be 0.
  The 8bpp variants load the node page byte but overwrite it before use (no page support); the 32bpp variant needs a 256 KB aligned texture base.
* Sprites: with clipping the loop counts are forced to >= 2 (and rows <= 250) so a sprite touching the border writes 1-2 pixels outside the clip (kept,
  JS typed arrays just ignore writes beyond the buffer; linear dest index like the original).  `ecx=0` glyph width / radius 0 would hang or #DE.
* 16/15 bpp expansion to 8 bit (DOSBox side) is an assumption; 32bpp is exact.

## Interesting inner loops (for the explainer)

1. **Box blur: pointer as running sum, division by table lookup, self-modifying strides** - `func_16cdd`.
   Setup patches the code: `16ce0: sub edi,esi` / `16ce6: mov [0x16d84],edi` (dst-src distance into `mov [esi+0x11111111],ebx`), `16d33: mov [0x16dcf],edx`
   (window offsets into the sliding loads).  Each channel keeps a *pointer into the division table* in a register (`eax`,`edi`,`ebp` start at the table base,
   `16d53: mov eax,[0x16b40]`).  Sliding window (one pixel = 3 adds + 3 subs + 3 table reads):
   ```
   16dcd: mov ebx,[esi+0x11111111]   ; incoming pixel
   16dd3: mov dl,bl / add eax,edx    ; ptr0 += b0
   16dd7: mov dl,bh / add edi,edx    ; ptr1 += b1
   16ddb: shr ebx,8 / mov dl,bh / add ebp,edx   ; ptr2 += b2
   16de2: mov ebx,[esi+0x11111111]   ; outgoing pixel ... sub eax/edi/ebp
   16df7: mov bh,[ebp] / shl ebx,8 / mov bl,[eax] / mov bh,[edi]   ; 3 lookups = 3 divisions, repacked B,G,R
   ```
   The division table (func_16c93 `16ca8..16caf: rep stosb` with ecx=w, value 0..255) has each value repeated w times, so `[base+sum]` = sum/w.
   Vertical version 0x16e53 only changes strides (0x500) - another 8 patched immediates.
2. **Radial blur on a ray list** - `func_1743b`: `174a1: ror ax,6` (the `6` is patched at 0x174a4 from the argument: window = 2^n) / `174a8: mov [edi+X],al` then
   `rol ax,6` - the 16-bit running sum is rotated so that `al` is `sum>>n` (a free divide by 2^n), the result goes to the pixel offset read from the path list;
   `174bd/174c4` add the entering sample (list index +2^n via patched `[edx+0x174c0]`).  The 0x17800 path entries = 188 steps x 512 rays built by 0x14d0b.
3. **Grid warp with carry-chained fixed point** - `func_1d6a4`: three interpolators (u, v, shade) in 8.16 whose integer bytes are `bl`,`bh`,`ch` and whose
   fractions are the top 16 bits of `edx`,`ebp`,`esi`:
   ```
   1d866: mov eax,[ebx*4]            ; texel: ebx = (base>>2)|(v<<8)|u  - the index IS the address
   1d86d: add edx,0x11111111 / 1d875: adc bl,dl     ; u += step (frac in the immediate, carry -> integer byte)
   1d873: mov cl,al / 1d877: mov al,[ecx]           ; shading: ecx = table|shade<<8|texel_byte  (table pointer as base)
   1d8c5: add [0x1d86f],ebx / 1d8cb: adc dl,[0x3edf6]  ; per row: the step *immediates in the code* are updated (bilinear second derivative)
   ```
   Cell shortcuts at `1d82f` (`or al,al` over the 4 corner shade bytes -> plain copy, `cmp ah,0xff` -> solid white).
4. **Glyph blend by table pointer** - `func_24cf0`: `24d33: mov eax,ebp` (table base) / `24d3d: mov al,[esi]` (glyph pixel) / `24d47: mov ah,0x11` (patched `~alpha`) /
   `24d49: mov ah,[eax]` - a 64 KB aligned table is indexed by replacing the low 16 bits of its own pointer: `T[~alpha][~g]` gives the coverage, then each
   channel `mov bl,[eax]` with `ah`=coverage: `T[cov][channel]`.  Tables from 0x14834 (`255-((255-a)(255-b)>>8)` and its complement).
5. **Mask wipes** - `func_1ec58`: `1ec87: shl ebx,0xb / 1ec8a: mov bl,al / 1ec8c: mov al,[ebp+ebx]` index = (k<<11)|channel through the inverse screen
   table (k = mask - threshold, 1..31): a 31-step fade band with one lookup per channel; `1ecaa` adds two such lookups (`not bh`) for the cross-fade.
6. **Colour matrix by 9 table sums** - `func_22990`: `22a03: mov eax,[ebp+ebx*4] / add eax,[ebp+ecx*4+0x400] / add eax,[ebp+edx*4+0x800] / shr eax,0x18 / add eax,0x70`
   = a 3x3 fixed point matrix without a single multiply (tables from 0x148c4: `trunc(i*2^24*coef)`).
7. **Saturating channel math with flags** - `func_1c4f6`: `1c525: add al,bl / jae 0x1c52b / mov al,0xff`, `ror eax,8 / ror ebx,8` to reach the third byte;
   `func_1c91e`: `cmp al,bl / ja / xchg bl,al` = per-byte max; `func_1f337`: `sub cl,dh / jae / xor cl,cl` + `bswap ecx` to reach byte 2.
8. **Scaled sprite with sub-pixel phase** - `func_1f337`: step `0x1000000 / (2R)` (`1f3a5..1f3b5`), start phase `(0x7f - frac(x) + frac(r)) * step >> 8`
   (`1f3d7..1f401`), `add eax,ebp / adc bl,dl` stepping an 8.8 texture coordinate in two registers, size/stride patched into the code (`mov [0x1f44d],cx`).
9. **Displacement light map** - `func_22b43`: `22b5e: mov bp,[ecx*2+X] / add bp,dx / mov bl,[ebp+Y]` 16-bit wrap-around lookup of a light texture through a displacement
   map (0x14b3d output), `add al,bl / jae` saturating add on the image.
10. **565 packing** - `func_25649`: `shr al,3 / mov dl,al`, `and bl,0xf8 / mov dh,bl`, `shl al,3 / and al,0xe0 / or dl,al`, `shr ah,5 / or dh,ah` assembles a 565 word from the
    bytes of a dword with 8-bit register halves only.
