
void FUN_0002c7ec(int param_1,int param_2,undefined4 unaff_EBX,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  bool bVar14;
  
  iVar7 = 1;
  iVar10 = *(int *)(param_1 + 4);
  iVar4 = param_1 + 0x10;
  iVar9 = iVar10;
  iVar5 = param_1;
  DAT_000413b8 = param_1;
  iVar12 = iVar10;
  DAT_000413ac = param_1;
  if (1 < param_2) {
    do {
      iVar2 = *(int *)(iVar4 + 4);
      iVar10 = iVar2;
      DAT_000413b8 = iVar4;
      if ((iVar9 <= iVar2) && (iVar10 = iVar9, DAT_000413b8 = iVar5, iVar12 < iVar2)) {
        iVar12 = iVar2;
        DAT_000413ac = iVar4;
      }
      iVar7 = iVar7 + 1;
      iVar4 = iVar4 + 0x10;
      iVar9 = iVar10;
      iVar5 = DAT_000413b8;
    } while (iVar7 < param_2);
  }
  DAT_000413b4 = iVar4 + -0x10;
  bVar14 = DAT_000413b8 == DAT_000413ac;
  DAT_000413b0 = param_1;
  DAT_000413bc = DAT_000413b8;
  while( true ) {
    if (bVar14) {
      return;
    }
    FUN_0002c600();
    if (0 < DAT_000413c0) break;
    bVar14 = DAT_000413b8 == DAT_000413ac;
  }
  do {
    if (DAT_000413bc == DAT_000413ac) {
      return;
    }
    FUN_0002c6cc();
  } while (DAT_000413c4 < 1);
  iVar10 = *DAT_00040304 * 4 * (iVar10 + 0xffff >> 0x10) + DAT_00040304[2];
  DAT_000413e8 = param_4;
  do {
    while( true ) {
      iVar9 = DAT_000413d0 + 0xffff >> 0x10;
      uVar8 = (DAT_000413c8 + 0xffff >> 0x10) - iVar9;
      if (0 < (int)uVar8) {
        iVar5 = (int)((ulonglong)((longlong)(iVar9 * 0x10000 - DAT_000413d0) * (longlong)param_4) >>
                     0x10) + DAT_000413d8;
        puVar13 = (undefined4 *)(iVar9 * 4 + iVar10);
        uVar8 = iVar5 * 0x10000 | uVar8 & 0xffff;
        iVar9 = CONCAT22((ushort)((uint)unaff_EBX >> 0x12),(ushort)(byte)((uint)iVar5 >> 0x10));
        uVar11 = DAT_000413e8 * 0x10000;
        cVar3 = DAT_000413e8._2_1_;
        do {
          puVar1 = (undefined4 *)(iVar9 * 4);
          iVar5 = uVar8 + uVar11;
          iVar9 = CONCAT31((int3)((uint)iVar9 >> 8),(char)iVar9 + cVar3 + CARRY4(uVar8,uVar11));
          *puVar13 = *puVar1;
          puVar13 = puVar13 + 1;
          sVar6 = (short)iVar5 + -1;
          uVar8 = CONCAT22((short)((uint)iVar5 >> 0x10),sVar6);
        } while (sVar6 != 0);
      }
      iVar10 = iVar10 + *DAT_00040304 * 4;
      DAT_000413c0 = DAT_000413c0 + -1;
      if (DAT_000413c0 < 1) {
        do {
          if (DAT_000413b8 == DAT_000413ac) {
            return;
          }
          FUN_0002c600();
        } while (DAT_000413c0 < 1);
      }
      else {
        DAT_000413c8 = DAT_000413c8 + DAT_000413cc;
      }
      DAT_000413c4 = DAT_000413c4 + -1;
      if (DAT_000413c4 < 1) break;
      DAT_000413d0 = DAT_000413d0 + DAT_000413d4;
      DAT_000413d8 = DAT_000413d8 + DAT_000413dc;
      DAT_000413e0 = DAT_000413e0 + DAT_000413e4;
    }
    do {
      if (DAT_000413bc == DAT_000413ac) {
        return;
      }
      FUN_0002c6cc();
    } while (DAT_000413c4 < 1);
  } while( true );
}

