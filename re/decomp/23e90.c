
void FUN_00023e90(char *param_1,uint param_2)

{
  char cVar1;
  undefined1 uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  undefined1 *extraout_EDX;
  char *pcVar6;
  byte bVar7;
  
  bVar7 = 0;
  uVar3 = FUN_0002890b();
  uVar3 = uVar3 >> 0x10 | uVar3;
  pcVar4 = (char *)FUN_00028a04();
  pcVar6 = param_1;
  do {
    cVar1 = *pcVar4;
    *pcVar6 = cVar1;
    if (cVar1 == '\0') break;
    cVar1 = pcVar4[1];
    pcVar4 = pcVar4 + 2;
    pcVar6[1] = cVar1;
    pcVar6 = pcVar6 + 2;
  } while (cVar1 != '\0');
  uVar5 = 0xffffffff;
  pcVar6 = param_1;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + (uint)bVar7 * -2 + 1;
  } while (cVar1 != '\0');
  param_1 = param_1 + (~uVar5 - 1);
  pcVar6 = param_1 + 4;
  *param_1 = 't';
  do {
    uVar2 = FUN_00023e84(uVar3 & 0xf,pcVar6);
    *extraout_EDX = uVar2;
    pcVar6 = extraout_EDX + -1;
    uVar3 = uVar3 >> 4;
  } while (pcVar6 != param_1);
  *(undefined1 *)(extraout_ECX + 5) = 0x5f;
  uVar2 = FUN_00023e84((int)param_2 >> 4 & 0xf);
  *(undefined1 *)(extraout_ECX_00 + 6) = uVar2;
  uVar2 = FUN_00023e84(param_2 & 0xf);
  *(undefined1 *)(extraout_ECX_01 + 8) = 0x2e;
  *(undefined1 *)(extraout_ECX_01 + 9) = 0x74;
  *(undefined1 *)(extraout_ECX_01 + 10) = 0x6d;
  *(undefined1 *)(extraout_ECX_01 + 0xb) = 0x70;
  *(undefined1 *)(extraout_ECX_01 + 0xc) = 0;
  *(undefined1 *)(extraout_ECX_01 + 7) = uVar2;
  return;
}

