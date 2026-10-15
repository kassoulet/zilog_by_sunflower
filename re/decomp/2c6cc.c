
void FUN_0002c6cc(void)

{
  longlong lVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar2 = DAT_000413bc;
  piVar4 = DAT_000413b0;
  if (DAT_000413bc < DAT_000413b4) {
    piVar4 = DAT_000413bc + 4;
  }
  DAT_000413c4 = (piVar4[1] + 0xffff >> 0x10) - (DAT_000413bc[1] + 0xffff >> 0x10);
  DAT_000413bc = piVar4;
  if (0 < DAT_000413c4) {
    if (DAT_000413c4 < 2) {
      iVar3 = (int)(0x40000000 / (longlong)(piVar4[1] - piVar2[1]));
      lVar1 = (longlong)(*piVar4 - *piVar2) * (longlong)iVar3;
      DAT_000413d4 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
      lVar1 = (longlong)(piVar4[2] - piVar2[2]) * (longlong)iVar3;
      DAT_000413dc = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
    }
    else {
      DAT_000413d4 = (uint)(CONCAT44(*piVar4 - *piVar2 >> 0x10,(*piVar4 - *piVar2) * 0x10000) /
                           (longlong)(piVar4[1] - piVar2[1]));
      DAT_000413dc = (uint)(CONCAT44(piVar4[2] - piVar2[2] >> 0x10,(piVar4[2] - piVar2[2]) * 0x10000
                                    ) / (longlong)(piVar4[1] - piVar2[1]));
    }
    iVar3 = (piVar2[1] + 0xffff >> 0x10) * 0x10000 - piVar2[1];
    lVar1 = (longlong)iVar3 * (longlong)(int)DAT_000413d4;
    DAT_000413d0 = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + *piVar2;
    lVar1 = (longlong)iVar3 * (longlong)(int)DAT_000413dc;
    DAT_000413d8 = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + piVar2[2];
  }
  return;
}

