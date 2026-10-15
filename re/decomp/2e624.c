
longlong FUN_0002e624(uint param_1,uint param_2)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  if (DAT_0003fd1c <= param_1) {
    return (ulonglong)param_2 << 0x20;
  }
  if ((int)param_1 < 5) {
    iVar4 = param_1 * 4;
    iVar3 = DAT_0003fd70 + iVar4;
    bVar2 = *(byte *)(iVar3 + 1);
    if ((bVar2 & 0x40) == 0) {
      *(byte *)(iVar3 + 1) = bVar2 | 0x40;
      uVar5 = FUN_0002e69a(param_1);
      param_1 = (uint)((ulonglong)uVar5 >> 0x20);
      if ((int)uVar5 != 0) {
        pbVar1 = (byte *)(iVar4 + 1 + DAT_0003fd70);
        *pbVar1 = *pbVar1 | 0x20;
      }
    }
  }
  return CONCAT44(param_2,*(undefined4 *)(DAT_0003fd70 + param_1 * 4));
}

