
undefined4 FUN_0002f150(void)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (DAT_0003fd9c != '\0') {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  return 0;
}

