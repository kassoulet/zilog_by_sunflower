
longlong FUN_00028c2f(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX,uint param_4)

{
  code *pcVar1;
  undefined4 extraout_ECX;
  byte in_CF;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(CONCAT11(0x3e,(char)param_1),param_2,param_1,param_1,param_4,unaff_EBX);
  if ((in_CF & 1) == 0) {
    FUN_0002e679(extraout_ECX,0);
    return (ulonglong)param_4 << 0x20;
  }
  FUN_000284cf(4);
  return CONCAT44(param_4,0xffffffff);
}

