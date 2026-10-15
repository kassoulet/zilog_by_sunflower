
int FUN_00039210(void)

{
  int iVar1;
  byte bVar2;
  byte *unaff_EDI;
  
  iVar1 = 0;
  while( true ) {
    bVar2 = *unaff_EDI;
    unaff_EDI = unaff_EDI + 1;
    if (bVar2 < 0x3a) {
      bVar2 = bVar2 - 0x30;
    }
    else {
      bVar2 = bVar2 + 0xb5;
    }
    if ((*unaff_EDI == 0x20) || (*unaff_EDI == 0)) break;
    iVar1 = (iVar1 + (uint)bVar2) * 0x10;
  }
  return iVar1 + (uint)bVar2;
}

