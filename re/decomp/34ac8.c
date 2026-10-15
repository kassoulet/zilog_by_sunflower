
void FUN_00034ac8(undefined2 param_1,undefined4 param_2,int unaff_EBX)

{
  uint uVar1;
  undefined1 uVar2;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  int iVar3;
  int extraout_EDX;
  int unaff_EDI;
  int iVar4;
  undefined2 *puVar5;
  byte bVar6;
  
  bVar6 = 0;
  iVar4 = unaff_EDI + DAT_00033768;
  uVar2 = (undefined1)((ushort)param_1 >> 8);
  *(ushort *)(iVar4 + 0xb8000) = CONCAT11(uVar2,0xc9);
  puVar5 = (undefined2 *)(iVar4 + 0xb8002);
  for (iVar3 = unaff_EBX; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = CONCAT11(uVar2,0xcd);
    puVar5 = puVar5 + 1;
  }
  *puVar5 = CONCAT11(uVar2,0xbb);
  FUN_00034aa7();
  FUN_00034ab3();
  puVar5[1] = CONCAT11(extraout_AH,0xcc);
  puVar5 = puVar5 + (uint)bVar6 * -2 + 2;
  for (iVar3 = unaff_EBX; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = CONCAT11(extraout_AH,0xcd);
    puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
  }
  uVar1 = (uint)bVar6;
  *puVar5 = CONCAT11(extraout_AH,0xb9);
  FUN_00034aa7();
  do {
    FUN_00034ab3();
  } while (extraout_EDX != 1);
  puVar5[uVar1 * -2 + 1] = CONCAT11(extraout_AH_00,200);
  puVar5 = puVar5 + uVar1 * -2 + 1 + (uint)bVar6 * -2 + 1;
  for (; unaff_EBX != 0; unaff_EBX = unaff_EBX + -1) {
    *puVar5 = CONCAT11(extraout_AH_00,0xcd);
    puVar5 = puVar5 + (uint)bVar6 * -2 + 1;
  }
  *puVar5 = CONCAT11(extraout_AH_00,0xbc);
  return;
}

