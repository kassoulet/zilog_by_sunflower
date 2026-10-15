
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __regparm1 FUN_000238b4(undefined4 param_1,code *param_2)

{
  code *pcVar1;
  short sVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  short extraout_CX;
  uint uVar5;
  int iVar6;
  short extraout_DX;
  uint *puVar7;
  uint *puVar8;
  char *pcVar9;
  char *pcVar10;
  undefined4 *puVar11;
  undefined2 in_ES;
  undefined2 in_DS;
  short in_GS;
  bool bVar12;
  undefined8 uVar13;
  
  DAT_0003ed20._0_2_ = 0x24;
  pcVar1 = (code *)swi(0x21);
  DAT_0003ed14 = (undefined1 *)register0x00000010;
  DAT_0003ed28 = (undefined1 *)register0x00000010;
  uVar13 = (*pcVar1)(0x3000);
  iVar6 = (int)((ulonglong)uVar13 >> 0x20);
  DAT_0003ed4b = (undefined1)uVar13;
  DAT_0003ed4c = (undefined1)((ulonglong)uVar13 >> 8);
  puVar7 = (uint *)0x0;
  pcVar9 = (char *)0x81;
  sVar2 = (short)((ulonglong)uVar13 >> 0x10);
  if (sVar2 == 0x4458) {
    DAT_0003ed14 = (undefined1 *)(iRam0000005c + 0xfffU & 0xfffff000);
    pcVar1 = (code *)swi(0x21);
    (*pcVar1)(CONCAT11(0x4a,(char)in_DS),iVar6,iRam0000005c + 0xfffU >> 0xc);
    uVar3 = SUB42(param_2,0);
    _DAT_0003ed49 = 0x2c;
  }
  else if (sVar2 == 0x4243) {
    pcVar1 = (code *)swi(0x21);
    _DAT_0003eea4 = iVar6;
    (*pcVar1)(CONCAT11(0x4a,(char)((ulonglong)uVar13 >> 0x10)),*(int *)(iVar6 + 0x1c),
              (int)&param_2 - *(int *)(iVar6 + 0x1c));
    pcVar9 = (char *)(*(int *)(iVar6 + 0x10) + 0x81);
    puVar7 = (uint *)((uint)*(ushort *)(*(int *)(iVar6 + 0x10) + 0x2c) << 4);
    uVar3 = 9;
    DAT_0003ed20._0_2_ = in_DS;
    _DAT_0003ed49 = in_DS;
  }
  else {
    pcVar1 = (code *)swi(0x21);
    uVar13 = (*pcVar1)(0xff00,0x78,0x50484152,(int)uVar13);
    if ((char)uVar13 == '\0') {
      _DAT_0003ed49 = 0x2c;
      uVar3 = 0;
    }
    else {
      if (in_GS != 0) {
        _DAT_0003eea8 = in_GS;
      }
      pcVar1 = (code *)swi(0x31);
      (*pcVar1)(6,(int)((ulonglong)uVar13 >> 0x20),CONCAT22(0x5048,in_DS));
      uVar3 = 1;
      DAT_0003ed20._0_2_ = in_ES;
      _DAT_0003ed49 = uRam0000002c;
      if (extraout_DX != 0 || extraout_CX != 0) {
        uVar3 = 0x101;
      }
    }
  }
  _DAT_0003ed10 = &stack0x00000008;
  DAT_0003ed42 = (char)uVar3;
  DAT_0003ed43 = (undefined1)((ushort)uVar3 >> 8);
  _DAT_0003ed1c = (char *)0x419c0;
  bVar12 = true;
  uVar5 = (uint)(byte)pcVar9[-1];
  do {
    pcVar10 = pcVar9;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar10 = pcVar9 + 1;
    bVar12 = *pcVar9 == ' ';
    pcVar9 = pcVar10;
  } while (bVar12);
  DAT_00023b11 = in_DS;
  _DAT_0003ed45 = puVar7;
  if (!bVar12) {
    pcVar9 = pcVar10 + -1;
    for (iVar6 = uVar5 + 1; iVar6 != 0; iVar6 = iVar6 + -1) {
      *_DAT_0003ed1c = *pcVar9;
      pcVar9 = pcVar9 + 1;
      _DAT_0003ed1c = _DAT_0003ed1c + 1;
    }
  }
  *_DAT_0003ed1c = '\0';
  _DAT_0003ed1c[1] = '\0';
  _DAT_0003ed1c = _DAT_0003ed1c + 1;
  _DAT_0003ed40 = 0;
  do {
    if (((*puVar7 | 0x20202020) == 0x37386f6e) && ((char)puVar7[1] == '=')) {
      _DAT_0003ed40 = _DAT_0003ed40 + 1;
    }
    do {
      puVar8 = puVar7;
      puVar7 = (uint *)((int)puVar8 + 1);
    } while ((char)*puVar8 != '\0');
  } while (*(char *)puVar7 != '\0');
  puVar7 = puVar8 + 1;
  pcVar9 = _DAT_0003ed1c;
  do {
    uVar5 = *puVar7;
    DAT_0003ed24 = pcVar9 + 1;
    *pcVar9 = (char)*puVar7;
    puVar7 = (uint *)((int)puVar7 + 1);
    pcVar9 = DAT_0003ed24;
  } while ((char)uVar5 != '\0');
  uVar5 = 0x16cc;
  if (DAT_0003ed42 == '\x01') {
    uVar5 = 0x1000;
  }
  puVar11 = &DAT_000402f0;
  for (uVar5 = uVar5 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)puVar11 = 0;
    puVar11 = (undefined4 *)((int)puVar11 + 1);
  }
  _DAT_0003ed18 = 0x419c0;
  param_2 = (code *)0x23ac4;
  func_24e0e(0xff);
  param_2 = thunk_FUN_00023af0;
  param_2 = (code *)func_2765c();
  FUN_00024e5a(0,0xf);
  pcVar1 = (code *)swi(0x21);
  uVar4 = (*pcVar1)(CONCAT11(0x4c,(char)param_2));
  return uVar4;
}

