
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_22f7b(uint *param_1)

{
  uint *puVar1;
  longdouble lVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
  longdouble lVar11;
  longdouble lVar12;
  float fStack_e0;
  int iStack_80;
  int iStack_7c;
  uint *puStack_4c;
  
  lVar7 = (longdouble)fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.02);
  lVar7 = (longdouble)fsin(lVar7 + (longdouble)(DAT_00040310 * (float)/*c*/0.015));
  lVar8 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.024);
  lVar9 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.031);
  fcos((longdouble)(float)(lVar7 * (longdouble)/*c*/3.0));
  fsin((longdouble)(float)(lVar7 * (longdouble)/*c*/3.0));
  fcos((longdouble)(float)(lVar8 * (longdouble)/*c*/3.0));
  fsin((longdouble)(float)(lVar8 * (longdouble)/*c*/3.0));
  fcos((longdouble)(float)(lVar9 * (longdouble)/*c*/3.0));
  fsin((longdouble)(float)(lVar9 * (longdouble)/*c*/3.0));
  lVar10 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.02456);
  lVar9 = (longdouble)/*c*/10.0;
  lVar7 = (longdouble)/*c*/20.5;
  lVar11 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.012543);
  lVar2 = (longdouble)/*c*/10.0;
  lVar8 = (longdouble)/*c*/12.5;
  fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.05);
  puStack_4c = param_1;
  for (iStack_7c = 0; iStack_7c < 0x1a; iStack_7c = iStack_7c + 1) {
    for (iStack_80 = 0; iStack_80 < 0x29; iStack_80 = iStack_80 + 1) {
      fVar4 = ((float)iStack_80 - (float)(lVar10 * lVar9 + lVar7)) * /*c*/8.0;
      fVar5 = ((float)iStack_7c * (float)/*c*/1.2 - (float)(lVar11 * lVar2 + lVar8)) *
              (float)/*c*/-8.0;
      fVar3 = 1.0 / SQRT(fVar5 * fVar5 + fVar4 * fVar4 + 62500.0);
      fVar4 = fVar4 * fVar3;
      fVar5 = fVar5 * fVar3;
      fVar6 = fVar5 * fVar5 + fVar4 * fVar4;
      fVar6 = -SQRT(fVar6 * 4096.0) / fVar6;
      fVar4 = fVar6 * fVar4;
      fVar5 = fVar6 * fVar5;
      fVar6 = fVar6 * fVar3 * 250.0;
      lVar12 = (longdouble)fpatan((longdouble)fVar4,(longdouble)fVar5);
      fStack_e0 = ABS(fVar6 * fVar6 + fVar5 * fVar5 + fVar4 * fVar4) * (float)/*c*/0.0032;
      if (0x437f0000 < (int)fStack_e0) {
        fStack_e0 = 255.0;
      }
      fVar3 = (float)((lVar12 * (longdouble)/*c*/3.0 * (longdouble)/*c*/256.0) /
                     (longdouble)/*c*/3.1415927) * /*c*/65536.0;
      fStack_e0 = fStack_e0 * /*c*/65536.0;
      *puStack_4c = (int)ROUND((DAT_00040310 * (float)/*c*/0.3 + fVar6 * /*c*/3.0) *
                               /*c*/65536.0) & 0xffffff;
      puVar1 = puStack_4c + 2;
      puStack_4c[1] = (int)ROUND(fVar3) & 0xffffff;
      puStack_4c = puStack_4c + 3;
      *puVar1 = (int)ROUND(fStack_e0) & 0xffffff;
    }
  }
  return;
}

