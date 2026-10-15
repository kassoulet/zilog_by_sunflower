
undefined8 FUN_00028a04(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  undefined **ppuVar4;
  char *pcVar5;
  byte bVar6;
  
  bVar6 = 0;
  if (DAT_0003fc2c == '\0') {
    for (ppuVar4 = &PTR_DAT_0003fc18; **ppuVar4 != '\0'; ppuVar4 = ppuVar4 + 1) {
      pcVar2 = (char *)FUN_0002e790();
      if (pcVar2 != (char *)0x0) {
        uVar3 = 0xffffffff;
        pcVar5 = pcVar2;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + (uint)bVar6 * -2 + 1;
        } while (cVar1 != '\0');
        if (~uVar3 - 1 < 0x90) {
          FUN_0002e7ea(&DAT_0003fc2c,pcVar2,0x8f);
          break;
        }
      }
    }
    if (DAT_0003fc2c == '\0') {
      pcVar5 = &DAT_0003fc2c;
      pcVar2 = (char *)FUN_0002eab9(0,0);
      do {
        cVar1 = *pcVar2;
        *pcVar5 = cVar1;
        if (cVar1 == '\0') break;
        cVar1 = pcVar2[1];
        pcVar2 = pcVar2 + 2;
        pcVar5[1] = cVar1;
        pcVar5 = pcVar5 + 2;
      } while (cVar1 != '\0');
    }
    uVar3 = 0xffffffff;
    pcVar2 = &DAT_0003fc2c;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + (uint)bVar6 * -2 + 1;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    if ((*(char *)(uVar3 + 0x3fc2a) != '\\') && (*(char *)(uVar3 + 0x3fc2a) != '/')) {
      (&DAT_0003fc2b)[uVar3] = 0x5c;
      (&DAT_0003fc2c)[uVar3] = 0;
    }
  }
  return CONCAT44(param_2,&DAT_0003fc2c);
}

