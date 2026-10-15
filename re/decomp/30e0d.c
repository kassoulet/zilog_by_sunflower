
undefined8 FUN_00030e0d(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  byte extraout_DL;
  undefined1 extraout_DH;
  uint extraout_EDX;
  undefined1 local_10;
  undefined1 local_f;
  byte local_c [4];
  undefined4 uStack_8;
  
  uStack_8 = param_2;
  FUN_00030ea2(param_1,local_c);
  iVar1 = FUN_000308a5(local_c,extraout_EDX & 0xffffff00);
  local_c[iVar1] = extraout_DL;
  if (((DAT_0003ff10 == 0x3a4) && (DAT_00041490 != 0)) && (((&DAT_00041495)[local_c[0]] & 1) != 0))
  {
    param_1 = FUN_000311d3(param_1);
  }
  else if ((DAT_00041490 == 0) || (((&DAT_00041495)[local_c[0]] & 1) == 0)) {
    local_10 = FUN_0002f5bd(local_c[0]);
    local_f = extraout_DH;
    param_1 = FUN_00030dd2(&local_10);
  }
  return CONCAT44(uStack_8,param_1);
}

