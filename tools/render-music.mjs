// Render the whole ZILOG music (music/ana.u from site/data/data.dat) to a 16-bit stereo WAV and print the order start times.
//   node tools/render-music.mjs [out.wav=tools/out/ana.wav] [--rate=44100] [--in=module.u|data.dat]
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';
import { parseContainer } from '../site/js/core/assets.js';
import { UsmPlayer, BLOCK_FRAMES } from '../site/js/music/usm.js';

const root = path.join(path.dirname(fileURLToPath(import.meta.url)), '..');
const args = process.argv.slice(2);
const opt = Object.fromEntries(args.filter(a => a.startsWith('--')).map(a => a.slice(2).split('=')));
const out = args.find(a => !a.startsWith('--')) ?? path.join(root, 'tools/out/ana.wav');
const rate = +(opt.rate ?? 44100);
const inp = opt.in ?? path.join(root, 'site/data/data.dat');
let bytes = new Uint8Array(fs.readFileSync(inp));
if (String.fromCharCode(...bytes.subarray(0, 4)) === 'DATA') bytes = parseContainer(bytes).get('music/ana.u');

const player = new UsmPlayer(bytes, rate);
const tl = player.timeline();
const total = Math.ceil((tl.blocks + 1) * BLOCK_FRAMES * rate / 44100);       // up to the end of the song (first wrap)
const L = new Float32Array(total), R = new Float32Array(total);
for (let o = 0; o < total; o += 4096) player.renderInto(L.subarray(o, Math.min(total, o + 4096)), R.subarray(o, Math.min(total, o + 4096)), Math.min(4096, total - o));

const pcm = Buffer.alloc(44 + total * 4);
pcm.write('RIFF', 0); pcm.writeUInt32LE(36 + total * 4, 4); pcm.write('WAVEfmt ', 8); pcm.writeUInt32LE(16, 16);
pcm.writeUInt16LE(1, 20); pcm.writeUInt16LE(2, 22); pcm.writeUInt32LE(rate, 24); pcm.writeUInt32LE(rate * 4, 28); pcm.writeUInt16LE(4, 32); pcm.writeUInt16LE(16, 34);
pcm.write('data', 36); pcm.writeUInt32LE(total * 4, 40);
const q = (x) => Math.max(-32768, Math.min(32767, Math.round(x * 32768)));
for (let i = 0; i < total; i++) { pcm.writeInt16LE(q(L[i]), 44 + 4 * i); pcm.writeInt16LE(q(R[i]), 46 + 4 * i); }
fs.mkdirSync(path.dirname(out), { recursive: true });
fs.writeFileSync(out, pcm);

console.log(`title "${player.mod.title.trim()}"  ${player.mod.nChannels} channels, ${player.mod.orderLen} orders, speed ${player.mod.initSpeed} tempo ${player.mod.initTempo}`);
console.log(`song duration ${tl.duration.toFixed(3)} s (${tl.blocks} blocks of ${BLOCK_FRAMES} frames @44100); wrote ${out} (${(total / rate).toFixed(2)} s @${rate} Hz)`);
console.log('order start times (s) at which the demo sees DAT_00031514 reach the value:');
for (const o of [5, 14, 19, 23, 27, 31, 35, 41, 49, 51]) console.log(`  order ${String(o).padStart(2)}  ${tl.orderStart(o).toFixed(3)}`);
