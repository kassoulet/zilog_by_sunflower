
void FUN_0001ecaa(undefined4 param_1,undefined2 param_2,int unaff_EBX)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined3 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  short sVar7;
  undefined2 uVar10;
  undefined3 uVar9;
  undefined1 *puVar8;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar6 = -64000;
  puVar8 = DAT_000402f8;
  uRam0001ecd8 = param_2;
  do {
    uVar4 = *(uint *)(&/*c*/20.0 + iVar6 * 4 + unaff_EDI);
    uVar10 = (undefined2)((uint)puVar8 >> 0x10);
    sVar7 = *(byte *)(unaff_ESI + 64000 + iVar6) + 0xeeef;
    puVar8 = (undefined1 *)CONCAT22(uVar10,sVar7);
    if (0 < sVar7) {
      if (sVar7 < 0x20) {
        uVar4 = ~uVar4;
        uVar9 = (undefined3)(CONCAT22(uVar10,sVar7 * 0x800) >> 8);
        uVar1 = *(undefined1 *)CONCAT31(uVar9,(char)(uVar4 >> 8));
        uVar5 = ~*(uint *)(&/*c*/20.0 + iVar6 * 4 + unaff_EBX);
        uVar3 = CONCAT21(uVar10,~(byte)((ushort)(sVar7 * 0x800) >> 8));
        uVar2 = *(undefined1 *)CONCAT31(uVar3,(char)(uVar5 >> 8));
        puVar8 = (undefined1 *)CONCAT31(uVar3,(char)(uVar5 >> 0x10));
        uVar4 = (CONCAT22((ushort)(uVar5 >> 0x18),CONCAT11(*puVar8,uVar2)) << 8 |
                CONCAT11(uVar2,*(undefined1 *)CONCAT31(uVar3,(char)uVar5)) & 0xff) +
                (CONCAT22((ushort)(uVar4 >> 0x18),
                          CONCAT11(*(undefined1 *)CONCAT31(uVar9,(char)(uVar4 >> 0x10)),uVar1)) << 8
                | CONCAT11(uVar1,*(undefined1 *)CONCAT31(uVar9,(char)uVar4)) & 0xff);
      }
      else {
        uVar4 = *(uint *)(&/*c*/20.0 + iVar6 * 4 + unaff_EBX);
      }
    }
    *(uint *)(&/*c*/20.0 + iVar6 * 4 + unaff_EDI) = uVar4;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0);
  return;
}

