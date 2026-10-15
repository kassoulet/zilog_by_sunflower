
void FUN_00034a03(ushort param_1)

{
  undefined4 *puVar1;
  ushort uVar2;
  int iVar3;
  undefined1 uVar4;
  
  iVar3 = 0;
  uVar2 = 0;
  while( true ) {
    puVar1 = (undefined4 *)(&PTR_PTR_FUN_0003397b)[iVar3];
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
    uVar2 = uVar2 + *(short *)(puVar1 + 7);
    if (param_1 <= uVar2) break;
    iVar3 = iVar3 + 1;
  }
  uVar2 = uVar2 - *(short *)(puVar1 + 7);
  uVar4 = param_1 < uVar2;
  DAT_0003398f = puVar1;
  DAT_00036450 = FUN_00034a43(param_1 - uVar2);
  (*(code *)*puVar1)();
  if ((bool)uVar4) {
    return;
  }
  return;
}

