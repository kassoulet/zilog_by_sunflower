
undefined8 __regparm2
FUN_0002fcdb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 *param_6,undefined4 *param_7,int param_8,
            undefined4 param_9)

{
  undefined4 extraout_ECX;
  undefined4 local_58;
  uint local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  longdouble local_2c;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  local_20 = param_3;
  uStack_1c = param_4;
  local_2c = (longdouble)(double)CONCAT44(param_4,param_3);
  if (param_8 != 0x46) {
    local_50 = 0xc;
  }
  else {
    local_50 = 10;
  }
  local_54 = (uint)(param_8 != 0x46);
  local_58 = param_5;
  local_48 = 0;
  local_4c = param_8;
  FUN_000278a1(&local_2c,&local_58,param_9);
  *param_6 = local_40;
  *param_7 = local_44;
  return CONCAT44(param_2,extraout_ECX);
}

