
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0002d0bc(int param_1,int param_2,int unaff_EBX)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char cVar9;
  undefined1 uVar10;
  ushort uVar11;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint *puVar19;
  bool bVar20;
  undefined2 uVar12;
  byte bVar13;
  
  iVar7 = 1;
  iVar16 = *(int *)(param_1 + 4);
  iVar6 = param_1 + 0xc;
  iVar8 = iVar16;
  iVar17 = iVar16;
  iVar18 = param_1;
  DAT_00041448 = param_1;
  DAT_0004143c = param_1;
  if (1 < param_2) {
    do {
      iVar1 = *(int *)(iVar6 + 4);
      iVar16 = iVar1;
      DAT_00041448 = iVar6;
      if ((iVar8 <= iVar1) && (iVar16 = iVar8, DAT_00041448 = iVar18, iVar17 < iVar1)) {
        iVar17 = iVar1;
        DAT_0004143c = iVar6;
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 0xc;
      iVar8 = iVar16;
      iVar18 = DAT_00041448;
    } while (iVar7 < param_2);
  }
  DAT_00041444 = iVar6 + -0xc;
  bVar20 = DAT_00041448 == DAT_0004143c;
  DAT_00041440 = param_1;
  DAT_0004144c = DAT_00041448;
  while( true ) {
    if (bVar20) {
      return;
    }
    FUN_0002ced0();
    if (0 < DAT_00041450) break;
    bVar20 = DAT_00041448 == DAT_0004143c;
  }
  do {
    if (DAT_0004144c == DAT_0004143c) {
      return;
    }
    FUN_0002cf9c();
  } while (DAT_00041454 < 1);
  DAT_00041470 = unaff_EBX << 0x10;
  _DAT_00041474 = unaff_EBX >> 0x10;
  iVar16 = DAT_00040304[2] + (iVar16 + 0xffff >> 0x10) * *DAT_00040304 * 4;
  do {
    while( true ) {
      uVar4 = DAT_00041470;
      iVar8 = DAT_00041460 + 0xffff >> 0x10;
      iVar17 = (DAT_00041458 + 0xffff >> 0x10) - iVar8;
      if (0 < iVar17) {
        puVar19 = (uint *)(iVar8 * 4 + iVar16);
        lVar3 = (longlong)(iVar8 * 0x10000 - DAT_00041460) * (longlong)unaff_EBX;
        uVar14 = DAT_00041468 + ((uint)lVar3 >> 0x10 | (int)((ulonglong)lVar3 >> 0x20) << 0x10);
        uVar15 = uVar14 * 0x10000 | uVar14 >> 0x10;
        uVar14 = (uint)CONCAT11(DAT_00041474,(char)(uVar14 >> 0x10));
        do {
          uVar2 = *puVar19;
          bVar5 = (byte)uVar14;
          cVar9 = (byte)uVar2 + bVar5;
          if (CARRY1((byte)uVar2,bVar5)) {
            cVar9 = -1;
          }
          bVar13 = (byte)(uVar2 >> 8);
          uVar11 = CONCAT11(bVar13 + bVar5,cVar9);
          if (CARRY1(bVar13,bVar5)) {
            uVar11 = CONCAT11(0xff,cVar9);
          }
          bVar13 = (byte)(uVar2 >> 0x10);
          uVar10 = (undefined1)(uVar11 >> 8);
          uVar12 = CONCAT11(bVar13 + bVar5,uVar10);
          if (CARRY1(bVar13,bVar5)) {
            uVar12 = CONCAT11(0xff,uVar10);
          }
          *puVar19 = CONCAT22((ushort)(uVar2 >> 0x18),uVar12) << 8 | uVar11 & 0xff;
          bVar20 = CARRY4(uVar15,uVar4);
          uVar15 = uVar15 + uVar4;
          uVar14 = CONCAT31((int3)(uVar14 >> 8),bVar5 + (char)(uVar14 >> 8) + bVar20);
          puVar19 = puVar19 + 1;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
      }
      DAT_00041450 = DAT_00041450 + -1;
      iVar16 = iVar16 + *DAT_00040304 * 4;
      if (DAT_00041450 < 1) {
        do {
          if (DAT_00041448 == DAT_0004143c) {
            return;
          }
          FUN_0002ced0();
        } while (DAT_00041450 < 1);
      }
      else {
        DAT_00041458 = DAT_00041458 + DAT_0004145c;
      }
      DAT_00041454 = DAT_00041454 + -1;
      if (DAT_00041454 < 1) break;
      DAT_00041460 = DAT_00041460 + DAT_00041464;
      DAT_00041468 = DAT_00041468 + DAT_0004146c;
    }
    do {
      if (DAT_0004144c == DAT_0004143c) {
        return;
      }
      FUN_0002cf9c();
    } while (DAT_00041454 < 1);
  } while( true );
}

