
byte * FUN_0002a0ff(byte *param_1,int param_2)

{
  byte *pbVar1;
  byte bVar3;
  int iVar2;
  uint local_10;
  
  bVar3 = *(byte *)(param_2 + 0x10);
  *(byte *)(param_2 + 0x10) = bVar3 | 1;
  *(undefined4 *)(param_2 + 0xc) = 0xffffffff;
  *(byte *)(param_2 + 0x10) = bVar3 & 3 | 1;
  if (*param_1 == 0x2a) {
    param_1 = param_1 + 1;
    *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) & 0xfe;
  }
  bVar3 = *param_1;
  if (((&DAT_0003fda0)[(byte)(bVar3 + 1)] & 0x20) != 0) {
    iVar2 = 0;
    do {
      local_10 = (uint)bVar3;
      param_1 = param_1 + 1;
      iVar2 = iVar2 * 10 + (local_10 - 0x30);
      bVar3 = *param_1;
    } while (((&DAT_0003fda0)[(byte)(bVar3 + 1)] & 0x20) != 0);
    *(int *)(param_2 + 0xc) = iVar2;
  }
  if (*param_1 == 0x4e) {
    *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) | 8;
    param_1 = param_1 + 1;
  }
  else if (*param_1 == 0x46) {
    *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) | 4;
    param_1 = param_1 + 1;
  }
  bVar3 = *param_1;
  pbVar1 = param_1 + 1;
  if (bVar3 < 0x68) {
    if (bVar3 < 0x49) {
      return param_1;
    }
    if (0x49 < bVar3) {
      if (bVar3 != 0x4c) {
        return param_1;
      }
      *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) | 0x40;
      return pbVar1;
    }
    if (param_1[1] != 0x36) {
      return param_1;
    }
    if (param_1[2] != 0x34) {
      return param_1;
    }
    bVar3 = *(byte *)(param_2 + 0x10) | 0x40;
    pbVar1 = param_1 + 3;
  }
  else {
    if (0x68 < bVar3) {
      if (bVar3 < 0x6c) {
        return param_1;
      }
      if ((0x6c < bVar3) && (bVar3 != 0x77)) {
        return param_1;
      }
      *(byte *)(param_2 + 0x10) = *(byte *)(param_2 + 0x10) | 0x20;
      return param_1 + 1;
    }
    bVar3 = *(byte *)(param_2 + 0x10) | 0x10;
  }
  *(byte *)(param_2 + 0x10) = bVar3;
  return pbVar1;
}

