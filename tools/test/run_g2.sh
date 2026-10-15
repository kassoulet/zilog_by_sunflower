#!/bin/sh
# regenerate vectors from the original (Unicorn) and run the JS differential test for scenes 2/3 helpers
cd "$(dirname "$0")/../.."
PY=${PY:-/tmp/claude-1000/-home-gautier-SynologyDrive-code-current-demos-zilog/30d78e4d-6a5d-45da-a815-458c6cbb7835/scratchpad/v/bin/python}
mkdir -p tools/out
[ "$1" = "--no-gen" ] || $PY tools/test/g2_gen.py tools/out/g2_vectors.json || exit 1
node tools/test/g2.test.mjs tools/out/g2_vectors.json
