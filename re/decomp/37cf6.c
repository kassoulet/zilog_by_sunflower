
undefined8 __regparm3 FUN_00037cf6(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  uint uVar3;
  undefined1 *unaff_ESI;
  short sVar4;
  uint unaff_EDI;
  
  uVar3 = unaff_EDI >> 0x10;
  out(DAT_00036456 + 0x103,0x44);
  out(DAT_00036456 + 0x105,(char)(unaff_EDI >> 0x10));
  out(DAT_00036456 + 0x103,0x43);
  do {
    sVar4 = (short)unaff_EDI;
    out(DAT_00036456 + 0x104,sVar4);
    uVar1 = *unaff_ESI;
    unaff_ESI = unaff_ESI + 1;
    out(DAT_00036456 + 0x107,uVar1);
    unaff_EDI = (uint)(ushort)(sVar4 + 1);
    if (sVar4 == -1) {
      uVar2 = (short)uVar3 + 1;
      uVar3 = (uint)uVar2;
      out(DAT_00036456 + 0x103,0x44);
      out(DAT_00036456 + 0x105,(char)uVar2);
      out(DAT_00036456 + 0x103,0x43);
    }
    param_3 = param_3 + -1;
  } while (param_3 != 0);
  return CONCAT44(param_2,param_1);
}

