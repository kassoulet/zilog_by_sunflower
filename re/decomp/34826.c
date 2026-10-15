
longlong FUN_00034826(undefined4 param_1,uint param_2,char unaff_BL)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int unaff_ESI;
  
  if (((unaff_ESI != 0) && (unaff_BL != '\0')) &&
     (bVar1 = *(char *)(unaff_ESI + 0x3d) + unaff_BL + -1, bVar1 < 0x84)) {
    if ((*(byte *)(unaff_ESI + 0x39) & 8) == 0) {
      uVar3 = (uint)*(ushort *)(&DAT_00036eb2 + (uint)bVar1 * 2);
      uVar2 = (ushort)*(uint *)(unaff_ESI + 0x3e);
      if ((99 < uVar2) && (uVar2 != 0x20ab)) {
        uVar3 = (uint)(((ulonglong)uVar3 * 0x20ab) / (ulonglong)*(uint *)(unaff_ESI + 0x3e));
      }
    }
    else {
      uVar3 = ((uint)bVar1 * -0x40 + 0x2100) - *(int *)(unaff_ESI + 0x3e);
    }
    return CONCAT44(param_2,uVar3);
  }
  return (ulonglong)param_2 << 0x20;
}

