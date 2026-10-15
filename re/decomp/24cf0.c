
undefined8 FUN_00024cf0(int param_1,int *param_2,undefined1 *unaff_EBX,byte param_4)

{
  byte bVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined3 uVar4;
  undefined1 *puVar5;
  undefined2 uVar6;
  undefined1 *puVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint *unaff_EDI;
  uint *puVar11;
  
  bRam00024d48 = ~param_4;
  pbVar9 = (byte *)(*param_2 + (uint)*(ushort *)(param_2[5] + (param_1 - param_2[4]) * 2));
  uRam00024d39 = (uint)*(byte *)(param_2[6] + (param_1 - param_2[4]));
  iRam00024d6a = (0x140 - uRam00024d39) * 4;
  iRam00024d70 = param_2[1] - uRam00024d39;
  iVar8 = param_2[2];
  do {
    puVar7 = &DAT_11111111;
    puVar5 = unaff_EBX;
    do {
      puVar11 = unaff_EDI;
      pbVar10 = pbVar9;
      bVar1 = *pbVar10;
      unaff_EBX = (undefined1 *)CONCAT31((int3)((uint)puVar5 >> 8),bVar1);
      if (bVar1 != 0) {
        uVar3 = *puVar11;
        uVar6 = (undefined2)((uint)puVar5 >> 0x10);
        uVar4 = CONCAT21(uVar6,~*(byte *)CONCAT22(uVar6,CONCAT11(0x11,~bVar1)));
        uVar2 = *(undefined1 *)CONCAT31(uVar4,(char)(uVar3 >> 8));
        unaff_EBX = (undefined1 *)CONCAT31(uVar4,(char)(uVar3 >> 0x10));
        *puVar11 = CONCAT22((ushort)(uVar3 >> 0x18),CONCAT11(*unaff_EBX,uVar2)) << 8 |
                   CONCAT11(uVar2,*(undefined1 *)CONCAT31(uVar4,(char)uVar3)) & 0xff;
      }
      puVar7 = puVar7 + -1;
      puVar5 = unaff_EBX;
      pbVar9 = pbVar10 + 1;
      unaff_EDI = puVar11 + 1;
    } while (puVar7 != (undefined1 *)0x0);
    unaff_EDI = (uint *)((int)puVar11 + 0x11111115);
    pbVar9 = pbVar10 + 0x11111112;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  return CONCAT44(param_2,param_1);
}

