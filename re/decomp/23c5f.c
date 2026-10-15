
undefined4
FUN_00023c5f(undefined4 param_1,undefined1 param_2,uint unaff_EBX,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  undefined4 uVar1;
  int extraout_ECX;
  int extraout_ECX_00;
  int iVar2;
  undefined4 extraout_ECX_01;
  undefined8 uVar3;
  
  *(byte *)(param_6 + 0xc) = *(byte *)(param_6 + 0xc) & 0xfc;
  *(uint *)(param_6 + 0xc) = *(uint *)(param_6 + 0xc) | unaff_EBX;
  FUN_00028505(param_2,param_4);
  uVar3 = FUN_00028537();
  *(int *)(extraout_ECX + 0x10) = (int)uVar3;
  if (*(int *)(extraout_ECX + 0x10) == -1) {
    FUN_00028883(extraout_ECX);
    uVar1 = 0;
  }
  else {
    *(undefined4 *)(extraout_ECX + 4) = 0;
    *(undefined4 *)(extraout_ECX + 0x14) = 0;
    *(undefined4 *)(*(int *)(extraout_ECX + 8) + 0xc) = 0;
    *(int *)(*(int *)(extraout_ECX + 8) + 0x10) = (int)((ulonglong)uVar3 >> 0x20);
    *(undefined4 *)(*(int *)(extraout_ECX + 8) + 8) = 0;
    iVar2 = extraout_ECX;
    if ((unaff_EBX & 0x80) != 0) {
      FUN_0002402d(extraout_ECX,0,2);
      iVar2 = extraout_ECX_00;
    }
    FUN_000288da(iVar2);
    uVar1 = extraout_ECX_01;
  }
  return uVar1;
}

