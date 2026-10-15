
/* WARNING: Removing unreachable block (ram,0x000154c4) */

undefined8 FUN_00015446(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 extraout_ECX;
  int local_24;
  undefined4 local_20;
  
  bVar1 = false;
  local_24 = 0;
  while ((local_24 < DAT_000404a0 && (!bVar1))) {
    iVar3 = thunk_FUN_00028ebb(DAT_000404a4 + local_24 * 0x24,param_1);
    if (iVar3 == 0) {
      bVar1 = true;
      local_20 = *(undefined4 *)(local_24 * 0x24 + DAT_000404a4 + 0x20);
    }
    local_24 = local_24 + 1;
  }
  uVar2 = FUN_00023d7f(&DAT_000403a0,&DAT_0003dcc1);
  FUN_0002402d(uVar2,local_20,0);
  FUN_0002413c(&DAT_00040370,1,0x24,uVar2);
  iVar3 = FUN_000243a3(DAT_00040370);
  if (iVar3 == 0) {
    FUN_00016031(&DAT_000404e8,s_FATAL__out_of_memory_0003dcc4);
    uVar4 = FUN_00016031(&DAT_000404e8,s__allocing_0003dce6);
    uVar4 = FUN_00024484(uVar4,DAT_00040370);
    uVar4 = FUN_00016031(uVar4,s_b_for___0003dcde);
    uVar4 = FUN_00016031(uVar4,param_1);
    FUN_00016031(uVar4,&DAT_0003dcda);
    FUN_0001780d(1);
  }
  iVar5 = FUN_0002413c(iVar3,1,DAT_00040370,uVar2);
  if (iVar5 != DAT_00040370) {
    uVar4 = FUN_00016031(&DAT_000404e8,s_FATAL__error_encountered_during_r_0003dcf3,&DAT_0003dcf1,
                         &DAT_00040374);
    uVar4 = FUN_00016031(uVar4,extraout_ECX);
    FUN_00016031(uVar4,&DAT_0003dcf1);
    FUN_0001780d(1);
  }
  FUN_00023e42(uVar2);
  return CONCAT44(param_2,iVar3);
}

