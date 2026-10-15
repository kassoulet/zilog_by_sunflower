
longlong FUN_00024822(uint param_1,uint param_2)

{
  if (5 < param_1) {
    return (ulonglong)param_2 << 0x20;
  }
  return CONCAT44(param_2,&DAT_0003fa08 + param_1 * 0x1a);
}

