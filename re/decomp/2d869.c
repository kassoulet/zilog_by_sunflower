
void FUN_0002d869(undefined4 param_1,char *param_2,int unaff_EBX)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  byte bVar6;
  
  bVar6 = 0;
  FUN_0002f4b5(param_1,param_2,0x10);
  uVar3 = 0xffffffff;
  pcVar4 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + (uint)bVar6 * -2 + 1;
  } while (cVar1 != '\0');
  iVar2 = unaff_EBX + -1;
  pcVar4 = param_2 + (~uVar3 - 1);
  pcVar5 = param_2 + iVar2;
  while (pcVar4 != param_2) {
    pcVar4 = pcVar4 + -1;
    iVar2 = iVar2 + -1;
    *pcVar5 = *pcVar4;
    pcVar5 = pcVar5 + -1;
  }
  pcVar4 = param_2 + iVar2;
  for (; -1 < iVar2; iVar2 = iVar2 + -1) {
    *pcVar4 = '0';
    pcVar4 = pcVar4 + -1;
  }
  param_2[unaff_EBX] = '\0';
  return;
}

