
undefined4 thunk_FUN_00023af0(undefined1 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_00024e5a(0,0xf);
  pcVar1 = (code *)swi(0x21);
  uVar2 = (*pcVar1)(CONCAT11(0x4c,param_1));
  return uVar2;
}

