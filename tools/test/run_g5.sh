#!/bin/sh
# regenerate vectors from the original (~2.5 min) and run the JS differential test.  usage: tools/test/run_g5.sh [--no-gen]
cd "$(dirname "$0")/../.."
PY=${PY:-/tmp/claude-1000/-home-gautier-SynologyDrive-code-current-demos-zilog/30d78e4d-6a5d-45da-a815-458c6cbb7835/scratchpad/v/bin/python}
mkdir -p tools/out
[ "$1" = "--no-gen" ] || $PY tools/test/g5_gen.py tools/out/g5_vectors.json || exit 1
node tools/test/g5.test.mjs tools/out/g5_vectors.json
