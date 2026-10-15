
void FUN_0002d8c7(undefined1 *param_1,uint param_2,int unaff_EBX)

{
  int iVar1;
  undefined1 *puVar2;
  char *extraout_ECX;
  char *pcVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 local_10;
  
  puVar2 = param_1;
  local_10 = param_2;
  if ((int)param_2 < 0) {
    local_10 = -param_2;
    puVar2 = param_1 + 1;
    *param_1 = 0x2d;
  }
  if (*(int *)(unaff_EBX + 8) == -1) {
    *(undefined4 *)(unaff_EBX + 8) = 4;
  }
  FUN_0002f4b5(local_10 >> 0x10,puVar2,10);
  pcVar4 = extraout_ECX;
  do {
    pcVar3 = pcVar4;
    pcVar4 = pcVar3 + 1;
  } while (*pcVar3 != '\0');
  if (*(int *)(unaff_EBX + 8) != 0) {
    *pcVar3 = '.';
    for (iVar1 = 0; iVar1 < *(int *)(unaff_EBX + 8); iVar1 = iVar1 + 1) {
      local_10 = local_10 & 0xffff;
      uVar5 = local_10 * 10;
      local_10._2_1_ = (char)(uVar5 >> 0x10);
      *pcVar4 = local_10._2_1_ + '0';
      pcVar4 = pcVar4 + 1;
      local_10 = uVar5;
    }
    *pcVar4 = '\0';
    pcVar3 = pcVar4;
  }
  if ((local_10 & 0x8000) != 0) {
    while (pcVar3 != extraout_ECX) {
      pcVar4 = pcVar3 + -1;
      if (*pcVar4 == '.') {
        pcVar4 = pcVar3 + -2;
      }
      if (*pcVar4 != '9') {
        *pcVar4 = *pcVar4 + '\x01';
        return;
      }
      *pcVar4 = '0';
      pcVar3 = pcVar4;
    }
    *extraout_ECX = '1';
    pcVar4 = extraout_ECX + 1;
    do {
      pcVar3 = pcVar4;
      pcVar4 = pcVar3 + 1;
    } while (*pcVar3 == '0');
    if (*pcVar3 == '.') {
      *pcVar3 = '0';
      pcVar3[1] = '.';
      for (pcVar3 = pcVar3 + 2; *pcVar3 == '0'; pcVar3 = pcVar3 + 1) {
      }
    }
    *pcVar3 = '0';
    pcVar3[1] = '\0';
  }
  return;
}

