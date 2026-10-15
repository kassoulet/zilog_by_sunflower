
void FUN_0001b7e3(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_20;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  iVar2 = *(int *)(param_1 + 0x18);
  for (local_20 = 0; local_20 < iVar2; local_20 = local_20 + 1) {
    uVar3 = *(undefined4 *)(local_20 * 0xc + iVar1);
    *(undefined4 *)(local_20 * 0xc + iVar1) = *(undefined4 *)(local_20 * 0xc + iVar1 + 4);
    *(undefined4 *)(local_20 * 0xc + iVar1 + 4) = uVar3;
  }
  return;
}

