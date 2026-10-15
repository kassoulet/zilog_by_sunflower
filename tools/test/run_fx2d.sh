#!/bin/sh
# Differential test of site/js/lib/fx2d*.js against the original code under Unicorn (~1 min).
# FX2D_PY = python with unicorn (default: the project scratch venv), vectors go to $FX2D_SCRATCH (default /tmp/fx2d_scratch).
PY=${FX2D_PY:-/tmp/claude-1000/-home-gautier-SynologyDrive-code-current-demos-zilog/30d78e4d-6a5d-45da-a815-458c6cbb7835/scratchpad/v/bin/python}
D=$(dirname "$0"); S=${FX2D_SCRATCH:-/tmp/fx2d_scratch}; mkdir -p "$S"
[ -f "$S/vectors.json" ] && [ "$1" != "--regen" ] || FX2D_SCRATCH=$S $PY "$D/fx2d_gen.py" "$S/vectors.json" > "$S/gen.log" || { tail "$S/gen.log"; exit 1; }
node "$D/fx2d.test.mjs" "$S/vectors.json"
