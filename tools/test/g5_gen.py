"""Differential vectors for site/js/scenes/_g5mesh.js + _g5draw.js (scenes 8/9/credits helper functions) from the ORIGINAL code under Unicorn.
   python g5_gen.py out.json   then   node g5.test.mjs out.json   (run_g5.sh)"""
import sys, os, json, base64, struct, random, math
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
OUT = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, 'tools', 'out', 'g5_vectors.json')
rnd = random.Random(5)
b64 = lambda b: base64.b64encode(bytes(b)).decode()
def mob(n): return open(os.path.join(ROOT, 'raw', '3d', n), 'rb').read()
import subprocess, tempfile
tmp = tempfile.mkdtemp()
subprocess.check_call(['node', '-e', '''
import fs from "fs"; import { makeEnv } from "%s/site/js/env.js";
const env = makeEnv(new Uint8Array(fs.readFileSync("%s/site/data/data.dat")));
const g = env.gfx("fullpics/hmask2.gfx"); fs.writeFileSync("%s/hmask2.bin", g.px);
''' % (ROOT, ROOT, tmp), '--input-type=module'])
HMASK = open(tmp + '/hmask2.bin', 'rb').read()
cases = []

def world():
    o = Orig()
    luts = o.alloc(0x100000, 0x40000)
    o.w32(0x402f4, luts); o.w32(0x402f8, luts + 0x10000); o.call(0x14834)
    scr = o.alloc(256000); o.w32(0x402f0, scr)
    tgt = o.alloc(32); o.w32(tgt, 320); o.w32(tgt + 4, 200); o.w32(tgt + 8, scr); o.w32(0x40304, tgt)
    return o, scr
def load(o, name):
    d = mob(name); p = o.alloc(len(d) + 16); o.write(p, d); return o.call(0x16478, eax=p).eax
def W(o, m): return struct.unpack('<21I', o.read(m, 0x54))
def mkobj(o, mesh, cx=160.0, cy=100.0, dist=3.5, focal=140.0, tex=0, mode=0, sub=0):
    ob = o.alloc(0x40); o.w32(ob, mesh); o.wf32(ob + 4, cx); o.wf32(ob + 8, cy); o.wf32(ob + 0xc, dist); o.wf32(ob + 0x10, focal)
    o.w32(ob + 0x14, tex); o.w8(ob + 0x1c, mode); o.w8(ob + 0x1d, sub); return ob
def mesh_out(o, m, n=None):
    w = W(o, m); np_ = w[0]
    d = {'npts': np_, 'pts': b64(o.read(w[1], np_ * 12)), 'faces': b64(o.read(w[7], w[6] * 12)), 'nfaces': w[6]}
    if w[2]: d['xpts'] = b64(o.read(w[2], np_ * 12))
    if w[0x12]: d['uv'] = b64(o.read(w[0x12], np_ * 8))
    return d

# ---- mesh preparation functions
for name, fn, args in (('hexp_on2.mob', 0x1b687, {}), ('hexp_on2.mob', 0x1b04f, dict(edx=320, ebx=200)), ('zilog1_o.mob', 0x1b04f, dict(edx=256, ebx=256)),
                       ('cub_tun2.mob', 0x1b1b4, {}), ('zilog1.mob', 0x1b1b4, {}), ('zilog1.mob', 0x1b7e3, {}), ('zilog1.mob', 0x1b854, {})):
    o, _ = world(); m = load(o, name); r = o.call(fn, eax=m, **args)
    c = {'kind': 'prep', 'fn': hex(fn), 'mob': name, 'args': args, 'out': mesh_out(o, m)}
    if fn == 0x1b854: c['ret'] = b64(o.read(r.eax, (W(o, m)[0] >> 1) * 4))
    cases.append(c); print('prep', hex(fn), name, flush=True)
o, _ = world(); sp = struct.unpack('<f', struct.pack('<f', 50.0))[0]
g = o.call(0x1b960, eax=20, edx=20, stack=[sp]).eax; wg = W(o, g)
cases.append({'kind': 'grid', 'npts': wg[0], 'pts': b64(o.read(wg[1], wg[0] * 12)), 'nedges': wg[0xf], 'edges': b64(o.read(wg[0x10], wg[0xf] * 8))})
o.call(0x1b2a4, eax=g); cases[-1]['uv'] = b64(o.read(W(o, g)[0x12], wg[0] * 8)); print('grid', flush=True)

# ---- deformers (time in DAT_00040310)
def deform(name, fn, mob_name, tvals, pre=None, extra=None, setup=None):
    for t in tvals:
        o, _ = world(); m = load(o, mob_name); o.wf32(0x40310, t)
        kw = {}; stack = []
        if setup: kw, stack = setup(o, m)
        if mob_name == 'grid':
            pass
        w = W(o, m); xp = o.alloc(w[0] * 12); o.w32(m + 8, xp)
        o.call(fn, eax=m, stack=stack, **kw)
        c = {'kind': 'deform', 'name': name, 't': t, 'mob': mob_name, 'out': b64(o.read(xp, w[0] * 12)), 'stack': stack}
        if 'edx' in kw: c['edx_pair'] = True
        cases.append(c)
    print('deform', name, flush=True)
T = [0.0, 3.7, 101.5, 363.2, 777.0, 2150.25]
deform('20a10', 0x20a10, 'cyl.mob', T)
deform('2112c', 0x2112c, 'cub_tun2.mob', T)
for p in ((12 - 11 * math.cos(0.15 * 20), 2 * (1 - math.cos(2.0)), (1 - math.cos(2.0))), (1.0, 0.0, 0.0), (5.3, 1.7, 0.4)):
    deform('21664', 0x21664, 'hexp_on2.mob', [0.0, 10.5, 40.0], setup=lambda o, m, p=p: ({}, [p[1], p[2], p[0]]))
    cases[-1]['p'] = p
    for c in cases[-3:]: c['p'] = p
# grid mesh (built by the original 1b960)
for t in T:
    o, _ = world(); g = o.call(0x1b960, eax=20, edx=20, stack=[sp]).eax; o.wf32(0x40310, t); wg = W(o, g); xp = o.alloc(wg[0] * 12); o.w32(g + 8, xp)
    o.call(0x206e0, eax=g); cases.append({'kind': 'deform', 'name': '206e0', 't': t, 'mob': 'grid', 'out': b64(o.read(xp, wg[0] * 12))})
print('206e0', flush=True)
for t, pv in ((0.0, 150.0), (50.0, 210.5), (999.0, 120.0)):
    o, _ = world(); m = load(o, 'zilog1.mob'); o.call(0x1b854, eax=m); o.wf32(0x40310, t)
    w = W(o, m); xp = o.alloc(w[0] * 12); o.w32(m + 8, xp)
    pr = o.call(0x1b854, eax=m).eax
    o.call(0x219e8, eax=m, edx=pr, stack=[pv])
    cases.append({'kind': 'deform', 'name': '219e8', 't': t, 'mob': 'zilog1.mob', 'out': b64(o.read(xp, w[0] * 12)), 'pv': pv, 'pair': b64(o.read(pr, (w[0] >> 1) * 4))})
print('219e8', flush=True)

# ---- drawing: 1ac25 and the sprite loops
def spot(o):
    a = o.alloc(65536, 65536); o.call(0x14639, eax=a); return a
bg = bytes(rnd.randrange(256) for _ in range(256000)); bg0 = bytes(256000)
def draw_case(name, mobn, kind, cam, deformfn=None, t=10.0, mode=6, sub=0, p=None):
    o, scr = world(); m = load(o, mobn); o.wf32(0x40310, t)
    if mobn == 'cub_tun2.mob': o.call(0x1b1b4, eax=m)
    if mobn == 'zilog1.mob': o.call(0x1b1b4, eax=m)
    w = W(o, m); xp = o.alloc(w[0] * 12); o.w32(m + 8, xp)
    tex = spot(o); ob = mkobj(o, m, tex=tex, mode=mode, sub=sub, **cam)
    if deformfn == 0x2112c: o.call(0x2112c, eax=m)
    elif deformfn == 0x20a10: o.call(0x20a10, eax=m)
    else: o.call(0x17e5e, eax=ob, stack=[0.3, 0.5, 0.2])
    if deformfn:
        o.w8(ob + 0x1c, 0); o.call(0x17e5e, eax=ob, stack=[0.2 * math.sin(t * .01), 0.3, 1.5 * 0.4])
    o.w8(ob + 0x1c, mode); o.call(0x1870b, eax=ob)
    w = W(o, m); np_ = w[0]
    o.write(scr, bg if kind != 'sprite' else bg0)
    inj = {'xpts': b64(o.read(w[2], np_ * 12)), 'p2d': b64(o.read(w[0x11], np_ * 8)), 'invz': b64(o.read(w[0x14], np_ * 4))}
    if kind == 'tri':
        o.call(0x1ac25, eax=ob)
    else:
        mk = o.alloc(64000 + 64); o.write(mk, HMASK)
        if kind == 'spr_front': o.call(0x1a415, eax=ob, edx=mk, stack=[p])
        elif kind == 'spr_back': o.call(0x1a5ea, eax=ob, stack=[p])
        else: o.call(0x19f57, eax=ob, stack=[p])
    cases.append({'kind': 'draw', 'name': name, 'draw': kind, 'mob': mobn, 'deform': deformfn, 't': t, 'cam': cam, 'mode': mode, 'sub': sub, 'p': p,
                  'bg': b64(bg if kind != 'sprite' else bg0), 'out': b64(o.read(scr, 256000)), 'inj': inj, 'uvsrc': b64(o.read(W(o, m)[0x12], np_ * 8)) if W(o, m)[0x12] else None,
                  'tex': b64(o.read(tex, 65536))})
    print('draw', name, flush=True)
cam0 = dict(cx=90.0, cy=100.0, dist=3.5, focal=140.0)
draw_case('tri_cub', 'cub_tun2.mob', 'tri', cam0, 0x2112c, t=12.0)
draw_case('tri_cub2', 'cub_tun2.mob', 'tri', dict(cx=40.0, cy=60.0, dist=2.4, focal=140.0), 0x2112c, t=200.0)
draw_case('tri_zil', 'zilog1.mob', 'tri', dict(cx=160.0, cy=100.0, dist=3.5, focal=140.0), None, t=5.0)
draw_case('tri_zil_clip', 'zilog1.mob', 'tri', dict(cx=300.0, cy=20.0, dist=2.2, focal=140.0), None, t=5.0)
for k, dist in (('a', 4.5), ('b', 3.0)):
    draw_case('spr_front_' + k, 'cyl.mob', 'spr_front', dict(cx=90.0, cy=100.0, dist=dist, focal=180.0), 0x20a10, t=100.0 + len(k) * 33, mode=9, p=26.0 if k == 'a' else 12.5)
    draw_case('spr_back_' + k, 'cyl.mob', 'spr_back', dict(cx=90.0, cy=100.0, dist=dist, focal=180.0), 0x20a10, t=150.0, mode=9, p=26.0 if k == 'a' else 12.5)
    draw_case('spr_all_' + k, 'hexp_on2.mob', 'sprite', dict(cx=160.0, cy=99.0, dist=0.666, focal=180.0), None, t=1.0, mode=9, p=6.0)
json.dump({'cases': cases}, open(OUT, 'w')); print('wrote', OUT, len(cases))
