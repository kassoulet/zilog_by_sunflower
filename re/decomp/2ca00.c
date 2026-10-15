
void FUN_0002ca00(void)

{
  longlong lVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = DAT_000413fc;
  piVar3 = DAT_000413f8;
  if (DAT_000413f4 < DAT_000413fc) {
    piVar3 = DAT_000413fc + -4;
  }
  DAT_00041404 = (piVar3[1] + 0xffff >> 0x10) - (DAT_000413fc[1] + 0xffff >> 0x10);
  DAT_000413fc = piVar3;
  if (0 < DAT_00041404) {
    if (DAT_00041404 < 2) {
      lVar1 = (longlong)(*piVar3 - *piVar2) *
              (longlong)(int)(0x40000000 / (longlong)(piVar3[1] - piVar2[1]));
      DAT_00041410 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
    }
    else {
      DAT_00041410 = (uint)(CONCAT44(*piVar3 - *piVar2 >> 0x10,(*piVar3 - *piVar2) * 0x10000) /
                           (longlong)(piVar3[1] - piVar2[1]));
    }
    lVar1 = (longlong)((piVar2[1] + 0xffff >> 0x10) * 0x10000 - piVar2[1]) *
            (longlong)(int)DAT_00041410;
    DAT_0004140c = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + *piVar2;
  }
  return;
}

