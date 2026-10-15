
uint FUN_00034911(uint param_1)

{
  longlong lVar1;
  
  lVar1 = (ulonglong)
          ((uint)((ulonglong)*(uint *)(&DAT_00034901 + (param_1 >> 0xc & 3) * 4) *
                 (ulonglong)*(uint *)(&DAT_000348c1 + (param_1 >> 8 & 0xf) * 4)) >> 0xf |
          (int)((ulonglong)*(uint *)(&DAT_00034901 + (param_1 >> 0xc & 3) * 4) *
                (ulonglong)*(uint *)(&DAT_000348c1 + (param_1 >> 8 & 0xf) * 4) >> 0x20) << 0x11) *
          (ulonglong)*(ushort *)(&DAT_000348a1 + (param_1 >> 4 & 0xf) * 2);
  lVar1 = (ulonglong)((uint)lVar1 >> 0xf | (int)((ulonglong)lVar1 >> 0x20) << 0x11) *
          (ulonglong)*(ushort *)(&DAT_00034881 + (param_1 & 0xf) * 2);
  return (uint)lVar1 >> 0xf | (int)((ulonglong)lVar1 >> 0x20) << 0x11;
}

