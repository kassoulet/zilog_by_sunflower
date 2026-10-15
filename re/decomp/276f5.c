
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000276f5(double *param_1,float *param_2)

{
  undefined4 uVar1;
  
  if ((((((ulonglong)*param_1 & 0x7fffffff00000000) == 0) && (*(int *)param_1 == 0)) ||
      ((0.0 < *param_1 && ((*param_1 <= _DAT_0003e9f8 && (_DAT_0003ea00 <= *param_1)))))) ||
     ((_DAT_0003ea08 <= *param_1 && (*param_1 <= _DAT_0003ea10)))) {
    uVar1 = 0;
    *param_2 = (float)*param_1;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

