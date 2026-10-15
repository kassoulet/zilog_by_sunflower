
undefined8 FUN_0001c91e(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  int unaff_ESI;
  uint *puVar9;
  byte *pbVar10;
  uint *unaff_EDI;
  uint *puVar11;
  
  if (*(char *)(unaff_ESI + 0xd) == '\x01') {
    if (*(char *)(unaff_ESI + 0xc) == ' ') {
      puVar9 = (uint *)(unaff_ESI + 0x16);
      while (uVar6 = *puVar9, uVar6 != 0xffffffff) {
        puVar9 = puVar9 + 1;
        if ((uVar6 & 0x80000000) == 0) {
          unaff_EDI = unaff_EDI + uVar6;
        }
        else {
          uVar6 = uVar6 & 0x7fffffff;
          do {
            uVar3 = *unaff_EDI;
            uVar2 = *puVar9;
            bVar8 = (byte)uVar2;
            if ((byte)uVar3 <= bVar8) {
              uVar2 = CONCAT31((int3)(uVar2 >> 8),(byte)uVar3);
              uVar3 = CONCAT31((int3)(uVar3 >> 8),bVar8);
            }
            bVar8 = (byte)(uVar2 >> 8);
            if ((byte)(uVar3 >> 8) <= bVar8) {
              uVar2 = uVar2 & 0xffff0000;
              uVar3 = CONCAT22((short)(uVar3 >> 0x10),CONCAT11(bVar8,(char)uVar3));
            }
            uVar4 = uVar3 >> 8 | uVar3 << 0x18;
            bVar8 = (byte)(uVar2 >> 0x10);
            if ((byte)(uVar3 >> 0x10) <= bVar8) {
              uVar4 = CONCAT22((short)(uVar4 >> 0x10),CONCAT11(bVar8,(char)(uVar3 >> 8)));
            }
            *unaff_EDI = uVar4 << 8 | uVar4 >> 0x18;
            puVar9 = puVar9 + 1;
            unaff_EDI = unaff_EDI + 1;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
      }
    }
    else {
      puVar9 = (uint *)(unaff_ESI + 0x16);
      while (uVar6 = *puVar9, uVar6 != 0xffffffff) {
        puVar9 = puVar9 + 1;
        if ((uVar6 & 0x80000000) == 0) {
          unaff_EDI = unaff_EDI + uVar6;
        }
        else {
          uVar6 = uVar6 & 0x7fffffff;
          do {
            uVar3 = *unaff_EDI;
            bVar8 = (byte)*puVar9;
            if ((byte)uVar3 <= bVar8) {
              uVar3 = CONCAT31((int3)(uVar3 >> 8),bVar8);
            }
            if ((byte)(uVar3 >> 8) <= bVar8) {
              uVar3 = CONCAT22((short)(uVar3 >> 0x10),CONCAT11(bVar8,(char)uVar3));
            }
            uVar2 = uVar3 >> 8 | uVar3 << 0x18;
            if ((byte)(uVar3 >> 0x10) <= bVar8) {
              uVar2 = CONCAT22((short)(uVar2 >> 0x10),CONCAT11(bVar8,(char)(uVar3 >> 8)));
            }
            *unaff_EDI = uVar2 << 8 | uVar2 >> 0x18;
            puVar9 = (uint *)((int)puVar9 + 1);
            unaff_EDI = unaff_EDI + 1;
            uVar6 = uVar6 - 1;
          } while (uVar6 != 0);
        }
      }
    }
  }
  else if (*(char *)(unaff_ESI + 0xc) == ' ') {
    iVar1 = *(int *)(unaff_ESI + 4);
    iVar7 = *(int *)(unaff_ESI + 8);
    iRam0001c975 = (0x140 - iVar1) * 4;
    puVar9 = (uint *)(unaff_ESI + 0x16);
    iVar5 = iVar1;
    do {
      do {
        puVar11 = unaff_EDI;
        uVar6 = *puVar11;
        uVar3 = *puVar9;
        bVar8 = (byte)uVar3;
        if ((byte)uVar6 <= bVar8) {
          uVar3 = CONCAT31((int3)(uVar3 >> 8),(byte)uVar6);
          uVar6 = CONCAT31((int3)(uVar6 >> 8),bVar8);
        }
        bVar8 = (byte)(uVar3 >> 8);
        if ((byte)(uVar6 >> 8) <= bVar8) {
          uVar3 = uVar3 & 0xffff0000;
          uVar6 = CONCAT22((short)(uVar6 >> 0x10),CONCAT11(bVar8,(char)uVar6));
        }
        uVar2 = uVar6 >> 8 | uVar6 << 0x18;
        bVar8 = (byte)(uVar3 >> 0x10);
        if ((byte)(uVar6 >> 0x10) <= bVar8) {
          uVar2 = CONCAT22((short)(uVar2 >> 0x10),CONCAT11(bVar8,(char)(uVar6 >> 8)));
        }
        *puVar11 = uVar2 << 8 | uVar2 >> 0x18;
        puVar9 = puVar9 + 1;
        iVar5 = iVar5 + -1;
        unaff_EDI = puVar11 + 1;
      } while (iVar5 != 0);
      iVar7 = iVar7 + -1;
      iVar5 = iVar1;
      unaff_EDI = (uint *)((int)puVar11 + 0x11111115);
    } while (iVar7 != 0);
  }
  else {
    iVar1 = *(int *)(unaff_ESI + 4);
    iVar7 = *(int *)(unaff_ESI + 8);
    iRam0001c9cb = (0x140 - iVar1) * 4;
    pbVar10 = (byte *)(unaff_ESI + 0x16);
    iVar5 = iVar1;
    do {
      do {
        puVar9 = unaff_EDI;
        uVar6 = *puVar9;
        bVar8 = *pbVar10;
        if ((byte)uVar6 <= bVar8) {
          uVar6 = CONCAT31((int3)(uVar6 >> 8),bVar8);
        }
        if ((byte)(uVar6 >> 8) <= bVar8) {
          uVar6 = CONCAT22((short)(uVar6 >> 0x10),CONCAT11(bVar8,(char)uVar6));
        }
        uVar3 = uVar6 >> 8 | uVar6 << 0x18;
        if ((byte)(uVar6 >> 0x10) <= bVar8) {
          uVar3 = CONCAT22((short)(uVar3 >> 0x10),CONCAT11(bVar8,(char)(uVar6 >> 8)));
        }
        *puVar9 = uVar3 << 8 | uVar3 >> 0x18;
        pbVar10 = pbVar10 + 1;
        iVar5 = iVar5 + -1;
        unaff_EDI = puVar9 + 1;
      } while (iVar5 != 0);
      iVar7 = iVar7 + -1;
      iVar5 = iVar1;
      unaff_EDI = (uint *)((int)puVar9 + 0x11111115);
    } while (iVar7 != 0);
  }
  return CONCAT44(param_2,param_1);
}

