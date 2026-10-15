
void FUN_00024017(undefined4 *param_1)

{
  undefined4 uVar1;
  
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xef;
  uVar1 = *(undefined4 *)(param_1[2] + 8);
  param_1[1] = 0;
  *param_1 = uVar1;
  return;
}

