
undefined4 FUN_00029993(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_18;
  undefined1 local_14 [4];
  
  if (*(int *)(param_1 + 0x10) == *(int *)(param_1 + 0x14) ||
      *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x14) < 0) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  else {
    iVar1 = (**(code **)(*(int *)(param_1 + 0x28) + 0x20))(param_1);
    if (iVar1 == -1) {
      return 0xffffffff;
    }
  }
  iVar1 = *(int *)(param_1 + 4);
  local_18._0_1_ = (undefined1)param_2;
  if (iVar1 == 0) {
    if (((iVar1 == 0) && ((*(uint *)(param_1 + 0x24) & 1) == 0)) &&
       (iVar1 = (**(code **)(*(int *)(param_1 + 0x28) + 0x28))(param_1), iVar1 == -1)) {
      return 0xffffffff;
    }
    iVar1 = *(int *)(param_1 + 4);
    if (iVar1 == 0) {
      if (param_2 == -1) {
        return 0;
      }
      local_14[0] = (undefined1)local_18;
      iVar1 = FUN_0002ee5a(local_14,1,1,*(undefined4 *)(param_1 + 0x2c));
      if (iVar1 != 1) {
        return 0xffffffff;
      }
      iVar1 = FUN_00028eab(*(undefined4 *)(param_1 + 0x2c));
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      return 0;
    }
  }
  else if (*(uint *)(param_1 + 0x18) < *(uint *)(param_1 + 0x20)) goto LAB_00029a56;
  *(int *)(param_1 + 0x18) = iVar1;
  *(int *)(param_1 + 0x20) = iVar1;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 8);
LAB_00029a56:
  iVar1 = param_2;
  if ((param_2 != -1) &&
     (iVar1 = param_2, *(undefined1 **)(param_1 + 0x20) < *(undefined1 **)(param_1 + 0x1c))) {
    **(undefined1 **)(param_1 + 0x20) = (undefined1)local_18;
    local_18 = -1;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    iVar1 = local_18;
  }
  local_18 = iVar1;
  iVar1 = *(int *)(param_1 + 0x20) - *(int *)(param_1 + 0x18);
  if (0 < iVar1) {
    iVar2 = FUN_0002ee5a(*(int *)(param_1 + 0x18),1,iVar1,*(undefined4 *)(param_1 + 0x2c));
    if (iVar2 == -1) {
      return 0xffffffff;
    }
    iVar1 = iVar1 - iVar2;
    if (iVar1 < 1) {
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
    }
    else {
      FUN_0002f03a(*(int *)(param_1 + 0x18),*(int *)(param_1 + 0x18) + iVar2,iVar1);
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + iVar1;
    }
  }
  if (local_18 != -1) {
    if (*(undefined1 **)(param_1 + 0x1c) <= *(undefined1 **)(param_1 + 0x20)) {
      return 0xffffffff;
    }
    **(undefined1 **)(param_1 + 0x20) = (undefined1)local_18;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  iVar2 = FUN_00028eab(*(undefined4 *)(param_1 + 0x2c));
  if ((iVar2 == 0) && (iVar1 == 0)) {
    return 0;
  }
  return 0xffffffff;
}

