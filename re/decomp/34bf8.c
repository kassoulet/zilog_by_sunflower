
void FUN_00034bf8(ushort param_1)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  int unaff_EDI;
  char *pcVar4;
  
  iVar3 = 0;
  uVar2 = param_1;
  do {
    iVar3 = iVar3 + 1;
    uVar2 = uVar2 / 10;
  } while (uVar2 != 0);
  pcVar4 = (char *)(unaff_EDI + iVar3);
  *pcVar4 = '\0';
  do {
    pcVar4 = pcVar4 + -1;
    uVar1 = (uint)param_1;
    param_1 = param_1 / 10;
    *pcVar4 = (char)(uVar1 % 10) + '0';
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

