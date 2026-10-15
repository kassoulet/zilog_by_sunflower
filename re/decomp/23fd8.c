
undefined4 FUN_00023fd8(int param_1,int *param_2)

{
  if ((param_1 <= param_2[1]) && (*(int *)(param_2[2] + 8) - *param_2 <= param_1)) {
    *(byte *)(param_2 + 3) = *(byte *)(param_2 + 3) & 0xef;
    *param_2 = *param_2 + param_1;
    param_2[1] = param_2[1] - param_1;
    return 0;
  }
  return 1;
}

