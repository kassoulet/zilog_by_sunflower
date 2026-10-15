
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00022e0e(uint *param_1)

{
  float fVar1;
  float fVar2;
  uint *puVar3;
  float fVar4;
  float fVar5;
  longdouble lVar6;
  float local_70;
  uint *local_2c;
  int local_28;
  int local_24;
  
  lVar6 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.02456);
  fVar1 = (float)(lVar6 * (longdouble)/*c*/20.0 + (longdouble)/*c*/20.5);
  lVar6 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.012543);
  fVar2 = (float)(lVar6 * (longdouble)/*c*/10.0 + (longdouble)/*c*/12.5);
  fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.05);
  local_2c = param_1;
  for (local_24 = 0; local_24 < 0x1a; local_24 = local_24 + 1) {
    for (local_28 = 0; local_28 < 0x29; local_28 = local_28 + 1) {
      lVar6 = (longdouble)
              fpatan((longdouble)local_24 * (longdouble)/*c*/1.2 - (longdouble)fVar2,
                     (longdouble)local_28 - (longdouble)fVar1);
      fVar4 = (float)local_28 - fVar1;
      fVar5 = (float)local_24 * (float)/*c*/1.2 - fVar2;
      local_70 = (float)/*c*/600.0 - SQRT(fVar5 * fVar5 + fVar4 * fVar4) * (float)/*c*/50.0;
      if (0x437f0000 < (int)local_70) {
        local_70 = 255.0;
      }
      if (local_70 < 0.0) {
        local_70 = 0.0;
      }
      local_70 = local_70 * /*c*/65536.0;
      *local_2c = (int)ROUND((float)((lVar6 * (longdouble)/*c*/6.0 * (longdouble)/*c*/128.0)
                                    / (longdouble)/*c*/3.1415927) * /*c*/65536.0) & 0xffffff;
      puVar3 = local_2c + 2;
      local_2c[1] = 0;
      local_2c = local_2c + 3;
      *puVar3 = (int)ROUND(local_70) & 0xffffff;
    }
  }
  return;
}

