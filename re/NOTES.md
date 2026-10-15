# ZILOG.EXE reverse-engineering notes (for the JS port)

Demo: "zilog" by Sunflower (mrock, falcon, visualize, voomie), 1999. DOS, PMODE/W, UPX-packed, Watcom C, FPU-heavy 3D + 320x200 true-colour software effects.
Goal: faithful JS port (`site/js/**`) + GitHub-pages explainer with asm inner-loop snippets.

## Where things are
* `re/image.bin`      unpacked LE object 1 (0x34000 bytes), **load address 0x10000**, entry 0x2383c (Watcom crt), `main` = func_100d3.
* `re/decomp/<addr>.c` Ghidra decompilation, one file per function (address = hex, no 0x). Float/double constants are inlined as `/*c*/1.5`.
  It is a *skeleton*: trust the arithmetic but double check args/pointer math in `re/asm2.txt` (annotated linear listing, strings and float constants resolved).
* `re/scripts/`       how it was produced (unpack with unicorn, recursive-descent disasm, ghidra headless script).
* `re/harness/orig.py` **Run any original function under Unicorn** for differential testing (see its docstring + selftest.py). Use it! Compare your JS output with the real code on random inputs.
* `site/data/data.dat` the demo's asset container; `site/js/core/{assets,gfx,mob}.js` loaders (already done & verified). `tools/extract.mjs`.
* Reference video of the original running in DOSBox: `tools/refframe.sh <sec> out.png` (20 fps, whole demo ~220 s; absolute times approximate, scene order reliable; ref.mkv in scratchpad).
  COLOUR ORDER (settled): screen dword = 0x00RRGGBB (byte0=B, byte2=R); display = R=byte2. The DOSBox *reference video* is R/B-swapped for direct-colour VESA modes (verified with a test .COM), so swap R/B on the ref frames when comparing colours. Warm orange simulcra.gfx is the true look.
* Python with unicorn+capstone: `/tmp/claude-1000/-home-gautier-SynologyDrive-code-current-demos-zilog/30d78e4d-6a5d-45da-a815-458c6cbb7835/scratchpad/v/bin/python` (use `-I` flag only when reading untrusted data).
* Ghidra 11.3.2 headless is in the same scratchpad (gh/…); redecompile recipe in re/scripts/dec.py (needs the fake JDK dir `fakejdk` + patched x86gcc.cspec). Rarely needed.

## Calling convention / decompiler caveats
* Watcom `-3r`: integer args in EAX, EDX, EBX, ECX then stack (callee pops). User functions preserve all registers except EAX. Floats are passed on the stack (4-byte float unless asm shows `fld qword`), floats returned in ST0.
* `ftrunc(x)` (func 0x1c472) = truncate-toward-zero of ST0 (round control 11). `(int)ROUND(ftrunc(..))` is just a C `(int)` cast of a float.
* Several routines are **self-modifying** (patched displacement `0x11111111`, immediates): blur functions 16cdd/16e53/16ffb/1743b. Read asm, not decomp.
* Pixel buffers are 320x200 **dwords** (0x00RRGGBB-ish; byte0,byte1,byte2 = channel bytes as stored in GFX files, byte3 unused/alpha). Per-channel math is done with packed byte tricks (`>>1 & 0x7f7f7f`, table lookups per byte). Keep dword semantics in JS (Uint32Array), reproduce wraparound/saturation exactly.
* Frame flip = FUN_00017c11 (screen buffer DAT_000402f0 -> VESA/VGA via 0x254ba etc.). The demo tries 32,24,16,15,12(fake),8 bpp. In DOSBox (ref capture) it ends up in a direct-colour mode.
* Timer ISR func_10010 @70 Hz: DAT_0004031c = tick counter, `DAT_00040324` fps counter. DAT_0003ed0c = frames elapsed since last frame (dt, in ticks?), DAT_00040310 = running time (float). Scene switching in main is driven by **music order DAT_00031514** (<5,<14,<19,<23,<27,<31,<35,<41,<49,<51) and row DAT_00031518, so the music player gives the timeline.
* 3D engine ("mobutil.c" 3dlib): MOB mesh struct (0x54 bytes) fields by dword index: 0 npts,1 pts,2 xformed pts,3 vertex-enable mask,4 vertex normals,5 xformed normals,6 nfaces,7 faces,8 face normals,
  0xc/0xd vertex->face adjacency (+index), 0xf nedges,0x10 edges,0x11 projected 2D (x,y floats),0x12? ,0x13 per-vertex 1/z, 0x0e.. etc. Object instance: {mesh*, cx, cy, dist, focal, texture*, ..., byte[+0x1c]=render mode, byte[+0x1d]=sub mode}.
  Render modes (FUN_00018beb): 0/1 filled faces env-mapped, 2/3 textured+env, 4 textured, 5/6 silhouette/feature edges, 7/8 all edges, 9 vertex point sprites (size from 1/z).

## JS conventions
* ES modules, isomorphic (browser + node), no deps. Buffers: `Uint32Array(64000)` for 320x200 screens; textures 256x256 -> `Uint32Array(65536)`; 8-bit data `Uint8Array`.
* Port functions with names `f_<hexaddr>` (e.g. `f_16cdd`) plus a descriptive alias, and a JSDoc line `// ported from func_16cdd (0x16cdd): <what it does>`.
* Mirror the original numerics: float32 where the original stores `float` (use Math.fround), integer wrap (`|0`, `>>>0`), 16.16 fixed point as in the asm.
* Every ported module gets a node self-check in `tools/test/<module>.test.mjs` (differential against the original via re/harness when feasible, run through `python` generating vectors -> JSON -> node compares).

## Status of libraries (wave 1 done)
* `site/js/lib/fx2d.js` (2D/FX, see re/PORT_2d.md), `site/js/lib/mesh3d.js` (3D engine, re/PORT_3d.md), `site/js/music/usm.js` (music, re/PORT_music.md). All differential-tested vs the original.
* Harness fix: Unicorn starts with x87 control word 0 (24-bit precision): orig.py now runs fninit(0x37f). Always do that if you write your own emulator setup.

## Scene API (wave 2)
Scenes = the 10 `while (DAT_00031514 < N)` loops of main (func_100d3, re/decomp/100d3.c; search `00031514 <`) with N = 5,14,19,23,27,31,35,41,49,51 (scene 0..9). Music order start times (s): 0, 17.339, 48.490, 67.513, 81.364, 95.215, 109.047, 122.898, 143.665, 171.348, end 178.283.
Each scene is `site/js/scenes/sceneN.js` exporting `createScene(env)` -> `{name, orderStart, orderEnd, init(), frame(st)}`; see `site/js/env.js` (assets, `env.scr`, per-frame globals `env.st`) and `tools/render-scene.mjs` (renders frames to PNG).
* `init()` = everything main() does for this scene *before/at the top of its loop* (allocs, table builds, `_DAT_00040314 = ticks*K` time re-basing, setup of object structs). The setup before the first loop (asset loading, 14639/14834/148c4/14c51/14d0b/15168 table builds, fonts) is global: each scene file may lazily build what it needs from `env` (cache on `env.shared` object so several scenes reuse them).
* `frame(st)` = one iteration of the loop body *including the prologue FUN_00010061* (already applied by host in `st`: ticks, dt, pos=order*64+row, time=ticks*0.25-timeBase) *and the final flip* (do NOT flip: the host presents `env.scr`). Loop-exit conditions are the host's job.
* The prologue @0x10061: waits for a tick change, `dt = ticks - lastTicks` (DAT_0003ed0c), `pos = order*64+row` (DAT_00040328), `time = ticks*0.25 - DAT_00040314` (DAT_00040310). Scene code re-bases DAT_00040314 itself: model it with a per-scene `timeBase` variable and compute `time` locally from `st.ticks` (do not rely on st.time).
* Music-driven triggers: DAT_000314f4 -> `st.sync` (value of the last 'sync marker' module effect), count in `st.syncCount`. Scenes test e.g. `DAT_000314f4 == 1`. Assume the host provides these.
* Per-frame float state kept across frames (DAT_0004032c, 40330.., fade values) = closure variables inside the scene. Global DAT_ variables shared between scenes: keep in `env.shared`.
* Differential testing of scene-specific functions (FPU effect objects 0x19f57..0x1bf97, 0x1ce90..0x1d3d8, 0x206e0..0x21664, 0x21290, 0x219e8 ...) against the original under Unicorn is expected wherever feasible (state in emulated memory). Whole frames can't be run in the emulator (hardware), so also compare rendered frames with the reference video (tools/refframe.sh; swap R/B on the ref!) — find the scene by eye on a contact sheet; times in the ref are approximate.
* Duplicates across scene files are OK for now (each agent ports the scene-specific helpers it needs in its own files `site/js/scenes/_<group>*.js`).
