
void FUN_0002f13b(int param_1,undefined4 param_2,undefined4 unaff_EBX,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 extraout_ECX;
  undefined4 *extraout_EDX;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  while (puVar1 != (undefined4 *)0x0) {
    thunk_FUN_00027561(puVar1,*puVar1,unaff_EBX,param_4,param_2);
    puVar1 = extraout_EDX;
    param_4 = extraout_ECX;
  }
  return;
}

