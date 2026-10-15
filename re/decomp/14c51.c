
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014c51(int param_1)

{
  double dVar1;
  longdouble lVar2;
  longdouble lVar3;
  undefined2 extraout_ST0h;
  undefined1 local_30;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  for (local_1c = 0; local_1c < 0x100; local_1c = local_1c + 1) {
    for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
      lVar2 = (longdouble)
              fcos((longdouble)local_28 * (longdouble)/*c*/3.1415927 * (longdouble)/*c*/0.0078125 +
                   (longdouble)/*c*/3.1415927);
      lVar3 = (longdouble)
              fcos((longdouble)local_1c * (longdouble)/*c*/3.1415927 * (longdouble)/*c*/0.0078125 +
                   (longdouble)/*c*/3.1415927);
      dVar1 = ftrunc(SUB108(((longdouble)1 + lVar3) *
                            (longdouble)
                            (double)(((longdouble)1 + lVar2) * (longdouble)/*c*/56.0) +
                            (longdouble)/*c*/16.0,0));
      local_30 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar1));
      *(undefined1 *)(local_20 + param_1) = local_30;
      local_20 = local_20 + 1;
    }
  }
  return;
}

