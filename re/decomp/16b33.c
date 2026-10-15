
undefined8 thunk_FUN_00024c8f(int param_1,undefined4 param_2)

{
  int extraout_EDX;
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
LAB_00024c98:
  uVar1 = FUN_000243a3(param_1);
  if ((int)uVar1 == 0) {
    if (DAT_000411c0 != (code *)0x0) goto LAB_00024cc3;
    goto LAB_00024caf;
  }
LAB_00024cb8:
  return CONCAT44(param_2,(int)uVar1);
LAB_00024cc3:
  uVar2 = (*DAT_000411c0)((int)((ulonglong)uVar1 >> 0x20));
  param_1 = (int)((ulonglong)uVar2 >> 0x20);
  if ((int)uVar2 == 0) {
LAB_00024caf:
    if (DAT_000411bc == (code *)0x0) goto LAB_00024cb8;
    (*DAT_000411bc)();
    param_1 = extraout_EDX;
  }
  goto LAB_00024c98;
}

