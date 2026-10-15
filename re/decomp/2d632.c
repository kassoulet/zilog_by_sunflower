
byte * FUN_0002d632(undefined4 param_1,int *param_2,int unaff_EBX)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  *(undefined1 *)(unaff_EBX + 0x16) = 0x20;
  pbVar4 = (byte *)FUN_0002d77f(param_1,unaff_EBX);
  *(undefined4 *)(unaff_EBX + 4) = 0;
  if (*pbVar4 == 0x2a) {
    piVar2 = (int *)*param_2;
    *param_2 = (int)(piVar2 + 1);
    iVar3 = *piVar2;
    *(int *)(unaff_EBX + 4) = iVar3;
    if (iVar3 < 0) {
      *(int *)(unaff_EBX + 4) = -iVar3;
      *(byte *)(unaff_EBX + 0x1e) = *(byte *)(unaff_EBX + 0x1e) | 8;
    }
    pbVar4 = pbVar4 + 1;
  }
  else {
    for (; (0x2f < *pbVar4 && (*pbVar4 < 0x3a)); pbVar4 = pbVar4 + 1) {
      *(uint *)(unaff_EBX + 4) = *(int *)(unaff_EBX + 4) * 10 + (*pbVar4 - 0x30);
    }
  }
  *(undefined4 *)(unaff_EBX + 8) = 0xffffffff;
  pbVar5 = pbVar4;
  if (*pbVar4 == 0x2e) {
    pbVar5 = pbVar4 + 1;
    *(undefined4 *)(unaff_EBX + 8) = 0;
    if (*pbVar5 == 0x2a) {
      piVar2 = (int *)*param_2;
      *param_2 = (int)(piVar2 + 1);
      iVar3 = *piVar2;
      *(int *)(unaff_EBX + 8) = iVar3;
      if (iVar3 < 0) {
        *(undefined4 *)(unaff_EBX + 8) = 0xffffffff;
      }
      pbVar5 = pbVar4 + 2;
    }
    else {
      for (; (0x2f < *pbVar5 && (*pbVar5 < 0x3a)); pbVar5 = pbVar5 + 1) {
        *(uint *)(unaff_EBX + 8) = *(int *)(unaff_EBX + 8) * 10 + (*pbVar5 - 0x30);
      }
    }
    if (*(int *)(unaff_EBX + 8) != -1) {
      *(undefined1 *)(unaff_EBX + 0x16) = 0x20;
    }
  }
  bVar1 = *pbVar5;
  pbVar4 = pbVar5 + 1;
  if (bVar1 < 0x4e) {
    if (bVar1 < 0x49) {
      if (bVar1 != 0x46) {
        return pbVar5;
      }
      *(byte *)(unaff_EBX + 0x1e) = *(byte *)(unaff_EBX + 0x1e) | 0x80;
    }
    else {
      if (0x49 < bVar1) {
        if (bVar1 == 0x4c) {
          *(byte *)(unaff_EBX + 0x1f) = *(byte *)(unaff_EBX + 0x1f) | 1;
          return pbVar4;
        }
        return pbVar5;
      }
      pbVar4 = pbVar5;
      if ((pbVar5[1] == 0x36) && (pbVar5[2] == 0x34)) {
        *(byte *)(unaff_EBX + 0x1f) = *(byte *)(unaff_EBX + 0x1f) | 1;
        return pbVar5 + 3;
      }
    }
  }
  else if (bVar1 < 0x4f) {
    *(byte *)(unaff_EBX + 0x1e) = *(byte *)(unaff_EBX + 0x1e) | 0x40;
  }
  else {
    if (0x6b < bVar1) {
      if ((0x6c < bVar1) && (bVar1 != 0x77)) {
        return pbVar5;
      }
      *(byte *)(unaff_EBX + 0x1e) = *(byte *)(unaff_EBX + 0x1e) | 0x20;
      return pbVar5 + 1;
    }
    if (bVar1 != 0x68) {
      return pbVar5;
    }
    *(byte *)(unaff_EBX + 0x1e) = *(byte *)(unaff_EBX + 0x1e) | 0x10;
  }
  return pbVar4;
}

