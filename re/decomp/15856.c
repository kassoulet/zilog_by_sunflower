
undefined8 FUN_00015856(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int local_1c;
  
  local_1c = 0;
  if ((DAT_000404a4 == 0) && (iVar1 = FUN_000152a4(DAT_000404a8), iVar1 == 0)) {
    FUN_000152a4(s_data_dat_0003dd8b);
  }
  if (DAT_000404a4 != 0) {
    local_1c = FUN_00015446(param_1);
  }
  if (local_1c == 0) {
    iVar1 = FUN_00023d7f(param_1,&DAT_0003dd94);
    if (iVar1 == 0) {
      uVar2 = FUN_00016031(&DAT_000404e8,s_error_opening_file_0003dd99,&DAT_0003dd97,param_1);
      uVar2 = FUN_00016031(uVar2,extraout_ECX);
      FUN_00016031(uVar2,&DAT_0003dd97);
    }
    else {
      FUN_0002402d(iVar1,0);
      DAT_00040370 = FUN_0002433b(iVar1);
      FUN_0002402d(iVar1,0,0);
      local_1c = FUN_000243a3(DAT_00040370);
      if (local_1c == 0) {
        FUN_00016031(&DAT_000404e8,s_FATAL__out_of_memory_0003ddad);
        uVar2 = FUN_00016031(&DAT_000404e8,s__allocing_0003ddcf);
        uVar2 = FUN_00024484(uVar2,DAT_00040370);
        uVar2 = FUN_00016031(uVar2,s_b_for___0003ddc7);
        uVar2 = FUN_00016031(uVar2,param_1);
        FUN_00016031(uVar2,&DAT_0003ddc3);
        FUN_0001780d(1);
      }
      iVar3 = FUN_0002413c(local_1c,1,DAT_00040370,iVar1);
      if (iVar3 != DAT_00040370) {
        uVar2 = FUN_00016031(&DAT_000404e8,s_FATAL__error_encountered_during_r_0003dddc,
                             &DAT_0003ddda,&DAT_00040374);
        uVar2 = FUN_00016031(uVar2,extraout_ECX_00);
        FUN_00016031(uVar2,&DAT_0003ddda);
        FUN_0001780d(1);
      }
      FUN_00023e42(iVar1);
    }
  }
  if (local_1c == 0) {
    uVar2 = FUN_00016031(&DAT_000404e8,s_FATAL__could_not_locate_file_0003de0c,&DAT_0003de0a,param_1
                        );
    uVar2 = FUN_00016031(uVar2,extraout_ECX_01);
    FUN_00016031(uVar2,&DAT_0003de0a);
    FUN_0001780d(1);
  }
  return CONCAT44(param_2,local_1c);
}

