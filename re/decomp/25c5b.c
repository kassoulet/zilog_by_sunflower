
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00025c5b(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  _DAT_0003f957 = param_1;
  do {
    uVar1 = 0;
    do {
      *(byte *)(param_1 + iVar3) = (byte)((ushort)uVar1 >> 3) | (byte)(((ushort)uVar2 >> 2) << 5);
      iVar3 = iVar3 + 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x100);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  uVar2 = 0;
  do {
    uVar1 = 0;
    do {
      *(byte *)(param_1 + iVar3) = (byte)((ushort)uVar1 >> 5) | (byte)uVar2 & 0xf8;
      iVar3 = iVar3 + 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x100);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  return CONCAT44(param_2,param_1);
}

