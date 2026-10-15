
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00021290(int *param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  float fVar10;
  float fVar11;
  float *pfVar12;
  float *pfVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  double dVar17;
  undefined2 extraout_ST0h;
  longdouble lVar18;
  longdouble lVar19;
  longdouble lVar20;
  longdouble lVar21;
  longdouble lVar22;
  longdouble lVar23;
  longdouble lVar24;
  
  iVar4 = *param_1;
  iVar5 = param_1[1];
  iVar16 = 0;
  iVar6 = param_1[2];
  if (0 < iVar4) {
    iVar14 = 0;
    iVar15 = iVar5;
    do {
      dVar17 = ftrunc(SUB108((longdouble)*(float *)(iVar15 + 8) + (longdouble)/*c*/-500.0,0));
      iVar1 = (int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar17));
      lVar18 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.01);
      lVar19 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.032);
      lVar19 = (longdouble)
               fcos(lVar19 + (longdouble)
                             (double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.02));
      lVar19 = lVar19 + (longdouble)(double)(lVar18 * (longdouble)iVar1 * (longdouble)/*c*/0.01)
      ;
      lVar20 = (longdouble)fsin(lVar19);
      lVar21 = (longdouble)fcos((longdouble)(float)lVar19);
      lVar18 = (longdouble)fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.01);
      lVar19 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.13);
      fVar2 = (float)(lVar19 * (longdouble)
                               (double)(lVar18 * (longdouble)/*c*/10.0 * (longdouble)iVar1 *
                                       (longdouble)/*c*/0.004));
      lVar18 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.07);
      fVar3 = (float)(lVar18 * (longdouble)/*c*/10.0 * (longdouble)iVar1 *
                     (longdouble)/*c*/0.004);
      lVar22 = (longdouble)
               fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.033 -
                    (longdouble)((double)iVar1 * /*c*/0.0001));
      lVar18 = (longdouble)/*c*/0.7;
      lVar19 = (longdouble)/*c*/0.01;
      lVar23 = (longdouble)
               fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.014 -
                    (longdouble)((double)iVar1 * /*c*/0.0001));
      lVar7 = (longdouble)/*c*/0.7;
      lVar8 = (longdouble)/*c*/0.01;
      lVar24 = (longdouble)
               fcos((longdouble)iVar1 * (longdouble)/*c*/0.008 +
                    (longdouble)DAT_00040310 * (longdouble)/*c*/0.04);
      lVar9 = (longdouble)/*c*/200.0;
      pfVar12 = (float *)(iVar5 + iVar14);
      pfVar13 = (float *)(iVar6 + iVar14);
      do {
        fVar10 = (*pfVar12 - fVar2) * (float)(lVar22 * lVar18 * (longdouble)iVar1 * lVar19);
        fVar11 = (pfVar12[1] - fVar3) * (float)(lVar23 * lVar7 * (longdouble)iVar1 * lVar8);
        *pfVar13 = fVar11 * (float)lVar20 + fVar10 * (float)lVar21 + fVar2;
        pfVar13[2] = (float)(lVar24 * lVar9);
        pfVar12 = pfVar12 + 3;
        pfVar13[1] = (fVar10 * (float)lVar20 + fVar3) - fVar11 * (float)lVar21;
        pfVar13 = pfVar13 + 3;
      } while (pfVar12 != (float *)(iVar5 + 0x6c + iVar14));
      iVar15 = iVar15 + 0x6c;
      iVar16 = iVar16 + 9;
      iVar14 = iVar14 + 0x6c;
    } while (iVar16 < iVar4);
  }
  return;
}

