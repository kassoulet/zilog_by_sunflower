
undefined8 FUN_00029432(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  byte bVar5;
  undefined8 uVar6;
  uint local_18;
  
  if ((DAT_0003fd8c != 0) && (DAT_0003ed14 != -2)) {
    iVar2 = FUN_00029629(&local_18);
    if (iVar2 == 0) goto LAB_00029429;
    bVar5 = DAT_0003ed42 == '\0';
    if (DAT_0003ed42 == '\x01') {
      puVar3 = (uint *)FUN_00029361(local_18);
      if (puVar3 != (uint *)0x0) {
        local_18 = *puVar3;
      }
    }
    else {
      pcVar1 = (code *)swi(0x21);
      uVar4 = (*pcVar1)(0x80004800);
      puVar3 = (uint *)(uVar4 & ~-(uint)bVar5);
      local_18 = local_18 - 4;
    }
    if (((puVar3 != (uint *)0x0) && (uVar4 = local_18 - 4, uVar4 <= local_18)) && (0x37 < uVar4)) {
      *puVar3 = uVar4;
      local_18 = uVar4;
      uVar6 = FUN_0002929e(puVar3);
      iVar2 = (int)((ulonglong)uVar6 >> 0x20);
      puVar3 = (uint *)uVar6;
      local_18 = *puVar3;
      *puVar3 = local_18 | 1;
      *(undefined4 *)(iVar2 + 0x14) = 0;
      *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 1;
      FUN_00027561(puVar3 + 1);
      iVar2 = 1;
      goto LAB_00029429;
    }
  }
  iVar2 = 0;
LAB_00029429:
  return CONCAT44(param_2,iVar2);
}

