
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_0001bf97(int param_1,int param_2,int unaff_EBX,undefined4 param_4,float param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_30;
  float local_2c;
  float local_28;
  float local_24;
  int local_20;
  int local_1c;
  int local_18;
  
  iVar5 = unaff_EBX * param_1 * param_2;
  iVar4 = unaff_EBX * (param_1 + -1) * param_2 + (param_2 + -1) * param_1 * unaff_EBX +
          (unaff_EBX + -1) * param_1 * param_2;
  iVar1 = thunk_FUN_00024c8f(iVar5 * 0xc);
  iVar2 = thunk_FUN_00024c8f(iVar4 * 8);
  local_30 = 0;
  for (local_24 = (float)-unaff_EBX * param_5 * /*c*/0.5;
      local_24 < (float)unaff_EBX * param_5 * /*c*/0.5; local_24 = local_24 + param_5) {
    for (local_28 = (float)-param_2 * param_5 * /*c*/0.5;
        local_28 < (float)param_2 * param_5 * /*c*/0.5; local_28 = local_28 + param_5) {
      for (local_2c = (float)-param_1 * param_5 * /*c*/0.5;
          local_2c < (float)param_1 * param_5 * /*c*/0.5; local_2c = local_2c + param_5) {
        *(float *)(local_30 * 0xc + iVar1) = local_2c;
        *(float *)(local_30 * 0xc + iVar1 + 4) = local_28;
        *(float *)(iVar1 + local_30 * 0xc + 8) = local_24;
        local_30 = local_30 + 1;
      }
    }
  }
  local_30 = 0;
  for (local_18 = 0; local_18 < unaff_EBX; local_18 = local_18 + 1) {
    for (local_1c = 0; local_1c < param_2; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < param_1 + -1; local_20 = local_20 + 1) {
        *(int *)(local_30 * 8 + iVar2) =
             local_1c * param_1 + local_20 + local_18 * param_1 * param_2;
        *(int *)(local_30 * 8 + iVar2 + 4) =
             local_1c * param_1 + local_20 + local_18 * param_1 * param_2 + 1;
        local_30 = local_30 + 1;
      }
    }
  }
  for (local_18 = 0; local_18 < unaff_EBX; local_18 = local_18 + 1) {
    for (local_1c = 0; local_1c < param_2 + -1; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < param_1; local_20 = local_20 + 1) {
        *(int *)(local_30 * 8 + iVar2) =
             local_18 * param_1 * param_2 + local_1c * param_1 + local_20;
        *(int *)(local_30 * 8 + iVar2 + 4) =
             local_20 + (local_1c + 1) * param_1 + local_18 * param_1 * param_2;
        local_30 = local_30 + 1;
      }
    }
  }
  for (local_18 = 0; local_18 < unaff_EBX + -1; local_18 = local_18 + 1) {
    for (local_1c = 0; local_1c < param_2; local_1c = local_1c + 1) {
      for (local_20 = 0; local_20 < param_1; local_20 = local_20 + 1) {
        *(int *)(local_30 * 8 + iVar2) =
             local_18 * param_1 * param_2 + local_1c * param_1 + local_20;
        *(int *)(local_30 * 8 + iVar2 + 4) =
             param_2 * (local_18 + 1) * param_1 + local_1c * param_1 + local_20;
        local_30 = local_30 + 1;
      }
    }
  }
  piVar3 = (int *)FUN_00024c8f(0x54);
  *piVar3 = iVar5;
  piVar3[1] = iVar1;
  iVar1 = thunk_FUN_00024c8f(iVar5 * 0xc);
  piVar3[2] = iVar1;
  piVar3[0x10] = iVar2;
  piVar3[0xf] = iVar4;
  iVar1 = thunk_FUN_00024c8f(iVar5 * 8);
  piVar3[0x11] = iVar1;
  piVar3[3] = 0;
  piVar3[0x14] = 0;
  piVar3[0x12] = 0;
  return piVar3;
}

