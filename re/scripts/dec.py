# Jython: create functions from funcs.txt, decompile all to out.c
from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor
import os
S='/tmp/claude-1000/-home-gautier-SynologyDrive-code-current-demos-zilog/30d78e4d-6a5d-45da-a815-458c6cbb7835/scratchpad/'
af=currentProgram.getAddressFactory().getDefaultAddressSpace()
fm=currentProgram.getFunctionManager()
for l in open(S+'funcs.txt'):
    a=af.getAddress(int(l.strip(),16))
    disassemble(a)
    if fm.getFunctionAt(a) is None: createFunction(a,'func_%x'%a.getOffset())
from ghidra.program.model.listing import ParameterImpl, Function
from ghidra.program.model.data import DoubleDataType
from ghidra.program.model.symbol import SourceType
f=fm.getFunctionAt(af.getAddress(0x1c472))
ST0=currentProgram.getRegister('ST0')
f.setName('ftrunc',SourceType.USER_DEFINED)
f.updateFunction(None,ParameterImpl('r',DoubleDataType.dataType,ST0,currentProgram),[ParameterImpl('x',DoubleDataType.dataType,ST0,currentProgram)],Function.FunctionUpdateType.CUSTOM_STORAGE,True,SourceType.USER_DEFINED)
di=DecompInterface(); di.openProgram(currentProgram)
mon=ConsoleTaskMonitor()
out=open(S+'out.c','w')
for f in fm.getFunctions(True):
    r=di.decompileFunction(f,60,mon)
    if r.decompileCompleted():
        c=r.getDecompiledFunction().getC(); out.write(c+'\n'); open(S+'fn/%x.c'%f.getEntryPoint().getOffset(),'w').write(c)
    else: out.write('// FAILED %s\n'%f.getName())
out.close()
