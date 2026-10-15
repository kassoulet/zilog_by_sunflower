
void FUN_0002c600(void)

{
  longlong lVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = DAT_000413b8;
  piVar3 = DAT_000413b4;
  if (DAT_000413b0 < DAT_000413b8) {
    piVar3 = DAT_000413b8 + -4;
  }
  DAT_000413c0 = (piVar3[1] + 0xffff >> 0x10) - (DAT_000413b8[1] + 0xffff >> 0x10);
  DAT_000413b8 = piVar3;
  if (0 < DAT_000413c0) {
    if (DAT_000413c0 < 2) {
      lVar1 = (longlong)(*piVar3 - *piVar2) *
              (longlong)(int)(0x40000000 / (longlong)(piVar3[1] - piVar2[1]));
      DAT_000413cc = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
    }
    else {
      DAT_000413cc = (uint)(CONCAT44(*piVar3 - *piVar2 >> 0x10,(*piVar3 - *piVar2) * 0x10000) /
                           (longlong)(piVar3[1] - piVar2[1]));
    }
    lVar1 = (longlong)((piVar2[1] + 0xffff >> 0x10) * 0x10000 - piVar2[1]) *
            (longlong)(int)DAT_000413cc;
    DAT_000413c8 = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + *piVar2;
  }
  return;
}

