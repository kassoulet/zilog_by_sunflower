
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001d3d8(uint *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  longdouble lVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
  longdouble lVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  int iVar16;
  int iVar17;
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
  
  lVar18 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.013);
  lVar18 = (longdouble)
           fsin(lVar18 + (longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.012))
  ;
  lVar19 = (longdouble)fcos(lVar18 * (longdouble)/*c*/3.0);
  lVar20 = (longdouble)fsin((longdouble)(float)(lVar18 * (longdouble)/*c*/3.0));
  lVar21 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.12);
  lVar2 = (longdouble)/*c*/0.01;
  lVar18 = (longdouble)/*c*/0.3;
  lVar22 = (longdouble)fsin((longdouble)/*c*/0.02 * (longdouble)DAT_00040310);
  lVar23 = (longdouble)
           fsin((longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.02) - lVar22)
  ;
  lVar3 = (longdouble)/*c*/16.0;
  lVar22 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.026);
  lVar24 = (longdouble)
           fcos((longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.033) - lVar22)
  ;
  lVar4 = (longdouble)/*c*/16.0;
  lVar25 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.09);
  lVar5 = (longdouble)/*c*/0.9;
  lVar26 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.07);
  lVar6 = (longdouble)/*c*/0.1;
  lVar22 = (longdouble)/*c*/0.5;
  lVar27 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.12);
  lVar7 = (longdouble)/*c*/0.01;
  lVar1 = (longdouble)/*c*/0.3;
  lVar28 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.04);
  lVar29 = (longdouble)
           fsin((longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.03) - lVar28)
  ;
  lVar8 = (longdouble)/*c*/16.0;
  lVar28 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.016);
  lVar30 = (longdouble)
           fcos((longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.023) - lVar28)
  ;
  lVar9 = (longdouble)/*c*/16.0;
  lVar31 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.04);
  lVar10 = (longdouble)/*c*/0.9;
  lVar32 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.05);
  lVar11 = (longdouble)/*c*/0.1;
  lVar28 = (longdouble)/*c*/0.5;
  iVar17 = -0xd;
  do {
    iVar16 = -0x14;
    do {
      fVar12 = (float)iVar16 + (float)(lVar23 * lVar3);
      fVar13 = (float)iVar17 * (float)/*c*/1.2 + (float)(lVar24 * lVar4);
      fVar14 = (float)iVar16 + (float)(lVar29 * lVar8);
      fVar15 = (float)iVar17 * (float)/*c*/1.2 + (float)(lVar30 * lVar9);
      fVar14 = (1.0 / ((fVar15 * fVar15 * (float)(lVar32 * lVar11 + lVar28) +
                       fVar14 * fVar14 * (float)((longdouble)1 + lVar31 * lVar10)) *
                       (float)/*c*/0.001 + (float)(lVar27 * lVar7 + lVar1))) *
               (fVar13 * (float)lVar19 + fVar12 * (float)lVar20) * /*c*/524288.0;
      *param_1 = (int)ROUND((DAT_00040310 * (float)/*c*/0.1 +
                            (fVar12 * (float)lVar19 - fVar13 * (float)lVar20) *
                            (1.0 / ((fVar13 * fVar13 * (float)(lVar26 * lVar6 + lVar22) +
                                    fVar12 * fVar12 * (float)((longdouble)1 + lVar25 * lVar5)) *
                                    (float)/*c*/0.001 + (float)(lVar21 * lVar2 + lVar18)))) *
                            /*c*/524288.0) & 0xffffff;
      param_1[1] = (int)ROUND(fVar14) & 0xffffff;
      iVar16 = iVar16 + 1;
      param_1[2] = 0;
      param_1 = param_1 + 3;
    } while (iVar16 < 0x15);
    iVar17 = iVar17 + 1;
  } while (iVar17 < 0xd);
  return;
}

