
undefined4 * __regparm3 FUN_00025e97(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = param_1;
  if (param_3 != 0) {
    do {
      if (((uint)param_1 & 0x1f) == 0) break;
      *param_1 = param_2;
      param_1 = param_1 + 1;
      param_3 = param_3 - 1;
    } while (param_3 != 0);
    if (param_3 >> 2 != 0) {
      iVar2 = (param_3 >> 2) - 1;
      if (iVar2 != 0) {
        do {
          puVar1 = param_1;
          *puVar1 = param_2;
          puVar1[1] = param_2;
          puVar1[2] = param_2;
          puVar1[3] = param_2;
          if (iVar2 == 1) goto LAB_00025ed6;
          puVar1[4] = param_2;
          puVar1[5] = param_2;
          iVar2 = iVar2 + -2;
          puVar1[6] = param_2;
          puVar1[7] = param_2;
          param_1 = puVar1 + 8;
        } while (iVar2 != 0);
        puVar1 = puVar1 + 4;
LAB_00025ed6:
        param_1 = puVar1 + 4;
      }
      *param_1 = param_2;
      param_1[1] = param_2;
      param_1[2] = param_2;
      param_1[3] = param_2;
      param_1 = param_1 + 4;
    }
    param_3 = param_3 & 3;
    puVar1 = param_1;
    if (param_3 != 0) {
      *param_1 = param_2;
      puVar1 = param_1 + 1;
      if (param_3 != 1) {
        *puVar1 = param_2;
        puVar1 = param_1 + 2;
        if (param_3 != 2) {
          *puVar1 = param_2;
          puVar1 = param_1 + 3;
        }
      }
    }
  }
  return puVar1;
}

