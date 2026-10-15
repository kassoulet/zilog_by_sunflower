
void FUN_00017641(int param_1,int param_2,int unaff_EBX,int param_4)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  
  local_1c = 0;
  uVar2 = 0xff;
  iVar3 = FUN_00024cd6(param_1);
  local_14 = 0;
  local_20 = 0;
  local_28 = unaff_EBX;
  local_24 = param_2;
  for (local_30 = 0; local_30 < iVar3; local_30 = local_30 + 1) {
    bVar1 = *(byte *)(param_1 + local_30);
    if (bVar1 == 0x20) {
      local_24 = local_24 + local_14 + 5;
    }
    else if (bVar1 == 10) {
      local_28 = local_28 + *(int *)(param_4 + 8) + local_20;
      local_24 = param_2;
    }
    else if (bVar1 == 0xb) {
      local_1c = 1 - local_1c;
    }
    else if (bVar1 == 8) {
      local_30 = local_30 + 1;
      uVar2 = *(undefined1 *)(param_1 + local_30);
    }
    else if (bVar1 == 7) {
      local_30 = local_30 + 1;
      local_14 = *(byte *)(param_1 + local_30) - 0x30;
    }
    else if (bVar1 == 0xc) {
      local_30 = local_30 + 1;
      local_20 = *(byte *)(param_1 + local_30) - 0x30;
    }
    else {
      if (local_1c == 0) {
        FUN_00024cf0(bVar1,param_4,*(undefined4 *)(DAT_00040304 + 0xc),uVar2,
                     (local_24 + local_28 * 0x140) * 4);
      }
      else {
        FUN_00024d79(bVar1,param_4,DAT_000402f8,uVar2,(local_24 + local_28 * 0x140) * 4);
      }
      local_24 = local_24 +
                 (uint)*(byte *)(*(int *)(param_4 + 0x18) + ((uint)bVar1 - *(int *)(param_4 + 0x10))
                                ) + local_14;
    }
  }
  return;
}

