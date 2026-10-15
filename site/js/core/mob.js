// MOB: 3D mesh container 'MOB:' u32 size, then chunks 'PNTS' n*(3 floats), 'FACE' n*(3 u32), 'EDGE' n*(2 u32).
// Port of FUN_00016478 + FUN_000160a9 (vertex->faces adjacency) + FUN_000162e7 (edge -> 2 adjacent faces).
export function loadMob(buf) {
  const dv = new DataView(buf.buffer, buf.byteOffset, buf.byteLength);
  if (String.fromCharCode(...buf.subarray(0, 4)) !== 'MOB:') throw Error('not MOB');
  const m = { npts: 0, nfaces: 0, nedges: 0, pts: null, faces: null, edges: null };
  for (let p = 8; p < buf.length;) {
    const tag = String.fromCharCode(...buf.subarray(p, p + 4)), n = dv.getUint32(p + 4, true); p += 8;
    if (tag === 'PNTS') { m.npts = n; m.pts = new Float32Array(buf.slice(p, p + n * 12).buffer); p += n * 12; }
    else if (tag === 'FACE') { m.nfaces = n; m.faces = new Int32Array(buf.slice(p, p + n * 12).buffer); p += n * 12; }
    else if (tag === 'EDGE') { m.nedges = n; m.edges = new Int32Array(buf.slice(p, p + n * 8).buffer); p += n * 8; }
    else break;
  }
  // vertex -> faces (flattened, -1 terminated lists; vtxIdx[i] = start of list i)  [mesh+0x30/0x34]
  const lists = Array.from({ length: m.npts }, () => []);
  for (let f = 0; f < m.nfaces; f++) for (let k = 0; k < 3; k++) lists[m.faces[f * 3 + k]].push(f);
  m.vfStart = new Int32Array(m.npts); const vf = []; 
  lists.forEach((l, i) => { m.vfStart[i] = vf.length; for (let k = l.length - 1; k >= 0; k--) vf.push(l[k]); vf.push(-1); }); // original prepends (reverse order)
  m.vf = Int32Array.from(vf);
  // edge -> the (up to) two faces sharing it [mesh+0x38]
  m.edgeFaces = new Int32Array(m.nedges * 2);
  for (let e = 0; e < m.nedges; e++) {
    let a = 0, b = 0, got = false;
    const la = lists[m.edges[e * 2]], lb = lists[m.edges[e * 2 + 1]];
    for (const fa of [...la].reverse()) for (const fb of [...lb].reverse()) if (fa === fb) { if (got) b = fa; else { a = fa; got = true; } }
    m.edgeFaces[e * 2] = a; m.edgeFaces[e * 2 + 1] = b;
  }
  return m;
}
