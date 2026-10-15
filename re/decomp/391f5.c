
int FUN_000391f5(void)

{
  char cVar1;
  int iVar2;
  char *unaff_EDI;
  
  iVar2 = 0;
  while( true ) {
    cVar1 = *unaff_EDI;
    unaff_EDI = unaff_EDI + 1;
    iVar2 = iVar2 + (uint)(byte)(cVar1 - 0x30);
    if ((*unaff_EDI == ' ') || (*unaff_EDI == '\0')) break;
    iVar2 = iVar2 * 10;
  }
  return iVar2;
}

