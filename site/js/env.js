// Scene environment: assets + shared per-frame globals, mirroring the original's globals (see re/NOTES.md "Scene API").
import { parseContainer } from './core/assets.js';
import { loadGfx } from './core/gfx.js';
import { loadMob } from './core/mob.js';

export function makeEnv(containerBytes) {
  const files = parseContainer(containerBytes), gfxC = new Map(), mobC = new Map();
  const env = {
    files,
    W: 320, H: 200,
    scr: new Uint32Array(320 * 200),                 // DAT_000402f0: the screen / main render target (0x00RRGGBB dwords)
    gfx(name) { if (!gfxC.has(name)) gfxC.set(name, loadGfx(files.get(name))); return gfxC.get(name); },   // e.g. 'fullpics/simulcra.gfx'
    mob(name) { if (!mobC.has(name)) mobC.set(name, loadMob(files.get(name))); return mobC.get(name); },    // e.g. '3d/zilog1.mob' (raw lists; mesh3d.loadMesh builds the engine mesh)
    // --- per-frame globals, set by the host before each scene.frame(st) — equivalent of func_10061 (frame prologue, asm @0x10061):
    //   ticks  DAT_0004031c  timer ticks, 70 Hz, integer
    //   dt     DAT_0003ed0c  ticks since previous frame (integer >= 1)
    //   pos    DAT_00040328  = order*64 + row   (music position, compared against constants like 0x33f in scene code)
    //   time   DAT_00040310  = ticks*0.25 - DAT_00040314   (float32; DAT_00040314 is re-based by every scene at its start: `_DAT_00040314 = ticks * K`)
    //   sync   DAT_000314f4  last value of the module's 'sync marker' effect (0x20/0x33); syncCount increments on every marker
    st: { ticks: 0, dt: 1, order: 0, row: 0, pos: 0, time: 0, sync: 0, syncCount: 0 },
  };
  return env;
}
// Host helper: fill env.st for a given demo tick (and music position) exactly like func_10061 does.
export function setFrame(env, ticks, order, row, sync = 0, syncCount = 0, timeBase = 0) {
  const st = env.st; st.dt = Math.max(1, ticks - st.ticks); st.ticks = ticks; st.order = order; st.row = row;
  st.pos = order * 64 + row; st.sync = sync; st.syncCount = syncCount; st.time = Math.fround(ticks * 0.25 - timeBase);
  return st;
}
