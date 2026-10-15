
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0002ad30(float *param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*param_1 < _DAT_00041304) {
    uVar1 = 4;
  }
  if (_DAT_0003fcec < *param_1) {
    uVar1 = uVar1 | 8;
  }
  return CONCAT44(param_2,uVar1);
}

