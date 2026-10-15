
void func_188e7(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  double dVar6;
  undefined2 extraout_ST0h;
  undefined4 uStack_20;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    uVar5 = thunk_FUN_00024c8f(*(int *)(param_1 + 0x18) << 2);
    *(undefined4 *)(param_1 + 0x24) = uVar5;
  }
  iVar1 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(param_1 + 0x24);
  iVar3 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0x1c);
  for (uStack_20 = 0; uStack_20 < iVar1; uStack_20 = uStack_20 + 1) {
    dVar6 = ftrunc(SUB108((longdouble)
                          *(float *)(*(int *)(uStack_20 * 0xc + iVar4) * 0xc + iVar3 + 8) +
                          (longdouble)
                          *(float *)(*(int *)(uStack_20 * 0xc + iVar4 + 4) * 0xc + iVar3 + 8) +
                          (longdouble)
                          *(float *)(*(int *)(uStack_20 * 0xc + iVar4 + 8) * 0xc + iVar3 + 8),0));
    *(int *)(uStack_20 * 4 + iVar2) = (int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar6));
  }
  return;
}

