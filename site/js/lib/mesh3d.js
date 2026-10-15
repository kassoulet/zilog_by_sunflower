// mesh3d.js -- the demo's 3D engine core ("mobutil.c"): mesh loader, rotation, normals, projection, render dispatcher.
// Faithful port of ZILOG.EXE functions 0x16478 .. 0x18beb. Mapping table + struct layouts: re/PORT_3d.md.
// Rasterizers/primitives are in mesh3d-raster.js (re-exported here).
import {
  makeRenderContext, trunc32, tri_25fc0, tri_26308, tri_26b90, tri_266a0, tri_26e28,
  line_21b70, line_21f3b, line_22463, sprite_1efbc, sprite_1febc,
} from './mesh3d-raster.js';
export * from './mesh3d-raster.js';
const f32 = Math.fround;

/**
 * Mesh = the original 0x54-byte struct (dword index in brackets, byte offset = 4*index).
 * Arrays are created by the loader (PNTS/FACE/EDGE chunks) or lazily by the transform functions, as in the original.
 * @typedef {object} Mesh
 * @property {number} npts          [0x00] number of points (scenes temporarily lower it to reveal points progressively)
 * @property {Float32Array} pts     [0x01] source points x,y,z
 * @property {Float32Array} xpts     [0x02] transformed points (output of rotate)
 * @property {Uint8Array|null} mask [0x03] optional per-vertex enable mask (0 = skip in rotate/project/sprites)
 * @property {Float32Array|null} nrm  [0x04] vertex normals (vertexNormals)
 * @property {Float32Array|null} xnrm [0x05] rotated vertex normals (rotateNormals)
 * @property {number} nfaces        [0x06]
 * @property {Int32Array} faces     [0x07] 3 vertex indices per face
 * @property {Float32Array|null} fnrm [0x08] face normals (faceNormals)
 * @property {Int32Array|null} key  [0x09] depth sort keys of the visible faces (sortFaces)
 * @property {Int32Array|null} order [0x0a] face indices of the visible faces, far to near (sortFaces)
 * @property {number} nvis          [0x0b] number of visible faces
 * @property {Int32Array} vf        [0x0c] vertex->faces adjacency lists, -1 terminated, flattened
 * @property {Int32Array} vfIdx     [0x0d] start of vertex i's list in vf
 * @property {Int32Array|null} edgeFaces [0x0e] for each edge the two faces sharing it (0,0 if none)
 * @property {number} nedges        [0x0f]
 * @property {Int32Array|null} edges [0x10] 2 vertex indices per edge
 * @property {Float32Array} p2d     [0x11] projected points x,y (screen px)
 * @property {Float32Array|null} uv [0x12 -> byte +0x48] per-vertex 2D attribute (u,v) supplied by scene code
 *                                   (texture coords in modes 2,3,4; colour byte in .x for modes 6,8)
 * @property {Int32Array} area      [0x13 -> byte +0x4c] signed screen area of each face (<0 = front facing)
 * @property {Float32Array|null} invz [0x14 -> byte +0x50] per vertex 1/(z/focal+dist) (project)
 */

const u32le = (d, o) => d.getUint32(o, true);
/** FUN_00016478 (+0x160a9 vertex->face lists, +0x162e7 edge->faces): parse a 'MOB:' file into a Mesh.
 *  @param {Uint8Array} buf @returns {Mesh} */
export function loadMesh(buf) {
  const dv = new DataView(buf.buffer, buf.byteOffset, buf.byteLength);
  if (String.fromCharCode(...buf.subarray(0, 4)) !== 'MOB:') throw Error('FATAL: attempt to init corrupted mob');
  const m = {
    npts: 0, pts: new Float32Array(0), xpts: new Float32Array(0), mask: null, nrm: null, xnrm: null, nfaces: 0,
    faces: new Int32Array(0), fnrm: null, key: null, order: null, nvis: 0, vf: null, vfIdx: null, edgeFaces: null,
    nedges: 0, edges: new Int32Array(0), p2d: new Float32Array(0), uv: null, area: new Int32Array(0), invz: null,
  };
  let rem = u32le(dv, 4), p = 8;
  while (rem > 0) {
    const tag = String.fromCharCode(...buf.subarray(p, p + 4)), n = u32le(dv, p + 4); p += 8; rem -= 8;
    if (tag === 'PNTS') {
      m.npts = n; m.pts = new Float32Array(buf.slice(p, p + n * 12).buffer); m.xpts = new Float32Array(n * 3); m.p2d = new Float32Array(n * 2);
      p += n * 12; rem -= n * 12;
    } else if (tag === 'FACE') {
      m.nfaces = n; m.faces = new Int32Array(buf.slice(p, p + n * 12).buffer); m.area = new Int32Array(n);
      p += n * 12; rem -= n * 12;
    } else if (tag === 'EDGE') {
      m.nedges = n; m.edges = new Int32Array(buf.slice(p, p + n * 8).buffer); p += n * 8; rem -= n * 8;
    }
  }
  // 0x160a9: lists are built by prepending, so each vertex's faces are stored in decreasing face order
  const lists = Array.from({ length: m.npts }, () => []);
  for (let f = 0; f < m.nfaces; f++) for (let k = 0; k < 3; k++) lists[m.faces[f * 3 + k]].unshift(f);
  const vf = []; m.vfIdx = new Int32Array(m.npts);
  lists.forEach((l, i) => { m.vfIdx[i] = vf.length; vf.push(...l, -1); });
  m.vf = Int32Array.from(vf);
  if (m.nedges) {                                              // 0x162e7: first two faces common to both end points
    m.edgeFaces = new Int32Array(m.nedges * 2);
    for (let e = 0; e < m.nedges; e++) {
      let got = false;
      for (const fa of lists[m.edges[e * 2]]) for (const fb of lists[m.edges[e * 2 + 1]]) {
        if (fa !== fb) continue;
        if (got) m.edgeFaces[e * 2 + 1] = fa; else { m.edgeFaces[e * 2] = fa; got = true; }
      }
    }
  }
  return m;
}

/**
 * Object instance = the struct scene code keeps on the stack and passes by pointer (`&piStack_20c`).
 * Byte offsets: +0 mesh*, +4 cx, +8 cy, +0xc dist, +0x10 focal, +0x14 tex, +0x1c mode, +0x1d sub.
 */
export class Obj3D {
  /** @param {Mesh} mesh @param {{cx?:number,cy?:number,dist?:number,focal?:number,tex?:any,mode?:number,sub?:number,colors?:Uint32Array|null}} o */
  constructor(mesh, o = {}) {
    this.mesh = mesh;
    this.cx = f32(o.cx ?? 160); this.cy = f32(o.cy ?? 100); this.dist = f32(o.dist ?? 6.5); this.focal = f32(o.focal ?? 140);
    this.tex = o.tex ?? null;            // +0x14: Uint32Array texture (block of 2 for modes 2/3), Uint8Array sprite table for mode 9
    this.mode = o.mode ?? 0;             // +0x1c render mode (0..9)
    this.sub = o.sub ?? 0;               // +0x1d render sub mode
    this.colors = o.colors ?? null;      // *DAT_00040308: per-point colour dwords for mode 9 / sub 3
  }
}

// ----------------------------------------------------------------------------------------------------------------
/** Euler rotation matrix rows with the 3 precomputed products used by the original's Winograd-style multiply. */
function rotMatrix(ax, ay, az) {
  const ca = f32(Math.cos(ax)), sa = f32(Math.sin(ax)), cb = f32(Math.cos(ay)), sb = f32(Math.sin(ay)), cc = f32(Math.cos(az)), sc = f32(Math.sin(az));
  const r = [f32(ca * cb), f32(sa * cb), sb,
    f32(ca * sb * sc + sa * cc), f32(sa * sb * sc + -ca * cc), f32(-cb * sc),
    f32(sa * sc - ca * sb * cc), f32(-ca * sc - sa * sb * cc), f32(cb * cc)];
  return { r, p: [f32(r[0] * r[1]), f32(r[3] * r[4]), f32(r[6] * r[7])] };
}
function xform(src, dst, n, mask, ax, ay, az) {
  const { r, p } = rotMatrix(ax, ay, az);
  for (let i = 0; i < n; i++) {
    if (mask && !mask[i]) continue;
    const x = src[i * 3], y = src[i * 3 + 1], z = src[i * 3 + 2], xy = f32(x * y);
    for (let k = 0; k < 3; k++)
      dst[i * 3 + k] = f32((r[k * 3] + y) * (r[k * 3 + 1] + x) + z * r[k * 3 + 2] - (p[k] + xy));
  }
}
/** FUN_00017e5e: rotate the mesh points by 3 euler angles (radians). Source = xpts (in place, cumulative) when the
 *  object's mode byte is 0 or 2, else the original pts. Honours the vertex mask. */
export function rotate(obj, ax, ay, az) {
  const m = obj.mesh, src = (obj.mode === 0 || obj.mode === 2) ? m.xpts : m.pts;
  xform(src, m.xpts, m.npts, m.mask, ax, ay, az);
}
/** FUN_00018144: rotate the vertex normals nrm -> xnrm (allocates xnrm on first use). Takes the mesh (not the object). */
export function rotateNormals(m, ax, ay, az) {
  if (!m.xnrm) m.xnrm = new Float32Array(m.npts * 3);
  xform(m.nrm, m.xnrm, m.npts, m.mask, ax, ay, az);
}
/** FUN_0001841d: per face normal (unnormalised cross product) from xpts (mode 0/2) or the source pts (other modes!). */
export function faceNormals(obj) {
  const m = obj.mesh, P = (obj.mode === 0 || obj.mode === 2) ? m.xpts : m.pts;
  if (!m.fnrm) m.fnrm = new Float32Array(m.nfaces * 3);
  for (let f = 0; f < m.nfaces; f++) {
    const a = m.faces[f * 3] * 3, b = m.faces[f * 3 + 1] * 3, c = m.faces[f * 3 + 2] * 3;
    const x0 = P[a], y0 = P[a + 1], z0 = P[a + 2], x1 = P[b], y1 = P[b + 1], z1 = P[b + 2], x2 = P[c], y2 = P[c + 1], z2 = P[c + 2];
    m.fnrm[f * 3] = (z2 - z0) * (y1 - y0) - (z1 - z0) * (y2 - y0);
    m.fnrm[f * 3 + 1] = (x2 - x0) * (z1 - z0) - (x1 - x0) * (z2 - z0);
    m.fnrm[f * 3 + 2] = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
  }
}
/** FUN_000185d4: vertex normals = normalised sum of the normals of the faces around each vertex (uses vf lists). */
export function vertexNormals(m) {
  if (!m.nrm) m.nrm = new Float32Array(m.npts * 3);
  for (let i = 0; i < m.npts; i++) {
    let x = 0, y = 0, z = 0;
    for (let k = m.vfIdx[i]; m.vf[k] !== -1; k++) {
      const f = m.vf[k] * 3; x = f32(x + m.fnrm[f]); y = f32(y + m.fnrm[f + 1]); z = f32(z + m.fnrm[f + 2]);
    }
    const s = f32(1 / Math.sqrt(z * z + y * y + x * x));
    m.nrm[i * 3] = x * s; m.nrm[i * 3 + 1] = y * s; m.nrm[i * 3 + 2] = z * s;
  }
}
/** FUN_0001870b: perspective projection of xpts -> p2d (+ invz): invz = 1/(z/focal + dist);
 *  x' = x*invz + cx ; y' = cy + y*invz*0.83 (aspect correction for the 320x200 screen). Honours mask. */
export function project(obj) {
  const m = obj.mesh;
  if (!m.invz) m.invz = new Float32Array(m.npts);
  const { dist, focal, cx, cy } = obj;
  for (let i = 0; i < m.npts; i++) {
    if (m.mask && !m.mask[i]) continue;
    const x = m.xpts[i * 3], y = m.xpts[i * 3 + 1], z = m.xpts[i * 3 + 2];
    const iz = f32(1 / (z / focal + dist));
    m.invz[i] = iz; m.p2d[i * 2] = x * iz + cx; m.p2d[i * 2 + 1] = cy + (y * iz) * 0.83;
  }
}
/** FUN_000189a5: signed screen-space area of each face (truncated to int), <0 = front facing. */
export function faceAreas(m) {
  const P = m.p2d;
  for (let f = 0; f < m.nfaces; f++) {
    const a = m.faces[f * 3], b = m.faces[f * 3 + 1], c = m.faces[f * 3 + 2];
    const bx = P[b * 2], by = P[b * 2 + 1];
    m.area[f] = trunc32((P[a * 2] - bx) * (P[c * 2 + 1] - by) - (P[c * 2] - bx) * (P[a * 2 + 1] - by));
  }
}
/** FUN_00025f13: the demo's in-place quicksort (Hoare partition, DESCENDING order, not stable) on keys + payload. */
function qsort(k, v, lo, hi) {
  let i = lo, j = hi; const pv = k[(lo + hi) >>> 1];
  do {
    while (pv < k[i]) i++;
    while (pv > k[j]) j--;
    if (i <= j) { let t = k[i]; k[i] = k[j]; k[j] = t; t = v[i]; v[i] = v[j]; v[j] = t; i++; j--; }
  } while (i <= j);
  if (lo < j) qsort(k, v, lo, j);
  if (i < hi) qsort(k, v, i, hi);
}
/** FUN_00018ab4: collect front-facing faces (area<0), key = trunc((z0+z1+z2)*100), sort far->near (painter's algo). */
export function sortFaces(m) {
  if (!m.key) m.key = new Int32Array(m.nfaces);
  if (!m.order) m.order = new Int32Array(m.nfaces);
  let n = 0; const P = m.xpts;
  for (let f = 0; f < m.nfaces; f++) {
    if (m.area[f] >= 0) continue;
    m.key[n] = trunc32((P[m.faces[f * 3] * 3 + 2] + P[m.faces[f * 3 + 1] * 3 + 2] + P[m.faces[f * 3 + 2] * 3 + 2]) * 100);
    m.order[n++] = f;
  }
  m.nvis = n;
  if (n > 0) qsort(m.key, m.order, 0, n - 1);
}

const F16 = 65536;
/**
 * FUN_00018beb: render dispatcher. obj.mode selects the primitive (obj.sub the variant):
 *  0/1 env-mapped filled faces (normals from m.nrm / m.xnrm); sub 0 = 2-D texture lookup (25fc0), sub 1 = 1-D ramp (26b90)
 *  2/3 env map + surface texture added (266a0), uv from m.uv;   4 textured with m.uv: sub 2 blended (26308), sub 4 screen-pitch warp (26e28), else 25fc0
 *  5 silhouette/contour edges, constant colour 255;  6 same, colour from m.uv.x of the edge ends (sub 5 = darkening lines)
 *  7 all edges (255);  8 all edges, colours from m.uv.x;  9 point sprites sized by 1/z (sub 3 = coloured from obj.colors)
 * Call project() first (and rotate/normals as the mode requires). @param {Obj3D} obj @param {object} ctx makeRenderContext()
 */
export function render(obj, ctx) {
  const m = obj.mesh, P = m.p2d, mode = obj.mode, sub = obj.sub;
  const ptr = (v) => [P[v * 2], P[v * 2 + 1]];
  if (mode === 5 || mode === 6) {
    faceAreas(m);
    for (let e = 0; e < m.nedges; e++) {
      const fa = m.edgeFaces[e * 2], fb = m.edgeFaces[e * 2 + 1], A = m.area[fa], B = m.area[fb];
      if (!((A <= 0 && B >= 0) || (A >= 0 && B <= 0))) continue;
      const v0 = m.edges[e * 2], v1 = m.edges[e * 2 + 1];
      const x0 = trunc32(P[v0 * 2] * F16), y0 = trunc32(P[v0 * 2 + 1] * F16), x1 = trunc32(P[v1 * 2] * F16), y1 = trunc32(P[v1 * 2 + 1] * F16);
      if (mode === 5) line_21b70(ctx, 255, x0, y0, x1, y1);
      else {
        const ax = ((trunc32(m.uv[v1 * 2]) << 8) | trunc32(m.uv[v0 * 2])) & 0xffff;   // ax = (c1<<8)|c0 -> 2 colour bytes
        if (sub === 5) line_22463(ctx, ax & 255, ax >>> 8, x0, y0, x1, y1);
        else line_21f3b(ctx, ax & 255, ax >>> 8, x0, y0, x1, y1);
      }
    }
  } else if (mode === 7 || mode === 8) {
    for (let e = 0; e < m.nedges; e++) {
      const v0 = m.edges[e * 2], v1 = m.edges[e * 2 + 1];
      const x0 = trunc32(P[v0 * 2] * F16), y0 = trunc32(P[v0 * 2 + 1] * F16), x1 = trunc32(P[v1 * 2] * F16), y1 = trunc32(P[v1 * 2 + 1] * F16);
      if (mode === 7) line_21b70(ctx, 255, x0, y0, x1, y1);
      else {
        const ax = ((trunc32(m.uv[v1 * 2]) << 8) | trunc32(m.uv[v0 * 2])) & 0xffff;
        line_21f3b(ctx, ax & 255, ax >>> 8, x0, y0, x1, y1);
      }
    }
  } else if (mode === 9) {
    const iz = m.invz, tgt = ctx.target;
    for (let i = 0; i < m.npts; i++) {
      if (m.mask && !m.mask[i]) continue;
      const r = f32(iz[i] * 26);
      if (!(r > 1)) continue;
      const r8 = trunc32(r * 256), y8 = trunc32(P[i * 2 + 1] * 256), x8 = trunc32(P[i * 2] * 256);
      if (sub === 3) {
        const c = obj.colors[i] & 0xffffff;                      // the original passes ~col; sprite_1febc undoes that
        sprite_1febc(tgt, obj.tex, x8, y8, r8, [c & 255, (c >>> 8) & 255, (c >>> 16) & 255]);
      } else sprite_1efbc(tgt, obj.tex, x8, y8, r8);
    }
  } else if (mode <= 4) {
    faceAreas(m); sortFaces(m);
    // vertex normals used as env-map coordinates: mode 0/2 -> nrm (+0x10), mode 1/3 -> xnrm (+0x14)
    const N = (mode === 0 || mode === 2) ? m.nrm : m.xnrm, uv = m.uv, st = (mode === 2 || mode === 3) ? 7 : 5;
    const V = new Float32Array(st * 3);
    for (let i = 0; i < m.nvis; i++) {
      const f = m.order[i];
      for (let k = 0; k < 3; k++) {                       // memory order of the vertex records is v0, v2, v1 (!)
        const v = m.faces[f * 3 + (k === 0 ? 0 : 3 - k)], o = k * st;
        V[o] = P[v * 2]; V[o + 1] = P[v * 2 + 1];
        if (mode <= 1) { V[o + 2] = N[v * 3] * 127 + 127; V[o + 3] = N[v * 3 + 1] * 127 + 127; }
        else if (mode <= 3) { V[o + 2] = N[v * 3] * 127 + 127; V[o + 3] = N[v * 3 + 1] * 127 + 127; V[o + 4] = uv[v * 2]; V[o + 5] = uv[v * 2 + 1]; }
        else { V[o + 2] = uv[v * 2]; V[o + 3] = uv[v * 2 + 1]; }
      }
      if (mode <= 1) { if (sub === 0) tri_25fc0(ctx, V, obj.tex); else if (sub === 1) tri_26b90(ctx, V, obj.tex); }
      else if (mode <= 3) tri_266a0(ctx, V, obj.tex);
      else if (sub === 2) tri_26308(ctx, V, obj.tex);
      else if (sub === 4) tri_26e28(ctx, V, obj.tex, 0x140);
      else tri_25fc0(ctx, V, obj.tex);
    }
  }
}
export { makeRenderContext };
