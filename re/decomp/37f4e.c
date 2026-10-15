
undefined2 FUN_00037f4e(undefined4 param_1,undefined2 param_2)

{
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined2 uVar1;
  undefined1 extraout_AH_01;
  undefined4 extraout_ECX;
  int iVar2;
  int extraout_ECX_00;
  undefined2 extraout_DX;
  undefined2 extraout_DX_00;
  undefined2 extraout_DX_01;
  undefined2 extraout_DX_02;
  undefined2 extraout_DX_03;
  undefined2 extraout_DX_04;
  
  FUN_00037d62(0,param_2,0x4c);
  FUN_00037ecb();
  FUN_00037ecb();
  FUN_00037d62(CONCAT11(extraout_AH,1),extraout_DX,0x4c);
  FUN_00037ecb();
  FUN_00037ecb();
  FUN_00037d62(CONCAT11(extraout_AH_00,0x1f),extraout_DX_00,0xe);
  iVar2 = 0x20;
  do {
    out(DAT_00036456 + 0x102,(char)iVar2 + -1);
    uVar1 = FUN_00037d62(3,DAT_00036456 + 0x102,0,iVar2);
    FUN_00037d62(uVar1,extraout_DX_01,0xd);
    FUN_00037d62(CONCAT11(extraout_AH_01,0x3f),extraout_DX_02,6);
    FUN_00037d7a(0x5000,extraout_DX_03,9);
    FUN_00037ecb();
    FUN_00037ecb();
    iVar2 = extraout_ECX_00 + -1;
  } while (iVar2 != 0);
  FUN_00037d62(3,extraout_DX_04,0x4c,extraout_ECX);
  FUN_00037ecb();
  out(DAT_00036456,8);
  return 8;
}

