
void FUN_00028d01(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  code *pcVar1;
  int iVar2;
  byte in_CF;
  
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)(CONCAT11(0x3f,(char)param_1),param_2,param_1,unaff_EBX);
  if ((in_CF & 1) != 0) {
    FUN_0002e6c3((iVar2 << 1 | (uint)in_CF) >> 1 & 0xffff);
  }
  return;
}

