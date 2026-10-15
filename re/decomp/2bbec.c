
void FUN_0002bbec(int param_1,int param_2,undefined4 unaff_EBX,int param_4,int param_5)

{
  undefined4 *puVar1;
  int iVar2;
  longlong lVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int extraout_EDX;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 *puVar15;
  bool bVar16;
  
  iVar6 = 1;
  iVar11 = *(int *)(param_1 + 4);
  iVar4 = param_1 + 0x10;
  iVar10 = iVar11;
  iVar7 = param_1;
  DAT_00041318 = param_1;
  DAT_0004130c = param_1;
  if (1 < param_2) {
    do {
      iVar2 = *(int *)(iVar4 + 4);
      iVar8 = iVar2;
      DAT_00041318 = iVar4;
      if ((iVar10 <= iVar2) && (iVar8 = iVar10, DAT_00041318 = iVar7, iVar11 < iVar2)) {
        iVar11 = iVar2;
        DAT_0004130c = iVar4;
      }
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + 0x10;
      iVar10 = iVar8;
      iVar7 = DAT_00041318;
    } while (iVar6 < param_2);
  }
  DAT_00041314 = iVar4 + -0x10;
  bVar16 = DAT_00041318 == DAT_0004130c;
  DAT_00041310 = param_1;
  DAT_0004131c = DAT_00041318;
  while( true ) {
    if (bVar16) {
      return;
    }
    FUN_0002b9c0();
    if (0 < DAT_00041320) break;
    bVar16 = DAT_00041318 == DAT_0004130c;
  }
  do {
    if (DAT_0004131c == DAT_0004130c) {
      return;
    }
    FUN_0002ba8c();
  } while (DAT_00041324 < 1);
  DAT_0004134c = param_5;
  iVar11 = DAT_00040304[2] + (extraout_EDX + 0xffff >> 0x10) * *DAT_00040304 * 4;
  DAT_00041348 = param_4;
  do {
    while( true ) {
      iVar10 = DAT_00041330 + 0xffff >> 0x10;
      uVar13 = (DAT_00041328 + 0xffff >> 0x10) - iVar10;
      if (0 < (int)uVar13) {
        iVar7 = iVar10 * 0x10000 - DAT_00041330;
        lVar3 = (longlong)iVar7 * (longlong)param_4;
        iVar4 = DAT_00041338 + ((uint)lVar3 >> 0x10 | (int)((ulonglong)lVar3 >> 0x20) << 0x10);
        puVar15 = (undefined4 *)(iVar10 * 4 + iVar11);
        lVar3 = (longlong)iVar7 * (longlong)param_5;
        iVar10 = DAT_00041340 + ((uint)lVar3 >> 0x10 | (int)((ulonglong)lVar3 >> 0x20) << 0x10);
        uVar13 = iVar4 * 0x10000 | uVar13 & 0xffff;
        iVar7 = CONCAT22((ushort)((uint)unaff_EBX >> 0x12),
                         CONCAT11((char)((uint)iVar10 >> 0x10),(char)((uint)iVar4 >> 0x10)));
        uVar14 = DAT_00041348 * 0x10000;
        uVar12 = DAT_0004134c * 0x10000;
        uVar9 = CONCAT22((short)((uint)(iVar10 * 0x10000) >> 0x10),
                         CONCAT11(DAT_0004134c._2_1_,DAT_00041348._2_1_));
        do {
          puVar1 = (undefined4 *)(iVar7 * 4);
          bVar16 = CARRY4(uVar9,uVar12);
          uVar9 = uVar9 + uVar12;
          iVar10 = uVar13 + uVar14;
          iVar7 = CONCAT31((int3)(CONCAT22((short)((uint)iVar7 >> 0x10),
                                           CONCAT11((char)((uint)iVar7 >> 8) + (char)(uVar9 >> 8) +
                                                    bVar16,(char)iVar7)) >> 8),
                           (char)iVar7 + (char)uVar9 + CARRY4(uVar13,uVar14));
          *puVar15 = *puVar1;
          puVar15 = puVar15 + 1;
          sVar5 = (short)iVar10 + -1;
          uVar13 = CONCAT22((short)((uint)iVar10 >> 0x10),sVar5);
        } while (sVar5 != 0);
      }
      DAT_00041320 = DAT_00041320 + -1;
      iVar11 = iVar11 + *DAT_00040304 * 4;
      if (DAT_00041320 < 1) {
        do {
          if (DAT_00041318 == DAT_0004130c) {
            return;
          }
          FUN_0002b9c0();
        } while (DAT_00041320 < 1);
      }
      else {
        DAT_00041328 = DAT_00041328 + DAT_0004132c;
      }
      DAT_00041324 = DAT_00041324 + -1;
      if (DAT_00041324 < 1) break;
      DAT_00041330 = DAT_00041330 + DAT_00041334;
      DAT_00041338 = DAT_00041338 + DAT_0004133c;
      DAT_00041340 = DAT_00041340 + DAT_00041344;
    }
    do {
      if (DAT_0004131c == DAT_0004130c) {
        return;
      }
      FUN_0002ba8c();
    } while (DAT_00041324 < 1);
  } while( true );
}

