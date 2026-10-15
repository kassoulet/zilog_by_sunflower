
int FUN_0002fd60(undefined4 param_1,byte *param_2,int unaff_EBX)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  byte *extraout_ECX_03;
  byte *extraout_ECX_04;
  byte *pbVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = 0;
  while (unaff_EBX != 0) {
    uVar3 = FUN_0003062b(param_1);
    iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    param_1 = extraout_ECX;
    if ((int)uVar3 != 0) break;
    uVar3 = FUN_0003062b(param_2);
    iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    param_1 = extraout_ECX_00;
    if ((int)uVar3 != 0) break;
    iVar2 = FUN_00030667(extraout_ECX_00,param_2);
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar3 = FUN_000306be(extraout_ECX_01,0);
    unaff_EBX = unaff_EBX + -1;
    uVar3 = FUN_000306be(param_2,(int)((ulonglong)uVar3 >> 0x20),unaff_EBX,(int)uVar3);
    iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    param_2 = (byte *)uVar3;
    param_1 = extraout_ECX_02;
  }
  if (unaff_EBX == 0) {
    return iVar2;
  }
  iVar2 = FUN_0003062b(param_1);
  pbVar1 = extraout_ECX_03;
  if (iVar2 == 0) {
    uVar3 = FUN_0003062b(param_2);
    pbVar1 = extraout_ECX_04;
    if ((int)uVar3 == 0) {
      return (int)((ulonglong)uVar3 >> 0x20);
    }
  }
  return (uint)*pbVar1 - (uint)*param_2;
}

