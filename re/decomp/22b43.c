
void FUN_00022b43(undefined4 param_1,short param_2,undefined4 unaff_EBX)

{
  byte bVar1;
  undefined4 uVar2;
  char cVar3;
  undefined1 uVar4;
  ushort uVar5;
  uint uVar8;
  undefined4 unaff_ESI;
  int unaff_EDI;
  undefined2 uVar6;
  byte bVar7;
  
  uVar8 = 0;
  uRam00022b62 = unaff_ESI;
  uRam00022b6b = unaff_EBX;
  uRam00022b72 = param_1;
  do {
    bVar1 = (&DAT_11111111)[(ushort)(*(short *)(&DAT_11111111 + uVar8 * 2) + param_2)];
    uVar2 = *(undefined4 *)(&DAT_11111111 + uVar8 * 4);
    cVar3 = (byte)uVar2 + bVar1;
    if (CARRY1((byte)uVar2,bVar1)) {
      cVar3 = -1;
    }
    bVar7 = (byte)((uint)uVar2 >> 8);
    uVar5 = CONCAT11(bVar7 + bVar1,cVar3);
    if (CARRY1(bVar7,bVar1)) {
      uVar5 = CONCAT11(0xff,cVar3);
    }
    bVar7 = (byte)((uint)uVar2 >> 0x10);
    uVar4 = (undefined1)(uVar5 >> 8);
    uVar6 = CONCAT11(bVar7 + bVar1,uVar4);
    if (CARRY1(bVar7,bVar1)) {
      uVar6 = CONCAT11(0xff,uVar4);
    }
    *(uint *)(unaff_EDI + uVar8 * 4) =
         CONCAT22((ushort)((uint)uVar2 >> 0x18),uVar6) << 8 | uVar5 & 0xff;
    uVar8 = uVar8 + 1;
  } while (uVar8 < 0x10000);
  return;
}

