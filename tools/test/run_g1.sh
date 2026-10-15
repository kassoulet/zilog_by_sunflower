#!/bin/sh
PY=${FX2D_PY:-/tmp/claude-1000/-home-gautier-SynologyDrive-code-current-demos-zilog/30d78e4d-6a5d-45da-a815-458c6cbb7835/scratchpad/v/bin/python}
D=$(dirname "$0"); S=${G1_SCRATCH:-/tmp/g1_scratch}; mkdir -p "$S"
$PY "$D/g1_gen.py" "$S/v.json" && node "$D/g1.test.mjs" "$S/v.json"
