
void FUN_00039aa5(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX,undefined4 param_4)

{
  uint uVar1;
  undefined1 in_CF;
  
  FUN_00037000(0x8400);
  uVar1 = DAT_00036ffc;
  if ((bool)in_CF) {
    uVar1 = FUN_00037099(DAT_00036ffc,param_2,unaff_EBX,param_4);
  }
  if (!(bool)in_CF) {
    DAT_000398aa = (uVar1 & 0xfffffe00) + 0x200;
    DAT_000398ae = uVar1;
    FUN_000399bd(DAT_000398a8);
    return;
  }
  return;
}

