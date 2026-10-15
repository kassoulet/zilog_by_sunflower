
void FUN_00034b33(void)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  
  pcVar8 = DAT_00033a1c;
  pcVar7 = s_Autodetect_best_device_00033ac9;
  pcVar9 = DAT_00033a1c;
  for (iVar4 = 0x17; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  pcVar8 = pcVar8 + 0x20;
  iVar5 = 0;
  iVar4 = 1;
  while( true ) {
    puVar2 = (&PTR_PTR_FUN_0003397b)[iVar5];
    iVar5 = iVar5 + 1;
    if (puVar2 == (undefined *)0x0) {
      return;
    }
    uVar3 = (uint)*(ushort *)(puVar2 + 0x1c);
    iVar4 = iVar4 + uVar3;
    if (0x12 < (ushort)iVar4) break;
    puVar6 = (undefined4 *)(puVar2 + 0x22);
    pcVar7 = pcVar8;
    do {
      pcVar8 = (char *)*puVar6;
      pcVar9 = pcVar7;
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        *pcVar9 = cVar1;
        pcVar9 = pcVar9 + 1;
      } while (cVar1 != '\0');
      pcVar8 = pcVar7 + 0x20;
      pcVar7[0x1f] = '\0';
      puVar6 = puVar6 + 1;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar8;
    } while (uVar3 != 0);
  }
  return;
}

