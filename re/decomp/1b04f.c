
void FUN_0001b04f(int *param_1,int param_2,int unaff_EBX)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int local_1c;
  
  if (param_1[0x12] == 0) {
    iVar3 = thunk_FUN_00024c8f(*param_1 << 3);
    param_1[0x12] = iVar3;
  }
  local_2c = *(float *)param_1[1];
  local_24 = *(float *)(param_1[1] + 4);
  local_28 = local_2c;
  local_20 = local_24;
  for (local_1c = 0; local_1c < *param_1; local_1c = local_1c + 1) {
    fVar1 = *(float *)(param_1[1] + local_1c * 0xc);
    fVar2 = *(float *)(param_1[1] + local_1c * 0xc + 4);
    if (fVar1 < local_2c) {
      local_2c = fVar1;
    }
    if (local_28 < fVar1) {
      local_28 = fVar1;
    }
    if (fVar2 < local_24) {
      local_24 = fVar2;
    }
    if (local_20 < fVar2) {
      local_20 = fVar2;
    }
  }
  for (local_1c = 0; local_1c < *param_1; local_1c = local_1c + 1) {
    *(float *)(param_1[0x12] + local_1c * 8) =
         (*(float *)(param_1[1] + local_1c * 0xc) - local_2c) *
         ((float)param_2 / (local_28 - local_2c));
    *(float *)(param_1[0x12] + local_1c * 8 + 4) =
         (float)unaff_EBX -
         (*(float *)(param_1[1] + local_1c * 0xc + 4) - local_24) *
         ((float)unaff_EBX / (local_20 - local_24));
  }
  return;
}

