# ZILOG (Sunflower, 1999) - asm snippets worth reading

All addresses are linear addresses of the unpacked image `re/image.bin` (the UPX-packed `ZILOG.EXE` run to its Watcom crt entry 0x2383c under Unicorn; PMODE/W flat model,
**load address 0x10000**). Every listing below was re-disassembled with capstone from that file (`re/scripts/disasm.py ADDR LEN`) while writing this document; addresses
are the ones printed. Watcom convention: arguments in EAX, EDX, EBX, ECX, then the stack; the user functions preserve everything but EAX.

The code is a 1999 *software* engine for a Pentium: 32-bit true colour, x87 for geometry, **no MMX, no SSE**. Its signature is that almost no pixel is ever multiplied: blends,
fades, colour matrices, divisions and even the mixer's volume are **table lookups**, and the tables are indexed by building a pointer from two bytes (`mov al,..` / `mov ah,..`).
The other signature is **self-modifying code**: the `0x11111111` immediates you see in the listings are placeholders overwritten with per-call constants.

---

## 1. Fixed-point stepping with `add` + `adc` (the carry is the fixed-point carry)

The warp renderer 0x1d6a4 (8x8 cells, bilinear u,v,shade) keeps each 8.16 coordinate as a **byte register (integer part) + the top half of a dword (fraction)**. The step is added to
the dword, and the carry out of that `add` is absorbed into the integer byte by `adc`:

```
1d866: mov eax, dword ptr [ebx*4]       ; texel; ebx = (page<<..)|v<<8|u : the index IS the address
1d86d: add edx, 0x11111111              ; u fraction += step (immediate, patched)
1d873: mov cl, al
1d875: adc bl, dl                       ; u integer += carry (+ patched integer step in dl)
1d877: mov al, byte ptr [ecx]           ; shade: ecx = (table|shade<<8|texel byte)
1d879: add ebp, 0x11111111              ; v fraction
1d87f: mov cl, ah
1d881: adc bh, dh                       ; v integer
1d883: mov ah, byte ptr [ecx]
1d885: ror eax, 8 / 1d888: mov cl, ah / 1d88a: mov ah, byte ptr [ecx] / 1d88c: rol eax, 8   ; third channel
1d88f: add esi, 0x11111111              ; shade fraction
1d895: adc ch, 0x11                     ; shade integer (the row of the table)
1d898: mov dword ptr [edi], eax / 1d89a: add edi, 4 / 1d89d: dec si / 1d89f: jne 0x1d866
```

Why it is clever: three bilinear interpolators plus the three-channel table shading in 18 instructions per pixel, with no multiplication and no shifts. u and v are 8-bit integers in
`bl`/`bh`, so they **wrap at 256 texels for free**, and `[ebx*4]` is directly the texel address (hence the 256 KB-aligned textures). The pixel counter is `si` (8 per cell row), a
separate register that the `adc`s never touch.

Between rows the code does second-order (bilinear) updates by patching the **immediates in the loop itself**:

```
1d8c5: add dword ptr [0x1d86f], ebx     ; the step immediate of 'add edx,imm32' (at 0x1d86f) += d(step)
1d8cb: adc dl, byte ptr [0x3edf6]
```

The same pattern is the texel span of the triangle filler (0x2bbec) where the **loop counter lives in `cx`** while the fraction of u lives in the high half of `ecx`, so the one register
carries both:

```
2bd35: rol ecx, 0x10 / 2bd38: mov cx, ax / 2bd3b: rol ecx, 0x10   ; ecx = (u_frac<<16) | count
2bd66: mov eax, dword ptr [ebx*4]       ; texel
2bd6d: add edx, ebp / 2bd6f: adc bh, dh ; v
2bd71: add ecx, esi / 2bd73: adc bl, dl ; u (the add cannot touch cx's count: esi has zero low half)
2bd75: mov dword ptr [edi], eax / 2bd77: add edi, 4 / 2bd7a: dec cx / 2bd7c: jne 0x2bd66
```

and the **environment-map + surface texture** span (0x2f2b4, used by `tri_266a0`), four coordinates with four gradients, all patched in, two loads and one add:

```
2f341: mov eax, dword ptr [ebx*4]       ; env texel
2f348: add eax, dword ptr [edx*4]       ; + surface texel (256 KB further), plain 32-bit add
2f354: add ecx, 0x11111111 / 2f35a: adc bl, 0x11      ; env u
2f35d: add ebp, 0x11111111 / 2f363: adc bh, 0x11      ; env v
2f366: add esi, 0x11111111 / 2f36c: adc dl, 0x11      ; surface u
2f36f: add bp, 0x1111       / 2f374: adc dh, 0x11      ; surface v
2f377: dec cx / 2f379: jne 0x2f341
```

The JS port cannot use the trick, so it keeps plain 24-bit accumulators: `uu = (uu + du) & 0xffffff` and takes `(uu >>> 16) & 255` for the integer byte.

## 2. Division by table lookup, pointer as a running sum (box blur, 0x16cdd)

The box blur never divides. Each channel keeps a **pointer into a division table** in a register (`eax`, `edi`, `ebp`). The table (built by 0x16c93) has every value `0..255` repeated `w` times
(`rep stosb` with `ecx = w`, `al` = value, 256 outer iterations):

```
16ca8: mov edx, 0x100
16cad: mov ecx, ebx             ; w
16caf: rep stosb                ; w copies of al
16cb1: inc eax / 16cb2: dec edx / 16cb3: jne 0x16cad
```

so `[base + sum]` is `sum / w`. The sliding window adds the pixel entering and subtracts the one leaving *to the pointers themselves*, then reads the three averages back:

```
16dcd: mov ebx, dword ptr [esi + 0x11111111]   ; incoming pixel
16dd3: mov dl, bl / add eax, edx                 ; pointer0 += b0
16dd7: mov dl, bh / add edi, edx                 ; pointer1 += b1
16ddb: shr ebx, 8 / mov dl, bh / add ebp, edx    ; pointer2 += b2
16de2: mov ebx, dword ptr [esi + 0x11111111]   ; outgoing pixel ... sub eax/edi/ebp
16df7: mov bh, byte ptr [ebp] / shl ebx, 8 / mov bl, byte ptr [eax] / mov bh, byte ptr [edi]  ; 3 lookups = 3 divisions, repacked
16e01: mov dword ptr [esi + 0x11111111], ebx
```

`edx` is zero-extended once and reused, so each channel costs `mov dl / add` for the entry and `mov dl / sub` for the exit. The three displacements are patched by the prologue
(`16ce0: mov [0x16d84], edi` / `16ce6: mov [0x16dbb], edi` / `16cec: mov [0x16e03], edi` = destination-minus-source distance; `16d33: mov [0x16dcf], edx` = window offset), so one routine serves
any radius, and the vertical variant 0x16e53 only has other strides.

The **radial blur** 0x1743b does the same on a precomputed list of pixel offsets with a 16-bit running sum in `ax`, where the division by 2^n is `ror ax, n`:

```
174a1: ror ax, 6                 ; the 6 is patched from the argument: window = 2^n; al = sum >> n
174a5: mov di, word ptr [edx]    ; pixel offset from the path list
174a8: mov byte ptr [edi + 0x11111111], al
174ae: rol ax, 6                 ; restore the sum (the discarded low bits come back)
174b2: movzx di, byte ptr [edi + 0x11111111] / 174ba: sub ax, di   ; leaving sample
174bd..174cc: ... add ax, di     ; entering sample (index +2^n, patched)
174cf: add edx, 2 / 174d2: dec ecx / 174d3: jne 0x174a1
```

`ror`/`rol` by n is a free "divide by 2^n and keep the remainder": the 16-bit accumulator holds `sum`, and the byte that is stored is `sum >> n`, then rotated back with no loss.

## 3. Packed blends with one table lookup per channel (mask wipes, 0x1ec58 / 0x1ee44 / 0x1eeb4)

A 64 KB blend table sits at a 64 KB-aligned address. The code takes the **table pointer's high half as base** and writes the two indices into the low 16 bits (`bl`/`bh`), so `T[a][b]` is one `mov`:

```
1ec7c: cmp ebx, 0x1f / 1ec7f: jle 0x1ec85 / 1ec81: xor eax, eax        ; k > 31: black
1ec85: not eax
1ec87: shl ebx, 0xb             ; k << 11
1ec8a: mov bl, al               ; + channel byte
1ec8c: mov al, byte ptr [ebp + ebx]   ; one lookup: fade by k
1ec90: mov bl, ah / 1ec92: mov ah, byte ptr [ebp + ebx]
1ec96: ror eax, 8 / 1ec99: mov bl, ah / ...                            ; third channel by rotating the dword
```

The cross-fade does both halves and sums them with one dword add; `not bh` flips the table row from `m` to `255-m` for the second image. `0x1ee44` with the early outs
(alpha 0 -> keep, `cmp bx,0xff` -> plain copy of the other image) before any lookup:

```
1ee5d: xor bx, bx
1ee60: mov bl, byte ptr [esi + ecx]     ; alpha from the 8-bit map
1ee66: or bx, bx / 1ee69: jle 0x1eeac   ; 0: keep
1ee6b: cmp bx, 0xff / 1ee70: jl 0x1ee77 / 1ee72: mov eax,[edx+ecx*4] / jmp  ; 255: take the other
1ee79: shl bx, 8 / 1ee7d: mov bl, al / 1ee7f: mov al, byte ptr [ebx] ...
```

and the partial invert 0x1eeb4 computes `m*(1-c)` and `(1-m)*c` as two lookups each and merges them with `1ef1c: add eax, ebp`, flipping the row with `1ef08: not bh`. The loop
counter of these routines runs from a negative count to 0 (`xor ecx,0xffffffff / inc ecx` = negate, then `jne`), so no `cmp` is needed.

The same idea in a 2D palette: the colourise-and-multiply pass 0x22b9c

```
22ba4: lea edi, [edi + ecx*4] / lea esi, [esi + ecx] / lea ebx, [ebx + ecx]   ; pre-bias the pointers by -count
22bad: xor ecx, 0xffffffff / 22bb0: inc ecx                                   ; ecx = -count
22bb1: mov al, byte ptr [ebx + ecx]       ; low image
22bb4: mov ah, byte ptr [esi + ecx]       ; high image
22bb7: mov ebp, dword ptr [edx + eax*4]   ; LUT (v*pal[idx]/64, built by 0x15168) -> 32-bit colour
22bba: mov dword ptr [edi + ecx*4], ebp
22bbd: inc ecx / 22bbe: jne 0x22bb1
```

Two 8-bit images are *concatenated by writing `al` and `ah`*, and the LUT performs colourisation and the multiplication; the loop is a bare 5 instructions per pixel.

A **3x3 colour matrix** (0x22990) is nine such tables summed, no multiply:

```
22a03: mov eax, dword ptr [ebp + ebx*4]
22a07: add eax, dword ptr [ebp + ecx*4 + 0x400]
22a0e: add eax, dword ptr [ebp + edx*4 + 0x800]    ; then shr eax,0x18 / add eax,0x70 (see 22a1x)
```

## 4. Saturating and per-byte arithmetic with flags (no MMX)

A packed 32-bit pixel is processed one byte at a time, using the carry flag for saturation and `ror`/`rol` to reach the third byte. The gouraud grey span of the glowing tunnel (0x2d1db..):

```
2d1db: rol ebx, 0x10            ; fraction to the high half
2d1e4: mov al, bl               ; al = integer intensity
2d1e6: mov ah, byte ptr [0x41474]    ; ah = integer step
2d1ec: mov edx, dword ptr [edi]
2d1ee: add dl, al / 2d1f0: jae 0x2d1f4 / 2d1f2: mov dl, 0xff    ; blue  += al, saturate
2d1f4: add dh, al / 2d1f6: jae 0x2d1fa / 2d1f8: mov dh, 0xff    ; green
2d1fa: ror edx, 8 / 2d1fd: add dh, al / jae / mov dh, 0xff / 2d203: rol edx, 8   ; red, reached by rotating the dword
2d206: mov dword ptr [edi], edx
2d208: add ebx, ebp             ; fractional step
2d20a: adc al, ah               ; its carry into the integer intensity (and the integer step)
2d20f: dec ecx / 2d210: jne 0x2d1ec
```

`add` / `jae` / `mov 0xff` is a saturating add in 3 instructions, and `adc al, ah` steps the intensity **with the carry from the fractional add**, so `ebx` and `ebp` hold the 16-bit fraction and the step. Because the span only *adds*, overlapping
faces simply glow brighter: the "light tunnel" look comes from a plain painter's loop.

The same family: the additive blit `1c525: add al, bl / 1c527: jae 0x1c52b / 1c529: mov al, 0xff` (`ror eax,8` for the next byte), the per-byte maximum of the lighten blit
`1c94d: cmp al, bl / 1c94f: ja 0x1c953 / 1c951: xchg bl, al`, and the **50 % blend** of a texel with the screen (0x2bfbd), where `rcr` rotates the carry of the byte add back in so that the average of two bytes needs no 9-bit register:

```
2bfbd: add al, byte ptr [edi]    / 2bfbf: rcr al, 1       ; (a + b) / 2
2bfc1: add ah, byte ptr [edi+1]  / 2bfc4: rcr ah, 1
2bfc6: ror eax, 8
2bfc9: add ah, byte ptr [edi+2]  / 2bfcc: rcr ah, 1
2bfce: rol eax, 8
```

## 5. Anti-aliased lines and glyphs through the blend table

The line core 0x21d1c writes two pixels per step with weights `(0xffff-frac)>>8` and `frac>>8`; the weighted colour and the screen blend are both lookups. Blending into the destination pixel:

```
21e3d: not ax                     ; ax = colour byte pair: ah is the row, al the column
21e40: mov ah, byte ptr [eax]     ; table lookup (eax's high half is the table address)
21e42: not ah
21e44: mov al, dl / 21e46: mov dl, byte ptr [eax]     ; destination byte 0
21e48: mov al, dh / 21e4a: mov dh, byte ptr [eax]     ; destination byte 1
21e4c: ror edx, 8 / 21e4f: mov al, dh / 21e51: mov dh, byte ptr [eax] / 21e53: rol edx, 8
21e56: mov dword ptr [edi], edx / 21e58: add edi, 0x500       ; next scanline (320*4 bytes)
```

The glyph blitter 0x24cf0 patches the **alpha into the instruction stream** (`24d38: mov ecx, 0x11111111`, `24d47: mov ah, 0x11`, `24d49: mov ah, byte ptr [eax]` is `T[~alpha][~glyph]`):

```
24d33: mov eax, ebp              ; table pointer
24d3d: mov al, byte ptr [esi]    ; glyph pixel
24d3f: or al, al / 24d41: je 0x24d61   ; transparent glyph pixel: skip
24d45: not al
24d47: mov ah, 0x11              ; ~alpha (patched)
24d49: mov ah, byte ptr [eax]    ; coverage
24d4b: not ah
24d4d: mov al, bl                ; then per channel T[coverage][channel]
```

(The "ah/al as table indices" works because the high 16 bits of `eax` are the table base, which is why those tables are 64 KB aligned in the original; the JS port just uses `tab[hi<<8|lo]`.)

## 6. The x87 stack as a register file (cone animator, 0x21290)

Per ring of the vortex, five constants (sin a, cos a, centre y, centre x, scale) are pushed on the FPU stack once, and every point is a handful of `fld`/`fsub st(n)`/`fmul st(n)` against them, no
memory operands for the constants. A 2D rotate-scale about a moving centre in 18 instructions:

```
2143c: fld dword ptr [eax] / 2143e: fsub st(2) / 21440: fmul st(1) / 21442: fstp dword ptr [esp]            ; fx = (x - cx) * sx
21445: fld dword ptr [eax+4] / 21448: fsub st(3) / 2144a: fmul dword ptr [esp+0x40] / 2144e: fstp [esp+4]   ; fy = (y - cy) * sy
21452: fld [esp] / 21455: fmul st(4) / 21457: fadd st(2) / 21459: fld [esp+4] / 2145d: fmul st(6) / 2145f: faddp st(1) / 21461: fstp [edx]    ; x' = fx*cos + cx + fy*sin
21463: fld [esp] / 21466: fmul st(5) / 21468: fadd st(3) / 2146d: fld [esp+4] / 21471: fmul st(5) / 21476: fsubp st(1) / 2147b: fstp [edx-8] ; y' = fx*sin + cy - fy*cos
2147e: cmp eax, ecx / 21480: jne 0x2143c
```

(Interleaved with `mov dword ptr [edx - 4], ebp` at 21473: the z store is slipped in while the multiplier is busy.) The 909 points of the tornado are done in this loop; the port
reproduces it bit-exactly (15 times x 909 points).

In the 3D rotation 0x17e5e the matrix is used in a **Winograd-style** form: the product `x*y` is computed once and shared by the three output rows, so each coordinate costs two multiplications
instead of three:

```
17fc9: fld [ebp-0x68] / fmul [ebp-0x64] / fstp [ebp-0x6c]      ; x*y once
17fd2: fld [ebp-0x50] / fadd [ebp-0x64] / fld [ebp-0x4c] / fadd [ebp-0x68] / fmulp st(1)   ; (m0 + y) * (m1 + x)
17fe0: fld [ebp-0x60] / fmul [ebp-0x48] / faddp st(1)                                       ; + z*m2
17fe8: fld [ebp-0x2c] / fadd [ebp-0x6c] / fsubp st(1)                                       ; - (m0*m1 + x*y)
```

## 7. The `fpatan` polar warp (0x206e0, 0x20b94, 0x20a10, 0x219e8)

Four deformers share one skeleton: Cartesian to spherical with **two `fpatan`**, modify r, convert back with `fsin`/`fcos`:

```
20775: fld [esp+4] / 2077c: fld [esp] / 20783: fpatan                 ; phi = atan2(y, x)
20789: fld [esp] / 2078c: fmul st(0) / 2078e: fstp qword [esp+0x1c]    ; x*x  (kept as a double)
20792: fld [esp+4] / 20796: fmul st(0) / 20798: fadd qword [esp+0x1c]  ; + y*y
2079c: fsqrt / 2079e: fld [esp+8] / 207a2: fpatan                       ; theta = atan2(sqrt(x*x+y*y), z)
```

`fpatan` takes its two arguments directly from the stack and handles every quadrant, so each angle is one instruction. The variants differ only in the radius map: wobble `r + 140 sin(cos(B r - e) + A r + d)`
(0x206e0), ripple `r + amp*sin(ax+d)sin(by+e)sin(cz+f)` (0x20b94), black hole `sqrt(r^2 + 200000) - 200` (0x20a10), extrusion `r + p` (0x219e8). In 0x20b94 the sum `x*x + y*y` is rounded to float32
once (a `fst dword [esp+0x20]`) before the second `sqrt`, which is why the port has a single extra `F(...)` there: bit-exactness depends on where the original stores through memory.

The lens field 0x1d200 has a similar subtlety: the angle is stored as float for one use, but `fcos` is taken from the unrounded register:

```
1d230: fst dword ptr [esp+0x28]      ; float copy
1d234: fcos                           ; ... on the full-precision st(0)
1d23a: fld dword ptr [esp+0x28] / 1d23e: fsin     ; ... but sin on the rounded copy
```

and the 1/r^2 field is `fmul st(0)` (square), the weights, `fmul qword ptr [0x3e348]` (0.001), `fld1 / fdivrp st(1)` at 0x1d345..0x1d367, then `fmul [0x3e350] / fistp / and eax, edi` (0x1d37f..0x1d3a2)
into 8.19 fixed texture coordinates; only 1066 nodes pay for trig, the interpolation does the 64000 pixels.

## 8. Float compared as integer, and an x87 residue that changes a pixel

0x1b533 clamps a float to 255.0 by **comparing its IEEE bits as a signed integer**: positive floats order like integers, so no `fcomp / fnstsw / sahf`:

```
1b656: cmp dword ptr [ebp-8], 0x437f0000     ; 0x437f0000 = 255.0f
1b65d: jle 0x1b666
```

And the opposite lesson in 0x1b2a4: `trunc(255 - r*0.51)` for r = 400: the exact product is 204.0000000000000036, which survives in the x87's 64-bit mantissa and truncates to 50, while a JS
double rounds it to exactly 204 and gives 51. The port needs a Veltkamp split (`trunc255()` in `scenes/_g5mesh.js`, the same family as `truncSum` for the ray table 0x14d0b).

## 9. Free depth split: one opcode decides front half / back half

The faces of an object are sorted far-to-near by `trunc((z0+z1+z2)*100)`; the key array is then walked by two otherwise identical functions, 0x1a7df and 0x1aa02. The first stops at keys <= 0:

```
1a8a9: cmp dword ptr [eax], 0
1a8ac: jle 0x1a9f4              ; (0x1a7df: the half behind z = 0)
```

while 0x1aa02 uses the other condition. The scene draws other things *between* the two halves of the same mesh (the light sprite, the wire rings, the crosshair), a depth interleaving
without a z-buffer. The sphere sprites do the same with `fldz / fcomp [z] / jae` vs `jbe` (0x1a21b / 0x1a5ea).

## 10. Division avoided in the edge stepper, and the one place it overflows (0x2ba62)

The triangle edge stepper needs `dx/dy` for several attributes. For a 1-scanline edge it computes **one** reciprocal and scales each delta by `imul` + `shrd` instead of one `idiv` per attribute:

```
2ba62: mov eax, 0x40000000
2ba67: mov esi, dword ptr [ebx+4] / 2ba6a: mov ebp, dword ptr [ecx+4] / 2ba6f: sub esi, ebp      ; dy
2ba71: sar edx, 0x1f / 2ba74: idiv esi                    ; 2^30 / dy
2ba76: mov ebx, [ebx] / 2ba78: sub ebx, [ecx]            ; dx
2ba7a: mov edx, eax / 2ba7c: mov eax, ebx / 2ba7e: imul edx / 2ba80: shrd eax, edx, 0xe   ; dx * (1/dy) >> 14
```

`imul` gives the full 64-bit product in edx:eax and `shrd eax, edx, 14` extracts the 16.16 result directly. For tiny dy the 32-bit `idiv` overflows exactly like the original, and the port reproduces
this literally with 64-bit intermediates.

The sprite scaler (0x1f337) uses the same scheme with `mov eax, 0x1000000 / ... / shl ecx, 1 / idiv ecx` (0x1f3a5..0x1f3b5): step = 2^24 / (2R) in 8.8-pixel units, and its start phase is derived
from the sub-pixel position (0x1f3d7..0x1f401).

## 11. The music mixer (Useless Sound System, 0x3a6e0)

The software mixer's whole inner loop for a stereo voice is four instructions per output sample, with the multiplication `volume * sample` replaced by a **65 x 256 table of 16-bit words**
(`s8 * vol * 65536 / (0x3e800/gain*64)`, built by 0x399bd) indexed by `(volume<<8)|sample`:

```
3a6e0: mov bl, byte ptr [esi]            ; sample byte (ebx high bytes = volume row, from the setup)
3a6e2: add cx, word ptr [0x3989a]        ; frac += step (16.16 position: frac in cx, int in esi)
3a6e9: mov ax, word ptr [ebx*2]          ; left  = table[vol_l][sample]
3a6f1: adc esi, ebp                      ; advance the integer position by the carry (+ int step in ebp)
3a6f3: mov dl, bl                        ; same sample byte, other volume row (edx = right row)
3a6f5: add word ptr [edi], ax            ; accumulate left (16-bit wrap, no clipping)
3a6f8: mov ax, word ptr [edx*2]          ; right = table[vol_r][sample]
3a700: add word ptr [edi+2], ax          ; accumulate right
```

Position `cx:esi` with `adc` is the same carry trick as in the graphics. The loop is unrolled 16 x 4 frames, and the loop-end check is done only once per chunk of 64 frames; exactness
at loop ends is obtained by **appending 0x200 bytes of the loop continuation** to each looped sample at upload time (0x39ae7; ping-pong loops get the reversed loop appended), so the mixer can
over-read safely.

Other musical bits:

* **Delta-coded samples** are decoded in place in a 6 instruction loop at load (0x322f0 ... 0x32332): `add al, [esi] / mov [esi], al / inc esi / loop`.
* **The tick scheduler** (0x32601, the 50 Hz IRQ callback) is quantised to the IRQ: `acc += 0x5d37` (= 1/50 s of the 1.19318 MHz PIT) and `while (acc >= tickLen) { acc -= tickLen; tick(); envelopes(); }`:
  ```
  32602: add dword ptr [0x31504], eax        ; acc += 23863
  32608: mov eax, dword ptr [0x31500] / 3260d: cmp [0x31504], eax / 32613: jb 0x32627   ; < tickLen: done
  32615: sub dword ptr [0x31504], eax / 3261b: call 0x3262e / 32620: call 0x343a6 / 32625: jmp 0x32608
  ```
* **`2^(x/768)` for the pitch** (0x34911): the exponent is split into four nibbles/2-bit fields, each indexes a small table of 16.16 factors, and the four factors are multiplied with
  `mul / shrd eax, edx, 0xf`:
  ```
  3492c: mov eax, [eax*4 + 0x34901] / 34933: mov edx, [edx*4 + 0x348c1] / 3493a: movzx ebx, word [ebx*2 + 0x348a1] / 34942: movzx ecx, word [ecx*2 + 0x34881]
  3494a: mul edx / 3494c: shrd eax, edx, 0xf / 34950: mul ebx / 34952: shrd eax, edx, 0xf / 34956: mul ecx / 34958: shrd eax, edx, 0xf
  ```
  A full `exp2` in three multiplications and four table loads (the tables are 16 + 16 + 4 + 4 entries).

## 12. What I looked for and did not extract

The Watcom runtime, the VESA converters (0x25649 packs RGB565 with only 8-bit register halves: `shr al,3 / and bl,0xf8 / ...`) and the self-checking PMODE/W stub are standard and not detailed here. No
anti-debug or packer-level tricks beyond UPX were found in the unpacked image; the packer itself was only used to get the image (run its own stub under Unicorn, dump at the crt entry).
