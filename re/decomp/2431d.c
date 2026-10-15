
int FUN_0002431d(byte *param_1,byte *param_2,int unaff_EBX)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  
  bVar2 = false;
  iVar1 = 0;
  bVar3 = true;
  do {
    if (unaff_EBX == 0) break;
    unaff_EBX = unaff_EBX + -1;
    bVar2 = *param_1 < *param_2;
    bVar3 = *param_1 == *param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  } while (bVar3);
  if (!bVar3) {
    iVar1 = (1 - (uint)bVar2) - (uint)(bVar2 != 0);
  }
  return iVar1;
}

