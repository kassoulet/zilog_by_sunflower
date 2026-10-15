
/* WARNING: Removing unreachable block (ram,0x000240ae) */

undefined4 FUN_0002402d(undefined4 *param_1,int param_2,uint unaff_EBX)

{
  int iVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar3;
  int extraout_ECX_02;
  int extraout_ECX_03;
  undefined4 extraout_ECX_04;
  
  if ((*(byte *)(param_1 + 3) & 6) != 0) {
    if ((*(byte *)((int)param_1 + 0xd) & 0x10) == 0) {
      if (unaff_EBX == 1) {
        param_2 = param_2 - param_1[1];
      }
      uVar3 = *(undefined4 *)(param_1[2] + 8);
      param_1[1] = 0;
      *param_1 = uVar3;
    }
    else {
      iVar1 = FUN_00028acc(param_1);
      param_1 = extraout_ECX;
      if (iVar1 != 0) {
        if (unaff_EBX != 0) {
          return 0xffffffff;
        }
        if (-1 < param_2) {
          return 0xffffffff;
        }
        goto LAB_00024053;
      }
    }
    *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xeb;
    iVar1 = FUN_00028bca(param_1[4],param_2);
    if (iVar1 != -1) {
      return 0;
    }
    return 0xffffffff;
  }
  if (unaff_EBX == 0) {
    iVar1 = FUN_00028c69(param_1[4]);
    iVar1 = FUN_00023fd8(param_2 - (iVar1 - *(int *)(extraout_ECX_02 + 4)),extraout_ECX_02);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = FUN_00028bca(*(undefined4 *)(extraout_ECX_03 + 0x10),param_2);
    uVar3 = extraout_ECX_04;
    if (iVar1 == -1) {
      return 0xffffffff;
    }
  }
  else {
    if (1 < unaff_EBX) {
      if (unaff_EBX == 2) {
        *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xef;
        *param_1 = *(undefined4 *)(param_1[2] + 8);
        param_1[1] = 0;
        iVar1 = FUN_00028bca(param_1[4],param_2);
        if (iVar1 != -1) {
          return 0;
        }
        return 0xffffffff;
      }
LAB_00024053:
      FUN_000284cf(9);
      return 0xffffffff;
    }
    iVar1 = param_1[1];
    iVar2 = FUN_00023fd8(param_2,param_1);
    if (iVar2 == 0) {
      return 0;
    }
    iVar1 = FUN_00028bca(*(undefined4 *)(extraout_ECX_00 + 0x10),param_2 - iVar1);
    uVar3 = extraout_ECX_01;
    if (iVar1 == -1) {
      return 0xffffffff;
    }
  }
  FUN_00024017(uVar3);
  return 0;
}

