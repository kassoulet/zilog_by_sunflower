
void FUN_0001675e(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined8 uVar4;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  local_8 = param_2;
  iVar2 = FUN_0002431d(param_2,&DAT_0003de88,4);
  if (iVar2 == 0) {
    local_c[0xf] = 0;
    local_14 = 0;
    iVar2 = 8;
    FUN_0001c48f(&local_1c,local_8,8);
    local_14 = local_14 + 8;
    local_10 = local_18;
    uVar3 = extraout_EDX;
    while (0 < local_10) {
      FUN_0001c48f(&local_1c,local_8 + local_14,8);
      local_14 = local_14 + 8;
      local_10 = local_10 + -8;
      iVar2 = FUN_0002431d(&local_1c,&DAT_0003de8d,4);
      if (iVar2 == 0) {
        *local_c = local_18;
        iVar2 = local_18 * 0xc;
        FUN_0001c48f(local_c[1],local_8 + local_14);
        local_14 = local_14 + local_18 * 0xc;
        local_10 = local_10 + local_18 * -0xc;
        uVar3 = extraout_EDX_00;
      }
      else {
        iVar2 = FUN_0002431d(&local_1c,&DAT_0003de92,4);
        if (iVar2 == 0) {
          local_c[6] = local_18;
          iVar2 = local_18 * 0xc;
          FUN_0001c48f(local_c[7],local_8 + local_14);
          local_14 = local_14 + local_18 * 0xc;
          local_10 = local_10 + local_18 * -0xc;
          uVar3 = extraout_EDX_01;
        }
        else {
          iVar2 = 4;
          uVar4 = FUN_0002431d(&local_1c,&DAT_0003de97);
          uVar3 = (undefined4)((ulonglong)uVar4 >> 0x20);
          if ((int)uVar4 == 0) {
            local_c[0xf] = local_18;
            iVar2 = local_18 << 3;
            FUN_0001c48f(local_c[0x10],local_8 + local_14);
            local_14 = local_14 + local_18 * 8;
            local_10 = local_10 + local_18 * -8;
            uVar3 = extraout_EDX_02;
          }
        }
      }
    }
    FUN_000160a9(local_c,uVar3,iVar2);
    if (local_c[0xf] != 0) {
      FUN_000162e7(local_c);
    }
  }
  else {
    pcVar1 = (code *)swi(0x10);
    (*pcVar1)(3);
    local_1c = 0x168e2;
    FUN_00016031(&DAT_000404e8,s_FATAL__attempt_to_init_corrupted_0003de9c);
    local_1c = 0x168ec;
    FUN_0001780d(1);
  }
  return;
}

