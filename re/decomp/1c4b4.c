
undefined8 FUN_0001c4b4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  uint *puVar3;
  uint *unaff_EDI;
  
  if (*(char *)(unaff_ESI + 0xd) == '\x01') {
    puVar3 = (uint *)(unaff_ESI + 0x16);
    while (uVar2 = *puVar3, uVar2 != 0xffffffff) {
      puVar3 = puVar3 + 1;
      if ((uVar2 & 0x80000000) == 0) {
        for (; uVar2 != 0; uVar2 = uVar2 - 1) {
          *unaff_EDI = 0;
          unaff_EDI = unaff_EDI + 1;
        }
      }
      else {
        for (uVar2 = uVar2 & 0x7fffffff; uVar2 != 0; uVar2 = uVar2 - 1) {
          *unaff_EDI = *puVar3;
          puVar3 = puVar3 + 1;
          unaff_EDI = unaff_EDI + 1;
        }
      }
    }
  }
  else {
    if (*(char *)(unaff_ESI + 0xc) != ' ') {
      return CONCAT44(param_2,param_1);
    }
    puVar3 = (uint *)(unaff_ESI + 0x16);
    for (iVar1 = 64000; iVar1 != 0; iVar1 = iVar1 + -1) {
      *unaff_EDI = *puVar3;
      puVar3 = puVar3 + 1;
      unaff_EDI = unaff_EDI + 1;
    }
  }
  return CONCAT44(param_2,param_1);
}

