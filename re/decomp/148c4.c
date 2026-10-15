
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000148c4(int param_1)

{
  double dVar1;
  undefined2 extraout_ST0h;
  undefined2 extraout_ST0h_00;
  undefined2 extraout_ST0h_01;
  undefined2 extraout_ST0h_02;
  undefined2 extraout_ST0h_03;
  undefined2 extraout_ST0h_04;
  undefined2 extraout_ST0h_05;
  undefined2 extraout_ST0h_06;
  undefined2 extraout_ST0h_07;
  undefined4 local_54;
  
  for (local_54 = 0; local_54 < 0x100; local_54 = local_54 + 1) {
    dVar1 = ftrunc(SUB108((longdouble)local_54 * (longdouble)/*c*/16777216.0 *
                          ((longdouble)1.402 * (longdouble)0.5 +
                          (longdouble)0.299 * (longdouble)0.0625),0));
    *(int *)(local_54 * 4 + param_1) = (int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar1));
    dVar1 = ftrunc(SUB108((longdouble)local_54 * (longdouble)/*c*/16777216.0 *
                          ((longdouble)1.402 * (longdouble)-0.41869 +
                          (longdouble)0.587 * (longdouble)0.0625),0));
    *(int *)(local_54 * 4 + param_1 + 0x400) =
         (int)ROUND((longdouble)CONCAT28(extraout_ST0h_00,dVar1));
    dVar1 = ftrunc(SUB108((longdouble)local_54 * (longdouble)/*c*/16777216.0 *
                          ((longdouble)1.402 * (longdouble)-0.08131 +
                          (longdouble)0.114 * (longdouble)0.0625),0));
    *(int *)(local_54 * 4 + param_1 + 0x800) =
         (int)ROUND((longdouble)CONCAT28(extraout_ST0h_01,dVar1));
    dVar1 = ftrunc(SUB108((longdouble)local_54 * (longdouble)/*c*/16777216.0 *
                          ((longdouble)-0.71414 * (longdouble)0.5 +
                          (longdouble)-0.34414 * (longdouble)-0.16874 +
                          (longdouble)0.299 * (longdouble)0.0625),0));
    *(int *)(local_54 * 4 + param_1 + 0xc00) =
         (int)ROUND((longdouble)CONCAT28(extraout_ST0h_02,dVar1));
    dVar1 = ftrunc(SUB108((longdouble)local_54 * (longdouble)/*c*/16777216.0 *
                          ((longdouble)-0.71414 * (longdouble)-0.41869 +
                          (longdouble)-0.34414 * (longdouble)-0.33126 +
                          (longdouble)0.587 * (longdouble)0.0625),0));
    *(int *)(local_54 * 4 + param_1 + 0x1000) =
         (int)ROUND((longdouble)CONCAT28(extraout_ST0h_03,dVar1));
    dVar1 = ftrunc(SUB108((longdouble)local_54 * (longdouble)/*c*/16777216.0 *
                          ((longdouble)-0.71414 * (longdouble)-0.08131 +
                          (longdouble)-0.34414 * (longdouble)0.5 +
                          (longdouble)0.114 * (longdouble)0.0625),0));
    *(int *)(local_54 * 4 + param_1 + 0x1400) =
         (int)ROUND((longdouble)CONCAT28(extraout_ST0h_04,dVar1));
    dVar1 = ftrunc(SUB108((longdouble)local_54 * (longdouble)/*c*/16777216.0 *
                          ((longdouble)1.772 * (longdouble)-0.16874 +
                          (longdouble)0.299 * (longdouble)0.0625),0));
    *(int *)(local_54 * 4 + param_1 + 0x1800) =
         (int)ROUND((longdouble)CONCAT28(extraout_ST0h_05,dVar1));
    dVar1 = ftrunc(SUB108((longdouble)local_54 * (longdouble)/*c*/16777216.0 *
                          ((longdouble)1.772 * (longdouble)-0.33126 +
                          (longdouble)0.587 * (longdouble)0.0625),0));
    *(int *)(local_54 * 4 + param_1 + 0x1c00) =
         (int)ROUND((longdouble)CONCAT28(extraout_ST0h_06,dVar1));
    dVar1 = ftrunc(SUB108((longdouble)local_54 * (longdouble)/*c*/16777216.0 *
                          ((longdouble)1.772 * (longdouble)0.5 +
                          (longdouble)0.114 * (longdouble)0.0625),0));
    *(int *)(local_54 * 4 + param_1 + 0x2000) =
         (int)ROUND((longdouble)CONCAT28(extraout_ST0h_07,dVar1));
  }
  return;
}

