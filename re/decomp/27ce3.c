
void FUN_00027ce3(uint *param_1,char *param_2,uint unaff_EBX,int param_4,char *param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  uint local_1c;
  
  uVar5 = *param_1;
  local_1c = param_4 + 1;
  uVar2 = 0;
  if ((param_1[2] & 4) != 0) {
    if (((int)unaff_EBX < (int)uVar5) && ((param_1[2] & 0x10) == 0)) {
      uVar5 = unaff_EBX;
    }
    uVar5 = uVar5 - local_1c;
    if ((int)uVar5 < 0) {
      uVar5 = 0;
    }
  }
  if ((int)local_1c < 1) {
    if ((param_1[2] & 8) == 0) {
      uVar2 = 1;
      *param_5 = '0';
      if ((0 < (int)uVar5) || ((param_1[2] & 0x10) != 0)) {
        uVar2 = 2;
        param_5[1] = '.';
      }
    }
    param_1[7] = uVar2;
    if (-uVar5 != local_1c && (int)uVar5 <= (int)-local_1c) {
      local_1c = -uVar5;
    }
    param_1[6] = local_1c;
    param_1[8] = local_1c;
    param_1[8] = -local_1c;
    uVar5 = uVar5 + local_1c;
    uVar3 = unaff_EBX;
    if ((int)uVar5 < (int)unaff_EBX) {
      uVar3 = uVar5;
    }
    pcVar4 = param_5 + uVar2;
    for (uVar1 = uVar3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar1 = uVar3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *pcVar4 = *param_2;
      param_2 = param_2 + 1;
      pcVar4 = pcVar4 + 1;
    }
    param_1[9] = uVar3;
    unaff_EBX = uVar2 + uVar3;
    param_1[10] = uVar5 - uVar3;
  }
  else if ((int)unaff_EBX < (int)local_1c) {
    pcVar4 = param_5;
    for (uVar2 = unaff_EBX >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)param_2;
      param_2 = param_2 + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar2 = unaff_EBX & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar4 = *param_2;
      param_2 = param_2 + 1;
      pcVar4 = pcVar4 + 1;
    }
    param_1[7] = unaff_EBX;
    param_1[8] = local_1c - unaff_EBX;
    param_1[6] = local_1c;
    if (((param_1[2] & 8) == 0) && ((0 < (int)uVar5 || ((param_1[2] & 0x10) != 0)))) {
      param_5[unaff_EBX] = '.';
      unaff_EBX = unaff_EBX + 1;
      param_1[9] = 1;
    }
    param_1[10] = uVar5;
  }
  else {
    pcVar4 = param_2;
    pcVar6 = param_5;
    for (uVar2 = local_1c >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar2 = local_1c & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar6 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    }
    param_1[6] = local_1c;
    uVar2 = local_1c;
    if ((param_1[2] & 8) == 0) {
      if ((0 < (int)uVar5) || ((param_1[2] & 0x10) != 0)) {
        param_5[local_1c] = '.';
        uVar2 = param_4 + 2;
      }
    }
    else if (*param_5 == '0') {
      param_1[6] = 0;
    }
    uVar3 = unaff_EBX - local_1c;
    if ((int)uVar5 < (int)(unaff_EBX - local_1c)) {
      uVar3 = uVar5;
    }
    pcVar4 = param_2 + local_1c;
    pcVar6 = param_5 + uVar2;
    for (uVar1 = uVar3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar1 = uVar3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *pcVar6 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      pcVar6 = pcVar6 + 1;
    }
    unaff_EBX = uVar2 + uVar3;
    param_1[7] = unaff_EBX;
    param_1[8] = uVar5 - uVar3;
  }
  param_5[unaff_EBX] = '\0';
  return;
}

