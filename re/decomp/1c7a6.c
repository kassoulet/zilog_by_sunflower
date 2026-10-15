
undefined8 FUN_0001c7a6(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  byte bVar8;
  uint uVar5;
  byte bVar9;
  ushort uVar10;
  undefined4 uVar6;
  uint uVar7;
  int iVar11;
  int iVar12;
  uint uVar13;
  int unaff_ESI;
  undefined4 *puVar14;
  byte *pbVar15;
  uint *puVar16;
  uint *unaff_EDI;
  undefined4 uVar4;
  
  if (*(char *)(unaff_ESI + 0xd) == '\x01') {
    if (*(char *)(unaff_ESI + 0xc) == ' ') {
      puVar16 = (uint *)(unaff_ESI + 0x16);
      while (uVar5 = *puVar16, uVar5 != 0xffffffff) {
        puVar16 = puVar16 + 1;
        if ((uVar5 & 0x80000000) == 0) {
          unaff_EDI = unaff_EDI + uVar5;
        }
        else {
          uVar5 = uVar5 & 0x7fffffff;
          do {
            uVar7 = *unaff_EDI;
            uVar13 = *puVar16;
            bVar8 = (byte)uVar13;
            if ((byte)uVar7 <= bVar8) {
              uVar13 = CONCAT31((int3)(uVar13 >> 8),(byte)uVar7);
              uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar8);
            }
            cVar2 = (char)uVar7 - (char)uVar13;
            uVar6 = CONCAT31((int3)(uVar7 >> 8),cVar2);
            bVar9 = (byte)(uVar13 >> 8);
            bVar8 = (byte)(uVar7 >> 8);
            if (bVar8 <= bVar9) {
              uVar13 = CONCAT22((short)(uVar13 >> 0x10),CONCAT11(bVar8,(char)uVar13));
              uVar6 = CONCAT22((short)(uVar7 >> 0x10),CONCAT11(bVar9,cVar2));
            }
            cVar2 = (char)((uint)uVar6 >> 8) - (char)(uVar13 >> 8);
            uVar7 = CONCAT22((short)((uint)uVar6 >> 0x10),CONCAT11(cVar2,(char)uVar6));
            uVar7 = uVar7 >> 8 | uVar7 << 0x18;
            bVar8 = (byte)(uVar13 >> 0x10);
            bVar9 = (byte)((uint)uVar6 >> 0x10);
            if (bVar9 <= bVar8) {
              uVar7 = CONCAT22((short)(uVar7 >> 0x10),CONCAT11(bVar8,cVar2));
              bVar8 = bVar9;
            }
            uVar10 = (ushort)(uVar7 >> 0x10);
            *unaff_EDI = CONCAT22(uVar10,CONCAT11((char)(uVar7 >> 8) - bVar8,(char)uVar7)) << 8 |
                         (uint)(uVar10 >> 8);
            puVar16 = puVar16 + 1;
            unaff_EDI = unaff_EDI + 1;
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
      }
    }
    else {
      puVar16 = (uint *)(unaff_ESI + 0x16);
      while (uVar5 = *puVar16, uVar5 != 0xffffffff) {
        puVar16 = puVar16 + 1;
        if ((uVar5 & 0x80000000) == 0) {
          unaff_EDI = unaff_EDI + uVar5;
        }
        else {
          uVar5 = uVar5 & 0x7fffffff;
          do {
            uVar7 = *unaff_EDI;
            bVar8 = (byte)*puVar16;
            bVar3 = (byte)uVar7;
            bVar9 = bVar8;
            if (bVar3 <= bVar8) {
              uVar7 = CONCAT31((int3)(uVar7 >> 8),bVar8);
              bVar9 = bVar3;
            }
            cVar2 = (char)uVar7 - bVar9;
            uVar6 = CONCAT31((int3)(uVar7 >> 8),cVar2);
            bVar3 = (byte)(uVar7 >> 8);
            bVar9 = bVar8;
            if (bVar3 <= bVar8) {
              uVar6 = CONCAT22((short)(uVar7 >> 0x10),CONCAT11(bVar8,cVar2));
              bVar9 = bVar3;
            }
            cVar2 = (char)((uint)uVar6 >> 8) - bVar9;
            uVar7 = CONCAT22((short)((uint)uVar6 >> 0x10),CONCAT11(cVar2,(char)uVar6));
            uVar7 = uVar7 >> 8 | uVar7 << 0x18;
            bVar9 = (byte)((uint)uVar6 >> 0x10);
            if (bVar9 <= bVar8) {
              uVar7 = CONCAT22((short)(uVar7 >> 0x10),CONCAT11(bVar8,cVar2));
              bVar8 = bVar9;
            }
            uVar10 = (ushort)(uVar7 >> 0x10);
            *unaff_EDI = CONCAT22(uVar10,CONCAT11((char)(uVar7 >> 8) - bVar8,(char)uVar7)) << 8 |
                         (uint)(uVar10 >> 8);
            puVar16 = (uint *)((int)puVar16 + 1);
            unaff_EDI = unaff_EDI + 1;
            uVar5 = uVar5 - 1;
          } while (uVar5 != 0);
        }
      }
    }
  }
  else if (*(char *)(unaff_ESI + 0xc) == ' ') {
    iVar1 = *(int *)(unaff_ESI + 4);
    iVar12 = *(int *)(unaff_ESI + 8);
    iRam0001c803 = (0x140 - iVar1) * 4;
    puVar14 = (undefined4 *)(unaff_ESI + 0x16);
    iVar11 = iVar1;
    do {
      do {
        puVar16 = unaff_EDI;
        uVar5 = *puVar16;
        uVar6 = *puVar14;
        bVar8 = (byte)uVar6;
        if ((byte)uVar5 <= bVar8) {
          uVar6 = CONCAT31((int3)((uint)uVar6 >> 8),(byte)uVar5);
          uVar5 = CONCAT31((int3)(uVar5 >> 8),bVar8);
        }
        cVar2 = (char)uVar5 - (char)uVar6;
        uVar4 = CONCAT31((int3)(uVar5 >> 8),cVar2);
        bVar9 = (byte)((uint)uVar6 >> 8);
        bVar8 = (byte)(uVar5 >> 8);
        if (bVar8 <= bVar9) {
          uVar6 = CONCAT22((short)((uint)uVar6 >> 0x10),CONCAT11(bVar8,(char)uVar6));
          uVar4 = CONCAT22((short)(uVar5 >> 0x10),CONCAT11(bVar9,cVar2));
        }
        cVar2 = (char)((uint)uVar4 >> 8) - (char)((uint)uVar6 >> 8);
        uVar5 = CONCAT22((short)((uint)uVar4 >> 0x10),CONCAT11(cVar2,(char)uVar4));
        uVar5 = uVar5 >> 8 | uVar5 << 0x18;
        bVar8 = (byte)((uint)uVar6 >> 0x10);
        bVar9 = (byte)((uint)uVar4 >> 0x10);
        if (bVar9 <= bVar8) {
          uVar5 = CONCAT22((short)(uVar5 >> 0x10),CONCAT11(bVar8,cVar2));
          bVar8 = bVar9;
        }
        uVar10 = (ushort)(uVar5 >> 0x10);
        *puVar16 = CONCAT22(uVar10,CONCAT11((char)(uVar5 >> 8) - bVar8,(char)uVar5)) << 8 |
                   (uint)(uVar10 >> 8);
        puVar14 = puVar14 + 1;
        iVar11 = iVar11 + -1;
        unaff_EDI = puVar16 + 1;
      } while (iVar11 != 0);
      iVar12 = iVar12 + -1;
      iVar11 = iVar1;
      unaff_EDI = (uint *)((int)puVar16 + 0x11111115);
    } while (iVar12 != 0);
  }
  else {
    iVar1 = *(int *)(unaff_ESI + 4);
    iVar12 = *(int *)(unaff_ESI + 8);
    iRam0001c85f = (0x140 - iVar1) * 4;
    pbVar15 = (byte *)(unaff_ESI + 0x16);
    iVar11 = iVar1;
    do {
      do {
        puVar16 = unaff_EDI;
        uVar5 = *puVar16;
        bVar8 = *pbVar15;
        bVar3 = (byte)uVar5;
        bVar9 = bVar8;
        if (bVar3 <= bVar8) {
          uVar5 = CONCAT31((int3)(uVar5 >> 8),bVar8);
          bVar9 = bVar3;
        }
        cVar2 = (char)uVar5 - bVar9;
        uVar6 = CONCAT31((int3)(uVar5 >> 8),cVar2);
        bVar3 = (byte)(uVar5 >> 8);
        bVar9 = bVar8;
        if (bVar3 <= bVar8) {
          uVar6 = CONCAT22((short)(uVar5 >> 0x10),CONCAT11(bVar8,cVar2));
          bVar9 = bVar3;
        }
        cVar2 = (char)((uint)uVar6 >> 8) - bVar9;
        uVar5 = CONCAT22((short)((uint)uVar6 >> 0x10),CONCAT11(cVar2,(char)uVar6));
        uVar5 = uVar5 >> 8 | uVar5 << 0x18;
        bVar9 = (byte)((uint)uVar6 >> 0x10);
        if (bVar9 <= bVar8) {
          uVar5 = CONCAT22((short)(uVar5 >> 0x10),CONCAT11(bVar8,cVar2));
          bVar8 = bVar9;
        }
        uVar10 = (ushort)(uVar5 >> 0x10);
        *puVar16 = CONCAT22(uVar10,CONCAT11((char)(uVar5 >> 8) - bVar8,(char)uVar5)) << 8 |
                   (uint)(uVar10 >> 8);
        pbVar15 = pbVar15 + 1;
        iVar11 = iVar11 + -1;
        unaff_EDI = puVar16 + 1;
      } while (iVar11 != 0);
      iVar12 = iVar12 + -1;
      iVar11 = iVar1;
      unaff_EDI = (uint *)((int)puVar16 + 0x11111115);
    } while (iVar12 != 0);
  }
  return CONCAT44(param_2,param_1);
}

