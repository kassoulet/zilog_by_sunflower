
void FUN_00024717(void)

{
  uint uVar1;
  int unaff_EBP;
  
  uVar1 = (uint)DAT_0003eecc;
  *(undefined1 *)(unaff_EBP + 2 + uVar1 * 3) = DAT_0003eed5;
  *(undefined2 *)(unaff_EBP + uVar1 * 3) = DAT_0003eec8;
  DAT_0003eecc = DAT_0003eecc + 1;
  return;
}

