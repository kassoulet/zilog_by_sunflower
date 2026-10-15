
int FUN_0002d800(short *param_1,undefined4 param_2,int unaff_EBX)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined1 auStack_10 [8];
  
  iVar3 = 0;
  if (unaff_EBX == -1) {
    while (sVar1 = *param_1, sVar1 != 0) {
      param_1 = param_1 + 1;
      iVar2 = FUN_0002f440(auStack_10,sVar1);
      iVar3 = extraout_ECX;
      if (iVar2 != -1) {
        iVar3 = extraout_ECX + iVar2;
      }
    }
  }
  else {
    while ((*param_1 != 0 && (iVar3 <= unaff_EBX))) {
      iVar2 = FUN_0002f440(auStack_10,*param_1);
      param_1 = param_1 + 1;
      iVar3 = extraout_ECX_00;
      if (iVar2 != -1) {
        iVar3 = extraout_ECX_00 + iVar2;
      }
    }
    if (unaff_EBX < iVar3) {
      return unaff_EBX;
    }
  }
  return iVar3;
}

