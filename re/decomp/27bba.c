
uint FUN_00027bba(undefined4 param_1,undefined4 param_2,undefined1 *unaff_EBX,undefined4 param_4,
                 int param_5)

{
  longdouble lVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int unaff_EBP;
  int *unaff_ESI;
  int iVar6;
  int unaff_retaddr;
  
  *unaff_EBX = 0;
  *(undefined1 **)(unaff_EBP + -0x28) = unaff_EBX;
  *(int *)(unaff_EBP + -0x24) = unaff_retaddr + 8;
  if (0 < *(int *)(unaff_EBP + -0x18)) {
    iVar3 = *(int *)(unaff_EBP + -0x18) + -8;
    *(int *)(unaff_EBP + -0x18) = iVar3;
    if ((*(ushort *)(unaff_EBP + -0x2c) & 0x7fff) != 0) {
      lVar1 = *(longdouble *)(unaff_EBP + -0x34);
      if (0 < iVar3) {
        *(longdouble *)(unaff_EBP + -0x40) = (longdouble)(int)ROUND(lVar1);
        *(longdouble *)(unaff_EBP + -0x34) =
             *(longdouble *)(unaff_EBP + -0x34) - *(longdouble *)(unaff_EBP + -0x40);
        *(undefined2 *)(unaff_EBP + -0x38) = 0x4019;
        *(undefined4 *)(unaff_EBP + -0x3c) = 3200000000;
        *(undefined4 *)(unaff_EBP + -0x40) = 0;
        *(longdouble *)(unaff_EBP + -0x34) =
             *(longdouble *)(unaff_EBP + -0x40) * *(longdouble *)(unaff_EBP + -0x34);
      }
      FUN_00027b75((int)ROUND(lVar1),*(undefined4 *)(unaff_EBP + -0x24),
                   *(undefined4 *)(unaff_EBP + -0x28));
      uVar2 = FUN_00027bba();
      return uVar2;
    }
  }
  iVar3 = *(int *)(unaff_EBP + -0x24);
  param_5 = param_5 + 7;
  for (pcVar4 = (char *)(unaff_EBP + -0x97); *pcVar4 == '0'; pcVar4 = pcVar4 + 1) {
    iVar3 = iVar3 + -1;
    param_5 = param_5 + -1;
  }
  iVar6 = *unaff_ESI;
  if ((*(byte *)(unaff_ESI + 2) & 2) == 0) {
    if ((*(byte *)(unaff_ESI + 2) & 1) != 0) {
      if (unaff_ESI[1] < 1) {
        iVar6 = iVar6 + unaff_ESI[1];
      }
      else {
        iVar6 = iVar6 + 1;
      }
      param_5 = (param_5 + 1) - unaff_ESI[1];
    }
  }
  else {
    param_5 = param_5 + unaff_ESI[1];
    iVar6 = iVar6 + param_5 + 1;
  }
  if (-1 < iVar6) {
    if (iVar3 < iVar6) {
      iVar6 = iVar3;
    }
    iVar5 = 0xf;
    if ((*(byte *)(unaff_ESI + 2) & 0x20) != 0) {
      iVar5 = 0x14;
    }
    if ((*(byte *)(unaff_ESI + 2) & 0x40) != 0) {
      iVar5 = iVar5 * 2;
    }
    if (iVar5 < iVar6) {
      iVar6 = iVar5 + 1;
    }
    *(undefined1 *)(unaff_EBP + -0x10) = 0x30;
    if ((iVar6 < iVar3) && (0x34 < (byte)pcVar4[iVar6])) {
      *(undefined1 *)(unaff_EBP + -0x10) = 0x39;
    }
    *(int *)(unaff_EBP + -0x1c) = iVar6;
    pcVar4 = pcVar4 + iVar6;
    while( true ) {
      pcVar4 = pcVar4 + -1;
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + -1;
      if (*pcVar4 != *(char *)(unaff_EBP + -0x10)) break;
      iVar6 = iVar6 + -1;
    }
    if (*(char *)(unaff_EBP + -0x10) == '9') {
      *pcVar4 = *pcVar4 + '\x01';
    }
    if (*(int *)(unaff_EBP + -0x1c) < 0) {
      iVar6 = iVar6 + 1;
      param_5 = param_5 + 1;
    }
  }
  if (iVar6 < 1) {
    param_5 = 0;
    *(undefined1 *)(unaff_EBP + -0x98) = 0x30;
    unaff_ESI[5] = 0;
  }
  if (((*(byte *)(unaff_ESI + 2) & 2) == 0) &&
     (((*(byte *)(unaff_ESI + 2) & 4) == 0 ||
      (((param_5 < -4 || (*unaff_ESI <= param_5)) && ((*(byte *)(unaff_ESI + 2) & 8) == 0)))))) {
    FUN_00027f01();
  }
  else {
    FUN_00027ce3();
  }
  return (uint)*(ushort *)(unaff_EBP + -0x14);
}

