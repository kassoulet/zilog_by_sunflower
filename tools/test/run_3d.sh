#!/bin/sh
# regenerate the vectors with the ORIGINAL code under Unicorn (~7 min) and run the JS differential test
# usage: tools/test/run_3d.sh [--no-gen]
cd "$(dirname "$0")/../.."
PY=${PY:-/tmp/claude-1000/-home-gautier-SynologyDrive-code-current-demos-zilog/30d78e4d-6a5d-45da-a815-458c6cbb7835/scratchpad/v/bin/python}
mkdir -p tools/out
[ "$1" = "--no-gen" ] || $PY tools/test/3d_gen.py tools/out/3d_vectors.json || exit 1
node tools/test/3d.test.mjs tools/out/3d_vectors.json
