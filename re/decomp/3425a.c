
uint FUN_0003425a(uint param_1)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = (&DAT_000368b2)[unaff_EBP];
  if (iVar1 == 0) {
    return param_1;
  }
  if ((*(byte *)(iVar1 + 0x39) & 4) == 0) {
    if ((*(byte *)(iVar1 + 0x39) & 2) == 0) {
      return param_1;
    }
    param_1 = (uint)*(byte *)(iVar1 + 0x3c);
  }
  return param_1;
}

