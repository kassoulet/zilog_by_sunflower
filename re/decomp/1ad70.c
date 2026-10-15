
void func_1ad70(int *param_1)

{
  int iVar1;
  int iStack_28;
  int iStack_20;
  int iStack_1c;
  
  FUN_00027390();
  for (iStack_20 = 0; iStack_20 < *param_1; iStack_20 = iStack_20 + 1) {
    FUN_00027390();
  }
  FUN_00027390();
  for (iStack_20 = 0; iStack_20 < param_1[6]; iStack_20 = iStack_20 + 1) {
    FUN_00027390();
  }
  FUN_00027390();
  for (iStack_20 = 0; iStack_20 < param_1[0xf]; iStack_20 = iStack_20 + 1) {
    FUN_00027390();
  }
  FUN_00027390();
  iStack_1c = 0;
  for (iStack_20 = 0; iStack_20 < *param_1; iStack_20 = iStack_20 + 1) {
    FUN_00027390();
    iStack_28 = 0;
    while (iStack_28 != -1) {
      iVar1 = iStack_1c + 1;
      iStack_28 = *(int *)(param_1[0xc] + iStack_1c * 4);
      iStack_1c = iVar1;
      if (iStack_28 != -1) {
        FUN_00027390();
      }
    }
    FUN_00027390();
  }
  FUN_00027390();
  for (iStack_20 = 0; iStack_20 < param_1[0xf]; iStack_20 = iStack_20 + 1) {
    FUN_00027390();
  }
  return;
}

