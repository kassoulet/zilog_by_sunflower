
int FUN_00015605(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_ECX;
  int local_20;
  int local_c;
  
  local_c = 0;
  iVar2 = FUN_00023d7f(param_2,&DAT_0003dd21);
  if (iVar2 != 0) {
    FUN_0002402d(iVar2,0xfffffff8,2);
    FUN_0002413c(&DAT_00040394,1,8,iVar2);
    iVar3 = FUN_0002431d(&DAT_00040394,&DAT_0003dd24,4);
    if (iVar3 != 0) {
      FUN_00023e42(iVar2);
      return 0;
    }
    FUN_0002402d(iVar2,-DAT_00040398,2);
    FUN_0002413c(&DAT_00040394,1,8,iVar2);
    iVar3 = FUN_0002431d(&DAT_00040394,&DAT_0003dd29,4);
    if (iVar3 != 0) {
      FUN_00023e42(iVar2);
      return 0;
    }
    local_20 = 0;
    bVar1 = false;
    while ((local_20 < DAT_00040398 && (!bVar1))) {
      local_20 = local_20 + 1;
      FUN_0002413c(&DAT_00040370,1,0x24,iVar2);
      iVar3 = thunk_FUN_00028ebb(&DAT_00040374,param_1);
      if (iVar3 == 0) {
        local_c = FUN_000243a3(DAT_00040370);
        if (local_c == 0) {
          FUN_00016031(&DAT_000404e8,s_FATAL__out_of_memory_0003dd2e);
          uVar4 = FUN_00016031(&DAT_000404e8,s__allocing_0003dd50);
          uVar4 = FUN_00024484(uVar4,DAT_00040370);
          uVar4 = FUN_00016031(uVar4,s_b_for___0003dd48);
          uVar4 = FUN_00016031(uVar4,param_1);
          FUN_00016031(uVar4,&DAT_0003dd44);
          FUN_0001780d(1);
        }
        iVar3 = FUN_0002413c(local_c,1,DAT_00040370,iVar2);
        if (iVar3 != DAT_00040370) {
          uVar4 = FUN_00016031(&DAT_000404e8,s_FATAL__error_encountered_during_r_0003dd5d,
                               &DAT_0003dd5b,&DAT_00040374);
          uVar4 = FUN_00016031(uVar4,extraout_ECX);
          FUN_00016031(uVar4,&DAT_0003dd5b);
          FUN_0001780d(1);
        }
        bVar1 = true;
      }
      else {
        FUN_0002402d(iVar2,DAT_00040370,1);
      }
    }
    FUN_00023e42(iVar2);
  }
  return local_c;
}

