
int FUN_00023d3b(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX)

{
  int iVar1;
  int iVar2;
  undefined1 *extraout_ECX;
  undefined8 uVar3;
  undefined4 local_10;
  
  uVar3 = FUN_00023b44(param_2,&local_10);
  iVar1 = (int)uVar3;
  iVar2 = iVar1;
  if ((iVar1 != 0) && (iVar2 = FUN_000287da(0,(int)((ulonglong)uVar3 >> 0x20),iVar1), iVar2 != 0)) {
    iVar2 = FUN_00023c5f(param_1,*extraout_ECX,iVar1,local_10,unaff_EBX,iVar2);
  }
  return iVar2;
}

