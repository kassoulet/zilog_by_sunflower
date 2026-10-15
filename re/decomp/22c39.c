
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm1 FUN_00022c39(uint *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  uint *puVar3;
  float fVar4;
  float fVar5;
  longdouble lVar6;
  float local_78;
  uint *local_30;
  int local_2c;
  int local_28;
  
  lVar6 = (longdouble)fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.025);
  lVar6 = (longdouble)fcos((longdouble)(DAT_00040310 * (float)/*c*/0.03) - lVar6);
  lVar6 = (longdouble)fsin(lVar6 + (longdouble)(DAT_00040310 * (float)/*c*/0.02456));
  fVar1 = (float)(lVar6 * (longdouble)/*c*/10.0 + (longdouble)/*c*/20.5);
  lVar6 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.035);
  lVar6 = (longdouble)fsin((longdouble)(DAT_00040310 * (float)/*c*/0.04) - lVar6);
  lVar6 = (longdouble)fsin(lVar6 + (longdouble)(DAT_00040310 * (float)/*c*/0.012543));
  fVar2 = (float)(lVar6 * (longdouble)/*c*/10.0 + (longdouble)/*c*/12.5);
  fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.05);
  local_30 = param_1;
  for (local_28 = 0; local_28 < 0x1a; local_28 = local_28 + 1) {
    for (local_2c = 0; local_2c < 0x29; local_2c = local_2c + 1) {
      lVar6 = (longdouble)
              fpatan((longdouble)local_28 * (longdouble)/*c*/1.2 - (longdouble)fVar2,
                     (longdouble)local_2c - (longdouble)fVar1);
      fVar4 = (float)local_2c - fVar1;
      fVar5 = (float)local_28 * (float)/*c*/1.2 - fVar2;
      local_78 = param_2 * ((float)/*c*/600.0 -
                           SQRT(fVar5 * fVar5 + fVar4 * fVar4) * (float)/*c*/50.0) +
                 (1.0 - param_2) * /*c*/256.0;
      if (0x437f0000 < (int)local_78) {
        local_78 = 255.0;
      }
      if (local_78 < 0.0) {
        local_78 = 0.0;
      }
      local_78 = local_78 * /*c*/65536.0;
      *local_30 = (int)ROUND((float)((lVar6 * (longdouble)/*c*/6.0 * (longdouble)/*c*/128.0)
                                    / (longdouble)/*c*/3.1415927) * /*c*/65536.0) & 0xffffff;
      puVar3 = local_30 + 2;
      local_30[1] = 0;
      local_30 = local_30 + 3;
      *puVar3 = (int)ROUND(local_78) & 0xffffff;
    }
  }
  return;
}

