
void FUN_00033818(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  
  DAT_00033774 = param_1;
  pbVar6 = DAT_00033770;
  do {
    uVar2 = (uint)*param_1;
    bVar7 = param_1 + 1 == (byte *)0x0;
    pbVar4 = param_1 + 1;
    do {
      pbVar5 = pbVar6;
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      pbVar5 = pbVar6 + 1;
      bVar7 = *pbVar4 == *pbVar6;
      pbVar4 = pbVar4 + 1;
      pbVar6 = pbVar5;
    } while (bVar7);
    if (bVar7) {
      return;
    }
    iVar3 = 0x400;
    do {
      pbVar6 = pbVar5;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      pbVar6 = pbVar5 + 1;
      bVar1 = *pbVar5;
      pbVar5 = pbVar6;
    } while (bVar1 != 0);
    if ((iVar3 == 0) || (*pbVar6 == 0)) {
      return;
    }
  } while( true );
}

