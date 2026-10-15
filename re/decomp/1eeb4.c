
void FUN_0001eeb4(void)

{
  byte bVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined3 uVar5;
  ushort uVar6;
  undefined3 uVar7;
  uint uVar8;
  int iVar9;
  undefined2 uVar11;
  undefined1 *puVar10;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar9 = -64000;
  puVar10 = DAT_000402f8;
  do {
    bVar1 = *(byte *)(unaff_ESI + 64000 + iVar9);
    uVar6 = (ushort)bVar1;
    uVar8 = *(uint *)(&/*c*/20.0 + iVar9 * 4 + unaff_EDI);
    uVar11 = (undefined2)((uint)puVar10 >> 0x10);
    puVar10 = (undefined1 *)CONCAT22(uVar11,uVar6);
    if (uVar6 != 0) {
      if (uVar6 < 0xff) {
        uVar8 = ~uVar8;
        uVar7 = CONCAT21(uVar11,bVar1);
        uVar2 = *(undefined1 *)CONCAT31(uVar7,(char)(uVar8 >> 8));
        uVar4 = *(undefined4 *)(&/*c*/20.0 + iVar9 * 4 + unaff_EDI);
        uVar5 = CONCAT21(uVar11,~bVar1);
        uVar3 = *(undefined1 *)CONCAT31(uVar5,(char)((uint)uVar4 >> 8));
        puVar10 = (undefined1 *)CONCAT31(uVar5,(char)((uint)uVar4 >> 0x10));
        uVar8 = (CONCAT22((ushort)((uint)uVar4 >> 0x18),CONCAT11(*puVar10,uVar3)) << 8 |
                CONCAT11(uVar3,*(undefined1 *)CONCAT31(uVar5,(char)uVar4)) & 0xff) +
                (CONCAT22((ushort)(uVar8 >> 0x18),
                          CONCAT11(*(undefined1 *)CONCAT31(uVar7,(char)(uVar8 >> 0x10)),uVar2)) << 8
                | CONCAT11(uVar2,*(undefined1 *)CONCAT31(uVar7,(char)uVar8)) & 0xff);
      }
      else {
        uVar8 = ~*(uint *)(&/*c*/20.0 + iVar9 * 4 + unaff_EDI) & 0xffffff;
      }
    }
    *(uint *)(&/*c*/20.0 + iVar9 * 4 + unaff_EDI) = uVar8;
    iVar9 = iVar9 + 1;
  } while (iVar9 != 0);
  return;
}

