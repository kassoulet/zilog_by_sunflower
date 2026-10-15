
void FUN_00025b60(void)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  ushort *unaff_ESI;
  byte *unaff_EDI;
  byte *pbVar5;
  
  iVar4 = 200;
  do {
    iVar3 = 0x50;
    do {
      pbVar5 = unaff_EDI;
      uVar1 = unaff_ESI[1];
      uVar2 = *unaff_ESI & 0xf0ff;
      if ((char)(uVar2 >> 8) == -0x10) {
        uVar2 = CONCAT11(0xe0,(char)uVar2);
      }
      *pbVar5 = (byte)uVar2 >> 4 | (byte)(uVar2 >> 8);
      pbVar5[0x50] = ((byte)uVar1 >> 4) - 0x10;
      unaff_ESI = unaff_ESI + 8;
      iVar3 = iVar3 + -1;
      unaff_EDI = pbVar5 + 1;
    } while (iVar3 != 0);
    unaff_EDI = pbVar5 + 0x51;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}

