
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001d200(uint *param_1)

{
  longdouble lVar1;
  longdouble lVar2;
  longdouble lVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  longdouble lVar11;
  longdouble lVar12;
  longdouble lVar13;
  longdouble lVar14;
  longdouble lVar15;
  longdouble lVar16;
  longdouble lVar17;
  longdouble lVar18;
  longdouble lVar19;
  longdouble lVar20;
  
  lVar11 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.013);
  lVar11 = (longdouble)
           fsin(lVar11 + (longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.012))
  ;
  lVar12 = (longdouble)fcos(lVar11 * (longdouble)/*c*/3.0);
  lVar13 = (longdouble)fsin((longdouble)(float)(lVar11 * (longdouble)/*c*/3.0));
  lVar14 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.12);
  lVar1 = (longdouble)/*c*/0.01;
  lVar11 = (longdouble)/*c*/0.09;
  lVar15 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.02);
  lVar16 = (longdouble)
           fsin((longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.05) - lVar15)
  ;
  lVar15 = (longdouble)/*c*/6.0;
  lVar17 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.026);
  lVar18 = (longdouble)
           fcos((longdouble)(double)((longdouble)DAT_00040310 * (longdouble)/*c*/0.063) - lVar17)
  ;
  lVar17 = (longdouble)/*c*/6.0;
  lVar19 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.09);
  lVar2 = (longdouble)/*c*/0.9;
  lVar20 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.07);
  lVar3 = (longdouble)/*c*/0.9;
  iVar10 = -0xd;
  do {
    iVar8 = -0x14;
    puVar9 = param_1;
    do {
      fVar4 = (float)iVar8 + (float)(lVar16 * lVar15);
      fVar5 = (float)iVar10 * (float)/*c*/1.2 + (float)(lVar18 * lVar17);
      fVar6 = 1.0 / ((fVar5 * fVar5 * (float)((longdouble)1 + lVar20 * lVar3) +
                     fVar4 * fVar4 * (float)((longdouble)1 + lVar19 * lVar2)) * (float)/*c*/0.001
                    + (float)(lVar14 * lVar1 + lVar11));
      fVar7 = fVar6 * (fVar5 * (float)lVar12 + fVar4 * (float)lVar13) * /*c*/524288.0;
      *puVar9 = (int)ROUND((fVar4 * (float)lVar12 - fVar5 * (float)lVar13) * fVar6 * /*c*/524288.0)
                & 0xffffff;
      param_1 = puVar9 + 3;
      puVar9[1] = (int)ROUND(fVar7) & 0xffffff;
      iVar8 = iVar8 + 1;
      puVar9[2] = 0;
      puVar9 = param_1;
    } while (iVar8 < 0x15);
    iVar10 = iVar10 + 1;
  } while (iVar10 < 0xd);
  return;
}

