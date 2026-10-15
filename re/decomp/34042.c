
void FUN_00034042(void)

{
  bool bVar1;
  
  if (DAT_00036450 == -1) {
    return;
  }
  bVar1 = DAT_00033997 == '\0';
  if (DAT_00033997 == '\x01') {
    DAT_00033997 = 0;
    (**(code **)(DAT_0003398f + 0x14))(0x301);
    if (!bVar1) {
      return;
    }
    return;
  }
  return;
}

