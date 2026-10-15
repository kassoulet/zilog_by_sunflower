
undefined4 FUN_0002f4b5(int param_1,undefined1 *param_2,int unaff_EBX,undefined4 param_4)

{
  undefined4 extraout_ECX;
  undefined1 *puVar1;
  
  puVar1 = param_2;
  if ((unaff_EBX == 10) && (param_1 < 0)) {
    param_1 = -param_1;
    *param_2 = 0x2d;
    puVar1 = param_2 + 1;
  }
  FUN_0002f46c(param_1,puVar1,unaff_EBX,param_2,param_4);
  return extraout_ECX;
}

