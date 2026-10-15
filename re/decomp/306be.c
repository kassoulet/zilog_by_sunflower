
undefined8 FUN_000306be(byte *param_1,undefined4 param_2)

{
  if (((DAT_00041490 != 0) && (((&DAT_00041495)[*param_1] & 1) != 0)) && (param_1[1] != 0)) {
    return CONCAT44(param_2,param_1 + 2);
  }
  return CONCAT44(param_2,param_1 + 1);
}

