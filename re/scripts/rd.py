# recursive descent over image.bin -> asm.txt ; functions.txt (call graph, sizes)
from capstone import *
from capstone.x86 import *
import re,collections
d=open('image.bin','rb').read(); B=0x10000; END=B+len(d)
md=Cs(CS_ARCH_X86,CS_MODE_32); md.detail=True
entry=0x2383c
funcs={entry}; work=[entry]; seen={}
# also seed with every aligned "push ebx; push ecx; push edx; push esi; push edi; push ebp; mov ebp,esp" Watcom-style prologue? just use calls.
pro=re.compile(rb'\x53\x51\x52\x56\x57\x55\x89\xe5')
for m in pro.finditer(d): funcs.add(m.start()+B); work.append(m.start()+B)
callers=collections.defaultdict(set)
def run(a):
    while B<=a<END and a not in seen:
        ins=list(md.disasm(d[a-B:a-B+16],a,1))
        if not ins: return
        i=ins[0]; seen[a]=i; a+=i.size
        m=i.mnemonic
        if m=='call' and i.operands[0].type==X86_OP_IMM:
            t=i.operands[0].imm
            callers[t].add(i.address)
            if t not in funcs and B<=t<END: funcs.add(t); work.append(t)
        elif m=='jmp' or m.startswith('j'):
            if i.operands and i.operands[0].type==X86_OP_IMM:
                t=i.operands[0].imm
                if B<=t<END and t not in seen: work.append(t)
            if m=='jmp': return
        elif m in('ret','retf','iret','hlt'): return
while work: run(work.pop())
addrs=sorted(seen)
with open('asm.txt','w') as f:
    prev=None
    for a in addrs:
        if prev is not None and a!=prev: f.write('\n')
        if a in funcs: f.write(f'\n; ===== func_{a:x} (callers: {len(callers[a])}) =====\n')
        i=seen[a]; f.write(f'{a:x}: {i.mnemonic} {i.op_str}\n'); prev=a+i.size
print(len(funcs),'funcs',len(seen),'insns', hex(addrs[0]),hex(addrs[-1]))
