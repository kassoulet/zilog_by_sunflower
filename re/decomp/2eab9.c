
undefined4 FUN_0002eab9(int param_1,uint param_2)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  byte bVar6;
  byte bVar7;
  undefined8 uVar8;
  char acStack_a0 [140];
  
  uVar8 = CONCAT44(param_2,param_1);
  bVar7 = 0;
  bVar6 = 0;
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(CONCAT11(0x47,(char)param_1),param_2 & 0xffffff00);
  if ((bVar6 & 1) == 0) {
    pcVar1 = (code *)swi(0x21);
    cVar2 = (*pcVar1)();
    acStack_a0[0] = cVar2 + 'A';
    acStack_a0[2] = 0x5c;
    acStack_a0[1] = 0x3a;
    uVar4 = 0xffffffff;
    pcVar5 = acStack_a0;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + (uint)bVar7 * -2 + 1;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4;
    if (param_1 == 0) {
      if (uVar4 < param_2) {
        uVar4 = param_2;
      }
      uVar8 = FUN_000243a3(uVar4);
      if ((int)uVar8 == 0) {
        uVar3 = 5;
        goto LAB_0002eadf;
      }
    }
    uVar3 = FUN_0002fdd2((int)uVar8,acStack_a0,(int)((ulonglong)uVar8 >> 0x20));
  }
  else {
    uVar3 = 1;
LAB_0002eadf:
    FUN_000284cf(uVar3);
    uVar3 = 0;
  }
  return uVar3;
}

