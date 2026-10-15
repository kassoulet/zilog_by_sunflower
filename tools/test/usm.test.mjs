// Self-check of site/js/music/usm.js against the ORIGINAL player (ground truth made with Unicorn, see usm_mktruth.py).
//   node tools/test/usm.test.mjs                                 whole-song check against tools/test/usm_truth.json
//   node tools/test/usm.test.mjs --vs mod.u gt.json [nblocks]    detailed per-block diff vs usm_groundtruth.py output (fuzzing)
//   node tools/test/usm.test.mjs --vs-mix mod.u mix.i16 [n]      mixer output diff vs usm_mixtruth.py output
import fs from 'node:fs';
import assert from 'node:assert/strict';
import zlib from 'node:zlib';
import { fileURLToPath } from 'node:url';
import path from 'node:path';
import { parseContainer } from '../../site/js/core/assets.js';
import { parseUsm, UsmPlayer, BLOCK_FRAMES } from '../../site/js/music/usm.js';

const root = path.join(path.dirname(fileURLToPath(import.meta.url)), '..', '..');
const loadModule = () => parseContainer(new Uint8Array(fs.readFileSync(path.join(root, 'site/data/data.dat')))).get('music/ana.u');
const STATE_FIELDS = [0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18];   // indexes into UsmPlayer.chState()
const crc = (u8) => zlib.crc32(u8) >>> 0;

// ---------------------------------------------------------------- detailed diff modes (used for fuzzing)
const argv = process.argv.slice(2);
if (argv[0] === '--vs') {
  const bytes = new Uint8Array(fs.readFileSync(argv[1])), gt = JSON.parse(fs.readFileSync(argv[2]));
  const p = new UsmPlayer(bytes, 44100, { noVoiceEnd: true }); p.muteMix = true;
  const names = ['period', 'vol', 'pan', 'freq', 'flags', 'smp', 'inst', 'base', 'pos', 'nvol', 'chvol', 'envV', 'fade', 'envP', 'panSet', 'envPosP', 'envFrP', 'envPosV', 'envFrV'];
  const n = Math.min(gt.blocks.length, +argv[3] || 1e9); let bad = 0;
  for (let i = 0; i < n && bad < 10; i++) {
    const g = gt.blocks[i];
    p.irq(false, (q) => {
      const h = [];
      if (q.order !== g.o || q.row !== g.r) h.push(`seq ${q.order}:${q.row} vs ${g.o}:${g.r}`);
      if (q.speed !== g.sp || q.tempo !== g.tp || q.gvol !== g.gv) h.push(`speed/tempo/gvol ${q.speed}/${q.tempo}/${q.gvol} vs ${g.sp}/${g.tp}/${g.gv}`);
      for (let c = 0; c < gt.nch; c++) {
        const a = q.chState(c), b = g.c[c];
        for (const k of STATE_FIELDS) {
          let bv = b[k]; if (k === 5 && bv >= 0xf0000000) bv = 0xffffffff; if (k === 6 && bv >= 0xf0000000) bv = 0;
          if (a[k] !== bv) h.push(`blk ${i} ch${c} ${names[k]} js=${a[k]} orig=${bv}`);
        }
      }
      if (h.length) { bad++; console.log(h.slice(0, 6).join('\n')); }
    });
  }
  console.log(`compared ${n} blocks, bad ${bad}`); process.exit(bad ? 1 : 0);
}
if (argv[0] === '--vs-mix') {
  const p = new UsmPlayer(new Uint8Array(fs.readFileSync(argv[1])), 44100);
  const raw = fs.readFileSync(argv[2]), o = new Int16Array(raw.buffer, raw.byteOffset, raw.length >> 1);
  const n = Math.min(+argv[3] || 1e9, o.length / (2 * BLOCK_FRAMES)); let bad = 0;
  for (let b = 0; b < n && bad < 5; b++) {
    p.irq(true); let cnt = 0, first = -1;
    for (let k = 0; k < 2 * BLOCK_FRAMES; k++) if ((p.acc[k] << 16 >> 16) !== o[b * 2 * BLOCK_FRAMES + k]) { cnt++; if (first < 0) first = k; }
    if (cnt) { bad++; console.log(`block ${b}: ${cnt} diffs, first at ${first} (order ${p.order} row ${p.row})`); }
  }
  console.log(`compared ${n} blocks, bad ${bad}`); process.exit(bad ? 1 : 0);
}

// ---------------------------------------------------------------- 1. file format
const bytes = loadModule();
const mod = parseUsm(bytes);
assert.equal(mod.title.trim(), '73 millions seconds');
assert.equal(mod.nChannels, 28); assert.equal(mod.orderLen, 60); assert.equal(mod.nSamples, 59); assert.equal(mod.nInstruments, 55);
assert.equal(mod.initSpeed, 3); assert.equal(mod.initTempo, 139); assert.equal(mod.globalVol, 0x80); assert.equal(mod.restartOrder, 1);
assert.equal(mod.patterns.filter(Boolean).length, 57); assert.equal(mod.samples.filter(Boolean).length, 59); assert.equal(mod.instruments.filter(Boolean).length, 55);
assert.throws(() => parseUsm(new Uint8Array(64)), /magic/);
console.log('ok  parse: header, 57 patterns, 59 samples, 55 instruments');

// ---------------------------------------------------------------- 2. whole song vs the original (Unicorn)
const T = JSON.parse(fs.readFileSync(new URL('./usm_truth.json', import.meta.url)));
const b64 = (s) => Buffer.from(s, 'base64');
const tOrder = new Uint8Array(b64(T.order)), tRowB = b64(T.row), tRow = new Uint16Array(tRowB.buffer, tRowB.byteOffset, T.nblocks);
const tState = new Uint32Array(new Uint8Array(b64(T.stateCrc)).buffer), tMix = new Uint32Array(new Uint8Array(b64(T.mixCrc)).buffer);
assert.deepEqual(T.fields, STATE_FIELDS);

// 2a. sequencer-only timeline == original order/row at every IRQ block
const player0 = new UsmPlayer(bytes, 44100, { mod });
const tl = player0.timeline();
assert.equal(tl.blocks, T.nblocks - 0, 'timeline length');
for (let i = 0; i < T.nblocks; i++) { if (tl.order[i] !== tOrder[i] || tl.row[i] !== tRow[i]) assert.fail(`block ${i}: js ${tl.order[i]}:${tl.row[i]} orig ${tOrder[i]}:${tRow[i]}`); }
const tSV = new Uint8Array(b64(T.syncValue)), tSC = new Uint32Array(new Uint8Array(b64(T.syncCount)).buffer);
for (let i = 0; i < T.nblocks; i++) if (tl.syncValue[i] !== tSV[i] || tl.syncCount[i] !== tSC[i]) assert.fail(`sync differs at block ${i}`);
assert.ok(tSC[T.nblocks - 1] > 0, 'song has sync markers');
{ const t = 100.5, n = Math.floor(t / tl.blockDur); assert.deepEqual(tl.syncAt(t), { value: tSV[n - 1], count: tSC[n - 1] }); }
assert.deepEqual([...new Set(tl.speed)], T.speed); assert.deepEqual([...new Set(tl.tempo)], T.tempo);
console.log(`ok  timeline: order/row identical to the original for all ${T.nblocks} IRQ blocks, duration ${tl.duration.toFixed(3)} s`);

// 2b. voice state (period, volume, pan, frequency, flags, sample/instrument, envelopes ...) after every block
{
  const p = new UsmPlayer(bytes, 44100, { mod, noVoiceEnd: true }); p.muteMix = true;
  const buf = new Uint32Array(T.nch * STATE_FIELDS.length);
  for (let i = 0; i < T.nblocks; i++) {
    let c32;
    p.irq(false, (q) => {
      let k = 0;
      for (let c = 0; c < T.nch; c++) { const s = q.chState(c); for (const f of STATE_FIELDS) buf[k++] = s[f] >>> 0; }
      c32 = crc(new Uint8Array(buf.buffer));
    });
    if (c32 !== tState[i]) assert.fail(`voice state differs at block ${i} (order ${p.order} row ${p.row})`);
  }
  console.log(`ok  voice state: crc of all ${T.nch} channels identical for all ${T.nblocks} blocks`);
}

// 2c. rendered samples: crc of every 884-frame int16 stereo block == original SB16 software mixer
{
  const p = new UsmPlayer(bytes, 44100, { mod }); const i16 = new Int16Array(2 * BLOCK_FRAMES);
  for (let i = 0; i < T.nblocks; i++) {
    p.irq(true); for (let k = 0; k < i16.length; k++) i16[k] = p.acc[k];
    if (crc(new Uint8Array(i16.buffer)) !== tMix[i]) assert.fail(`mixer output differs at block ${i}`);
  }
  console.log(`ok  mixer: all ${T.nblocks} blocks sample-exact vs the original mixer (16-bit wrap included)`);
}

// ---------------------------------------------------------------- 3. API behaviour
{
  // render() continues seamlessly whatever the chunking; starts with 2 silent blocks; stereo; amplitude sane
  const a = new UsmPlayer(bytes, 44100, { mod }), b = new UsmPlayer(bytes, 44100, { mod });
  const N = 44100 * 3, whole = a.render(N), L = new Float32Array(N), R = new Float32Array(N);
  for (let o = 0, step = 1; o < N; o += step, step = (step * 7 + 13) % 4000 + 1) { const n = Math.min(step, N - o); b.renderInto(L.subarray(o, o + n), R.subarray(o, o + n), n); }
  assert.deepEqual(whole.left, L); assert.deepEqual(whole.right, R);
  assert.ok(whole.left.slice(0, 2 * BLOCK_FRAMES).every((v) => v === 0), 'first 2 blocks silent');
  assert.ok(whole.left.some((v) => v !== 0) && whole.left.every((v) => Math.abs(v) < 1));
  // different output rate: same duration, finite, correlated energy
  const c = new UsmPlayer(bytes, 48000, { mod }), r48 = c.render(48000 * 3);
  assert.equal(r48.left.length, 144000); assert.ok(r48.left.every(Number.isFinite));
  const rms = (x) => Math.sqrt(x.reduce((s, v) => s + v * v, 0) / x.length);
  assert.ok(Math.abs(rms(r48.left) / rms(whole.left) - 1) < 0.15, 'rms @48k ~ rms @44.1k');
  console.log('ok  render(): chunk-independent, 2 silent start blocks, 48 kHz output');
}
{
  // timeline helpers + the demo's scene switch orders
  const expect = { 5: 17.339, 14: 48.490, 19: 67.513, 23: 81.364, 27: 95.215, 31: 109.047, 35: 122.898, 41: 143.665, 49: 171.348, 51: 178.283 };
  for (const [o, t] of Object.entries(expect)) assert.ok(Math.abs(tl.orderStart(+o) - t) < 0.002, `order ${o} start ${tl.orderStart(+o)}`);
  assert.deepEqual(tl.positionAt(tl.orderStart(14) + 0.001), { order: 14, row: tl.row[Math.floor((tl.orderStart(14) + 0.001) / tl.blockDur) - 1] });
  assert.equal(tl.positionAt(tl.orderStart(14) - 0.05).order, 13);
  assert.ok(Math.abs(tl.duration - 209.434) < 0.01);
  console.log('ok  timeline: scene order thresholds ' + Object.keys(expect).map((o) => `${o}@${tl.orderStart(+o).toFixed(2)}s`).join(' '));
}
{
  // seek: lands on the requested order and keeps playing
  const p = new UsmPlayer(bytes, 44100, { mod }); p.seek(23, 0);
  assert.equal(p.order, 23); const x = p.render(44100); assert.ok(x.left.some((v) => v !== 0));
  assert.ok(p.order >= 23 && p.order <= 24);
  const t0 = tl.orderStart(14), r = new UsmPlayer(bytes, 44100, { mod }); r.seekTime(t0);
  assert.deepEqual({ order: r.order, row: r.row }, tl.positionAt(t0)); assert.deepEqual({ value: r.syncValue, count: r.syncCount }, tl.syncAt(t0));
  assert.ok(r.render(4410).left.some((v) => v !== 0));
  const q = new UsmPlayer(bytes, 44100, { mod }); q.seek(5, 10); assert.equal(q.order, 5); assert.ok(q.row > 10);
  console.log('ok  seek(order,row)');
}
console.log('all usm tests passed');
