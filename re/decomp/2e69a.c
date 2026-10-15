
undefined8
FUN_0002e69a(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX,undefined4 param_4)

{
  code *pcVar1;
  uint extraout_EDX;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(0x4400,param_2,param_1,param_4,param_4,unaff_EBX);
  return CONCAT44(param_4,(uint)((extraout_EDX & 0x80) != 0));
}

