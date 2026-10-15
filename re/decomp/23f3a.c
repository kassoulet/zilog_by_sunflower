
uint FUN_00023f3a(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  int iVar4;
  undefined1 auStack_b4 [160];
  
  if (*(int *)(param_1 + 0xc) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = 0;
    if ((*(byte *)(param_1 + 0xd) & 0x10) != 0) {
      uVar1 = FUN_00028acc(param_1);
      param_1 = extraout_ECX;
    }
    iVar2 = FUN_0002433b(param_1);
    iVar4 = extraout_ECX_00;
    if (iVar2 != -1) {
      FUN_00028bca(*(undefined4 *)(extraout_ECX_00 + 0x10),iVar2,0);
      iVar4 = extraout_ECX_01;
    }
    if (param_2 != 0) {
      uVar3 = FUN_00028c2f(*(undefined4 *)(iVar4 + 0x10));
      uVar1 = uVar1 | uVar3;
      iVar4 = extraout_ECX_02;
    }
    if ((*(byte *)(iVar4 + 0xc) & 8) != 0) {
      FUN_00027561(*(undefined4 *)(*(int *)(iVar4 + 8) + 8));
      *(undefined4 *)(*(int *)(extraout_ECX_03 + 8) + 8) = 0;
      iVar4 = extraout_ECX_03;
    }
    if ((*(byte *)(iVar4 + 0xd) & 8) != 0) {
      FUN_00023e90(auStack_b4,*(undefined1 *)(*(int *)(iVar4 + 8) + 0x14));
      thunk_FUN_0002ebc2(auStack_b4);
    }
  }
  return uVar1;
}

