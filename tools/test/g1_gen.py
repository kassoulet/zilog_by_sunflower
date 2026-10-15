"""Vectors for scenes/_g1fx.js: runs original 0x1d200 / 0x1d3d8 (DAT_00040310 = time float) under Unicorn.  python g1_gen.py out.json"""
import sys, os, json, base64, struct
HERE = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, os.path.join(HERE, '..', '..', 're', 'harness'))
from orig import Orig
res = []
for addr, name in ((0x1d200, 'warpMeshLens'), (0x1d3d8, 'warpMeshLens2')):
    for t in (0.0, 3.5, 17.25, 120.0, 333.75, 777.5, 1500.25, 2600.0):
        o = Orig(); a = o.alloc(26 * 41 * 12); o.wf32(0x40310, t); o.call(addr, eax=a)
        res.append({'fn': name, 't': t, 'out': base64.b64encode(o.read(a, 26 * 41 * 12)).decode()})
json.dump(res, open(sys.argv[1], 'w'))
