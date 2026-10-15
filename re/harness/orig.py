"""Run functions of the ORIGINAL ZILOG.EXE (unpacked image) under Unicorn, for differential testing of the JS port.

  S=/tmp/claude-1000/-home-gautier-SynologyDrive-code-current-demos-zilog/30d78e4d-6a5d-45da-a815-458c6cbb7835/scratchpad
  $S/v/bin/python  your_test.py          (venv has unicorn + capstone)

Usage:
  from orig import Orig
  o = Orig()
  buf = o.alloc(64000*4)                 # heap block in emulated memory (bump allocator, zero-filled)
  o.write(buf, bytes)                    # / o.read(buf, n) / o.w32(addr,v) / o.r32(addr) / o.wf32(addr,f) ...
  r = o.call(0x16cdd, eax=.., edx=.., ebx=.., ecx=.., esi=.., edi=.., stack=[a,b,c], st=[floats pushed on x87 stack])
  r.eax, r.edx ... ; r.st0 (top of x87 stack) ; o.read(...) afterwards.

Conventions: image base 0x10000 (file offset = addr-0x10000), data/bss 0x3d000-0x44000 live and mutable (globals
such as DAT_000402f0 are real memory; set them with o.w32 before calling functions that depend on them).
Watcom register convention: args in EAX, EDX, EBX, ECX then stack (callee pops). Most user functions preserve all regs
except EAX. Float args are pushed on the stack as 4-byte floats (or 8 for double) in the order shown by the asm.
Hooks: malloc(0x24c8f)->bump alloc, free(0x23831)->nop, thunk malloc, in/out/int -> ignored (logged in o.io_log).
"""
import os, struct
from unicorn import *
from unicorn.x86_const import *

HERE = os.path.dirname(os.path.abspath(__file__))
IMAGE = os.path.join(HERE, '..', 'image.bin')
BASE, IMGSZ = 0x10000, 0x34000
HEAP, HEAPSZ = 0x2000000, 0x6000000
STK = 0x900000
SENT = 0x8ff000          # return sentinel

class R: pass

class Orig:
    def __init__(self, image=IMAGE):
        mu = self.mu = Uc(UC_ARCH_X86, UC_MODE_32)
        mu.mem_map(BASE, 0x40000)                       # image + bss (0x10000..0x50000)
        mu.mem_write(BASE, open(image, 'rb').read()[:IMGSZ])
        mu.mem_map(STK - 0x100000, 0x200000)
        mu.mem_map(HEAP, HEAPSZ)
        mu.mem_write(SENT, b'\xf4')                      # hlt
        self.brk = HEAP + 0x1000
        self.io_log = []
        self.last_unmapped = None
        mu.hook_add(UC_HOOK_CODE, self._code)
        self._fpu_init()
        mu.hook_add(UC_HOOK_INTR, lambda uc, n, ud: self.io_log.append(('int', n)))
        mu.hook_add(UC_HOOK_INSN, lambda uc, port, size, ud: 0, None, 1, 0, UC_X86_INS_IN)
        mu.hook_add(UC_HOOK_INSN, lambda uc, port, size, val, ud: self.io_log.append(('out', port, val)), None, 1, 0, UC_X86_INS_OUT)

    def _fpu_init(self):
        # Unicorn starts with x87 control word 0 (24-bit precision!). The real program runs after fninit (0x37f).
        d = self.alloc(16); code = self.alloc(16)
        self.write(d, b'\x7f\x03'); self.write(code, b'\xd9\x2d' + struct.pack('<I', d) + b'\xc3')
        self.call_raw = None
        self.call(code)

    # ---- memory helpers
    def alloc(self, n, align=16):
        self.brk = (self.brk + align - 1) & ~(align - 1)
        a = self.brk; self.brk += n
        assert self.brk < HEAP + HEAPSZ
        return a
    def write(self, a, b): self.mu.mem_write(a, bytes(b))
    def read(self, a, n): return bytes(self.mu.mem_read(a, n))
    def w32(self, a, v): self.mu.mem_write(a, struct.pack('<I', v & 0xffffffff))
    def r32(self, a): return struct.unpack('<I', self.read(a, 4))[0]
    def wf32(self, a, f): self.mu.mem_write(a, struct.pack('<f', f))
    def rf32(self, a): return struct.unpack('<f', self.read(a, 4))[0]
    def w16(self, a, v): self.mu.mem_write(a, struct.pack('<H', v & 0xffff))
    def w8(self, a, v): self.mu.mem_write(a, bytes([v & 255]))

    def _code(self, uc, addr, size, ud):
        if addr in (0x24c8f,):                           # malloc(eax=size) -> eax
            n = uc.reg_read(UC_X86_REG_EAX)
            uc.reg_write(UC_X86_REG_EAX, self.alloc(max(n, 4)))
            self._ret(uc)
        elif addr in (0x23831,):                         # free
            self._ret(uc)
    def _ret(self, uc):
        esp = uc.reg_read(UC_X86_REG_ESP)
        ret = struct.unpack('<I', bytes(uc.mem_read(esp, 4)))[0]
        uc.reg_write(UC_X86_REG_ESP, esp + 4); uc.reg_write(UC_X86_REG_EIP, ret)

    def call(self, addr, eax=0, edx=0, ebx=0, ecx=0, esi=0, edi=0, ebp=0, stack=(), st=(), max_insn=200_000_000):
        mu = self.mu
        esp = STK
        for v in reversed(stack):                        # stack args: first arg at lowest address
            esp -= 4
            mu.mem_write(esp, struct.pack('<I', v & 0xffffffff) if not isinstance(v, float) else struct.pack('<f', v))
        esp -= 4; mu.mem_write(esp, struct.pack('<I', SENT))
        for r, v in ((UC_X86_REG_EAX, eax), (UC_X86_REG_EDX, edx), (UC_X86_REG_EBX, ebx), (UC_X86_REG_ECX, ecx),
                     (UC_X86_REG_ESI, esi), (UC_X86_REG_EDI, edi), (UC_X86_REG_EBP, ebp), (UC_X86_REG_ESP, esp)):
            mu.reg_write(r, v & 0xffffffff)
        mu.reg_write(UC_X86_REG_EFLAGS, 0x202)
        try:
            mu.emu_start(addr, SENT, count=max_insn)
        except UcError as e:
            raise RuntimeError(f'emulation error {e} at eip={mu.reg_read(UC_X86_REG_EIP):#x}')
        r = R()
        for n, reg in (('eax', UC_X86_REG_EAX), ('edx', UC_X86_REG_EDX), ('ebx', UC_X86_REG_EBX), ('ecx', UC_X86_REG_ECX),
                       ('esi', UC_X86_REG_ESI), ('edi', UC_X86_REG_EDI), ('esp', UC_X86_REG_ESP)):
            setattr(r, n, mu.reg_read(reg))
        try: r.st0 = mu.reg_read(UC_X86_REG_ST0)
        except Exception: r.st0 = None
        return r
