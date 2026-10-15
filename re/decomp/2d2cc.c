
undefined4 FUN_0002d2cc(int param_1,undefined4 param_2,undefined1 unaff_BL)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  byte bVar4;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  bool bVar5;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0xc);
  if (iVar1 != 1) {
    if (iVar1 != 0) {
      return 0;
    }
    *(undefined4 *)(*(int *)(param_1 + 8) + 0xc) = 1;
  }
  uVar2 = *(uint *)(param_1 + 0xc);
  *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xcf;
  if (*(int *)(*(int *)(param_1 + 8) + 8) == 0) {
    FUN_00028c7a(param_1);
    param_2 = extraout_EDX;
  }
  bVar5 = (*(byte *)(param_1 + 0xd) & 4) != 0;
  if (bVar5) {
    bVar4 = *(byte *)(param_1 + 0xd) & 0xfa;
    *(byte *)(param_1 + 0xd) = bVar4;
    *(byte *)(param_1 + 0xd) = bVar4 | 1;
  }
  uVar3 = FUN_0002d371(param_1,param_2,unaff_BL,&LAB_0002d2bb);
  if (bVar5) {
    bVar4 = *(byte *)(param_1 + 0xd) & 0xfa;
    *(byte *)(param_1 + 0xd) = bVar4;
    *(byte *)(param_1 + 0xd) = bVar4 | 4;
    FUN_00028acc(param_1);
    uVar3 = extraout_EDX_00;
  }
  if ((*(byte *)(param_1 + 0xc) & 0x20) != 0) {
    uVar3 = 0xffffffff;
  }
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | uVar2 & 0x30;
  return uVar3;
}

