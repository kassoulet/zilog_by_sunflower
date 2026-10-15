
void FUN_000322f0(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int unaff_ESI;
  char *pcVar7;
  
  uVar5 = 0;
  do {
    if (*(int *)(unaff_ESI + 0x1be + uVar5 * 4) != 0) {
      piVar1 = (int *)(unaff_ESI + 0x1be + uVar5 * 4);
      *piVar1 = *piVar1 + unaff_ESI;
    }
    uVar5 = (uint)(ushort)((short)uVar5 + 1);
  } while (uVar5 != 0x200);
  uVar5 = 0;
  do {
    iVar2 = *(int *)(unaff_ESI + 0x5be + uVar5 * 4);
    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0x39) & 1) != 0)) {
      *(byte *)(iVar2 + 0x39) = *(byte *)(iVar2 + 0x39) & 0xfe;
      pcVar7 = (char *)(*(int *)(iVar2 + 0x42) + unaff_ESI);
      iVar6 = *(int *)(iVar2 + 0x24);
      cVar3 = '\0';
      do {
        cVar3 = cVar3 + *pcVar7;
        *pcVar7 = cVar3;
        pcVar7 = pcVar7 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      *(byte *)(iVar2 + 0x39) = *(byte *)(iVar2 + 0x39) & 0xdf;
      FUN_00034076();
    }
    uVar4 = (short)uVar5 + 1;
    uVar5 = (uint)uVar4;
  } while (uVar4 != *(ushort *)(unaff_ESI + 0x32));
  return;
}

