
undefined8 FUN_0002ec17(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  uint uVar2;
  
  uVar2 = DAT_0003ed34;
  DAT_0003ed34 = 0;
  if (uVar2 == 0) {
    pcVar1 = (code *)swi(0x21);
    uVar2 = (*pcVar1)();
    uVar2 = uVar2 & 0xff;
  }
  return CONCAT44(param_2,uVar2);
}

