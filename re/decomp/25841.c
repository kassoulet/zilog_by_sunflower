
void FUN_00025841(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)(0x4f05,DAT_0003f5dc,0);
  pcVar1 = (code *)swi(0x10);
  (*pcVar1)(0x4f05,DAT_0003f5dc,1);
  return;
}

