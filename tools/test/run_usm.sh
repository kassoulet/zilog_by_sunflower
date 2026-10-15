#!/bin/sh
# regenerate the ground truth with the ORIGINAL code under Unicorn (~1.5 min) and run the JS test
# usage: tools/test/run_usm.sh [--no-gen]
cd "$(dirname "$0")/../.."
PY=${PY:-/tmp/claude-1000/-home-gautier-SynologyDrive-code-current-demos-zilog/30d78e4d-6a5d-45da-a815-458c6cbb7835/scratchpad/v/bin/python}
if [ "$1" != "--no-gen" ]; then
  node -e "import('./site/js/core/assets.js').then(m=>{const fs=require('fs');fs.mkdirSync('tools/out',{recursive:true});fs.writeFileSync('tools/out/ana.u',m.parseContainer(new Uint8Array(fs.readFileSync('site/data/data.dat'))).get('music/ana.u'))})" || exit 1
  $PY tools/test/usm_mktruth.py tools/out/ana.u tools/test/usm_truth.json || exit 1
fi
node tools/test/usm.test.mjs
