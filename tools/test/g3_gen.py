"""Differential vectors for scenes/_g3.js (func_21290) from the ORIGINAL under Unicorn:  python g3_gen.py out.json ; node g3.test.mjs out.json"""
import sys, os, json, base64, struct, math, random
HERE = os.path.dirname(os.path.abspath(__file__)); ROOT = os.path.abspath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, os.path.join(ROOT, 're', 'harness'))
from orig import Orig as _Orig
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX
class Orig(_Orig):
    def _code(self, uc, addr, size, ud):      # no usable ES in Unicorn: hook memcpy / memcmp
        if addr == 0x1c48f:
            d, s_, n = (uc.reg_read(r) for r in (UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX))
            uc.mem_write(d, bytes(uc.mem_read(s_, n))); self._ret(uc)
        elif addr == 0x2431d:
            a, b, n = (uc.reg_read(r) for r in (UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX))
            x, y = bytes(uc.mem_read(a, n)), bytes(uc.mem_read(b, n))
            uc.reg_write(UC_X86_REG_EAX, (x > y) - (x < y) & 0xffffffff); self._ret(uc)
        else: super()._code(uc, addr, size, ud)
o = Orig()
d = open(os.path.join(ROOT, 'raw', '3d', 'cones3.mob'), 'rb').read()
p = o.alloc(len(d) + 16); o.write(p, d); m = o.call(0x16478, eax=p).eax
npts, pts, xpts = o.r32(m), o.r32(m + 4), o.r32(m + 8)
out = {'npts': npts, 'pts': base64.b64encode(o.read(pts, npts * 12)).decode(), 'cases': []}
rnd = random.Random(5)
for t in [0.0, 1.0, 37.25, 160.0, 500.5, 1234.75, 3000.0] + [rnd.uniform(0, 4000) for _ in range(8)]:
    t = struct.unpack('<f', struct.pack('<f', t))[0]
    o.wf32(0x40310, t); o.write(xpts, b'\0' * npts * 12); o.call(0x21290, eax=m)
    out['cases'].append({'t': t, 'xpts': base64.b64encode(o.read(xpts, npts * 12)).decode()})
json.dump(out, open(sys.argv[1], 'w'))
print('cones3 npts', npts, 'cases', len(out['cases']))
