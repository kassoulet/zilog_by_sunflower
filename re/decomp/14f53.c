
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_14f53(int param_1)

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
  undefined1 uStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  for (uStack_28 = 0; uStack_28 < 0x80; uStack_28 = uStack_28 + 1) {
    fVar1 = (float)/*c*/0.0078125;
    fVar2 = (float)/*c*/0.0039062;
    fVar3 = (float)/*c*/0.0078125;
    for (uStack_2c = 0; uStack_2c < 0x100; uStack_2c = uStack_2c + 1) {
      dVar4 = ftrunc(SUB108((longdouble)uStack_2c * (longdouble)((float)(0x80 - uStack_28) * fVar1),
                            0));
      uStack_34 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar4));
      *(undefined1 *)((uStack_28 * 0x100 + uStack_2c) * 4 + param_1) = uStack_34;
      dVar4 = ftrunc(SUB108((longdouble)uStack_2c * (longdouble)((float)uStack_28 * fVar2),0));
      uStack_34 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h_00,dVar4));
      *(undefined1 *)((uStack_28 * 0x100 + uStack_2c) * 4 + param_1 + 1) = uStack_34;
      dVar4 = ftrunc(SUB108((longdouble)uStack_2c * (longdouble)((float)uStack_28 * fVar3),0));
      uStack_34 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h_01,dVar4));
      *(undefined1 *)((uStack_28 * 0x100 + uStack_2c) * 4 + param_1 + 2) = uStack_34;
      *(undefined1 *)((uStack_28 * 0x100 + uStack_2c) * 4 + param_1 + 3) = 0;
    }
  }
  for (uStack_28 = 0x80; uStack_28 < 0x100; uStack_28 = uStack_28 + 1) {
    fVar1 = (float)/*c*/0.0078125;
    fVar2 = (float)/*c*/0.0039062;
    fVar3 = (float)/*c*/0.0078125;
    for (uStack_2c = 0; uStack_2c < 0x100; uStack_2c = uStack_2c + 1) {
      dVar4 = ftrunc(SUB108((longdouble)uStack_2c * (longdouble)((float)(uStack_28 + -0x80) * fVar1)
                            ,0));
      uStack_34 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h_02,dVar4));
      *(undefined1 *)((uStack_28 * 0x100 + uStack_2c) * 4 + param_1) = uStack_34;
      dVar4 = ftrunc(SUB108((longdouble)uStack_2c * (longdouble)((float)uStack_28 * fVar2),0));
      uStack_34 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h_03,dVar4));
      *(undefined1 *)((uStack_28 * 0x100 + uStack_2c) * 4 + param_1 + 1) = uStack_34;
      dVar4 = ftrunc(SUB108((longdouble)uStack_2c * (longdouble)((float)(0x100 - uStack_28) * fVar3)
                            ,0));
      uStack_34 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h_04,dVar4));
      *(undefined1 *)((uStack_28 * 0x100 + uStack_2c) * 4 + param_1 + 2) = uStack_34;
      *(undefined1 *)((uStack_28 * 0x100 + uStack_2c) * 4 + param_1 + 3) = 0;
    }
  }
  return;
}

