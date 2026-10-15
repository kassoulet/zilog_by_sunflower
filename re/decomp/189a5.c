
void FUN_000189a5(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  double dVar9;
  undefined2 extraout_ST0h;
  undefined4 local_2c;
  
  iVar1 = *(int *)(param_1 + 0x44);
  iVar2 = *(int *)(param_1 + 0x1c);
  iVar3 = *(int *)(param_1 + 0x4c);
  iVar4 = *(int *)(param_1 + 0x18);
  for (local_2c = 0; local_2c < iVar4; local_2c = local_2c + 1) {
    iVar5 = *(int *)(local_2c * 0xc + iVar2);
    iVar6 = *(int *)(local_2c * 0xc + iVar2 + 4);
    fVar7 = *(float *)(iVar6 * 8 + iVar1);
    fVar8 = *(float *)(iVar6 * 8 + iVar1 + 4);
    iVar6 = *(int *)(local_2c * 0xc + iVar2 + 8);
    dVar9 = ftrunc(SUB108(((longdouble)*(float *)(iVar5 * 8 + iVar1) - (longdouble)fVar7) *
                          ((longdouble)*(float *)(iVar6 * 8 + iVar1 + 4) - (longdouble)fVar8) -
                          ((longdouble)*(float *)(iVar6 * 8 + iVar1) - (longdouble)fVar7) *
                          ((longdouble)*(float *)(iVar5 * 8 + iVar1 + 4) - (longdouble)fVar8),0));
    *(int *)(local_2c * 4 + iVar3) = (int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar9));
  }
  return;
}

