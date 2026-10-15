
undefined2 FUN_00036422(undefined2 param_1,undefined4 param_2,int unaff_EBX)

{
  if (DAT_0003626e != unaff_EBX) {
    out(0x43,0x36);
    out(0x40,(char)unaff_EBX);
    out(0x40,(char)((uint)unaff_EBX >> 8));
    DAT_0003626e = unaff_EBX;
  }
  return param_1;
}

