
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00014f58(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  undefined2 extraout_ST0h;
  undefined2 extraout_ST0h_00;
  undefined2 extraout_ST0h_01;
  undefined2 extraout_ST0h_02;
  undefined2 extraout_ST0h_03;
  undefined2 extraout_ST0h_04;
  undefined1 local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  for (local_14 = 0; local_14 < 0x80; local_14 = local_14 + 1) {
    fVar1 = (float)/*c*/0.0078125;
    fVar2 = (float)/*c*/0.0039062;
    fVar3 = (float)/*c*/0.0078125;
    for (local_18 = 0; local_18 < 0x100; local_18 = local_18 + 1) {
      dVar4 = ftrunc(SUB108((longdouble)local_18 * (longdouble)((float)(0x80 - local_14) * fVar1),0)
                    );
      local_20 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar4));
      *(undefined1 *)((local_14 * 0x100 + local_18) * 4 + param_1) = local_20;
      dVar4 = ftrunc(SUB108((longdouble)local_18 * (longdouble)((float)local_14 * fVar2),0));
      local_20 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h_00,dVar4));
      *(undefined1 *)((local_14 * 0x100 + local_18) * 4 + param_1 + 1) = local_20;
      dVar4 = ftrunc(SUB108((longdouble)local_18 * (longdouble)((float)local_14 * fVar3),0));
      local_20 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h_01,dVar4));
      *(undefined1 *)((local_14 * 0x100 + local_18) * 4 + param_1 + 2) = local_20;
      *(undefined1 *)((local_14 * 0x100 + local_18) * 4 + param_1 + 3) = 0;
    }
  }
  for (local_14 = 0x80; local_14 < 0x100; local_14 = local_14 + 1) {
    fVar1 = (float)/*c*/0.0078125;
    fVar2 = (float)/*c*/0.0039062;
    fVar3 = (float)/*c*/0.0078125;
    for (local_18 = 0; local_18 < 0x100; local_18 = local_18 + 1) {
      dVar4 = ftrunc(SUB108((longdouble)local_18 * (longdouble)((float)(local_14 + -0x80) * fVar1),0
                           ));
      local_20 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h_02,dVar4));
      *(undefined1 *)((local_14 * 0x100 + local_18) * 4 + param_1) = local_20;
      dVar4 = ftrunc(SUB108((longdouble)local_18 * (longdouble)((float)local_14 * fVar2),0));
      local_20 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h_03,dVar4));
      *(undefined1 *)((local_14 * 0x100 + local_18) * 4 + param_1 + 1) = local_20;
      dVar4 = ftrunc(SUB108((longdouble)local_18 * (longdouble)((float)(0x100 - local_14) * fVar3),0
                           ));
      local_20 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h_04,dVar4));
      *(undefined1 *)((local_14 * 0x100 + local_18) * 4 + param_1 + 2) = local_20;
      *(undefined1 *)((local_14 * 0x100 + local_18) * 4 + param_1 + 3) = 0;
    }
  }
  return;
}

