
undefined8 FUN_00016b44(uint param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  if (param_1 < 0x40) {
    DAT_00016b40 = *(char **)(&DAT_00016b93 + param_1 * 4);
  }
  else {
    DAT_00016b40 = DAT_00016b38;
    if (param_1 != DAT_00016b3c) {
      iVar3 = 0x100;
      cVar1 = '\0';
      uVar2 = param_1;
      pcVar4 = DAT_00016b38;
      DAT_00016b3c = param_1;
      do {
        for (; uVar2 != 0; uVar2 = uVar2 - 1) {
          *pcVar4 = cVar1;
          pcVar4 = pcVar4 + 1;
        }
        cVar1 = cVar1 + '\x01';
        iVar3 = iVar3 + -1;
        uVar2 = param_1;
      } while (iVar3 != 0);
    }
  }
  return CONCAT44(param_2,param_1);
}

