
undefined4 FUN_0002f18b(ushort *param_1,byte *param_2,uint unaff_EBX)

{
  if (param_2 == (byte *)0x0) {
    return 0;
  }
  if (unaff_EBX != 0) {
    if (*param_2 == 0) {
      if (param_1 == (ushort *)0x0) {
        return 0;
      }
      *param_1 = 0;
      return 0;
    }
    if (((DAT_00041490 == 0) || (((&DAT_00041495)[*param_2] & 1) == 0)) || (param_2[1] != 0)) {
      if (((DAT_00041490 != 0) && (((&DAT_00041495)[*param_2] & 1) != 0)) && (1 < unaff_EBX)) {
        if (param_1 != (ushort *)0x0) {
          *param_1 = CONCAT11(*param_2,param_2[1]);
        }
        return 2;
      }
      if ((DAT_00041490 == 0) || (((&DAT_00041495)[*param_2] & 1) == 0)) {
        if (param_1 != (ushort *)0x0) {
          *param_1 = (ushort)*param_2;
        }
        return 1;
      }
    }
  }
  return 0xffffffff;
}

