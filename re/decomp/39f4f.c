
void FUN_00039f4f(undefined4 param_1,uint param_2)

{
  uint unaff_ESI;
  
  if (DAT_00039896 == 0) {
    if ((unaff_ESI < DAT_00039892) && (0xf < param_2)) {
      return;
    }
  }
  else {
    for (; DAT_00039892 <= unaff_ESI; unaff_ESI = unaff_ESI - DAT_00039896) {
    }
    if (0xf < param_2) {
      return;
    }
  }
  return;
}

