
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014639(int param_1)

{
  double dVar1;
  longdouble lVar2;
  undefined2 extraout_ST0h;
  undefined4 local_34;
  undefined1 local_30;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  for (local_1c = -0x80; local_1c < 0x80; local_1c = local_1c + 1) {
    for (local_28 = -0x80; local_28 < 0x80; local_28 = local_28 + 1) {
      local_34 = SQRT((float)local_1c * (float)/*c*/1.17 *
                      (float)local_1c * (float)/*c*/1.17 + (float)local_28 * (float)local_28);
      if (0x42fe0000 < (int)local_34) {
        local_34 = 127.0;
      }
      lVar2 = (longdouble)fcos((longdouble)local_34 / (longdouble)/*c*/40.4);
      dVar1 = ftrunc(SUB108((longdouble)
                            (float)(lVar2 * (longdouble)/*c*/0.5 + (longdouble)/*c*/0.5) *
                            (longdouble)/*c*/255.0,0));
      local_30 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar1));
      *(undefined1 *)(local_20 + param_1) = local_30;
      local_20 = local_20 + 1;
    }
  }
  return;
}

