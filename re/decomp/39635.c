
void FUN_00039635(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_00039715(param_1,param_2,0x41);
  uVar2 = FUN_00039715((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_0003645a._1_1_);
  uVar2 = FUN_00039715((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(undefined1)DAT_0003645a);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  if ((DAT_0003645c & 1) == 0) {
    uVar2 = FUN_00039715((int)uVar2,uVar1,0xb4);
    uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
    if ((DAT_0003645c & 4) == 0) {
      uVar2 = FUN_00039715((int)uVar2,uVar1,0x30);
    }
    else {
      uVar2 = FUN_00039715((int)uVar2,uVar1,0x10);
    }
  }
  else {
    uVar2 = FUN_00039715((int)uVar2,uVar1,0xc6);
    uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
    if ((DAT_0003645c & 4) == 0) {
      uVar2 = FUN_00039715((int)uVar2,uVar1,0x30);
    }
    else {
      uVar2 = FUN_00039715((int)uVar2,uVar1,0x10);
    }
  }
  uVar2 = FUN_00039715((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_00039162);
  FUN_00039715((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),DAT_00039163);
  return;
}

