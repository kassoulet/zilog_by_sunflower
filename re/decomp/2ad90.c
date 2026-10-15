
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int FUN_0002ad90(undefined4 *param_1,int param_2)

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
  int *piVar9;
  undefined8 uVar10;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 *local_24;
  undefined4 *local_20;
  int *local_1c;
  int *local_18;
  
  DAT_000411e8 = param_2 + 0x14;
  _DAT_000411ec = param_2 + 0x28;
  iVar7 = 0;
  pfVar6 = (float *)(param_2 + 0x3c);
  DAT_000411e4 = param_2;
  _DAT_000411f0 = param_2;
  for (local_18 = &DAT_000411e4; local_18 != (int *)&DAT_000411f0; local_18 = local_18 + 1) {
    pfVar1 = (float *)*local_18;
    pfVar2 = (float *)local_18[1];
    if (((uint)pfVar1[4] & 4) == 0) {
      (&DAT_00041214)[iVar7] = pfVar1;
      iVar7 = iVar7 + 1;
      if (((uint)pfVar2[4] & 4) != 0) {
LAB_0002aeca:
        fVar5 = _DAT_00041304;
        fVar3 = (_DAT_00041304 - *pfVar1) / (*pfVar2 - *pfVar1);
        piVar9 = &DAT_00041214 + iVar7;
        fVar4 = 1.0 - fVar3;
        *piVar9 = (int)pfVar6;
        pfVar6[1] = pfVar2[1] * fVar3 + pfVar1[1] * fVar4;
        *(float *)*piVar9 = fVar5;
        *(float *)(*piVar9 + 8) = pfVar2[2] * fVar3 + pfVar1[2] * fVar4;
        *(float *)(*piVar9 + 0xc) = fVar4 * pfVar1[3] + pfVar2[3] * fVar3;
        uVar10 = FUN_0002ad60(*piVar9);
        pfVar6 = (float *)(extraout_ECX + 0x14);
        iVar7 = (int)((ulonglong)uVar10 >> 0x20) + 1;
        *(int *)(*piVar9 + 0x10) = (int)uVar10;
      }
    }
    else if (((uint)pfVar2[4] & 4) == 0) goto LAB_0002aeca;
  }
  iVar8 = 0;
  (&DAT_00041214)[iVar7] = DAT_00041214;
  local_24 = &DAT_00041214;
  for (local_28 = 0; local_28 < iVar7; local_28 = local_28 + 1) {
    pfVar1 = (float *)*local_24;
    pfVar2 = (float *)local_24[1];
    if (((uint)pfVar1[4] & 8) == 0) {
      (&DAT_000411e4)[iVar8] = (int)pfVar1;
      iVar8 = iVar8 + 1;
      if (((uint)pfVar2[4] & 8) != 0) {
LAB_0002af74:
        fVar5 = _DAT_0003fcec;
        fVar3 = (_DAT_0003fcec - *pfVar1) / (*pfVar2 - *pfVar1);
        fVar4 = 1.0 - fVar3;
        (&DAT_000411e4)[iVar8] = (int)pfVar6;
        pfVar6[1] = pfVar2[1] * fVar3 + pfVar1[1] * fVar4;
        *(float *)(&DAT_000411e4)[iVar8] = fVar5;
        *(float *)((&DAT_000411e4)[iVar8] + 8) = pfVar2[2] * fVar3 + pfVar1[2] * fVar4;
        *(float *)((&DAT_000411e4)[iVar8] + 0xc) = fVar4 * pfVar1[3] + pfVar2[3] * fVar3;
        uVar10 = FUN_0002ad60((&DAT_000411e4)[iVar8]);
        piVar9 = &DAT_000411e4 + iVar8;
        pfVar6 = (float *)(extraout_ECX_00 + 0x14);
        iVar8 = (int)((ulonglong)uVar10 >> 0x20) + 1;
        *(int *)(*piVar9 + 0x10) = (int)uVar10;
      }
    }
    else if (((uint)pfVar2[4] & 8) == 0) goto LAB_0002af74;
    local_24 = local_24 + 1;
  }
  iVar7 = 0;
  (&DAT_000411e4)[iVar8] = DAT_000411e4;
  local_1c = &DAT_000411e4;
  for (local_30 = 0; local_30 < iVar8; local_30 = local_30 + 1) {
    pfVar1 = (float *)*local_1c;
    pfVar2 = (float *)local_1c[1];
    if (((uint)pfVar1[4] & 1) == 0) {
      (&DAT_00041214)[iVar7] = pfVar1;
      iVar7 = iVar7 + 1;
      if (((uint)pfVar2[4] & 1) != 0) {
LAB_0002b00f:
        fVar5 = _DAT_00041308;
        fVar3 = (_DAT_00041308 - pfVar1[1]) / (pfVar2[1] - pfVar1[1]);
        fVar4 = 1.0 - fVar3;
        (&DAT_00041214)[iVar7] = pfVar6;
        *pfVar6 = *pfVar2 * fVar3 + *pfVar1 * fVar4;
        *(float *)((&DAT_00041214)[iVar7] + 4) = fVar5;
        *(float *)((&DAT_00041214)[iVar7] + 8) = pfVar2[2] * fVar3 + pfVar1[2] * fVar4;
        *(float *)((&DAT_00041214)[iVar7] + 0xc) = fVar4 * pfVar1[3] + pfVar2[3] * fVar3;
        uVar10 = FUN_0002ad30((&DAT_00041214)[iVar7]);
        piVar9 = &DAT_00041214 + iVar7;
        pfVar6 = (float *)(extraout_ECX_01 + 0x14);
        iVar7 = (int)((ulonglong)uVar10 >> 0x20) + 1;
        *(int *)(*piVar9 + 0x10) = (int)uVar10;
      }
    }
    else if (((uint)pfVar2[4] & 1) == 0) goto LAB_0002b00f;
    local_1c = local_1c + 1;
  }
  iVar8 = 0;
  (&DAT_00041214)[iVar7] = DAT_00041214;
  local_2c = 0;
  if (0 < iVar7) {
    local_20 = &DAT_00041214;
    do {
      pfVar1 = (float *)*local_20;
      pfVar2 = (float *)local_20[1];
      if (((uint)pfVar1[4] & 2) == 0) {
        (&DAT_000411e4)[iVar8] = (int)pfVar1;
        iVar8 = iVar8 + 1;
        if (((uint)pfVar2[4] & 2) != 0) goto LAB_0002b101;
      }
      else if (((uint)pfVar2[4] & 2) == 0) {
LAB_0002b101:
        fVar5 = _DAT_0003fcf0;
        fVar3 = (_DAT_0003fcf0 - pfVar1[1]) / (pfVar2[1] - pfVar1[1]);
        fVar4 = 1.0 - fVar3;
        (&DAT_000411e4)[iVar8] = (int)pfVar6;
        *pfVar6 = *pfVar2 * fVar3 + *pfVar1 * fVar4;
        *(float *)((&DAT_000411e4)[iVar8] + 4) = fVar5;
        *(float *)((&DAT_000411e4)[iVar8] + 8) = pfVar2[2] * fVar3 + pfVar1[2] * fVar4;
        iVar8 = iVar8 + 1;
        pfVar6 = pfVar6 + 5;
        *(float *)(*(int *)(&DAT_000411e0 + iVar8 * 4) + 0xc) =
             fVar4 * pfVar1[3] + pfVar2[3] * fVar3;
      }
      local_20 = local_20 + 1;
      local_2c = local_2c + 1;
    } while (local_2c < iVar7);
  }
  *param_1 = &DAT_000411e4;
  return iVar8;
}

