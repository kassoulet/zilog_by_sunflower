
void FUN_00029d46(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined2 in_DS;
  
  iVar1 = FUN_0002f150(param_1,in_DS,param_1,param_2,param_4,unaff_EBX);
  if (iVar1 != 0) {
    FUN_0001780d(extraout_ECX);
    return;
  }
  thunk_FUN_00023acd(param_1,extraout_ECX);
  return;
}

