
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_0002ad60(int param_1,undefined4 param_2)

{
  byte bVar1;
  
  bVar1 = *(float *)(param_1 + 4) < _DAT_00041308;
  if (_DAT_0003fcf0 < *(float *)(param_1 + 4)) {
    bVar1 = bVar1 | 2;
  }
  return CONCAT44(param_2,(uint)bVar1);
}

