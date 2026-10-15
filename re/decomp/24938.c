
undefined4 FUN_00024938(int *param_1,undefined4 *param_2,uint unaff_EBX,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  byte bVar7;
  undefined4 local_1c;
  undefined4 *local_18;
  uint local_14;
  uint local_10;
  
  bVar7 = 0;
  local_1c = 0;
  local_10 = *(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x1c) - unaff_EBX;
  local_18 = (undefined4 *)0x0;
  if (0 < (int)local_10) {
    local_18 = (undefined4 *)thunk_FUN_00024c8f();
    if (local_18 == (undefined4 *)0x0) {
      local_10 = 0;
    }
    else {
      FUN_00017e46(local_18,*(undefined1 *)((int)param_1 + *(int *)(*param_1 + 4) + 0x24),local_10);
    }
  }
  iVar1 = *(int *)((int)param_1 + *(int *)(*param_1 + 4) + 4);
  uVar3 = *(uint *)((int)param_1 + *(int *)(*param_1 + 4) + 0xc);
  if ((uVar3 & 2) == 0) {
    uVar2 = local_14;
    if ((uVar3 & 8) == 0) {
      if (0 < (int)local_10) {
        local_14 = local_10;
        if ((int)local_10 < *(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x20)) {
          puVar5 = local_18;
          puVar6 = *(undefined4 **)(iVar1 + 0x20);
          for (uVar3 = local_10 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + (uint)bVar7 * -2 + 1;
            puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
          }
          for (uVar3 = local_10 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
            puVar5 = (undefined4 *)((int)puVar5 + (uint)bVar7 * -2 + 1);
            puVar6 = (undefined4 *)((int)puVar6 + (uint)bVar7 * -2 + 1);
          }
          *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + local_10;
          uVar2 = local_10;
        }
        else {
          uVar2 = (**(code **)(*(int *)(iVar1 + 0x28) + 4))(iVar1,local_18,local_10);
        }
      }
      if (uVar2 != local_14) goto LAB_00024a15;
      if (*(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x20) <= (int)unaff_EBX) {
        iVar4 = *(int *)(iVar1 + 0x28);
        local_14 = unaff_EBX;
        goto LAB_00024aa3;
      }
      puVar5 = *(undefined4 **)(iVar1 + 0x20);
      for (uVar3 = unaff_EBX >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = *param_2;
        param_2 = param_2 + (uint)bVar7 * -2 + 1;
        puVar5 = puVar5 + (uint)bVar7 * -2 + 1;
      }
      for (uVar3 = unaff_EBX & 3; local_14 = unaff_EBX, uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar5 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + (uint)bVar7 * -2 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + (uint)bVar7 * -2 + 1);
      }
    }
    else {
      if (0 < (int)param_4) {
        local_14 = param_4;
        if ((int)param_4 < *(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x20)) {
          puVar5 = param_2;
          puVar6 = *(undefined4 **)(iVar1 + 0x20);
          for (uVar3 = param_4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + (uint)bVar7 * -2 + 1;
            puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
          }
          for (uVar3 = param_4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
            puVar5 = (undefined4 *)((int)puVar5 + (uint)bVar7 * -2 + 1);
            puVar6 = (undefined4 *)((int)puVar6 + (uint)bVar7 * -2 + 1);
          }
          *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + param_4;
          uVar2 = param_4;
        }
        else {
          uVar2 = (**(code **)(*(int *)(iVar1 + 0x28) + 4))(iVar1,param_2,param_4);
        }
      }
      if ((uVar2 == local_14) && (0 < (int)local_10)) {
        local_14 = local_10;
        if ((int)local_10 < *(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x20)) {
          puVar5 = local_18;
          puVar6 = *(undefined4 **)(iVar1 + 0x20);
          for (uVar3 = local_10 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar6 = *puVar5;
            puVar5 = puVar5 + (uint)bVar7 * -2 + 1;
            puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
          }
          for (uVar3 = local_10 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
            puVar5 = (undefined4 *)((int)puVar5 + (uint)bVar7 * -2 + 1);
            puVar6 = (undefined4 *)((int)puVar6 + (uint)bVar7 * -2 + 1);
          }
          *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + local_10;
          uVar2 = local_10;
        }
        else {
          uVar2 = (**(code **)(*(int *)(iVar1 + 0x28) + 4))(iVar1,local_18,local_10);
        }
      }
      if (uVar2 != local_14) goto LAB_00024a15;
      local_14 = unaff_EBX - param_4;
      param_2 = (undefined4 *)((int)param_2 + param_4);
      if (*(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x20) <= (int)local_14) {
        iVar4 = *(int *)(iVar1 + 0x28);
LAB_00024aa3:
        uVar2 = (**(code **)(iVar4 + 4))(iVar1,param_2,local_14);
        goto LAB_00024a15;
      }
      puVar5 = *(undefined4 **)(iVar1 + 0x20);
      for (uVar3 = local_14 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = *param_2;
        param_2 = param_2 + (uint)bVar7 * -2 + 1;
        puVar5 = puVar5 + (uint)bVar7 * -2 + 1;
      }
      for (uVar3 = local_14 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar5 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + (uint)bVar7 * -2 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + (uint)bVar7 * -2 + 1);
      }
    }
  }
  else {
    if ((int)unaff_EBX < *(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x20)) {
      puVar5 = *(undefined4 **)(iVar1 + 0x20);
      for (uVar3 = unaff_EBX >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = *param_2;
        param_2 = param_2 + (uint)bVar7 * -2 + 1;
        puVar5 = puVar5 + (uint)bVar7 * -2 + 1;
      }
      for (uVar3 = unaff_EBX & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar5 = *(undefined1 *)param_2;
        param_2 = (undefined4 *)((int)param_2 + (uint)bVar7 * -2 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + (uint)bVar7 * -2 + 1);
      }
      *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + unaff_EBX;
      uVar2 = unaff_EBX;
    }
    else {
      uVar2 = (**(code **)(*(int *)(iVar1 + 0x28) + 4))(iVar1,param_2,unaff_EBX);
    }
    local_14 = unaff_EBX;
    if ((uVar2 != unaff_EBX) || ((int)local_10 < 1)) goto LAB_00024a15;
    local_14 = local_10;
    if (*(int *)(iVar1 + 0x1c) - *(int *)(iVar1 + 0x20) <= (int)local_10) {
      iVar4 = *(int *)(iVar1 + 0x28);
      param_2 = local_18;
      goto LAB_00024aa3;
    }
    puVar5 = local_18;
    puVar6 = *(undefined4 **)(iVar1 + 0x20);
    for (uVar3 = local_10 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + (uint)bVar7 * -2 + 1;
      puVar6 = puVar6 + (uint)bVar7 * -2 + 1;
    }
    for (local_10 = local_10 & 3; local_10 != 0; local_10 = local_10 - 1) {
      *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
      puVar5 = (undefined4 *)((int)puVar5 + (uint)bVar7 * -2 + 1);
      puVar6 = (undefined4 *)((int)puVar6 + (uint)bVar7 * -2 + 1);
    }
  }
  *(int *)(iVar1 + 0x20) = *(int *)(iVar1 + 0x20) + local_14;
  uVar2 = local_14;
LAB_00024a15:
  if (uVar2 != local_14) {
    local_1c = 2;
  }
  if (local_18 != (undefined4 *)0x0) {
    thunk_FUN_00023831(local_18);
  }
  *(undefined4 *)((int)param_1 + *(int *)(*param_1 + 4) + 0x1c) = 0;
  return local_1c;
}

