
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_2765c(undefined4 param_1)

{
  undefined8 uVar1;
  
  uVar1 = func_2dff8(param_1,_DAT_0003ed2c + 3U & 0xfffffffc);
  if ((uint)((ulonglong)uVar1 >> 0x20) < (uint)uVar1) {
    func_2e01a();
    _DAT_0003ed30 = &stack0xfffffff8;
  }
  else {
    _DAT_0003ed30 = (undefined1 *)0x0;
  }
  _DAT_0003ed30 = _DAT_0003ed30 + _DAT_0003ed2c;
  func_2e04a();
  func_100d3(_DAT_00041478,_DAT_0004147c);
  FUN_0001780d();
  return;
}

