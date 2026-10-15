
void FUN_0002f087(int param_1,uint param_2,uint unaff_EBX,int param_4)

{
  uint *puVar1;
  int extraout_ECX;
  uint extraout_EDX;
  
  if ((*(byte *)(param_1 + 0x24) & 2) != 0) {
    thunk_FUN_00027561(*(undefined4 *)(param_1 + 4));
    param_4 = extraout_ECX;
    param_2 = extraout_EDX;
  }
  if ((param_2 != 0) && (param_2 < unaff_EBX)) {
    *(uint *)(param_1 + 4) = param_2;
    puVar1 = (uint *)(param_1 + 0x24);
    *(uint *)(param_1 + 8) = unaff_EBX;
    *(byte *)puVar1 = *(byte *)puVar1 & 0xfd;
    *puVar1 = *puVar1 | (uint)(param_4 != 0) * 2;
    *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) & 0xfe;
    return;
  }
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) & 0xfc;
  *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) | 1;
  return;
}

