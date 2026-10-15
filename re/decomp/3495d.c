
void FUN_0003495d(uint param_1)

{
  uint uVar1;
  int unaff_EBP;
  
  if ((&DAT_000368b2)[unaff_EBP] == 0) {
    return;
  }
  if ((*(byte *)((&DAT_000368b2)[unaff_EBP] + 0x39) & 8) == 0) {
    if (param_1 < 0xb) {
      return;
    }
    uVar1 = (uint)(0xda7790 / (ulonglong)param_1);
  }
  else {
    uVar1 = FUN_00034911(0x2100 - param_1);
    uVar1 = (uint)((ulonglong)uVar1 * 0x20ab) >> 0x14 |
            (int)((ulonglong)uVar1 * 0x20ab >> 0x20) << 0xc;
  }
  (&DAT_00036672)[unaff_EBP] = uVar1;
  return;
}

