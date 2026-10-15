
void FUN_000340ba(byte param_1)

{
  int iVar1;
  
  if (0x80 < param_1) {
    param_1 = 0x80;
  }
  iVar1 = 0;
  DAT_0003646d = param_1;
  do {
    (&DAT_00036472)[iVar1] = (&DAT_00036472)[iVar1] | 0x40;
    iVar1 = iVar1 + 1;
  } while (iVar1 != DAT_0003646e);
  return;
}

