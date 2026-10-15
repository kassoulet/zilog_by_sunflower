
void FUN_00027847(undefined4 param_1,int param_2,undefined4 unaff_EBX,undefined4 param_4)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  
  if (param_2 < 0x1001) {
    if (param_2 < -0x1000) {
      FUN_000277c6(param_1,0xfffff000,param_2,param_1,param_4,unaff_EBX);
      param_2 = param_2 + 0x1000;
      param_1 = extraout_ECX_00;
    }
  }
  else {
    FUN_000277c6(param_1,0x1000,param_2,param_1,param_4,unaff_EBX);
    param_2 = param_2 + -0x1000;
    param_1 = extraout_ECX;
  }
  FUN_000277c6(param_1,param_2);
  return;
}

