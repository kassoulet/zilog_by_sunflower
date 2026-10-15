
undefined8 FUN_00024d79(int param_1,int *param_2,undefined1 *unaff_EBX,byte param_4)

{
  byte bVar1;
  undefined1 uVar2;
  undefined3 uVar3;
  undefined1 *puVar4;
  undefined2 uVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint *unaff_EDI;
  uint *puVar11;
  
  bRam00024dd3 = ~param_4;
  pbVar9 = (byte *)(*param_2 + (uint)*(ushort *)(param_2[5] + (param_1 - param_2[4]) * 2));
  uRam00024dc2 = (uint)*(byte *)(param_2[6] + (param_1 - param_2[4]));
  iRam00024df3 = (0x140 - uRam00024dc2) * 4;
  iRam00024df9 = param_2[1] - uRam00024dc2;
  iVar7 = param_2[2];
  do {
    puVar6 = &DAT_11111111;
    puVar4 = unaff_EBX;
    do {
      puVar11 = unaff_EDI;
      pbVar10 = pbVar9;
      bVar1 = *pbVar10;
      unaff_EBX = (undefined1 *)CONCAT31((int3)((uint)puVar4 >> 8),bVar1);
      if (bVar1 != 0) {
        uVar8 = ~*puVar11;
        uVar5 = (undefined2)((uint)puVar4 >> 0x10);
        uVar3 = CONCAT21(uVar5,*(undefined1 *)CONCAT22(uVar5,CONCAT11(0x11,~bVar1)));
        uVar2 = *(undefined1 *)CONCAT31(uVar3,(char)(uVar8 >> 8));
        unaff_EBX = (undefined1 *)CONCAT31(uVar3,(char)(uVar8 >> 0x10));
        *puVar11 = CONCAT22((ushort)(uVar8 >> 0x18),CONCAT11(*unaff_EBX,uVar2)) << 8 |
                   CONCAT11(uVar2,*(undefined1 *)CONCAT31(uVar3,(char)uVar8)) & 0xff;
      }
      puVar6 = puVar6 + -1;
      puVar4 = unaff_EBX;
      pbVar9 = pbVar10 + 1;
      unaff_EDI = puVar11 + 1;
    } while (puVar6 != (undefined1 *)0x0);
    unaff_EDI = (uint *)((int)puVar11 + 0x11111115);
    pbVar9 = pbVar10 + 0x11111112;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  return CONCAT44(param_2,param_1);
}

