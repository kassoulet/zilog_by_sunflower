
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00014d0b(int param_1,int param_2,int unaff_EBX)

{
  short sVar1;
  double dVar2;
  longdouble lVar3;
  undefined2 extraout_ST0h;
  undefined2 extraout_ST0h_00;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  for (local_14 = 0; local_14 < 0xbc; local_14 = local_14 + 1) {
    for (local_18 = 0; local_18 < 0x200; local_18 = local_18 + 1) {
      lVar3 = (longdouble)
              fsin((longdouble)local_18 * (longdouble)/*c*/3.1415927 * (longdouble)/*c*/0.0039062);
      dVar2 = ftrunc(SUB108((longdouble)local_14 * lVar3 + (longdouble)/*c*/160.0,0));
      local_2c = (int)ROUND((longdouble)CONCAT28(extraout_ST0h,dVar2));
      lVar3 = (longdouble)
              fcos((longdouble)local_18 * (longdouble)/*c*/3.1415927 * (longdouble)/*c*/0.0039062);
      dVar2 = ftrunc(SUB108((longdouble)local_14 * lVar3 + (longdouble)/*c*/100.0,0));
      local_30 = (int)ROUND((longdouble)CONCAT28(extraout_ST0h_00,dVar2));
      if (local_30 < 0) {
        local_30 = 0;
      }
      if (199 < local_30) {
        local_30 = 199;
      }
      if (local_2c < 0) {
        local_2c = 0;
      }
      if (0x13f < local_2c) {
        local_2c = 0x13f;
      }
      *(short *)((local_18 * 0xbc + local_14) * 2 + param_1) =
           (short)local_2c + (short)local_30 * 0x140;
    }
  }
  FUN_00017e46(unaff_EBX,0,64000);
  for (local_18 = 0; local_18 < 0x17800; local_18 = local_18 + 1) {
    *(undefined1 *)((uint)*(ushort *)(local_18 * 2 + param_1) + unaff_EBX) = 0xff;
  }
  local_1c = 0;
  for (local_18 = 0x140; local_18 < 0xf8c0; local_18 = local_18 + 1) {
    if (*(char *)(unaff_EBX + local_18) == '\0') {
      sVar1 = (short)local_18;
      if (*(char *)(unaff_EBX + local_18 + -0x140) != '\0') {
        *(short *)(local_1c * 2 + param_2) = sVar1 + -0x140;
        *(short *)(local_1c * 2 + param_2 + 2) = sVar1;
      }
      if (*(char *)(unaff_EBX + local_18 + 0x140) != '\0') {
        *(short *)(local_1c * 2 + param_2) = sVar1 + 0x140;
        *(short *)(local_1c * 2 + param_2 + 2) = sVar1;
      }
      if (*(char *)(unaff_EBX + local_18 + -1) != '\0') {
        *(short *)(local_1c * 2 + param_2) = sVar1 + -1;
        *(short *)(local_1c * 2 + param_2 + 2) = sVar1;
      }
      if (*(char *)(unaff_EBX + local_18 + 1) != '\0') {
        *(short *)(local_1c * 2 + param_2) = sVar1 + 1;
        *(short *)(local_1c * 2 + param_2 + 2) = sVar1;
      }
      local_1c = local_1c + 2;
    }
  }
  return local_1c >> 1;
}

