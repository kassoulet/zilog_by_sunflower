"""Differential vectors for site/js/scenes/_g4fx.js (funcs 0x1b04f 0x1bf97 0x20b94 0x20a10 0x1b533) from the ORIGINAL code under Unicorn.
   python g4_gen.py out.json ; node g4.test.mjs out.json   (run_g4.sh)"""
import sys, os, json, base64, struct, random
HERE = os.path.dirname(os.path.abspath(__file__)); ROOT = os.path.abspath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, os.path.join(ROOT, 're', 'harness'))
from orig import Orig as _Orig
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX
class Orig(_Orig):
    def _code(self, uc, addr, size, ud):   # no usable ES in Unicorn: hook memcpy 0x1c48f / memcmp 0x2431d
        if addr == 0x1c48f:
            d, s_, n = (uc.reg_read(r) for r in (UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX)); uc.mem_write(d, bytes(uc.mem_read(s_, n))); self._ret(uc)
        elif addr == 0x2431d:
            a, b, n = (uc.reg_read(r) for r in (UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX)); x, y = bytes(uc.mem_read(a, n)), bytes(uc.mem_read(b, n))
            uc.reg_write(UC_X86_REG_EAX, (x > y) - (x < y) & 0xffffffff); self._ret(uc)
        else: super()._code(uc, addr, size, ud)
b64 = lambda b: base64.b64encode(bytes(b)).decode()
fb = lambda f: struct.unpack('<I', struct.pack('<f', f))[0]
OUT = sys.argv[1]; cases = []
mob = open(os.path.join(ROOT, 'raw', '3d', 'k_1.mob'), 'rb').read()
def loadk():
    o = Orig(); p = o.alloc(len(mob) + 16); o.write(p, mob); return o, o.call(0x16478, eax=p).eax
def info(o, m): return struct.unpack('<21I', o.read(m, 0x54))
def rdf(o, a, n): return o.read(a, n * 4)
# 1b04f planar uv
for w, h in ((256, 256), (320, 200)):
    o, m = loadk(); o.call(0x1b04f, eax=m, edx=w, ebx=h); w_ = info(o, m)
    cases.append({'fn': 'planarUV', 'w': w, 'h': h, 'uv': b64(rdf(o, w_[0x12], w_[0] * 2))})
# 20b94 ripple (needs xpts allocated by the loader: yes) and 20a10/1b533
rnd = random.Random(5)
for t in (0.0, 3.5, 77.25, 400.0, 1234.5, 2500.75):
    amp = rnd.uniform(0, 400)
    o, m = loadk(); o.wf32(0x40310, t); o.call(0x20b94, eax=m, stack=[fb(amp)]); w_ = info(o, m)
    cases.append({'fn': 'rippleSphere', 't': t, 'amp': amp, 'xpts': b64(rdf(o, w_[2], w_[0] * 3))})
# lattice
o = Orig(); mm = o.call(0x1bf97, eax=10, edx=10, ebx=6, stack=[fb(50.0)]).eax; w_ = info(o, mm)
cases.append({'fn': 'makeLattice', 'npts': w_[0], 'nedges': w_[0xf], 'pts': b64(rdf(o, w_[1], w_[0] * 3)), 'edges': b64(o.read(w_[0x10], w_[0xf] * 8))})
for (a, b, c, s) in ((4, 3, 5, 30.0), (7, 2, 3, 12.5)):
    o = Orig(); mm = o.call(0x1bf97, eax=a, edx=b, ebx=c, stack=[fb(s)]).eax; w_ = info(o, mm)
    cases.append({'fn': 'makeLattice', 'dims': [a, b, c, s], 'npts': w_[0], 'nedges': w_[0xf], 'pts': b64(rdf(o, w_[1], w_[0] * 3)), 'edges': b64(o.read(w_[0x10], w_[0xf] * 8))})
for t in (0.0, 5.0, 91.5, 600.0, 1500.25, 2600.0):
    o = Orig(); mm = o.call(0x1bf97, eax=10, edx=10, ebx=6, stack=[fb(50.0)]).eax; w_ = info(o, mm)
    o.wf32(0x40310, t); o.call(0x20a10, eax=mm); xp = rdf(o, w_[2], w_[0] * 3)
    k = rnd.uniform(0.1, 2.0); o.call(0x1b533, eax=mm, stack=[fb(k)]); w_ = info(o, mm)
    cases.append({'fn': 'blackHole', 't': t, 'k': k, 'xpts': b64(xp), 'uv': b64(rdf(o, w_[0x12], w_[0] * 2))})
json.dump(cases, open(OUT, 'w'))
print(len(cases), 'cases')
