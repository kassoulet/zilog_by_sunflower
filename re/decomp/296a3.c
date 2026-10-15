
undefined4 FUN_000296a3(uint param_1)

{
  param_1 = param_1 & 0x70;
  if (param_1 != 0x10) {
    if (param_1 == 0x20) {
      return 8;
    }
    if (param_1 == 0x40) {
      return 0x10;
    }
  }
  return 10;
}

