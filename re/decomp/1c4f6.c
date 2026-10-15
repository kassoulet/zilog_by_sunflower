
undefined8 FUN_0001c4f6(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  undefined1 uVar6;
  ushort uVar7;
  byte bVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int unaff_ESI;
  undefined4 *puVar14;
  byte *pbVar15;
  uint *puVar16;
  uint *unaff_EDI;
  undefined2 uVar8;
  byte bVar9;
  
  if (*(char *)(unaff_ESI + 0xd) == '\x01') {
    if (*(char *)(unaff_ESI + 0xc) == ' ') {
      puVar16 = (uint *)(unaff_ESI + 0x16);
      while (uVar12 = *puVar16, uVar12 != 0xffffffff) {
        puVar16 = puVar16 + 1;
        if ((uVar12 & 0x80000000) == 0) {
          unaff_EDI = unaff_EDI + uVar12;
        }
        else {
          uVar12 = uVar12 & 0x7fffffff;
          do {
            uVar3 = *puVar16;
            uVar4 = *unaff_EDI;
            cVar5 = (byte)uVar3 + (byte)uVar4;
            if (CARRY1((byte)uVar3,(byte)uVar4)) {
              cVar5 = -1;
            }
            bVar9 = (byte)(uVar3 >> 8);
            bVar10 = (byte)(uVar4 >> 8);
            uVar7 = CONCAT11(bVar9 + bVar10,cVar5);
            if (CARRY1(bVar9,bVar10)) {
              uVar7 = CONCAT11(0xff,cVar5);
            }
            bVar9 = (byte)(uVar4 >> 0x10);
            bVar10 = (byte)(uVar3 >> 0x10);
            uVar6 = (undefined1)(uVar7 >> 8);
            uVar8 = CONCAT11(bVar10 + bVar9,uVar6);
            if (CARRY1(bVar10,bVar9)) {
              uVar8 = CONCAT11(0xff,uVar6);
            }
            *unaff_EDI = CONCAT22((ushort)(uVar3 >> 0x18),uVar8) << 8 | uVar7 & 0xff;
            puVar16 = puVar16 + 1;
            unaff_EDI = unaff_EDI + 1;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
      }
    }
    else {
      puVar16 = (uint *)(unaff_ESI + 0x16);
      while (uVar12 = *puVar16, uVar12 != 0xffffffff) {
        puVar16 = puVar16 + 1;
        if ((uVar12 & 0x80000000) == 0) {
          unaff_EDI = unaff_EDI + uVar12;
        }
        else {
          uVar12 = uVar12 & 0x7fffffff;
          do {
            uVar3 = *unaff_EDI;
            bVar9 = (byte)*puVar16;
            cVar5 = (byte)uVar3 + bVar9;
            if (CARRY1((byte)uVar3,bVar9)) {
              cVar5 = -1;
            }
            bVar10 = (byte)(uVar3 >> 8);
            uVar7 = CONCAT11(bVar10 + bVar9,cVar5);
            if (CARRY1(bVar10,bVar9)) {
              uVar7 = CONCAT11(0xff,cVar5);
            }
            bVar10 = (byte)(uVar3 >> 0x10);
            uVar6 = (undefined1)(uVar7 >> 8);
            uVar8 = CONCAT11(bVar10 + bVar9,uVar6);
            if (CARRY1(bVar10,bVar9)) {
              uVar8 = CONCAT11(0xff,uVar6);
            }
            *unaff_EDI = CONCAT22((ushort)(uVar3 >> 0x18),uVar8) << 8 | uVar7 & 0xff;
            puVar16 = (uint *)((int)puVar16 + 1);
            unaff_EDI = unaff_EDI + 1;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
      }
    }
  }
  else if (*(char *)(unaff_ESI + 0xc) == ' ') {
    iVar1 = *(int *)(unaff_ESI + 4);
    iVar13 = *(int *)(unaff_ESI + 8);
    iRam0001c54d = (0x140 - iVar1) * 4;
    puVar14 = (undefined4 *)(unaff_ESI + 0x16);
    iVar11 = iVar1;
    do {
      do {
        puVar16 = unaff_EDI;
        uVar2 = *puVar14;
        uVar12 = *puVar16;
        cVar5 = (byte)uVar2 + (byte)uVar12;
        if (CARRY1((byte)uVar2,(byte)uVar12)) {
          cVar5 = -1;
        }
        bVar9 = (byte)((uint)uVar2 >> 8);
        bVar10 = (byte)(uVar12 >> 8);
        uVar7 = CONCAT11(bVar9 + bVar10,cVar5);
        if (CARRY1(bVar9,bVar10)) {
          uVar7 = CONCAT11(0xff,cVar5);
        }
        bVar9 = (byte)(uVar12 >> 0x10);
        bVar10 = (byte)((uint)uVar2 >> 0x10);
        uVar6 = (undefined1)(uVar7 >> 8);
        uVar8 = CONCAT11(bVar10 + bVar9,uVar6);
        if (CARRY1(bVar10,bVar9)) {
          uVar8 = CONCAT11(0xff,uVar6);
        }
        *puVar16 = CONCAT22((ushort)((uint)uVar2 >> 0x18),uVar8) << 8 | uVar7 & 0xff;
        puVar14 = puVar14 + 1;
        iVar11 = iVar11 + -1;
        unaff_EDI = puVar16 + 1;
      } while (iVar11 != 0);
      iVar13 = iVar13 + -1;
      iVar11 = iVar1;
      unaff_EDI = (uint *)((int)puVar16 + 0x11111115);
    } while (iVar13 != 0);
  }
  else {
    iVar1 = *(int *)(unaff_ESI + 4);
    iVar13 = *(int *)(unaff_ESI + 8);
    iRam0001c59f = (0x140 - iVar1) * 4;
    pbVar15 = (byte *)(unaff_ESI + 0x16);
    iVar11 = iVar1;
    do {
      do {
        puVar16 = unaff_EDI;
        uVar12 = *puVar16;
        bVar9 = *pbVar15;
        cVar5 = (byte)uVar12 + bVar9;
        if (CARRY1((byte)uVar12,bVar9)) {
          cVar5 = -1;
        }
        bVar10 = (byte)(uVar12 >> 8);
        uVar7 = CONCAT11(bVar10 + bVar9,cVar5);
        if (CARRY1(bVar10,bVar9)) {
          uVar7 = CONCAT11(0xff,cVar5);
        }
        bVar10 = (byte)(uVar12 >> 0x10);
        uVar6 = (undefined1)(uVar7 >> 8);
        uVar8 = CONCAT11(bVar10 + bVar9,uVar6);
        if (CARRY1(bVar10,bVar9)) {
          uVar8 = CONCAT11(0xff,uVar6);
        }
        *puVar16 = CONCAT22((ushort)(uVar12 >> 0x18),uVar8) << 8 | uVar7 & 0xff;
        pbVar15 = pbVar15 + 1;
        iVar11 = iVar11 + -1;
        unaff_EDI = puVar16 + 1;
      } while (iVar11 != 0);
      iVar13 = iVar13 + -1;
      iVar11 = iVar1;
      unaff_EDI = (uint *)((int)puVar16 + 0x11111115);
    } while (iVar13 != 0);
  }
  return CONCAT44(param_2,param_1);
}

