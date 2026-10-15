
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001febc(undefined4 param_1,int param_2,undefined4 unaff_EBX,uint param_4)

{
  longlong lVar1;
  byte *pbVar2;
  char cVar3;
  undefined1 uVar4;
  ushort uVar5;
  uint uVar7;
  uint uVar8;
  int iVar10;
  byte bVar11;
  byte *pbVar12;
  undefined2 uVar14;
  byte *pbVar13;
  undefined3 uVar16;
  byte *pbVar15;
  short sVar17;
  uint uVar18;
  uint unaff_ESI;
  int iVar19;
  uint unaff_EDI;
  int iVar20;
  uint *puVar21;
  uint *puVar22;
  bool bVar23;
  ushort uVar6;
  byte bVar9;
  
  uRam0002002b = (undefined1)param_1;
  uRam00020033 = (undefined1)((uint)param_1 >> 8);
  uRam0002003d = (undefined1)((uint)param_1 >> 0x10);
  iVar10 = (int)param_4 >> 8;
  iVar20 = (int)unaff_EDI >> 8;
  iVar19 = (int)unaff_ESI >> 8;
  uVar14 = (undefined2)((uint)unaff_EBX >> 0x10);
  uRam00020289 = uRam0002002b;
  uRam00020291 = uRam00020033;
  uRam0002029b = uRam0002003d;
  DAT_0003ee54 = unaff_EDI;
  DAT_0003ee58 = unaff_ESI;
  DAT_0003ee5c = param_4;
  if ((((-1 < iVar20 - iVar10) && ((iVar20 - iVar10) + iVar10 * 2 < 0x13f)) &&
      (-1 < iVar19 - iVar10)) && ((iVar19 - iVar10) + iVar10 * 2 < 199)) {
    puVar21 = (uint *)(iVar20 * 4 + iVar10 * -0x504 + iVar19 * 0x500 + param_2);
    sRam0002001e = (short)(param_4 >> 8) * 2;
    lVar1 = 0x1000000 / (longlong)(int)(param_4 << 1);
    DAT_0003ee60 = (int)lVar1;
    uRam00020053 = (undefined1)((ulonglong)lVar1 >> 8);
    iRam0002004d = DAT_0003ee60 << 0x18;
    iRam0002005a = (iVar10 * -2 + 0x140) * 4;
    DAT_0003ee48 = ((0x7f - (unaff_EDI & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60 >> 8;
    uVar7 = ((0x7f - (unaff_ESI & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60;
    DAT_0003ee4c = uVar7 >> 8;
    uVar16 = CONCAT21(uVar14,(char)(uVar7 >> 0x10));
    uVar7 = CONCAT22((short)((DAT_0003ee4c << 0x18) >> 0x10),sRam0002001e);
    pbVar12 = DAT_000402f8;
    iRam00020060 = iRam0002004d;
    uRam00020066 = uRam00020053;
    do {
      uVar8 = DAT_0003ee48 << 0x18;
      uVar18 = CONCAT22((short)(uVar8 >> 0x10),0x1111);
      pbVar13 = pbVar12;
      pbVar2 = (byte *)CONCAT31(uVar16,(char)(DAT_0003ee48 >> 8));
      do {
        puVar22 = puVar21;
        pbVar15 = pbVar2;
        bVar11 = *pbVar15;
        pbVar12 = (byte *)CONCAT31((int3)((uint)pbVar13 >> 8),bVar11);
        if (bVar11 != 0) {
          bVar11 = ~bVar11;
          uVar8 = *puVar22;
          uVar14 = (undefined2)((uint)pbVar13 >> 0x10);
          pbVar12 = (byte *)CONCAT22(uVar14,CONCAT11(0x11,bVar11));
          cVar3 = (byte)uVar8 + *pbVar12;
          if (CARRY1((byte)uVar8,*pbVar12)) {
            cVar3 = -1;
          }
          pbVar12 = (byte *)CONCAT22(uVar14,CONCAT11(0x11,bVar11));
          bVar9 = (byte)(uVar8 >> 8);
          uVar5 = CONCAT11(bVar9 + *pbVar12,cVar3);
          if (CARRY1(bVar9,*pbVar12)) {
            uVar5 = CONCAT11(0xff,cVar3);
          }
          bVar9 = (byte)(uVar8 >> 0x10);
          pbVar12 = (byte *)CONCAT22(uVar14,CONCAT11(0x11,bVar11));
          uVar4 = (undefined1)(uVar8 >> 0x18);
          uVar6 = CONCAT11(bVar9 + *pbVar12,uVar4);
          if (CARRY1(bVar9,*pbVar12)) {
            uVar6 = CONCAT11(0xff,uVar4);
          }
          uVar8 = uVar5 & 0xff | ((uint)(uVar5 >> 8) << 0x10) >> 8 | (uVar6 & 0xff00) << 8 |
                  CONCAT22(uVar5 >> 8,uVar6) << 0x18;
          *puVar22 = uVar8;
        }
        bVar23 = 0xeeeeeeee < uVar18;
        sVar17 = (short)(&DAT_11111111 + uVar18) + -1;
        uVar18 = CONCAT22((short)((uint)(&DAT_11111111 + uVar18) >> 0x10),sVar17);
        pbVar13 = pbVar12;
        pbVar2 = (byte *)CONCAT31((int3)((uint)pbVar15 >> 8),(char)pbVar15 + '\x11' + bVar23);
        puVar21 = puVar22 + 1;
      } while (sVar17 != 0);
      puVar21 = (uint *)((int)puVar22 + 0x11111115);
      uVar16 = CONCAT21((short)((uint)pbVar15 >> 0x10),
                        (char)((uint)pbVar15 >> 8) + '\x11' + (0xeeeeeeee < uVar7));
      sVar17 = (short)(&DAT_11111111 + uVar7) + -1;
      uVar7 = CONCAT22((short)((uint)(&DAT_11111111 + uVar7) >> 0x10),sVar17);
    } while (sVar17 != 0);
    return uVar8;
  }
  uVar7 = iVar20 - iVar10;
  if ((((int)uVar7 < 0x13f) && (uVar7 = uVar7 + iVar10 * 2, -1 < (int)uVar7)) &&
     ((uVar7 = iVar19 - iVar10, (int)uVar7 < 199 && (uVar7 = uVar7 + iVar10 * 2, 0 < (int)uVar7))))
  {
    iVar20 = iVar20 - iVar10;
    iVar19 = iVar19 - iVar10;
    DAT_0003ee40 = iVar10 * 2;
    lVar1 = 0x1000000 / (longlong)(int)(param_4 << 1);
    DAT_0003ee60 = (int)lVar1;
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
    uRam000202b1 = (undefined1)((ulonglong)lVar1 >> 8);
    iRam000202ab = DAT_0003ee60 << 0x18;
    if ((int)DAT_0003ee44 < 2) {
      DAT_0003ee44 = 2;
    }
    puVar21 = (uint *)((iVar20 + iVar19 * 0x140) * 4 + param_2);
    uRam0002027c = (undefined2)DAT_0003ee44;
    iRam000202b8 = (0x140 - DAT_0003ee44) * 4;
    DAT_0003ee48 = DAT_0003ee48 +
                   (((0x7f - (unaff_EDI + 0x6400 & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60 >> 8);
    DAT_0003ee4c = DAT_0003ee4c +
                   (((0x7f - (unaff_ESI + 0x6400 & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60 >> 8);
    uVar8 = DAT_0003ee40;
    if (0xf9 < (int)DAT_0003ee40) {
      uVar8 = 0xfa;
    }
    if ((int)uVar8 < 2) {
      uVar8 = 2;
    }
    uVar16 = CONCAT21(uVar14,(char)(DAT_0003ee4c >> 8));
    uVar8 = uVar8 | DAT_0003ee4c * 0x1000000;
    pbVar12 = DAT_000402f8;
    iRam000202be = iRam000202ab;
    uRam000202c4 = uRam000202b1;
    _DAT_0003ee50 = param_2;
    do {
      uVar7 = DAT_0003ee48 << 0x18;
      uVar18 = CONCAT22((short)(uVar7 >> 0x10),0x1111);
      pbVar13 = pbVar12;
      pbVar2 = (byte *)CONCAT31(uVar16,(char)(DAT_0003ee48 >> 8));
      do {
        puVar22 = puVar21;
        pbVar15 = pbVar2;
        bVar11 = *pbVar15;
        pbVar12 = (byte *)CONCAT31((int3)((uint)pbVar13 >> 8),bVar11);
        if (bVar11 != 0) {
          bVar11 = ~bVar11;
          uVar7 = *puVar22;
          uVar14 = (undefined2)((uint)pbVar13 >> 0x10);
          pbVar12 = (byte *)CONCAT22(uVar14,CONCAT11(0x11,bVar11));
          cVar3 = (byte)uVar7 + *pbVar12;
          if (CARRY1((byte)uVar7,*pbVar12)) {
            cVar3 = -1;
          }
          pbVar12 = (byte *)CONCAT22(uVar14,CONCAT11(0x11,bVar11));
          bVar9 = (byte)(uVar7 >> 8);
          uVar5 = CONCAT11(bVar9 + *pbVar12,cVar3);
          if (CARRY1(bVar9,*pbVar12)) {
            uVar5 = CONCAT11(0xff,cVar3);
          }
          bVar9 = (byte)(uVar7 >> 0x10);
          pbVar12 = (byte *)CONCAT22(uVar14,CONCAT11(0x11,bVar11));
          uVar4 = (undefined1)(uVar7 >> 0x18);
          uVar6 = CONCAT11(bVar9 + *pbVar12,uVar4);
          if (CARRY1(bVar9,*pbVar12)) {
            uVar6 = CONCAT11(0xff,uVar4);
          }
          uVar7 = uVar5 & 0xff | ((uint)(uVar5 >> 8) << 0x10) >> 8 | (uVar6 & 0xff00) << 8 |
                  CONCAT22(uVar5 >> 8,uVar6) << 0x18;
          *puVar22 = uVar7;
        }
        bVar23 = 0xeeeeeeee < uVar18;
        sVar17 = (short)(&DAT_11111111 + uVar18) + -1;
        uVar18 = CONCAT22((short)((uint)(&DAT_11111111 + uVar18) >> 0x10),sVar17);
        pbVar13 = pbVar12;
        pbVar2 = (byte *)CONCAT31((int3)((uint)pbVar15 >> 8),(char)pbVar15 + '\x11' + bVar23);
        puVar21 = puVar22 + 1;
      } while (sVar17 != 0);
      puVar21 = (uint *)((int)puVar22 + 0x11111115);
      uVar16 = CONCAT21((short)((uint)pbVar15 >> 0x10),
                        (char)((uint)pbVar15 >> 8) + '\x11' + (0xeeeeeeee < uVar8));
      sVar17 = (short)(&DAT_11111111 + uVar8) + -1;
      uVar8 = CONCAT22((short)((uint)(&DAT_11111111 + uVar8) >> 0x10),sVar17);
    } while (sVar17 != 0);
  }
  return uVar7;
}

