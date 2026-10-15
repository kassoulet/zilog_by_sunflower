
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __regparm3 FUN_00024568(void)

{
  undefined1 uVar1;
  ushort uVar2;
  int unaff_EBX;
  undefined4 unaff_ESI;
  undefined1 *unaff_EDI;
  byte bVar3;
  
  bVar3 = 0;
  DAT_0003eece = 0;
  DAT_0003eed0 = 9;
  DAT_0003eed2 = 0x200;
  DAT_0003eede = 0;
  _DAT_0003eec0 = unaff_ESI;
  while (uVar2 = FUN_000246a1(), uVar2 != 0x101) {
    if (uVar2 == 0x100) {
      FUN_000246fb();
      DAT_0003eec6 = FUN_000246a1();
      DAT_0003eed4 = (undefined1)DAT_0003eec6;
      DAT_0003eec8 = DAT_0003eec6;
      DAT_0003eed5 = DAT_0003eed4;
      *unaff_EDI = DAT_0003eed4;
      unaff_EDI = unaff_EDI + (uint)bVar3 * -2 + 1;
    }
    else {
      DAT_0003eec6 = uVar2;
      if (DAT_0003eecc <= (short)uVar2) {
        DAT_0003eec6 = DAT_0003eec8;
        DAT_0003eece = DAT_0003eece + 1;
      }
      for (; 0xff < (short)DAT_0003eec6;
          DAT_0003eec6 = *(ushort *)(unaff_EBX + (uint)DAT_0003eec6 * 3)) {
        DAT_0003eece = DAT_0003eece + 1;
      }
      uVar1 = (undefined1)DAT_0003eec6;
      DAT_0003eed4 = uVar1;
      DAT_0003eed5 = uVar1;
      DAT_0003eeca = uVar2;
      for (DAT_0003eece = DAT_0003eece + 1; DAT_0003eece != 0; DAT_0003eece = DAT_0003eece + -1) {
        *unaff_EDI = uVar1;
        unaff_EDI = unaff_EDI + (uint)bVar3 * -2 + 1;
      }
      FUN_00024717();
      DAT_0003eec8 = DAT_0003eeca;
      if ((DAT_0003eed2 <= DAT_0003eecc) && (DAT_0003eed0 != 0xc)) {
        DAT_0003eed0 = DAT_0003eed0 + 1;
        DAT_0003eed2 = DAT_0003eed2 << 1;
      }
    }
  }
  return;
}

