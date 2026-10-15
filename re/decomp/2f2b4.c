
void FUN_0002f2b4(int param_1,int param_2,uint unaff_EBX,undefined4 param_4)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar5;
  int iVar4;
  uint uVar6;
  undefined4 unaff_ESI;
  undefined1 *puVar7;
  int *unaff_EDI;
  bool bVar8;
  
  uVar6 = CONCAT22((short)param_4,(short)unaff_ESI);
  uVar5 = (ushort)(unaff_EBX >> 0x10);
  iVar4 = CONCAT31(CONCAT21(uVar5,(char)((uint)param_4 >> 0x10)),(char)((uint)param_1 >> 0x10));
  uVar2 = unaff_EBX & 0xffff | param_1 << 0x10;
  puVar7 = (undefined1 *)(param_2 << 0x10);
  uVar3 = (uint)CONCAT11((char)((uint)unaff_ESI >> 0x10),(char)((uint)param_2 >> 0x10)) |
          (uint)uVar5 * 0x10000 + 0x10000;
  iRam0002f356 = DAT_0004139c << 0x10;
  uRam0002f35c = (undefined1)((uint)DAT_0004139c >> 0x10);
  iRam0002f35f = DAT_000413a0 << 0x10;
  uRam0002f365 = (undefined1)((uint)DAT_000413a0 >> 0x10);
  iRam0002f368 = DAT_000413a4 << 0x10;
  uRam0002f36e = (undefined1)((uint)DAT_000413a4 >> 0x10);
  uRam0002f372 = (undefined2)DAT_000413a8;
  uRam0002f376 = (undefined1)((uint)DAT_000413a8 >> 0x10);
  do {
    *unaff_EDI = *(int *)(iVar4 * 4) + *(int *)(uVar3 * 4);
    unaff_EDI = unaff_EDI + 1;
    iVar4 = CONCAT22((short)((uint)iVar4 >> 0x10),
                     CONCAT11((char)((uint)iVar4 >> 8) + '\x11' + (0xeeeeeeee < uVar6),
                              (char)iVar4 + '\x11' + (0xeeeeeeee < uVar2)));
    bVar8 = (undefined1 *)0xeeeeeeee < puVar7;
    puVar7 = &DAT_11111111 + (int)puVar7;
    uVar5 = (ushort)(&DAT_11111111 + uVar6);
    uVar6 = CONCAT22((short)((uint)(&DAT_11111111 + uVar6) >> 0x10),uVar5 + 0x1111);
    uVar3 = CONCAT22((short)(uVar3 >> 0x10),
                     CONCAT11((char)(uVar3 >> 8) + '\x11' + (0xeeee < uVar5),
                              (char)uVar3 + '\x11' + bVar8));
    sVar1 = (short)(&DAT_11111111 + uVar2) + -1;
    uVar2 = CONCAT22((short)((uint)(&DAT_11111111 + uVar2) >> 0x10),sVar1);
  } while (sVar1 != 0);
  return;
}

