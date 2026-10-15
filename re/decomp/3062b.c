
longlong FUN_0003062b(byte *param_1,uint param_2)

{
  if (*param_1 == 0) {
    return CONCAT44(param_2,1);
  }
  if (((DAT_00041490 != 0) && (((&DAT_00041495)[*param_1] & 1) != 0)) && (param_1[1] == 0)) {
    return CONCAT44(param_2,2);
  }
  return (ulonglong)param_2 << 0x20;
}

