
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000266a0(int param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  double dVar6;
  float fVar7;
  undefined4 uVar8;
  int iVar9;
  int extraout_ECX;
  float *extraout_ECX_00;
  int iVar10;
  float *pfVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  undefined8 uVar15;
  int local_44;
  
  pfVar1 = (float *)(param_1 + 0x1c);
  uVar8 = FUN_00026650(param_1,param_1 + 0x38,unaff_EBX,param_1);
  *(undefined4 *)(extraout_ECX + 0x18) = uVar8;
  uVar15 = FUN_00026650(pfVar1);
  *(int *)(param_1 + 0x34) = (int)uVar15;
  uVar15 = FUN_00026650((int)((ulonglong)uVar15 >> 0x20));
  pfVar11 = (float *)((ulonglong)uVar15 >> 0x20);
  pfVar11[6] = (float)uVar15;
  if (((uint)extraout_ECX_00[6] & *(uint *)(param_1 + 0x34) & (uint)pfVar11[6]) == 0) {
    fVar7 = *(float *)(param_1 + 0x20) - pfVar11[1];
    dVar6 = (double)((*extraout_ECX_00 - *pfVar11) * fVar7 -
                    (*pfVar1 - *pfVar11) * (extraout_ECX_00[1] - pfVar11[1]));
    local_44 = SUB84(dVar6,0);
    if ((((ulonglong)dVar6 & 0x7fffffff00000000) != 0) || (local_44 != 0)) {
      dVar6 = (1.0 / dVar6) * /*c*/65536.0;
      iVar2 = (int)ROUND(((extraout_ECX_00[2] - pfVar11[2]) * fVar7 -
                         (*(float *)(param_1 + 0x24) - pfVar11[2]) *
                         (extraout_ECX_00[1] - pfVar11[1])) * (float)dVar6);
      iVar3 = (int)ROUND(((*(float *)(param_1 + 0x20) - pfVar11[1]) *
                          (extraout_ECX_00[3] - pfVar11[3]) -
                         (extraout_ECX_00[1] - pfVar11[1]) *
                         (*(float *)(param_1 + 0x28) - pfVar11[3])) * (float)dVar6);
      iVar4 = (int)ROUND(((*(float *)(param_1 + 0x20) - pfVar11[1]) *
                          (extraout_ECX_00[4] - pfVar11[4]) -
                         (extraout_ECX_00[1] - pfVar11[1]) *
                         (*(float *)(param_1 + 0x2c) - pfVar11[4])) * (float)dVar6);
      iVar5 = (int)ROUND(((*(float *)(param_1 + 0x20) - pfVar11[1]) *
                          (extraout_ECX_00[5] - pfVar11[5]) -
                         (extraout_ECX_00[1] - pfVar11[1]) *
                         (*(float *)(param_1 + 0x30) - pfVar11[5])) * (float)dVar6);
      if ((((uint)extraout_ECX_00[6] | *(uint *)(param_1 + 0x34) | (uint)pfVar11[6]) & 0xf) == 0) {
        DAT_00040974 = (int)ROUND(*extraout_ECX_00 * _DAT_0003f964);
        DAT_00040978 = (int)ROUND(extraout_ECX_00[1] * _DAT_0003f964);
        DAT_0004097c = (int)ROUND(extraout_ECX_00[2] * _DAT_0003f964);
        DAT_00040980 = (int)ROUND(extraout_ECX_00[3] * _DAT_0003f964);
        DAT_00040984 = (int)ROUND(extraout_ECX_00[4] * _DAT_0003f964);
        DAT_00040988 = (int)ROUND(extraout_ECX_00[5] * _DAT_0003f964);
        DAT_0004098c = (int)ROUND(*pfVar1 * _DAT_0003f964);
        DAT_00040990 = (int)ROUND(*(float *)(param_1 + 0x20) * _DAT_0003f964);
        DAT_00040994 = (int)ROUND(*(float *)(param_1 + 0x24) * _DAT_0003f964);
        DAT_00040998 = (int)ROUND(*(float *)(param_1 + 0x28) * _DAT_0003f964);
        DAT_0004099c = (int)ROUND(*(float *)(param_1 + 0x2c) * _DAT_0003f964);
        DAT_000409a0 = (int)ROUND(*(float *)(param_1 + 0x30) * _DAT_0003f964);
        DAT_000409a4 = (int)ROUND(*pfVar11 * _DAT_0003f964);
        DAT_000409a8 = (int)ROUND(pfVar11[1] * _DAT_0003f964);
        DAT_000409ac = (int)ROUND(pfVar11[2] * _DAT_0003f964);
        DAT_000409b0 = (int)ROUND(pfVar11[3] * _DAT_0003f964);
        DAT_000409b4 = (int)ROUND(pfVar11[4] * _DAT_0003f964);
        DAT_000409b8 = (int)ROUND(pfVar11[5] * _DAT_0003f964);
        DAT_000409bc = (float)(int)ROUND(pfVar11[6] * _DAT_0003f964);
        FUN_0002c35c(&DAT_00040974,3,param_2,iVar2,iVar3,iVar4,iVar5);
        return;
      }
      DAT_000409bc = *extraout_ECX_00;
      _DAT_000409d4 = extraout_ECX_00[6];
      _DAT_000409c0 = extraout_ECX_00[1];
      _DAT_000409c4 = extraout_ECX_00[2];
      _DAT_000409c8 = extraout_ECX_00[3];
      _DAT_000409cc = extraout_ECX_00[4];
      _DAT_000409d0 = extraout_ECX_00[5];
      _DAT_000409d8 = *pfVar1;
      _DAT_000409dc = *(undefined4 *)(param_1 + 0x20);
      _DAT_000409e0 = *(undefined4 *)(param_1 + 0x24);
      _DAT_000409e4 = *(undefined4 *)(param_1 + 0x28);
      _DAT_000409e8 = *(undefined4 *)(param_1 + 0x2c);
      _DAT_000409ec = *(undefined4 *)(param_1 + 0x30);
      _DAT_000409f4 = *pfVar11;
      _DAT_000409f8 = pfVar11[1];
      _DAT_000409fc = pfVar11[2];
      _DAT_00040a00 = pfVar11[3];
      _DAT_00040a04 = pfVar11[4];
      _DAT_00040a08 = pfVar11[5];
      _DAT_000409f0 = *(uint *)(param_1 + 0x34);
      _DAT_00040a0c = pfVar11[6];
      iVar9 = FUN_0002b1c8(&DAT_00040b0c,&DAT_000409bc);
      if (2 < iVar9) {
        iVar10 = 0;
        if (0 < iVar9) {
          piVar13 = &DAT_00040b20;
          piVar14 = &DAT_00040b18;
          iVar12 = 0;
          do {
            fVar7 = (*(float **)(iVar12 + DAT_00040b0c))[1] * _DAT_0003f964;
            (&DAT_00040b10)[iVar10 * 6] =
                 (int)ROUND(**(float **)(iVar12 + DAT_00040b0c) * _DAT_0003f964);
            (&DAT_00040b14)[iVar10 * 6] = (int)ROUND(fVar7);
            fVar7 = *(float *)(*(int *)(iVar12 + DAT_00040b0c) + 0xc) * _DAT_0003f964;
            *piVar14 = (int)ROUND(*(float *)(*(int *)(iVar12 + DAT_00040b0c) + 8) * _DAT_0003f964);
            piVar14[1] = (int)ROUND(fVar7);
            iVar10 = iVar10 + 1;
            piVar14 = piVar14 + 6;
            fVar7 = *(float *)(*(int *)(iVar12 + DAT_00040b0c) + 0x14) * _DAT_0003f964;
            *piVar13 = (int)ROUND(*(float *)(*(int *)(iVar12 + DAT_00040b0c) + 0x10) * _DAT_0003f964
                                 );
            piVar13[1] = (int)ROUND(fVar7);
            piVar13 = piVar13 + 6;
            iVar12 = iVar12 + 4;
          } while (iVar10 < iVar9);
        }
        FUN_0002c35c(&DAT_00040b10,iVar9,param_2,iVar2,iVar3,iVar4,iVar5);
        return;
      }
    }
  }
  return;
}

