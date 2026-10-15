// node g3.test.mjs vectors.json  -- compares scenes/_g3.js against the original (see g3_gen.py)
import fs from 'fs';
import { coneWarp } from '../../site/js/scenes/_g3.js';
const v = JSON.parse(fs.readFileSync(process.argv[2]));
const f = (s) => { const b = Buffer.from(s, 'base64'); return new Float32Array(b.buffer, b.byteOffset, b.length / 4); };
const pts = f(v.pts); let bad = 0, maxd = 0;
for (const c of v.cases) {
  const m = { npts: v.npts, pts, xpts: new Float32Array(v.npts * 3) }; coneWarp(m, c.t);
  const e = f(c.xpts);
  for (let i = 0; i < e.length; i++) if (m.xpts[i] !== e[i]) { bad++; maxd = Math.max(maxd, Math.abs(m.xpts[i] - e[i])); }
}
console.log(bad ? `FAIL ${bad} diffs (max ${maxd})` : `OK ${v.cases.length} cases bit exact`); process.exit(bad ? 1 : 0);
