
undefined8 FUN_0002a1f6(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    uVar1 = FUN_00029e7c(param_1);
    if (((&DAT_0003fda0)[(byte)((char)uVar1 + 1)] & 2) == 0) break;
    iVar2 = iVar2 + 1;
  }
  if ((*(byte *)(param_1 + 0x10) & 2) == 0) {
    FUN_00029e83(uVar1,param_1);
  }
  return CONCAT44(param_2,iVar2);
}

