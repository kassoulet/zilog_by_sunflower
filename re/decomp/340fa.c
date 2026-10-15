
void FUN_000340fa(uint param_1,undefined4 param_2,uint unaff_EBX)

{
  int iVar1;
  int unaff_EBP;
  bool bVar2;
  
  (&DAT_00036472)[unaff_EBP] = (&DAT_00036472)[unaff_EBP] | 4;
  if (unaff_EBX == 0) {
    return;
  }
  if (0x78 < unaff_EBX) {
    return;
  }
  if (DAT_0003646c == '\x01') {
    if (0x7f < param_1) {
      return;
    }
    iVar1 = *(int *)(DAT_00036464 + param_1 * 4);
    if (iVar1 == 0) {
      return;
    }
    (&DAT_000364f2)[unaff_EBP] = iVar1;
    param_1 = (uint)*(byte *)(iVar1 + 0x1f + unaff_EBX);
    if (param_1 == 0) {
      return;
    }
    param_1 = param_1 - 1;
  }
  if (param_1 < 0x80) {
    iVar1 = *(int *)(DAT_00036460 + param_1 * 4);
    bVar2 = false;
    if (iVar1 != 0) {
      (&DAT_000368b2)[unaff_EBP] = iVar1;
      FUN_00034826();
      if ((!bVar2) && (FUN_000342cb(), (*(byte *)(iVar1 + 0x39) & 1) != 0)) {
        (&DAT_000369b2)[unaff_EBP] = *(undefined4 *)(iVar1 + 0x42);
        (&DAT_00036472)[unaff_EBP] = (&DAT_00036472)[unaff_EBP] | 0x52;
        return;
      }
    }
  }
  return;
}

