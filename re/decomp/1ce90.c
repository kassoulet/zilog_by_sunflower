
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001ce90(uint *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int iVar13;
  int iVar14;
  longdouble lVar15;
  longdouble lVar16;
  longdouble lVar17;
  longdouble lVar18;
  longdouble lVar19;
  longdouble lVar20;
  longdouble lVar21;
  longdouble lVar22;
  longdouble lVar23;
  longdouble lVar24;
  longdouble lVar25;
  longdouble lVar26;
  longdouble lVar27;
  longdouble lVar28;
  longdouble lVar29;
  longdouble lVar30;
  longdouble lVar31;
  longdouble lVar32;
  longdouble lVar33;
  longdouble lVar34;
  
  lVar15 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.013);
  lVar15 = (longdouble)
           fsin(lVar15 + (longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.012))
  ;
  lVar16 = (longdouble)fcos(lVar15 * (longdouble)/*c*/3.0);
  lVar17 = (longdouble)fsin((longdouble)(float)(lVar15 * (longdouble)/*c*/3.0));
  lVar15 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.02);
  lVar18 = (longdouble)
           fsin((longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.01) - lVar15)
  ;
  lVar15 = (longdouble)/*c*/14.0;
  lVar19 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.026);
  lVar20 = (longdouble)
           fcos((longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.013) - lVar19)
  ;
  lVar19 = (longdouble)/*c*/11.0;
  lVar21 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.09);
  lVar1 = (longdouble)/*c*/0.5;
  lVar22 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.07);
  lVar2 = (longdouble)/*c*/0.5;
  lVar23 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.02);
  lVar24 = (longdouble)
           fsin((longdouble)
                (double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.01 +
                        (longdouble)/*c*/0.3) - lVar23);
  lVar23 = (longdouble)/*c*/14.0;
  lVar25 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.026);
  lVar26 = (longdouble)
           fcos((longdouble)
                (double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.013 +
                        (longdouble)/*c*/0.3) - lVar25);
  lVar25 = (longdouble)/*c*/11.0;
  lVar27 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.05);
  lVar3 = (longdouble)/*c*/0.5;
  lVar28 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.03);
  lVar4 = (longdouble)/*c*/0.5;
  lVar29 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.01);
  lVar30 = (longdouble)
           fsin((longdouble)
                (double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.02 +
                        (longdouble)/*c*/0.3) - lVar29);
  lVar29 = (longdouble)/*c*/14.0;
  lVar31 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.036);
  lVar32 = (longdouble)
           fcos((longdouble)
                (double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.033 +
                        (longdouble)/*c*/0.3) - lVar31);
  lVar31 = (longdouble)/*c*/11.0;
  lVar33 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.07);
  lVar5 = (longdouble)/*c*/0.5;
  lVar34 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.05);
  lVar6 = (longdouble)/*c*/0.5;
  iVar14 = -0xd;
  do {
    iVar13 = -0x14;
    do {
      fVar11 = (float)iVar14 * (float)/*c*/1.2;
      fVar7 = (float)iVar13;
      fVar8 = fVar7 + (float)(lVar18 * lVar15);
      fVar9 = fVar11 + (float)(lVar20 * lVar19);
      fVar10 = fVar7 + (float)(lVar24 * lVar23);
      fVar12 = fVar11 + (float)(lVar26 * lVar25);
      fVar7 = fVar7 + (float)(lVar30 * lVar29);
      fVar11 = fVar11 + (float)(lVar32 * lVar31);
      fVar7 = (1.0 / ((fVar9 * fVar9 * (float)((longdouble)1 + lVar22 * lVar2) +
                      fVar8 * fVar8 * (float)((longdouble)1 + lVar21 * lVar1)) *
                      (float)/*c*/0.001 + (float)/*c*/0.2) -
              1.0 / ((fVar12 * fVar12 * (float)((longdouble)1 + lVar28 * lVar4) +
                     fVar10 * fVar10 * (float)((longdouble)1 + lVar27 * lVar3)) *
                     (float)/*c*/0.001 + (float)/*c*/0.2)) -
              1.0 / ((fVar11 * fVar11 * (float)((longdouble)1 + lVar34 * lVar6) +
                     fVar7 * fVar7 * (float)((longdouble)1 + lVar33 * lVar5)) * (float)/*c*/0.001
                    + (float)/*c*/0.2);
      fVar10 = fVar7 * ((float)lVar17 * fVar8 + fVar9 * (float)lVar16) * /*c*/196608.0;
      *param_1 = (int)ROUND((fVar8 * (float)lVar16 - fVar9 * (float)lVar17) * fVar7 * /*c*/196608.0)
                 & 0xffffff;
      param_1[1] = (int)ROUND(fVar10) & 0xffffff;
      iVar13 = iVar13 + 1;
      param_1[2] = 0;
      param_1 = param_1 + 3;
    } while (iVar13 < 0x15);
    iVar14 = iVar14 + 1;
  } while (iVar14 < 0xd);
  return;
}

