
undefined8 FUN_0001b854(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  undefined2 extraout_ST0h;
  undefined2 extraout_ST0h_00;
  undefined2 extraout_ST0h_01;
  undefined2 extraout_ST0h_02;
  int local_3c;
  int local_38;
  
  iVar2 = *param_1 >> 1;
  iVar3 = thunk_FUN_00024c8f(iVar2 << 2);
  for (local_3c = 0; local_3c < iVar2; local_3c = local_3c + 1) {
    *(undefined4 *)(local_3c * 4 + iVar3) = 0;
  }
  iVar1 = param_1[1];
  for (local_3c = 0; local_38 = iVar2, local_3c < iVar2; local_3c = local_3c + 1) {
    for (; local_38 < iVar2 * 2; local_38 = local_38 + 1) {
      dVar4 = ftrunc(SUB108((longdouble)*(float *)(local_3c * 0xc + iVar1),0));
      dVar5 = ftrunc(SUB108((longdouble)*(float *)(local_38 * 0xc + iVar1),0));
      dVar6 = ftrunc(SUB108((longdouble)*(float *)(local_3c * 0xc + iVar1 + 4),0));
      dVar7 = ftrunc(SUB108((longdouble)*(float *)(local_38 * 0xc + iVar1 + 4),0));
      if (((int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar4)) ==
           (int)ROUND((longdouble)CONCAT28(extraout_ST0h_00,dVar5))) &&
         ((int)ROUND((longdouble)CONCAT28(extraout_ST0h_01,dVar6)) ==
          (int)ROUND((longdouble)CONCAT28(extraout_ST0h_02,dVar7)))) {
        *(int *)(local_3c * 4 + iVar3) = local_38;
      }
    }
  }
  return CONCAT44(param_2,iVar3);
}

