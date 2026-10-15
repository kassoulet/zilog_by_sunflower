
void FUN_00027f01(int *param_1,undefined4 *param_2,uint unaff_EBX,int param_4,undefined4 *param_5)

{
  int iVar1;
  int extraout_ECX;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  byte bVar5;
  int local_28;
  undefined4 *local_20;
  uint local_18;
  uint local_14;
  uint local_10;
  
  bVar5 = 0;
  iVar1 = param_1[1];
  if (iVar1 < 1) {
    local_18 = *param_1 + iVar1;
  }
  else {
    local_18 = (*param_1 - iVar1) + 1;
  }
  if ((*(byte *)(param_1 + 2) & 4) != 0) {
    if ((int)unaff_EBX < (int)local_18) {
      local_18 = unaff_EBX;
    }
    local_18 = local_18 - 1;
    if ((int)local_18 < 0) {
      local_18 = 0;
    }
  }
  local_14 = param_1[1];
  if ((int)local_14 < 1) {
    local_10 = 1;
    *(undefined1 *)param_5 = 0x30;
    local_20 = param_2;
  }
  else {
    if ((int)unaff_EBX < (int)local_14) {
      local_14 = unaff_EBX;
    }
    puVar3 = param_2;
    puVar4 = param_5;
    for (uVar2 = local_14 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar2 = local_14 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    local_20 = (undefined4 *)((int)param_2 + local_14);
    unaff_EBX = unaff_EBX - local_14;
    local_10 = local_14;
    if ((int)local_14 < param_1[1]) {
      iVar1 = param_1[1] - local_14;
      FUN_00017e46((undefined1 *)((int)param_5 + local_14),0x30,iVar1);
      local_10 = local_14 + iVar1;
    }
  }
  param_1[6] = local_10;
  if (((*(byte *)(param_1 + 2) & 8) == 0) &&
     ((0 < (int)local_18 || ((*(byte *)(param_1 + 2) & 0x10) != 0)))) {
    *(undefined1 *)(local_10 + (int)param_5) = 0x2e;
    local_10 = local_10 + 1;
  }
  iVar1 = param_1[1];
  if (iVar1 < 0) {
    FUN_00017e46((undefined1 *)((int)param_5 + local_10),0x30);
    local_10 = extraout_ECX - iVar1;
  }
  if (0 < (int)local_18) {
    if ((int)local_18 < (int)unaff_EBX) {
      unaff_EBX = local_18;
    }
    if (unaff_EBX != 0) {
      puVar3 = (undefined4 *)((int)param_5 + local_10);
      for (uVar2 = unaff_EBX >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar3 = *local_20;
        local_20 = local_20 + (uint)bVar5 * -2 + 1;
        puVar3 = puVar3 + (uint)bVar5 * -2 + 1;
      }
      for (uVar2 = unaff_EBX & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined1 *)puVar3 = *(undefined1 *)local_20;
        local_20 = (undefined4 *)((int)local_20 + (uint)bVar5 * -2 + 1);
        puVar3 = (undefined4 *)((int)puVar3 + (uint)bVar5 * -2 + 1);
      }
      local_10 = local_10 + unaff_EBX;
    }
    param_1[7] = local_10;
    param_1[8] = local_18 - unaff_EBX;
  }
  if (param_1[3] != 0) {
    *(char *)(local_10 + (int)param_5) = (char)param_1[3];
    local_10 = local_10 + 1;
  }
  if (param_4 < 0) {
    local_28 = -param_4;
    *(undefined1 *)(local_10 + (int)param_5) = 0x2d;
  }
  else {
    *(undefined1 *)(local_10 + (int)param_5) = 0x2b;
    local_28 = param_4;
  }
  iVar1 = param_1[4];
  switch(iVar1) {
  case 0:
    if (local_28 < 1000) {
      iVar1 = 3;
      goto switchD_000280fe_default;
    }
    goto LAB_00028135;
  case 1:
    if (9 < local_28) {
      iVar1 = 2;
    }
  case 2:
    break;
  case 3:
    goto switchD_000280fe_caseD_3;
  default:
    goto switchD_000280fe_default;
  }
  if (99 < local_28) {
    iVar1 = 3;
  }
switchD_000280fe_caseD_3:
  if (999 < local_28) {
LAB_00028135:
    iVar1 = 4;
  }
switchD_000280fe_default:
  param_1[4] = iVar1;
  uVar2 = local_10 + 1;
  if (3 < iVar1) {
    local_14._0_1_ = '\0';
    if (999 < local_28) {
      local_14._0_1_ = (char)(local_28 / 1000);
      local_28 = local_28 % 1000;
    }
    *(char *)(local_10 + 1 + (int)param_5) = (char)local_14 + '0';
    uVar2 = local_10 + 2;
  }
  local_10 = uVar2;
  if (2 < iVar1) {
    local_14._0_1_ = '\0';
    if (99 < local_28) {
      local_14._0_1_ = (char)(local_28 / 100);
      local_28 = local_28 % 100;
    }
    *(char *)(local_10 + (int)param_5) = (char)local_14 + '0';
    local_10 = local_10 + 1;
  }
  if (1 < iVar1) {
    local_14._0_1_ = '\0';
    if (9 < local_28) {
      local_14._0_1_ = (char)(local_28 / 10);
      local_28 = local_28 % 10;
    }
    *(char *)(local_10 + (int)param_5) = (char)local_14 + '0';
    local_10 = local_10 + 1;
  }
  *(char *)(local_10 + (int)param_5) = (char)local_28 + '0';
  param_1[9] = (local_10 + 1) - param_1[7];
  *(undefined1 *)((int)param_5 + local_10 + 1) = 0;
  return;
}

