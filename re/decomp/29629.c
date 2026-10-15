
longlong FUN_00029629(uint *param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *param_1 + 7 & 0xfffffff8;
  if (uVar1 != 0) {
    if (((DAT_0003ed42 == '\x01') && (DAT_0003ed43 == '\0')) || (DAT_0003ed42 == '\t')) {
      uVar1 = uVar1 + 8;
    }
    else {
      uVar2 = FUN_00029312();
      uVar1 = (int)((ulonglong)uVar2 >> 0x20) - (int)uVar2;
    }
    *param_1 = uVar1;
    uVar1 = uVar1 + 0x3c;
    if (*param_1 <= uVar1) {
      if (uVar1 < DAT_0003fd90) {
        uVar1 = DAT_0003fd90 & 0xfffffffe;
      }
      *param_1 = uVar1;
      if (*param_1 <= uVar1 + 0xfff) {
        uVar1 = uVar1 + 0xfff >> 8 & 0xfffff0;
        *param_1 = uVar1 << 8;
        return CONCAT44(param_2,(uint)(uVar1 != 0));
      }
    }
  }
  return (ulonglong)param_2 << 0x20;
}

