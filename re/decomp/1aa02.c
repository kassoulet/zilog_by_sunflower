
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001aa02(int *param_1)

{
  int iVar1;
  undefined4 local_80;
  undefined4 local_7c;
  float local_78;
  float local_74;
  undefined4 local_6c;
  undefined4 local_68;
  float local_64;
  float local_60;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  int local_44;
  int local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  char local_20;
  int *local_1c;
  
  if (((char)param_1[7] == '\0') || ((char)param_1[7] == '\x01')) {
    local_1c = param_1;
    FUN_000189a5(*param_1);
    FUN_00018ab4(*local_1c);
    local_44 = *(int *)(*local_1c + 0x1c);
    local_30 = *(int *)(*local_1c + 0x44);
    if ((char)local_1c[7] == '\0') {
      local_40 = *(int *)(*local_1c + 0x10);
    }
    else {
      local_40 = *(int *)(*local_1c + 0x14);
    }
    local_3c = *(int *)(*local_1c + 0x28);
    local_38 = *(undefined4 *)(*local_1c + 0x2c);
    local_34 = local_1c[5];
    local_20 = *(char *)((int)local_1c + 0x1d);
    for (local_28 = 0; local_28 < *(int *)(*local_1c + 0x2c); local_28 = local_28 + 1) {
      if (*(int *)(*(int *)(*local_1c + 0x24) + local_28 * 4) < 0) {
        local_24 = *(int *)(local_28 * 4 + local_3c);
        iVar1 = *(int *)(local_24 * 0xc + local_44);
        local_80 = *(undefined4 *)(iVar1 * 8 + local_30);
        local_7c = *(undefined4 *)(iVar1 * 8 + local_30 + 4);
        local_78 = *(float *)(iVar1 * 0xc + local_40) * /*c*/127.0 + /*c*/127.0;
        local_74 = *(float *)(iVar1 * 0xc + local_40 + 4) * /*c*/127.0 + /*c*/127.0;
        iVar1 = *(int *)(local_24 * 0xc + local_44 + 4);
        local_58 = *(undefined4 *)(iVar1 * 8 + local_30);
        local_54 = *(undefined4 *)(iVar1 * 8 + local_30 + 4);
        local_50 = *(float *)(iVar1 * 0xc + local_40) * /*c*/127.0 + /*c*/127.0;
        local_4c = *(float *)(iVar1 * 0xc + local_40 + 4) * /*c*/127.0 + /*c*/127.0;
        local_2c = *(int *)(local_24 * 0xc + local_44 + 8);
        local_6c = *(undefined4 *)(local_2c * 8 + local_30);
        local_68 = *(undefined4 *)(local_2c * 8 + local_30 + 4);
        local_64 = *(float *)(local_2c * 0xc + local_40) * /*c*/127.0 + /*c*/127.0;
        local_60 = *(float *)(local_2c * 0xc + local_40 + 4) * /*c*/127.0 + /*c*/127.0;
        if (local_20 == '\0') {
          FUN_00025fc0(&local_80,local_34);
        }
        else if (local_20 == '\x01') {
          FUN_00026b90(&local_80,local_34);
        }
      }
    }
  }
  return;
}

