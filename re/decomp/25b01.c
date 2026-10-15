
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_00025b01(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  DAT_0003f5e2 = param_1;
  do {
    out(0x3c4,CONCAT11('\x01' << ((byte)uVar1 & 0x1f),2));
    FUN_00025b60(_DAT_0003f8e6 & 0xffff,0x3c4,uVar1 << 2);
    uVar1 = uVar1 + 1;
  } while (uVar1 < 4);
  out(0x3d4,CONCAT11((char)(_DAT_0003f8e6 >> 8),0xc));
  out(0x3d4,CONCAT11((char)_DAT_0003f8e6,0xd));
  _DAT_0003f8e6 = _DAT_0003f8e6 >> 0x10 | _DAT_0003f8e6 << 0x10;
  return CONCAT44(param_2,param_1);
}

