
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_1b354(int *param_1)

{
  float fVar1;
  int iVar2;
  float fStack_28;
  float fStack_24;
  int iStack_20;
  
  if (param_1[0x12] == 0) {
    iVar2 = thunk_FUN_00024c8f(*param_1 << 3);
    param_1[0x12] = iVar2;
  }
  fStack_28 = *(float *)(param_1[1] + 8);
  fStack_24 = fStack_28;
  for (iStack_20 = 0; iStack_20 < *param_1; iStack_20 = iStack_20 + 1) {
    fVar1 = *(float *)(param_1[1] + iStack_20 * 0xc + 8);
    if (fVar1 < fStack_28) {
      fStack_28 = fVar1;
    }
    if (fStack_24 < fVar1) {
      fStack_24 = fVar1;
    }
  }
  fVar1 = /*c*/254.0 / (fStack_24 - fStack_28);
  for (iStack_20 = 0; iStack_20 < *param_1; iStack_20 = iStack_20 + 1) {
    *(float *)(param_1[0x12] + iStack_20 * 8) =
         /*c*/256.0 - ((*(float *)(param_1[1] + iStack_20 * 0xc + 8) - fStack_28) * fVar1 + 1.0);
  }
  return;
}

