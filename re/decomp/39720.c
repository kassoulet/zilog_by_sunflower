
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_00039720(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = 10000;
  do {
    cVar1 = in(DAT_00036456 + 0xe);
    if (cVar1 < '\0') {
      cVar1 = in(DAT_00036456 + 10);
      return cVar1;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _DAT_0003915a = 1;
  return cVar1;
}

