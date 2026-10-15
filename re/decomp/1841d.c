
void FUN_0001841d(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  undefined4 uVar14;
  int local_30;
  int local_24;
  
  if (*(int *)(*param_1 + 0x20) == 0) {
    uVar14 = thunk_FUN_00024c8f(*(int *)(*param_1 + 0x18) * 0xc);
    *(undefined4 *)(*param_1 + 0x20) = uVar14;
  }
  iVar1 = *(int *)(*param_1 + 0x20);
  if (((char)param_1[7] == '\0') || ((char)param_1[7] == '\x02')) {
    local_24 = *(int *)(*param_1 + 8);
  }
  else {
    local_24 = *(int *)(*param_1 + 4);
  }
  iVar2 = *(int *)(*param_1 + 0x1c);
  iVar3 = *(int *)(*param_1 + 0x18);
  for (local_30 = 0; local_30 < iVar3; local_30 = local_30 + 1) {
    iVar4 = *(int *)(local_30 * 0xc + iVar2);
    fVar5 = *(float *)(iVar4 * 0xc + local_24);
    fVar6 = *(float *)(iVar4 * 0xc + local_24 + 4);
    fVar7 = *(float *)(iVar4 * 0xc + local_24 + 8);
    iVar4 = *(int *)(local_30 * 0xc + iVar2 + 4);
    fVar8 = *(float *)(iVar4 * 0xc + local_24);
    fVar9 = *(float *)(iVar4 * 0xc + local_24 + 4);
    fVar10 = *(float *)(iVar4 * 0xc + local_24 + 8);
    iVar4 = *(int *)(local_30 * 0xc + iVar2 + 8);
    fVar11 = *(float *)(iVar4 * 0xc + local_24);
    fVar12 = *(float *)(iVar4 * 0xc + local_24 + 4);
    fVar13 = *(float *)(iVar4 * 0xc + local_24 + 8);
    *(float *)(local_30 * 0xc + iVar1) =
         (fVar13 - fVar7) * (fVar9 - fVar6) - (fVar10 - fVar7) * (fVar12 - fVar6);
    *(float *)(local_30 * 0xc + iVar1 + 4) =
         (fVar11 - fVar5) * (fVar10 - fVar7) - (fVar8 - fVar5) * (fVar13 - fVar7);
    *(float *)(local_30 * 0xc + iVar1 + 8) =
         (fVar8 - fVar5) * (fVar12 - fVar6) - (fVar11 - fVar5) * (fVar9 - fVar6);
  }
  return;
}

