
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int FUN_0002b634(undefined4 *param_1,int param_2)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined8 uVar9;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 *local_28;
  int *local_24;
  undefined4 *local_20;
  int *local_1c;
  
  DAT_000412a8 = param_2 + 0x14;
  _DAT_000412ac = param_2 + 0x28;
  iVar6 = 0;
  pfVar5 = (float *)(param_2 + 0x3c);
  DAT_000412a4 = param_2;
  _DAT_000412b0 = param_2;
  for (local_1c = &DAT_000412a4; local_1c != (int *)&DAT_000412b0; local_1c = local_1c + 1) {
    pfVar1 = (float *)*local_1c;
    pfVar2 = (float *)local_1c[1];
    if (((uint)pfVar1[4] & 4) == 0) {
      (&DAT_000412d4)[iVar6] = pfVar1;
      iVar6 = iVar6 + 1;
      if (((uint)pfVar2[4] & 4) != 0) {
LAB_0002b764:
        fVar4 = _DAT_00041304;
        fVar3 = (_DAT_00041304 - *pfVar1) / (*pfVar2 - *pfVar1);
        piVar8 = &DAT_000412d4 + iVar6;
        *piVar8 = (int)pfVar5;
        pfVar5[1] = pfVar2[1] * fVar3 + pfVar1[1] * (1.0 - fVar3);
        *(float *)*piVar8 = fVar4;
        *(float *)(*piVar8 + 8) = (1.0 - fVar3) * pfVar1[2] + pfVar2[2] * fVar3;
        uVar9 = FUN_0002ad60(*piVar8,iVar6,pfVar1,pfVar5 + 5);
        iVar6 = (int)((ulonglong)uVar9 >> 0x20) + 1;
        *(int *)(*piVar8 + 0x10) = (int)uVar9;
        pfVar5 = extraout_ECX;
      }
    }
    else if (((uint)pfVar2[4] & 4) == 0) goto LAB_0002b764;
  }
  iVar7 = 0;
  (&DAT_000412d4)[iVar6] = DAT_000412d4;
  local_20 = &DAT_000412d4;
  for (local_2c = 0; local_2c < iVar6; local_2c = local_2c + 1) {
    pfVar1 = (float *)*local_20;
    pfVar2 = (float *)local_20[1];
    if (((uint)pfVar1[4] & 8) == 0) {
      (&DAT_000412a4)[iVar7] = (int)pfVar1;
      iVar7 = iVar7 + 1;
      if (((uint)pfVar2[4] & 8) != 0) {
LAB_0002b7fb:
        fVar4 = _DAT_0003fcec;
        fVar3 = (_DAT_0003fcec - *pfVar1) / (*pfVar2 - *pfVar1);
        (&DAT_000412a4)[iVar7] = (int)pfVar5;
        pfVar5[1] = pfVar2[1] * fVar3 + pfVar1[1] * (1.0 - fVar3);
        *(float *)(&DAT_000412a4)[iVar7] = fVar4;
        *(float *)((&DAT_000412a4)[iVar7] + 8) = (1.0 - fVar3) * pfVar1[2] + pfVar2[2] * fVar3;
        uVar9 = FUN_0002ad60((&DAT_000412a4)[iVar7],iVar7 + 1);
        iVar7 = (int)((ulonglong)uVar9 >> 0x20);
        pfVar5 = (float *)(extraout_ECX_00 + 0x14);
        *(int *)(*(int *)(&DAT_000412a0 + iVar7 * 4) + 0x10) = (int)uVar9;
      }
    }
    else if (((uint)pfVar2[4] & 8) == 0) goto LAB_0002b7fb;
    local_20 = local_20 + 1;
  }
  iVar6 = 0;
  (&DAT_000412a4)[iVar7] = DAT_000412a4;
  local_24 = &DAT_000412a4;
  for (local_34 = 0; local_34 < iVar7; local_34 = local_34 + 1) {
    pfVar1 = (float *)*local_24;
    pfVar2 = (float *)local_24[1];
    if (((uint)pfVar1[4] & 1) == 0) {
      (&DAT_000412d4)[iVar6] = pfVar1;
      iVar6 = iVar6 + 1;
      if (((uint)pfVar2[4] & 1) != 0) {
LAB_0002b881:
        fVar4 = _DAT_00041308;
        fVar3 = (_DAT_00041308 - pfVar1[1]) / (pfVar2[1] - pfVar1[1]);
        (&DAT_000412d4)[iVar6] = pfVar5;
        *pfVar5 = *pfVar2 * fVar3 + *pfVar1 * (1.0 - fVar3);
        *(float *)((&DAT_000412d4)[iVar6] + 4) = fVar4;
        *(float *)((&DAT_000412d4)[iVar6] + 8) = (1.0 - fVar3) * pfVar1[2] + pfVar2[2] * fVar3;
        uVar9 = FUN_0002ad30((&DAT_000412d4)[iVar6],iVar6 + 1);
        iVar6 = (int)((ulonglong)uVar9 >> 0x20);
        pfVar5 = (float *)(extraout_ECX_01 + 0x14);
        *(int *)(*(int *)(&DAT_000412d0 + iVar6 * 4) + 0x10) = (int)uVar9;
      }
    }
    else if (((uint)pfVar2[4] & 1) == 0) goto LAB_0002b881;
    local_24 = local_24 + 1;
  }
  iVar7 = 0;
  (&DAT_000412d4)[iVar6] = DAT_000412d4;
  local_30 = 0;
  if (0 < iVar6) {
    local_28 = &DAT_000412d4;
    do {
      pfVar1 = (float *)*local_28;
      pfVar2 = (float *)local_28[1];
      if (((uint)pfVar1[4] & 2) == 0) {
        (&DAT_000412a4)[iVar7] = (int)pfVar1;
        iVar7 = iVar7 + 1;
        if (((uint)pfVar2[4] & 2) != 0) goto LAB_0002b961;
      }
      else if (((uint)pfVar2[4] & 2) == 0) {
LAB_0002b961:
        fVar4 = _DAT_0003fcf0;
        fVar3 = (_DAT_0003fcf0 - pfVar1[1]) / (pfVar2[1] - pfVar1[1]);
        (&DAT_000412a4)[iVar7] = (int)pfVar5;
        *pfVar5 = *pfVar2 * fVar3 + *pfVar1 * (1.0 - fVar3);
        *(float *)((&DAT_000412a4)[iVar7] + 4) = fVar4;
        iVar7 = iVar7 + 1;
        pfVar5 = pfVar5 + 5;
        *(float *)(*(int *)(&DAT_000412a0 + iVar7 * 4) + 8) =
             (1.0 - fVar3) * pfVar1[2] + pfVar2[2] * fVar3;
      }
      local_28 = local_28 + 1;
      local_30 = local_30 + 1;
    } while (local_30 < iVar6);
  }
  *param_1 = &DAT_000412a4;
  return iVar7;
}

