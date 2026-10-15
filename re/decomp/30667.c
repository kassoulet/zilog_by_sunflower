
void __regparm3 FUN_00030667(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined1 extraout_DL;
  undefined1 extraout_DH;
  uint extraout_EDX;
  undefined1 auStack_10 [4];
  undefined1 local_c [4];
  undefined4 uStack_8;
  
  uStack_8 = param_3;
  FUN_00030874(auStack_10,param_1,param_1,param_2);
  iVar1 = FUN_000308a5(param_1,extraout_EDX & 0xffffff00);
  auStack_10[iVar1] = extraout_DL;
  FUN_00030874(local_c,extraout_ECX);
  iVar1 = FUN_000308a5(extraout_ECX_00);
  local_c[iVar1] = extraout_DH;
  FUN_000308d0(auStack_10);
  FUN_000308d0(local_c,local_c);
  FUN_0003091f(auStack_10);
  return;
}

