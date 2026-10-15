
undefined8 FUN_000248e2(int *param_1,undefined4 param_2)

{
  int *extraout_EDX;
  int *extraout_EDX_00;
  
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 8) != 0) {
    FUN_000248a3();
    param_1 = extraout_EDX;
  }
  if ((*(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc) & 0x4000) != 0) {
    FUN_00024822(1);
    FUN_00028acc();
    FUN_00024822(2);
    FUN_00028acc();
    param_1 = extraout_EDX_00;
  }
  return CONCAT44(param_2,(uint)(*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x10) == 0));
}

