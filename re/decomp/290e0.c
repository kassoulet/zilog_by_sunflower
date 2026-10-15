
void FUN_000290e0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == DAT_0003eeb4) {
    DAT_0003eeb4 = *(int *)(DAT_0003eeb4 + 8);
  }
  if ((param_1 == DAT_0003eeb8) && (DAT_0003eeb8 = *(int *)(DAT_0003eeb8 + 4), DAT_0003eeb8 == 0)) {
    DAT_0003eeb8 = DAT_0003eeb4;
    DAT_0003eebc = 0;
  }
  if (param_1 == DAT_000411a0) {
    DAT_000411a0 = 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    *(int *)(iVar1 + 8) = iVar2;
  }
  if (iVar2 != 0) {
    *(int *)(iVar2 + 4) = iVar1;
  }
  return;
}

