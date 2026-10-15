
undefined8 FUN_000248a3(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *extraout_ECX;
  undefined4 extraout_ECX_00;
  
  if (*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 0x10) == 0) {
    iVar1 = (**(code **)(*(int *)(*(int *)((int)param_1 + *(int *)(*param_1 + 4) + 4) + 0x28) + 0x20
                        ))();
    param_1 = extraout_ECX;
    if (iVar1 == -1) {
      FUN_00024c72(*(int *)(*extraout_ECX + 4) + (int)extraout_ECX,2);
      return CONCAT44(param_2,extraout_ECX_00);
    }
  }
  return CONCAT44(param_2,param_1);
}

