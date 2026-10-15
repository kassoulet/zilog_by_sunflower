
void FUN_0002b9c0(void)

{
  longlong lVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = DAT_00041318;
  piVar3 = DAT_00041314;
  if (DAT_00041310 < DAT_00041318) {
    piVar3 = DAT_00041318 + -4;
  }
  DAT_00041320 = (piVar3[1] + 0xffff >> 0x10) - (DAT_00041318[1] + 0xffff >> 0x10);
  DAT_00041318 = piVar3;
  if (0 < DAT_00041320) {
    if (DAT_00041320 < 2) {
      lVar1 = (longlong)(*piVar3 - *piVar2) *
              (longlong)(int)(0x40000000 / (longlong)(piVar3[1] - piVar2[1]));
      DAT_0004132c = (uint)lVar1 >> 0xe | (int)((ulonglong)lVar1 >> 0x20) << 0x12;
    }
    else {
      DAT_0004132c = (uint)(CONCAT44(*piVar3 - *piVar2 >> 0x10,(*piVar3 - *piVar2) * 0x10000) /
                           (longlong)(piVar3[1] - piVar2[1]));
    }
    lVar1 = (longlong)((piVar2[1] + 0xffff >> 0x10) * 0x10000 - piVar2[1]) *
            (longlong)(int)DAT_0004132c;
    DAT_00041328 = ((uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10) + *piVar2;
  }
  return;
}

