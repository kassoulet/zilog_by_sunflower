
undefined8 FUN_0002acfb(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  iVar1 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc) = iVar1 + -1;
  if (iVar1 != 0) {
    uVar3 = FUN_00029e7c(param_1);
    uVar2 = (undefined4)uVar3;
    if ((*(byte *)((int)((ulonglong)uVar3 >> 0x20) + 0x10) & 2) == 0) goto LAB_0002ad1e;
  }
  uVar2 = 0xffffffff;
LAB_0002ad1e:
  return CONCAT44(param_2,uVar2);
}

