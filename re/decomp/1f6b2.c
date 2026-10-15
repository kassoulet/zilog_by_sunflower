
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0001f6b2(uint param_1,int param_2,undefined4 unaff_EBX,uint param_4)

{
  byte bVar1;
  longlong lVar2;
  byte *pbVar3;
  char cVar4;
  undefined1 uVar5;
  ushort uVar6;
  uint uVar8;
  uint uVar9;
  int iVar11;
  undefined2 uVar12;
  undefined3 uVar14;
  byte *pbVar13;
  short sVar15;
  uint uVar16;
  uint unaff_ESI;
  int iVar17;
  uint unaff_EDI;
  int iVar18;
  uint *puVar19;
  uint *puVar20;
  bool bVar21;
  ushort uVar7;
  byte bVar10;
  
  cVar4 = (char)param_1;
  if (cVar4 != -1) {
    iVar11 = (int)param_4 >> 8;
    iVar18 = (int)unaff_EDI >> 8;
    iVar17 = (int)unaff_ESI >> 8;
    uVar12 = (undefined2)((uint)unaff_EBX >> 0x10);
    cRam0001f80f = cVar4;
    cRam0001fa77 = cVar4;
    DAT_0003ee54 = unaff_EDI;
    DAT_0003ee58 = unaff_ESI;
    DAT_0003ee5c = param_4;
    if ((((-1 < iVar18 - iVar11) && ((iVar18 - iVar11) + iVar11 * 2 < 0x13f)) &&
        (-1 < iVar17 - iVar11)) && ((iVar17 - iVar11) + iVar11 * 2 < 199)) {
      puVar19 = (uint *)(iVar18 * 4 + iVar11 * -0x504 + iVar17 * 0x500 + param_2);
      sRam0001f802 = (short)(param_4 >> 8) * 2;
      lVar2 = 0x1000000 / (longlong)(int)(param_4 << 1);
      DAT_0003ee60 = (int)lVar2;
      uRam0001f835 = (undefined1)((ulonglong)lVar2 >> 8);
      iRam0001f82f = DAT_0003ee60 << 0x18;
      iRam0001f83c = (iVar11 * -2 + 0x140) * 4;
      DAT_0003ee48 = ((0x7f - (unaff_EDI & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60 >> 8;
      uVar8 = ((0x7f - (unaff_ESI & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60;
      DAT_0003ee4c = uVar8 >> 8;
      uVar14 = CONCAT21(uVar12,(char)(uVar8 >> 0x10));
      uVar8 = CONCAT22((short)((DAT_0003ee4c << 0x18) >> 0x10),sRam0001f802);
      iVar11 = DAT_000402f8;
      iRam0001f842 = iRam0001f82f;
      uRam0001f848 = uRam0001f835;
      do {
        uVar9 = DAT_0003ee48 << 0x18;
        uVar16 = CONCAT22((short)(uVar9 >> 0x10),0x1111);
        iVar17 = iVar11;
        pbVar3 = (byte *)CONCAT31(uVar14,(char)(DAT_0003ee48 >> 8));
        do {
          puVar20 = puVar19;
          pbVar13 = pbVar3;
          bVar1 = *pbVar13;
          iVar11 = CONCAT31((int3)((uint)iVar17 >> 8),bVar1);
          if (bVar1 != 0) {
            uVar9 = *puVar20;
            uVar12 = (undefined2)((uint)iVar17 >> 0x10);
            bVar1 = *(byte *)CONCAT22(uVar12,CONCAT11(0x11,~bVar1));
            iVar11 = (uint)CONCAT21(uVar12,bVar1) << 8;
            cVar4 = (byte)uVar9 + bVar1;
            if (CARRY1((byte)uVar9,bVar1)) {
              cVar4 = -1;
            }
            bVar10 = (byte)(uVar9 >> 8);
            uVar6 = CONCAT11(bVar10 + bVar1,cVar4);
            if (CARRY1(bVar10,bVar1)) {
              uVar6 = CONCAT11(0xff,cVar4);
            }
            bVar10 = (byte)(uVar9 >> 0x10);
            uVar5 = (undefined1)(uVar9 >> 0x18);
            uVar7 = CONCAT11(bVar10 + bVar1,uVar5);
            if (CARRY1(bVar10,bVar1)) {
              uVar7 = CONCAT11(0xff,uVar5);
            }
            uVar9 = uVar6 & 0xff | ((uint)(uVar6 >> 8) << 0x10) >> 8 | (uVar7 & 0xff00) << 8 |
                    CONCAT22(uVar6 >> 8,uVar7) << 0x18;
            *puVar20 = uVar9;
          }
          bVar21 = 0xeeeeeeee < uVar16;
          sVar15 = (short)(&DAT_11111111 + uVar16) + -1;
          uVar16 = CONCAT22((short)((uint)(&DAT_11111111 + uVar16) >> 0x10),sVar15);
          iVar17 = iVar11;
          pbVar3 = (byte *)CONCAT31((int3)((uint)pbVar13 >> 8),(char)pbVar13 + '\x11' + bVar21);
          puVar19 = puVar20 + 1;
        } while (sVar15 != 0);
        puVar19 = (uint *)((int)puVar20 + 0x11111115);
        uVar14 = CONCAT21((short)((uint)pbVar13 >> 0x10),
                          (char)((uint)pbVar13 >> 8) + '\x11' + (0xeeeeeeee < uVar8));
        sVar15 = (short)(&DAT_11111111 + uVar8) + -1;
        uVar8 = CONCAT22((short)((uint)(&DAT_11111111 + uVar8) >> 0x10),sVar15);
      } while (sVar15 != 0);
      return uVar9;
    }
    param_1 = iVar18 - iVar11;
    if ((((int)param_1 < 0x13f) && (param_1 = param_1 + iVar11 * 2, -1 < (int)param_1)) &&
       ((param_1 = iVar17 - iVar11, (int)param_1 < 199 &&
        (param_1 = param_1 + iVar11 * 2, 0 < (int)param_1)))) {
      iVar18 = iVar18 - iVar11;
      iVar17 = iVar17 - iVar11;
      DAT_0003ee40 = iVar11 * 2;
      lVar2 = 0x1000000 / (longlong)(int)(param_4 << 1);
      DAT_0003ee60 = (int)lVar2;
      DAT_0003ee48 = 0;
      DAT_0003ee4c = 0;
      DAT_0003ee44 = DAT_0003ee40;
      if (iVar18 < 0) {
        DAT_0003ee44 = DAT_0003ee40 + iVar18;
        DAT_0003ee48 = -iVar18 * DAT_0003ee60;
        iVar18 = 0;
      }
      if (0x13e < (int)(iVar18 + DAT_0003ee44)) {
        DAT_0003ee44 = 0x140 - iVar18;
      }
      if (iVar17 < 0) {
        DAT_0003ee40 = DAT_0003ee40 + iVar17;
        DAT_0003ee4c = -iVar17 * DAT_0003ee60;
        iVar17 = 0;
      }
      if (0xc6 < (int)(iVar17 + DAT_0003ee40)) {
        DAT_0003ee40 = 200 - iVar17;
      }
      uRam0001fa9d = (undefined1)((ulonglong)lVar2 >> 8);
      iRam0001fa97 = DAT_0003ee60 << 0x18;
      if ((int)DAT_0003ee44 < 2) {
        DAT_0003ee44 = 2;
      }
      puVar19 = (uint *)((iVar18 + iVar17 * 0x140) * 4 + param_2);
      uRam0001fa6a = (undefined2)DAT_0003ee44;
      iRam0001faa4 = (0x140 - DAT_0003ee44) * 4;
      DAT_0003ee48 = DAT_0003ee48 +
                     (((0x7f - (unaff_EDI + 0x6400 & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60 >> 8)
      ;
      DAT_0003ee4c = DAT_0003ee4c +
                     (((0x7f - (unaff_ESI + 0x6400 & 0xff)) + (param_4 & 0xff)) * DAT_0003ee60 >> 8)
      ;
      uVar8 = DAT_0003ee40;
      if (0xf9 < (int)DAT_0003ee40) {
        uVar8 = 0xfa;
      }
      if ((int)uVar8 < 2) {
        uVar8 = 2;
      }
      uVar14 = CONCAT21(uVar12,(char)(DAT_0003ee4c >> 8));
      uVar8 = uVar8 | DAT_0003ee4c * 0x1000000;
      iVar11 = DAT_000402f8;
      iRam0001faaa = iRam0001fa97;
      uRam0001fab0 = uRam0001fa9d;
      _DAT_0003ee50 = param_2;
      do {
        param_1 = DAT_0003ee48 << 0x18;
        uVar9 = CONCAT22((short)(param_1 >> 0x10),0x1111);
        iVar17 = iVar11;
        pbVar3 = (byte *)CONCAT31(uVar14,(char)(DAT_0003ee48 >> 8));
        do {
          puVar20 = puVar19;
          pbVar13 = pbVar3;
          bVar1 = *pbVar13;
          iVar11 = CONCAT31((int3)((uint)iVar17 >> 8),bVar1);
          if (bVar1 != 0) {
            uVar16 = *puVar20;
            uVar12 = (undefined2)((uint)iVar17 >> 0x10);
            bVar1 = *(byte *)CONCAT22(uVar12,CONCAT11(0x11,~bVar1));
            iVar11 = (uint)CONCAT21(uVar12,bVar1) << 8;
            cVar4 = (byte)uVar16 + bVar1;
            if (CARRY1((byte)uVar16,bVar1)) {
              cVar4 = -1;
            }
            bVar10 = (byte)(uVar16 >> 8);
            uVar6 = CONCAT11(bVar10 + bVar1,cVar4);
            if (CARRY1(bVar10,bVar1)) {
              uVar6 = CONCAT11(0xff,cVar4);
            }
            bVar10 = (byte)(uVar16 >> 0x10);
            uVar5 = (undefined1)(uVar16 >> 0x18);
            uVar7 = CONCAT11(bVar10 + bVar1,uVar5);
            if (CARRY1(bVar10,bVar1)) {
              uVar7 = CONCAT11(0xff,uVar5);
            }
            param_1 = uVar6 & 0xff | ((uint)(uVar6 >> 8) << 0x10) >> 8 | (uVar7 & 0xff00) << 8 |
                      CONCAT22(uVar6 >> 8,uVar7) << 0x18;
            *puVar20 = param_1;
          }
          bVar21 = 0xeeeeeeee < uVar9;
          sVar15 = (short)(&DAT_11111111 + uVar9) + -1;
          uVar9 = CONCAT22((short)((uint)(&DAT_11111111 + uVar9) >> 0x10),sVar15);
          iVar17 = iVar11;
          pbVar3 = (byte *)CONCAT31((int3)((uint)pbVar13 >> 8),(char)pbVar13 + '\x11' + bVar21);
          puVar19 = puVar20 + 1;
        } while (sVar15 != 0);
        puVar19 = (uint *)((int)puVar20 + 0x11111115);
        uVar14 = CONCAT21((short)((uint)pbVar13 >> 0x10),
                          (char)((uint)pbVar13 >> 8) + '\x11' + (0xeeeeeeee < uVar8));
        sVar15 = (short)(&DAT_11111111 + uVar8) + -1;
        uVar8 = CONCAT22((short)((uint)(&DAT_11111111 + uVar8) >> 0x10),sVar15);
      } while (sVar15 != 0);
    }
  }
  return param_1;
}

