
undefined8 FUN_00028775(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  int extraout_EDX_00;
  uint uVar5;
  int extraout_EDX_01;
  byte bVar6;
  undefined4 uStack_14;
  
  uVar3 = FUN_0002e624();
  FUN_0002e679(param_1,uVar3 | 0x40);
  bVar6 = 0;
  if ((uVar3 & 0x2000) == 0) {
LAB_000287d0:
    uVar4 = 0;
  }
  else {
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)(CONCAT22(extraout_var,0x4400),extraout_EDX,param_1);
    bVar2 = (bVar6 & 1) != 0;
    uVar3 = (extraout_EDX_00 << 1 | (uint)bVar6) >> 1;
    uVar5 = uVar3 | (uint)bVar2 << 0x1f;
    uStack_14 = uVar5;
    if (!bVar2) {
      uStack_14._0_1_ = (byte)uVar3;
      bVar6 = 0;
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(CONCAT22(extraout_var_00,0x4401),
                CONCAT22((short)(uVar5 >> 0x10),(ushort)((byte)uStack_14 | 0x20)),param_1);
      uStack_14 = (extraout_EDX_01 << 1 | (uint)bVar6) >> 1;
      if ((bVar6 & 1) == 0) goto LAB_000287d0;
    }
    uVar4 = FUN_0002e6c3(uStack_14 & 0xffff);
  }
  return CONCAT44(param_2,uVar4);
}

