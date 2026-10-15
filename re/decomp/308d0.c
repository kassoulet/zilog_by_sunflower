
undefined8 __regparm3 FUN_000308d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined1 extraout_DL;
  uint extraout_EDX;
  undefined1 auStack_10 [4];
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  while( true ) {
    iVar1 = FUN_0003062b(param_1);
    if (iVar1 != 0) break;
    FUN_00030dd2(param_1,auStack_10);
    FUN_00030e0d();
    FUN_00030ea2();
    iVar1 = FUN_000308a5(auStack_10,extraout_EDX & 0xffffff00);
    auStack_10[iVar1] = extraout_DL;
    FUN_00030874(param_1,auStack_10);
    param_1 = FUN_000306be(param_1);
  }
  return CONCAT44(uStack_c,extraout_ECX);
}

