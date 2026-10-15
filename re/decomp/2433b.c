
undefined8 FUN_0002433b(int param_1,undefined4 param_2)

{
  int iVar1;
  int extraout_EDX;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  
  if (((*(byte *)(param_1 + 0xc) & 0x80) != 0) && ((*(byte *)(param_1 + 0xd) & 0x10) != 0)) {
    FUN_00028eab(param_1);
    param_1 = extraout_EDX;
  }
  uVar4 = FUN_00028c69(*(undefined4 *)(param_1 + 0x10));
  iVar2 = (int)((ulonglong)uVar4 >> 0x20);
  iVar3 = (int)uVar4;
  if ((iVar3 != -1) && (iVar1 = *(int *)(iVar2 + 4), iVar1 != 0)) {
    if ((*(byte *)(iVar2 + 0xd) & 0x10) == 0) {
      iVar3 = iVar3 - iVar1;
    }
    else {
      iVar3 = iVar1 + iVar3;
    }
  }
  return CONCAT44(param_2,iVar3);
}

