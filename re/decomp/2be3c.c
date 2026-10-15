
void FUN_0002be3c(int param_1,int param_2,undefined4 unaff_EBX,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  byte bVar5;
  byte bVar6;
  int iVar4;
  short sVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int extraout_EDX;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint *puVar17;
  bool bVar18;
  
  iVar8 = 1;
  iVar13 = *(int *)(param_1 + 4);
  iVar4 = param_1 + 0x10;
  iVar12 = iVar13;
  iVar9 = param_1;
  DAT_00041318 = param_1;
  DAT_0004130c = param_1;
  if (1 < param_2) {
    do {
      iVar1 = *(int *)(iVar4 + 4);
      iVar10 = iVar1;
      DAT_00041318 = iVar4;
      if ((iVar12 <= iVar1) && (iVar10 = iVar12, DAT_00041318 = iVar9, iVar13 < iVar1)) {
        iVar13 = iVar1;
        DAT_0004130c = iVar4;
      }
      iVar8 = iVar8 + 1;
      iVar4 = iVar4 + 0x10;
      iVar12 = iVar10;
      iVar9 = DAT_00041318;
    } while (iVar8 < param_2);
  }
  DAT_00041314 = iVar4 + -0x10;
  bVar18 = DAT_00041318 == DAT_0004130c;
  DAT_00041310 = param_1;
  DAT_0004131c = DAT_00041318;
  while( true ) {
    if (bVar18) {
      return;
    }
    FUN_0002b9c0();
    if (0 < DAT_00041320) break;
    bVar18 = DAT_00041318 == DAT_0004130c;
  }
  do {
    if (DAT_0004131c == DAT_0004130c) {
      return;
    }
    FUN_0002ba8c();
  } while (DAT_00041324 < 1);
  DAT_0004134c = param_5;
  iVar13 = DAT_00040304[2] + (extraout_EDX + 0xffff >> 0x10) * *DAT_00040304 * 4;
  DAT_00041348 = param_4;
  do {
    while( true ) {
      iVar12 = DAT_00041330 + 0xffff >> 0x10;
      uVar15 = (DAT_00041328 + 0xffff >> 0x10) - iVar12;
      if (0 < (int)uVar15) {
        iVar9 = iVar12 * 0x10000 - DAT_00041330;
        lVar3 = (longlong)iVar9 * (longlong)param_4;
        iVar4 = DAT_00041338 + ((uint)lVar3 >> 0x10 | (int)((ulonglong)lVar3 >> 0x20) << 0x10);
        puVar17 = (uint *)(iVar12 * 4 + iVar13);
        lVar3 = (longlong)iVar9 * (longlong)param_5;
        iVar12 = DAT_00041340 + ((uint)lVar3 >> 0x10 | (int)((ulonglong)lVar3 >> 0x20) << 0x10);
        uVar15 = iVar4 * 0x10000 | uVar15 & 0xffff;
        iVar9 = CONCAT22((ushort)((uint)unaff_EBX >> 0x12),
                         CONCAT11((char)((uint)iVar12 >> 0x10),(char)((uint)iVar4 >> 0x10)));
        uVar16 = DAT_00041348 * 0x10000;
        uVar14 = DAT_0004134c * 0x10000;
        uVar11 = CONCAT22((short)((uint)(iVar12 * 0x10000) >> 0x10),
                          CONCAT11(DAT_0004134c._2_1_,DAT_00041348._2_1_));
        do {
          uVar2 = *(undefined4 *)(iVar9 * 4);
          bVar5 = (byte)((uint)uVar2 >> 8);
          bVar5 = (byte)(bVar5 + *(byte *)((int)puVar17 + 1)) >> 1 |
                  CARRY1(bVar5,*(byte *)((int)puVar17 + 1)) << 7;
          bVar6 = (byte)((uint)uVar2 >> 0x10);
          bVar18 = CARRY4(uVar11,uVar14);
          uVar11 = uVar11 + uVar14;
          iVar12 = uVar15 + uVar16;
          iVar9 = CONCAT31((int3)(CONCAT22((short)((uint)iVar9 >> 0x10),
                                           CONCAT11((char)((uint)iVar9 >> 8) + (char)(uVar11 >> 8) +
                                                    bVar18,(char)iVar9)) >> 8),
                           (char)iVar9 + (char)uVar11 + CARRY4(uVar15,uVar16));
          *puVar17 = CONCAT22((ushort)((uint)uVar2 >> 0x18),
                              CONCAT11((byte)(bVar6 + *(byte *)((int)puVar17 + 2)) >> 1 |
                                       CARRY1(bVar6,*(byte *)((int)puVar17 + 2)) << 7,bVar5)) << 8 |
                     CONCAT11(bVar5,(byte)((byte)uVar2 + (byte)*puVar17) >> 1 |
                                    CARRY1((byte)uVar2,(byte)*puVar17) << 7) & 0xff;
          puVar17 = puVar17 + 1;
          sVar7 = (short)iVar12 + -1;
          uVar15 = CONCAT22((short)((uint)iVar12 >> 0x10),sVar7);
        } while (sVar7 != 0);
      }
      DAT_00041320 = DAT_00041320 + -1;
      iVar13 = iVar13 + *DAT_00040304 * 4;
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

