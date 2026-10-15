# ZILOG — a 1999 DOS demo, reverse-engineered to JavaScript

Port of **ZILOG** by *Sunflower* (mrock, falcon, visualize, voomie) — a 32-bit DOS demo (PMODE/W, Watcom C, x87 software 3D at 320×200 true colour).
Playable in the browser, with an explainer page (retro context, scene-by-scene notes, asm inner loops, 3D engine).

* **Live site**: `site/` is a static site → GitHub Pages (workflow in `.github/workflows/pages.yml`; enable *Settings → Pages → Source: GitHub Actions*).
  Locally: `python3 -m http.server --directory site` and open http://localhost:8000.
* **Player**: pause, skip scene (← / →), fullscreen (F), scene chips, seek bar. Audio is the ported tracker player running in an AudioWorklet.

## Layout
| path | what |
|---|---|
| `site/index.html`, `site/js/main.js`, `player.js`, `demo.js` | page, canvas player, host that drives scenes from the music position |
| `site/js/core/` | asset container + LZW, GFX and MOB loaders |
| `site/js/lib/` | `fx2d*` (2D/post FX, tables, text, flip), `mesh3d*` (3D engine + rasterisers) |
| `site/js/music/` | `usm.js` (Useless Sound System module player, bit-exact), AudioWorklet |
| `site/js/scenes/` | the 11 loops of `main()` (`scene0..9.js`, credits = `_g5final.js`) and their helpers |
| `site/data/data.dat` | the demo's own asset container (63 LZW files, tail of `ZILOG.EXE`) |
| `re/` | reverse-engineering material: `NOTES.md`, per-area `PORT_*.md`/`SCENE_g*.md`, Ghidra decompilation, Unicorn harness `re/harness/orig.py` |
| `tools/` | `extract.mjs` (container from the EXE), `render-scene.mjs`, `refframe.sh`, and `tools/test/` differential tests |

## Verification
Every ported function is compared with the **original machine code** executed under Unicorn (`re/harness/orig.py`):
`tools/test/run_fx2d.sh` (216 vectors), `run_3d.sh` (206 checks, pixel-exact), `run_usm.sh` (all 10 448 music blocks, sample-exact),
`run_g1.sh … run_g5.sh` (scene-specific functions). Whole frames were compared by eye with a DOSBox capture.
Needs python3 with `unicorn` + `capstone` and node ≥ 20. `ZILOG.EXE` (original) is expected in the repo root for `tools/extract.mjs`.

## Credits and rights
ZILOG is © 1999 Sunflower. Original artwork, models and music are theirs and are shown with credit; contact the maintainers to have anything removed.
Sound system: Useless Sound System v1.04 (FreddyV/Useless). DOS extender: PMODE/W (Daredevil & Tran).
