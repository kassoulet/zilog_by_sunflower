
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001b1b4(int *param_1)

{
  float fVar1;
  int iVar2;
  float local_28;
  float local_24;
  int local_20;
  
  if (param_1[0x12] == 0) {
    iVar2 = thunk_FUN_00024c8f(*param_1 << 3);
    param_1[0x12] = iVar2;
  }
  local_28 = *(float *)(param_1[1] + 8);
  local_24 = local_28;
  for (local_20 = 0; local_20 < *param_1; local_20 = local_20 + 1) {
    fVar1 = *(float *)(param_1[1] + local_20 * 0xc + 8);
    if (fVar1 < local_28) {
      local_28 = fVar1;
    }
    if (local_24 < fVar1) {
      local_24 = fVar1;
    }
  }
  fVar1 = /*c*/254.0 / (local_24 - local_28);
  for (local_20 = 0; local_20 < *param_1; local_20 = local_20 + 1) {
    *(float *)(param_1[0x12] + local_20 * 8) =
         (*(float *)(param_1[1] + local_20 * 0xc + 8) - local_28) * fVar1 + 1.0;
  }
  return;
}

