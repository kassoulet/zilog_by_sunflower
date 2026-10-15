
void __regparm3 FUN_00034a96(undefined2 param_1,undefined4 param_2,int param_3)

{
  int unaff_EDI;
  undefined2 *puVar1;
  
  puVar1 = (undefined2 *)(unaff_EDI + DAT_00033768 + 0xb8000);
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *puVar1 = param_1;
    puVar1 = puVar1 + 1;
  }
  return;
}

