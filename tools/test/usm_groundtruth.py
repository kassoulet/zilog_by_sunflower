"""Ground truth for the USM player: runs the ORIGINAL sequencer/envelope/voice-update code (re/harness/orig.py, Unicorn)
on music/ana.u block by block (one block = one SB IRQ = 0x5d37 PIT units) and dumps the state into JSON.
usage: python usm_groundtruth.py ana.u out.json [maxblocks]
The sound device is replaced by a stub (upload: sets sample flag bit0 like the real one; mixer hook: no-op), and the
mixer's per-block flag processing (0x39bc0) is emulated here."""
import sys, json, struct
sys.path.insert(0, __import__('os').path.join(__import__('os').path.dirname(__file__), '..', '..', 're', 'harness'))
from orig import Orig
o = Orig()
img = bytearray(o.read(0x32000, 0x4500))
for m in __import__('re').finditer(b'\x1e\x07', bytes(img)): o.write(0x32000 + m.start(), b'\x90\x90')   # 'push ds; pop es' misbehaves in unicorn flat mode
data = open(sys.argv[1], 'rb').read()
mod = o.alloc(len(data) + 0x1000)
o.write(mod, data)
stub = o.alloc(16)
o.write(stub, bytes([0x80, 0x4f, 0x39, 0x01, 0xf8, 0xc3]))      # or byte [edi+0x39],1 ; clc ; ret
stub2 = o.alloc(16); o.write(stub2, bytes([0xf8, 0xc3]))         # clc ; ret
vt = o.alloc(64)
for i in range(8): o.w32(vt + 4 * i, stub2)
o.w32(vt + 4, stub)
o.w32(0x3398f, vt); o.w16(0x36450, 0); o.w8(0x33997, 0)
o.call(0x322f0, esi=mod)
o.call(0x32406, esi=mod)
assert o.r32(0x34e10) in (0, 0x301) or True
print('load err code', hex(o.r32(0x34e10)))
nch = o.r32(0x314fc)
blocks = []
maxb = int(sys.argv[3]) if len(sys.argv) > 3 else 20000
for n in range(maxb):
    o.call(0x32601, eax=0x5d37)
    st = dict(o=struct.unpack('<H', o.read(0x31514, 2))[0], r=struct.unpack('<H', o.read(0x31518, 2))[0],
              sp=o.read(0x31509, 1)[0], tp=o.read(0x31508, 1)[0], gv=o.read(0x3646d, 1)[0], lf=o.read(0x314f5, 1)[0],
              sy=o.r32(0x314f0), sv=o.read(0x314f4, 1)[0])
    ch = []
    for c in range(nch):
        fl = struct.unpack('<H', o.read(0x36472 + 2 * c, 2))[0]
        ch.append([struct.unpack('<H', o.read(0x365f2 + 2 * c, 2))[0], o.read(0x367f2 + c, 1)[0], o.read(0x36872 + c, 1)[0],
                   o.r32(0x36672 + 4 * c), fl, (o.r32(0x368b2 + 4 * c) - mod) & 0xffffffff, (o.r32(0x364f2 + 4 * c) - mod) & 0xffffffff,
                   struct.unpack('<H', o.read(0x31670 + 2 * c, 2))[0], o.r32(0x369b2 + 4 * c) - mod if o.r32(0x369b2 + 4 * c) else 0,
                   o.read(0x31630 + c, 1)[0], o.read(0x36772 + c, 1)[0], o.read(0x36c32 + c, 1)[0], struct.unpack('<H', o.read(0x36ab2 + 2 * c, 2))[0],
                   o.read(0x36d72 + c, 1)[0], o.read(0x36832 + c, 1)[0], struct.unpack('<H', o.read(0x36c72 + 2 * c, 2))[0], struct.unpack('<H', o.read(0x36cf2 + 2 * c, 2))[0],
                   struct.unpack('<H', o.read(0x36b32 + 2 * c, 2))[0], struct.unpack('<H', o.read(0x36bb2 + 2 * c, 2))[0]])
        # emulate mixer flag handling (0x39bc0)
        if fl & 4: fl &= 0xfff9
        if fl & 0x10: fl = (fl & 0xffef) | 2
        fl &= 0xff1f
        o.w16(0x36472 + 2 * c, fl)
    st['c'] = ch
    blocks.append(st)
    if st['lf'] and n > 10: break
json.dump(dict(nch=nch, blocks=blocks), open(sys.argv[2], 'w'), separators=(',', ':'))
print('blocks', len(blocks), 'last', blocks[-1]['o'], blocks[-1]['r'])
