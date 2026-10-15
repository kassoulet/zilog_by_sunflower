
uint FUN_00023b44(byte *param_1,byte *param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  uint local_18;
  
  bVar2 = true;
  bVar3 = false;
  bVar4 = false;
  bVar5 = false;
  if (param_2 != (byte *)0x0) {
    if (DAT_0003fa04 == 1) {
      param_2[0] = 1;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
    }
    else {
      param_2[0] = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
    }
  }
  bVar1 = *param_1;
  if (bVar1 < 0x72) {
    if (bVar1 != 0x61) {
LAB_00023b94:
      FUN_000284cf(9);
      return 0;
    }
    local_18 = 0x82;
  }
  else if (bVar1 < 0x73) {
    local_18 = 1;
  }
  else {
    if (bVar1 != 0x77) goto LAB_00023b94;
    local_18 = 2;
  }
LAB_00023ba5:
  param_1 = param_1 + 1;
  bVar1 = *param_1;
  if ((bVar1 == 0) || (!bVar2)) {
    if (bVar4) {
      return local_18;
    }
    if (DAT_0003fc11 != 0x200) {
      return local_18;
    }
    local_18 = local_18 | 0x40;
    return local_18;
  }
  if (bVar1 < 99) goto LAB_00023bd2;
  if (bVar1 < 100) {
    if (!bVar5) {
      bVar5 = true;
      *param_2 = *param_2 | 1;
      goto LAB_00023ba5;
    }
  }
  else {
    if (bVar1 < 0x6e) goto LAB_00023ba5;
    if (0x6e < bVar1) {
      if (bVar1 == 0x74) {
        if (bVar4) goto LAB_00023be2;
        bVar4 = true;
      }
      goto LAB_00023ba5;
    }
    if (!bVar5) {
      bVar5 = true;
      *param_2 = *param_2 & 0xfe;
      goto LAB_00023ba5;
    }
  }
  goto LAB_00023be2;
LAB_00023bd2:
  if (bVar1 < 0x2b) goto LAB_00023ba5;
  if (bVar1 < 0x2c) {
    if (!bVar3) {
      bVar3 = true;
      local_18 = local_18 | 3;
      goto LAB_00023ba5;
    }
  }
  else {
    if (bVar1 != 0x62) goto LAB_00023ba5;
    if (!bVar4) {
      bVar4 = true;
      local_18 = local_18 | 0x40;
      goto LAB_00023ba5;
    }
  }
LAB_00023be2:
  bVar2 = false;
  goto LAB_00023ba5;
}

