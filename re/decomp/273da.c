
void FUN_000273da(undefined1 *param_1,double *param_2,int unaff_EBX,uint param_4)

{
  uint extraout_ECX;
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  byte bVar5;
  int local_70 [4];
  undefined4 local_60;
  int iStack_5c;
  uint uStack_54;
  int iStack_50;
  uint uStack_4c;
  int iStack_48;
  undefined4 local_44 [9];
  longdouble local_20;
  undefined4 local_14;
  undefined4 uStack_10;
  
  bVar5 = 0;
  local_14 = *(undefined4 *)param_2;
  uStack_10 = *(undefined4 *)((int)param_2 + 4);
  local_20 = (longdouble)*param_2;
  if ((param_4 & 0x1800) == 0x800) {
    local_70[2] = 1;
    local_70[1] = 1;
  }
  else if ((param_4 & 0x1800) == 0x1000) {
    local_70[2] = 2;
    local_70[1] = 0;
  }
  else {
    local_70[2] = 4;
    local_70[1] = 1;
    if (unaff_EBX == 0) {
      unaff_EBX = 1;
    }
  }
  if ((param_4 & 0x100) != 0) {
    local_70[2] = local_70[2] | 0x10;
  }
  if ((param_4 & 0x200) == 0) {
    local_70[3] = 0x65;
  }
  else {
    local_70[3] = 0x45;
  }
  local_60 = 0;
  iVar2 = 0;
  local_70[0] = unaff_EBX;
  (*(code *)PTR_FUN_0003f970)(&local_20,local_70,local_44);
  if (iStack_5c < 0) {
    iVar2 = 1;
    *param_1 = 0x2d;
  }
  else if ((extraout_ECX & 0x400) != 0) {
    iVar2 = 1;
    *param_1 = 0x2b;
  }
  if (uStack_54 != 0) {
    puVar3 = local_44;
    puVar4 = (undefined4 *)(param_1 + iVar2);
    for (uVar1 = uStack_54 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + (uint)bVar5 * -2 + 1;
      puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
    }
    for (uVar1 = uStack_54 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + (uint)bVar5 * -2 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar5 * -2 + 1);
    }
    iVar2 = iVar2 + uStack_54;
  }
  FUN_00017e46(param_1 + iVar2,0x30,iStack_50);
  iVar2 = iVar2 + iStack_50;
  if (uStack_4c != 0) {
    puVar3 = (undefined4 *)((int)local_44 + uStack_54);
    puVar4 = (undefined4 *)(param_1 + iVar2);
    for (uVar1 = uStack_4c >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + (uint)bVar5 * -2 + 1;
      puVar4 = puVar4 + (uint)bVar5 * -2 + 1;
    }
    for (uVar1 = uStack_4c & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + (uint)bVar5 * -2 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar5 * -2 + 1);
    }
    iVar2 = iVar2 + uStack_4c;
  }
  FUN_00017e46(param_1 + iVar2,0x30,iStack_48);
  param_1[iVar2 + iStack_48] = 0;
  return;
}

