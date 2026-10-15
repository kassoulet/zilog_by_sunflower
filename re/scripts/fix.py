import re,struct,os,glob
d=open('image.bin','rb').read(); B=0x10000
width={}
for l in open('asm.txt'):
    m=re.search(r'\b(f\w+) (dword|qword) ptr \[0x([0-9a-f]+)\]',l)
    if m and m.group(1) in('fld','fmul','fadd','fsub','fsubr','fdiv','fdivr','fcom','fcomp','fmulp','fimul'):
        a=int(m.group(3),16)
        if 0x3d000<=a<0x3f000: width[a]=m.group(2)
def lit(a):
    o=a-B
    if width.get(a)=='qword': v=struct.unpack_from('<d',d,o)[0]
    else: v=struct.unpack_from('<f',d,o)[0]
    return repr(round(v,7)) if v==v else 'nan'
os.makedirs('fn2',exist_ok=True)
for f in glob.glob('fn/*.c'):
    s=open(f).read()
    s=re.sub(r'\b_?DAT_0003([0-9a-f]{4})\b',lambda m: ('/*c*/'+lit(int('3'+m.group(1),16))) if int('3'+m.group(1),16) in width else m.group(0),s)
    open('fn2/'+os.path.basename(f),'w').write(s)
print(len(width))
