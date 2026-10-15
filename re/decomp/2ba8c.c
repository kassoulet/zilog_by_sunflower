
void FUN_0002ba8c(void)

{
  longlong lVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar2 = DAT_0004131c;
  piVar3 = DAT_00041310;
  if (DAT_0004131c < DAT_00041314) {
    piVar3 = DAT_0004131c + 4;
  }
  DAT_00041324 = (piVar3[1] + 0xffff >> 0x10) - (DAT_0004131c[1] + 0xffff >> 0x10);
  DAT_0004131c = piVar3;
  if (0 < DAT_00041324) {
    if (DAT_00041324 < 2) {
      iVar4 = (int)(0x40000000 / (longlong)(piVar3[1] - piVar2[1]));
      lVar1 = (longlong)(*piVar3 - *piVar2) * (longlong)iVar4;
      DAT_00041334 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
      lVar1 = (longlong)(piVar3[2] - piVar2[2]) * (longlong)iVar4;
      DAT_0004133c = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
      lVar1 = (longlong)(piVar3[3] - piVar2[3]) * (longlong)iVar4;
      DAT_00041344 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
    }
    else {
      iVar4 = piVar3[1] - piVar2[1];
      DAT_00041334 = (uint)(CONCAT44(*piVar3 - *piVar2 >> 0x10,(*piVar3 - *piVar2) * 0x10000) /
                           (longlong)iVar4);
      DAT_0004133c = (uint)(CONCAT44(piVar3[2] - piVar2[2] >> 0x10,(piVar3[2] - piVar2[2]) * 0x10000
                                    ) / (longlong)iVar4);
      DAT_00041344 = (uint)(CONCAT44(piVar3[3] - piVar2[3] >> 0x10,(piVar3[3] - piVar2[3]) * 0x10000
                                    ) / (longlong)iVar4);
    }
    iVar4 = (piVar2[1] + 0xffff >> 0x10) * 0x10000 - piVar2[1];
    DAT_00041330 = ((uint)((longlong)iVar4 * (longlong)(int)DAT_00041334) >> 0x10 |
                   (int)((ulonglong)((longlong)iVar4 * (longlong)(int)DAT_00041334) >> 0x20) << 0x10
                   ) + *piVar2;
    DAT_00041338 = ((uint)((longlong)iVar4 * (longlong)(int)DAT_0004133c) >> 0x10 |
                   (int)((ulonglong)((longlong)iVar4 * (longlong)(int)DAT_0004133c) >> 0x20) << 0x10
                   ) + piVar2[2];
    DAT_00041340 = ((uint)((longlong)iVar4 * (longlong)(int)DAT_00041344) >> 0x10 |
                   (int)((ulonglong)((longlong)iVar4 * (longlong)(int)DAT_00041344) >> 0x20) << 0x10
                   ) + piVar2[3];
  }
  return;
}

