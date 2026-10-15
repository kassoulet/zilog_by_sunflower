
void FUN_00039749(void)

{
  char cVar1;
  int iVar2;
  short sVar3;
  
  sVar3 = DAT_00036456 + 6;
  out(sVar3,1);
  iVar2 = 10;
  do {
    in(sVar3);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  out(sVar3,0);
  iVar2 = 1000;
  while (cVar1 = in(DAT_00036456 + 0xe), -1 < cVar1) {
    iVar2 = iVar2 + -1;
    if (iVar2 == 0) {
      return;
    }
  }
  iVar2 = 1000;
  do {
    cVar1 = in(DAT_00036456 + 10);
    if (cVar1 == -0x56) {
      return;
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

