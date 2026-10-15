
undefined8 __regparm3 FUN_00037e9f(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  out(DAT_00036456 + 0x103,0x43);
  out(DAT_00036456 + 0x104,(short)param_3);
  out(DAT_00036456 + 0x103,0x44);
  out(DAT_00036456 + 0x105,(char)((uint)param_3 >> 0x10));
  out(DAT_00036456 + 0x107,(char)param_1);
  return CONCAT44(param_2,param_1);
}

