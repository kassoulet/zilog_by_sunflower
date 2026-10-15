import sys
from capstone import *
import os
d=open(os.path.join(os.path.dirname(os.path.abspath(__file__)),'..','image.bin'),'rb').read(); B=0x10000
md=Cs(CS_ARCH_X86,CS_MODE_32)
a=int(sys.argv[1],16); n=int(sys.argv[2],16) if len(sys.argv)>2 else 0x200
for i in md.disasm(d[a-B:a-B+n],a): print(f"{i.address:x}: {i.mnemonic} {i.op_str}")
