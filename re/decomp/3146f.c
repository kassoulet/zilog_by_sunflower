
longlong FUN_0003146f(uint param_1,uint param_2)

{
  int iVar1;
  
  if ((DAT_00041490 != 0) && (((&DAT_00041495)[param_1 >> 8 & 0xff] & 1) != 0)) {
    iVar1 = FUN_000314ae(param_1 & 0xff);
    if (iVar1 != 0) {
      return CONCAT44(param_2,1);
    }
  }
  return (ulonglong)param_2 << 0x20;
}

