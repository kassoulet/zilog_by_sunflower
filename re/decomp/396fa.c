
void FUN_000396fa(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 10000;
  do {
    cVar1 = in(DAT_00036456 + 0xc);
    if (-1 < cVar1) {
      return;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

