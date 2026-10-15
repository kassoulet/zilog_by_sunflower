
void FUN_00027769(longdouble *param_1,uint param_2)

{
  longdouble *plVar1;
  
  if (0x1fff < (int)param_2) {
    param_2 = 0x2000;
  }
  plVar1 = (longdouble *)&DAT_0003f978;
  for (; 0 < (int)param_2; param_2 = (int)param_2 >> 1) {
    if ((param_2 & 1) != 0) {
      *param_1 = *plVar1 * *param_1;
    }
    plVar1 = (longdouble *)((int)plVar1 + 10);
  }
  return;
}

