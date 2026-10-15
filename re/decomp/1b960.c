
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __regparm2 FUN_0001b960(int param_1,int param_2,float param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_2c;
  float local_28;
  float local_24;
  int local_20;
  int local_1c;
  
  iVar1 = param_1 * param_2;
  iVar5 = param_2 * (param_1 + -1) + (param_2 + -1) * param_1;
  iVar2 = thunk_FUN_00024c8f(iVar1 * 0xc);
  iVar3 = thunk_FUN_00024c8f(iVar5 * 8);
  local_2c = 0;
  for (local_24 = (float)-param_2 * param_3 * /*c*/0.5;
      local_24 < (float)param_2 * param_3 * /*c*/0.5; local_24 = local_24 + param_3) {
    for (local_28 = (float)-param_1 * param_3 * /*c*/0.5;
        local_28 < (float)param_1 * param_3 * /*c*/0.5; local_28 = local_28 + param_3) {
      *(float *)(local_2c * 0xc + iVar2) = local_28;
      *(float *)(local_2c * 0xc + iVar2 + 4) = local_24;
      *(undefined4 *)(local_2c * 0xc + iVar2 + 8) = 0xc2480000;
      local_2c = local_2c + 1;
    }
  }
  local_2c = 0;
  for (local_1c = 0; local_1c < param_2; local_1c = local_1c + 1) {
    for (local_20 = 0; local_20 < param_1 + -1; local_20 = local_20 + 1) {
      *(int *)(local_2c * 8 + iVar3) = local_1c * param_1 + local_20;
      *(int *)(local_2c * 8 + iVar3 + 4) = local_1c * param_1 + local_20 + 1;
      local_2c = local_2c + 1;
    }
  }
  for (local_1c = 0; local_1c < param_2 + -1; local_1c = local_1c + 1) {
    for (local_20 = 0; local_20 < param_1; local_20 = local_20 + 1) {
      *(int *)(local_2c * 8 + iVar3) = local_1c * param_1 + local_20;
      *(int *)(local_2c * 8 + iVar3 + 4) = local_20 + (local_1c + 1) * param_1;
      local_2c = local_2c + 1;
    }
  }
  piVar4 = (int *)FUN_00024c8f(0x54);
  *piVar4 = iVar1;
  piVar4[1] = iVar2;
  iVar2 = thunk_FUN_00024c8f(iVar1 * 0xc);
  piVar4[2] = iVar2;
  piVar4[0x10] = iVar3;
  piVar4[0xf] = iVar5;
  iVar1 = thunk_FUN_00024c8f(iVar1 * 8);
  piVar4[0x11] = iVar1;
  piVar4[3] = 0;
  piVar4[0x14] = 0;
  piVar4[0x12] = 0;
  return piVar4;
}

