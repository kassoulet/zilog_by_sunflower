
void FUN_0001ac25(int *param_1)

{
  int iVar1;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined1 local_1c;
  
  local_2c = param_1;
  FUN_000189a5(*param_1);
  FUN_00018ab4(*local_2c);
  local_40 = *(int *)(*local_2c + 0x1c);
  local_3c = *(int *)(*local_2c + 0x44);
  local_38 = *(int *)(*local_2c + 0x48);
  local_34 = *(int *)(*local_2c + 0x28);
  local_30 = *(int *)(*local_2c + 0x2c);
  local_1c = *(undefined1 *)((int)local_2c + 0x1d);
  for (local_24 = 0; local_24 < local_30; local_24 = local_24 + 1) {
    local_20 = *(int *)(local_24 * 4 + local_34);
    iVar1 = *(int *)(local_20 * 0xc + local_40);
    local_7c = *(undefined4 *)(iVar1 * 8 + local_3c);
    local_78 = *(undefined4 *)(iVar1 * 8 + local_3c + 4);
    local_74 = *(undefined4 *)(iVar1 * 8 + local_38);
    iVar1 = *(int *)(local_20 * 0xc + local_40 + 4);
    local_54 = *(undefined4 *)(iVar1 * 8 + local_3c);
    local_50 = *(undefined4 *)(iVar1 * 8 + local_3c + 4);
    local_4c = *(undefined4 *)(iVar1 * 8 + local_38);
    local_28 = *(int *)(local_20 * 0xc + local_40 + 8);
    local_68 = *(undefined4 *)(local_28 * 8 + local_3c);
    local_64 = *(undefined4 *)(local_28 * 8 + local_3c + 4);
    local_60 = *(undefined4 *)(local_28 * 8 + local_38);
    FUN_00027128(&local_7c);
  }
  return;
}

