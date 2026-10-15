
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001efbc(undefined4 param_1,int param_2,undefined4 unaff_EBX,uint param_4)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  undefined1 uVar8;
  byte bVar11;
  int iVar10;
  char cVar12;
  uint uVar13;
  undefined2 uVar16;
  undefined3 uVar15;
  byte *pbVar14;
  short sVar17;
  uint uVar18;
  ushort uVar19;
  uint unaff_ESI;
  int iVar20;
  uint unaff_EDI;
  int iVar21;
  uint *puVar22;
  uint *puVar23;
  bool bVar24;
  ushort uVar9;
  
  iVar10 = (int)param_4 >> 8;
  iVar21 = (int)unaff_EDI >> 8;
  iVar20 = (int)unaff_ESI >> 8;
  uVar16 = (undefined2)((uint)unaff_EBX >> 0x10);
  DAT_0003ee54 = unaff_EDI;
  DAT_0003ee58 = unaff_ESI;
  DAT_0003ee5c = param_4;
  if ((((-1 < iVar21 - iVar10) && ((iVar21 - iVar10) + iVar10 * 2 < 0x13f)) &&
      (-1 < iVar20 - iVar10)) && ((iVar20 - iVar10) + iVar10 * 2 < 199)) {
    puVar22 = (uint *)(iVar21 * 4 + iVar10 * -0x504 + iVar20 * 0x500 + param_2);
    uRam0001f0d2 = (undefined2)(iVar10 * 2);
    DAT_0003ee60 = (uint)(0x1000000 / (longlong)(int)(param_4 << 1));
    uVar18 = DAT_0003ee60 << 0x18;
    iRam0001f10b = (iVar10 * -2 + 0x140) * 4;
    DAT_0003ee48 = ((0x7f - (unaff_EDI & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60 >> 8;
    uVar5 = ((0x7f - (unaff_ESI & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60;
    DAT_0003ee4c = uVar5 >> 8;
    uVar15 = CONCAT21(uVar16,(char)(uVar5 >> 0x10));
    uVar5 = DAT_0003ee60 >> 8 | DAT_0003ee4c << 0x18;
    uVar13 = iVar10 * 2 & 0xffff;
    do {
      uVar18 = CONCAT22((short)(uVar18 >> 0x10),0x1111);
      uVar6 = DAT_0003ee48 << 0x18;
      pbVar4 = (byte *)CONCAT31(uVar15,(char)(DAT_0003ee48 >> 8));
      do {
        puVar23 = puVar22;
        pbVar14 = pbVar4;
        bVar1 = *pbVar14;
        cVar12 = (char)uVar5;
        uVar5 = CONCAT22((short)(uVar5 >> 0x10),CONCAT11(bVar1,cVar12));
        if (bVar1 != 0) {
          uVar2 = *puVar23;
          cVar7 = (byte)uVar2 + bVar1;
          if (CARRY1((byte)uVar2,bVar1)) {
            cVar7 = -1;
          }
          bVar11 = (byte)(uVar2 >> 8);
          uVar19 = CONCAT11(bVar11 + bVar1,cVar7);
          if (CARRY1(bVar11,bVar1)) {
            uVar19 = CONCAT11(0xff,cVar7);
          }
          bVar11 = (byte)(uVar2 >> 0x10);
          uVar8 = (undefined1)(uVar2 >> 0x18);
          uVar9 = CONCAT11(bVar11 + bVar1,uVar8);
          if (CARRY1(bVar11,bVar1)) {
            uVar9 = CONCAT11(0xff,uVar8);
          }
          *puVar23 = uVar19 & 0xff | ((uint)(uVar19 >> 8) << 0x10) >> 8 | (uVar9 & 0xff00) << 8 |
                     CONCAT22(uVar19 >> 8,uVar9) << 0x18;
        }
        bVar24 = CARRY4(uVar6,uVar18);
        uVar6 = uVar6 + uVar18;
        sVar17 = (short)uVar18 + -1;
        uVar18 = CONCAT22((short)(uVar18 >> 0x10),sVar17);
        pbVar4 = (byte *)CONCAT31((int3)((uint)pbVar14 >> 8),(char)pbVar14 + cVar12 + bVar24);
        puVar22 = puVar23 + 1;
      } while (sVar17 != 0);
      puVar22 = (uint *)((int)puVar23 + 0x11111115);
      bVar24 = CARRY4(uVar5,uVar18);
      uVar5 = uVar5 + uVar18;
      uVar15 = CONCAT21((short)((uint)pbVar14 >> 0x10),
                        (char)((uint)pbVar14 >> 8) + (char)uVar5 + bVar24);
      uVar19 = (short)uVar13 - 1;
      uVar13 = (uint)uVar19;
    } while (uVar19 != 0);
    return;
  }
  if (((iVar21 - iVar10 < 0x13f) && (-1 < (iVar21 - iVar10) + iVar10 * 2)) &&
     ((iVar20 - iVar10 < 199 && (-1 < (iVar20 - iVar10) + iVar10 * 2)))) {
    iVar21 = iVar21 - iVar10;
    iVar20 = iVar20 - iVar10;
    DAT_0003ee40 = iVar10 * 2;
    lVar3 = 0x1000000 / (longlong)(int)(param_4 << 1);
    DAT_0003ee60 = (uint)lVar3;
    DAT_0003ee48 = 0;
    DAT_0003ee4c = 0;
    DAT_0003ee44 = DAT_0003ee40;
    if (iVar21 < 0) {
      DAT_0003ee44 = DAT_0003ee40 + iVar21;
      DAT_0003ee48 = -iVar21 * DAT_0003ee60;
      iVar21 = 0;
    }
    if (0x13e < (int)(iVar21 + DAT_0003ee44)) {
      DAT_0003ee44 = 0x140 - iVar21;
    }
    if (iVar20 < 0) {
      DAT_0003ee40 = DAT_0003ee40 + iVar20;
      DAT_0003ee4c = -iVar20 * DAT_0003ee60;
      iVar20 = 0;
    }
    if (0xc6 < (int)(iVar20 + DAT_0003ee40)) {
      DAT_0003ee40 = 200 - iVar20;
    }
    uVar5 = DAT_0003ee60 << 0x18;
    if ((int)DAT_0003ee44 < 2) {
      DAT_0003ee44 = 2;
    }
    puVar22 = (uint *)((iVar21 + iVar20 * 0x140) * 4 + param_2);
    uRam0001f2f0 = (undefined2)DAT_0003ee44;
    iRam0001f329 = (0x140 - DAT_0003ee44) * 4;
    DAT_0003ee48 = DAT_0003ee48 +
                   (((0x7f - (unaff_EDI + 0x6400 & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60 >> 8);
    DAT_0003ee4c = DAT_0003ee4c +
                   (((0x7f - (unaff_ESI + 0x6400 & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60 >> 8);
    uVar15 = CONCAT21(uVar16,(char)(DAT_0003ee4c >> 8));
    uVar13 = CONCAT22((short)(DAT_0003ee4c * 0x1000000 >> 0x10),(short)((ulonglong)lVar3 >> 8));
    uVar18 = DAT_0003ee40;
    if (0xf9 < (int)DAT_0003ee40) {
      uVar18 = 0xfa;
    }
    _DAT_0003ee50 = param_2;
    if ((int)uVar18 < 2) {
      uVar18 = 2;
    }
    do {
      uVar5 = CONCAT22((short)(uVar5 >> 0x10),0x1111);
      uVar6 = DAT_0003ee48 << 0x18;
      pbVar4 = (byte *)CONCAT31(uVar15,(char)(DAT_0003ee48 >> 8));
      do {
        puVar23 = puVar22;
        pbVar14 = pbVar4;
        bVar1 = *pbVar14;
        cVar12 = (char)uVar13;
        uVar13 = CONCAT22((short)(uVar13 >> 0x10),CONCAT11(bVar1,cVar12));
        if (bVar1 != 0) {
          uVar2 = *puVar23;
          cVar7 = (byte)uVar2 + bVar1;
          if (CARRY1((byte)uVar2,bVar1)) {
            cVar7 = -1;
          }
          bVar11 = (byte)(uVar2 >> 8);
          uVar19 = CONCAT11(bVar11 + bVar1,cVar7);
          if (CARRY1(bVar11,bVar1)) {
            uVar19 = CONCAT11(0xff,cVar7);
          }
          bVar11 = (byte)(uVar2 >> 0x10);
          uVar8 = (undefined1)(uVar2 >> 0x18);
          uVar9 = CONCAT11(bVar11 + bVar1,uVar8);
          if (CARRY1(bVar11,bVar1)) {
            uVar9 = CONCAT11(0xff,uVar8);
          }
          *puVar23 = uVar19 & 0xff | ((uint)(uVar19 >> 8) << 0x10) >> 8 | (uVar9 & 0xff00) << 8 |
                     CONCAT22(uVar19 >> 8,uVar9) << 0x18;
        }
        bVar24 = CARRY4(uVar6,uVar5);
        uVar6 = uVar6 + uVar5;
        sVar17 = (short)uVar5 + -1;
        uVar5 = CONCAT22((short)(uVar5 >> 0x10),sVar17);
        pbVar4 = (byte *)CONCAT31((int3)((uint)pbVar14 >> 8),(char)pbVar14 + cVar12 + bVar24);
        puVar22 = puVar23 + 1;
      } while (sVar17 != 0);
      puVar22 = (uint *)((int)puVar23 + 0x11111115);
      bVar24 = CARRY4(uVar13,uVar5);
      uVar13 = uVar13 + uVar5;
      uVar15 = CONCAT21((short)((uint)pbVar14 >> 0x10),
                        (char)((uint)pbVar14 >> 8) + (char)uVar13 + bVar24);
      uVar19 = (short)uVar18 - 1;
      uVar18 = (uint)uVar19;
    } while (uVar19 != 0);
  }
  return;
}

