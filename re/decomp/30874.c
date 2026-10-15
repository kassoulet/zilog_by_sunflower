
void FUN_00030874(byte *param_1,byte *param_2)

{
  if ((DAT_00041490 != 0) && (((&DAT_00041495)[*param_2] & 1) != 0)) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    return;
  }
  *param_1 = *param_2;
  return;
}

