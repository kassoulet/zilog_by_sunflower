
void FUN_00028883(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = &DAT_000411cc;
  do {
    puVar2 = puVar1;
    puVar1 = (undefined4 *)*puVar2;
    if (puVar1 == (undefined4 *)0x0) {
      return;
    }
  } while (param_1 != puVar1[1]);
  *(byte *)(param_1 + 0xc) = *(byte *)(puVar1[1] + 0xc) | 3;
  *puVar2 = *puVar1;
  *puVar1 = DAT_000411d0;
  DAT_000411d0 = puVar1;
  return;
}

