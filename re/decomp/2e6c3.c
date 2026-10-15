
undefined8 FUN_0002e6c3(uint param_1,undefined4 param_2)

{
  byte bVar1;
  uint uVar2;
  uint extraout_EDX;
  
  bVar1 = (byte)param_1;
  FUN_000284f9(param_1 & 0xff,param_1 & 0xff);
  if (0xff < param_1) {
    uVar2 = param_1 >> 8 & 0xff;
    goto LAB_0002e71a;
  }
  if (DAT_0003ed4b < 3) {
LAB_0002e6fa:
    uVar2 = extraout_EDX;
    if (0x13 < (byte)extraout_EDX) {
LAB_0002e6ff:
      uVar2 = 0x13;
    }
  }
  else if (bVar1 == 0x50) {
    uVar2 = 0xe;
  }
  else {
    if (0x21 < bVar1) goto LAB_0002e6ff;
    if (bVar1 < 0x20) goto LAB_0002e6fa;
    uVar2 = 5;
  }
  uVar2 = *(int *)((int)&DAT_0003fd70 + (uVar2 & 0xff) + 1) >> 0x18;
LAB_0002e71a:
  FUN_000284cf(uVar2);
  return CONCAT44(param_2,0xffffffff);
}

