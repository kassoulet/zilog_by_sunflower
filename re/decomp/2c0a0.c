
void FUN_0002c0a0(void)

{
  longlong lVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = DAT_0004135c;
  piVar3 = DAT_00041358;
  if (DAT_00041354 < DAT_0004135c) {
    piVar3 = DAT_0004135c + -6;
  }
  DAT_00041364 = (piVar3[1] + 0xffff >> 0x10) - (DAT_0004135c[1] + 0xffff >> 0x10);
  DAT_0004135c = piVar3;
  if (0 < DAT_00041364) {
    if (DAT_00041364 < 2) {
      lVar1 = (longlong)(*piVar3 - *piVar2) *
              (longlong)(int)(0x40000000 / (longlong)(piVar3[1] - piVar2[1]));
      DAT_00041370 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
    }
    else {
      DAT_00041370 = (uint)(CONCAT44(*piVar3 - *piVar2 >> 0x10,(*piVar3 - *piVar2) * 0x10000) /
                           (longlong)(piVar3[1] - piVar2[1]));
    }
    lVar1 = (longlong)((piVar2[1] + 0xffff >> 0x10) * 0x10000 - piVar2[1]) *
            (longlong)(int)DAT_00041370;
    DAT_0004136c = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + *piVar2;
  }
  return;
}

