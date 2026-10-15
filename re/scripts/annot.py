import re,struct
d=open('image.bin','rb').read(); B=0x10000
def cstr(a):
    o=a-B
    if not(0<=o<len(d)): return None
    e=d.find(b'\0',o); s=d[o:e]
    return s.decode('latin1') if 2<=len(s)<80 and all(32<=c<127 or c in(9,10,13,36) for c in s) else None
def f32(a):
    o=a-B
    return struct.unpack_from('<f',d,o)[0] if 0<=o<len(d)-4 else None
def f64(a):
    o=a-B
    return struct.unpack_from('<d',d,o)[0] if 0<=o<len(d)-8 else None
out=[]
for l in open('asm.txt'):
    l=l.rstrip('\n')
    m=re.match(r'(\w+): (\w+) (.*)',l)
    if m:
        mn,ops=m.group(2),m.group(3)
        note=''
        for im in re.findall(r'0x([0-9a-f]{5})\b',ops):
            a=int(im,16)
            if 0x3d000<=a<0x50000:
                s=cstr(a)
                if s and mn in('mov','push','lea') : note=f'  ; "{s}"'
        mm=re.search(r'(fld|fmul|fadd|fsub|fsubr|fdiv|fdivr|fcomp|fcom|fild|fst|fstp) (dword|qword) ptr \[0x([0-9a-f]+)\]',l)
        if mm:
            a=int(mm.group(3),16); v=f32(a) if mm.group(2)=='dword' else f64(a)
            if v is not None and mm.group(1) not in('fst','fstp'): note=f'  ; ={v:.6g}'
        l=l+note
    out.append(l)
open('asm2.txt','w').write('\n'.join(out))
