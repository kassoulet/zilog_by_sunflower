
void FUN_0002d9ec(undefined2 *param_1,undefined4 param_2,int unaff_EBX,code *param_4)

{
  int iVar1;
  int extraout_ECX;
  undefined1 *puVar2;
  undefined1 local_14 [4];
  
  while( true ) {
    do {
      puVar2 = local_14;
      if (*(int *)(unaff_EBX + 0x28) < 1) {
        return;
      }
      iVar1 = FUN_0002f440(local_14,*param_1);
      param_1 = param_1 + 1;
    } while (iVar1 == -1);
    if (*(int *)(unaff_EBX + 0x28) < iVar1) break;
    while (iVar1 = iVar1 + -1, iVar1 != -1) {
      (*param_4)(unaff_EBX,*puVar2);
      puVar2 = (undefined1 *)(extraout_ECX + 1);
      *(int *)(unaff_EBX + 0x28) = *(int *)(unaff_EBX + 0x28) + -1;
    }
  }
  *(undefined4 *)(unaff_EBX + 0x28) = 0;
  return;
}

