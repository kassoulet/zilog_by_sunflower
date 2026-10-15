
longlong FUN_00029c69(int param_1,uint param_2,undefined4 unaff_EBX,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x20) != *(int *)(param_1 + 0x18)) {
    uVar1 = (**(code **)(*(int *)(param_1 + 0x28) + 0xc))
                      (param_1,0xffffffff,unaff_EBX,*(int *)(param_1 + 0x28),param_4);
    return CONCAT44(param_2,uVar1);
  }
  if (*(int *)(param_1 + 0x10) != *(int *)(param_1 + 0x14)) {
    return CONCAT44(param_2,0xffffffff);
  }
  return (ulonglong)param_2 << 0x20;
}

