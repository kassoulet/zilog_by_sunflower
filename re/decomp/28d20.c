
undefined8 FUN_00028d20(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 *extraout_EDX;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = *(int *)(param_1[2] + 0xc);
  if (iVar2 != 1) {
    if (iVar2 != 0) {
      uVar1 = 0xffffffff;
      goto LAB_00028dc2;
    }
    *(undefined4 *)(param_1[2] + 0xc) = 1;
  }
  if ((*(byte *)(param_1 + 3) & 1) == 0) {
    FUN_000284cf(4);
    uVar1 = 0xffffffff;
    *(byte *)(extraout_EDX + 3) = *(byte *)(extraout_EDX + 3) | 0x20;
    param_1 = extraout_EDX;
  }
  else {
    iVar2 = param_1[1];
    param_1[1] = iVar2 + -1;
    if (iVar2 + -1 < 0) {
      uVar3 = FUN_00028dc8(param_1);
      param_1 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
      uVar1 = (uint)uVar3;
    }
    else {
      uVar1 = (uint)*(byte *)*param_1;
      *param_1 = (byte *)*param_1 + 1;
    }
  }
  uVar3 = CONCAT44(param_1,uVar1);
  if ((*(byte *)(param_1 + 3) & 0x40) == 0) {
    if (uVar1 == 0xd) {
      iVar2 = param_1[1];
      param_1[1] = iVar2 + -1;
      if (iVar2 + -1 < 0) {
        uVar3 = FUN_00028dc8(param_1);
      }
      else {
        uVar3 = CONCAT44(param_1,(uint)*(byte *)*param_1);
        *param_1 = (byte *)*param_1 + 1;
      }
    }
    iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    uVar1 = (uint)uVar3;
    if (uVar1 == 0x1a) {
      uVar1 = 0xffffffff;
      *(byte *)(iVar2 + 0xc) = *(byte *)(iVar2 + 0xc) | 0x10;
    }
  }
LAB_00028dc2:
  return CONCAT44(param_2,uVar1);
}

