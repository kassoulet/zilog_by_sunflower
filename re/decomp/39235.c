
void FUN_00039235(void)

{
  byte bVar1;
  byte *unaff_EDI;
  undefined1 in_CF;
  
  DAT_00036456 = 0x220;
  DAT_00036458 = 7;
  DAT_00036459 = 1;
  DAT_0003645c = 0x105;
  DAT_0003645a = 0x5654;
  DAT_00039172 = 5;
  FUN_00033818(&DAT_00039173);
  if (!(bool)in_CF) {
    while( true ) {
      bVar1 = *unaff_EDI;
      unaff_EDI = unaff_EDI + 1;
      if (bVar1 == 0) break;
      bVar1 = bVar1 & 0xdf;
      if (bVar1 == 0x41) {
        DAT_00036456 = FUN_00039210();
      }
      else if (bVar1 == 0x49) {
        DAT_00036458 = FUN_000391f5();
      }
      else if (bVar1 == 0x44) {
        DAT_00036459 = FUN_000391f5();
      }
      else if (bVar1 == 0x48) {
        DAT_00039172 = FUN_000391f5();
      }
    }
  }
  return;
}

