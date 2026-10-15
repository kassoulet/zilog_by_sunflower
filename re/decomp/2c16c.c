
void FUN_0002c16c(void)

{
  longlong lVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar2 = DAT_00041360;
  piVar3 = DAT_00041354;
  if (DAT_00041360 < DAT_00041358) {
    piVar3 = DAT_00041360 + 6;
  }
  DAT_00041368 = (piVar3[1] + 0xffff >> 0x10) - (DAT_00041360[1] + 0xffff >> 0x10);
  DAT_00041360 = piVar3;
  if (0 < DAT_00041368) {
    if (DAT_00041368 < 2) {
      iVar4 = (int)(0x40000000 / (longlong)(piVar3[1] - piVar2[1]));
      lVar1 = (longlong)(*piVar3 - *piVar2) * (longlong)iVar4;
      DAT_00041378 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
      lVar1 = (longlong)(piVar3[2] - piVar2[2]) * (longlong)iVar4;
      DAT_00041384 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
      lVar1 = (longlong)(piVar3[3] - piVar2[3]) * (longlong)iVar4;
      DAT_00041394 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
      lVar1 = (longlong)(piVar3[4] - piVar2[4]) * (longlong)iVar4;
      DAT_00041388 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
      lVar1 = (longlong)(piVar3[5] - piVar2[5]) * (longlong)iVar4;
      DAT_00041398 = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
    }
    else {
      iVar4 = piVar3[1] - piVar2[1];
      DAT_00041378 = (uint)(CONCAT44(*piVar3 - *piVar2 >> 0x10,(*piVar3 - *piVar2) * 0x10000) /
                           (longlong)iVar4);
      DAT_00041384 = (uint)(CONCAT44(piVar3[2] - piVar2[2] >> 0x10,(piVar3[2] - piVar2[2]) * 0x10000
                                    ) / (longlong)iVar4);
      DAT_00041394 = (uint)(CONCAT44(piVar3[3] - piVar2[3] >> 0x10,(piVar3[3] - piVar2[3]) * 0x10000
                                    ) / (longlong)iVar4);
      DAT_00041388 = (uint)(CONCAT44(piVar3[4] - piVar2[4] >> 0x10,(piVar3[4] - piVar2[4]) * 0x10000
                                    ) / (longlong)iVar4);
      DAT_00041398 = (uint)(CONCAT44(piVar3[5] - piVar2[5] >> 0x10,(piVar3[5] - piVar2[5]) * 0x10000
                                    ) / (longlong)iVar4);
    }
    iVar4 = (piVar2[1] + 0xffff >> 0x10) * 0x10000 - piVar2[1];
    DAT_00041374 = ((uint)((longlong)iVar4 * (longlong)(int)DAT_00041378) >> 0x10 |
                   (int)((ulonglong)((longlong)iVar4 * (longlong)(int)DAT_00041378) >> 0x20) << 0x10
                   ) + *piVar2;
    DAT_0004137c = ((uint)((longlong)iVar4 * (longlong)(int)DAT_00041384) >> 0x10 |
                   (int)((ulonglong)((longlong)iVar4 * (longlong)(int)DAT_00041384) >> 0x20) << 0x10
                   ) + piVar2[2];
    DAT_0004138c = ((uint)((longlong)iVar4 * (longlong)(int)DAT_00041394) >> 0x10 |
                   (int)((ulonglong)((longlong)iVar4 * (longlong)(int)DAT_00041394) >> 0x20) << 0x10
                   ) + piVar2[3];
    DAT_00041380 = ((uint)((longlong)iVar4 * (longlong)(int)DAT_00041388) >> 0x10 |
                   (int)((ulonglong)((longlong)iVar4 * (longlong)(int)DAT_00041388) >> 0x20) << 0x10
                   ) + piVar2[4];
    DAT_00041390 = ((uint)((longlong)iVar4 * (longlong)(int)DAT_00041398) >> 0x10 |
                   (int)((ulonglong)((longlong)iVar4 * (longlong)(int)DAT_00041398) >> 0x20) << 0x10
                   ) + piVar2[5];
  }
  return;
}

