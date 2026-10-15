
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001f337(undefined4 param_1,int param_2,undefined4 unaff_EBX,uint param_4)

{
  byte bVar1;
  uint uVar2;
  longlong lVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  byte bVar10;
  ushort uVar8;
  int iVar9;
  char cVar11;
  uint uVar12;
  undefined2 uVar15;
  undefined3 uVar14;
  byte *pbVar13;
  short sVar16;
  uint uVar17;
  ushort uVar18;
  uint unaff_ESI;
  int iVar19;
  uint unaff_EDI;
  int iVar20;
  uint *puVar21;
  uint *puVar22;
  bool bVar23;
  
  iVar9 = (int)param_4 >> 8;
  iVar20 = (int)unaff_EDI >> 8;
  iVar19 = (int)unaff_ESI >> 8;
  uVar15 = (undefined2)((uint)unaff_EBX >> 0x10);
  DAT_0003ee54 = unaff_EDI;
  DAT_0003ee58 = unaff_ESI;
  DAT_0003ee5c = param_4;
  if ((((-1 < iVar20 - iVar9) && ((iVar20 - iVar9) + iVar9 * 2 < 0x13f)) && (-1 < iVar19 - iVar9))
     && ((iVar19 - iVar9) + iVar9 * 2 < 199)) {
    puVar21 = (uint *)(iVar20 * 4 + iVar9 * -0x504 + iVar19 * 0x500 + param_2);
    uRam0001f44d = (undefined2)(iVar9 * 2);
    DAT_0003ee60 = (uint)(0x1000000 / (longlong)(int)(param_4 << 1));
    uVar17 = DAT_0003ee60 << 0x18;
    iRam0001f486 = (iVar9 * -2 + 0x140) * 4;
    DAT_0003ee48 = ((0x7f - (unaff_EDI & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60 >> 8;
    uVar5 = ((0x7f - (unaff_ESI & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60;
    DAT_0003ee4c = uVar5 >> 8;
    uVar14 = CONCAT21(uVar15,(char)(uVar5 >> 0x10));
    uVar5 = DAT_0003ee60 >> 8 | DAT_0003ee4c << 0x18;
    uVar12 = iVar9 * 2 & 0xffff;
    do {
      uVar17 = CONCAT22((short)(uVar17 >> 0x10),0x1111);
      uVar6 = DAT_0003ee48 << 0x18;
      pbVar4 = (byte *)CONCAT31(uVar14,(char)(DAT_0003ee48 >> 8));
      do {
        puVar22 = puVar21;
        pbVar13 = pbVar4;
        bVar1 = *pbVar13;
        cVar11 = (char)uVar5;
        uVar5 = CONCAT22((short)(uVar5 >> 0x10),CONCAT11(bVar1,cVar11));
        if (bVar1 != 0) {
          uVar2 = *puVar22;
          bVar7 = (byte)uVar2 - bVar1;
          if ((byte)uVar2 < bVar1) {
            bVar7 = 0;
          }
          bVar10 = (byte)(uVar2 >> 8);
          uVar18 = CONCAT11(bVar10 - bVar1,bVar7);
          if (bVar10 < bVar1) {
            uVar18 = (ushort)bVar7;
          }
          bVar7 = (byte)(uVar2 >> 0x10);
          bVar10 = (byte)(uVar2 >> 0x18);
          uVar8 = CONCAT11(bVar7 - bVar1,bVar10);
          if (bVar7 < bVar1) {
            uVar8 = (ushort)bVar10;
          }
          *puVar22 = uVar18 & 0xff | ((uint)(uVar18 >> 8) << 0x10) >> 8 | (uVar8 & 0xff00) << 8 |
                     CONCAT22(uVar18 >> 8,uVar8) << 0x18;
        }
        bVar23 = CARRY4(uVar6,uVar17);
        uVar6 = uVar6 + uVar17;
        sVar16 = (short)uVar17 + -1;
        uVar17 = CONCAT22((short)(uVar17 >> 0x10),sVar16);
        pbVar4 = (byte *)CONCAT31((int3)((uint)pbVar13 >> 8),(char)pbVar13 + cVar11 + bVar23);
        puVar21 = puVar22 + 1;
      } while (sVar16 != 0);
      puVar21 = (uint *)((int)puVar22 + 0x11111115);
      bVar23 = CARRY4(uVar5,uVar17);
      uVar5 = uVar5 + uVar17;
      uVar14 = CONCAT21((short)((uint)pbVar13 >> 0x10),
                        (char)((uint)pbVar13 >> 8) + (char)uVar5 + bVar23);
      uVar18 = (short)uVar12 - 1;
      uVar12 = (uint)uVar18;
    } while (uVar18 != 0);
    return;
  }
  if (((iVar20 - iVar9 < 0x13f) && (-1 < (iVar20 - iVar9) + iVar9 * 2)) &&
     ((iVar19 - iVar9 < 199 && (-1 < (iVar19 - iVar9) + iVar9 * 2)))) {
    iVar20 = iVar20 - iVar9;
    iVar19 = iVar19 - iVar9;
    DAT_0003ee40 = iVar9 * 2;
    lVar3 = 0x1000000 / (longlong)(int)(param_4 << 1);
    DAT_0003ee60 = (uint)lVar3;
    DAT_0003ee48 = 0;
    DAT_0003ee4c = 0;
    DAT_0003ee44 = DAT_0003ee40;
    if (iVar20 < 0) {
      DAT_0003ee44 = DAT_0003ee40 + iVar20;
      DAT_0003ee48 = -iVar20 * DAT_0003ee60;
      iVar20 = 0;
    }
    if (0x13e < (int)(iVar20 + DAT_0003ee44)) {
      DAT_0003ee44 = 0x140 - iVar20;
    }
    if (iVar19 < 0) {
      DAT_0003ee40 = DAT_0003ee40 + iVar19;
      DAT_0003ee4c = -iVar19 * DAT_0003ee60;
      iVar19 = 0;
    }
    if (0xc6 < (int)(iVar19 + DAT_0003ee40)) {
      DAT_0003ee40 = 200 - iVar19;
    }
    uVar5 = DAT_0003ee60 << 0x18;
    if ((int)DAT_0003ee44 < 2) {
      DAT_0003ee44 = 2;
    }
    puVar21 = (uint *)((iVar20 + iVar19 * 0x140) * 4 + param_2);
    uRam0001f66b = (undefined2)DAT_0003ee44;
    iRam0001f6a4 = (0x140 - DAT_0003ee44) * 4;
    DAT_0003ee48 = DAT_0003ee48 +
                   (((0x7f - (unaff_EDI + 0x6400 & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60 >> 8);
    DAT_0003ee4c = DAT_0003ee4c +
                   (((0x7f - (unaff_ESI + 0x6400 & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60 >> 8);
    uVar14 = CONCAT21(uVar15,(char)(DAT_0003ee4c >> 8));
    uVar12 = CONCAT22((short)(DAT_0003ee4c * 0x1000000 >> 0x10),(short)((ulonglong)lVar3 >> 8));
    uVar17 = DAT_0003ee40;
    if (0xf9 < (int)DAT_0003ee40) {
      uVar17 = 0xfa;
    }
    _DAT_0003ee50 = param_2;
    if ((int)uVar17 < 2) {
      uVar17 = 2;
    }
    do {
      uVar5 = CONCAT22((short)(uVar5 >> 0x10),0x1111);
      uVar6 = DAT_0003ee48 << 0x18;
      pbVar4 = (byte *)CONCAT31(uVar14,(char)(DAT_0003ee48 >> 8));
      do {
        puVar22 = puVar21;
        pbVar13 = pbVar4;
        bVar1 = *pbVar13;
        cVar11 = (char)uVar12;
        uVar12 = CONCAT22((short)(uVar12 >> 0x10),CONCAT11(bVar1,cVar11));
        if (bVar1 != 0) {
          uVar2 = *puVar22;
          bVar7 = (byte)uVar2 - bVar1;
          if ((byte)uVar2 < bVar1) {
            bVar7 = 0;
          }
          bVar10 = (byte)(uVar2 >> 8);
          uVar18 = CONCAT11(bVar10 - bVar1,bVar7);
          if (bVar10 < bVar1) {
            uVar18 = (ushort)bVar7;
          }
          bVar7 = (byte)(uVar2 >> 0x10);
          bVar10 = (byte)(uVar2 >> 0x18);
          uVar8 = CONCAT11(bVar7 - bVar1,bVar10);
          if (bVar7 < bVar1) {
            uVar8 = (ushort)bVar10;
          }
          *puVar22 = uVar18 & 0xff | ((uint)(uVar18 >> 8) << 0x10) >> 8 | (uVar8 & 0xff00) << 8 |
                     CONCAT22(uVar18 >> 8,uVar8) << 0x18;
        }
        bVar23 = CARRY4(uVar6,uVar5);
        uVar6 = uVar6 + uVar5;
        sVar16 = (short)uVar5 + -1;
        uVar5 = CONCAT22((short)(uVar5 >> 0x10),sVar16);
        pbVar4 = (byte *)CONCAT31((int3)((uint)pbVar13 >> 8),(char)pbVar13 + cVar11 + bVar23);
        puVar21 = puVar22 + 1;
      } while (sVar16 != 0);
      puVar21 = (uint *)((int)puVar22 + 0x11111115);
      bVar23 = CARRY4(uVar12,uVar5);
      uVar12 = uVar12 + uVar5;
      uVar14 = CONCAT21((short)((uint)pbVar13 >> 0x10),
                        (char)((uint)pbVar13 >> 8) + (char)uVar12 + bVar23);
      uVar18 = (short)uVar17 - 1;
      uVar17 = (uint)uVar18;
    } while (uVar18 != 0);
  }
  return;
}

