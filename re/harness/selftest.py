# smoke test: run the demo's own LZW decoder (0x24568) and the box-blur-table builder
import sys; sys.path.insert(0,'.')
from orig import Orig
o=Orig()
tab=o.alloc(0x10100)
o.w32(0x16b38,tab)                       # DAT_00016b38: table memory for widths >= 0x40
r=o.call(0x16b44,eax=100)               # build /100 division table
print('table ptr', hex(o.r32(0x16b40)), 'tab[250]=',o.read(tab+250,1)[0], 'tab[100]=',o.read(tab+100,1)[0], 'expected 2 and 1')
