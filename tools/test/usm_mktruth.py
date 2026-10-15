"""Build tools/test/usm_truth.json: compact ground truth for tools/test/usm.test.mjs, produced by the ORIGINAL code under Unicorn.
  python usm_mktruth.py ana.u [out.json]
Runs usm_groundtruth.py (sequencer + envelopes + voice update, block by block) and usm_mixtruth.py (real SB16 software mixer) and keeps
per block: order, row, speed, tempo, crc32 of the per-channel voice state, crc32 of the 884-frame stereo int16 output block."""
import sys, os, json, struct, zlib, subprocess, tempfile, base64
here = os.path.dirname(os.path.abspath(__file__))
src = sys.argv[1]; out = sys.argv[2] if len(sys.argv) > 2 else os.path.join(here, 'usm_truth.json')
tmp = tempfile.mkdtemp()
gt = os.path.join(tmp, 'gt.json'); mx = os.path.join(tmp, 'mix.i16')
subprocess.check_call([sys.executable, os.path.join(here, 'usm_groundtruth.py'), src, gt, '20000'])
g = json.load(open(gt)); n = len(g['blocks'])
subprocess.check_call([sys.executable, os.path.join(here, 'usm_mixtruth.py'), src, mx, str(n)])
mix = open(mx, 'rb').read()
FIELDS = [0, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18]    # = STATE_FIELDS in usm.test.mjs
def statecrc(chs):
    v = []
    for c in chs:
        for k in FIELDS:
            x = c[k]
            if k == 5 and x >= 0xf0000000: x = 0xffffffff
            if k == 6 and x >= 0xf0000000: x = 0
            v.append(x & 0xffffffff)
    return zlib.crc32(struct.pack('<%dI' % len(v), *v))
B = g['blocks']
doc = dict(nblocks=n, nch=g['nch'], fields=FIELDS,
           order=base64.b64encode(bytes(b['o'] for b in B)).decode(),
           row=base64.b64encode(struct.pack('<%dH' % n, *[b['r'] for b in B])).decode(),
           speed=sorted(set(b['sp'] for b in B)), tempo=sorted(set(b['tp'] for b in B)),
           syncValue=base64.b64encode(bytes(b['sv'] for b in B)).decode(), syncCount=base64.b64encode(struct.pack('<%dI' % n, *[b['sy'] for b in B])).decode(),
           stateCrc=base64.b64encode(struct.pack('<%dI' % n, *[statecrc(b['c']) for b in B])).decode(),
           mixCrc=base64.b64encode(struct.pack('<%dI' % n, *[zlib.crc32(mix[i * 3536:(i + 1) * 3536]) for i in range(n)])).decode())
json.dump(doc, open(out, 'w'), separators=(',', ':'))
print('wrote', out, n, 'blocks')
