#!/bin/sh
cd "$(dirname "$0")/../.."
PY=${PY:-/tmp/claude-1000/-home-gautier-SynologyDrive-code-current-demos-zilog/30d78e4d-6a5d-45da-a815-458c6cbb7835/scratchpad/v/bin/python}
mkdir -p tools/out; $PY tools/test/g4_gen.py tools/out/g4_vectors.json && node tools/test/g4.test.mjs tools/out/g4_vectors.json
