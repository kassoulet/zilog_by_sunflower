
void FUN_00033900(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined1 in_CF;
  
  pcVar1 = (code *)swi(0x31);
  uVar2 = (*pcVar1)(0x100,param_2,0x800);
  if (!(bool)in_CF) {
    return;
  }
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(CONCAT11(9,(char)uVar2),&DAT_0003393c);
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(0x4c00,uVar2);
  return;
}

