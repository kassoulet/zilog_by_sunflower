"""Ground truth for the USM *mixer*: runs the original SB16 software mixer (0x39bc0 / 0x3a5d6 ...) under Unicorn for the real
module and dumps every 884-frame stereo int16 block.  The DMA hardware is skipped: the mixer buffers are set up by hand and the
heap allocators (0x37000/0x37028/0x3704a/0x37099) are hooked.
usage: python usm_mixtruth.py ana.u out.i16 nblocks     (out: raw little-endian int16 L,R interleaved, 1768 values/block)"""
import sys, os, struct
from unicorn import *
from unicorn.x86_const import *
HERE = os.path.dirname(os.path.abspath(__file__))
IMAGE = os.path.join(HERE, '..', '..', 're', 'image.bin')
BASE, IMGSZ, HEAP, HEAPSZ, STK, SENT = 0x10000, 0x34000, 0x2000000, 0x6000000, 0x900000, 0x8ff000
mu = Uc(UC_ARCH_X86, UC_MODE_32)
mu.mem_map(BASE, 0x40000)
img = bytearray(open(IMAGE, 'rb').read()[:IMGSZ])
i = 0x32000 - BASE
while True:                                   # 'push ds; pop es' misbehaves in unicorn flat mode
    j = img.find(b'\x1e\x07', i, 0x3c000 - BASE)
    if j < 0: break
    img[j:j + 2] = b'\x90\x90'; i = j + 2
mu.mem_write(BASE, bytes(img))
mu.mem_map(STK - 0x100000, 0x200000); mu.mem_map(HEAP, HEAPSZ); mu.mem_write(SENT, b'\xf4')
brk = [HEAP + 0x1000]
def alloc(n, al=16):
    brk[0] = (brk[0] + al - 1) & ~(al - 1); a = brk[0]; brk[0] += n; return a
w32 = lambda a, v: mu.mem_write(a, struct.pack('<I', v & 0xffffffff))
r32 = lambda a: struct.unpack('<I', bytes(mu.mem_read(a, 4)))[0]
w16 = lambda a, v: mu.mem_write(a, struct.pack('<H', v & 0xffff))
def ret(uc):
    esp = uc.reg_read(UC_X86_REG_ESP); r = r32(esp)
    uc.reg_write(UC_X86_REG_ESP, esp + 4); uc.reg_write(UC_X86_REG_EIP, r)
    uc.reg_write(UC_X86_REG_EFLAGS, uc.reg_read(UC_X86_REG_EFLAGS) & ~1)       # clc
def hk(uc, addr, size, ud):
    if addr in (0x37000, 0x37028):
        n = uc.reg_read(UC_X86_REG_EAX); w32(0x36ffc, alloc(n + 16)); ret(uc)
    elif addr in (0x3704a, 0x37099): ret(uc)
for a in (0x37000, 0x37028, 0x3704a, 0x37099): mu.hook_add(UC_HOOK_CODE, hk, begin=a, end=a)
mu.hook_add(UC_HOOK_INSN, lambda uc, port, size, ud: 0, None, 1, 0, UC_X86_INS_IN)
mu.hook_add(UC_HOOK_INSN, lambda uc, port, size, val, ud: None, None, 1, 0, UC_X86_INS_OUT)
def call(addr, **regs):
    esp = STK - 4; mu.mem_write(esp, struct.pack('<I', SENT))
    for r, v in (('EAX', 0), ('EDX', 0), ('EBX', 0), ('ECX', 0), ('ESI', 0), ('EDI', 0), ('EBP', 0)):
        mu.reg_write(getattr(__import__('unicorn.x86_const', fromlist=['x']), 'UC_X86_REG_' + r), regs.get(r.lower(), 0) & 0xffffffff)
    mu.reg_write(UC_X86_REG_ESP, esp); mu.reg_write(UC_X86_REG_EFLAGS, 0x202)
    mu.emu_start(addr, SENT, count=2_000_000_000)

data = open(sys.argv[1], 'rb').read(); nblk = int(sys.argv[3])
mod = alloc(len(data) + 0x1000); mu.mem_write(mod, data)
# --- device state: SB16 @44100 stereo 16-bit signed (flags 0x11a, set by 0x3927x for DSP >= 4.00)
w32(0x3398f, 0x38090); w16(0x36450, 5); mu.mem_write(0x33997, b'\0')
w16(0x3645a, 44100); w16(0x3645c, 0x11a)
w32(0x39880, 1768)
dma = alloc(2 * 3536 + 64); w32(0x39888, dma)
w16(0x398a8, 200)                                    # call 0x3409e(0xc8) in main
call(0x39a15)                                        # clear DMA buffer, allocate mix buffer + volume table (0x399bd)
call(0x322f0, esi=mod)                               # relocate + delta decode + upload samples through the real 0x39ae7
call(0x32406, esi=mod)                               # module init (the DSP start in 0x34009 fails harmlessly: no hardware)
w32(0x3916c, 0x32601)
out = open(sys.argv[2], 'wb')
for n in range(nblk):
    tog = struct.unpack('<H', bytes(mu.mem_read(0x3988c, 2)))[0]
    mu.reg_write(UC_X86_REG_EBP, 0)
    call(0x32601, eax=0x5d37)
    out.write(bytes(mu.mem_read(dma + (3536 if tog else 0), 3536)))
    if n % 500 == 0: print(n, flush=True)
out.close()
