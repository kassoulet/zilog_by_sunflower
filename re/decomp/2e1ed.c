
undefined4 FUN_0002e1ed(byte *param_1,undefined4 *param_2,undefined4 *unaff_EBX)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined4 uVar7;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint uVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  undefined4 uStack_48;
  byte local_44 [20];
  undefined4 local_30;
  undefined4 local_2c;
  ushort local_28;
  byte *local_24;
  int local_20;
  
  for (pbVar5 = param_1; (bVar9 = *pbVar5, bVar9 == 0x20 || ((8 < bVar9 && (bVar9 < 0xe))));
      pbVar5 = pbVar5 + 1) {
  }
  if ((bVar9 == 0x2b) || (bVar9 == 0x2d)) {
    pbVar5 = pbVar5 + 1;
  }
  bVar3 = false;
  bVar2 = false;
  bVar4 = false;
  iVar10 = 0;
  bVar9 = 0x30;
  local_20 = 0;
  local_24 = param_1;
  while( true ) {
    while( true ) {
      bVar1 = *pbVar5;
      pbVar6 = pbVar5 + 1;
      if (bVar1 != 0x2e) break;
      if (bVar4) goto LAB_0002e266;
      bVar4 = true;
      pbVar5 = pbVar6;
    }
    if ((bVar1 < 0x30) || (0x39 < bVar1)) break;
    if (bVar4) {
      local_20 = local_20 + 1;
    }
    bVar9 = bVar9 | bVar1;
    if (bVar9 != 0x30) {
      if (iVar10 < 0x13) {
        local_44[iVar10] = bVar1;
      }
      iVar10 = iVar10 + 1;
    }
    bVar2 = true;
    pbVar5 = pbVar6;
  }
LAB_0002e266:
  iVar11 = 0;
  if ((bVar2) && ((bVar1 == 0x65 || (local_24 = pbVar5, bVar1 == 0x45)))) {
    local_24 = pbVar5 + 2;
    if ((*pbVar6 != 0x2b) && (local_24 = pbVar6, *pbVar6 == 0x2d)) {
      bVar3 = true;
      local_24 = pbVar5 + 2;
    }
    bVar2 = false;
    while( true ) {
      bVar9 = *local_24;
      if ((bVar9 < 0x30) || (0x39 < bVar9)) break;
      if (iVar11 < 1000) {
        iVar11 = (uint)bVar9 + iVar11 * 10 + -0x30;
      }
      bVar2 = true;
      local_24 = local_24 + 1;
    }
    if (bVar3) {
      iVar11 = -iVar11;
    }
    if (!bVar2) {
      local_24 = pbVar5;
    }
  }
  if (unaff_EBX != (undefined4 *)0x0) {
    *unaff_EBX = local_24;
  }
  iVar11 = iVar11 - local_20;
  if (0x13 < iVar10) {
    iVar11 = iVar11 + iVar10 + -0x13;
    iVar10 = 0x13;
  }
  for (; (0 < iVar10 && (local_44[iVar10 + -1] == 0x30)); iVar10 = iVar10 + -1) {
    iVar11 = iVar11 + 1;
  }
  if (iVar10 == 0) {
    *(undefined2 *)(param_2 + 2) = 0;
    param_2[1] = 0;
    *param_2 = 0;
    uVar7 = 0;
  }
  else {
    local_44[iVar10] = 0;
    uStack_48 = 0x2e32b;
    FUN_0002fc32(local_44,&local_30);
    uVar8 = extraout_ECX;
    if (iVar11 != 0) {
      uStack_48 = 0x2e339;
      FUN_00027847(&local_30,iVar11);
      uVar8 = extraout_ECX_00;
    }
    if ((uVar8 & 1) != 0) {
      local_28 = local_28 | 0x8000;
    }
    *(ushort *)(param_2 + 2) = local_28;
    param_2[1] = local_2c;
    *param_2 = local_30;
    iVar10 = iVar11 + -1 + iVar10;
    if (iVar10 < 0x135) {
      if (iVar10 < -0x134) {
        uVar7 = 2;
      }
      else {
        uVar7 = 1;
      }
    }
    else {
      uVar7 = 3;
    }
  }
  return uVar7;
}

