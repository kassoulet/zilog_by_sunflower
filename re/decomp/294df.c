
undefined8 FUN_000294df(uint param_1,undefined4 param_2)

{
  int *piVar1;
  undefined3 uVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  ushort in_DS;
  undefined8 uVar8;
  uint local_18;
  
  local_18 = param_1;
  if (((DAT_0003ed42 == 1) && (DAT_0003ed43 == '\0')) || (DAT_0003ed42 == 9)) {
    iVar3 = FUN_00029432(param_1);
    goto LAB_00029620;
  }
  if ((DAT_0003fd8c == 0) || (DAT_0003ed14 == 0xfffffffe)) goto LAB_00029516;
  iVar3 = FUN_00029629(&local_18);
  if (iVar3 == 0) goto LAB_00029620;
  if (((1 < DAT_0003ed42) && (DAT_0003ed42 < 9)) && (DAT_0003ed44 == '\0')) {
    uVar2 = SegmentLimit((uint)in_DS);
    DAT_0003ed14 = (ushort)uVar2 + 1;
  }
  uVar6 = local_18 + DAT_0003ed14;
  if (uVar6 < DAT_0003ed14) {
    uVar6 = 0xfffffffe;
  }
  uVar8 = FUN_0002ed04(uVar6);
  puVar7 = (uint *)((ulonglong)uVar8 >> 0x20);
  puVar4 = (uint *)uVar8;
  if (((puVar4 != (uint *)0xffffffff) && (puVar4 < (uint *)0xfffffff9)) && (puVar4 < puVar7)) {
    uVar6 = (int)puVar7 - (int)puVar4;
    local_18 = uVar6 - 4;
    puVar7 = DAT_0003eeb4;
    if (local_18 <= uVar6) {
      for (; ((puVar7 != (uint *)0x0 && (puVar7[2] != 0)) &&
             ((puVar4 < puVar7 || ((uint *)((int)puVar7 + *puVar7 + 4) < puVar4))));
          puVar7 = (uint *)puVar7[2]) {
      }
      if (puVar7 == (uint *)0x0) {
LAB_000295e4:
        if (local_18 < 0x38) goto LAB_00029516;
        *puVar4 = local_18;
        uVar8 = FUN_0002929e(puVar4,puVar4);
        local_18 = *(uint *)uVar8;
      }
      else {
        puVar5 = (uint *)(*puVar7 + (int)puVar7);
        uVar8 = CONCAT44(puVar7,puVar5);
        if (puVar4 + -1 != puVar5) goto LAB_000295e4;
        *puVar7 = *puVar7 + uVar6;
        *(undefined4 *)((int)puVar5 + uVar6) = 0xffffffff;
        local_18 = uVar6;
      }
      iVar3 = (int)((ulonglong)uVar8 >> 0x20);
      *(uint *)uVar8 = local_18 | 1;
      piVar1 = (int *)(iVar3 + 0x18);
      *piVar1 = *piVar1 + 1;
      *(undefined4 *)(iVar3 + 0x14) = 0xffffffff;
      FUN_00027561((uint *)uVar8 + 1);
      iVar3 = 1;
      goto LAB_00029620;
    }
  }
LAB_00029516:
  iVar3 = 0;
LAB_00029620:
  return CONCAT44(param_2,iVar3);
}

