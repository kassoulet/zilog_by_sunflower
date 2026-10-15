
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm1 FUN_00021664(int *param_1,float param_2,float param_3,float param_4)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  double dVar15;
  double dVar16;
  undefined2 extraout_ST0h;
  undefined2 extraout_ST0h_00;
  longdouble lVar17;
  longdouble lVar18;
  longdouble lVar19;
  longdouble lVar20;
  longdouble lVar21;
  longdouble lVar22;
  longdouble lVar23;
  
  iVar5 = *param_1;
  iVar6 = param_1[1];
  iVar14 = 0;
  iVar7 = param_1[2];
  if (0 < iVar5) {
    param_3 = param_3 * /*c*/50.0;
    iVar12 = 0;
    pfVar13 = (float *)(iVar6 + 0x18);
    do {
      dVar15 = ftrunc(SUB108((longdouble)*pfVar13,0));
      iVar9 = (int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar15));
      dVar16 = ftrunc(SUB108((longdouble)pfVar13[1],0));
      iVar1 = (int)ROUND((longdouble)CONCAT28(extraout_ST0h_00,dVar16));
      lVar17 = (longdouble)
               fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.032 +
                    (longdouble)((double)iVar1 * /*c*/0.1));
      lVar17 = (longdouble)
               fcos(lVar17 + (longdouble)
                             (double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.02 +
                                     (longdouble)((double)iVar9 * /*c*/0.1)));
      fVar2 = (float)(lVar17 * (longdouble)param_2);
      dVar16 = (double)((longdouble)param_2 * (longdouble)/*c*/0.3);
      lVar17 = (longdouble)
               fsin((longdouble)iVar1 * (longdouble)/*c*/0.081 +
                    (longdouble)DAT_00040310 * (longdouble)/*c*/0.022);
      lVar17 = (longdouble)
               fcos(lVar17 + (longdouble)
                             (double)((longdouble)iVar9 * (longdouble)/*c*/0.071 +
                                     (longdouble)DAT_00040310 * (longdouble)/*c*/0.03));
      fVar3 = (float)(lVar17 * (longdouble)dVar16);
      lVar17 = (longdouble)
               fsin((longdouble)iVar1 * (longdouble)/*c*/0.091 +
                    (longdouble)DAT_00040310 * (longdouble)/*c*/0.052);
      lVar17 = (longdouble)
               fcos(lVar17 + (longdouble)
                             (double)((longdouble)iVar9 * (longdouble)/*c*/0.081 +
                                     (longdouble)DAT_00040310 * (longdouble)/*c*/0.01));
      fVar4 = (float)(lVar17 * (longdouble)dVar16);
      lVar17 = (longdouble)fsin((longdouble)fVar2);
      lVar18 = (longdouble)fcos((longdouble)fVar2);
      lVar19 = (longdouble)fsin((longdouble)fVar3);
      lVar20 = (longdouble)fcos((longdouble)fVar3);
      lVar21 = (longdouble)fsin((longdouble)fVar4);
      lVar22 = (longdouble)fcos((longdouble)fVar4);
      lVar23 = (longdouble)
               fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.012 -
                    (longdouble)((double)iVar1 * /*c*/0.1));
      fsin(lVar23 + (longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.01));
      lVar23 = (longdouble)
               fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.022 -
                    (longdouble)((double)iVar9 * /*c*/0.1));
      fcos(lVar23 + (longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.007));
      fVar2 = (float)(int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar15));
      lVar23 = (longdouble)
               fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.061 -
                    (longdouble)iVar1 * (longdouble)/*c*/0.02);
      lVar23 = (longdouble)
               fsin((longdouble)
                    (double)((longdouble)iVar9 * (longdouble)/*c*/0.01 +
                            (longdouble)DAT_00040310 * (longdouble)/*c*/0.012) - lVar23);
      pfVar11 = (float *)(iVar6 + iVar12);
      pfVar10 = (float *)(iVar7 + iVar12);
      do {
        fVar8 = *pfVar11 - fVar2;
        fVar3 = pfVar11[1] - (float)iVar1;
        fVar4 = fVar8 * (float)lVar18 + fVar3 * (float)lVar17;
        fVar3 = fVar8 * (float)lVar17 - fVar3 * (float)lVar18;
        *pfVar10 = fVar4 * (float)lVar20 + param_4 * fVar2;
        fVar4 = fVar4 * (float)lVar19;
        pfVar10[1] = fVar4 * (float)lVar21 + -param_4 * (float)iVar1 + fVar3 * (float)lVar22;
        pfVar11 = pfVar11 + 3;
        pfVar10[2] = (fVar3 * (float)lVar21 + (float)(lVar23 * (longdouble)param_3)) -
                     fVar4 * (float)lVar22;
        pfVar10 = pfVar10 + 3;
      } while (pfVar11 != (float *)(iVar6 + 0x54 + iVar12));
      pfVar13 = pfVar13 + 0x15;
      iVar14 = iVar14 + 7;
      iVar12 = iVar12 + 0x54;
    } while (iVar14 < iVar5);
  }
  return;
}

