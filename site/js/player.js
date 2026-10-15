// Canvas player: owns the 320x200 canvas, the clock (audio or wall), pause / skip scene / fullscreen.
// A "demo" object provides: scenes:[{name, start(order), end(order)}], frame(rgbaImageData, state), positionAt(sec)->{order,row}, duration, secOf(order)
const TICK = 70; // original timer rate (Hz)
export class Player {
  constructor(canvas, demo, { audio = null, onScene = () => {}, onTime = () => {} } = {}) {
    Object.assign(this, { canvas, demo, audio, onScene, onTime });
    this.ctx = canvas.getContext('2d', { alpha: false });
    this.img = this.ctx.createImageData(320, 200);
    this.t = 0; this.playing = false; this.scene = -1; this.last = 0; this.raf = 0; this.frameNo = 0;
  }
  get sceneIndex() { return this.scene; }
  now() { return this.audio && this.audio.ready ? this.audio.time : this.t; }
  play() { if (this.playing) return; this.playing = true; this.audio?.resume?.(this.t); this.last = performance.now(); this.raf = requestAnimationFrame(this.loop); }
  pause() { this.playing = false; this.audio?.suspend?.(); cancelAnimationFrame(this.raf); }
  toggle() { this.playing ? this.pause() : this.play(); }
  seek(sec) { this.t = Math.max(0, Math.min(this.demo.duration - 0.01, sec)); this.audio?.seek?.(this.t); this.demo.reset?.(this.t); this.draw(0); }
  skip(delta = 1) {                                   // next/previous scene
    const s = this.demo.scenes; let i = Math.max(0, this.scene) + delta;
    if (delta < 0 && this.t - this.demo.secOf(s[this.scene].start) > 2) i = this.scene; // first press: restart current scene
    i = Math.max(0, Math.min(s.length - 1, i)); this.seek(this.demo.secOf(s[i].start));
  }
  fullscreen() {
    const el = this.canvas.parentElement;
    if (document.fullscreenElement) document.exitFullscreen(); else (el.requestFullscreen || el.webkitRequestFullscreen).call(el);
  }
  loop = (now) => {
    if (!this.playing) return;
    const dt = Math.min(0.1, (now - this.last) / 1000); this.last = now;
    if (!(this.audio && this.audio.ready)) this.t += dt; else this.t = this.audio.time;
    if (this.t >= this.demo.duration) { this.t = 0; this.audio?.seek?.(0); this.demo.reset?.(0); }
    this.draw(dt); this.raf = requestAnimationFrame(this.loop);
  };
  draw(dt) {
    const pos = this.demo.positionAt(this.t);
    const si = this.demo.scenes.findIndex(s => pos.order >= s.start && pos.order < s.end);
    if (si !== this.scene) { this.scene = si; this.onScene(si); }
    this.demo.frame(this.img.data, { t: this.t, dt, ticks: Math.floor(this.t * TICK), order: pos.order, row: pos.row, scene: si });
    this.ctx.putImageData(this.img, 0, 0); this.frameNo++;
    this.onTime(this.t, this.demo.duration);
  }
}
