
void FUN_000342cb(short param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  undefined2 uVar2;
  int iVar1;
  int unaff_EBP;
  
  uVar2 = (undefined2)((uint)unaff_EBX >> 0x10);
  if (param_1 < DAT_00036468) {
    iVar1 = CONCAT31((int3)(CONCAT22(uVar2,DAT_00036468) >> 8),1);
    param_1 = (short)iVar1;
  }
  else if (DAT_0003646a < param_1) {
    iVar1 = CONCAT31((int3)(CONCAT22(uVar2,DAT_0003646a) >> 8),1);
    param_1 = (short)iVar1;
  }
  else {
    iVar1 = 0;
  }
  if ((&DAT_000368b2)[unaff_EBP] != 0) {
    (&DAT_000365f2)[unaff_EBP] = param_1;
    (&DAT_00036472)[unaff_EBP] = (&DAT_00036472)[unaff_EBP] | 0x20;
    if (iVar1 != 0) {
      return;
    }
  }
  return;
}

