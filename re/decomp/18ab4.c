
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00018ab4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  double dVar8;
  undefined2 extraout_ST0h;
  undefined4 local_40;
  undefined4 local_24;
  undefined4 local_1c;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    uVar7 = thunk_FUN_00024c8f(*(int *)(param_1 + 0x18) << 2);
    *(undefined4 *)(param_1 + 0x24) = uVar7;
  }
  if (*(int *)(param_1 + 0x28) == 0) {
    uVar7 = thunk_FUN_00024c8f(*(int *)(param_1 + 0x18) << 2);
    *(undefined4 *)(param_1 + 0x28) = uVar7;
  }
  iVar1 = *(int *)(param_1 + 0x4c);
  iVar2 = *(int *)(param_1 + 0x24);
  iVar3 = *(int *)(param_1 + 0x28);
  iVar4 = *(int *)(param_1 + 0x18);
  iVar5 = *(int *)(param_1 + 8);
  iVar6 = *(int *)(param_1 + 0x1c);
  local_1c = 0;
  for (local_24 = 0; local_24 < iVar4; local_24 = local_24 + 1) {
    if (*(int *)(local_24 * 4 + iVar1) < 0) {
      dVar8 = ftrunc(SUB108(((longdouble)
                             *(float *)(*(int *)(local_24 * 0xc + iVar6) * 0xc + iVar5 + 8) +
                             (longdouble)
                             *(float *)(*(int *)(local_24 * 0xc + iVar6 + 4) * 0xc + iVar5 + 8) +
                            (longdouble)
                            *(float *)(*(int *)(local_24 * 0xc + iVar6 + 8) * 0xc + iVar5 + 8)) *
                            (longdouble)/*c*/100.0,0));
      *(int *)(local_1c * 4 + iVar2) = (int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar8));
      *(int *)(iVar3 + local_1c * 4) = local_24;
      local_1c = local_1c + 1;
    }
  }
  *(int *)(param_1 + 0x2c) = local_1c;
  FUN_00025f04();
  return CONCAT44(param_2,local_40);
}

