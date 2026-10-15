import { Player } from './player.js';
import { parseContainer } from './core/assets.js';
import { loadMob } from './core/mob.js';
import { SCENES } from './scenes-info.js';

// ---- tiny x86 highlighter for the <pre class="asm"> blocks
const REG = /\b(e?[abcd]x|[abcd][lh]|e?[sd]i|e?[sb]p|[cdefgs]s|st\(?\d?\)?|eip)\b/g;
export function hl(src) {
  return src.split('\n').map(l => {
    let c = ''; const i = l.indexOf(';'); if (i >= 0) { c = l.slice(i); l = l.slice(0, i); }
    const hot = l.startsWith('>'); if (hot) l = l.slice(1);
    l = l.replace(/&/g, '&amp;').replace(/</g, '&lt;');
    l = l.replace(/^(\s*)([0-9a-f]{5,6}:)?(\s*)([a-z]+)/i, (_, a, ad, b, m) => `${a}<span class="a">${ad || ''}</span>${b}<span class="m">${m}</span>`);
    l = l.replace(REG, '<span class="r">$1</span>').replace(/\b(0x[0-9a-f]+|\d+)\b(?![^<]*>)/gi, '<span class="n">$1</span>');
    c = c ? `<span class="c">${c.replace(/&/g, '&amp;').replace(/</g, '&lt;')}</span>` : '';
    return hot ? `<span class="hl">${l}${c}</span>` : l + c;
  }).join('\n');
}
document.querySelectorAll('pre.asm').forEach(p => { p.innerHTML = hl(p.textContent.replace(/^\n/, '')); });

// ---- player
const $ = s => document.querySelector(s);
async function boot() {
  let demo;
  try { demo = (await import('./demo.js')).demo; } catch (e) { console.warn('real demo not available, using stub', e); demo = (await import('./stub-demo.js')).stubDemo; }
  const canvas = $('#screen'), badge = $('#badge'), seek = $('#seek'), time = $('#time'), chips = $('#chips');
  let audio = null;
  try { audio = demo.audio ? await demo.audio() : null; } catch (e) { console.warn('audio unavailable', e); }
  const pl = new Player(canvas, demo, {
    audio,
    onScene: i => { badge.textContent = (demo.scenes[i]?.name) || ''; [...chips.children].forEach((c, k) => c.classList.toggle('on', k === i)); },
    onTime: (t, d) => { if (!seek.matches(':active')) seek.value = t / d * 1000; time.textContent = fmt(t) + ' / ' + fmt(d); },
  });
  const fmt = s => `${Math.floor(s / 60)}:${String(Math.floor(s % 60)).padStart(2, '0')}`;
  demo.scenes.forEach((s, i) => { const b = document.createElement('button'); b.textContent = s.name; b.title = 'Jump to ' + s.name; b.onclick = () => pl.seek(demo.secOf(s.start)); chips.append(b); });
  const playBtn = $('#bplay'), big = $('#big');
  const upd = () => { playBtn.textContent = pl.playing ? '⏸' : '▶'; playBtn.setAttribute('aria-label', pl.playing ? 'Pause' : 'Play'); big.hidden = pl.playing || pl.frameNo > 1; };
  let first = true;
  const toggle = () => { if (first && !pl.playing) { first = false; pl.seek(0); } pl.toggle(); upd(); };
  playBtn.onclick = big.onclick = toggle;
  $('#prev').onclick = () => pl.skip(-1); $('#next').onclick = () => pl.skip(1);
  $('#fs').onclick = () => pl.fullscreen();
  seek.oninput = () => pl.seek(seek.value / 1000 * demo.duration);
  addEventListener('keydown', e => {
    if (e.target.matches('input,button')) return;
    if (e.code === 'Space') { e.preventDefault(); toggle(); } else if (e.key === 'f') pl.fullscreen();
    else if (e.key === 'ArrowRight' || e.key === 'n') pl.skip(1); else if (e.key === 'ArrowLeft' || e.key === 'p') pl.skip(-1);
  });
  time.textContent = '0:00 / ' + fmt(demo.duration);
  const poster = new Image(); poster.onload = () => pl.ctx.drawImage(poster, 0, 0); poster.src = 'img/scene1.png'; upd();   // poster until the first play
  big.querySelector('button').textContent = '▶ Play the demo'; big.querySelector('button').disabled = false;
  window.__player = pl;
}
boot();

// ---- live wireframe gallery of the demo's 3D models (read straight from data.dat)
async function gallery() {
  const host = $('#meshes'); if (!host) return;
  const files = parseContainer(new Uint8Array(await (await fetch('data/data.dat')).arrayBuffer()));
  const items = [];
  for (const [name, bytes] of files) if (name.endsWith('.mob')) {
    const m = loadMob(bytes), el = document.createElement('div'); el.className = 'mesh';
    el.innerHTML = `<canvas width="240" height="240"></canvas><b>${name.slice(3, -4)}</b><br>${m.npts} verts · ${m.nfaces} faces · ${m.nedges} edges`;
    host.append(el); let r = 0; for (let i = 0; i < m.npts * 3; i++) r = Math.max(r, Math.abs(m.pts[i]));
    items.push({ m, c: el.querySelector('canvas'), r, vis: false });
  }
  items.forEach(i => new IntersectionObserver(es => { i.vis = es[0].isIntersecting; }).observe(i.c));
  const col = getComputedStyle(document.documentElement).getPropertyValue('--teal') || '#4fd1c5';
  (function tick(t) {
    for (const it of items) if (it.vis) {
      const g = it.c.getContext('2d'), { m } = it, a = t / 2500, ca = Math.cos(a), sa = Math.sin(a), cb = Math.cos(a * .7), sb = Math.sin(a * .7), s = 100 / it.r;
      g.clearRect(0, 0, 240, 240); g.strokeStyle = col.trim() || '#4fd1c5'; g.lineWidth = .6; g.globalAlpha = .8; g.beginPath();
      const P = new Float32Array(m.npts * 2);
      for (let i = 0; i < m.npts; i++) { const x = m.pts[i * 3], y = m.pts[i * 3 + 1], z = m.pts[i * 3 + 2];
        const x1 = x * ca + z * sa, z1 = -x * sa + z * ca, y1 = y * cb - z1 * sb, z2 = y * sb + z1 * cb, f = 1 / (1 + z2 / it.r / 6);
        P[i * 2] = 120 + x1 * s * f; P[i * 2 + 1] = 120 + y1 * s * f; }
      for (let e = 0; e < m.nedges; e++) { const a0 = m.edges[e * 2], b0 = m.edges[e * 2 + 1]; g.moveTo(P[a0 * 2], P[a0 * 2 + 1]); g.lineTo(P[b0 * 2], P[b0 * 2 + 1]); }
      g.stroke();
    }
    requestAnimationFrame(tick);
  })(0);
}
gallery().catch(e => console.warn('gallery', e));

// ---- scene cards (jump buttons seek the player)
(function sceneCards() {
  const host = document.querySelector('#scene-list'); if (!host) return;
  host.innerHTML = SCENES.map((sc, i) => `<article class="scene"><div><img src="img/${sc.img}" alt="${sc.title}" width="320" height="200"><button class="jump" data-i="${i}" type="button">▶ ${sc.t}</button></div><div><h3>${i}. ${sc.title} <small class="dim">orders ${sc.start}–${sc.end - 1}</small></h3><p>${sc.text}</p>${sc.tags.map(t => `<span class="tag">${t}</span>`).join('')}</div></article>`).join('');
  host.addEventListener('click', e => { const b = e.target.closest('.jump'); if (!b || !window.__player) return; const pl = window.__player; pl.seek(pl.demo.secOf(SCENES[+b.dataset.i].start)); document.querySelector('#play').scrollIntoView({ behavior: 'smooth' }); if (!pl.playing) document.querySelector('#bplay').click(); });
})();
