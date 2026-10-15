
void FUN_0002dfe0(char *param_1)

{
  undefined1 uVar1;
  undefined1 *extraout_EDX;
  
  while (*param_1 != '\0') {
    uVar1 = FUN_0002f5bd(*param_1);
    *extraout_EDX = uVar1;
    param_1 = extraout_EDX + 1;
  }
  return;
}

