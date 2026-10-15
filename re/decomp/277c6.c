
uint FUN_000277c6(uint param_1,int param_2)

{
  longdouble *extraout_ECX;
  longdouble *extraout_ECX_00;
  ushort in_FPUControlWord;
  uint local_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined2 uStack_18;
  
  if (param_2 != 0) {
    local_24 = (uint)in_FPUControlWord;
    uStack_18 = 0x3fff;
    local_20 = 0;
    uStack_1c = 0x80000000;
    if (param_2 < 0) {
      FUN_00027769(&local_20,-param_2,0x80000000,param_1);
      *extraout_ECX = *extraout_ECX / (longdouble)CONCAT28(uStack_18,CONCAT44(uStack_1c,local_20));
      param_1 = local_24;
    }
    else {
      FUN_00027769(&local_20,param_2,0x80000000,param_1);
      *extraout_ECX_00 =
           (longdouble)CONCAT28(uStack_18,CONCAT44(uStack_1c,local_20)) * *extraout_ECX_00;
      param_1 = local_24;
    }
  }
  return param_1;
}

