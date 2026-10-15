
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00039e50(void)

{
  int iVar1;
  uint uVar2;
  undefined2 extraout_CX;
  undefined2 extraout_CX_00;
  undefined2 extraout_CX_01;
  undefined2 extraout_CX_02;
  undefined2 uVar3;
  int unaff_EBP;
  
  iVar1 = (&DAT_000368b2)[unaff_EBP];
  _DAT_0003988e = (uint)*(byte *)(iVar1 + 0x38);
  DAT_00039892 = *(int *)(iVar1 + 0x42) + *(int *)(iVar1 + 0x24);
  DAT_00039896 = 0;
  if (((*(byte *)(iVar1 + 0x38) & 8) != 0) &&
     (DAT_00039896 = *(int *)(iVar1 + 0x2c) - *(int *)(iVar1 + 0x28),
     (*(byte *)(iVar1 + 0x38) & 0x10) != 0)) {
    DAT_00039892 = DAT_00039892 + DAT_00039896;
    DAT_00039896 = DAT_00039896 * 2;
  }
  uVar2 = (&DAT_000369b2)[unaff_EBP];
  DAT_000398a4 = (uint)(byte)(&DAT_00039976)[unaff_EBP] << 8;
  _DAT_0003989a = (&DAT_00039936)[unaff_EBP];
  _DAT_0003989c = (uint)(ushort)(&DAT_000398f6)[unaff_EBP];
  if ((DAT_0003645c & 0x20) == 0) {
    if ((DAT_0003645c & 8) == 0) {
      FUN_00039f80();
      uVar3 = extraout_CX_01;
    }
    else {
      FUN_0003a5d6((uint)(byte)(&DAT_00039996)[unaff_EBP] * 0x100,DAT_00039880 >> 2,
                   (DAT_000398aa >> 1) + (uint)(byte)(&DAT_00039996)[unaff_EBP] * 0x100,
                   (&DAT_000398b6)[unaff_EBP]);
      uVar3 = extraout_CX_02;
    }
  }
  else if ((DAT_0003645c & 8) == 0) {
    FUN_0003b0e6();
    uVar3 = extraout_CX;
  }
  else {
    FUN_0003bd0e();
    uVar3 = extraout_CX_00;
  }
  if ((DAT_00039896 == 0) && (DAT_00039892 <= uVar2)) {
    (&DAT_00036472)[unaff_EBP] = (&DAT_00036472)[unaff_EBP] & 0xfffd;
    return;
  }
  (&DAT_000398b6)[unaff_EBP] = uVar3;
  (&DAT_000369b2)[unaff_EBP] = uVar2;
  return;
}

