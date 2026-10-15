
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00015168(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  undefined2 extraout_ST0h;
  undefined2 extraout_ST0h_00;
  undefined2 extraout_ST0h_01;
  undefined1 local_38;
  undefined4 local_28;
  undefined4 local_24;
  
  for (local_24 = 0; local_24 < 0x100; local_24 = local_24 + 1) {
    bVar1 = *(byte *)(local_24 * 3 + param_2 + 2);
    fVar4 = (float)/*c*/0.015625;
    bVar2 = *(byte *)(local_24 * 3 + param_2 + 1);
    fVar5 = (float)/*c*/0.015625;
    bVar3 = *(byte *)(local_24 * 3 + param_2);
    fVar6 = (float)/*c*/0.015625;
    for (local_28 = 0; local_28 < 0x100; local_28 = local_28 + 1) {
      dVar7 = ftrunc(SUB108((longdouble)local_28 * (longdouble)((float)bVar1 * fVar4),0));
      local_38 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar7));
      *(undefined1 *)((local_24 * 0x100 + local_28) * 4 + param_1) = local_38;
      dVar7 = ftrunc(SUB108((longdouble)local_28 * (longdouble)((float)bVar2 * fVar5),0));
      local_38 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h_00,dVar7));
      *(undefined1 *)((local_24 * 0x100 + local_28) * 4 + param_1 + 1) = local_38;
      dVar7 = ftrunc(SUB108((longdouble)local_28 * (longdouble)((float)bVar3 * fVar6),0));
      local_38 = (undefined1)(int)ROUND((longdouble)CONCAT28(extraout_ST0h_01,dVar7));
      *(undefined1 *)((local_24 * 0x100 + local_28) * 4 + param_1 + 2) = local_38;
      *(undefined1 *)((local_24 * 0x100 + local_28) * 4 + param_1 + 3) = 0;
    }
  }
  return;
}

