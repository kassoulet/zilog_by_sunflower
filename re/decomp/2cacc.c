
void FUN_0002cacc(void)

{
  longlong lVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar2 = DAT_00041400;
  piVar3 = DAT_000413f4;
  if (DAT_00041400 < DAT_000413f8) {
    piVar3 = DAT_00041400 + 4;
  }
  DAT_00041408 = (piVar3[1] + 0xffff >> 0x10) - (DAT_00041400[1] + 0xffff >> 0x10);
  DAT_00041400 = piVar3;
  if (0 < DAT_00041408) {
    if (DAT_00041408 < 2) {
      iVar4 = (int)(0x40000000 / (longlong)(piVar3[1] - piVar2[1]));
      lVar1 = (longlong)(*piVar3 - *piVar2) * (longlong)iVar4;
      DAT_00041418 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
      lVar1 = (longlong)(piVar3[2] - piVar2[2]) * (longlong)iVar4;
      DAT_00041420 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
      lVar1 = (longlong)(piVar3[3] - piVar2[3]) * (longlong)iVar4;
      DAT_00041428 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
    }
    else {
      iVar4 = piVar3[1] - piVar2[1];
      DAT_00041418 = (uint)(CONCAT44(*piVar3 - *piVar2 >> 0x10,(*piVar3 - *piVar2) * 0x10000) /
                           (longlong)iVar4);
      DAT_00041420 = (uint)(CONCAT44(piVar3[2] - piVar2[2] >> 0x10,(piVar3[2] - piVar2[2]) * 0x10000
                                    ) / (longlong)iVar4);
      DAT_00041428 = (uint)(CONCAT44(piVar3[3] - piVar2[3] >> 0x10,(piVar3[3] - piVar2[3]) * 0x10000
                                    ) / (longlong)iVar4);
    }
    iVar4 = (piVar2[1] + 0xffff >> 0x10) * 0x10000 - piVar2[1];
    DAT_00041414 = ((uint)((longlong)iVar4 * (longlong)(int)DAT_00041418) >> 0x10 |
                   (int)((ulonglong)((longlong)iVar4 * (longlong)(int)DAT_00041418) >> 0x20) << 0x10
                   ) + *piVar2;
    DAT_0004141c = ((uint)((longlong)iVar4 * (longlong)(int)DAT_00041420) >> 0x10 |
                   (int)((ulonglong)((longlong)iVar4 * (longlong)(int)DAT_00041420) >> 0x20) << 0x10
                   ) + piVar2[2];
    DAT_00041424 = ((uint)((longlong)iVar4 * (longlong)(int)DAT_00041428) >> 0x10 |
                   (int)((ulonglong)((longlong)iVar4 * (longlong)(int)DAT_00041428) >> 0x20) << 0x10
                   ) + piVar2[3];
  }
  return;
}

