// Scene-specific mesh helpers for scenes 6 and 7 (main() loops 0x23 and 0x29).  Mesh = lib/mesh3d.js Mesh object.
// x87 notes: intermediates are doubles (the original keeps 80 bit), every `fstp dword` is a Math.fround.
const F = Math.fround, sin = Math.sin, cos = Math.cos, atan2 = Math.atan2, sqrt = Math.sqrt;

/** ported from func_1b04f (0x1b04f): planar texture coordinates: bounding box of (x,y) mapped to [0,w] x [h,0] (y flipped). Allocates mesh.uv. */
export function planarUV(m, w, h) {
  if (!m.uv) m.uv = new Float32Array(m.npts * 2);
  const p = m.pts;
  let x0 = p[0], x1 = p[0], y0 = p[1], y1 = p[1];
  for (let i = 0; i < m.npts; i++) {
    const x = p[i * 3], y = p[i * 3 + 1];
    if (x < x0) x0 = x; if (x > x1) x1 = x; if (y < y0) y0 = y; if (y > y1) y1 = y;
  }
  const sx = F(w / (x1 - x0)), sy = F(h / (y1 - y0));
  for (let i = 0; i < m.npts; i++) {
    m.uv[i * 2] = F((p[i * 3] - x0) * sx);
    m.uv[i * 2 + 1] = F(h - (p[i * 3 + 1] - y0) * sy);   // no intermediate rounding (x87)
  }
}
export const f_1b04f = planarUV;

/** ported from func_1bf97 (0x1bf97): lattice mesh nx*ny*nz points (spacing s, centred, float32 accumulation as in the original) and its
 *  axis-aligned edges (x neighbours, then y, then z).  Only pts/xpts/p2d/edges/npts/nedges are filled (no faces: wire modes only). */
export function makeLattice(nx, ny, nz, s) {
  const np = nx * ny * nz, ne = nz * (nx - 1) * ny + (ny - 1) * nx * nz + (nz - 1) * nx * ny;
  const pts = new Float32Array(np * 3), edges = new Int32Array(ne * 2);
  let n = 0;
  for (let z = F(F(-nz * s) * 0.5); z < F(F(nz * s) * 0.5); z = F(z + s))
    for (let y = F(F(-ny * s) * 0.5); y < F(F(ny * s) * 0.5); y = F(y + s))
      for (let x = F(F(-nx * s) * 0.5); x < F(F(nx * s) * 0.5); x = F(x + s)) { pts[n * 3] = x; pts[n * 3 + 1] = y; pts[n * 3 + 2] = z; n++; }
  let e = 0;
  for (let k = 0; k < nz; k++) for (let j = 0; j < ny; j++) for (let i = 0; i < nx - 1; i++) { const a = j * nx + i + k * nx * ny; edges[e++] = a; edges[e++] = a + 1; }
  for (let k = 0; k < nz; k++) for (let j = 0; j < ny - 1; j++) for (let i = 0; i < nx; i++) { edges[e++] = k * nx * ny + j * nx + i; edges[e++] = i + (j + 1) * nx + k * nx * ny; }
  for (let k = 0; k < nz - 1; k++) for (let j = 0; j < ny; j++) for (let i = 0; i < nx; i++) { edges[e++] = k * nx * ny + j * nx + i; edges[e++] = ny * (k + 1) * nx + j * nx + i; }
  return { npts: np, pts, xpts: new Float32Array(np * 3), mask: null, nrm: null, xnrm: null, nfaces: 0, faces: new Int32Array(0), fnrm: null, key: null, order: null,
    nvis: 0, vf: null, vfIdx: null, edgeFaces: null, nedges: ne, edges, p2d: new Float32Array(np * 2), uv: null, area: new Int32Array(0), invz: null };
}
export const f_1bf97 = makeLattice;

/** ported from func_20b94 (0x20b94): "sine ripple" deformation pts -> xpts in spherical coordinates:
 *  r' = r + amp * sin(a x + d) sin(b y + e) sin(c z + f) (a,b,c = slow 0.0061 * oscillators of t), angles unchanged. */
export function rippleSphere(m, t, amp) {
  const A = F(sin(t * 0.05) * 0.0061), B = F(cos(sin(t * 0.02) + t * 0.06) * 0.0061), C = F(cos(t * 0.01) * 0.0061);
  const D = F(t * 0.031), E = F(t * 0.042), Fp = F(t * 0.051);
  amp = F(amp);
  const p = m.pts, o = m.xpts;
  for (let i = 0; i < m.npts; i++) {
    const x = p[i * 3], y = p[i * 3 + 1], z = p[i * 3 + 2];
    const az = F(atan2(y, x)), xy2 = x * x + y * y, xy2f = F(xy2);
    const th = F(atan2(sqrt(xy2), z));
    let r = F(sqrt(z * z + xy2f));
    const s = sin(A * x + D) * sin(B * y + E) * sin(C * z + Fp);
    r = F(s * amp + r);
    const tmp = sin(th) * r;
    o[i * 3] = F(cos(az) * tmp); o[i * 3 + 1] = F(sin(az) * tmp); o[i * 3 + 2] = F(cos(th) * r);
  }
}
export const f_20b94 = rippleSphere;

const centre = (t) => [F(sin(cos(t * 0.0347) + t * 0.00132) * 200), F(cos(t * 0.00241 - sin(t * 0.0458)) * 200), F(sin(cos(t * 0.0612) + t * 0.00145) * 200)];

/** ported from func_20a10 (0x20a10): "black hole" warp pts -> xpts around a Lissajous centre c(t): d = p - c, r' = sqrt(|d|^2 + 200000) - 200 (spherical coords re-built, + c). */
export function blackHole(m, t) {
  const [cx, cy, cz] = centre(t);
  const p = m.pts, o = m.xpts;
  for (let i = 0; i < m.npts; i++) {
    const dx = F(p[i * 3] - cx), dy = F(p[i * 3 + 1] - cy), dz = F(p[i * 3 + 2] - cz);
    const az = F(atan2(dy, dx)), th = F(atan2(sqrt(dx * dx + dy * dy), dz));
    const r = F(sqrt(dz * dz + (dy * dy + dx * dx) + 200000) - 200);
    const tmp = sin(th) * r;
    o[i * 3] = F(cos(az) * tmp + cx); o[i * 3 + 1] = F(sin(az) * tmp + cy); o[i * 3 + 2] = F(cos(th) * r + cz);
  }
}
export const f_20a10 = blackHole;

/** ported from func_1b533 (0x1b533): per-vertex colour byte uv.x = 255 - min(255, k * |xpt - c(t)|) (distance to the same centre as blackHole): points near the hole are bright. */
export function distanceColours(m, t, k) {
  if (!m.uv) m.uv = new Float32Array(m.npts * 2);
  const [cx, cy, cz] = centre(t);
  const o = m.xpts;
  for (let i = 0; i < m.npts; i++) {
    const dx = o[i * 3] - cx, dy = o[i * 3 + 1] - cy, dz = o[i * 3 + 2] - cz;
    let d = F(F(k) * sqrt(dx * dx + dy * dy + dz * dz));
    if (d > 255) d = 255;
    m.uv[i * 2] = F(255 - d);
  }
}
export const f_1b533 = distanceColours;
