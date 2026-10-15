
void FUN_00034b8d(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined1 *puVar5;
  char *pcVar6;
  char *pcVar7;
  
  puVar1 = DAT_00033a1c;
  puVar3 = &DAT_00033ae0;
  puVar5 = DAT_00033a1c;
  for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  pcVar6 = puVar1 + 0x20;
  if ((DAT_0003645c & 8) != 0) {
    pcVar4 = s_Stereo_00033ae5;
    for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pcVar6 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    }
    pcVar6 = puVar1 + 0x40;
  }
  pcVar4 = s_Mono_oversampling_00033aec;
  pcVar7 = pcVar6;
  for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pcVar7 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar7 = pcVar7 + 1;
  }
  if ((DAT_0003645c & 8) != 0) {
    pcVar4 = s_Stereo_oversampling_00033afe;
    pcVar6 = pcVar6 + 0x20;
    for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pcVar6 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  return;
}

