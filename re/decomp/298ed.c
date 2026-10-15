
int FUN_000298ed(int param_1,undefined4 *param_2,uint unaff_EBX)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  byte bVar6;
  int local_18;
  undefined4 *local_14;
  
  bVar6 = 0;
  local_18 = 0;
  local_14 = param_2;
  do {
    if ((int)unaff_EBX < 1) {
      return local_18;
    }
    if (*(int *)(param_1 + 0x18) == 0) {
      iVar2 = (**(code **)(*(int *)(param_1 + 0x28) + 0xc))(param_1,*(undefined1 *)local_14);
      if (iVar2 == -1) {
        return local_18;
      }
      uVar1 = 1;
    }
    else {
      uVar1 = *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x20);
      if ((int)uVar1 < 1) {
        iVar2 = (**(code **)(*(int *)(param_1 + 0x28) + 0xc))(param_1,0xffffffff);
        if (iVar2 == -1) {
          return local_18;
        }
        uVar1 = *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x20);
      }
      if ((int)unaff_EBX < (int)uVar1) {
        uVar1 = unaff_EBX;
      }
      puVar4 = local_14;
      puVar5 = *(undefined4 **)(param_1 + 0x20);
      for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + (uint)bVar6 * -2 + 1;
        puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
      }
      for (uVar3 = uVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
        puVar4 = (undefined4 *)((int)puVar4 + (uint)bVar6 * -2 + 1);
        puVar5 = (undefined4 *)((int)puVar5 + (uint)bVar6 * -2 + 1);
      }
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + uVar1;
    }
    local_18 = local_18 + uVar1;
    local_14 = (undefined4 *)((int)local_14 + uVar1);
    unaff_EBX = unaff_EBX - uVar1;
  } while( true );
}

