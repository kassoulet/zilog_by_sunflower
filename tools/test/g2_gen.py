"""Differential vectors for site/js/scenes/_g2fx.js (scenes 2+3 FPU effect objects) from the ORIGINAL code under Unicorn.
   python g2_gen.py out.json ; node g2.test.mjs out.json   (see run_g2.sh)"""
import sys, os, json, base64, struct, random, subprocess
HERE = os.path.dirname(os.path.abspath(__file__)); ROOT = os.path.abspath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, os.path.join(ROOT, 're', 'harness'))
from orig import Orig as _Orig
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX
class Orig(_Orig):
    def _code(self, uc, addr, size, ud):
        if addr == 0x1c48f:
            d, s_, n = (uc.reg_read(r) for r in (UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX))
            uc.mem_write(d, bytes(uc.mem_read(s_, n))); self._ret(uc)
        elif addr == 0x2431d:
            a, b, n = (uc.reg_read(r) for r in (UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX))
            x, y = bytes(uc.mem_read(a, n)), bytes(uc.mem_read(b, n))
            uc.reg_write(UC_X86_REG_EAX, (x > y) - (x < y) & 0xffffffff); self._ret(uc)
        else: super()._code(uc, addr, size, ud)
OUT = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, 'tools', 'out', 'g2_vectors.json')
SCR = '/tmp/z3d_scratch'; os.makedirs(SCR, exist_ok=True); AS = os.path.join(SCR, 'assets.json')
if not os.path.exists(AS): subprocess.check_call(['node', os.path.join(HERE, '3d_assets.mjs'), AS])
ASSETS = {k: dict(v, px=base64.b64decode(v['px'])) for k, v in json.load(open(AS)).items()}
rnd = random.Random(7); b64 = lambda b: base64.b64encode(bytes(b)).decode()
blobs, cases = {}, []
def blob(n, d): blobs[n] = b64(d); return n
def mob(n): return open(os.path.join(ROOT, 'raw', '3d', n), 'rb').read()
def world():
    o = Orig()
    luts = o.alloc(0x100000, 0x40000); o.w32(0x402f4, luts); o.w32(0x402f8, luts + 0x10000); o.call(0x14834)
    scr = o.alloc(256000); o.w32(0x402f0, scr)
    tgt = o.alloc(32); o.w32(tgt, 320); o.w32(tgt + 4, 200); o.w32(tgt + 8, scr); o.w32(0x40304, tgt)
    return o, scr
def load(o, name):
    d = mob(name); p = o.alloc(len(d) + 16); o.write(p, d); return o.call(0x16478, eax=p).eax
def mi(o, m): return struct.unpack('<21I', o.read(m, 0x54))
def mkobj(o, mesh, cx=160.0, cy=100.0, dist=6.5, focal=140.0, tex=0, mode=0, sub=0):
    ob = o.alloc(0x40); o.w32(ob, mesh); o.wf32(ob + 4, cx); o.wf32(ob + 8, cy); o.wf32(ob + 0xc, dist); o.wf32(ob + 0x10, focal)
    o.w32(ob + 0x14, tex); o.w8(ob + 0x1c, mode); o.w8(ob + 0x1d, sub); return ob
f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
TS = [0.0, 13.37, 250.5, 1234.75, 4000.25]
# ---- ring mesh 1bdb0
o, _ = world(); m = o.call(0x1bdb0, eax=26, edx=5, stack=[800.0]).eax; w = mi(o, m)
cases.append({'k': 'ring', 'pts': blob('ring_pts', o.read(w[1], w[0] * 12)), 'edges': blob('ring_e', o.read(w[0x10], w[0xf] * 8)), 'n': w[0], 'ne': w[0xf]})
# ---- mesh deformers
for fn, addr, stack in (('wobble', 0x206e0, None), ('blob', 0x20b94, [60.0]), ('uv', 0x1b446, [0.1])):
    for mn in ('b2.mob', 'kph2.mob', 'sph1024.mob', 'ring'):
        for t in TS:
            o, _ = world(); o.wf32(0x40310, t)
            m = o.call(0x1bdb0, eax=26, edx=5, stack=[800.0]).eax if mn == 'ring' else load(o, mn)
            w = mi(o, m)
            o.call(addr, eax=m, **({'stack': stack} if stack else {}))
            w = mi(o, m)
            res = o.read(w[2], w[0] * 12) if fn != 'uv' else o.read(w[0x12], w[0] * 8)
            pts = o.read(w[1], w[0] * 12)
            cases.append({'k': fn, 'mob': mn, 't': t, 'pts': blob('p_%s_%s_%s' % (fn, mn, t), pts), 'out': blob('o_%s_%s_%s' % (fn, mn, t), res), 'n': w[0]})
    print(fn, flush=True)
# ---- lens nodes 1ce90
for t in TS + [77.7, 500.125]:
    o, _ = world(); o.wf32(0x40310, t); a = o.alloc(41 * 26 * 12); o.call(0x1ce90, eax=a)
    cases.append({'k': 'lens', 't': t, 'out': blob('lens_%s' % t, o.read(a, 41 * 26 * 12))})
print('lens', flush=True)
# ---- rendering halves
env1, max_t2 = (ASSETS['textures/' + n + '.gfx']['px'] for n in ('env1', 'max_t2'))
bg = ASSETS['fullpics/simulcra.gfx']['px'][:256000]
def chain(o, m, ob, ang, nang):
    o.w8(ob + 0x1c, 9); o.call(0x17e5e, eax=ob, stack=list(ang)); o.call(0x1841d, eax=ob); o.call(0x185d4, eax=m)
    o.call(0x18144, eax=m, stack=list(nang)); o.call(0x1870b, eax=ob)
    w = mi(o, m); npts, nf = w[0], w[6]
    return {k: blob('h%d_%s' % (len(cases), k), o.read(w[i], n)) for k, i, n in (('xpts', 2, npts * 12), ('nrm', 4, npts * 12), ('p2d', 0x11, npts * 8), ('invz', 0x14, npts * 4), ('fnrm', 8, nf * 12))}
def A(): return [rnd.uniform(-3, 3) for _ in range(3)]
o_, _ = world(); sa = o_.alloc(65536, 65536); o_.call(0x14639, eax=sa); spot = o_.read(sa, 65536)
for mn in ('b2.mob', 'kph2.mob'):
    for fn, addr in (('far', 0x1a7df), ('near', 0x1aa02)):
        for k in range(2):
            o, scr = world(); m = load(o, mn); tex = o.alloc(0x40000, 0x40000); o.write(tex, max_t2[:262144])
            ob = mkobj(o, m, cx=rnd.uniform(150, 230), cy=100.0, dist=rnd.choice([4.0, 6.0]), focal=140.0, tex=tex)
            ang, nang = A(), A(); inj = chain(o, m, ob, ang, nang); o.write(scr, bg); o.w8(ob + 0x1c, 0); o.w8(ob + 0x1d, 0)
            o.call(addr, eax=ob)
            cases.append({'k': 'half', 'fn': fn, 'mob': mn, 'tex': blob('hg_tex', max_t2[:262144]), 'bg': blob('hg_bg', bg), 'inj': inj, 'out': blob('ho%d' % len(cases), o.read(scr, 256000)),
                          'cx': f32(struct.unpack('<f', o.read(ob + 4, 4))[0]), 'dist': struct.unpack('<f', o.read(ob + 0xc, 4))[0]})
    print('half', mn, flush=True)
for far, addr in ((True, 0x1a21b), (False, 0x1a5ea)):
    for k in range(3):
        o, scr = world(); m = load(o, 'sph1024.mob'); tex = o.alloc(65536, 65536); o.write(tex, spot)
        ob = mkobj(o, m, cx=220.0, cy=100.0, dist=6.0, focal=100.0, tex=tex, mode=9, sub=6)
        ang, nang = A(), A(); inj = chain(o, m, ob, ang, nang); o.write(scr, bg); o.w8(ob + 0x1c, 9); o.w8(ob + 0x1d, 6)
        o.call(addr, eax=ob, stack=[17.0])
        cases.append({'k': 'sprites', 'far': far, 'spot': blob('spot', spot), 'bg': blob('hg_bg', bg), 'inj': inj, 'out': blob('so%d' % len(cases), o.read(scr, 256000))})
    print('sprites', far, flush=True)
json.dump({'blobs': blobs, 'cases': cases}, open(OUT, 'w'))
print('wrote', OUT)
