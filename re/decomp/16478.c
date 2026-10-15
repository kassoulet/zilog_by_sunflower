
undefined8 FUN_00016478(int param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined8 uVar4;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int *local_1c;
  
  local_24 = param_1;
  iVar2 = FUN_0002431d(param_1,&DAT_0003de49,4);
  if (iVar2 == 0) {
    local_1c = (int *)FUN_00024c8f(0x54);
    *local_1c = 0;
    local_1c[1] = 0;
    local_1c[2] = 0;
    local_1c[3] = 0;
    local_1c[4] = 0;
    local_1c[5] = 0;
    local_1c[6] = 0;
    local_1c[7] = 0;
    local_1c[8] = 0;
    local_1c[9] = 0;
    local_1c[10] = 0;
    local_1c[0xb] = 0;
    local_1c[0xc] = 0;
    local_1c[0xd] = 0;
    local_1c[0xe] = 0;
    local_1c[0xf] = 0;
    local_1c[0x10] = 0;
    local_1c[0x11] = 0;
    local_1c[0x12] = 0;
    local_1c[0x13] = 0;
    local_1c[0x14] = 0;
    local_2c = 0;
    iVar2 = 8;
    FUN_0001c48f(&local_34,local_24,8);
    local_2c = local_2c + 8;
    local_28 = local_30;
    uVar3 = extraout_EDX;
    while (0 < local_28) {
      FUN_0001c48f(&local_34,local_24 + local_2c,8);
      local_2c = local_2c + 8;
      local_28 = local_28 + -8;
      iVar2 = FUN_0002431d(&local_34,&DAT_0003de4e,4);
      if (iVar2 == 0) {
        *local_1c = local_30;
        iVar2 = thunk_FUN_00024c8f(local_30 * 0xc);
        local_1c[1] = iVar2;
        iVar2 = thunk_FUN_00024c8f(local_30 * 0xc);
        local_1c[2] = iVar2;
        iVar2 = thunk_FUN_00024c8f(local_30 << 3);
        local_1c[0x11] = iVar2;
        iVar2 = local_30 * 0xc;
        FUN_0001c48f(local_1c[1],local_24 + local_2c);
        local_2c = local_2c + local_30 * 0xc;
        local_28 = local_28 + local_30 * -0xc;
        uVar3 = extraout_EDX_00;
      }
      else {
        iVar2 = FUN_0002431d(&local_34,&DAT_0003de53,4);
        if (iVar2 == 0) {
          local_1c[6] = local_30;
          iVar2 = thunk_FUN_00024c8f(local_30 * 0xc);
          local_1c[7] = iVar2;
          iVar2 = thunk_FUN_00024c8f(local_30 << 2);
          local_1c[0x13] = iVar2;
          iVar2 = local_30 * 0xc;
          FUN_0001c48f(local_1c[7],local_24 + local_2c);
          local_2c = local_2c + local_30 * 0xc;
          local_28 = local_28 + local_30 * -0xc;
          uVar3 = extraout_EDX_01;
        }
        else {
          iVar2 = 4;
          uVar4 = FUN_0002431d(&local_34,&DAT_0003de58);
          uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
          if ((int)uVar4 == 0) {
            local_1c[0xf] = local_30;
            iVar2 = thunk_FUN_00024c8f(local_30 << 3);
            local_1c[0x10] = iVar2;
            iVar2 = local_30 << 3;
            FUN_0001c48f(local_1c[0x10],local_24 + local_2c);
            local_2c = local_2c + local_30 * 8;
            local_28 = local_28 + local_30 * -8;
            uVar3 = extraout_EDX_02;
          }
        }
      }
    }
    FUN_000160a9(local_1c,uVar3,iVar2);
    if (local_1c[0xf] != 0) {
      FUN_000162e7(local_1c);
    }
  }
  else {
    pcVar1 = (code *)swi(0x10);
    (*pcVar1)(3);
    local_34 = 0x1673e;
    FUN_00016031(&DAT_000404e8,s_FATAL__attempt_to_init_corrupted_0003de5d);
    local_34 = 0x16748;
    FUN_0001780d(1);
  }
  return CONCAT44(param_2,local_1c);
}

