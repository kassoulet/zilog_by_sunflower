
undefined6 FUN_000377bd(void)

{
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined4 uVar1;
  undefined4 extraout_ECX;
  int iVar2;
  int extraout_ECX_00;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 extraout_DX_01;
  undefined2 extraout_DX_02;
  undefined2 extraout_DX_03;
  undefined2 extraout_DX_04;
  undefined6 uVar3;
  
  uVar3 = FUN_00037796();
  uVar3 = FUN_000375a1(1,(short)((uint6)uVar3 >> 0x20),0x19);
  FUN_000375a1(0x1f,(short)((uint6)uVar3 >> 0x20),0xe);
  iVar2 = 0x20;
  do {
    out(DAT_00036456 + 0x102,(char)iVar2 + -1);
    uVar3 = FUN_000375a1(3,DAT_00036456 + 0x102,0,iVar2);
    uVar3 = FUN_000375a1((int)uVar3,(short)((uint6)uVar3 >> 0x20),0xd);
    FUN_000375a1(0x3f,(short)((uint6)uVar3 >> 0x20),6);
    uVar3 = FUN_000375b9(CONCAT22(extraout_var,0x5000),extraout_DX,9);
    FUN_000375a1(0x22,(short)((uint6)uVar3 >> 0x20),0x15);
    FUN_000375a1(0,extraout_DX_00,0x10);
    FUN_000375b9(CONCAT22(extraout_var_00,0xfd0),extraout_DX_01,0x13);
    FUN_000375b9(CONCAT22(extraout_var_01,0xfd0),extraout_DX_02,0x1c);
    FUN_000375b9(CONCAT22(extraout_var_02,0xfd0),extraout_DX_03,0xc);
    FUN_000375b9(CONCAT22(extraout_var_03,0xfd0),extraout_DX_04,0x1b);
    FUN_0003770a();
    uVar3 = FUN_0003770a();
    iVar2 = extraout_ECX_00 + -1;
  } while (iVar2 != 0);
  FUN_000375a1(3,(short)((uint6)uVar3 >> 0x20),0x4c,extraout_ECX);
  uVar1 = FUN_0003770a();
  out(DAT_00036456,8);
  return CONCAT24(DAT_00036456,CONCAT31((int3)((uint)uVar1 >> 8),8));
}

