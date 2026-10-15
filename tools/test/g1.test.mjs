// node g1.test.mjs vectors.json  (see run_g1.sh)
import fs from 'fs';
import * as G from '../../site/js/scenes/_g1fx.js';
let bad = 0, tot = 0;
for (const v of JSON.parse(fs.readFileSync(process.argv[2], 'utf8'))) {
  const o = new Int32Array(26 * 41 * 3); G[v.fn](o, Math.fround(v.t));
  const e = new Int32Array(new Uint8Array(Buffer.from(v.out, 'base64')).buffer);
  let d = 0, mx = 0; for (let i = 0; i < e.length; i++) if (o[i] !== e[i]) { d++; mx = Math.max(mx, Math.abs(o[i] - e[i])); }
  tot++; if (d) { bad++; console.log('DIFF', v.fn, v.t, d, 'max', mx); }
}
console.log(bad ? `${bad}/${tot} vectors differ` : `all ${tot} vectors identical`);
process.exit(bad ? 1 : 0);
