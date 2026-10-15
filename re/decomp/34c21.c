
void FUN_00034c21(undefined4 param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  undefined2 uVar4;
  uint uVar3;
  byte bVar5;
  byte bVar6;
  int iVar7;
  int unaff_EDI;
  byte *pbVar8;
  
  iVar7 = 0;
  uVar1 = (undefined2)param_1;
  do {
    iVar7 = iVar7 + 1;
    uVar4 = (undefined2)((uint)param_1 >> 0x10);
    uVar2 = (ushort)param_1 >> 4;
    param_1 = CONCAT22(uVar4,uVar2);
  } while (uVar2 != 0);
  uVar3 = CONCAT22(uVar4,uVar1);
  pbVar8 = (byte *)(unaff_EDI + iVar7);
  *pbVar8 = 0;
  do {
    pbVar8 = pbVar8 + -1;
    bVar5 = (byte)uVar3 & 0xf;
    bVar6 = bVar5 + 0x30;
    if (0x39 < bVar6) {
      bVar6 = bVar5 + 0x41;
    }
    *pbVar8 = bVar6;
    uVar3 = uVar3 >> 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  return;
}

