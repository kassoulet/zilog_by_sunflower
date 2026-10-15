
int FUN_00029850(int param_1,undefined4 *param_2,uint unaff_EBX)

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
    uVar1 = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x14);
    if ((int)uVar1 < 1) {
      iVar2 = (**(code **)(*(int *)(param_1 + 0x28) + 0x10))(param_1);
      if (iVar2 == -1) {
        return local_18;
      }
      uVar1 = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0x14);
    }
    if ((int)unaff_EBX < (int)uVar1) {
      uVar1 = unaff_EBX;
    }
    puVar4 = *(undefined4 **)(param_1 + 0x14);
    puVar5 = local_14;
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
    local_18 = local_18 + uVar1;
    unaff_EBX = unaff_EBX - uVar1;
    local_14 = (undefined4 *)((int)local_14 + uVar1);
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar1;
  } while( true );
}

