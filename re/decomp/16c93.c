
undefined8 FUN_00016c93(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar4 = 1;
  pcVar5 = DAT_00016b8f;
  do {
    *(char **)(&DAT_00016b93 + uVar4 * 4) = pcVar5;
    cVar1 = '\0';
    iVar3 = 0x100;
    uVar2 = uVar4;
    do {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *pcVar5 = cVar1;
        pcVar5 = pcVar5 + 1;
      }
      cVar1 = cVar1 + '\x01';
      iVar3 = iVar3 + -1;
      uVar2 = uVar4;
    } while (iVar3 != 0);
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x40);
  return CONCAT44(param_2,param_1);
}

