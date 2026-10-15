
void FUN_000399bd(uint param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined2 *puVar5;
  
  DAT_000398a8 = (undefined2)param_1;
  if (DAT_000398ae != 0) {
    if (param_1 == 0) {
      iVar2 = 0xffff;
    }
    else {
      iVar2 = (int)(0x3e800 / (ulonglong)param_1);
    }
    iVar3 = 0;
    puVar4 = DAT_000398aa;
    do {
      sVar1 = 0;
      puVar5 = puVar4;
      do {
        puVar4 = puVar5 + 1;
        *puVar5 = (short)(((longlong)(int)(char)sVar1 * (longlong)iVar3) / (longlong)(iVar2 << 6));
        sVar1 = sVar1 + 1;
        puVar5 = puVar4;
      } while (sVar1 != 0x100);
      iVar3 = iVar3 + 0x10000;
    } while (iVar3 != 0x410000);
  }
  return;
}

