
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00022990(int param_1,int param_2,int unaff_EBX,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int unaff_ESI;
  int iVar4;
  int unaff_EDI;
  uint *puVar5;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (0x13f < unaff_EBX) {
    unaff_EBX = 0x13f;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  if (199 < param_2) {
    param_2 = 199;
  }
  DAT_00022984 = param_4 - param_1;
  DAT_00022988 = param_2 - unaff_EBX;
  puVar5 = (uint *)(unaff_EDI + (param_1 + unaff_EBX * 0x140) * 4);
  iVar4 = DAT_00022984;
  _DAT_0002298c = DAT_00022988;
  do {
    do {
      uVar1 = *puVar5;
      uVar3 = uVar1 & 0xff;
      uVar2 = uVar1 >> 8 & 0xff;
      uVar1 = uVar1 >> 0x10 & 0xff;
      *(char *)puVar5 =
           (char)((uint)(*(int *)(unaff_ESI + uVar3 * 4) + *(int *)(unaff_ESI + 0x400 + uVar2 * 4) +
                        *(int *)(unaff_ESI + 0x800 + uVar1 * 4)) >> 0x18) + 'p';
      *(char *)((int)puVar5 + 1) =
           (char)((uint)(*(int *)(unaff_ESI + 0xc00 + uVar3 * 4) +
                         *(int *)(unaff_ESI + 0x1000 + uVar2 * 4) +
                        *(int *)(unaff_ESI + 0x1400 + uVar1 * 4)) >> 0x18) + 'p';
      *(char *)((int)puVar5 + 2) =
           (char)((uint)(*(int *)(unaff_ESI + 0x1800 + uVar3 * 4) +
                         *(int *)(unaff_ESI + 0x1c00 + uVar2 * 4) +
                        *(int *)(unaff_ESI + 0x2000 + uVar1 * 4)) >> 0x18) + 'p';
      puVar5 = puVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    puVar5 = puVar5 + (0x140 - DAT_00022984);
    _DAT_0002298c = _DAT_0002298c + -1;
    iVar4 = DAT_00022984;
  } while (_DAT_0002298c != 0);
  return;
}

