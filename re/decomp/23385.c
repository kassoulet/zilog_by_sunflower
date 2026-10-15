
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00023385(uint *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint *puVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  longdouble lVar17;
  longdouble lVar18;
  longdouble lVar19;
  longdouble lVar20;
  float local_bc;
  int local_58;
  int local_54;
  uint *local_8;
  
  lVar17 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.01);
  lVar18 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.02);
  lVar19 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.03);
  lVar20 = (longdouble)fcos((longdouble)(float)(lVar17 * (longdouble)/*c*/0.5));
  fVar1 = (float)lVar20;
  lVar17 = (longdouble)fsin((longdouble)(float)(lVar17 * (longdouble)/*c*/0.5));
  fVar2 = (float)lVar17;
  lVar17 = (longdouble)fcos((longdouble)(float)(lVar18 * (longdouble)/*c*/0.5));
  fVar3 = (float)lVar17;
  lVar17 = (longdouble)fsin((longdouble)(float)(lVar18 * (longdouble)/*c*/0.5));
  fVar4 = (float)lVar17;
  lVar17 = (longdouble)fcos((longdouble)(float)(lVar19 * (longdouble)/*c*/0.5));
  fVar5 = (float)lVar17;
  lVar17 = (longdouble)fsin((longdouble)(float)(lVar19 * (longdouble)/*c*/0.5));
  fVar6 = (float)lVar17;
  fVar8 = fVar2 * fVar5 + fVar1 * fVar4 * fVar6;
  fVar9 = -fVar1 * fVar5 + fVar2 * fVar4 * fVar6;
  fVar10 = fVar2 * fVar6 - fVar1 * fVar4 * fVar5;
  fVar11 = -fVar1 * fVar6 - fVar2 * fVar4 * fVar5;
  fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.05);
  local_8 = param_1;
  for (local_54 = -0xd; local_54 < 0xd; local_54 = local_54 + 1) {
    for (local_58 = -0x14; local_58 < 0x15; local_58 = local_58 + 1) {
      fVar12 = (float)(local_58 << 3);
      fVar16 = (float)local_54 * (float)/*c*/1.2 * (float)/*c*/8.0;
      fVar13 = fVar12 * fVar16;
      fVar14 = (fVar10 * 230.0 + (fVar8 + fVar12) * (fVar1 * fVar3 + fVar16)) -
               (fVar1 * fVar3 * fVar2 * fVar3 + fVar13);
      fVar15 = (fVar11 * 230.0 + (fVar9 + fVar12) * (fVar2 * fVar3 + fVar16)) -
               (fVar8 * fVar9 + fVar13);
      fVar12 = (fVar3 * fVar5 * 230.0 + (-fVar3 * fVar6 + fVar12) * (fVar4 + fVar16)) -
               (fVar10 * fVar11 + fVar13);
      fVar13 = 1.0 / SQRT(fVar12 * fVar12 + fVar15 * fVar15 + fVar14 * fVar14);
      fVar16 = (float)/*c*/10.0 / (fVar12 * fVar13);
      fVar14 = fVar16 * fVar14 * fVar13;
      fVar15 = fVar16 * fVar15 * fVar13;
      fVar12 = fVar16 * fVar12 * fVar13;
      local_bc = ABS(fVar12 * fVar12 + fVar15 * fVar15 + fVar14 * fVar14) * (float)/*c*/1.182;
      if (0x437f0000 < (int)local_bc) {
        local_bc = 255.0;
      }
      if (fVar16 < 0.0) {
        local_bc = 255.0;
      }
      fVar12 = fVar15 * /*c*/20.0 * /*c*/65536.0;
      local_bc = local_bc * /*c*/65536.0;
      *local_8 = (int)ROUND(fVar14 * /*c*/20.0 * /*c*/65536.0) & 0xffffff;
      puVar7 = local_8 + 2;
      local_8[1] = (int)ROUND(fVar12) & 0xffffff;
      local_8 = local_8 + 3;
      *puVar7 = (int)ROUND(local_bc) & 0xffffff;
    }
  }
  return;
}

