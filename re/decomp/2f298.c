
longlong FUN_0002f298(uint param_1,int param_2,uint unaff_EBX,int param_4)

{
  if ((param_2 == 0) && (param_4 == 0)) {
    return (ulonglong)param_1 * (ulonglong)unaff_EBX;
  }
  return CONCAT44((int)((ulonglong)param_1 * (ulonglong)unaff_EBX >> 0x20) +
                  param_1 * param_4 + param_2 * unaff_EBX,
                  (int)((ulonglong)param_1 * (ulonglong)unaff_EBX));
}

