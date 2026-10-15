
undefined8 FUN_00025bec(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar2 = 0;
  DAT_0003f953 = param_1;
  do {
    uVar1 = 0;
    do {
      uVar3 = (ushort)uVar2 >> 4;
      if (uVar3 == 0xf) {
        uVar3 = 0xe;
      }
      *(ushort *)(param_1 + iVar4) = (ushort)uVar1 >> 4 | uVar3 << 4;
      iVar4 = iVar4 + 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < 0x100);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  uVar2 = 0;
  do {
    *(char *)(param_1 + 0x10000 + uVar2) = (char)((ushort)uVar2 >> 4) + -0x10;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  return CONCAT44(param_2,param_1);
}

