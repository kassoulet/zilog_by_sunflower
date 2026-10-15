
undefined8 FUN_00030229(uint param_1,uint param_2,uint unaff_EBX,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  
  if (param_4 == 0) {
    uVar3 = param_2;
    if (unaff_EBX != 1) {
      uVar3 = 0;
      if (unaff_EBX <= param_2) {
        uVar3 = param_2 / unaff_EBX;
        param_2 = param_2 % unaff_EBX;
      }
      param_1 = (uint)(CONCAT44(param_2,param_1) / (ulonglong)unaff_EBX);
    }
    return CONCAT44(uVar3,param_1);
  }
  if (param_2 <= param_4) {
    if ((param_4 == param_2) && (unaff_EBX <= param_1)) {
      return 1;
    }
    return 0;
  }
  uVar3 = 0;
  uVar5 = 0;
  iVar4 = 0;
  do {
    bVar6 = CARRY4(unaff_EBX,unaff_EBX);
    unaff_EBX = unaff_EBX * 2;
    bVar7 = CARRY4(param_4,param_4) || CARRY4(param_4 * 2,(uint)bVar6);
    param_4 = param_4 * 2 + (uint)bVar6;
    if (bVar7) goto LAB_00030289;
    iVar4 = iVar4 + 1;
  } while ((param_4 < param_2) || ((param_4 <= param_2 && (unaff_EBX <= param_1))));
  bVar6 = false;
  while( true ) {
    bVar7 = CARRY4(uVar3,uVar3);
    uVar1 = uVar3 * 2;
    uVar3 = uVar1 + bVar6;
    uVar1 = (uint)(bVar7 || CARRY4(uVar1,(uint)bVar6));
    bVar7 = CARRY4(uVar5,uVar5) || CARRY4(uVar5 * 2,uVar1);
    uVar5 = uVar5 * 2 + uVar1;
    iVar4 = iVar4 + -1;
    if (iVar4 < 0) break;
LAB_00030289:
    uVar1 = param_4 & 1;
    param_4 = param_4 >> 1 | (uint)bVar7 << 0x1f;
    unaff_EBX = unaff_EBX >> 1 | (uint)(uVar1 != 0) << 0x1f;
    bVar6 = param_1 < unaff_EBX;
    param_1 = param_1 - unaff_EBX;
    uVar1 = (uint)bVar6;
    bVar7 = param_4 <= param_2;
    uVar2 = param_2 - param_4;
    param_2 = uVar2 - uVar1;
    bVar6 = bVar7 && uVar1 <= uVar2;
    if (!bVar7 || uVar1 > uVar2) {
      do {
        bVar6 = CARRY4(uVar3,uVar3);
        uVar3 = uVar3 * 2;
        uVar5 = uVar5 * 2 + (uint)bVar6;
        iVar4 = iVar4 + -1;
        if (iVar4 < 0) goto LAB_000302ab;
        uVar1 = param_4 & 1;
        param_4 = param_4 >> 1;
        unaff_EBX = unaff_EBX >> 1 | (uint)(uVar1 != 0) << 0x1f;
        bVar6 = CARRY4(param_1,unaff_EBX);
        param_1 = param_1 + unaff_EBX;
        uVar1 = (uint)bVar6;
        bVar7 = CARRY4(param_2,param_4);
        uVar2 = param_2 + param_4;
        bVar6 = bVar7 || CARRY4(uVar2,uVar1);
        param_2 = uVar2 + uVar1;
      } while (!bVar7 && !CARRY4(uVar2,uVar1));
    }
  }
LAB_000302ab:
  return CONCAT44(uVar5,uVar3);
}

