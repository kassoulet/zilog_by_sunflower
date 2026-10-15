
void FUN_000340e3(byte param_1)

{
  int unaff_EBP;
  
  if (0x40 < param_1) {
    param_1 = 0x40;
  }
  (&DAT_00036772)[unaff_EBP] = param_1;
  (&DAT_00036472)[unaff_EBP] = (&DAT_00036472)[unaff_EBP] | 0x40;
  return;
}

