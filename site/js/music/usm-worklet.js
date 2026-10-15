// AudioWorklet processor: runs the ported USM player (bit-exact SB16 mixer of the original) and streams it out.
import { UsmPlayer } from './usm.js';
class UsmProcessor extends AudioWorkletProcessor {
  constructor() {
    super(); this.p = null; this.l = new Float32Array(128); this.r = new Float32Array(128); this.playing = false;
    this.port.onmessage = ({ data }) => {
      if (data.bytes) this.p = new UsmPlayer(data.bytes, sampleRate);
      if (data.seek && this.p) this.p.seek(data.seek.order, data.seek.row);
      if ('playing' in data) this.playing = data.playing;
    };
  }
  process(_, outputs) {
    const o = outputs[0]; if (!this.p || !this.playing) return true;
    this.p.renderInto(this.l, this.r, 128); o[0].set(this.l); if (o[1]) o[1].set(this.r);
    return true;
  }
}
registerProcessor('usm', UsmProcessor);
