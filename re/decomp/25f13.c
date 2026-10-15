
void __regparm3 FUN_00025f13(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int unaff_EBP;
  int iVar5;
  int unaff_EDI;
  
  iVar3 = *(int *)(unaff_EBP + ((uint)(param_3 + param_2) >> 1) * 4);
  iVar4 = param_3;
  iVar5 = param_2;
  do {
    for (; iVar3 < *(int *)(unaff_EBP + iVar4 * 4); iVar4 = iVar4 + 1) {
    }
    for (; *(int *)(unaff_EBP + iVar5 * 4) < iVar3; iVar5 = iVar5 + -1) {
    }
    if (iVar4 <= iVar5) {
      LOCK();
      puVar1 = (undefined4 *)(unaff_EBP + iVar5 * 4);
      uVar2 = *puVar1;
      *puVar1 = *(undefined4 *)(unaff_EBP + iVar4 * 4);
      UNLOCK();
      *(undefined4 *)(unaff_EBP + iVar4 * 4) = uVar2;
      LOCK();
      puVar1 = (undefined4 *)(unaff_EDI + iVar5 * 4);
      uVar2 = *puVar1;
      *puVar1 = *(undefined4 *)(unaff_EDI + iVar4 * 4);
      UNLOCK();
      *(undefined4 *)(unaff_EDI + iVar4 * 4) = uVar2;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + -1;
    }
  } while (iVar4 <= iVar5);
  if (param_3 < iVar5) {
    FUN_00025f13(iVar3,iVar5);
  }
  if (iVar4 < param_2) {
    FUN_00025f13();
  }
  return;
}

