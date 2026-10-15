
void FUN_0002fe07(undefined2 param_1,undefined4 param_2)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(CONCAT11(0x68,(char)param_1),param_2,param_1);
  FUN_000306ec();
  return;
}

