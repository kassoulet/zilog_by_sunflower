
byte FUN_000337d8(undefined4 param_1,byte param_2)

{
  byte bVar1;
  ushort uVar2;
  
  uVar2 = -2 << (param_2 & 0xf) | 0xfffeU >> 0x10 - (param_2 & 0xf);
  if (param_2 < 8) {
    bVar1 = in(0x21);
    bVar1 = bVar1 & (byte)uVar2;
    out(0x21,bVar1);
  }
  else {
    bVar1 = in(0xa1);
    out(0xa1,bVar1 & (byte)(uVar2 >> 8));
    bVar1 = in(0x21);
    bVar1 = bVar1 & 0xfb;
    out(0x21,bVar1);
  }
  return bVar1;
}

