// mesh3d-raster.js -- rasterizers / primitives used by the 3D engine (ZILOG.EXE "mobutil.c" 3dlib).
// Everything here is a faithful port of the original x86 routines (asm in re/asm2.txt); see re/PORT_3d.md.
// Pixel buffers are Uint32Array (320x200 dwords, byte0,1,2 = channels, byte3 = unused). Textures: 256x256 Uint32Array.
//
// Render context (the original keeps these in globals):
//   ctx.target  Uint32Array  DAT_00040304[2]: pixel buffer polygons and sprites draw to   (320 px pitch)
//   ctx.pitch   number       DAT_00040304[0]: row pitch in pixels (320)
//   ctx.screen  Uint32Array  DAT_000402f0  : buffer the line drawers draw to (normally === target)
//   ctx.lut1/lut2 Uint8Array(65536)  DAT_000402f4 / DAT_000402f8 (see makeLuts)
const f32 = Math.fround;

/** round to nearest, ties to even: x87 fistp with the default rounding mode */
export function rne(x) {
  const f = Math.floor(x), d = x - f;
  return d < 0.5 ? f : d > 0.5 ? f + 1 : (f % 2 === 0 ? f : f + 1);
}
/** C (int)x / ftrunc+fistp: truncate toward zero; out of range -> 0x80000000 (x87 "integer indefinite") */
export function trunc32(x) { x = Math.trunc(x); return (x >= -2147483648 && x <= 2147483647) ? x : -2147483648; }
/** low 32 bits of (a*b)>>s, 64-bit signed product (imul + shrd) */
function mulsh(a, b, s) {
  const p = a * b;
  if (Math.abs(p) < 9007199254740992) return Math.floor(p / 2 ** s) | 0;
  return Number(BigInt.asIntN(32, (BigInt(a) * BigInt(b)) >> BigInt(s)));
}
/** idiv of ((n<<16) as 64 bit) by d */
const div16 = (n, d) => Math.trunc(n * 65536 / d) | 0;

/** The two 64K lookup tables built by FUN_00014834 (DAT_000402f4 / DAT_000402f8).
 *  lut1[a<<8|b] = 255 - ((255-a)*(255-b) >> 8)   "screen" blend  1-(1-a)(1-b)
 *  lut2 = ~lut1                                  ((255-a)*(255-b) >> 8), the "multiply" blend */
export function makeLuts() {
  const lut1 = new Uint8Array(65536), lut2 = new Uint8Array(65536);
  for (let a = 0, i = 0; a < 256; a++) for (let b = 0; b < 256; b++, i++) {
    lut1[i] = 255 - (((255 - a) * (255 - b)) >> 8) & 255; lut2[i] = ~lut1[i] & 255;
  }
  return { lut1, lut2 };
}
/** Build a render context. @param {Uint32Array} target 320x200 pixel buffer */
export function makeRenderContext(target, luts = makeLuts()) {
  return { target, screen: target, pitch: 320, lut1: luts.lut1, lut2: luts.lut2, colors: null };
}

// ---------------------------------------------------------------------------------------------------------------
// Polygon clipping (Sutherland-Hodgman against x=0, x=320, y=0, y=200 in that order: 0x2ad90 / 0x2b634 / 0x2b1c8)
// Vertices are Float32Array [x, y, attr0, attr1, ...]; `na` = number of interpolated attributes.
const CLIPS = [[0, 0, true], [0, 320, false], [1, 0, true], [1, 200, false]];   // [axis, value, outsideIfLess]
export function clipPoly(L, na) {
  for (const [ax, c, low] of CLIPS) {
    const out = [], m = L.length, o = 1 - ax;
    for (let i = 0; i < m; i++) {
      const p = L[i], q = L[(i + 1) % m];
      const pin = low ? !(p[ax] < c) : !(p[ax] > c), qin = low ? !(q[ax] < c) : !(q[ax] > c);
      if (pin) out.push(p);
      if (pin !== qin) {                                   // edge crosses the line: t=(c-p)/(q-p), v=p*(1-t)+q*t
        const t = (c - p[ax]) / (q[ax] - p[ax]), r = new Float32Array(p.length);
        r[ax] = c; r[o] = p[o] * (1 - t) + q[o] * t;
        for (let k = 0; k < na; k++) r[2 + k] = p[2 + k] * (1 - t) + q[2 + k] * t;
        out.push(r);
      }
    }
    L = out;
  }
  return L;
}
const outcode = (v) => (v[1] < 0 ? 1 : 0) | (v[1] > 200 ? 2 : 0) | (v[0] < 0 ? 4 : 0) | (v[0] > 320 ? 8 : 0);   // 0x25f70

// ---------------------------------------------------------------------------------------------------------------
// Generic polygon scan converter = 0x2bbec / 0x2be3c / 0x2c35c / 0x2c7ec / 0x2cc2c with their edge steppers
// (0x2b9c0/0x2ba8c/...). P = Int32Array of 16.16 vertices [x,y,attr...] stride S; edge A (right side, x only) walks
// backwards from the top vertex, edge B (left side: x + attributes) forwards. Gradients along x are constant
// (planar mapping), so only B carries attributes. span(dstIndex, count, pre, B.attrs) is called per scanline;
// pre = (ceil(x)<<16) - x is the 16.16 sub-pixel pre-step.
export function fillPoly(P, n, S, na, pitch, span) {
  let top = 0, bot = 0, ymin = P[1], ymax = P[1];
  for (let i = 1; i < n; i++) { const y = P[i * S + 1]; if (ymin <= y) { if (ymax < y) { ymax = y; bot = i; } } else { ymin = y; top = i; } }
  if (top === bot) return;
  let Aidx = top, Acnt = 0, Ax = 0, Astep = 0;
  let Bidx = top, Bcnt = 0, Bx = 0, Bstep = 0;
  const Ba = new Int32Array(na), Bda = new Int32Array(na);
  const ceil = (y) => (y + 0xffff) >> 16;
  const fetchA = () => {                                       // 0x2b9c0
    const cur = Aidx, nx = cur > 0 ? cur - 1 : n - 1, cy = P[cur * S + 1], ny = P[nx * S + 1];
    Aidx = nx; Acnt = ceil(ny) - ceil(cy);
    if (Acnt <= 0) return;
    const dx = (P[nx * S] - P[cur * S]) | 0, dy = (ny - cy) | 0;
    Astep = Acnt > 1 ? div16(dx, dy) : mulsh(dx, Math.trunc(0x40000000 / dy) | 0, 14);
    Ax = (mulsh((ceil(cy) << 16) - cy | 0, Astep, 16) + P[cur * S]) | 0;
  };
  const fetchB = () => {                                       // 0x2ba8c
    const cur = Bidx, nx = cur < n - 1 ? cur + 1 : 0, cy = P[cur * S + 1], ny = P[nx * S + 1];
    Bidx = nx; Bcnt = ceil(ny) - ceil(cy);
    if (Bcnt <= 0) return;
    const dy = (ny - cy) | 0, pre = (ceil(cy) << 16) - cy | 0, one = Bcnt <= 1, rc = one ? Math.trunc(0x40000000 / dy) | 0 : 0;
    const dx = (P[nx * S] - P[cur * S]) | 0;
    Bstep = one ? mulsh(dx, rc, 14) : div16(dx, dy);
    Bx = (mulsh(pre, Bstep, 16) + P[cur * S]) | 0;
    for (let k = 0; k < na; k++) {
      const d = (P[nx * S + 2 + k] - P[cur * S + 2 + k]) | 0;
      Bda[k] = one ? mulsh(d, rc, 14) : div16(d, dy);
      Ba[k] = (mulsh(pre, Bda[k], 16) + P[cur * S + 2 + k]) | 0;
    }
  };
  fetchA();
  while (Acnt <= 0) { if (Aidx === bot) return; fetchA(); }
  for (;;) { if (Bidx === bot) return; fetchB(); if (Bcnt > 0) break; }
  let row = ceil(ymin) * pitch;
  for (;;) {
    const xl = ceil(Bx), cnt = ceil(Ax) - xl;
    if (cnt > 0) span(row + xl, cnt, (xl << 16) - Bx | 0, Ba);
    row += pitch;
    if (--Acnt <= 0) { for (;;) { if (Aidx === bot) return; fetchA(); if (Acnt > 0) break; } } else Ax = (Ax + Astep) | 0;
    if (--Bcnt <= 0) { for (;;) { if (Bidx === bot) return; fetchB(); if (Bcnt > 0) break; } }
    else { Bx = (Bx + Bstep) | 0; for (let k = 0; k < na; k++) Ba[k] = (Ba[k] + Bda[k]) | 0; }
  }
}

// ---- span loops (the inner loops). 8.8 texture coordinates are kept as 24-bit (int8:frac16) accumulators: the
// original adds the 16-bit fraction into a register half and `adc`s the carry into an 8-bit integer register,
// so u,v wrap at 256 texels for free.
const M24 = 0xffffff;
/** 0x2bbec span: opaque affine texture lookup tex[v<<8|u] */
const spanTex = (buf, tex, gu, gv) => (dst, n, pre, a) => {
  let u = ((a[0] + mulsh(pre, gu, 16)) | 0) & M24, v = ((a[1] + mulsh(pre, gv, 16)) | 0) & M24;
  const du = gu & M24, dv = gv & M24;
  for (let i = 0; i < n; i++) { buf[dst + i] = tex[((v >>> 16) << 8) | (u >>> 16)]; u = (u + du) & M24; v = (v + dv) & M24; }
};
/** 0x2be3c span: 50% blend with the destination: per byte (t+d)>>1 (add / rcr), byte3 from the texel */
const spanTexAvg = (buf, tex, gu, gv) => (dst, n, pre, a) => {
  let u = ((a[0] + mulsh(pre, gu, 16)) | 0) & M24, v = ((a[1] + mulsh(pre, gv, 16)) | 0) & M24;
  const du = gu & M24, dv = gv & M24;
  for (let i = 0; i < n; i++) {
    const t = tex[((v >>> 16) << 8) | (u >>> 16)], d = buf[dst + i];
    buf[dst + i] = ((t & 0xff000000) | (((t & d) + (((t ^ d) >>> 1) & 0x7f7f7f)) & 0xffffff)) >>> 0;
    u = (u + du) & M24; v = (v + dv) & M24;
  }
};
/** 0x2c7ec span: 1-D lookup tex[u] (v is forced to 0): "shading ramp" indexed by the normal's x component */
const spanRamp = (buf, tex, gu) => (dst, n, pre, a) => {
  let u = ((a[0] + mulsh(pre, gu, 16)) | 0) & M24; const du = gu & M24;
  for (let i = 0; i < n; i++) { buf[dst + i] = tex[u >>> 16]; u = (u + du) & M24; }
};
/** 0x2f2b4 span (called from 0x2c35c; self-modifying code in the original): two lookups added with a plain 32-bit add:
 *  tex1[(b<<8)|a] + tex2[(d<<8)|c] where tex2 is the 256x256 table 0x40000 bytes behind tex1 (env map + surface texture) */
const spanTwoTex = (buf, tex1, tex2, g) => (dst, n, pre, at) => {
  const s = [0, 1, 2, 3].map((k) => ((at[k] + mulsh(pre, g[k], 16)) | 0) & M24), d = g.map((x) => x & M24);
  let [a, b, c, e] = s;
  for (let i = 0; i < n; i++) {
    buf[dst + i] = (tex1[((b >>> 16) << 8) | (a >>> 16)] + tex2[((e >>> 16) << 8) | (c >>> 16)]) >>> 0;
    a = (a + d[0]) & M24; b = (b + d[1]) & M24; c = (c + d[2]) & M24; e = (e + d[3]) & M24;
  }
};
/** 0x2cc2c span: linear texture addressing with arbitrary pitch (u + v*pitch), carry of the v fraction selects the
 *  row step; `tex` is any Uint32Array (the demo passes a 320-wide screen copy -> screen-space warp) */
const spanWarp = (buf, tex, tpitch, du, dv) => (dst, n, pre, a) => {
  const u = (a[0] + mulsh(pre, du, 16)) | 0, v = (a[1] + mulsh(pre, dv, 16)) | 0;
  let idx = (u >> 16) + (v >> 16) * tpitch, uf = (u & 0xffff) >>> 0, vf = (v & 0xffff) >>> 0;
  const dfu = du & 0xffff, dfv = dv & 0xffff, step = (du >> 16) + (dv >> 16) * tpitch;
  for (let i = 0; i < n; i++) {
    buf[dst + i] = tex[idx];
    uf += dfu; vf += dfv; idx += step;
    if (uf > 0xffff) { uf &= 0xffff; idx++; }
    if (vf > 0xffff) { vf &= 0xffff; idx += tpitch; }
  }
};

// ---------------------------------------------------------------------------------------------------------------
// Triangle entry points. V = Float32Array of 3 vertices with stride 5 (x,y,a,b,-) or 7 (x,y,a,b,c,d,-) as built by
// the dispatcher (the last slot is the outcode in the original). tex = Uint32Array (256x256) or a 2x block.
function vtx(V, st, i, k) { return V.slice(i * st, i * st + k); }
/** gradients: first attr uses the float32-rounded dy's (stored on the stack in the original), the others recompute them */
function setup(v, na) {
  const dy1 = f32(v[1][1] - v[2][1]), dy2 = f32(v[0][1] - v[2][1]);
  const det = (v[0][0] - v[2][0]) * dy1 - (v[1][0] - v[2][0]) * dy2;
  if (det === 0) return null;
  const inv = (1 / det) * 65536, g = [];
  for (let k = 0; k < na; k++) {
    const a0 = v[0][2 + k] - v[2][2 + k], a1 = v[1][2 + k] - v[2][2 + k];
    g.push(rne(k === 0 ? (a0 * dy1 - a1 * dy2) * inv
      : (a0 * (v[1][1] - v[2][1]) - a1 * (v[0][1] - v[2][1])) * inv));
  }
  return g;
}
/** convert a clipped float polygon to 16.16 and scan convert; or (no clipping needed) the 3 vertices directly */
function run(v, na, S, ctx, mkSpan, andReject) {
  const oc = v.map(outcode);
  if (andReject && (oc[0] & oc[1] & oc[2])) return;
  let L = v;
  if ((oc[0] | oc[1] | oc[2]) & 15) { L = clipPoly(v, na); if (L.length < 3) return; }
  const P = new Int32Array(L.length * S);
  for (let i = 0; i < L.length; i++) for (let k = 0; k < 2 + na; k++) P[i * S + k] = rne(L[i][k] * 65536);
  fillPoly(P, L.length, S, na, ctx.pitch, mkSpan);
}
/** 0x25fc0: opaque textured triangle, vertices (x,y,u,v) */
export function tri_25fc0(ctx, V, tex) {
  const v = [0, 1, 2].map((i) => vtx(V, 5, i, 4)), g = setup(v, 2);
  if (g) run(v, 2, 4, ctx, spanTex(ctx.target, tex, g[0], g[1]), false);
}
/** 0x26308: like 25fc0 but 50% blended with what is already on screen */
export function tri_26308(ctx, V, tex) {
  const v = [0, 1, 2].map((i) => vtx(V, 5, i, 4)), g = setup(v, 2);
  if (g) run(v, 2, 4, ctx, spanTexAvg(ctx.target, tex, g[0], g[1]), false);
}
/** 0x26b90: vertices (x,y,u): 1-D ramp lookup tex[u] */
export function tri_26b90(ctx, V, tex) {
  const v = [0, 1, 2].map((i) => vtx(V, 5, i, 3)), g = setup(v, 1);
  if (g) run(v, 1, 4, ctx, spanRamp(ctx.target, tex, g[0]), false);
}
/** 0x266a0: vertices (x,y,eu,ev,tu,tv): env-map texel + surface texel; tex = block of 2 textures (env, surface) */
export function tri_266a0(ctx, V, tex) {
  const v = [0, 1, 2].map((i) => vtx(V, 7, i, 6)), g = setup(v, 4);
  if (g) run(v, 4, 6, ctx, spanTwoTex(ctx.target, tex, tex.subarray(65536), g), true);
}
/** 0x26e28: vertices (x,y,u,v) addressing `tex` with row pitch `tpitch` (0x140) */
export function tri_26e28(ctx, V, tex, tpitch) {
  const v = [0, 1, 2].map((i) => vtx(V, 5, i, 4)), g = setup(v, 2);
  if (g) run(v, 2, 4, ctx, spanWarp(ctx.target, tex, tpitch, g[0], g[1]), true);
}

// ---------------------------------------------------------------------------------------------------------------
// Anti-aliased lines (0x21b70 / 0x21f3b / 0x22463 clip against [1,318]x[1,198], coordinates are 16.16)
const XMIN = 0x10000, XMAX = 318 * 65536, YMIN = 0x10000, YMAX = 198 * 65536;
/** clip a line (swap/xchg dance of the original); c0,c1 are 16.16 colours that are interpolated at the cut points.
 *  returns [x0,y0,x1,y1,c0,c1] or null */
function clipLine(x0, y0, x1, y1, c0, c1) {
  let ebx = x0, ecx = y0, esi = x1, edi = y1, a = c0, b = c1, t;
  const lerp = (p, q) => (mulsh(p, 0x10000 - t, 16) + mulsh(q, t, 16)) | 0;
  if (ebx > esi) { [esi, ebx] = [ebx, esi]; [edi, ecx] = [ecx, edi]; [b, a] = [a, b]; }
  if (ebx < XMIN && esi > XMIN) { t = div16((XMIN - ebx) | 0, (esi - ebx) | 0); ecx = lerp(ecx, edi); a = lerp(a, b); ebx = XMIN; }
  if (ebx <= XMAX && esi > XMAX) { t = div16((XMAX - ebx) | 0, (esi - ebx) | 0); edi = lerp(ecx, edi); b = lerp(a, b); esi = XMAX; }
  if (ecx > edi) { [esi, ebx] = [ebx, esi]; [edi, ecx] = [ecx, edi]; [b, a] = [a, b]; }
  if (ecx < YMIN && edi > YMIN) { t = div16((YMIN - ecx) | 0, (edi - ecx) | 0); ebx = lerp(ebx, esi); a = lerp(a, b); ecx = YMIN; }
  if (edi > YMAX && ecx < YMAX) { t = div16((YMAX - ecx) | 0, (edi - ecx) | 0); esi = lerp(ebx, esi); b = lerp(a, b); edi = YMAX; }
  if (ebx < XMIN || ebx > XMAX || ecx < YMIN || ecx > YMAX || esi < XMIN || esi > XMAX || edi < YMIN || edi > YMAX) return null;
  return [ebx, ecx, esi, edi, a, b];
}
/** the line drawer core 0x21d1c / 0x221fc / 0x2271c: 2 pixels per step with weights (1-f, f) -> I=W*C>>8,
 *  then screen blend (lut1: lighten) or multiply (lut2: darken, `mode`='mul') with the destination. */
function drawLine(ctx, x0, y0, x1, y1, c0, c1, mul) {
  const scr = ctx.screen, L = ctx.lut1;
  let dx = (x1 - x0) | 0, dy = (y1 - y0) | 0, xmaj = true;
  if (dx === 0 && dy === 0) return;
  let ebx = x0, ecx = y0, esi = x1, edi = y1, ca = (c0 & 255) << 16, cb = (c1 & 255) << 16;
  if (Math.abs(dx) <= Math.abs(dy)) { xmaj = false; [ebx, ecx] = [ecx, ebx]; [esi, edi] = [edi, esi]; [dx, dy] = [dy, dx]; }
  if (ebx > esi) { [esi, ebx] = [ebx, esi]; [edi, ecx] = [ecx, edi]; [cb, ca] = [ca, cb]; dx = -dx; dy = -dy; }
  const cstep = div16(cb - ca | 0, dx), slope = div16(dy, dx);
  const first = (ebx + 0x8000) & 0xffff0000;
  let ypos = (mulsh(first - ebx | 0, slope, 16) + ecx) | 0, xend = (esi + 0x8000) >> 16, x = first >> 16, c = ca;
  const plot = (idx, w, col) => {
    const I = (w * col) >> 8, d = scr[idx];
    if (mul) {                                                        // 0x2271c: ((255-I)*D)>>8 per byte, byte3 inverted
      let r = ((~d) & 0xff000000);
      for (let s = 0; s < 24; s += 8) r |= ((255 - I) * ((d >>> s) & 255) >> 8) << s;
      scr[idx] = r >>> 0;
    } else {                                                          // lighten: lut1[I<<8|D]
      scr[idx] = ((d & 0xff000000) | (L[(I << 8) | (d & 255)]) | (L[(I << 8) | ((d >>> 8) & 255)] << 8) | (L[(I << 8) | ((d >>> 16) & 255)] << 16)) >>> 0;
    }
  };
  do {                                                   // do-while: at least one step (inc/cmp/jl at the bottom)
    const frac = ypos & 0xffff, col = (c >>> 16) & 255, w1 = (0xffff - frac) >> 8, w2 = frac >> 8, y = ypos >>> 16;
    if (xmaj) { plot(y * 320 + x, w1, col); plot((y + 1) * 320 + x, w2, col); }
    else { plot(x * 320 + y, w1, col); plot(x * 320 + y + 1, w2, col); }
    c = (c + cstep) | 0; ypos = (ypos + slope) | 0;
  } while (++x < xend);
}
/** 0x21b70: line with constant colour (0..255), 16.16 coordinates */
export function line_21b70(ctx, col, x0, y0, x1, y1) {
  const c = clipLine(x0, y0, x1, y1, 0, 0);
  if (c) drawLine(ctx, c[0], c[1], c[2], c[3], col, col, false);
}
/** 0x21f3b: lighten line, colour interpolated from c0 (at x0,y0) to c1 (at x1,y1) */
export function line_21f3b(ctx, c0, c1, x0, y0, x1, y1) {
  if (!c0 && !c1) return;
  const c = clipLine(x0, y0, x1, y1, (c0 & 255) << 16, (c1 & 255) << 16);
  if (c) drawLine(ctx, c[0], c[1], c[2], c[3], (c[4] >>> 16) & 255, (c[5] >>> 16) & 255, false);
}
/** 0x22463: darkening (multiply) variant of 21f3b */
export function line_22463(ctx, c0, c1, x0, y0, x1, y1) {
  if (!c0 && !c1) return;
  const c = clipLine(x0, y0, x1, y1, (c0 & 255) << 16, (c1 & 255) << 16);
  if (c) drawLine(ctx, c[0], c[1], c[2], c[3], (c[4] >>> 16) & 255, (c[5] >>> 16) & 255, true);
}

// ---------------------------------------------------------------------------------------------------------------
// Point sprites 0x1efbc / 0x1febc: a 256x256 byte intensity table (tex) is scaled onto a (2r)x(2r) box centered at
// (x,y) (all 8.8 fixed point) and added with saturation (per byte) to the destination.
// colour (0x1febc): added value is (colorByte*t)>>8 instead of t.
function sprite(dst, tex, x8, y8, r8, col) {
  const add = (d, t) => {
    if (col === null) return ((d & 0xff000000) | (Math.min(255, (d & 255) + t)) | (Math.min(255, ((d >>> 8) & 255) + t) << 8) | (Math.min(255, ((d >>> 16) & 255) + t) << 16)) >>> 0;
    const t0 = (col[0] * t) >> 8, t1 = (col[1] * t) >> 8, t2 = (col[2] * t) >> 8;
    return ((d & 0xff000000) | (Math.min(255, (d & 255) + t0)) | (Math.min(255, ((d >>> 8) & 255) + t1) << 8) | (Math.min(255, ((d >>> 16) & 255) + t2) << 16)) >>> 0;
  };
  const ex = x8 >> 8, ey = y8 >> 8, r = r8 >> 8;
  const step = Math.trunc(0x1000000 / (2 * r8)) | 0;
  let edi, cols, rows, u0, v0;
  const uo = ((0x7f - (x8 & 255) + (r8 & 255)) * step) >>> 8, vo = ((0x7f - (y8 & 255) + (r8 & 255)) * step) >>> 8;
  if (ex - r >= 0 && ex + r < 0x13f && ey - r >= 0 && ey + r < 0xc7) {          // fully inside
    edi = ex - r + (ey - r) * 320; cols = rows = 2 * r; u0 = uo; v0 = vo;
  } else {                                                                      // clipped path (0x1f119)
    if (ex - r >= 0x13f || ex + r < 0 || ey - r >= 0xc7 || ey + r < 0) return;
    let x = ex - r, y = ey - r; rows = cols = 2 * r; u0 = v0 = 0;
    const colsMax = cols, rowsMax = rows;
    if (x < 0) { cols = colsMax + x; u0 = Math.imul(-x, step); x = 0; }
    if (x + cols >= 0x13f) cols = 0x140 - x;
    if (y < 0) { rows = rowsMax + y; v0 = Math.imul(-y, step); y = 0; }
    if (y + rows >= 0xc7) rows = 0xc8 - y;
    if (cols < 2) cols = 2;
    u0 = (u0 + uo) | 0; v0 = (v0 + vo) | 0;
    edi = x + y * 320; rows = Math.max(2, Math.min(rows, 0xfa));
  }
  // row/column loops: 8-bit integer texel with 8-bit fraction carried in the top byte of a register (adc trick)
  const sI = (step >>> 8) & 255, sF = step & 255;
  let vint = (v0 >>> 8) & 255, vfr = v0 & 255;
  for (let j = 0; j < rows; j++) {
    let uint = (u0 >>> 8) & 255, ufr = u0 & 255, p = edi;
    for (let i = 0; i < cols; i++, p++) {
      const t = tex[(vint << 8) | uint];
      if (t) dst[p] = add(dst[p], t);
      ufr += sF; uint = (uint + sI + (ufr >> 8)) & 255; ufr &= 255;
    }
    vfr += sF; vint = (vint + sI + (vfr >> 8)) & 255; vfr &= 255;
    edi += 320;
  }
}
/** 0x1efbc: additive white point sprite. dst=target buffer, tex=256x256 Uint8Array, x8/y8/r8 in 8.8 fixed point */
export function sprite_1efbc(dst, tex, x8, y8, r8) { sprite(dst, tex, x8, y8, r8, null); }
/** 0x1febc: coloured additive sprite; rgb bytes = [byte0, byte1, byte2] of the colour dword */
export function sprite_1febc(dst, tex, x8, y8, r8, rgb) { sprite(dst, tex, x8, y8, r8, rgb); }
