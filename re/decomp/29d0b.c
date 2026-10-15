
undefined4 FUN_00029d0b(int param_1,uint param_2,undefined4 unaff_EBX,undefined4 param_4)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  uint extraout_EDX;
  
  if ((param_2 & 4) != 0) {
    FUN_00029cea(param_1,&DAT_0003ecd0,unaff_EBX,param_1,param_4);
    thunk_FUN_00023831();
    return extraout_ECX_00;
  }
  *(undefined ***)(param_1 + 0x28) = &PTR_FUN_0003ecc4;
  FUN_0002f13b();
  if ((extraout_EDX & 2) == 0) {
    return extraout_ECX;
  }
  FUN_00023831(extraout_ECX);
  return extraout_ECX_01;
}

