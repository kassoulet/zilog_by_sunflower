
void FUN_0002cf9c(void)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar2 = DAT_0004144c;
  piVar4 = DAT_00041440;
  if (DAT_0004144c < DAT_00041444) {
    piVar4 = DAT_0004144c + 3;
  }
  DAT_00041454 = (piVar4[1] + 0xffff >> 0x10) - (DAT_0004144c[1] + 0xffff >> 0x10);
  DAT_0004144c = piVar4;
  if (0 < DAT_00041454) {
    if (DAT_00041454 < 2) {
      iVar3 = (int)(0x40000000 / (longlong)(piVar4[1] - piVar2[1]));
      lVar1 = (longlong)(*piVar4 - *piVar2) * (longlong)iVar3;
      DAT_00041464 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
      lVar1 = (longlong)(piVar4[2] - piVar2[2]) * (longlong)iVar3;
      DAT_0004146c = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
    }
    else {
      DAT_00041464 = (uint)(CONCAT44(*piVar4 - *piVar2 >> 0x10,(*piVar4 - *piVar2) * 0x10000) /
                           (longlong)(piVar4[1] - piVar2[1]));
      DAT_0004146c = (uint)(CONCAT44(piVar4[2] - piVar2[2] >> 0x10,(piVar4[2] - piVar2[2]) * 0x10000
                                    ) / (longlong)(piVar4[1] - piVar2[1]));
    }
    iVar3 = (piVar2[1] + 0xffff >> 0x10) * 0x10000 - piVar2[1];
    lVar1 = (longlong)iVar3 * (longlong)(int)DAT_00041464;
    DAT_00041460 = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + *piVar2;
    lVar1 = (longlong)iVar3 * (longlong)(int)DAT_0004146c;
    DAT_00041468 = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + piVar2[2];
  }
  return;
}

