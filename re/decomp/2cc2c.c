
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002cc2c(int param_1,int param_2,int unaff_EBX,int param_4,int param_5,int param_6)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int extraout_EDX;
  undefined4 *puVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  bool bVar15;
  int local_10;
  
  iVar7 = 1;
  iVar13 = *(int *)(param_1 + 4);
  iVar5 = param_1 + 0x10;
  iVar8 = iVar13;
  iVar11 = param_1;
  DAT_000413fc = param_1;
  DAT_000413f0 = param_1;
  if (1 < param_2) {
    do {
      iVar2 = *(int *)(iVar5 + 4);
      iVar9 = iVar2;
      DAT_000413fc = iVar5;
      if ((iVar8 <= iVar2) && (iVar9 = iVar8, DAT_000413fc = iVar11, iVar13 < iVar2)) {
        iVar13 = iVar2;
        DAT_000413f0 = iVar5;
      }
      iVar7 = iVar7 + 1;
      iVar5 = iVar5 + 0x10;
      iVar8 = iVar9;
      iVar11 = DAT_000413fc;
    } while (iVar7 < param_2);
  }
  DAT_000413f8 = iVar5 + -0x10;
  bVar15 = DAT_000413fc == DAT_000413f0;
  DAT_000413f4 = param_1;
  DAT_00041400 = DAT_000413fc;
  while( true ) {
    if (bVar15) {
      return;
    }
    FUN_0002ca00();
    if (0 < DAT_00041404) break;
    bVar15 = DAT_000413fc == DAT_000413f0;
  }
  do {
    if (DAT_00041400 == DAT_000413f0) {
      return;
    }
    FUN_0002cacc();
  } while (DAT_00041408 < 1);
  local_10 = DAT_00040304[2] + (extraout_EDX + 0xffff >> 0x10) * *DAT_00040304 * 4;
  DAT_0004142c = param_5 << 0x10;
  _DAT_00041430 = param_6 << 0x10;
  _DAT_00041438 = (param_5 >> 0x10) + param_4 * (param_6 >> 0x10);
  _DAT_00041434 = _DAT_00041438 + param_4;
  do {
    while( true ) {
      uVar4 = DAT_0004142c;
      iVar13 = DAT_00041414 + 0xffff >> 0x10;
      uVar14 = (DAT_0004140c + 0xffff >> 0x10) - iVar13;
      if (0 < (int)uVar14) {
        iVar8 = iVar13 * 0x10000 - DAT_00041414;
        lVar3 = (longlong)iVar8 * (longlong)param_5;
        iVar5 = DAT_0004141c + ((uint)lVar3 >> 0x10 | (int)((ulonglong)lVar3 >> 0x20) << 0x10);
        lVar3 = (longlong)iVar8 * (longlong)param_6;
        iVar11 = DAT_00041424 + ((uint)lVar3 >> 0x10 | (int)((ulonglong)lVar3 >> 0x20) << 0x10);
        iVar8 = (iVar5 >> 0x10) + (unaff_EBX >> 2) + (iVar11 >> 0x10) * param_4;
        puVar10 = (undefined4 *)(iVar13 * 4 + local_10);
        uVar12 = iVar11 * 0x10000;
        bVar15 = CARRY4(uVar12,_DAT_00041430);
        uVar12 = uVar12 + _DAT_00041430;
        uVar14 = uVar14 | iVar5 * 0x10000;
        do {
          puVar1 = (undefined4 *)(iVar8 * 4);
          iVar13 = uVar14 + uVar4;
          iVar8 = iVar8 + *(int *)(&DAT_00041438 + (uint)bVar15 * -4) + (uint)CARRY4(uVar14,uVar4);
          bVar15 = CARRY4(uVar12,_DAT_00041430);
          uVar12 = uVar12 + _DAT_00041430;
          *puVar10 = *puVar1;
          puVar10 = puVar10 + 1;
          sVar6 = (short)iVar13 + -1;
          uVar14 = CONCAT22((short)((uint)iVar13 >> 0x10),sVar6);
        } while (sVar6 != 0);
      }
      DAT_00041404 = DAT_00041404 + -1;
      local_10 = local_10 + *DAT_00040304 * 4;
      if (DAT_00041404 < 1) {
        do {
          if (DAT_000413fc == DAT_000413f0) {
            return;
          }
          FUN_0002ca00();
        } while (DAT_00041404 < 1);
      }
      else {
        DAT_0004140c = DAT_0004140c + DAT_00041410;
      }
      DAT_00041408 = DAT_00041408 + -1;
      if (DAT_00041408 < 1) break;
      DAT_00041414 = DAT_00041414 + DAT_00041418;
      DAT_0004141c = DAT_0004141c + DAT_00041420;
      DAT_00041424 = DAT_00041424 + DAT_00041428;
    }
    do {
      if (DAT_00041400 == DAT_000413f0) {
        return;
      }
      FUN_0002cacc();
    } while (DAT_00041408 < 1);
  } while( true );
}

