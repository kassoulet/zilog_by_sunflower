
void FUN_000185d4(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  int local_44;
  float local_3c;
  float local_38;
  float local_34;
  int local_2c;
  int local_1c;
  
  iVar2 = param_1[0xc];
  iVar3 = param_1[8];
  if (param_1[4] == 0) {
    iVar5 = thunk_FUN_00024c8f(*param_1 * 0xc);
    param_1[4] = iVar5;
  }
  iVar5 = param_1[4];
  local_1c = 0;
  for (local_2c = 0; local_2c < *param_1; local_2c = local_2c + 1) {
    local_3c = 0.0;
    local_38 = 0.0;
    local_34 = 0.0;
    local_44 = 0;
    while (local_44 != -1) {
      iVar1 = local_1c + 1;
      local_44 = *(int *)(local_1c * 4 + iVar2);
      local_1c = iVar1;
      if (local_44 != -1) {
        local_3c = local_3c + *(float *)(local_44 * 0xc + iVar3);
        local_38 = local_38 + *(float *)(local_44 * 0xc + iVar3 + 4);
        local_34 = local_34 + *(float *)(local_44 * 0xc + iVar3 + 8);
      }
    }
    fVar4 = 1.0 / SQRT(local_34 * local_34 + local_38 * local_38 + local_3c * local_3c);
    *(float *)(local_2c * 0xc + iVar5) = local_3c * fVar4;
    *(float *)(local_2c * 0xc + iVar5 + 4) = local_38 * fVar4;
    *(float *)(local_2c * 0xc + iVar5 + 8) = local_34 * fVar4;
  }
  return;
}

