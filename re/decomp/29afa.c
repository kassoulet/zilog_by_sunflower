
undefined8 FUN_00029afa(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar3;
  int extraout_ECX;
  undefined8 uVar4;
  undefined1 local_10;
  byte *pbVar2;
  
  if (*(int *)(param_1 + 0x20) != *(int *)(param_1 + 0x18) &&
      -1 < *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x18)) {
    uVar4 = (**(code **)(*(int *)(param_1 + 0x28) + 0x20))(param_1);
    param_1 = (int)((ulonglong)uVar4 >> 0x20);
    if ((int)uVar4 == -1) {
      uVar1 = 0xffffffff;
      goto LAB_00029b6c;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  iVar3 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  if (iVar3 == 0) {
    if ((iVar3 == 0) && ((*(uint *)(param_1 + 0x24) & 1) == 0)) {
      uVar4 = (**(code **)(*(int *)(param_1 + 0x28) + 0x28))(param_1);
      param_1 = (int)((ulonglong)uVar4 >> 0x20);
      if ((int)uVar4 == -1) {
        uVar1 = 0xffffffff;
        goto LAB_00029b6c;
      }
    }
    iVar3 = *(int *)(param_1 + 4);
    if (iVar3 != 0) {
LAB_00029b35:
      *(int *)(param_1 + 0xc) = iVar3;
      *(int *)(param_1 + 0x14) = iVar3 + 4;
      *(int *)(param_1 + 0x10) = iVar3 + 4;
      goto LAB_00029b41;
    }
    *(int *)(param_1 + 0x14) = param_1 + 0x34;
    *(int *)(param_1 + 0x10) = param_1 + 0x34;
    *(int *)(param_1 + 0xc) = param_1 + 0x30;
    uVar4 = FUN_00028d20(*(undefined4 *)(param_1 + 0x2c));
    iVar3 = (int)((ulonglong)uVar4 >> 0x20);
    uVar1 = (uint)uVar4;
    if (uVar1 == 0xffffffff) goto LAB_00029b6c;
    **(undefined1 **)(iVar3 + 0x10) = (char)uVar4;
    *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) + 1;
    pbVar2 = *(byte **)(iVar3 + 0x14);
  }
  else {
    if (*(uint *)(param_1 + 0x10) <= *(uint *)(param_1 + 0x14)) goto LAB_00029b35;
LAB_00029b41:
    if (*(int *)(param_1 + 8) == *(int *)(param_1 + 0x10) ||
        *(int *)(param_1 + 8) - *(int *)(param_1 + 0x10) < 0) {
      iVar3 = 0;
    }
    else {
      uVar4 = FUN_00028d20(*(undefined4 *)(param_1 + 0x2c));
      param_1 = (int)((ulonglong)uVar4 >> 0x20);
      uVar1 = (uint)uVar4;
      if (uVar1 == 0xffffffff) goto LAB_00029b6c;
      local_10 = (undefined1)uVar4;
      **(undefined1 **)(param_1 + 0x10) = local_10;
      iVar3 = extraout_ECX;
    }
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + iVar3;
    pbVar2 = *(byte **)(param_1 + 0x14);
    if (*(byte **)(param_1 + 0x10) <= pbVar2) {
      uVar1 = 0xffffffff;
      goto LAB_00029b6c;
    }
  }
  uVar1 = (uint)*pbVar2;
LAB_00029b6c:
  return CONCAT44(param_2,uVar1);
}

