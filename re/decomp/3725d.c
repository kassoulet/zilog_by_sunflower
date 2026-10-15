
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0003725d(void)

{
  undefined4 uVar1;
  undefined1 in_CF;
  
  uVar1 = FUN_00033818(s_INTERWAVE_00037243);
  if ((bool)in_CF) {
    return uVar1;
  }
  DAT_00037251 = 0;
  DAT_00036456 = 0x210;
  do {
    uVar1 = FUN_00037726();
    if (!(bool)in_CF) {
      FUN_000377bd();
      DAT_0003645c = 0x22a;
      DAT_00036452 = s_AMD_Interwave_00037226;
      _DAT_0003645e = 0x20;
      return 1;
    }
    DAT_00036456 = DAT_00036456 + 0x10;
    in_CF = DAT_00036456 < 0x260;
  } while (DAT_00036456 < 0x261);
  return uVar1;
}

