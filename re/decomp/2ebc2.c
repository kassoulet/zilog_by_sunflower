
longlong FUN_0002ebc2(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  byte in_CF;
  uint unaff_retaddr;
  
  pcVar1 = (code *)swi(0x21);
  iVar2 = (*pcVar1)(CONCAT11(0x41,(char)param_1),param_1);
  if ((in_CF & 1) != 0) {
    uVar3 = FUN_0002e6c3((iVar2 << 1 | (uint)in_CF) >> 1 & 0xffff);
    return CONCAT44(unaff_retaddr,uVar3);
  }
  return (ulonglong)unaff_retaddr << 0x20;
}

