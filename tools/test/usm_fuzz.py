"""Make a randomised variant of a USM module for differential fuzzing of the player against the original:
  python usm_fuzz.py ana.u fuzz.u SEED          (SEED>=100 also randomises header flags / speed / tempo / channel pan+vol)
then  python usm_groundtruth.py fuzz.u gt.json 1500  &&  node usm.test.mjs --vs fuzz.u gt.json     (sequencer, envelopes, voices)
      python usm_mixtruth.py fuzz.u mix.i16 1500     &&  node usm.test.mjs --vs-mix fuzz.u mix.i16  (mixer; differs only when a voice
      runs >512 bytes past a sample end: the original then reads whatever follows in the heap)"""
import sys, random, struct
src, dst, seed = sys.argv[1], sys.argv[2], int(sys.argv[3])
d = bytearray(open(src, 'rb').read())
r = random.Random(seed)
u32 = lambda o: struct.unpack_from('<I', d, o)[0]
u16 = lambda o: struct.unpack_from('<H', d, o)[0]
nch = u16(0x2e); olen = u16(0x36)
orders = sorted(set(d[0x3e:0x3e + olen]))
mode = seed % 3
for o in orders[:12]:
    p = u32(0x1be + 4 * o)
    if not p: continue
    rows = u16(p + 10); e = p + 12
    for row in range(rows):
        k = nch
        while True:
            if d[e] == 0xfc: e += 1; break
            if r.random() < 0.35:
                note = r.choice([0] * 3 + list(range(1, 0x79)) * 2 + [0xfd, 0xfe, 0xff])
                d[e] = note
                d[e + 1] = r.choice([0, 0, 1, 2, 4, 7, 9, 10, 17, 14, 31, 55])
                d[e + 2] = r.choice([0, 0, 0x10 + r.randrange(0x41)] + [0x60 + r.randrange(0xa0)] * 2)
                cmd = r.randrange(0x45)
                if cmd in (0xb, 0x34, 0x15 if mode == 1 else 0x15) and r.random() < 0.8: cmd = r.choice([0x2, 0x3, 0x4, 0xa])
                d[e + 3] = cmd
                par = r.randrange(256)
                if cmd == 0x34 and par == 0: par = 3
                d[e + 4] = par
            e += 5; k -= 1
            if k == 0: break
if seed >= 100:
    fl = 0x43 ^ (r.choice([0, 4, 8, 0x10, 0x40, 0x80, 0xdc]) & 0xfc)
    struct.pack_into('<H', d, 0x26, fl)
    d[0x3a] = r.choice([1, 2, 3, 4, 6]); d[0x3b] = r.choice([0x40, 0x7d, 0x8b, 0xa0, 0xf0]); d[0x3c] = r.choice([0x80, 0x60, 0x20])
    for i in range(nch):
        d[0x13e + i] = r.choice([0, 0x20, 0x40, 0x64, 0x7f, 0x80, 0xa0, 0xc0]); d[0x17e + i] = r.choice([0x40, 0x40, 0x30, 0x10, 0])
open(dst, 'wb').write(d)
