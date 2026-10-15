
void __regparm3 FUN_0001ee44(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined3 uVar4;
  ushort uVar5;
  undefined3 uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int unaff_EBX;
  undefined2 uVar11;
  undefined1 *puVar10;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar9 = -64000;
  puVar10 = DAT_000402f8;
  do {
    bVar1 = *(byte *)(unaff_ESI + 64000 + iVar9);
    uVar5 = (ushort)bVar1;
    uVar7 = *(uint *)(&/*c*/20.0 + iVar9 * 4 + unaff_EDI);
    uVar11 = (undefined2)((uint)puVar10 >> 0x10);
    puVar10 = (undefined1 *)CONCAT22(uVar11,uVar5);
    if (uVar5 != 0) {
      if (uVar5 < 0xff) {
        uVar7 = ~uVar7;
        uVar6 = CONCAT21(uVar11,bVar1);
        uVar2 = *(undefined1 *)CONCAT31(uVar6,(char)(uVar7 >> 8));
        uVar8 = ~*(uint *)(&/*c*/20.0 + iVar9 * 4 + unaff_EBX);
        uVar4 = CONCAT21(uVar11,~bVar1);
        uVar3 = *(undefined1 *)CONCAT31(uVar4,(char)(uVar8 >> 8));
        puVar10 = (undefined1 *)CONCAT31(uVar4,(char)(uVar8 >> 0x10));
        uVar7 = (CONCAT22((ushort)(uVar8 >> 0x18),CONCAT11(*puVar10,uVar3)) << 8 |
                CONCAT11(uVar3,*(undefined1 *)CONCAT31(uVar4,(char)uVar8)) & 0xff) +
                (CONCAT22((ushort)(uVar7 >> 0x18),
                          CONCAT11(*(undefined1 *)CONCAT31(uVar6,(char)(uVar7 >> 0x10)),uVar2)) << 8
                | CONCAT11(uVar2,*(undefined1 *)CONCAT31(uVar6,(char)uVar7)) & 0xff);
      }
      else {
        uVar7 = *(uint *)(&/*c*/20.0 + iVar9 * 4 + unaff_EBX);
      }
    }
    *(uint *)(&/*c*/20.0 + iVar9 * 4 + unaff_EDI) = uVar7;
    iVar9 = iVar9 + 1;
  } while (iVar9 != 0);
  return;
}

