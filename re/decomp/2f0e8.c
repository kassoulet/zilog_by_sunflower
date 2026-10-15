
undefined8 FUN_0002f0e8(int *param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  int *extraout_ECX;
  int iVar3;
  
  iVar1 = *(int *)(param_1[1] + 0x10);
  pcVar2 = *(code **)(param_1[1] + 0xc);
  iVar3 = *param_1 * iVar1 + param_1[2];
  while (*param_1 != 0) {
    iVar3 = iVar3 - iVar1;
    *param_1 = *param_1 + -1;
    (*pcVar2)(iVar3,0);
    param_1 = extraout_ECX;
  }
  return CONCAT44(param_2,param_1[2]);
}

