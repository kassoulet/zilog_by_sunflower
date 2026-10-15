
undefined6 FUN_000347c4(undefined4 param_1,short param_2,ushort unaff_BX,char param_4)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = (byte)unaff_BX;
  if (param_4 == '\0') {
    uVar2 = (uint)(byte)(&DAT_0003399c)[bVar3 & 0x7f];
  }
  else if (param_4 == '\x01') {
    if (bVar3 < 0x80) {
      uVar2 = (uint)(ushort)(unaff_BX << 1);
    }
    else {
      uVar2 = -(uint)(ushort)((unaff_BX - 0x100) * 2);
    }
  }
  else if (param_4 == '\x04') {
    if (bVar3 < 0x80) {
      uVar2 = (uint)(ushort)((unaff_BX & 0xff) * -2);
    }
    else {
      uVar2 = (uint)(ushort)(((unaff_BX & 0xff) - 0x100) * 2);
    }
  }
  else {
    uVar2 = 0xff;
  }
  if (0x7f < bVar3) {
    uVar2 = CONCAT22((short)(uVar2 >> 0x10),-(short)uVar2);
  }
  iVar1 = (int)(short)uVar2 * (int)param_2;
  return CONCAT24((short)((uint)iVar1 >> 0x10),CONCAT22((short)(uVar2 >> 0x10),(short)iVar1));
}

