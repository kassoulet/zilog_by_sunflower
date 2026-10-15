// "Useless Sound System v1.04" (FreddyV) module player, 'USLM' v4 modules -- port of the music code of ZILOG.EXE.
// Isomorphic ES module (browser + node), no dependencies.  See re/PORT_music.md for the format + function map.
//
//   import { parseUsm, UsmPlayer } from './usm.js';
//   const p = new UsmPlayer(bytes, ctx.sampleRate);        // bytes: Uint8Array of music/ana.u
//   const { left, right } = p.render(1024);                // pull as many frames as you like, it continues
//   p.order, p.row                                         // == DAT_00031514 / DAT_00031518 of the original
//   const tl = p.timeline();  tl.positionAt(12.3) -> {order,row};  tl.duration;  tl.orderStart(5)
//
// AudioWorklet usage: construct the player in the worklet (or post the bytes to it); in process(inputs, outputs)
// call `const {left,right} = player.render(128)` (render() allocates two Float32Array(128); use renderInto(l, r, n)
// to avoid allocations) and copy to outputs[0][0], outputs[0][1].  Sample-rate conversion is built in (cubic).
//
// What is exact: the sequencer (ticks, rows, orders, every effect handler), envelopes, auto-vibrato, the period /
// frequency maths, the volume / pan maths, the 16.16 nearest-neighbour software mixer incl. loop/pingpong buffer
// layout, the 20 ms block structure (SB16 IRQ: 884 frames @44100 Hz stereo, one block of latency) and the
// 16-bit wrap-around accumulation.  Everything below is a transliteration of the original machine code, the
// original address of each routine is given as 0xNNNNN in the comments.

const SINE = [0, 6, 12, 18, 24, 31, 37, 43, 49, 55, 61, 68, 74, 79, 85, 91, 97, 103, 109, 114, 120, 125, 131, 136, 141, 146, 151, 156, 161, 166, 171, 175, 180, 184, 188, 193, 197, 201, 204, 208, 212, 215, 218, 221, 224, 227, 230, 233, 235, 237, 240, 242, 244, 245, 247, 248, 250, 251, 252, 253, 253, 254, 254, 254, 255, 254, 245, 254, 253, 253, 252, 251, 250, 248, 247, 245, 244, 242, 240, 237, 235, 233, 230, 227, 224, 221, 218, 215, 212, 208, 204, 201, 197, 193, 188, 184, 180, 175, 171, 166, 161, 156, 151, 146, 141, 136, 131, 125, 120, 114, 109, 103, 97, 91, 85, 79, 74, 68, 61, 55, 49, 43, 37, 31, 24, 18, 12, 6]; // 0x3399c (note the original's typo at [66]=245)
// Amiga-style period table (0x36eb2, 132 words) -- only used by non-linear samples
const PERIODS = [54784, 51712, 48768, 46080, 43392, 40960, 38656, 36480, 34432, 32512, 30720, 28992, 27392, 25856, 24384, 23040, 21696, 20480, 19328, 18240, 17216, 16256, 15360, 14496, 13696, 12928, 12192, 11520, 10848, 10240, 9664, 9120, 8608, 8128, 7680, 7248, 6848, 6464, 6096, 5760, 5424, 5120, 4832, 4560, 4304, 4064, 3840, 3624, 3424, 3232, 3048, 2880, 2712, 2560, 2416, 2280, 2152, 2032, 1920, 1812, 1712, 1616, 1524, 1440, 1356, 1280, 1208, 1140, 1076, 1016, 960, 906, 856, 808, 762, 720, 678, 640, 604, 570, 538, 508, 480, 453, 428, 404, 381, 360, 339, 320, 302, 285, 269, 254, 240, 226, 214, 202, 190, 180, 170, 160, 151, 143, 135, 127, 120, 113, 107, 101, 95, 90, 85, 80, 75, 71, 67, 63, 60, 56, 53, 50, 47, 45, 42, 40, 37, 35, 33, 31, 30, 28];
// 2^x fixed point tables used by the linear-frequency path (0x34881, 0x348a1, 0x348c1, 0x34901)
const EXP_A = [32768, 32798, 32827, 32857, 32887, 32916, 32946, 32976, 33005, 33035, 33065, 33094, 33125, 33155, 33185, 33215];
const EXP_B = [32768, 33245, 33728, 34219, 34716, 35221, 35733, 36254, 36781, 37315, 37859, 38409, 38968, 39535, 40110, 40693];
const EXP_C = [32768, 41285, 52016, 65536, 82570, 104032, 131072, 165140, 208063, 262144, 330281, 416128, 524288, 660561, 832255, 1048576];
const EXP_D = [32768, 1321123, 53264341, 2147483648];

// T0[cmd] / TK[cmd]: tick-0 and tick>0 effect handlers by original address (tables at 0x334e7 / 0x335f7)
const T0 = [0x32a8f, 0x32b3c, 0x32b47, 0x32b52, 0x32b7b, 0x32c13, 0x32c13, 0x32bc5, 0x32be4, 0x32bff, 0x32c13, 0x32d61, 0x32d71, 0x32d7d, 0x32a4a, 0x32a83, 0x32daa, 0x32db0, 0x32a4a, 0x32a4a, 0x32dc5, 0x32dda, 0x32a4a, 0x32a4a, 0x32a4a, 0x32ddf, 0x32a4a, 0x32dea, 0x32a4a, 0x32e48, 0x32a4a, 0x32a4a, 0x32fc4, 0x32e65, 0x32a4a, 0x32a4a, 0x32a4a, 0x32ec5, 0x32ef1, 0x32a4a, 0x32f1b, 0x32a4a, 0x32f22, 0x32f65, 0x32bf0, 0x32dc5, 0x32f6c, 0x32f96, 0x32dc5, 0x32dc5, 0x32fbe, 0x32fc4, 0x32a4b, 0x32a65, 0x32d8a, 0x32a51, 0x32c2e, 0x32aa2, 0x32aa2, 0x32aa2, 0x32c2e, 0x32c2e, 0x32dbb, 0x32c8d, 0x32a4a, 0x32e0b, 0x32b7b, 0x32cfa];
const TK = [0x33005, 0x33044, 0x33079, 0x33099, 0x330f4, 0x33131, 0x3313b, 0x33142, 0x32a4a, 0x32a4a, 0x33192, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x331eb, 0x32a4a, 0x32a4a, 0x33228, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x3323c, 0x32a4a, 0x3328b, 0x32a4a, 0x33316, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x33344, 0x32a4a, 0x32a4a, 0x33376, 0x33392, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32a4a, 0x32fd0, 0x33192, 0x33079, 0x33044, 0x33099, 0x3313b, 0x33131, 0x32a4a, 0x331c2, 0x32a4a, 0x33269, 0x330f4, 0x331eb];
// volume-column handlers (tables at 0x33707 / 0x3372f), column type = (byte-0x60)>>4
const V0 = [0x333d5, 0x333d5, 0x333dc, 0x333f6, 0x33412, 0x33421, 0x33433, 0x333d5, 0x333d5, 0x33443];
const VK = [0x3346f, 0x3348d, 0x32a4a, 0x32a4a, 0x32a4a, 0x330f4, 0x32a4a, 0x334ad, 0x334ca, 0x33099];

export const BLOCK_FRAMES = 884;        // frames per SB IRQ block at 44100 Hz ((44100/50+3)&~3), 20.045 ms
export const MIX_RATE = 44100;          // rate the original mixes at (SB16 autodetect, 0x3813e table)
export const IRQ_UNITS = 0x5d37;        // PIT units credited to the sequencer per IRQ block (ISR @0x394e6)
const TEMPO_K = 0x5b084c;               // tick length = 5964876 / (2*tempo)  (func_32a65)
const NCH_MAX = 64;
const clamp40 = (a) => (a > 0x40 ? 0x40 : a);
const MIX_GAIN = 200;                   // 0xc8, call 0x3409e(0xc8) from main -> volume table scale (func_399bd)

const u16 = (b, o) => b[o] | b[o + 1] << 8;
const u32 = (b, o) => (b[o] | b[o + 1] << 8 | b[o + 2] << 16 | b[o + 3] << 24) >>> 0;
const str = (b, o, n) => { let s = ''; for (let i = 0; i < n && b[o + i]; i++) s += String.fromCharCode(b[o + i]); return s; };

/** Parse a 'USLM' v4 module (header, orders, patterns, samples, instruments).  Pure data, no state.
 *  @param {Uint8Array} bytes @returns {object} */
export function parseUsm(bytes) {
  const b = bytes;
  if (u32(b, 0) !== 0x4d4c5355) throw new Error('USM: bad magic (expected USLM)');
  if (u16(b, 4) !== 4) throw new Error('USM: unsupported version ' + u16(b, 4));
  const m = {
    title: str(b, 6, 32), flags: u16(b, 0x26), minPeriod: u16(b, 0x2a), maxPeriod: u16(b, 0x2c), nChannels: u16(b, 0x2e),
    nPatterns: u16(b, 0x30), nSamples: u16(b, 0x32), nInstruments: u16(b, 0x34), orderLen: u16(b, 0x36), restartOrder: u16(b, 0x38),
    initSpeed: b[0x3a], initTempo: b[0x3b], globalVol: b[0x3c], orders: b.subarray(0x3e, 0x3e + 0x100),
    chanPan: b.subarray(0x13e, 0x17e), chanVol: b.subarray(0x17e, 0x1be),
    instMode: (u16(b, 0x26) & 2) !== 0, patterns: [], samples: [], instruments: [],
  };
  if (m.nChannels > 0x40) throw new Error('USM: too many channels');
  for (let i = 0; i < 256; i++) {
    const p = u32(b, 0x1be + 4 * i);
    m.patterns.push(p ? { off: p, rows: u16(b, p + 10), data: p + 12 } : null);
  }
  for (let i = 0; i < 128; i++) {
    const p = u32(b, 0x5be + 4 * i);
    if (!p) { m.samples.push(null); continue; }
    const s = {
      index: i, off: p, name: str(b, p + 4, 28), len: u32(b, p + 0x24), loopStart: u32(b, p + 0x28), loopEnd: u32(b, p + 0x2c),
      f38: b[p + 0x38], f39: b[p + 0x39], defVol: b[p + 0x3a], gvol: b[p + 0x3b], defPan: b[p + 0x3c], transpose: b[p + 0x3d],
      c2: u32(b, p + 0x3e), dataOff: u32(b, p + 0x42),
      avWave: b[p + 0x46], avSweep: b[p + 0x47], avDepth: b[p + 0x48], avRate: b[p + 0x49],
      data: null, dev: null, devEnd: 0, devWrap: 0,
    };
    // func_322f0: samples flagged 'present' (bit0) are delta-coded signed 8 bit -> running sum
    if (s.f39 & 1) {
      const d = new Int8Array(s.len);
      let acc = 0;
      for (let k = 0; k < s.len; k++) { acc = (acc + b[s.dataOff + k]) & 255; d[k] = acc << 24 >> 24; }
      s.data = d;
      buildDeviceBuffer(s);
    }
    m.samples.push(s);
  }
  for (let i = 0; i < 128; i++) {
    const p = u32(b, 0x7be + 4 * i);
    if (!p) { m.instruments.push(null); continue; }
    const env = (o) => {
      const n = b[p + o + 1], pts = [];
      for (let k = 0; k < 12; k++) pts.push([u16(b, p + o + 5 + 4 * k), u16(b, p + o + 7 + 4 * k)]);
      return { flags: b[p + o], n, sustain: b[p + o + 2], loopStart: b[p + o + 3], loopEnd: b[p + o + 4], pts };
    };
    m.instruments.push({
      index: i, off: p, name: str(b, p + 4, 28), map: b.subarray(p + 0x1f, p + 0x1f + 0x79), fadeout: u16(b, p + 0x2a),
      vol: env(0xa4), pan: env(0xd9),
    });
  }
  return m;
}

// func_39ae7 (SB driver 'upload sample'): copies the data into mixer memory.  Looped samples are cut at the loop end, a
// ping-pong loop gets its reversed loop appended, and 0x200 bytes of the (cyclic) loop continuation are appended so the
// mixer can run past the loop end for up to 64 frames before the (chunked) wrap check fires.
function buildDeviceBuffer(s) {
  const loop = (s.f38 & 8) !== 0, pp = loop && (s.f38 & 0x10) !== 0;
  const len = loop ? s.loopEnd : s.len, ls = s.loopStart, ll = s.loopEnd - s.loopStart;
  const dev = new Int8Array(len + (pp ? ll : 0) + 0x200);
  dev.set(s.data.subarray(0, Math.min(len, s.data.length)));
  s.devEnd = len; s.devWrap = 0;
  if (loop) {
    let cyc = ll, w = len;
    if (pp) { for (let k = 0; k < ll; k++) dev[len + k] = s.data[len - 1 - k]; cyc = 2 * ll; w = len + ll; s.devEnd = len + ll; s.devWrap = 2 * ll; }
    else s.devWrap = ll;
    for (let j = 0, o = w; j < 0x200 && cyc > 0; j++, o++) dev[o] = dev[ls + (j % cyc)];
  }
  s.dev = dev;
}

// func_399bd: volume x sample table, vol 0..64 -> Int16 (idiv truncates toward zero)
function buildVolTable(gain) {
  const t = new Int16Array(65 * 256), ecx = (Math.floor(0x3e800 / gain)) * 64;
  for (let v = 0; v <= 64; v++) for (let a = 0; a < 256; a++) t[v * 256 + a] = Math.trunc((a << 24 >> 24) * v * 65536 / ecx);
  return t;
}
const VOLTAB = buildVolTable(MIX_GAIN);

// func_34911: 2^(x/768) style fixed point product of four small tables
function expTab(x) {
  const a = EXP_D[(x >>> 12) & 3], c = EXP_C[(x >>> 8) & 15], d = EXP_B[(x >>> 4) & 15], e = EXP_A[x & 15];
  let r = Math.floor((a * c) / 32768) >>> 0;            // mul edx; shrd eax,edx,15  (64 bit product, keep low 32)
  r = Math.floor((r * d) / 32768) >>> 0;
  r = Math.floor((r * e) / 32768) >>> 0;
  return r;
}

export class UsmPlayer {
  /** @param {Uint8Array} bytes the .u file  @param {number} sampleRate output rate (mixing is always 44100 internally) */
  constructor(bytes, sampleRate = 44100, opts = {}) {
    this.bytes = bytes; this.mod = opts.mod || parseUsm(bytes); this.sampleRate = sampleRate;
    this.opts = opts;
    this.reset();
  }

  // ------------------------------------------------------------------ state
  reset() {
    const m = this.mod, N = NCH_MAX;
    this.nch = m.nChannels;
    const u8 = () => new Uint8Array(N), u16a = () => new Uint16Array(N);
    // --- sequencer globals (0x314f0..0x3152f) ---
    this.minPer = m.minPeriod; this.maxPer = m.maxPeriod; this.flags = m.flags;
    this.tickLen = 0; this.tempo = 0; this.speed = 0; this.tickAcc = 0;   // 31500, 31508, 31509, 31504
    this.tickInRow = 0; this.tickNo = 0;                                  // 3150a, 3150b
    this.patRef = null; this.rowPtr = 0;                                  // 3150c, 31510
    this.order = 0; this.patNo = 0; this.row = 0; this.nRows = 0;         // 31514, 31516, 31518, 3151a
    this.patDelay = 0; this.nextOrder = 0; this.nextRow = 0;    // 3151c, 3151d, 3151f (zeroed by the loader: start at order 0 row 0)
    this.cellInst = 0; this.cellNote = 0; this.cellVol = 0; this.cellVolType = 0xff; this.cellVolPar = 0; this.cellCmd = 0; this.cellPar = 0; this.newInst = 0;
    this.loopFlag = 0; this.syncCount = 0; this.syncValue = 0;            // 314f5, 314f0, 314f4
    this.gvol = 0;                                                        // 3646d (global volume, 0..0x80)
    // --- per channel sequencer arrays (0x31530...) ---
    this.curInst = u8(); this.lastNote = u8(); this.cmdPrev = u8().fill(0); this.volPrev = u8(); this.vol = u8();
    this.basePeriod = u16a(); this.pan316f0 = u8(); this.cNote = u8(); this.cInst = u8(); this.cVol = u8();
    this.m317f0 = u8(); this.arpPar = u8(); this.arpCnt = u8(); this.upMem = u8(); this.dnMem = u8(); this.tpSpeed = u8(); this.tpTarget = u16a();
    this.vibWave = u8(); this.vibSpeed = u8(); this.vibDepth = u8(); this.vibPos = u8();
    this.tremWave = u8(); this.tremSpeed = u8(); this.tremDepth = u8(); this.tremPos = u8();
    this.vsMem = u8(); this.cvsMem = u8(); this.gvsMem = u8(); this.psMem = u8();
    this.rtInt = u8(); this.rtType = u8(); this.rtCnt = u8(); this.trCnt = u8(); this.trTot = u8(); this.trOn = u8();
    this.fvUp = u8(); this.fvDn = u8(); this.fpUp = u8(); this.fpDn = u8(); this.xfpUp = u8(); this.xfpDn = u8();
    this.loopRow = u8(); this.loopCnt = u8(); this.delayPar = u8();
    this.m320b0 = u8(); this.m320f0 = u8(); this.m32130 = u8(); this.m32170 = u8(); this.m321b0 = u8(); this.m321f0 = u8(); this.m32270 = u8(); this.m322b0 = u8();
    // --- player-side (mixer) arrays (0x36472...) ---
    this.mflags = u16a(); this.period = u16a(); this.panSet = u8(); this.chvol = u8(); this.noteVol = u8();
    this.volOut = u8(); this.panOut = u8(); this.freq = new Uint32Array(N); this.fade = u16a(); this.envPosV = u16a(); this.envFrV = u16a();
    this.envValV = u8(); this.envPosP = u16a(); this.envFrP = u16a(); this.envValP = u8(); this.avPos = u8(); this.avSweepCnt = u8();
    this.avOff = new Int16Array(N); this.smp = new Array(N).fill(null); this.inst = new Array(N).fill(null);
    this.pos = new Int32Array(N); this.frac = u16a(); this.stepF = u16a(); this.stepI = u16a(); this.volL = u8(); this.volR = u8();
    this.carry = false;
    // --- load (func_32406) ---
    for (let c = 0; c < this.nch; c++) {
      let p = m.chanPan[c]; if (p > 0x7f) p -= 0x80; if (p === 100) p = 0x40;
      this.setPan(c, p === 0x40 ? 0xff : (p << 2) & 0xff);
      this.pan316f0[c] = this.panSet[c];
    }
    for (let c = 0; c < this.nch; c++) this.setChanVol(c, m.chanVol[c]);
    this.setGlobalVol(m.globalVol);
    this.setTempo(m.initTempo);
    this.speed = m.initSpeed; this.tickInRow = (this.speed - 1) & 255;
    this.tickAcc = 0;
    // block/output state
    this.blockNo = 0; this.finished = false; this.outBlock = 0; this.outPos = BLOCK_FRAMES;
    this.blkL = new Float32Array(BLOCK_FRAMES); this.blkR = new Float32Array(BLOCK_FRAMES);
    this.acc = new Int32Array(BLOCK_FRAMES * 2);
    this.rs = { pos: 0, hl: new Float64Array(4), hr: new Float64Array(4), started: false };
    this.muteMix = false;
  }

  get tick() { return this.tickNo; }
  /** time (s) of the next IRQ block boundary */
  get time() { return this.blockNo * BLOCK_FRAMES / MIX_RATE; }

  // ------------------------------------------------------------------ small mixer-side setters
  setPan(c, a) { this.panSet[c] = a; this.mflags[c] |= 0x80; }                         // 0x34348
  setVol(c, a) { if (a > 0x40) a = 0x40; this.noteVol[c] = a; this.mflags[c] |= 0x40; } // 0x3432a
  setChanVol(c, a) { if (a > 0x40) a = 0x40; this.chvol[c] = a; this.mflags[c] |= 0x40; } // 0x340e3
  setGlobalVol(a) { if (a > 0x80) a = 0x80; this.gvol = a; for (let c = 0; c < this.nch; c++) this.mflags[c] |= 0x40; } // 0x340ba
  setTempo(a) { if (a) { this.tempo = a; this.tickLen = Math.floor(TEMPO_K / (a * 2)); } }  // 0x32a65
  keyCut(c) { this.mflags[c] |= 4; }                                                     // 0x3435a
  keyOff(c) { const i = this.inst[c]; if (i) this.mflags[c] |= 8; }                      // 0x34365
  noteOff(c) { const i = this.inst[c]; if (!i || !(i.vol.flags & 1)) this.mflags[c] |= 4; else this.mflags[c] |= 8; } // 0x3437a

  // 0x342cb: clamp the period to [min,max], store as playing period; carry set when clamped
  setPeriod(c, ax) {
    ax &= 0xffff; let cl = false;
    const sax = ax << 16 >> 16;
    if (sax < (this.minPer << 16 >> 16)) { ax = (this.minPer & 0xff00) | 1; cl = true; }
    else if (sax > (this.maxPer << 16 >> 16)) { ax = (this.maxPer & 0xff00) | 1; cl = true; }
    if (this.smp[c]) { this.period[c] = ax; this.mflags[c] |= 0x20; this.carry = cl; } else this.carry = false;
    return ax;
  }

  // 0x34826: note (1-based) -> period, -1 when impossible (carry)
  periodFor(sp, note) {
    if (!sp || (note & 0xff) === 0) return -1;
    const al = (sp.transpose + ((note - 1) & 0xff)) & 0xff;
    if (al >= 0x84) return -1;
    if (sp.f39 & 8) return (0x2100 - (al << 6) - sp.c2) >>> 0;
    let e = PERIODS[al];
    if ((sp.c2 & 0xffff) >= 0x64 && (sp.c2 & 0xffff) !== 0x20ab) e = Math.floor(e * 0x20ab / sp.c2);
    return e;
  }

  // 0x340fa: start a note on channel c.  inst is 0-based.  returns true on carry (failure)
  trigger(c, inst, note) {
    const m = this.mod; let eax = inst;
    this.mflags[c] |= 4;
    if (note === 0 || note > 0x78) return true;
    if (m.instMode) {
      if (eax >= 0x80) return true;
      const ip = m.instruments[eax]; if (!ip) return true;
      this.inst[c] = ip;
      eax = ip.map[note]; if (!eax) return true;
      eax--;
    }
    if (eax >= 0x80) return true;
    const sp = m.samples[eax]; if (!sp) return true;
    this.smp[c] = sp;
    const per = this.periodFor(sp, note);
    if (per < 0) return true;
    this.setPeriod(c, per);
    if (sp.f39 & 1) { this.pos[c] = 0; this.mflags[c] |= 0x52; }
    return false;
  }

  // 0x3417e: reset envelopes etc. on instrument column
  resetVoiceState(c) {
    this.fade[c] = 0x8000; this.envPosV[c] = 0; this.envFrV[c] = 0; this.envValV[c] = 0; this.envPosP[c] = 0; this.envFrP[c] = 0; this.envValP[c] = 0;
    this.avPos[c] = 0; this.avSweepCnt[c] = 0; this.mflags[c] &= 0xfff7;
  }

  // 0x3427b: sample offset -> restart at eax (relative to sample start)
  setOffset(c, eax) {
    const sp = this.smp[c];
    if (sp && (sp.f39 & 1)) { this.pos[c] = eax | 0; this.mflags[c] |= 0x56; }
  }

  // 0x341cc: set envelope position
  setEnvPos(c, al) {
    const ip = this.inst[c]; if (!ip) return;
    const v = ip.vol;
    if (v.flags & 1) {
      let ecx = v.n, edx;
      for (;;) {
        edx = ecx ? v.pts[ecx - 1][0] : 0;                  // word [edi+ecx*4+0xa5]
        if (edx > al) { ecx--; if (ecx !== 0) continue; break; }
        edx = al - edx; ecx--; break;
      }
      this.envPosV[c] = ecx & 0xffff; this.envFrV[c] = edx & 0xffff;
    }
    const p = ip.pan;
    if (!(p.flags & 1)) {
      let ecx = p.n, edx;
      for (;;) {
        edx = ecx ? p.pts[ecx - 1][0] : 0;
        if (edx > al) { ecx--; if (ecx !== 0) continue; break; }
        edx = al - edx; ecx--; break;
      }
      this.envPosP[c] = ecx & 0xffff; this.envFrP[c] = edx & 0xffff;
    }
  }

  // 0x347c4: LFO. returns [value(int16), newPos]
  lfo(wave, speed, depth, pos) {
    let ax;
    if (wave === 0) ax = SINE[pos & 0x7f];
    else if (wave === 1) { ax = pos <= 0x7f ? pos << 1 : -(((pos - 0x100) << 1)); }
    else if (wave === 4) { ax = pos <= 0x7f ? -(pos << 1) : (pos - 0x100) << 1; }
    else ax = 0xff;
    if (pos > 0x7f) ax = -ax;
    const v = Math.imul(ax << 16 >> 16, depth << 16 >> 16) << 16 >> 16;   // imul dx -> low word
    return [v, (pos + speed) & 0xff];
  }

  // ------------------------------------------------------------------ sequencer (0x3262e and friends)
  seqTick() { // func_3262e
    this.tickInRow = (this.tickInRow + 1) & 255;
    if (this.tickInRow === this.speed) {
      this.tickInRow = 0; this.tickNo = 0;
      if (this.patDelay) { this.patDelay--; this.runTickEffects(); return; }
      if (this.nextOrder === 0xffff) {
        if (this.row < this.nRows) { /* stay in pattern */ } else { this.nextRow = 0; this.nextOrder = (this.order + 1) & 0xffff; this.newPattern(); }
      } else this.newPattern();
      if (this.nextRow !== 0xffff) this.seekRow();
      this.readRow();
      this.row = (this.row + 1) & 0xffff;
      return;
    }
    this.runTickEffects();
  }
  runTickEffects() { // 0x326b1
    this.tickNo = (this.tickNo + 1) & 255;
    for (let c = 0; c < this.nch; c++) {
      const v = this.volPrev[c]; if (v < 10) this.hv(VK[v], c, 0, 0);
      const k = this.cmdPrev[c]; if (k < 0x44) this.hv(TK[k], c, 0, k);
    }
  }
  newPattern() { // func_3299e
    const m = this.mod; let o = this.nextOrder;
    if (o >= m.orderLen) { this.loopFlag = 1; this.finished = true; o = m.restartOrder; }
    this.order = o; this.patNo = m.orders[o];
    const p = m.patterns[this.patNo];
    this.patRef = p; this.nRows = p ? p.rows : 0x40;
    this.nextOrder = 0xffff;
  }
  seekRow() { // func_329f9
    const p = this.patRef; let eax = this.nextRow;
    if (!p) { this.rowPtr = 0; this.nextRow = 0xffff; return; }
    if (p.rows <= eax) eax = 0;
    this.row = eax;
    let e = p.data; const b = this.bytes, n = this.nch;
    for (let r = eax; r > 0; r--) {
      let k = n;
      for (;;) { if (b[e] === 0xfc) { e++; break; } e += 5; if (--k === 0) break; }
    }
    this.rowPtr = e; this.nextRow = 0xffff;
  }
  readRow() { // func_326e9
    const b = this.bytes, n = this.nch;
    let esi = this.rowPtr, c = 0;
    for (; c < n; c++) {
      if (!esi || b[esi] === 0xfc) { if (esi) esi++; this.rowPtr = esi; for (; c < n; c++) { this.cmdPrev[c] = 0xff; this.volPrev[c] = 0xff; } return; }
      this.rowPtr = esi + 5;
      const note = b[esi], inst = b[esi + 1], vc = b[esi + 2], cmd0 = b[esi + 3], par = b[esi + 4];
      esi += 5;
      this.cellNote = note; this.cNote[c] = note; this.cellInst = inst; this.cInst[c] = inst;
      this.cellCmd = cmd0; this.cellPar = par; if (cmd0 === 0 && par === 0) this.cellCmd = 0xff;
      this.cellVolType = 0xff; this.cellVol = vc;
      if (vc > 0x50) { this.cellVol = 0; const t = (vc - 0x60) & 0xffff; this.cellVolType = t >> 4; this.cellVolPar = t & 0xf; }
      this.cVol[c] = this.cellVol & 0xff;
      if (this.cmdPrev[c] !== (this.cellCmd & 0xff)) {                 // restore the un-vibrato'd period
        if (this.period[c] !== this.basePeriod[c]) this.setPeriod(c, this.basePeriod[c]);
      }
      if (this.cellCmd !== 0x31) this.noteColumn(c);
      this.volPrev[c] = this.cellVolType & 0xff;
      if (this.cellVolType < 10) this.hv(V0[this.cellVolType], c, this.cellVolPar, 0);
      let cmd = this.cellCmd, par2 = this.cellPar;
      if (par2 === 0 && cmd === 0) cmd = 0xff;
      if (cmd < 0x44) this.hv(T0[cmd], c, par2, cmd);
      this.cmdPrev[c] = cmd & 0xff;
    }
  }
  noteColumn(c) { // func_32858: instrument/note/volume columns
    const m = this.mod;
    this.newInst = 0;
    if (this.cellInst !== 0) {
      this.curInst[c] = this.cellInst; this.resetVoiceState(c); this.newInst = 1;
      this.trCnt[c] = 0;
      if (!(this.flags & 0x80)) this.rtCnt[c] = 0;
      if (this.vibWave[c] < 4) this.vibPos[c] = 0;
      if (this.tremWave[c] < 4) this.tremPos[c] = 0;
    }
    const n = this.cellNote;
    if (n === 0xff) this.noteOff(c);
    else if (n === 0xfe) this.keyCut(c);
    else if (n === 0xfd) this.keyOff(c);
    else if (n !== 0 && this.cellCmd !== 3 && this.cellCmd !== 0x3b && this.cellVolType !== 9) {
      this.lastNote[c] = n;
      const i = this.curInst[c];
      if (i !== 0) { this.trigger(c, i - 1, n); this.basePeriod[c] = this.period[c]; }  // 0x32985
    }
    if (this.newInst) {
      const sp = this.smp[c];
      if (sp) {                                                       // 0x34247 default volume, 0x3425a default pan
        this.vol[c] = sp.defVol; this.setVol(c, sp.defVol);
        if (sp.f39 & 4) { this.pan316f0[c] = sp.defVol; this.setPan(c, sp.defVol); }
        else if (sp.f39 & 2) { this.pan316f0[c] = sp.defPan; this.setPan(c, sp.defPan); }
      }
    }
    if (this.cellVol !== 0) {
      this.cellVol = (this.cellVol - 0x10) & 0xffff; this.vol[c] = this.cellVol & 0xff; this.setVol(c, this.cellVol & 0xff);
    }
  }

  // ------------------------------------------------------------------ effect dispatch
  // hv(addr, channel, param, cmd): run the handler that lives at original address `addr`
  hv(a, c, p, cmd) {
    switch (a) {
      case 0x32a4a: return;
      case 0x32a4b: this.speed = p; return;                                    // set speed
      case 0x32a51: if (p) this.m317f0[c] = p; if (p > 0x20) this.setTempo(p); return; // T: tempo / slide
      case 0x32a65: this.setTempo(p); return;                                  // set tempo
      case 0x32a83: if (p < 0x20) this.speed = p; else this.setTempo(p); return; // F: speed/tempo
      case 0x32a8f: this.arpPar[c] = p; this.arpCnt[c] = 0; return this.hv(0x33005, c, 0, 0); // J: arpeggio
      case 0x32aa2: { // combined 'E/F/G' style porta commands 0x39,0x3a,0x3b
        if (p) this.m320b0[c] = p; p = this.m320b0[c];
        if (cmd === 0x39) {                                                    // 0x32b03
          if (p) this.m32130[c] = p; this.dnMem[c] = 0; p = this.m32130[c];
          const t = p & 0xf0;
          if (t === 0xf0) return this.hv(0x32ef1, c, p & 0xf, 0);
          if (t === 0xe0) return this.hv(0x32e65, c, (p & 0xf) | 0x20, 0);
          return this.hv(0x32b47, c, p, 0);
        }
        if (cmd === 0x3a) {                                                    // 0x32acb
          if (p) this.m320f0[c] = p; this.upMem[c] = 0; p = this.m320f0[c];
          const t = p & 0xf0;
          if (t === 0xf0) return this.hv(0x32ec5, c, p & 0xf, 0);
          if (t === 0xe0) return this.hv(0x32e65, c, (p & 0xf) | 0x10, 0);
          return this.hv(0x32b3c, c, p, 0);
        }
        if (cmd === 0x3b) return this.hv(0x32b52, c, p, 0);
        return;
      }
      case 0x32b3c: if (p) this.upMem[c] = p; return;                          // porta up memory
      case 0x32b47: if (p) this.dnMem[c] = p; return;                          // porta down memory
      case 0x32b52: {                                                          // tone porta
        if (p) this.tpSpeed[c] = p;
        if (this.cellNote !== 0) { const v = this.periodFor(this.smp[c], this.cellNote); this.tpTarget[c] = v < 0 ? 0 : v & 0xffff; }
        return;
      }
      case 0x32b7b: {                                                          // vibrato (4, 0x42)
        let al = p;
        if (al & 0xf0) this.vibSpeed[c] = ((al >> 4) << 2) & 0xff;
        if (al & 0xf) { al &= 0xf; if (cmd !== 0x42) al = (al << 2) & 0xff; if (!(this.flags & 8)) al = (al << 1) & 0xff; this.vibDepth[c] = al; }
        if (this.flags & 8) this.hv(0x330f4, c, 0, 0);
        return;
      }
      case 0x32bc5: if (p & 0xf0) this.tremSpeed[c] = ((p >> 4) << 2) & 0xff; if (p & 0xf) this.tremDepth[c] = p & 0xf; return; // tremolo
      case 0x32be4: this.pan316f0[c] = p; this.setPan(c, p); return;           // set pan
      case 0x32bf0: p = (p << 4) & 0xff; this.pan316f0[c] = p; this.setPan(c, p); return;
      case 0x32bff: if (this.cellNote !== 0) this.setOffset(c, (p << 8) & 0xffff); return; // sample offset
      case 0x32c13: if (p) this.vsMem[c] = p; if (this.flags & 4) this.hv(0x33192, c, 0, 0); return; // volslide
      case 0x32c2e: {                                                          // volslide with fine variants
        if (p) this.m32170[c] = p; this.vsMem[c] = 0; p = this.m32170[c];
        if (p !== 0xf) {
          if ((p & 0xf) !== 0) {
            if ((p & 0xf) === 0xf) return this.hv(0x32f6c, c, p >> 4, 0);
            const bl = p >> 4;
            if (bl !== 0 && bl === 0xf) return this.hv(0x32f96, c, p & 0xf, 0);
          }
        }
        this.vsMem[c] = p; if (this.flags & 4) this.hv(0x33192, c, 0, 0); return;
      }
      case 0x32c8d: {                                                          // channel volume slide
        if (p) this.m321b0[c] = p; this.cvsMem[c] = 0; p = this.m321b0[c];
        if (p !== 0xf && (p & 0xf) !== 0) {
          if ((p & 0xf) === 0xf) { const bl = p >> 4; this.setChanVol(c, Math.min(0x40, this.chvol[c] + bl)); return; }
          const bl = p >> 4;
          if (bl !== 0 && bl === 0xf) { const d = this.chvol[c] - (p & 0xf); this.setChanVol(c, d < 0 ? 0 : d); return; }
        }
        this.cvsMem[c] = p; return;
      }
      case 0x32cfa: {                                                          // global volume slide
        if (p) this.m321f0[c] = p; this.gvsMem[c] = 0; p = this.m321f0[c];
        if (p !== 0xf && (p & 0xf) !== 0) {
          if ((p & 0xf) === 0xf) { this.setGlobalVol((this.gvol + (p >> 4)) & 0xff); return; }
          const bl = p >> 4;
          if (bl !== 0 && bl === 0xf) { const d = this.gvol - (p & 0xf); this.setGlobalVol(d < 0 ? 0 : d); return; }
        }
        this.gvsMem[c] = p; return;
      }
      case 0x32d61: this.nextOrder = p; this.nextRow = 0; return;              // position jump
      case 0x32d71: this.vol[c] = p; this.setVol(c, p); return;                // set volume
      case 0x32d7d: p = (p >> 4) * 10 + (p & 0xf); // fallthrough: pattern break (BCD)
      case 0x32d8a: this.nextRow = p & 0xffff; if (this.nextOrder === 0xffff) this.nextOrder = (this.order + 1) & 0xffff; return; // (0x36: hex)
      case 0x32daa: this.setGlobalVol(p); return;
      case 0x32db0: if (p) this.gvsMem[c] = p; return;
      case 0x32dbb: if (p <= 0x40) this.setChanVol(c, p); return;
      case 0x32dc5: this.delayPar[c] = p; return this.hv(TK[this.cellCmd & 0xffff], c, 0, this.cellCmd); // 0x14,0x2d,0x30,0x31
      case 0x32dda: return this.setEnvPos(c, p);
      case 0x32ddf: if (p) this.psMem[c] = p; return;                          // pan slide mem
      case 0x32dea: {                                                          // retrigger (with tick)
        if (p & 0xf0) this.rtType[c] = p >> 4; if (p & 0xf) this.rtInt[c] = p & 0xf;
        return this.hv(0x3328b, c, 0, 0);
      }
      case 0x32e0b: {                                                          // retrigger w/ memory (0x41)
        if (p) this.m32270[c] = p; p = this.m32270[c];
        this.rtType[c] = p >> 4; if (p & 0xf) this.rtInt[c] = p & 0xf;
        if (this.cmdPrev[c] !== 0x41) this.rtCnt[c] = 0;
        return this.hv(0x33269, c, 0, 0);
      }
      case 0x32e48: if (p) { const lo = p & 0xf, hi = (p >> 4) + 1; this.trTot[c] = (lo + 1 + hi) & 0xff; this.trOn[c] = hi; } return; // tremor
      case 0x32e65: {                                                          // fine porta (p = 0x1y up / 0x2y down)
        const t = (p >> 4) & 0xf, lo = p & 0xf;
        if (t === 1) { if (lo) this.fpUp[c] = lo; this.basePeriod[c] = this.setPeriod(c, this.basePeriod[c] - this.fpUp[c]); }
        else if (t === 2) { if (lo) this.fpDn[c] = lo; this.basePeriod[c] = this.setPeriod(c, this.basePeriod[c] + this.fpDn[c]); }
        return;
      }
      case 0x32ec5: if (p) this.xfpUp[c] = p; this.basePeriod[c] = this.setPeriod(c, this.basePeriod[c] - (this.xfpUp[c] << 2)); return;
      case 0x32ef1: if (p) this.xfpDn[c] = p; this.basePeriod[c] = this.setPeriod(c, this.basePeriod[c] + (this.xfpDn[c] << 2)); return;
      case 0x32f1b: this.vibWave[c] = p; return;
      case 0x32f22: {                                                          // SBx pattern loop
        if (p === 0) { this.loopRow[c] = this.row & 0xff; return; }
        p = (p + 1) & 0xff;
        if (this.loopCnt[c] === 0) this.loopCnt[c] = p;
        this.loopCnt[c] = (this.loopCnt[c] - 1) & 0xff;
        if (this.loopCnt[c] === 0) return;
        this.nextRow = this.loopRow[c]; this.nextOrder = this.order; return;
      }
      case 0x32f65: this.tremWave[c] = p; return;
      case 0x32f6c: if (p) this.fvUp[c] = p; this.vol[c] = clamp40((this.vol[c] + this.fvUp[c]) & 0xff); this.setVol(c, this.vol[c]); return;
      case 0x32f96: if (p) this.fvDn[c] = p; { const d = this.vol[c] - this.fvDn[c]; this.vol[c] = d < 0 ? 0 : d; } this.setVol(c, this.vol[c]); return;
      case 0x32fbe: this.patDelay = p; return;
      case 0x32fc4: this.syncValue = p; this.syncCount++; return;              // 0x20 / 0x33: demo sync marker
      case 0x32fd0: {                                                          // tempo slide (tick)
        const bl = this.m317f0[c]; if (bl >= 0x20) return;
        let al = this.tempo;
        if (bl < 0xa) { al -= bl & 0xf; if (al < 0) al = 0x20; if (al <= 0x20) al = 0x20; }
        else { al += bl & 0xf; if (al > 255) al = 0xff; }
        this.setTempo(al); return;
      }
      case 0x33005: {                                                          // arpeggio tick
        let al = this.lastNote[c], cl = this.arpCnt[c]; const bl = this.arpPar[c];
        if (cl === 1) al = (al + (bl >> 4)) & 0xff; else if (cl !== 0) al = (al + (bl & 0xf)) & 0xff;
        cl++; if (cl === 3) cl = 0; this.arpCnt[c] = cl;
        const per = this.periodFor(this.smp[c], al);                           // 0x342a0
        if (per >= 0) { this.period[c] = per & 0xffff; this.mflags[c] |= 0x20; }
        return;
      }
      case 0x33044: {                                                          // porta up tick
        this.basePeriod[c] = this.setPeriod(c, this.basePeriod[c] - (this.upMem[c] << 2));
        if (this.carry && (this.flags & 0x10)) this.keyCut(c);
        return;
      }
      case 0x33079: this.basePeriod[c] = this.setPeriod(c, this.basePeriod[c] + (this.dnMem[c] << 2)); return;
      case 0x33099: {                                                          // tone porta tick
        let ax = this.basePeriod[c]; const bx = (this.tpSpeed[c] << 2) & 0xffff, cx = this.tpTarget[c];
        if (cx === 0) return;
        if (ax === cx) return;
        if (ax < cx) { ax = (ax + bx) & 0xffff; if (!(ax <= cx)) ax = cx; }
        else { if (ax > bx) { ax = (ax - bx) & 0xffff; if (!(ax >= cx)) ax = cx; } else ax = cx; }
        this.basePeriod[c] = this.setPeriod(c, ax); return;
      }
      case 0x330f4: {                                                          // vibrato tick
        const [v, np] = this.lfo(this.vibWave[c] & 3, this.vibSpeed[c], this.vibDepth[c], this.vibPos[c]);
        this.vibPos[c] = np; this.setPeriod(c, this.basePeriod[c] + (v >> 8)); return;
      }
      case 0x33131: this.hv(0x33192, c, 0, 0); return this.hv(0x33099, c, 0, 0);
      case 0x3313b: this.hv(0x33192, c, 0, 0); return this.hv(0x330f4, c, 0, 0);
      case 0x33142: {                                                          // tremolo tick
        const [v, np] = this.lfo(this.tremWave[c] & 3, this.tremSpeed[c], this.tremDepth[c], this.tremPos[c]);
        this.tremPos[c] = np; const cx = v >> 6; let al = this.vol[c];
        if (cx >= 0) { al = (al + (cx & 0xff)) & 0xff; if (al > 0x40) al = 0x40; }
        else { al = (al + (cx & 0xff)) & 0xff; if (al > 0x40) al = 0; }
        this.setVol(c, al); return;
      }
      case 0x33192: {                                                          // volume slide tick
        let al = this.vol[c]; const bl = this.vsMem[c];
        if ((bl & 0xf0) === 0) { al -= bl; if (al < 0) al = 0; } else al = clamp40((al + (bl >> 4)) & 0xff);
        this.vol[c] = al; this.setVol(c, al); return;
      }
      case 0x331c2: {                                                          // channel volume slide tick
        let al = this.chvol[c]; const bl = this.cvsMem[c];
        if ((bl & 0xf0) === 0) { al -= bl; if (al < 0) al = 0; } else { al += bl >> 4; if (al > 0x40) al = 0x40; }
        this.setChanVol(c, al); return;
      }
      case 0x331eb: {                                                          // global volume slide tick
        let al = this.gvol, bl = this.gvsMem[c];
        if ((bl & 0xf0) === 0) { if (this.flags & 0x40) bl = (bl << 1) & 0xff; al -= bl; if (al < 0) al = 0; }
        else { bl >>= 4; if (this.flags & 0x40) bl = (bl << 1) & 0xff; al = (al + bl) & 0xff; }
        this.setGlobalVol(al); return;
      }
      case 0x33228: if (this.delayPar[c] === this.tickNo) this.noteOff(c); return;       // key-off at tick
      case 0x3323c: {                                                          // pan slide tick
        let al = this.panSet[c]; const bl = this.psMem[c];
        if ((bl & 0xf0) === 0) { al -= bl; if (al < 0) al = 0; } else { al += bl >> 4; if (al > 0xff) al = 0xff; }
        this.pan316f0[c] = al; this.setPan(c, al); return;
      }
      case 0x33269: {                                                          // retrigger tick (0x41)
        const bl = this.rtInt[c], al = this.rtCnt[c];
        if (al < bl) { this.rtCnt[c] = al + 1; return; }
        this.rtCnt[c] = 0; return this.retrigBody(c);
      }
      case 0x3328b: {                                                          // retrigger tick (0x1b)
        this.rtCnt[c] = (this.rtCnt[c] + 1) & 0xff;
        if (this.rtInt[c] !== this.rtCnt[c]) return;
        this.rtCnt[c] = 0; return this.retrigBody(c);
      }
      case 0x33316: {                                                          // tremor tick
        let bl = this.trCnt[c], al = this.vol[c];
        if (!(bl < this.trOn[c])) al = 0;
        bl = (bl + 1) & 0xff; if (!(bl < this.trTot[c])) bl = 0;
        this.trCnt[c] = bl; this.setVol(c, al); return;
      }
      case 0x33344: {                                                          // retrigger every n ticks (Qxy-like)
        const t = this.tickNo, d = this.delayPar[c];
        if (t !== d) { if (t === 0) return; if (d === 0) return; if (t % d !== 0) return; }
        this.setOffset(c, 0); return;
      }
      case 0x33376: if (this.delayPar[c] === this.tickNo) { this.vol[c] = 0; this.setVol(c, 0); } return;   // note cut
      case 0x33392: {                                                          // note delay
        if (this.delayPar[c] !== this.tickNo) return;
        this.cellNote = this.cNote[c]; this.cellInst = this.cInst[c]; this.cellVol = this.cVol[c]; this.cellCmd = 0xff;
        this.noteColumn(c); return;
      }
      // --- volume column ---
      case 0x333d5: this.m322b0[c] = p; return;
      case 0x333dc: { const d = this.vol[c] - p; this.vol[c] = d < 0 ? 0 : d; this.setVol(c, this.vol[c]); return; }
      case 0x333f6: { const v = clamp40((this.vol[c] + p) & 0xff); this.vol[c] = v; this.setVol(c, v); return; }
      case 0x33412: if (p === 0) { if (this.flags & 8) this.hv(0x330f4, c, 0, 0); } else this.vibSpeed[c] = p; return;
      case 0x33421: if (p === 0) { if (this.flags & 8) this.hv(0x330f4, c, 0, 0); } else this.vibDepth[c] = (p << 2) & 0xff; return;
      case 0x33433: { const v = (p << 4) & 0xff; this.pan316f0[c] = v; this.setPan(c, v); return; }
      case 0x33443: {
        p = (p << 4) & 0xff; if (p) this.tpSpeed[c] = p;
        if (this.cellNote !== 0) { const v = this.periodFor(this.smp[c], this.cellNote); this.tpTarget[c] = v < 0 ? 0 : v & 0xffff; }
        return;
      }
      case 0x3346f: { const d = this.vol[c] - this.m322b0[c]; this.vol[c] = d < 0 ? 0 : d; this.setVol(c, this.vol[c]); return; }
      case 0x3348d: { const v = clamp40((this.vol[c] + this.m322b0[c]) & 0xff); this.vol[c] = v; this.setVol(c, v); return; }
      case 0x334ad: { const d = this.panSet[c] - this.m322b0[c]; this.setPan(c, d < 0 ? 0 : d); return; }
      case 0x334ca: { const v = this.panSet[c] + this.m322b0[c]; this.setPan(c, v > 0xff ? 0xff : v); return; }
      default: throw new Error('USM: unhandled handler 0x' + a.toString(16));
    }
  }
  retrigBody(c) { // 0x332a6: restart sample, then volume change by type
    this.setOffset(c, 0);
    let al = this.vol[c]; const cl = this.rtType[c];
    if (cl > 8) {
      if (cl < 0xe) { al = (al + (1 << (cl - 9))) & 0xff; }
      else if (cl === 0xe) { const ah = al; al = ((al << 1) & 0xff); al = (al + ah) & 0xff; al >>= 1; }
      else al = (al << 1) & 0xff;
      if (al > 0x40) al = 0x40;
    } else if (cl === 8 || cl === 0) return;
    else if (cl < 6) { al = (al - (1 << (cl - 1))) & 0xff; if (al & 0x80) al = 0; }   // sub al,bl; jns
    else if (cl === 6) al = Math.floor(((al << 1) & 0xff) / 3);
    else al >>= 1;
    this.vol[c] = al; this.setVol(c, al);
  }

  // ------------------------------------------------------------------ envelopes + autovibrato (func_343a6, once per tick)
  envTick() {
    for (let c = 0; c < this.nch; c++) {
      const ip = this.inst[c];
      if (!ip || !(this.mflags[c] & 2)) continue;
      const v = ip.vol;
      if (v.flags & 1) {
        if (this.mflags[c] & 8) {
          let ax = this.fade[c] - ip.fadeout;
          if (ax < 0) { ax = 0; this.mflags[c] |= 4; }
          this.fade[c] = ax;
        }
        if (this.envFrV[c] === 0) {
          let dl = this.envPosV[c];
          let skip = false;
          if ((v.flags & 2) && dl === v.sustain && (this.mflags[c] & 8)) skip = true;
          if (!skip && (v.flags & 4) && dl === v.loopEnd) { dl = v.loopStart; this.envPosV[c] = dl; }
        }
        const idx = this.envPosV[c];
        if (idx + 1 === v.n) { this.envValV[c] = v.pts[idx][1] & 0xff; }
        else {
          const x0 = v.pts[idx][0], y0 = v.pts[idx][1], x1 = v.pts[idx + 1][0], y1 = v.pts[idx + 1][1];
          const seg = (x1 - x0) & 0xffff;
          const prod = ((((y1 - y0) << 16) >> 16) * (this.envFrV[c] << 16 >> 16)) | 0;
          this.envValV[c] = (Math.trunc(prod / (seg << 16 >> 16)) + y0) & 0xff;
          const hold = this.envFrV[c] === 0 && (v.flags & 2) && !(this.mflags[c] & 8) && this.envPosV[c] === v.sustain;
          if (!hold) {
            let f = this.envFrV[c] + 1;
            if (f >= seg) { f = 0; this.envPosV[c]++; }
            this.envFrV[c] = f;
          }
        }
        this.mflags[c] |= 0x40;
      }
      const p = ip.pan;
      if (p.flags & 1) {
        if (this.envFrP[c] === 0) {
          let dl = this.envPosP[c];
          let skip = false;
          if ((p.flags & 2) && dl === p.sustain && (this.mflags[c] & 8)) skip = true;
          if (!skip && (p.flags & 4) && dl === p.loopEnd) { dl = p.loopStart; this.envPosP[c] = dl; }
        }
        const idx = this.envPosP[c];
        if (idx + 1 === p.n) { this.envValP[c] = p.pts[idx][1] & 0xff; }
        else {
          const x0 = p.pts[idx][0], y0 = p.pts[idx][1], x1 = p.pts[idx + 1][0], y1 = p.pts[idx + 1][1];
          const seg = (x1 - x0) & 0xffff;
          const prod = ((((y1 - y0) << 16) >> 16) * (this.envFrP[c] << 16 >> 16)) | 0;
          this.envValP[c] = (Math.trunc(prod / (seg << 16 >> 16)) + y0) & 0xff;
          const hold = this.envFrP[c] === 0 && (p.flags & 2) && !(this.mflags[c] & 8) && this.envPosP[c] === p.sustain;
          if (!hold) {
            let f = this.envFrP[c] + 1;
            if (f >= seg) { f = 0; this.envPosP[c]++; }
            this.envFrP[c] = f;
          }
        }
        this.mflags[c] |= 0x80;
      }
    }
    for (let c = 0; c < this.nch; c++) {                                   // 0x34634 sample auto-vibrato
      const sp = this.smp[c];
      if (!sp || !(this.mflags[c] & 2) || !sp.avDepth) continue;
      let [ax, np] = this.lfo(sp.avWave, sp.avRate, sp.avDepth, this.avPos[c]);
      this.avPos[c] = np;
      const cl = this.avSweepCnt[c];
      if (cl < sp.avSweep) {
        const prod = Math.imul(ax, cl) | 0;                                // imul cx -> dx:ax
        ax = Math.trunc((prod << 0) / sp.avSweep) & 0xffff; ax = ax << 16 >> 16;
        this.avSweepCnt[c] = cl + 1;
      }
      this.avOff[c] = -(ax >> 8);
      this.mflags[c] |= 0x20;
    }
  }

  // ------------------------------------------------------------------ func_346b1: derive freq / volume / pan
  update() {
    for (let c = 0; c < this.nch; c++) {
      const f = this.mflags[c];
      if (f & 0x20) {
        const per = (this.period[c] + this.avOff[c]) & 0xffff, sp = this.smp[c];   // 0x3495d
        if (sp) {
          if (sp.f39 & 8) this.freq[c] = Math.floor(expTab(((0x2100 - per) >>> 0)) * 0x20ab / 0x100000) >>> 0;
          else if (per > 10) this.freq[c] = Math.floor(0xda7790 / per);
        }
      }
      if (f & 0x40) {
        const ip = this.inst[c], sp = this.smp[c];
        let p = this.noteVol[c] * this.gvol; let sh = 7;
        p *= this.chvol[c]; sh += 6;
        if (f & 8) { p = Math.floor(p * this.fade[c] / 512); sh += 6; }
        if (ip && (ip.vol.flags & 1)) { p *= this.envValV[c]; sh += 6; }
        sh -= 6;
        p = Math.floor(p / 2 ** sh) >>> 0; sh = 6;
        if (sp) { p = p * sp.gvol; sh += 6; }
        this.volOut[c] = Math.floor(p / 2 ** sh) & 0xff;
      }
      if (f & 0x80) {
        let dl = this.panSet[c] << 24 >> 24;
        const ip = this.inst[c];
        if (ip && (ip.pan.flags & 1)) {
          const al = (this.envValP[c] - 0x20) << 24 >> 24, d = (dl ^ (dl >> 8)) << 24 >> 24; // xor dl,dh
          const ax = (al * d) & 0xffff;
          dl = (((ax >> 5) & 0xff) + this.panSet[c]) & 0xff;
        }
        this.panOut[c] = dl & 0xff;
      }
    }
  }

  // ------------------------------------------------------------------ func_39bc0 + mixing loops: render one 20 ms block
  mixBlock() {
    const acc = this.acc; acc.fill(0);
    for (let c = 0; c < this.nch; c++) {
      let f = this.mflags[c];
      if (f & 4) f &= 0xfff9;
      if (f & 0x10) { f = (f & 0xffef) | 2; this.frac[c] = 0; }
      if (f & 0x20) {
        const q = Math.floor(this.freq[c] * 65536 / MIX_RATE);            // div ecx -> 32 bit quotient
        this.stepF[c] = q & 0xffff; this.stepI[c] = (q >>> 16) & 0xffff;
      }
      if (f & 0xc0) {
        const bl = this.volOut[c], ecx = this.panOut[c];
        this.volR[c] = ((((ecx + 1) * bl) >> 8)) & 0xff;                  // 0x39976
        this.volL[c] = ((((0x100 - ecx) * bl) >> 8)) & 0xff;              // 0x39996
      }
      f &= 0xff1f;
      this.mflags[c] = f;
      if (f & 2) this.mixVoice(c);
    }
    const out = this.blkL, outR = this.blkR;
    for (let i = 0; i < BLOCK_FRAMES; i++) { out[i] = (acc[2 * i] << 16 >> 16) / 32768; outR[i] = (acc[2 * i + 1] << 16 >> 16) / 32768; }
  }

  // func_39e50 + 0x3a5d6 (stereo chunked loop, nearest neighbour, 16.16 position)
  mixVoice(c) {
    const sp = this.smp[c];
    if (!sp || !sp.dev) { if (!this.opts.noVoiceEnd) this.mflags[c] &= 0xfffd; return; }   // empty sample: the original ends the voice at once
    const dev = sp.dev, end = sp.devEnd, wrap = sp.devWrap;
    const tl = VOLTAB.subarray(this.volL[c] * 256, this.volL[c] * 256 + 256), tr = VOLTAB.subarray(this.volR[c] * 256, this.volR[c] * 256 + 256);
    const sF = this.stepF[c], sI = this.stepI[c], acc = this.acc, mix = !this.muteMix, noEnd = this.opts.noVoiceEnd;
    let pos = this.pos[c], frac = this.frac[c], rem = BLOCK_FRAMES >> 2, o = 0;
    const run = (iters) => {
      const n = iters * 4;
      if (mix) {
        for (let k = 0; k < n; k++) {
          const b = pos < dev.length ? dev[pos] & 255 : 0;
          acc[o++] += tl[b]; acc[o++] += tr[b];
          frac += sF; if (frac > 0xffff) { frac &= 0xffff; pos++; } pos += sI;
        }
      } else {
        const t = frac + sF * n; pos += sI * n + Math.floor(t / 65536); frac = t % 65536; o += 2 * n;
      }
    };
    let ended = false;
    for (;;) {                                                           // 0x39f4f check before every 64-frame chunk
      if (wrap) { while (pos >= end) pos -= wrap; } else if (pos >= end) { ended = true; }
      if (ended || rem < 16) break;
      run(16); rem -= 16;
    }
    if (rem > 0 && !(wrap === 0 && pos >= end)) run(rem);
    this.pos[c] = pos; this.frac[c] = frac;
    if (wrap === 0 && pos >= end && !noEnd) this.mflags[c] &= 0xfffd;
  }

  // ------------------------------------------------------------------ block (IRQ) level driver
  /** One IRQ: credit 0x5d37 PIT units to the sequencer, run due ticks, update voices, mix 884 frames. */
  irq(mix = true, probe = null) {
    this.tickAcc += IRQ_UNITS;
    while (this.tickAcc >= this.tickLen) {
      this.tickAcc -= this.tickLen;
      this.seqTick(); this.envTick();
    }
    this.update();
    this.blockNo++;
    if (probe) probe(this);
    if (mix) this.mixBlock(); else { const m = this.muteMix; this.muteMix = true; this.mixBlock(); this.muteMix = m; }
  }

  /** Fill l[0..n) / r[0..n) with the next n frames at this.sampleRate.  The first 2 blocks (40 ms) are silence like the
   *  original (double-buffered DMA, one block of latency). */
  renderInto(l, r, n) {
    const ratio = MIX_RATE / this.sampleRate, rs = this.rs;
    const next = () => { // next frame at 44100
      if (this.outPos >= BLOCK_FRAMES) {
        if (this.outBlock < 2) { this.blkL.fill(0); this.blkR.fill(0); this.outBlock++; }
        else { this.irq(true); this.outBlock++; }
        this.outPos = 0;
      }
      return this.outPos++;
    };
    if (ratio === 1) {
      for (let i = 0; i < n; i++) { const k = next(); l[i] = this.blkL[k]; r[i] = this.blkR[k]; }
      return;
    }
    // sample-rate conversion: 4-point Catmull-Rom between the 44.1 kHz frames (no anti-alias filter when downsampling)
    const hl = rs.hl, hr = rs.hr, pull = () => { const k = next(); hl[0] = hl[1]; hl[1] = hl[2]; hl[2] = hl[3]; hl[3] = this.blkL[k]; hr[0] = hr[1]; hr[1] = hr[2]; hr[2] = hr[3]; hr[3] = this.blkR[k]; };
    if (!rs.started) { pull(); pull(); pull(); hl[0] = hl[1]; hr[0] = hr[1]; rs.started = true; rs.pos = 0; }   // [s0,s0,s1,s2]
    for (let i = 0; i < n; i++) {
      while (rs.pos >= 1) { rs.pos -= 1; pull(); }
      const t = rs.pos;
      l[i] = hl[1] + 0.5 * t * (hl[2] - hl[0] + t * (2 * hl[0] - 5 * hl[1] + 4 * hl[2] - hl[3] + t * (3 * (hl[1] - hl[2]) + hl[3] - hl[0])));
      r[i] = hr[1] + 0.5 * t * (hr[2] - hr[0] + t * (2 * hr[0] - 5 * hr[1] + 4 * hr[2] - hr[3] + t * (3 * (hr[1] - hr[2]) + hr[3] - hr[0])));
      rs.pos += ratio;
    }
  }
  /** @returns {{left:Float32Array,right:Float32Array}} */
  render(nFrames) {
    const left = new Float32Array(nFrames), right = new Float32Array(nFrames);
    this.renderInto(left, right, nFrames);
    return { left, right };
  }

  /** Seconds of audio rendered so far, in output time. */
  get position() { return Math.max(0, this.outBlock - 2) * BLOCK_FRAMES / MIX_RATE; }

  /** Start at an arbitrary second (DMA time, same semantics as timeline().positionAt): replays the sequencer silently from the
   *  start, so order/row/syncValue/syncCount are exactly what a continuous run shows at `sec`.  e.g. skip scene: p.seekTime(tl.orderStart(14)) */
  seekTime(sec) {
    this.reset(); this.muteMix = true;
    const n = Math.floor(sec / (BLOCK_FRAMES / MIX_RATE));
    for (let i = 0; i < n && !this.finished; i++) this.irq(false);
    this.muteMix = false; this.outBlock = 2; this.outPos = BLOCK_FRAMES;
  }

  /** Jump to (order,row) by re-running the sequencer from the start without producing audio.  `row` is the index of the row
   *  that was just played (the demo's DAT_00031518 minus one).  Voices continue from their (approximate) positions. */
  seek(order, row = 0) {
    this.reset();
    this.muteMix = true;
    for (let guard = 0; guard < 200000; guard++) {
      if (this.order === order && this.row > row) break;
      if (this.finished) break;
      this.irq(false);
    }
    this.muteMix = false;
    this.outBlock = 2; this.outPos = BLOCK_FRAMES;
  }

  /** Fast sequencer-only pass (no envelopes, no mixing).  Records the order/row visible after every IRQ block.
   *  Stops at the first end-of-song wrap (original: DAT_000314f5 set, then it loops from restartOrder).
   *  @returns {{blocks:number, duration:number, order:Uint8Array, row:Uint16Array, tempo:Uint8Array, speed:Uint8Array,
   *   blockDur:number, positionAt:(s:number)=>{order:number,row:number}, orderStart:(o:number)=>number, orderStarts:Float64Array}} */
  timeline(maxSeconds = 3600) {
    const p = new UsmPlayer(this.bytes, MIX_RATE, { mod: this.mod });
    const max = Math.ceil(maxSeconds * MIX_RATE / BLOCK_FRAMES);
    const O = [], R = [], TP = [], SP = [], SV = [], SC = [];
    while (!p.finished && O.length < max) {
      p.tickAcc += IRQ_UNITS;
      while (p.tickAcc >= p.tickLen) { p.tickAcc -= p.tickLen; p.seqTick(); }
      O.push(p.order); R.push(p.row); SV.push(p.syncValue); SC.push(p.syncCount); TP.push(p.tempo); SP.push(p.speed);
    }
    const blockDur = BLOCK_FRAMES / MIX_RATE, nb = O.length;
    const starts = new Float64Array(256).fill(-1);
    for (let i = 0; i < nb; i++) if (starts[O[i]] < 0) starts[O[i]] = (i + 1) * blockDur;
    const tl = {
      blocks: nb, blockDur, duration: nb * blockDur, order: Uint8Array.from(O), row: Uint16Array.from(R), tempo: Uint8Array.from(TP), speed: Uint8Array.from(SP),
      orderStarts: starts, syncValue: Uint8Array.from(SV), syncCount: Uint32Array.from(SC),
      /** DAT_000314f4 (last sync marker, effect 0x20/0x33) and number of markers so far, as the demo sees them at DMA time s */
      syncAt(s) { const n = Math.min(nb, Math.floor(s / blockDur)); if (n < 1) return { value: 0, count: 0 }; return { value: SV[n - 1], count: SC[n - 1] }; },
      /** state the demo's main loop would read at audio time `s` seconds (IRQ n happens at n*blockDur, n>=1) */
      positionAt(s) { const n = Math.min(nb, Math.floor(s / blockDur)); if (n < 1) return { order: 0, row: 0 }; return { order: O[n - 1], row: R[n - 1] }; },
      /** time (s) at which the original first reports order `o` */
      orderStart(o) { return starts[o]; },
    };
    return tl;
  }

  /** debug: per channel snapshot in the layout of tools/test/usm_groundtruth.py */
  chState(c) {
    const sp = this.smp[c], ip = this.inst[c];
    return [this.period[c], this.volOut[c], this.panOut[c], this.freq[c], this.mflags[c], sp ? sp.off : 0xffffffff, ip ? ip.off : 0, this.basePeriod[c], this.pos[c], this.vol[c], this.chvol[c], this.envValV[c], this.fade[c], this.envValP[c], this.panSet[c], this.envPosP[c], this.envFrP[c], this.envPosV[c], this.envFrV[c]];
  }
}

/** helper: start `player` at second `sec` (see UsmPlayer.seekTime) */
export function seekTime(player, sec) { player.seekTime(sec); return player; }
