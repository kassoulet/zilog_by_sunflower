// Usage: node tools/extract.mjs ZILOG.EXE site/data   -> writes data.dat (the container) + decoded files in raw/ (optional)
import fs from 'fs'; import path from 'path';
import { parseContainer } from '../site/js/core/assets.js';
const [exe, out, dump] = process.argv.slice(2);
const e = fs.readFileSync(exe), p = e.indexOf('DATA?\0\0\0');
const dat = e.subarray(p);
fs.mkdirSync(out, { recursive: true }); fs.writeFileSync(path.join(out, 'data.dat'), dat);
if (dump) for (const [n, d] of parseContainer(new Uint8Array(dat))) { const f = path.join(dump, n); fs.mkdirSync(path.dirname(f), { recursive: true }); fs.writeFileSync(f, d); }
console.log('container', dat.length, 'bytes');
