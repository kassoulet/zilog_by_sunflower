
undefined8 FUN_00030dd2(byte *param_1,undefined4 param_2)

{
  if ((DAT_00041490 != 0) && (((&DAT_00041495)[*param_1] & 1) != 0)) {
    return CONCAT44(param_2,(uint)CONCAT11(*param_1,param_1[1]));
  }
  return CONCAT44(param_2,(uint)*param_1);
}

