
void FUN_000162e7(int param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_50;
  undefined4 local_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_28;
  undefined4 local_1c;
  
  local_1c = *(int *)(param_1 + 0x38);
  if (local_1c == 0) {
    local_1c = thunk_FUN_00024c8f(*(int *)(param_1 + 0x3c) << 3);
  }
  for (local_28 = 0; local_28 < *(int *)(param_1 + 0x3c); local_28 = local_28 + 1) {
    *(undefined4 *)(local_28 * 8 + local_1c) = 0;
    *(undefined4 *)(local_28 * 8 + local_1c + 4) = 0;
  }
  for (local_28 = 0; local_28 < *(int *)(param_1 + 0x3c); local_28 = local_28 + 1) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x34) +
                    *(int *)(*(int *)(param_1 + 0x40) + local_28 * 8 + 4) * 4);
    local_3c = 0;
    bVar3 = false;
    local_44 = *(int *)(*(int *)(param_1 + 0x34) +
                       *(int *)(*(int *)(param_1 + 0x40) + local_28 * 8) * 4);
    while (local_3c != -1) {
      iVar1 = local_44 + 1;
      local_3c = *(int *)(*(int *)(param_1 + 0x30) + local_44 * 4);
      local_44 = iVar1;
      if (local_3c != -1) {
        local_38 = 0;
        local_50 = iVar2;
        while (local_38 != -1) {
          iVar1 = local_50 + 1;
          local_38 = *(int *)(*(int *)(param_1 + 0x30) + local_50 * 4);
          local_50 = iVar1;
          if (local_3c == local_38) {
            if (bVar3) {
              *(int *)(local_28 * 8 + local_1c + 4) = local_3c;
            }
            else {
              *(int *)(local_28 * 8 + local_1c) = local_3c;
              bVar3 = true;
            }
          }
        }
      }
    }
  }
  *(int *)(param_1 + 0x38) = local_1c;
  return;
}

