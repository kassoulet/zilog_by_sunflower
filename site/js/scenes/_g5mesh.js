// _g5mesh.js -- scene-specific mesh helpers for scenes 8, 9 and the credits loop (orders 41..59 of main = func_100d3).
// Ports of the FPU routines 0x1b687 0x1b04f 0x1b1b4 0x1b2a4 0x1b7e3 0x1b854 0x1b960 (mesh preparation, run once) and
// 0x20a10 0x2112c 0x21664 0x206e0 0x219e8 (per frame point deformers, they read mesh.pts and write mesh.xpts).
// Original numerics: x87 extended intermediates, floats stored to memory (Math.fround at the stores). Differentially tested
// against the original under Unicorn: tools/test/g5_gen.py + g5.test.mjs.
import { trunc32 } from '../lib/mesh3d.js';
const f32 = Math.fround;
const { sin, cos, atan2, sqrt } = Math;

/** ported from func_1b687 (0x1b687): make all faces of a mesh face the same way in the (x,y) plane (swap v0,v1 of a face whose
 *  screen-plane area is negative), then stretch y by 1.03. Used on hexp_on2 (hexagon tile plane). */
export function f_1b687(m) {
  const P = m.pts, F = m.faces;
  for (let i = 0; i < m.nfaces; i++) {
    const a = F[i * 3], b = F[i * 3 + 1], c = F[i * 3 + 2];
    const x1 = P[b * 3], y1 = P[b * 3 + 1];
    if ((P[a * 3] - x1) * (P[c * 3 + 1] - y1) - (P[c * 3] - x1) * (P[a * 3 + 1] - y1) < 0) { F[i * 3] = b; F[i * 3 + 1] = a; }
  }
  for (let i = 0; i < m.npts; i++) P[i * 3 + 1] = f32(P[i * 3 + 1] * 1.03);
}
/** ported from func_1b04f (0x1b04f): mesh.uv[i] = (x,y) of the point normalised to a w x h picture (y flipped): planar texture coordinates. */
export function f_1b04f(m, w, h) {
  if (!m.uv) m.uv = new Float32Array(m.npts * 2);
  const P = m.pts; let x0 = P[0], y0 = P[1], x1 = x0, y1 = y0;
  for (let i = 0; i < m.npts; i++) {
    const x = P[i * 3], y = P[i * 3 + 1];
    if (x < x0) x0 = x; if (x1 < x) x1 = x; if (y < y0) y0 = y; if (y1 < y) y1 = y;
  }
  for (let i = 0; i < m.npts; i++) {
    m.uv[i * 2] = f32((P[i * 3] - x0) * f32(w / (x1 - x0)));
    m.uv[i * 2 + 1] = f32(h - (P[i * 3 + 1] - y0) * f32(h / (y1 - y0)));
  }
}
/** ported from func_1b1b4 (0x1b1b4): mesh.uv[i].x = depth of point i (z) normalised to 1..255 (a colour byte for the line/face drawers). */
export function f_1b1b4(m) {
  if (!m.uv) m.uv = new Float32Array(m.npts * 2);
  const P = m.pts; let lo = P[2], hi = lo;
  for (let i = 0; i < m.npts; i++) { const z = P[i * 3 + 2]; if (z < lo) lo = z; if (hi < z) hi = z; }
  const k = f32(254 / (hi - lo));
  for (let i = 0; i < m.npts; i++) m.uv[i * 2] = f32((P[i * 3 + 2] - lo) * k + 1);
}
/** trunc(255 - s*0.51) evaluated like the x87 (64-bit mantissa): the double product s*0.51 loses a residue that decides e.g. 400 -> 50, not 51 */
function trunc255(s) {
  const c = 0.51, t = 134217729 * s, sh = t - (t - s), sl = s - sh, t2 = 134217729 * c, ch = t2 - (t2 - c), cl = c - ch;
  const p = s * c, e = ((sh * ch - p) + sh * cl + sl * ch) + sl * cl, k = 255 - p;
  return Number.isInteger(k) && e > 0 ? k - 1 : Math.trunc(k - e);
}
/** ported from func_1b2a4 (0x1b2a4): mesh.uv[i].x = max(0, trunc(255 - 0.51 * hypot(x,y))): brightness fading to the border (for the wire grid). */
export function f_1b2a4(m) {
  if (!m.uv) m.uv = new Float32Array(m.npts * 2);
  const P = m.pts;
  for (let i = 0; i < m.npts; i++) {
    const x = P[i * 3], y = P[i * 3 + 1];
    let v = trunc255(sqrt(y * y + x * x)); if (v < 0) v = 0;
    m.uv[i * 2] = v;
  }
}
/** ported from func_1b7e3 (0x1b7e3): swap vertex 0 and 1 of every face (flip the winding). */
export function f_1b7e3(m) {
  const F = m.faces;
  for (let i = 0; i < m.nfaces; i++) { const t = F[i * 3]; F[i * 3] = F[i * 3 + 1]; F[i * 3 + 1] = t; }
}
/** ported from func_1b854 (0x1b854): zilog1.mob is front half + back half; for every front vertex i (< npts/2) find the back vertex
 *  (the last j in [n/2, n)) with the same truncated (x,y); 0 if none. @returns {Int32Array} partner table */
export function f_1b854(m) {
  const h = m.npts >> 1, T = new Int32Array(h), P = m.pts;
  for (let i = 0; i < h; i++) for (let j = h; j < h * 2; j++)
    if (trunc32(P[i * 3]) === trunc32(P[j * 3]) && trunc32(P[i * 3 + 1]) === trunc32(P[j * 3 + 1])) T[i] = j;
  return T;
}
/** ported from func_1b960 (0x1b960): w x h point grid in the z=-50 plane (spacing sp) with horizontal and vertical edges, no faces. */
export function f_1b960(w, h, sp) {
  const n = w * h, ne = h * (w - 1) + (h - 1) * w, pts = new Float32Array(n * 3), edges = new Int32Array(ne * 2);
  let k = 0;
  for (let y = f32(f32(-h * sp) * 0.5); y < f32(h * sp) * 0.5; y = f32(y + sp))
    for (let x = f32(f32(-w * sp) * 0.5); x < f32(w * sp) * 0.5; x = f32(x + sp)) { pts[k * 3] = x; pts[k * 3 + 1] = y; pts[k * 3 + 2] = -50; k++; }
  k = 0;
  for (let j = 0; j < h; j++) for (let i = 0; i < w - 1; i++, k++) { edges[k * 2] = j * w + i; edges[k * 2 + 1] = j * w + i + 1; }
  for (let j = 0; j < h - 1; j++) for (let i = 0; i < w; i++, k++) { edges[k * 2] = j * w + i; edges[k * 2 + 1] = i + (j + 1) * w; }
  return {
    npts: n, pts, xpts: new Float32Array(n * 3), mask: null, nrm: null, xnrm: null, nfaces: 0, faces: new Int32Array(0), fnrm: null, key: null,
    order: null, nvis: 0, vf: null, vfIdx: null, edgeFaces: null, nedges: ne, edges, p2d: new Float32Array(n * 2), uv: null, area: new Int32Array(0), invz: null,
  };
}

// ---------------------------------------------------------------------------------------------------------------------------------
/** ported from func_20a10 (0x20a10): "lens": every point is moved radially (spherical coordinates around a wandering centre, r -> sqrt(r^2+200000)-200). */
export function f_20a10(m, t) {
  const P = m.pts, O = m.xpts;
  const cx = f32(sin(cos(t * 0.0347) + t * 0.00132) * 200), cy = f32(cos(t * 0.00241 - sin(t * 0.0458)) * 200), cz = f32(sin(cos(t * 0.0612) + t * 0.00145) * 200);
  for (let i = 0; i < m.npts; i++) {
    const x = f32(P[i * 3] - cx), y = f32(P[i * 3 + 1] - cy), z = f32(P[i * 3 + 2] - cz);
    const th = f32(atan2(y, x)), ph = f32(atan2(sqrt(y * y + x * x), z));
    const r = f32(sqrt(z * z + y * y + x * x + 200000) - 200);
    const sp = sin(ph) * r;
    O[i * 3] = cos(th) * sp + cx; O[i * 3 + 1] = sin(th) * sp + cy; O[i * 3 + 2] = cos(ph) * r + cz;
  }
}
/** ported from func_2112c (0x2112c): cub_tun2 (tunnel of 107-point rings): every ring is rotated in the xy plane by an angle growing with its
 *  depth (twist) around a wobbling centre. */
export function f_2112c(m, t) {
  const P = m.pts, O = m.xpts;
  for (let b = 0; b < m.npts; b += 107) {
    const k = trunc32(P[b * 3 + 2] + 700);
    const a = sin(t * 0.01) * 3 * k * 0.002, sa = sin(a), ca = cos(f32(a));
    const cx = f32(sin(t * 0.13) * (cos(t * 0.01) * 10 * k * 0.004)), cy = f32(sin(t * 0.07) * 10 * k * 0.004);
    for (let i = b; i < b + 107; i++) {
      const dx = f32(P[i * 3] - cx), dy = f32(P[i * 3 + 1] - cy);
      O[i * 3] = dy * f32(sa) + dx * f32(ca) + cx;
      O[i * 3 + 1] = dx * f32(sa) + cy - dy * f32(ca);
      O[i * 3 + 2] = P[i * 3 + 2];
    }
  }
}
/** ported from func_21664 (0x21664): hexagon tiles (7 points each, hexp_on2) fly in: every tile gets its own rotation (3 angles from its
 *  integer centre and time), zoom p4 about the origin and a z wave; p2 = rotation amount, p3 = z amplitude (x50). */
export function f_21664(m, p2, p3, p4, t) {
  const P = m.pts, O = m.xpts; p3 = f32(p3 * 50);
  for (let b = 0; b < m.npts; b += 7) {
    const cx = trunc32(P[(b + 2) * 3]), cy = trunc32(P[(b + 2) * 3 + 1]);
    const a1 = f32(cos(sin(t * 0.032 + cy * 0.1) + (t * 0.02 + cx * 0.1)) * p2), q = p2 * 0.3;
    const a2 = f32(cos(sin(cy * 0.081 + t * 0.022) + (cx * 0.071 + t * 0.03)) * q), a3 = f32(cos(sin(cy * 0.091 + t * 0.052) + (cx * 0.081 + t * 0.01)) * q);
    const sA = f32(sin(a1)), cA = f32(cos(a1)), sB = f32(sin(a2)), cB = f32(cos(a2)), sC = f32(sin(a3)), cC = f32(cos(a3));
    const wz = sin(cx * 0.01 + t * 0.012 - cos(t * 0.061 - cy * 0.02));
    for (let i = b; i < b + 7; i++) {
      const dx = f32(P[i * 3] - cx), dy = f32(P[i * 3 + 1] - cy);
      const u = f32(dx * cA + dy * sA), v = f32(dx * sA - dy * cA);
      O[i * 3] = u * cB + p4 * cx;
      const w = f32(u * sB);
      O[i * 3 + 1] = w * sC + -p4 * cy + v * cC;
      O[i * 3 + 2] = (v * sC + f32(wz * p3)) - w * cC;
    }
  }
}
/** ported from func_206e0 (0x206e0): radial sine ripple of the wire grid (spherical coordinates, r -> r + 140 sin(..r..)). */
export function f_206e0(m, t) {
  const P = m.pts, O = m.xpts;
  const l12 = sin(t * 0.03), l14 = cos(sin(t * 0.1) + t * 0.04), c1 = f32(l14 * 0.01), c2 = f32(l12 * 0.01);
  const f7 = f32(t * f32(0.0041)), f8 = f32(t * f32(0.0062));
  for (let i = 0; i < m.npts; i++) {
    const x = P[i * 3], y = P[i * 3 + 1], z = P[i * 3 + 2];
    const th = f32(atan2(y, x)), ph = f32(atan2(sqrt(y * y + x * x), z));
    let r = f32(sqrt(z * z + y * y + x * x));
    r = f32(sin(cos(c1 * r - f8) + (c2 * r + f7)) * 140 + r);
    const sp = sin(ph) * r;
    O[i * 3] = cos(th) * sp; O[i * 3 + 1] = sin(th) * sp; O[i * 3 + 2] = cos(ph) * r;
  }
}
/** ported from func_219e8 (0x219e8): extrude the zilog logo: front points stay, each back point (index via pair table) is placed
 *  radially away from a wandering centre (a,b,340) by distance + p. */
export function f_219e8(m, pair, p, t) {
  const P = m.pts, O = m.xpts, s1 = sin(t * 0.061) * 250, s2 = sin(t * 0.073) * 50;
  for (let i = 0; i < m.npts >> 1; i++) {
    O[i * 3] = P[i * 3]; O[i * 3 + 1] = P[i * 3 + 1]; O[i * 3 + 2] = P[i * 3 + 2];
    const x = f32(P[i * 3] - f32(s1)), y = f32(P[i * 3 + 1] - f32(s2)), z = f32(P[i * 3 + 2] - 340);
    const th = f32(atan2(y, x)), ph = f32(atan2(sqrt(y * y + x * x), z));
    const r = f32(sqrt(z * z + y * y + x * x) + p), j = pair[i], sp = sin(ph) * r;
    O[j * 3] = cos(th) * sp + f32(s1); O[j * 3 + 1] = sin(th) * sp + f32(s2); O[j * 3 + 2] = cos(ph) * r + 340;
  }
}
