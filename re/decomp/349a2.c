
short FUN_000349a2(void)

{
  short sVar1;
  undefined4 *puVar2;
  short sVar3;
  int iVar4;
  undefined1 uVar5;
  
  DAT_00033993 = 0;
  DAT_00033995 = 0;
  for (iVar4 = 0; puVar2 = (undefined4 *)(&PTR_PTR_FUN_0003397b)[iVar4], puVar2 != (undefined4 *)0x0
      ; iVar4 = iVar4 + 1) {
    sVar1 = *(short *)(puVar2 + 7);
    uVar5 = 0;
    if (DAT_00033993 == 0) {
      FUN_00034a43();
      sVar3 = (*(code *)*puVar2)();
      if (!(bool)uVar5) {
        DAT_00033993 = sVar3 + DAT_00033995;
      }
    }
    DAT_00033995 = DAT_00033995 + sVar1;
  }
  return DAT_00033995;
}

