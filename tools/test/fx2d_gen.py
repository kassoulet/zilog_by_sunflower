"""Generate differential-test vectors for site/js/lib/fx2d*.js by running the ORIGINAL code under Unicorn.
   python fx2d_gen.py out.json        then:  node fx2d.test.mjs out.json
 (see run_fx2d.sh).  Each test: {fn, p: params, in: {name: b64}, out: {name: b64}}.
"""
import sys, os, json, base64, struct, random, subprocess
HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, os.path.join(ROOT, 're', 'harness'))
import orig as _o
from orig import Orig as _Orig
from unicorn import *
from unicorn.x86_const import *

class Orig(_Orig):
    """Faster than harness Orig (which runs a Python hook on EVERY instruction): code hooks only on the few addresses we intercept:
    malloc 0x24c8f, free 0x23831, and (Unicorn has no usable ES after `mov es,eax`) strlen 0x24cd6 and memcpy 0x1c48f."""
    def __init__(self):
        mu = self.mu = Uc(UC_ARCH_X86, UC_MODE_32)
        mu.mem_map(_o.BASE, 0x40000); mu.mem_write(_o.BASE, open(_o.IMAGE, 'rb').read()[:_o.IMGSZ])
        mu.mem_map(_o.STK - 0x100000, 0x200000); mu.mem_map(_o.HEAP, _o.HEAPSZ); mu.mem_write(_o.SENT, b'\xf4')
        self.brk = _o.HEAP + 0x1000; self.io_log = []; self.last_unmapped = None
        for a in (0x24c8f, 0x23831, 0x24cd6, 0x1c48f): mu.hook_add(UC_HOOK_CODE, self._code, begin=a, end=a)
        mu.hook_add(UC_HOOK_INTR, lambda uc, n, ud: self.io_log.append(('int', n)))
        mu.reg_write(UC_X86_REG_FPCW, 0x37f)    # harness default is CW=0 (24-bit precision!); a DOS program runs with the default 0x37f (64-bit)
    def _code(self, uc, addr, size, ud):
        if addr == 0x24cd6:
            p = uc.reg_read(UC_X86_REG_EAX); n = 0
            while uc.mem_read(p + n, 1)[0]: n += 1
            uc.reg_write(UC_X86_REG_EAX, n); self._ret(uc)
        elif addr == 0x1c48f:
            d, s_, n = (uc.reg_read(r) for r in (UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX))
            uc.mem_write(d, bytes(uc.mem_read(s_, n))); self._ret(uc)
        else: super()._code(uc, addr, size, ud)

SCR = os.environ.get('FX2D_SCRATCH', '/tmp/fx2d_scratch')
os.makedirs(SCR, exist_ok=True)
AS = os.path.join(SCR, 'assets.json')
subprocess.check_call(['node', os.path.join(HERE, 'fx2d_assets.mjs'), AS])
ASSETS = {k: dict(v, px=base64.b64decode(v['px'])) for k, v in json.load(open(AS)).items()}
rnd = random.Random(1234)
b64 = lambda b: base64.b64encode(bytes(b)).decode()
tests = []

import time
_t0 = time.time()
def T(fn, p, ins, outs):
    print('%6.1fs %s %s' % (time.time() - _t0, fn, str(p)[:60]), flush=True)
    tests.append({'fn': fn, 'p': p, 'in': {k: b64(v) for k, v in ins.items()}, 'out': {k: b64(v) for k, v in outs.items()}})

def rb(n): return bytes(rnd.randrange(256) for _ in range(n))
def real32(name='fullpics/simulcra.gfx'): return ASSETS[name]['px'][:256000]
def blend_tables(o):
    """run func_14834 for real: returns (t1,t2) addresses (64K aligned)"""
    t1 = o.alloc(65536, 65536); t2 = o.alloc(65536, 65536)
    o.w32(0x402f4, t1); o.w32(0x402f8, t2); o.call(0x14834)
    return t1, t2

# ---------------------------------------------------------------- table generators
o = Orig(); a = o.alloc(65536); o.call(0x14639, eax=a); T('radialCosSpot', {}, {}, {'dst': o.read(a, 65536)})
o = Orig(); a = o.alloc(65536); o.call(0x146f9, eax=a); T('radialDiscMask', {}, {}, {'dst': o.read(a, 65536)})
o = Orig(); t1, t2 = blend_tables(o); T('screenBlendTables', {}, {}, {'t1': o.read(t1, 65536), 't2': o.read(t2, 65536)})
o = Orig(); a = o.alloc(9216); o.call(0x148c4, eax=a); T('colorMatrixTables', {}, {}, {'dst': o.read(a, 9216)})
o = Orig(); a = o.alloc(131072); s = o.alloc(65536); h = rb(65536); o.write(s, h); o.call(0x14b3d, eax=a, edx=s)
T('bumpDisplacementMap', {}, {'h': h}, {'dst': o.read(a, 131072)})
o = Orig(); a = o.alloc(65536); o.call(0x14c51, eax=a); T('cosCosPlasma', {}, {}, {'dst': o.read(a, 65536)})
o = Orig(); rays = o.alloc(0x2f000); pairs = o.alloc(0x13880 * 4); tmp = o.alloc(64000)
n = o.call(0x14d0b, eax=rays, edx=pairs, ebx=tmp).eax
T('radialRayTables', {'n': n}, {}, {'rays': o.read(rays, 0x2f000), 'pairs': o.read(pairs, n * 4), 'tmp': o.read(tmp, 64000)})
pal_file = open(os.path.join(ROOT, 'raw', 'pal.sc'), 'rb').read()
o = Orig(); a = o.alloc(262144); pp = o.alloc(1024); o.write(pp, pal_file); o.call(0x15168, eax=a, edx=pp + 10)
T('paletteShadeLut', {}, {'pal': pal_file[10:10 + 768]}, {'dst': o.read(a, 262144)})
d = rb(262144)
for addr, name in ((0x1478a, 'halveDwords'), (0x147df, 'invertDwords')):
    o = Orig(); a = o.alloc(262144); o.write(a, d); o.call(addr, eax=a); T(name, {}, {'src': d}, {'dst': o.read(a, 262144)})
o = Orig(); a = o.alloc(262144); o.call(0x14f53, eax=a); T('colourRampLut', {}, {}, {'dst': o.read(a, 262144)})

# ---------------------------------------------------------------- blur
def blur_env():
    o = Orig()
    tab = o.alloc(256 * 63 * 64 + 4096)
    o.w32(0x16b8f, tab); o.call(0x16c93)
    big = o.alloc(256 * 300); o.w32(0x16b38, big)
    return o
def px_patterns():
    return [real32('fullpics/simulcra.gfx'), rb(256000), real32('fullpics/truesimu.gfx')]
for r in (3, 4, 7, 16, 33, 63, 64, 100):
    for k, src in enumerate(px_patterns()[:2] if r not in (3, 16) else px_patterns()):
        for name, addr in (('boxBlurH', 0x16cdd), ('boxBlurV', 0x16e53)):
            o = blur_env(); s = o.alloc(256000); dd = o.alloc(256000); o.write(s, src); o.write(dd, bytes(256000))
            o.call(addr, eax=r, esi=s, edi=dd)
            T(name, {'r': r}, {'src': src}, {'dst': o.read(dd, 256000)})
radii = [rnd.choice([0, 1, 2, 3, 5, 8, 20, 40, 63, 64, 90]) for _ in range(200)]
rad = b''.join(struct.pack('<i', v) for v in radii)
o = blur_env(); s = o.alloc(256000); dd = o.alloc(256000); ra = o.alloc(800); o.write(s, src); o.write(ra, rad)
o.call(0x16ffb, eax=ra, esi=s, edi=dd)
T('boxBlurHVar', {}, {'src': src, 'radii': rad}, {'dst': o.read(dd, 256000)})
# radial path blur: real tables from 14d0b
o = Orig(); rays = o.alloc(0x2f000 + 4096); pairs = o.alloc(0x13880 * 4); tmp = o.alloc(64000)
npairs = o.call(0x14d0b, eax=rays, edx=pairs, ebx=tmp).eax
o.w32(0x402fc, pairs); o.w32(0x40300, npairs)
for n in (1, 3, 6):
    srcimg = (ASSETS['fullpics/mask5.gfx']['px'][:64000])
    s = o.alloc(64000); dd = o.alloc(64000); o.write(s, srcimg)
    o.write(dd, bytes(rnd.randrange(256) for _ in range(64000)))
    pre = o.read(dd, 64000)
    o.call(0x1743b, eax=n, edx=rays, edi=dd, esi=s)
    T('radialPathBlur', {'n': n, 'npairs': npairs}, {'rays': o.read(rays, 0x2f000 + (2 << n)), 'pairs': o.read(pairs, npairs * 4), 'src': srcimg, 'out0': pre}, {'out': o.read(dd, 64000)})

# ---------------------------------------------------------------- memset / memcpy
o = Orig(); a = o.alloc(4096); o.write(a, rb(4096)); o.call(0x17e46, eax=a + 3, edx=0x5a, ebx=1001)
T('memset', {'off': 3, 'val': 0x5a, 'n': 1001}, {}, {})   # (trivial) check in js only
tests.pop()
o = Orig(); a = o.alloc(4096); b = o.alloc(4096); src = rb(4096); o.write(a, src); o.write(b, rb(4096)); pre = o.read(b, 4096)
o.call(0x1c48f, eax=b + 1, edx=a + 5, ebx=1003)
T('memcpy', {'d': 1, 's': 5, 'n': 1003}, {'src': src, 'dst0': pre}, {'dst': o.read(b, 4096)})
o = Orig(); a = o.alloc(4096); o.write(a, pre); o.call(0x17e46, eax=a + 3, edx=0x5a, ebx=1001)
T('memset', {'off': 3, 'val': 0x5a, 'n': 1001}, {'dst0': pre}, {'dst': o.read(a, 4096)})

# ---------------------------------------------------------------- GFX in-memory images (as built by func_15a48)
def rle32(px):
    n = len(px) // 4; w = struct.unpack('<%dI' % n, px); out = []; i = 0
    while i < n:
        c = 0
        while i < n and w[i] == 0: i += 1; c += 1
        out.append(c)
        if i >= n: break
        run = []
        while i < n and w[i] != 0: run.append(w[i]); i += 1
        out.append(len(run) | 0x80000000); out += run
    out.append(0xffffffff)
    return struct.pack('<%dI' % len(out), *out)
def gfx_image(name, rle=None):
    g = ASSETS[name]; hdr = bytearray(b'GFX:' + struct.pack('<II', g['w'], g['h']) + bytes([g['bpp'], 0]) + b'\0' * 8)
    if g['bpp'] == 0x20 and rle: hdr[13] = 1; data = rle32(g['px'])
    else:
        hdr[13] = 1 if (g['bpp'] == 8 and g['flags'] & 1) else 0; data = g['px']
    struct.pack_into('<I', hdr, 14, len(data))
    return bytes(hdr) + data
def put_gfx(o, img): a = o.alloc(len(img) + 16); o.write(a, img); return a
def small_img(w, h, bpp, rle):      # synthetic sprite with transparent holes
    if bpp == 8: px = bytes(rnd.choice([0, 0, 0, rnd.randrange(1, 256)]) for _ in range(w * h)); g = {'w': w, 'h': h, 'bpp': 8, 'flags': 0, 'px': px}
    else: px = b''.join(struct.pack('<I', rnd.choice([0, 0, rnd.getrandbits(24), rnd.getrandbits(32) | 1])) for _ in range(w * h)); g = {'w': w, 'h': h, 'bpp': 0x20, 'flags': 1 if rle else 0, 'px': px}
    return g
def img_of(g):
    hdr = bytearray(b'GFX:' + struct.pack('<II', g['w'], g['h']) + bytes([g['bpp'], 1 if g['flags'] & 1 else 0]) + b'\0' * 8)
    data = rle32(g['px']) if (g['bpp'] == 0x20 and g['flags'] & 1) else g['px']
    struct.pack_into('<I', hdr, 14, len(data)); return bytes(hdr) + data

BLITS = [('blitAdd', 0x1c4f6), ('blitDifference', 0x1c7a6), ('blitLighten', 0x1c91e)]
screens = [real32(), rb(256000)]
cases = []
for (w, h, bpp, rle, x, y) in ((40, 30, 0x20, False, 100, 50), (50, 20, 0x20, True, 7, 3), (33, 41, 8, False, 200, 120), (1, 5, 0x20, False, 319, 0)):
    cases.append((small_img(w, h, bpp, rle), x, y))
for nm in ('smalpics/jp05.gfx', 'smalpics/jp01.gfx'):
    g = dict(ASSETS[nm]); cases.append((g, 0, 0))
g = dict(ASSETS['fullpics/truesimu.gfx']); g['flags'] = 1; cases.append((g, 0, 0))
g = dict(ASSETS['fullpics/truesimu.gfx']); g['flags'] = 0; cases.append((g, 0, 0))
for name, addr in BLITS:
    for ci, (g, x, y) in enumerate(cases):
        o = Orig(); sc = o.alloc(256000 + 4 * 64000); o.write(sc, screens[ci & 1]); im = put_gfx(o, img_of(g))
        o.call(addr, esi=im, edi=sc + (y * 320 + x) * 4)
        T(name, {'x': x, 'y': y, 'w': g['w'], 'h': g['h'], 'bpp': g['bpp'], 'flags': g['flags'] & 1}, {'scr': screens[ci & 1], 'px': g['px']}, {'scr': o.read(sc, 256000)})
# blitCopy
for g in (ASSETS['fullpics/truesimu.gfx'], dict(ASSETS['fullpics/truesimu.gfx'], flags=1)):
    o = Orig(); sc = o.alloc(256000 + 64); o.write(sc, rb(256000)); pre = o.read(sc, 256000); im = put_gfx(o, img_of(g)); o.call(0x1c4b4, esi=im, edi=sc)
    T('blitCopy', {'w': g['w'], 'h': g['h'], 'bpp': g['bpp'], 'flags': g['flags'] & 1}, {'scr': pre, 'px': g['px']}, {'scr': o.read(sc, 256000)})

# bbox 1c34e
for trial in range(3):
    n = 40 + trial; pts = [rnd.choice([-50.0, 3.5, 100.25, 400.0, 250.5, -1.0, 199.0]) * rnd.random() * (1 + trial) for _ in range(2 * n)]
    o = Orig(); obj = o.alloc(0x100); arr = o.alloc(8 * n)
    o.w32(obj, n); o.w32(obj + 0x44, arr); o.write(arr, struct.pack('<%df' % (2 * n), *pts)); o.call(0x1c34e, eax=obj)
    T('projectedBBox', {'n': n}, {'xy': struct.pack('<%df' % (2 * n), *pts)}, {'bbox': o.read(0x40358, 16)})

# ---------------------------------------------------------------- mask fades
for name, addr in (('maskFadeToBlack', 0x1ec58),):
    for thr in (0, 5, 100, 250):
        o = Orig(); t1, t2 = blend_tables(o); sc = o.alloc(256000); m = o.alloc(64000)
        src = real32(); mk = bytes((i * 7 + (i >> 8) * 3 + rnd.randrange(3)) & 255 for i in range(64000))
        o.write(sc, src); o.write(m, mk); o.call(addr, esi=m, edi=sc, edx=thr)
        T(name, {'thr': thr}, {'scr': src, 'mask': mk, 'T': o.read(t2, 65536)}, {'scr': o.read(sc, 256000)})
for thr in (0, 7, 200):
    o = Orig(); t1, t2 = blend_tables(o); sc = o.alloc(256000); m = o.alloc(64000); bi = o.alloc(256000)
    src = real32(); other = real32('fullpics/truesimu.gfx')[::-1]; mk = bytes((i * 5 + (i >> 8) * 11) & 255 for i in range(64000))
    o.write(sc, src); o.write(m, mk); o.write(bi, other); o.call(0x1ecaa, esi=m, edi=sc, ebx=bi, edx=thr)
    T('maskWipeCrossfade', {'thr': thr}, {'scr': src, 'mask': mk, 'b': other, 'T': o.read(t2, 65536)}, {'scr': o.read(sc, 256000)})
for name, addr, hasb in (('alphaMaskCrossfade', 0x1ee44, 1), ('maskInvert', 0x1eeb4, 0)):
    o = Orig(); t1, t2 = blend_tables(o); sc = o.alloc(256000); m = o.alloc(64000); bi = o.alloc(256000)
    src = rb(256000); other = rb(256000); mk = bytes(rnd.choice([0, 255, rnd.randrange(256)]) for _ in range(64000))
    o.write(sc, src); o.write(m, mk); o.write(bi, other)
    o.call(addr, esi=m, edi=sc, ebx=bi)
    ins = {'scr': src, 'mask': mk, 'T': o.read(t2, 65536)}
    if hasb: ins['b'] = other
    T(name, {}, ins, {'scr': o.read(sc, 256000)})

# lightMapAdd 22b43 : eax=src dwords, ebx=map8, esi=word table, edi=dst, edx=dx
for dx in (0, 0x1234, 0xffff):
    o = Orig(); src = rb(262144); disp = rb(131072); mp = rb(65536)
    s = o.alloc(262144); dd = o.alloc(262144); di = o.alloc(131072); m = o.alloc(65536); o.write(s, src); o.write(di, disp); o.write(m, mp)
    o.call(0x22b43, eax=s, ebx=m, esi=di, edi=dd, edx=dx)
    T('lightMapAdd', {'dx': dx}, {'src': src, 'disp': disp, 'map': mp}, {'dst': o.read(dd, 262144)})
# lutLookup2D 22b9c: ebx=lo bytes, esi=hi bytes, edx=lut, edi=dst
o = Orig(); lo = rb(64000); hi = rb(64000); lut = rb(262144)
l = o.alloc(64000); h_ = o.alloc(64000); lt = o.alloc(262144); dd = o.alloc(256000); o.write(l, lo); o.write(h_, hi); o.write(lt, lut)
o.call(0x22b9c, ebx=l, esi=h_, edx=lt, edi=dd)
T('lutLookup2D', {}, {'lo': lo, 'hi': hi, 'lut': lut}, {'dst': o.read(dd, 256000)})
# colorMatrixRect 22990
o = Orig(); tb = o.alloc(9216); o.call(0x148c4, eax=tb); tab = o.read(tb, 9216)
for (x0, y0, x1, y1) in ((10, 20, 200, 150), (-5, 0, 320, 199), (100, 100, 101, 101), (0, 0, 400, 250)):
    src = real32(); sc = o.alloc(256000); o.write(sc, src)
    o.call(0x22990, eax=x0, ebx=y0, ecx=x1, edx=y1, esi=tb, edi=sc)
    T('colorMatrixRect', {'r': [x0, y0, x1, y1]}, {'scr': src, 'tab': tab}, {'scr': o.read(sc, 256000)})

# ---------------------------------------------------------------- mesh tables 22c39 / 22e0e
for tm in (0.0, 13.7, 250.25, 1000.5):
    o = Orig(); o.wf32(0x40310, tm); a = o.alloc(26 * 41 * 12)
    o.call(0x22e0e, eax=a); T('warpMeshB', {'t': tm}, {}, {'dst': o.read(a, 26 * 41 * 12)})
    for mix in (0.0, 0.3, 1.0, 0.77):
        o = Orig(); o.wf32(0x40310, tm); a = o.alloc(26 * 41 * 12)
        o.call(0x22c39, eax=a, stack=[mix]); T('warpMeshA', {'t': tm, 'mix': mix}, {}, {'dst': o.read(a, 26 * 41 * 12)})

# ---------------------------------------------------------------- font + text
def font_mem(o, name, first, n):
    g = ASSETS[name]; img = img_of(g); a = put_gfx(o, img)
    obj = o.call(0x174fe, eax=a, edx=first, ebx=n).eax
    return obj
for name, first, n in (('fonts/sysf.gfx', 32, 90), ('fonts/verdana.gfx', 33, 95), ('fonts/verd_sm.gfx', 33, 95)):
    o = Orig(); obj = font_mem(o, name, first, n)
    offs = o.r32(obj + 0x14); wid = o.r32(obj + 0x18)
    T('buildFont', {'name': name, 'first': first, 'n': n}, {'px': ASSETS[name]['px']}, {'offs': o.read(offs, 2 * n), 'wid': o.read(wid, n), 'hdr': o.read(obj, 0x1c)[4:20]})
    # text printing
    texts = ['Hello World! ZILOG', 'AB\x0bCD\x0bEF', 'Line1\nLine2\x07\x35 sp\x08\x80 half\x0c\x32\nx', 'abcdefghijklmnopqrstuvwxyz0123456789']
    o2 = Orig(); t1, t2 = blend_tables(o2); obj = font_mem(o2, name, first, n)
    for txt in texts:
        txt = ''.join(c if (c in '\n\x0b\x07\x08\x0c ' or first <= ord(c) < first + n) else '?' for c in txt)
        sc = o2.alloc(256000 + 4096); base = real32(); o2.write(sc, base)
        ctx = o2.alloc(0x40); o2.w32(0x40304, ctx); o2.w32(ctx + 8, sc); o2.w32(ctx + 0xc, t1)
        sa = o2.alloc(256); raw = txt.encode('latin1') + b'\0'; o2.write(sa, raw)
        # keep glyph codes in range for the font
        o2.call(0x17641, eax=sa, edx=10, ebx=5, ecx=obj)
        T('printText', {'name': name, 'first': first, 'n': n, 'txt': txt, 'x': 10, 'y': 5},
          {'px': ASSETS[name]['px'], 'scr': base, 't1': o2.read(t1, 65536), 't2': o2.read(t2, 65536)}, {'scr': o2.read(sc, 256000)})

# ---------------------------------------------------------------- flip converters (VRAM write stream captured with a memory hook)
for bpp, addr in ((32, 0x254ba), (24, 0x257bb), (16, 0x25649), (15, 0x2570c)):
    o = Orig(); o.mu.mem_map(0xa0000, 0x20000); stream = bytearray()
    o.mu.hook_add(UC_HOOK_MEM_WRITE, lambda uc, acc, a, size, val, ud: stream.extend((val & ((1 << (8 * size)) - 1)).to_bytes(size, 'little')), None, 0xa0000, 0xbffff)
    src = real32() if bpp != 24 else rb(256000)
    sc = o.alloc(256000 + 64); o.write(sc, src)
    o.w16(0x3f5da, 0x10000 >> 10 if False else 64)      # bank granularity (VESA window granularity in KB)
    o.call(addr, eax=sc, edx=0) if bpp == 32 else o.call(addr, eax=sc)
    T('vesaFramebuffer', {'bpp': bpp}, {'scr': src}, {'fb': bytes(stream)})

# ---------------------------------------------------------------- grid warp renderers + sprites
def mesh_nodes(seed, t, kind):
    """real mesh from func_22e0e / 22c39, then randomised pages and a few forced shade bytes"""
    o = Orig(); o.wf32(0x40310, t); a = o.alloc(26 * 41 * 12)
    if kind == 'B': o.call(0x22e0e, eax=a)
    else: o.call(0x22c39, eax=a, stack=[0.5])
    n = list(struct.unpack('<%di' % (26 * 41 * 3), o.read(a, 26 * 41 * 12)))
    r = random.Random(seed)
    for i in range(26 * 41):
        if r.random() < 0.5: n[i * 3] = (n[i * 3] & 0xffffff) | (r.randrange(2) << 24)
        if r.random() < 0.08: n[i * 3 + 2] = r.choice([0, 0xff0000, 0x00ffff, 0xff1234, 0x120000])
        if r.random() < 0.1: n[i * 3 + 1] = r.getrandbits(24)
    return struct.pack('<%di' % len(n), *n)
for (name, addr, kind, tab_addr) in (('gridWarpTex32', 0x1d6a4, 32, 0x402f4), ('gridWarpTex8', 0x1e266, 8, 0x402f8),
                                     ('gridWarpStrip8', 0x1e62e, 8, 0x402f4), ('gridWarpStrip8Inv', 0x1e941, 8, 0x402f8)):
    for (seed, tm, mk) in ((1, 0.0, 'B'), (2, 55.5, 'A'), (3, 400.0, 'B')):
        nodes = mesh_nodes(seed, tm, mk)
        o = Orig(); t1, t2 = blend_tables(o)
        if kind == 32:
            tex = ASSETS['textures/env1.gfx']['px'][:262144] + rb(262144)    # 2 pages of 65536 dwords
            tb = o.alloc(len(tex), 0x40000); o.write(tb, tex); scr = o.alloc(256000 + 4096); init = rb(256000)
        else:
            tex = ASSETS['textures/lites2.gfx']['px'][:65536] + rb(65536)
            tb = o.alloc(len(tex), 0x10000); o.write(tb, tex); scr = o.alloc(64000 + 4096); init = rb(64000)
        o.write(scr, init); na = o.alloc(len(nodes)); o.write(na, nodes)
        o.call(addr, eax=scr, ebx=tb, ecx=na)
        T(name, {'seed': seed}, {'scr0': init, 'tex': tex, 'nodes': nodes, 'T': o.read(t1 if tab_addr == 0x402f4 else t2, 65536)}, {'scr': o.read(scr, 256000 if kind == 32 else 64000)})
# sprites
spot = ASSETS['textures/lites2.gfx']['px'][:65536]
cases = [((160 << 8) + 40, (100 << 8) + 200, (30 << 8) + 17), ((20 << 8), (10 << 8) + 99, (50 << 8)), ((300 << 8) + 255, (190 << 8) + 3, (25 << 8) + 128),
         ((-10 << 8) + 7, (50 << 8) + 128, (40 << 8) + 5), ((100 << 8), (-30 << 8), (45 << 8) + 90), ((330 << 8), (120 << 8), (30 << 8)),
         ((160 << 8), (100 << 8), (3 << 8)), ((318 << 8) + 128, (199 << 8), (1 << 8) + 100), ((5 << 8), (5 << 8), (300 << 8)), ((160 << 8), (190 << 8) + 50, 70 << 8)]
for (name, addr, alpha) in (('spriteSubtract', 0x1f337, None), ('spriteAddAlpha', 0x1f6b2, True), ('spriteSubtractAlpha', 0x1fab7, True)):
    for ci, (X, Y, R) in enumerate(cases):
        for al in ((0, 77, 200, 255) if alpha else (0,)):
            if alpha and ci % 3 and al in (0, 255): continue
            o = Orig(); t1, t2 = blend_tables(o); scr = o.alloc(256000 + 4 * 4096); init = rb(256000); mk = o.alloc(65536, 0x10000)
            mdata = bytes(b if (i * 7) % 5 else 0 for i, b in enumerate(spot))
            o.write(scr, init); o.write(mk, mdata)
            o.call(addr, eax=al, edi=X, esi=Y, ecx=R, edx=scr, ebx=mk)
            T(name, {'X': X, 'Y': Y, 'R': R, 'alpha': al}, {'scr0': init, 'mask': mdata, 'T': o.read(t2, 65536)}, {'scr': o.read(scr, 256000)})

json.dump(tests, open(sys.argv[1], 'w'))
print(len(tests), 'tests')
