
void FUN_000160a9(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 *local_58;
  int local_3c;
  int local_38;
  int local_28;
  int local_24;
  int local_20;
  
  local_24 = param_1[0xc];
  if (local_24 == 0) {
    local_24 = thunk_FUN_00024c8f((*param_1 + param_1[6] * 3) * 4);
  }
  local_20 = param_1[0xd];
  if (local_20 == 0) {
    local_20 = thunk_FUN_00024c8f(*param_1 << 2);
  }
  iVar3 = thunk_FUN_00024c8f(*param_1 << 2);
  for (local_3c = 0; local_3c < *param_1; local_3c = local_3c + 1) {
    *(undefined4 *)(local_3c * 4 + iVar3) = 0;
  }
  for (local_3c = 0; local_3c < param_1[6]; local_3c = local_3c + 1) {
    iVar1 = *(int *)(param_1[7] + local_3c * 0xc);
    piVar4 = (int *)FUN_00024c8f(8);
    piVar4[1] = *(int *)(iVar1 * 4 + iVar3);
    *piVar4 = local_3c;
    *(int **)(iVar1 * 4 + iVar3) = piVar4;
    iVar1 = *(int *)(local_3c * 0xc + param_1[7] + 4);
    piVar4 = (int *)FUN_00024c8f(8);
    piVar4[1] = *(int *)(iVar1 * 4 + iVar3);
    *piVar4 = local_3c;
    *(int **)(iVar1 * 4 + iVar3) = piVar4;
    iVar1 = *(int *)(local_3c * 0xc + param_1[7] + 8);
    piVar4 = (int *)FUN_00024c8f(8);
    piVar4[1] = *(int *)(iVar1 * 4 + iVar3);
    *piVar4 = local_3c;
    *(int **)(iVar1 * 4 + iVar3) = piVar4;
  }
  local_38 = 0;
  local_28 = 0;
  for (local_3c = 0; local_3c < *param_1; local_3c = local_3c + 1) {
    *(int *)(local_28 * 4 + local_20) = local_38;
    local_58 = *(undefined4 **)(local_3c * 4 + iVar3);
    while (local_58 != (undefined4 *)0x0) {
      *(undefined4 *)(local_38 * 4 + local_24) = *local_58;
      puVar2 = (undefined4 *)local_58[1];
      FUN_00023831(local_58);
      local_58 = puVar2;
      local_38 = local_38 + 1;
    }
    *(undefined4 *)(local_38 * 4 + local_24) = 0xffffffff;
    local_38 = local_38 + 1;
    local_28 = local_28 + 1;
  }
  thunk_FUN_00023831(iVar3);
  param_1[0xc] = local_24;
  param_1[0xd] = local_20;
  return;
}

