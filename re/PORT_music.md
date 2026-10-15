# Music player port (Useless Sound System v1.04, USM / 'USLM' modules)

Files: `site/js/music/usm.js` (player), `tools/render-music.mjs` (WAV + order times), `tools/test/usm.test.mjs`
(+ `usm_groundtruth.py`, `usm_mixtruth.py`, `usm_mktruth.py`, `usm_fuzz.py`, `run_usm.sh`, `usm_truth.json`).

Status: **bit-exact** against the original machine code run under Unicorn: order/row/speed/tempo at every IRQ block, the complete
per-channel voice state (period, volume, pan, frequency, flags, sample/instrument, envelope positions, fade-out) at every block, and
every sample of the mixer output (all 10448 blocks = 209.434 s, 16-bit wrap-around included).  ~110 randomised variants of the
module (random notes/instruments/volume column/every effect 0x00..0x43/header flags/speed/tempo/pan) were also compared; every effect
handler was exercised and matches.

## What the original does (architecture)

* Music is `music\ana.u` from the asset container (loaded by `main` at 0x107c8, `FUN_000322f0` then `FUN_00032406`).
* "Useless Sound System v1.04 (c) 1996-1997 FreddyV/Useless".  Device table at 0x3397b: AMD Interwave (0x37200), GUS (0x37a00),
  **Sound Blaster family (0x38090)**, no-sound (0x39810).  Each device = {detect, upload-sample (+4), ?, ?(+0xc set mix volume), start(+0x10),
  stop(+0x14), per-IRQ update/mix (+0x18)}.  Under DOSBox/SB16 the SB driver runs: **44100 Hz, stereo, 16-bit signed, software mixer**
  (rate/flags table at 0x3813e/0x38148, flags 0x11a: bit1 16bit, bit3 stereo, bit4 signed, bit5 oversampling(off)).  For DSP < 4.0 the
  driver falls back to 8-bit modes / lower rates (not ported; ana.u is only ever heard through the SB16 path in DOSBox).
* The DSP runs auto-init DMA with two halves of 884 frames ((44100/50+3)&~3).  Every half-buffer IRQ (ISR 0x394e6, 20.045 ms) calls the
  player callback **0x32601 with eax=0x5d37** (=23863 "PIT units", i.e. 1/50 s of 1.19318 MHz):
  1. `acc += 0x5d37; while (acc >= tickLen) { acc -= tickLen; tick (0x3262e); envelopes (0x343a6) }`  with `tickLen = 5964876 / (2*tempo)`
     (0x32a65) -> tempo 125 = 50 ticks/s, tempo 139 = 55.6 ticks/s.  A tick is *quantised to the IRQ*: all ticks of one 20 ms block happen
     back to back, then
  2. 0x346b1 derives per-channel frequency/volume/pan from the state (only for channels whose dirty flag is set), then calls the device (+0x18 = 0x39bc0)
     which mixes the next 884 frames into the half of the DMA buffer that just finished -> **audible one block later** (the first two blocks are silence).
* The demo main loop reads `DAT_00031514` (order) and `DAT_00031518` (row) at arbitrary times; they change only inside the IRQ callback, so they are
  piecewise constant per 20.045 ms block.  `row` is *the index of the next row to play* (it is incremented right after a row was read), range 1..nrows
  while a pattern plays; `row-1` is the row whose notes were just triggered.
* IRQ n happens at `n*884/44100` s.  `timeline().positionAt(t)` = the (order,row) the demo sees at DMA time `t` (state after IRQ floor(t/blockDur)).
  `render()` is exactly the DMA stream: music from the start of a `UsmPlayer` begins with 2 silent blocks, so rendered audio at time t was produced by IRQ n-1.

### Key numbers (ana.u)
28 channels, 60 orders (patterns 0,0,1,1,2,3,4,3,5,6,...,56; restart order 1), 57 patterns of 64 rows (one of 96), 59 samples, 55 instruments, speed 3, tempo 139
(tick 17.99 ms, row 54 ms, pattern 3.456 s).  **Song length 209.434 s (10448 IRQ blocks) until the end-of-song wrap** (DAT_000314f5 set, loops to order 1).
Order start times at which the demo sees `DAT_00031514` reach the value:

| order | 5 | 14 | 19 | 23 | 27 | 31 | 35 | 41 | 49 | 51 |
|---|---|---|---|---|---|---|---|---|---|---|
| s | 17.339 | 48.490 | 67.513 | 81.364 | 95.215 | 109.047 | 122.898 | 143.665 | 171.348 | 178.283 |

(`tools/render-music.mjs` prints these.  Orders 0 and 1 both play pattern 0.)

## File format ('USLM' version 4, little endian)

| offset | size | meaning |
|---|---|---|
| 0x00 | 4 | 'USLM' |
| 0x04 | u16 | version = 4 |
| 0x06 | 32 | title (ASCIIZ) |
| 0x26 | u16 | flags (ana.u: 0x43).  bit1 = instrument mode (note->sample via instruments, else instrument number = sample number); bit2 (4) = volume slide also on tick 0; bit3 (8) = vibrato also on tick 0 / fine-vibrato depth scaling; bit4 (0x10) = portamento running into the period limit cuts the note; bit6 (0x40) = global volume slide x2; bit7 (0x80) = a new instrument does not reset the retrigger counter |
| 0x28 | u16 | (unused, =2 in ana.u) |
| 0x2a | u16 | minimum period (0) ; 0x2c: maximum period (0x1e00) -- clamp range of 0x342cb |
| 0x2e | u16 | number of channels (<= 0x40) |
| 0x30 | u16 | number of patterns (57) |
| 0x32 | u16 | number of samples (59; loader relocates/decodes this many) |
| 0x34 | u16 | number of instruments (55) |
| 0x36 | u16 | song length in orders (60) |
| 0x38 | u16 | restart order (1) |
| 0x3a | u8 | initial speed (ticks/row) (3) |
| 0x3b | u8 | initial tempo (139) |
| 0x3c | u8 | global volume 0..0x80 (0x80) |
| 0x3e | 256 | order list: pattern number per order |
| 0x13e | 64 | channel pan: 0..0x7f (x4 -> 0..0xfc), bit7 ignored, 100 or 0x40 = 0xff.  ana.u: all 0, overridden by sample default pan |
| 0x17e | 64 | channel volume 0..0x40 |
| 0x1be | 256 x u32 | pattern offsets (0 = empty pattern of 64 rows) |
| 0x5be | 128 x u32 | sample header offsets |
| 0x7be | 128 x u32 | instrument header offsets |
| 0x9be | .. | patterns, samples, instruments (all offsets are from file start; the loader (0x322f0) adds the load address to all 512 non-zero entries) |

**Pattern** header: +0x0a u16 rows, data at +0x0c.  A row is a list of 5-byte cells for channels 0..n-1, **terminated by a single byte 0xfc if fewer than n cells follow**
(empty tail); cell = `note, instrument, volume column, command, parameter`:
* note: 0 none, 1..0x78 note (1-based), 0xff note-off (key-off if the instrument has a volume envelope else cut), 0xfe cut, 0xfd key-off.  (0xfc is the row terminator, so never a note.)
* instrument: 0 none (else sets the instrument/sample, resets envelopes, loads default volume and default pan).
* volume column: 0x10..0x50 = set volume 0..0x40 (1..0x0f also "set" with a wrapped value, clamps to 0x40); >0x50: type = (v-0x60)>>4, param = (v-0x60)&0xf:
  0 vol slide down (memory), 1 vol slide up, 2 fine vol down, 3 fine vol up, 4 vibrato speed, 5 vibrato depth, 6 pan (x16), 7/8 pan slide left/right (memory), 9 tone portamento (x16).
* command 0 with parameter 0 means "no command" (0xff); otherwise command number 0..0x43 (table below).

**Sample header** (at offset p): +4 name (28), +0x24 u32 length, +0x28 loop start, +0x2c loop end, +0x38 u8 loop flags (bit3 = loop, bit4 = ping-pong), +0x39 u8 flags (bit0 = has data (delta coded), bit1 = default pan valid, bit2 = "pan from volume" (never set), bit3 = linear frequency table, bit5 = decode pending),
+0x3a default volume (0..0x40), +0x3b sample global volume (0..0x40), +0x3c default pan 0..255, +0x3d u8 transpose (added to note-1, byte wrap, must be < 0x84), +0x3e u32 c2spd/fine-tune
(linear mode: *subtracted* from the period, signed), +0x42 u32 data offset, +0x46 auto-vibrato: waveform, sweep, depth, rate.
Data = signed 8 bit, **delta coded** (running sum mod 256, 0x322f0).  `length` bytes.

**Instrument header**: +4 name, +0x1f note->sample map (index by note 1..0x78, value = sample number+1), +0x2a u16 fade-out, volume envelope at +0xa4 and pan envelope at +0xd9:
`flags (bit0 on, bit1 sustain, bit2 loop), npoints, sustain point, loop start, loop end, 12 x {u16 tick, u16 value}` (value 0..0x40, pan centre 0x20).

### Period / frequency
Linear mode (all samples of ana.u): `period = 0x2100 - ((note-1+transpose)&0xff)*64 - c2spd`; played period = base period (+ vibrato, + auto-vibrato);
`freq(Hz) = (2^((0x2100-period)/768) in 16.16 via 4 table products, 0x34911) * 8363 >> 20`.  Non-linear (Amiga style): `0xda7790/period` with the 0x36eb2 table (ported, unused by ana.u).
Mixer step = `freq * 65536 / 44100` (16.16), nearest-neighbour (no interpolation).

### Mixer
Per voice: `volume = (noteVol * globalVol * channelVol [*fade>>9] [*volEnv]) >> .. * sampleGlobalVol >> ..` (0..64, exact shrd chain in `update()`),
pan 0..255 (pan envelope: `pan + (env-0x20)*distToEdge>>5`), `L = (256-pan)*vol>>8`, `R = (pan+1)*vol>>8`; each output word `+= table[vol][sample]` with the 65x256 int16
table `s8*vol*65536/(0x3e800/200*64)` (func_399bd, gain 200 % = call 0x3409e(0xc8) from main), **16-bit wrap-around, no clipping**.
Loops are handled by the device upload (0x39ae7): looped samples are truncated at the loop end, ping-pong loops get the reversed loop appended, and 0x200 bytes of the cyclic
loop continuation are appended; the mixer checks "end reached -> wrap/stop" only every 64 frames (chunks of 16x4 frames), so a non-looped voice reads on up to 63 frames past the end.

### Effects (cmd -> tick-0 handler / per-tick handler, original addresses)
00 arpeggio 32a8f/33005 | 01 porta up 32b3c/33044 | 02 porta down 32b47/33079 | 03 tone porta 32b52/33099 | 04 vibrato 32b7b/330f4 | 05 tone porta+vol slide 32c13/33131 |
06 vibrato+vol slide 32c13/3313b | 07 tremolo 32bc5/33142 | 08 set pan 32be4 | 09 sample offset 32bff | 0a vol slide 32c13/33192 | 0b position jump 32d61 | 0c set volume 32d71 |
0d pattern break (BCD) 32d7d | 0f set speed (<0x20) / tempo 32a83 | 10 global volume 32daa | 11 global vol slide 32db0/331eb | 14 key-off at tick 32dc5/33228 | 15 set envelope position 32dda |
19 pan slide 32ddf/3323c | 1b retrigger 32dea/3328b | 1d tremor 32e48/33316 | 20, 33 sync marker (DAT_000314f4/f0) 32fc4 | 21 fine porta E1x/E2x 32e65 | 25/26 extra-fine porta up/down 32ec5/32ef1 |
28 vibrato waveform 32f1b | 2a pattern loop 32f22 | 2b tremolo waveform 32f65 | 2c set pan (x16) 32bf0 | 2d retrigger every n ticks 32dc5/33344 | 2e/2f fine vol up/down 32f6c/32f96 |
30 note cut 32dc5/33376 | 31 note delay 32dc5/33392 | 32 pattern delay 32fbe | 34 set speed 32a4b | 35 set tempo 32a65 | 36 pattern break (hex) 32d8a | 37 tempo slide / set 32a51/32fd0 |
38 vol slide w/ fine variants 32c2e/33192 | 39/3a porta down/up w/ fine variants, shared memory 32aa2/33079,33044 | 3b tone porta (shared memory) 32aa2/33099 |
3c vib+volslide 32c2e/3313b | 3d tone porta+volslide 32c2e/33131 | 3e set channel volume 32dbb | 3f channel vol slide 32c8d/331c2 | 41 retrigger w/ memory 32e0b/33269 |
42 fine vibrato 32b7b/330f4 | 43 global vol slide w/ fine 32cfa/331eb.  Others (0e, 12, 13, 16-18, 1a, 1c, 1e, 1f, 22-24, 27, 29, 3e..) are no-ops.
Only 02, 03, 04, 09, 0a, 0d, 20, 24, 2d and the volume-column types 2 (fine vol down) and 3 (fine vol up) appear in ana.u; all other handlers are verified by fuzzing only.

## Function -> JS map

| original | JS (`usm.js`) |
|---|---|
| 0x322f0 relocate+delta decode+upload, 0x32406 load/validate/init | `parseUsm()` + `buildDeviceBuffer()`, `UsmPlayer.reset()` |
| 0x32601 IRQ callback | `UsmPlayer.irq()` |
| 0x3262e tick, 0x326b1 tick effects | `seqTick()`, `runTickEffects()` |
| 0x3299e new pattern / 0x329f9 seek row / 0x326e9 read row / 0x32858 note column | `newPattern()`, `seekRow()`, `readRow()`, `noteColumn()` |
| 0x334e7/0x335f7/0x33707/0x3372f tables, 0x32a4a..0x334ca handlers | `hv(addr, ch, param, cmd)` (a `switch` on the original address) |
| 0x340fa trigger, 0x3417e reset voice, 0x3427b offset, 0x341cc env pos, 0x342cb clamp period, 0x34826 period | `trigger()`, `resetVoiceState()`, `setOffset()`, `setEnvPos()`, `setPeriod()`, `periodFor()` |
| 0x343a6 envelopes + auto-vibrato | `envTick()` |
| 0x346b1 + 0x3495d + 0x34911 | `update()`, `expTab()` |
| 0x347c4 LFO (sine table 0x3399c has a typo at [66]=245, kept) | `lfo()` |
| 0x39ae7 sample upload | `buildDeviceBuffer()` |
| 0x399bd volume table | `buildVolTable()` |
| 0x39bc0 mix block, 0x39e50 voice setup, 0x39f4f loop check, 0x3a5d6/0x3a6e0 stereo loops | `mixBlock()`, `mixVoice()` |

Not ported: the setup UI (0x33b46), device detection/DMA/DSP programming, GUS/Interwave/other SB modes, the PIT timer client (0x3627e, which the demo also uses for its own 70 Hz ISR),
mono/oversampling mixers (0x39f80, 0x3b0e6, 0x3bd0e).

## Uncertain / approximated
* **Device assumption**: the SB16 path (44.1 kHz stereo 16-bit) is what DOSBox gives (`sbtype=sb16`, BLASTER A220 I7 D1 H5).  Real hardware with an older SB would mix in 8 bit at lower rates; not ported.
* A voice that runs more than 512 bytes (about 8 samples per output frame, i.e. a pitch > 8x the mix rate) past a loop end / sample end reads memory behind the sample buffer in the original (heap
  garbage); the port reads zeros there.  Does not happen in ana.u (the whole song is sample exact).
* For `sampleRate != 44100` the 44.1 kHz stream is resampled with a 4-point Catmull-Rom (no anti-aliasing filter when downsampling); at 44100 the output is the original stream.
* `render()` mixes in 884-frame blocks like the original.  Blocks are produced when needed, so a call may take longer when it crosses a block boundary (about 30 us per block on a desktop CPU).
* `seek()` re-runs the sequencer from the start (fast, 1.2 s of CPU for the whole song) and advances voice positions arithmetically (including loops), no audio.
* DOSBox capture (`scratchpad/emu/audio.f32`, 110 s of audio): not sample-comparable (different clock, js-dos mixer) but consistent: the envelope autocorrelation has the same pattern period (3.46 s, harmonics at
  6.92 s), the tick/row rhythm peak is at 18.5 Hz in both, and the long-term spectra (80 log bands, 30 Hz..10 kHz) correlate 0.965 with the port's rendering (0.49-0.70 if the pitch is shifted by x2/x1.5).
  I could not align the two time axes (the capture contains the first ~100 s of audio-clock only and starts at 5.6 s).
* Fuzzed modules where a note switches to an instrument with fewer envelope points than the current envelope position (no instrument column => envelope not reset) make the original execute
  `idiv` by a zero segment length (#DE, a crash on a real machine; Unicorn's harness silently skips it).  The port does not crash and its result there is meaningless; this never happens in ana.u.
* `finished` becomes true when the song reaches its end for the first time (the player keeps looping from the restart order like the original).

## Interesting inner loops (for the explainer page)
* **0x3a6e0** (stereo chunk, 16 x 4 frames): `mov bl,[esi]; add cx,[step]; mov ax,[ebx*2]; adc esi,ebp; mov dl,bl; add [edi],ax; mov ax,[edx*2]; add [edi+2],ax` -- the whole mixer is a 16.16 position
  in `cx:esi`, the volume x sample multiplication replaced by a 65x256 word lookup table indexed by `(volume<<8)|sample`, `adc` propagating the fractional carry.
* **0x39f4f / 0x3a5d6** loop handling: wrap check only once per 64 frames, made exact by the 0x200 bytes of loop continuation appended in 0x39ae7 (ping-pong = reversed loop appended).
* **0x399bd** builds the 65x256 `s8*vol*65536/(0x3e800/gain*64)` table with `imul/idiv`.
* **0x34911** `2^(x/768)` as the product of four 16-entry tables with `mul; shrd eax,edx,15` (0x34881/0x348a1/0x348c1/0x34901), then `*8363>>20` (0x3495d).
* **0x346b1** volume chain: `mul` / `shrd eax,edx,cl` fixed-point products (note vol x global vol x channel vol x fade x envelope x sample vol), shift counts accumulated in `bl`.
* **0x343a6** envelope interpolation `imul word [frac]; idiv word [seglen]` per tick and channel; 0x347c4 LFO table lookups (`neg`/`imul dx` tricks for the waveforms).
* **0x32601** the IRQ-quantised tick scheduler (`acc += 0x5d37; while (acc >= tickLen) tick`), **0x322f0** the delta decoder (`add al,[esi]; mov [esi],al; loop`), 0x32332.
* **0x394e6** the SB ISR: acknowledge DSP, switch to a private stack, call the player, EOI both PICs.

## Testing
`node tools/test/usm.test.mjs` (1 s) compares against `tools/test/usm_truth.json` (generated by `tools/test/run_usm.sh`, ~1.5 min, original code under Unicorn via
`usm_groundtruth.py` = sequencer/voices with the device replaced by a stub, `usm_mixtruth.py` = the real SB16 mixer with the DMA hardware skipped).
Fuzzing: `usm_fuzz.py ana.u fuzz.u SEED`, then the `--vs` / `--vs-mix` modes of the test (see the header of `usm_fuzz.py`).
Note for the harness: 'push ds / pop es' (1e 07) is patched to NOPs because Unicorn's flat-mode segment push/pop is inconsistent.
