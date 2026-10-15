
undefined8 FUN_000152a4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined4 uVar3;
  undefined8 uVar4;
  int local_28;
  undefined4 local_20;
  
  iVar1 = FUN_00023d7f(param_1,&DAT_0003dcb4);
  if (iVar1 == 0) {
    FUN_00023e42(0);
    local_20 = 0;
  }
  else {
    FUN_0002402d(iVar1,0xfffffff8,2);
    FUN_0002413c(&DAT_00040394,1,8,iVar1);
    iVar2 = FUN_0002431d(&DAT_00040394,&DAT_0003dcb7,4);
    if (iVar2 == 0) {
      FUN_0002402d(iVar1,-DAT_00040398,2);
      FUN_0002413c(&DAT_00040394,1,8,iVar1);
      uVar3 = 4;
      iVar2 = FUN_0002431d(&DAT_00040394,&DAT_0003dcbc,4);
      if (iVar2 == 0) {
        uVar4 = thunk_FUN_00024c8f(DAT_00040398 * 0x24);
        DAT_000404a0 = DAT_00040398;
        for (local_28 = 0; DAT_000404a4 = (int)uVar4, local_28 < DAT_00040398;
            local_28 = local_28 + 1) {
          uVar3 = FUN_0002433b(iVar1);
          *(undefined4 *)(local_28 * 0x24 + DAT_000404a4 + 0x20) = uVar3;
          FUN_0002413c(&DAT_00040370,1,0x24,iVar1);
          FUN_0001c48f(DAT_000404a4 + local_28 * 0x24,&DAT_00040374,0x20);
          uVar3 = 1;
          FUN_0002402d(iVar1,DAT_00040370);
          uVar4 = CONCAT44(extraout_EDX,DAT_000404a4);
        }
        FUN_00023e42(iVar1,(int)((ulonglong)uVar4 >> 0x20),uVar3);
        FUN_0002437e(&DAT_000403a0,param_1);
        local_20 = 1;
      }
      else {
        FUN_00023e42(iVar1);
        local_20 = 0;
      }
    }
    else {
      FUN_00023e42(iVar1);
      local_20 = 0;
    }
  }
  return CONCAT44(param_2,local_20);
}

