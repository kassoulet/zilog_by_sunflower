
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00025f70(float *param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = param_1[1] < _DAT_00041308;
  if (_DAT_0003fcf0 < param_1[1]) {
    bVar1 = bVar1 | 2;
  }
  if (*param_1 < _DAT_00041304) {
    bVar1 = bVar1 | 4;
  }
  if (_DAT_0003fcec < *param_1) {
    bVar1 = bVar1 | 8;
  }
  return CONCAT44(param_2,(uint)bVar1);
}

