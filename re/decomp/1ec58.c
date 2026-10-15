
void FUN_0001ec58(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined3 uVar6;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = DAT_000402f8;
  iVar4 = -64000;
  do {
    uVar3 = *(uint *)(&/*c*/20.0 + iVar4 * 4 + unaff_EDI);
    iVar5 = (uint)*(byte *)(unaff_ESI + 64000 + iVar4) - param_2;
    if (0 < iVar5) {
      if (iVar5 < 0x20) {
        uVar3 = ~uVar3;
        uVar6 = (undefined3)((uint)(iVar5 * 0x800) >> 8);
        uVar1 = *(undefined1 *)(iVar2 + CONCAT31(uVar6,(char)(uVar3 >> 8)));
        uVar3 = CONCAT22((ushort)(uVar3 >> 0x18),
                         CONCAT11(*(undefined1 *)(iVar2 + CONCAT31(uVar6,(char)(uVar3 >> 0x10))),
                                  uVar1)) << 8 |
                CONCAT11(uVar1,*(undefined1 *)(iVar2 + CONCAT31(uVar6,(char)uVar3))) & 0xff;
      }
      else {
        uVar3 = 0;
      }
    }
    *(uint *)(&/*c*/20.0 + iVar4 * 4 + unaff_EDI) = uVar3;
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0);
  return;
}

