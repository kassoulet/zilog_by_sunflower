
undefined4 FUN_00034009(void)

{
  undefined4 uVar1;
  undefined4 unaff_ESI;
  bool bVar2;
  
  uVar1 = 0x301;
  if (DAT_00036450 != -1) {
    uVar1 = 0x302;
    bVar2 = false;
    if (DAT_00033997 == '\0') {
      DAT_00033997 = '\x01';
      DAT_00033998 = unaff_ESI;
      uVar1 = (**(code **)(DAT_0003398f + 0x10))(0x302);
      if (!bVar2) {
        return uVar1;
      }
    }
  }
  return uVar1;
}

