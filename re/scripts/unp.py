from unicorn import *; from unicorn.x86_const import *
from capstone import *
d=open('/home/gautier/SynologyDrive/code/current/demos/zilog/ZILOG.EXE','rb').read()
BASE=0x10000; SZ=0x34000; STK=0x44000
mu=Uc(UC_ARCH_X86,UC_MODE_32)
mu.mem_map(BASE,SZ+0x2000)
mu.mem_write(BASE,d[0x2e53:0x2e53+19*0x1000-0x1000+0xcf8])
mu.mem_map(0x100000,0x10000)  # scratch
md=Cs(CS_ARCH_X86,CS_MODE_32)
eip=BASE+0xc9
for i in md.disasm(mu.mem_read(eip,120),eip): print(hex(i.address),i.mnemonic,i.op_str)
print('---run')
mu.reg_write(UC_X86_REG_ESP,STK+0x1000)
mu.reg_write(UC_X86_REG_EDI,BASE); mu.mem_write(BASE+0xd5,b'\x90\x90\x90')
state={'tail':False,'n':0}
def hook(uc,addr,size,ud):
    state['n']+=1
    if addr>=0x43000: state['tail']=True
    elif state['tail'] and addr<0x43000:
        print('LEFT TAIL at',hex(addr),'after',state['n']); uc.emu_stop()
def intr(uc,n,ud):
    print('INT',n,hex(uc.reg_read(UC_X86_REG_EIP)),hex(uc.reg_read(UC_X86_REG_EAX))); uc.emu_stop()
mu.hook_add(UC_HOOK_CODE,hook); mu.hook_add(UC_HOOK_INTR,intr)
try: mu.emu_start(BASE+0xd5,0,count=50_000_000)
except UcError as e: print('ERR',e,hex(mu.reg_read(UC_X86_REG_EIP)))
print('eip',hex(mu.reg_read(UC_X86_REG_EIP)),hex(mu.reg_read(UC_X86_REG_ESP)),state)
open('image.bin','wb').write(bytes(mu.mem_read(BASE,SZ)))
