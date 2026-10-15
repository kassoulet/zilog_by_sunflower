// Placeholder demo used until the real engine is wired in (checkerboard + scene tint).
export const stubDemo = {
  duration: 60, scenes: Array.from({ length: 10 }, (_, i) => ({ name: 'scene ' + i, start: i * 5, end: i * 5 + 5 })),
  secOf: o => o * 1.2, positionAt(t) { return { order: Math.floor(t / 1.2), row: 0 }; },
  frame(rgba, s) { for (let y = 0; y < 200; y++) for (let x = 0; x < 320; x++) { const i = (y * 320 + x) * 4, v = ((x + s.ticks) ^ y) & 255; rgba[i] = v; rgba[i + 1] = v * (s.scene + 1) / 10; rgba[i + 2] = 255 - v; rgba[i + 3] = 255; } },
};
