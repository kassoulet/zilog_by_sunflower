
uint FUN_000314ae(uint param_1)

{
  if (DAT_00041490 == 0) {
    param_1 = 0;
  }
  else {
    if (DAT_0003ff10 == 0x3a4) {
      return (uint)((&DAT_00040181)[param_1 & 0xff] & 8);
    }
    if (param_1 != 0) {
      return 1;
    }
  }
  return param_1;
}

