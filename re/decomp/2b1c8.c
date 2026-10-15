
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int FUN_0002b1c8(undefined4 *param_1,int param_2)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  undefined8 uVar11;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 *local_24;
  int *local_20;
  undefined4 *local_1c;
  int *local_18;
  
  DAT_00041248 = param_2 + 0x1c;
  _DAT_0004124c = param_2 + 0x38;
  iVar7 = 0;
  pfVar6 = (float *)(param_2 + 0x54);
  DAT_00041244 = param_2;
  _DAT_00041250 = param_2;
  for (local_18 = &DAT_00041244; local_18 != (int *)&DAT_00041250; local_18 = local_18 + 1) {
    pfVar1 = (float *)*local_18;
    pfVar2 = (float *)local_18[1];
    if (((uint)pfVar1[6] & 4) == 0) {
      (&DAT_00041274)[iVar7] = pfVar1;
      iVar7 = iVar7 + 1;
      if (((uint)pfVar2[6] & 4) != 0) {
LAB_0002b306:
        fVar5 = _DAT_00041304;
        fVar3 = (_DAT_00041304 - *pfVar1) / (*pfVar2 - *pfVar1);
        piVar10 = &DAT_00041274 + iVar7;
        fVar4 = 1.0 - fVar3;
        *piVar10 = (int)pfVar6;
        pfVar6[1] = pfVar2[1] * fVar3 + pfVar1[1] * fVar4;
        *(float *)*piVar10 = fVar5;
        *(float *)(*piVar10 + 8) = pfVar2[2] * fVar3 + pfVar1[2] * fVar4;
        *(float *)(*piVar10 + 0x10) = pfVar2[4] * fVar3 + pfVar1[4] * fVar4;
        *(float *)(*piVar10 + 0xc) = pfVar2[3] * fVar3 + pfVar1[3] * fVar4;
        *(float *)(*piVar10 + 0x14) = fVar4 * pfVar1[5] + pfVar2[5] * fVar3;
        uVar11 = FUN_0002b198(*piVar10);
        pfVar6 = (float *)(extraout_ECX + 0x1c);
        iVar7 = (int)((ulonglong)uVar11 >> 0x20) + 1;
        *(int *)(*piVar10 + 0x18) = (int)uVar11;
      }
    }
    else if (((uint)pfVar2[6] & 4) == 0) goto LAB_0002b306;
  }
  iVar8 = 0;
  (&DAT_00041274)[iVar7] = DAT_00041274;
  local_24 = &DAT_00041274;
  for (local_28 = 0; local_28 < iVar7; local_28 = local_28 + 1) {
    pfVar1 = (float *)*local_24;
    pfVar2 = (float *)local_24[1];
    if (((uint)pfVar1[6] & 8) == 0) {
      (&DAT_00041244)[iVar8] = (int)pfVar1;
      iVar8 = iVar8 + 1;
      if (((uint)pfVar2[6] & 8) != 0) {
LAB_0002b3d6:
        fVar5 = _DAT_0003fcec;
        fVar3 = (_DAT_0003fcec - *pfVar1) / (*pfVar2 - *pfVar1);
        fVar4 = 1.0 - fVar3;
        (&DAT_00041244)[iVar8] = (int)pfVar6;
        pfVar6[1] = pfVar2[1] * fVar3 + pfVar1[1] * fVar4;
        *(float *)(&DAT_00041244)[iVar8] = fVar5;
        *(float *)((&DAT_00041244)[iVar8] + 8) = pfVar2[2] * fVar3 + pfVar1[2] * fVar4;
        *(float *)((&DAT_00041244)[iVar8] + 0x10) = pfVar2[4] * fVar3 + pfVar1[4] * fVar4;
        *(float *)((&DAT_00041244)[iVar8] + 0xc) = pfVar2[3] * fVar3 + pfVar1[3] * fVar4;
        *(float *)((&DAT_00041244)[iVar8] + 0x14) = fVar4 * pfVar1[5] + pfVar2[5] * fVar3;
        uVar11 = FUN_0002b198((&DAT_00041244)[iVar8]);
        iVar9 = (int)((ulonglong)uVar11 >> 0x20);
        iVar8 = iVar9 + 1;
        pfVar6 = (float *)(extraout_ECX_00 + 0x1c);
        *(int *)((&DAT_00041244)[iVar9] + 0x18) = (int)uVar11;
      }
    }
    else if (((uint)pfVar2[6] & 8) == 0) goto LAB_0002b3d6;
    local_24 = local_24 + 1;
  }
  iVar7 = 0;
  (&DAT_00041244)[iVar8] = DAT_00041244;
  local_20 = &DAT_00041244;
  for (local_2c = 0; local_2c < iVar8; local_2c = local_2c + 1) {
    pfVar1 = (float *)*local_20;
    pfVar2 = (float *)local_20[1];
    if (((uint)pfVar1[6] & 1) == 0) {
      (&DAT_00041274)[iVar7] = pfVar1;
      iVar7 = iVar7 + 1;
      if (((uint)pfVar2[6] & 1) != 0) {
LAB_0002b494:
        fVar5 = _DAT_00041308;
        fVar3 = (_DAT_00041308 - pfVar1[1]) / (pfVar2[1] - pfVar1[1]);
        fVar4 = 1.0 - fVar3;
        (&DAT_00041274)[iVar7] = pfVar6;
        *pfVar6 = *pfVar2 * fVar3 + *pfVar1 * fVar4;
        *(float *)((&DAT_00041274)[iVar7] + 4) = fVar5;
        *(float *)((&DAT_00041274)[iVar7] + 8) = pfVar2[2] * fVar3 + pfVar1[2] * fVar4;
        *(float *)((&DAT_00041274)[iVar7] + 0x10) = pfVar2[4] * fVar3 + pfVar1[4] * fVar4;
        *(float *)((&DAT_00041274)[iVar7] + 0xc) = pfVar2[3] * fVar3 + pfVar1[3] * fVar4;
        *(float *)((&DAT_00041274)[iVar7] + 0x14) = fVar4 * pfVar1[5] + pfVar2[5] * fVar3;
        uVar11 = FUN_0002b168((&DAT_00041274)[iVar7]);
        piVar10 = &DAT_00041274 + iVar7;
        pfVar6 = (float *)(extraout_ECX_01 + 0x1c);
        iVar7 = (int)((ulonglong)uVar11 >> 0x20) + 1;
        *(int *)(*piVar10 + 0x18) = (int)uVar11;
      }
    }
    else if (((uint)pfVar2[6] & 1) == 0) goto LAB_0002b494;
    local_20 = local_20 + 1;
  }
  iVar8 = 0;
  (&DAT_00041274)[iVar7] = DAT_00041274;
  local_30 = 0;
  if (0 < iVar7) {
    local_1c = &DAT_00041274;
    do {
      pfVar1 = (float *)*local_1c;
      pfVar2 = (float *)local_1c[1];
      if (((uint)pfVar1[6] & 2) == 0) {
        (&DAT_00041244)[iVar8] = (int)pfVar1;
        iVar8 = iVar8 + 1;
        if (((uint)pfVar2[6] & 2) != 0) goto LAB_0002b5aa;
      }
      else if (((uint)pfVar2[6] & 2) == 0) {
LAB_0002b5aa:
        fVar5 = _DAT_0003fcf0;
        fVar3 = (_DAT_0003fcf0 - pfVar1[1]) / (pfVar2[1] - pfVar1[1]);
        fVar4 = 1.0 - fVar3;
        (&DAT_00041244)[iVar8] = (int)pfVar6;
        *pfVar6 = *pfVar2 * fVar3 + *pfVar1 * fVar4;
        *(float *)((&DAT_00041244)[iVar8] + 4) = fVar5;
        *(float *)((&DAT_00041244)[iVar8] + 8) = pfVar2[2] * fVar3 + pfVar1[2] * fVar4;
        *(float *)((&DAT_00041244)[iVar8] + 0x10) = pfVar2[4] * fVar3 + pfVar1[4] * fVar4;
        *(float *)((&DAT_00041244)[iVar8] + 0xc) = pfVar2[3] * fVar3 + pfVar1[3] * fVar4;
        pfVar6 = pfVar6 + 7;
        piVar10 = &DAT_00041244 + iVar8;
        iVar8 = iVar8 + 1;
        *(float *)(*piVar10 + 0x14) = fVar4 * pfVar1[5] + pfVar2[5] * fVar3;
      }
      local_1c = local_1c + 1;
      local_30 = local_30 + 1;
    } while (local_30 < iVar7);
  }
  *param_1 = &DAT_00041244;
  return iVar8;
}

