
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm1 FUN_0001b533(int *param_1,float param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
  longdouble lVar11;
  longdouble lVar12;
  float local_20;
  int local_1c;
  
  if (param_1[0x12] == 0) {
    iVar6 = thunk_FUN_00024c8f(*param_1 << 3);
    param_1[0x12] = iVar6;
  }
  lVar7 = (longdouble)fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.0347);
  lVar8 = (longdouble)fsin(lVar7 + (longdouble)(DAT_00040310 * (float)/*c*/0.00132));
  lVar7 = (longdouble)/*c*/200.0;
  lVar9 = (longdouble)fsin((longdouble)DAT_00040310 * (longdouble)/*c*/0.0458);
  lVar10 = (longdouble)fcos((longdouble)(DAT_00040310 * (float)/*c*/0.00241) - lVar9);
  lVar9 = (longdouble)/*c*/200.0;
  lVar11 = (longdouble)fcos((longdouble)DAT_00040310 * (longdouble)/*c*/0.0612);
  lVar12 = (longdouble)fsin(lVar11 + (longdouble)(DAT_00040310 * (float)/*c*/0.00145));
  lVar11 = (longdouble)/*c*/200.0;
  iVar6 = param_1[0x12];
  iVar1 = param_1[2];
  iVar2 = *param_1;
  for (local_1c = 0; local_1c < iVar2; local_1c = local_1c + 1) {
    fVar3 = *(float *)(local_1c * 0xc + iVar1) - (float)(lVar8 * lVar7);
    fVar4 = *(float *)(local_1c * 0xc + iVar1 + 4) - (float)(lVar10 * lVar9);
    fVar5 = *(float *)(local_1c * 0xc + iVar1 + 8) - (float)(lVar12 * lVar11);
    local_20 = param_2 * SQRT(fVar5 * fVar5 + fVar4 * fVar4 + fVar3 * fVar3);
    if (0x437f0000 < (int)local_20) {
      local_20 = 255.0;
    }
    *(float *)(local_1c * 8 + iVar6) = /*c*/255.0 - local_20;
  }
  return;
}

