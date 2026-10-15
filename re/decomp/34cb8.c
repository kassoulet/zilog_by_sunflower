
void FUN_00034cb8(int param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  undefined4 uVar1;
  uint uVar2;
  int extraout_ECX;
  int iVar3;
  undefined8 uVar4;
  
  DAT_00033a22 = DAT_00033768 + 0xb81e2 + DAT_00033a22;
  param_1 = DAT_00033a22 + param_1;
  uVar1 = 0x7100;
  uVar2 = (uint)DAT_00033a20;
  iVar3 = DAT_00033a1c;
  DAT_00033a26 = param_1;
  do {
    uVar4 = FUN_00034cae(uVar1,param_2,unaff_EBX,uVar2,param_1,iVar3);
    param_2 = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar1 = (undefined4)uVar4;
    param_1 = param_1 + 0xa0;
    iVar3 = iVar3 + 0x20;
    uVar2 = extraout_ECX - 1;
  } while (uVar2 != 0);
  return;
}

