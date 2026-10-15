
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001b359(int *param_1)

{
  float fVar1;
  int iVar2;
  float local_14;
  float local_10;
  int local_c;
  
  if (param_1[0x12] == 0) {
    iVar2 = thunk_FUN_00024c8f(*param_1 << 3);
    param_1[0x12] = iVar2;
  }
  local_14 = *(float *)(param_1[1] + 8);
  local_10 = local_14;
  for (local_c = 0; local_c < *param_1; local_c = local_c + 1) {
    fVar1 = *(float *)(param_1[1] + local_c * 0xc + 8);
    if (fVar1 < local_14) {
      local_14 = fVar1;
    }
    if (local_10 < fVar1) {
      local_10 = fVar1;
    }
  }
  fVar1 = /*c*/254.0 / (local_10 - local_14);
  for (local_c = 0; local_c < *param_1; local_c = local_c + 1) {
    *(float *)(param_1[0x12] + local_c * 8) =
         /*c*/256.0 - ((*(float *)(param_1[1] + local_c * 0xc + 8) - local_14) * fVar1 + 1.0);
  }
  return;
}

