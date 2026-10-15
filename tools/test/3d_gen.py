"""Generate differential-test vectors for site/js/lib/mesh3d*.js by running the ORIGINAL 3D engine under Unicorn.
   python 3d_gen.py out.json        then:  node 3d.test.mjs out.json      (see run_3d.sh)
 Cases: load (0x16478), xform (0x17e5e 0x1841d 0x185d4 0x18144 0x1870b), render (0x18beb, every mode the scenes use),
 each render case in two flavours: 'inj' (JS starts from the ORIGINAL transformed/projected arrays -> isolates the
 rasterizers, expected to be bit exact) and 'full' (JS runs the whole pipeline).
"""
import sys, os, json, base64, struct, random, subprocess
HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, '..', '..'))
sys.path.insert(0, os.path.join(ROOT, 're', 'harness'))
from orig import Orig as _Orig
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX

class Orig(_Orig):
    """Unicorn has no usable ES: hook the es-string helpers (memcpy 0x1c48f, memcmp 0x2431d)."""
    def _code(self, uc, addr, size, ud):
        if addr == 0x1c48f:
            d, s_, n = (uc.reg_read(r) for r in (UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX))
            uc.mem_write(d, bytes(uc.mem_read(s_, n))); self._ret(uc)
        elif addr == 0x2431d:
            a, b, n = (uc.reg_read(r) for r in (UC_X86_REG_EAX, UC_X86_REG_EDX, UC_X86_REG_EBX))
            x, y = bytes(uc.mem_read(a, n)), bytes(uc.mem_read(b, n))
            uc.reg_write(UC_X86_REG_EAX, (x > y) - (x < y) & 0xffffffff); self._ret(uc)
        else: super()._code(uc, addr, size, ud)

OUT = sys.argv[1] if len(sys.argv) > 1 else os.path.join(ROOT, 'tools', 'out', '3d_vectors.json')
SCR = os.environ.get('Z3D_SCRATCH', '/tmp/z3d_scratch'); os.makedirs(SCR, exist_ok=True)
AS = os.path.join(SCR, 'assets.json')
subprocess.check_call(['node', os.path.join(HERE, '3d_assets.mjs'), AS])
ASSETS = {k: dict(v, px=base64.b64decode(v['px'])) for k, v in json.load(open(AS)).items()}
rnd = random.Random(99)
b64 = lambda b: base64.b64encode(bytes(b)).decode()
blobs, cases = {}, []
def blob(name, data):
    blobs[name] = b64(data); return name

def fpu_init(o):
    """Unicorn starts with FPU control word 0 = PRECISION CONTROL 24 BIT (single) and unmasked exceptions; the real program runs with
    fninit (0x37f: 64 bit mantissa, round nearest, masked). Without this every x87 intermediate would be rounded to float32."""
    d = o.alloc(16); code = o.alloc(16); o.write(d, b'\x7f\x03'); o.write(code, b'\xd9\x2d' + struct.pack('<I', d) + b'\xc3'); o.call(code)

def world():
    o = Orig(); fpu_init(o)
    luts = o.alloc(0x100000, 0x40000)
    o.w32(0x402f4, luts); o.w32(0x402f8, luts + 0x10000); o.call(0x14834)
    scr = o.alloc(256000); o.w32(0x402f0, scr)
    tgt = o.alloc(32); o.w32(tgt, 320); o.w32(tgt + 4, 200); o.w32(tgt + 8, scr); o.w32(0x40304, tgt)
    return o, scr

def load(o, mobname):
    d = ASSETS[mobname]['px']; p = o.alloc(len(d) + 16); o.write(p, d)
    return o.call(0x16478, eax=p).eax
def mesh_info(o, m):
    w = struct.unpack('<21I', o.read(m, 0x54)); return w
def mkobj(o, mesh, cx=160.0, cy=100.0, dist=6.5, focal=140.0, tex=0, mode=0, sub=0):
    ob = o.alloc(0x40); o.w32(ob, mesh); o.wf32(ob + 4, cx); o.wf32(ob + 8, cy); o.wf32(ob + 0xc, dist); o.wf32(ob + 0x10, focal)
    o.w32(ob + 0x14, tex); o.w8(ob + 0x1c, mode); o.w8(ob + 0x1d, sub); return ob
def rd(o, a, n): return o.read(a, n) if a else b''

# ---------------------------------------------------------------- loader
MOBS = ['3d/zilog1.mob', '3d/hexp_on2.mob', '3d/sph1024.mob', '3d/cyl.mob', '3d/cones3.mob', '3d/cub_tun2.mob', '3d/3b_2.mob']
for mn in MOBS:
    o, _ = world(); m = load(o, mn); w = mesh_info(o, m)
    npts, nf, ne = w[0], w[6], w[0xf]
    cases.append({'kind': 'load', 'mob': mn, 'blob': blob(mn, ASSETS[mn]['px']), 'npts': npts, 'nfaces': nf, 'nedges': ne,
                  'vf': blob(mn + '.vf', rd(o, w[0xc], (npts + nf * 3) * 4)), 'vfIdx': blob(mn + '.vfi', rd(o, w[0xd], npts * 4)),
                  'ef': blob(mn + '.ef', rd(o, w[0xe], ne * 8))})
    print('load', mn, npts, nf, ne, flush=True)

# ---------------------------------------------------------------- transform chain
def chain(o, mesh, obj, angles, nrm_angles, mode, mask=None):
    """returns dict of arrays after rotate (mode) -> face normals -> vertex normals -> rotate normals -> project"""
    w = mesh_info(o, mesh); npts, nf = w[0], w[6]
    o.w8(obj + 0x1c, mode)
    if mask is not None:
        mp = o.alloc(npts); o.write(mp, mask); o.w32(mesh + 0xc, mp)
    o.call(0x17e5e, eax=obj, stack=list(angles))
    o.call(0x1841d, eax=obj); o.call(0x185d4, eax=mesh)
    o.call(0x18144, eax=mesh, stack=list(nrm_angles))
    o.call(0x1870b, eax=obj)
    w = mesh_info(o, mesh)
    return {'xpts': o.read(w[2], npts * 12), 'fnrm': o.read(w[8], nf * 12), 'nrm': o.read(w[4], npts * 12), 'xnrm': o.read(w[5], npts * 12),
            'p2d': o.read(w[0x11], npts * 8), 'invz': o.read(w[0x14], npts * 4)}

for mn in ['3d/zilog1.mob', '3d/sph1024.mob', '3d/hexp_on2.mob']:
    for k in range(3):
        o, _ = world(); m = load(o, mn); npts = mesh_info(o, m)[0]
        ob = mkobj(o, m, cx=rnd.uniform(100, 220), cy=rnd.uniform(60, 140), dist=rnd.uniform(4, 9), focal=rnd.uniform(80, 200))
        ang = [rnd.uniform(-3, 3) for _ in range(3)]; ang2 = [rnd.uniform(-3, 3) for _ in range(3)]
        mask = bytes(rnd.choice([0, 1, 1, 2, 255]) for _ in range(npts)) if k == 2 else None
        r1 = chain(o, m, ob, ang, ang2, 9, mask)
        # second rotation with mode 0: cumulative, source = xpts (in place)
        ang3 = [rnd.uniform(-1, 1) for _ in range(3)]
        o.w8(ob + 0x1c, 0); o.call(0x17e5e, eax=ob, stack=list(ang3)); w = mesh_info(o, m)
        r2 = o.read(w[2], npts * 12)
        c = {'kind': 'xform', 'mob': mn, 'blob': blob(mn, ASSETS[mn]['px']), 'cx': ob and struct.unpack('<f', o.read(ob + 4, 4))[0],
             'cy': struct.unpack('<f', o.read(ob + 8, 4))[0], 'dist': struct.unpack('<f', o.read(ob + 0xc, 4))[0],
             'focal': struct.unpack('<f', o.read(ob + 0x10, 4))[0], 'ang': ang, 'ang2': ang2, 'ang3': ang3,
             'mask': blob('mask%d' % len(cases), mask) if mask else None}
        for kk, v in r1.items(): c[kk] = blob('x%d_%s' % (len(cases), kk), v)
        c['xpts_cum'] = blob('x%d_cum' % len(cases), r2)
        cases.append(c); print('xform', mn, k, flush=True)

# ---------------------------------------------------------------- render
env1, max_t2, city = (ASSETS['textures/' + n + '.gfx']['px'] for n in ('env1', 'max_t2', 'cityscap'))
bg = ASSETS['fullpics/simulcra.gfx']['px'][:256000]
bgn = bytes(rnd.randrange(256) for _ in range(256000))
sprite_tab = None
def render_case(name, mn, mode, sub, texbytes, uvkind, bgd, ang, nang, tex_align_extra=0, colors=False, cam=None, mask=False, npts_limit=None):
    o, scr = world()
    m = load(o, mn); w = mesh_info(o, m); npts, nf = w[0], w[6]
    tex = 0
    if texbytes is not None:
        tex = o.alloc(len(texbytes) + 0x40000, 0x40000); o.write(tex, texbytes)
    cam = cam or dict(cx=160.0, cy=100.0, dist=rnd.uniform(5, 8), focal=140.0)
    ob = mkobj(o, m, tex=tex, mode=9, sub=sub, **cam)
    uv = None
    if uvkind:
        ua = o.alloc(npts * 8)
        vals = []
        for i in range(npts):
            if uvkind == 'tex': vals += [rnd.uniform(0, 255), rnd.uniform(0, 255)]
            elif uvkind == 'col': vals += [float(rnd.randrange(0, 256)), float(rnd.randrange(0, 256))]
            elif uvkind == 'warp': vals += [rnd.uniform(1, 318), rnd.uniform(1, 198)]   # inside the 320x200 source image
            elif uvkind == 'texbig': vals += [rnd.uniform(-300, 600), rnd.uniform(-300, 600)]
        uv = struct.pack('<%df' % (npts * 2), *vals); o.write(ua, uv); o.w32(m + 0x48, ua)
    cols = None
    if colors:
        cols = bytes(rnd.randrange(256) for _ in range(npts * 4))
        ca = o.alloc(npts * 4); o.write(ca, cols); o.w32(0x40308, ca)
    mk = None
    if mask:
        mk = bytes(rnd.choice([0, 1, 1, 1]) for _ in range(npts)); mp = o.alloc(npts); o.write(mp, mk); o.w32(m + 0xc, mp)
    if npts_limit: o.w32(m, min(npts, npts_limit))
    o.write(scr, bgd)
    # transform in the original (mode 9 = source pts), then render with the real mode
    o.w8(ob + 0x1c, 9)
    o.call(0x17e5e, eax=ob, stack=list(ang))
    o.call(0x1841d, eax=ob); o.call(0x185d4, eax=m); o.call(0x18144, eax=m, stack=list(nang)); o.call(0x1870b, eax=ob)
    w = mesh_info(o, m); np_ = w[0]
    inj = {k: blob('%s_%s' % (name, k), o.read(w[i], n)) for k, i, n in
           (('xpts', 2, npts * 12), ('nrm', 4, npts * 12), ('xnrm', 5, npts * 12), ('p2d', 0x11, npts * 8), ('invz', 0x14, npts * 4), ('fnrm', 8, nf * 12))}
    o.w8(ob + 0x1c, mode); o.w8(ob + 0x1d, sub)
    o.call(0x18beb, eax=ob)
    out = o.read(scr, 256000)
    srt = None
    if mode <= 4:
        w = mesh_info(o, m); nv = w[0xb]
        srt = (blob(name + '_ord', o.read(w[10], nv * 4)), blob(name + '_key', o.read(w[9], nv * 4)))
    c = {'kind': 'render', 'name': name, 'mob': mn, 'blob': blob(mn, ASSETS[mn]['px']), 'mode': mode, 'sub': sub, 'ang': ang, 'nang': nang,
         'tex': blob(name + '_tex', texbytes) if texbytes is not None else None, 'uv': blob(name + '_uv', uv) if uv else None,
         'colors': blob(name + '_col', cols) if cols else None, 'mask': blob(name + '_mask', mk) if mk else None, 'npts_limit': npts_limit,
         'order': srt and srt[0], 'keys': srt and srt[1], 'bg': blob('bg_' + str(len(bgd)) + '_' + str(hash(bgd) & 0xffff), bgd), 'out': blob(name + '_out', out), 'inj': inj}
    c.update(cam); cases.append(c); print('render', name, flush=True)

def angs(): return [rnd.uniform(-3, 3) for _ in range(3)]
o_, _ = world(); sa = o_.alloc(65536, 65536); o_.call(0x14639, eax=sa); sprite_tab = o_.read(sa, 65536)
ramp = bytes(env1[:1024]) * 1                                   # first texture row = 256 dwords used as the 1-D ramp
two = env1[:262144] + max_t2[:262144]                           # env map texture + surface texture (2x256KB block)
scrimg = bg
for mn in ['3d/zilog1.mob', '3d/sph1024.mob']:
    t = mn.split('/')[1][:3]
    for k in range(2):
        render_case('m0_%s_%d' % (t, k), mn, 0, 0, env1[:262144], None, bg, angs(), angs())
        render_case('m1s0_%s_%d' % (t, k), mn, 1, 0, env1[:262144], None, bg, angs(), angs())
        render_case('m1s1_%s_%d' % (t, k), mn, 1, 1, env1[:262144], None, bgn, angs(), angs())
        render_case('m2_%s_%d' % (t, k), mn, 2, 0, two, 'tex', bg, angs(), angs())
        render_case('m3_%s_%d' % (t, k), mn, 3, 0, two, 'tex', bg, angs(), angs())
        render_case('m4s0_%s_%d' % (t, k), mn, 4, 0, city[:262144], 'tex', bg, angs(), angs())
        render_case('m4s2_%s_%d' % (t, k), mn, 4, 2, city[:262144], 'tex', bg, angs(), angs())
        render_case('m4s4_%s_%d' % (t, k), mn, 4, 4, bg, 'warp', bg, angs(), angs())
        render_case('m5_%s_%d' % (t, k), mn, 5, 3, None, None, bgn, angs(), angs())
        render_case('m6_%s_%d' % (t, k), mn, 6, 0, None, 'col', bg, angs(), angs())
        render_case('m6s5_%s_%d' % (t, k), mn, 6, 5, None, 'col', bg, angs(), angs())
        render_case('m7_%s_%d' % (t, k), mn, 7, 0, None, None, bg, angs(), angs())
        render_case('m8_%s_%d' % (t, k), mn, 8, 0, None, 'col', bg, angs(), angs())
        render_case('m9_%s_%d' % (t, k), mn, 9, 0, sprite_tab, None, bg, angs(), angs())
        render_case('m9s3_%s_%d' % (t, k), mn, 9, 3, sprite_tab, None, bg, angs(), angs(), colors=True)
# close-up / clipped variants (camera inside the screen edges -> polygon + sprite + line clipping)
for k in range(3):
    cam = dict(cx=rnd.uniform(20, 300), cy=rnd.uniform(10, 190), dist=rnd.uniform(1.6, 3.2), focal=140.0)
    render_case('clip_m0_%d' % k, '3d/zilog1.mob', 0, 0, env1[:262144], None, bg, angs(), angs(), cam=dict(cam))
    render_case('clip_m1s1_%d' % k, '3d/hexp_on2.mob', 1, 1, env1[:262144], None, bg, angs(), angs(), cam=dict(cam))
    render_case('clip_m2_%d' % k, '3d/zilog1.mob', 2, 0, two, 'texbig', bg, angs(), angs(), cam=dict(cam))
    render_case('clip_m4s4_%d' % k, '3d/hexp_on2.mob', 4, 4, bg, 'warp', bg, angs(), angs(), cam=dict(cam))
    render_case('clip_m3_%d' % k, '3d/hexp_on2.mob', 3, 0, two, 'texbig', bg, angs(), angs(), cam=dict(cam))
    render_case('clip_m4s0_%d' % k, '3d/zilog1.mob', 4, 0, city[:262144], 'texbig', bg, angs(), angs(), cam=dict(cam))
    render_case('clip_m4s2_%d' % k, '3d/zilog1.mob', 4, 2, city[:262144], 'texbig', bg, angs(), angs(), cam=dict(cam))
    render_case('clip_m1s0_%d' % k, '3d/sph1024.mob', 1, 0, env1[:262144], None, bg, angs(), angs(), cam=dict(cam))
    render_case('clip_m6_%d' % k, '3d/sph1024.mob', 6, 0, None, 'col', bg, angs(), angs(), cam=dict(cam))
    render_case('clip_m8_%d' % k, '3d/hexp_on2.mob', 8, 0, None, 'col', bg, angs(), angs(), cam=dict(cam))
    render_case('clip_m9_%d' % k, '3d/sph1024.mob', 9, 0, sprite_tab, None, bg, angs(), angs(), cam=dict(cx=cam['cx'], cy=cam['cy'], dist=rnd.uniform(2.2, 3.5), focal=140.0))
render_case('m9mask', '3d/sph1024.mob', 9, 0, sprite_tab, None, bg, angs(), angs(), mask=True)
render_case('m9lim', '3d/sph1024.mob', 9, 3, sprite_tab, None, bg, angs(), angs(), colors=True, npts_limit=300)

json.dump({'blobs': blobs, 'cases': cases}, open(OUT, 'w'))
print('wrote', OUT, len(cases), 'cases')
