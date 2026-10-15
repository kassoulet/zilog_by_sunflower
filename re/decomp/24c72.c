
void FUN_00024c72(int param_1,uint param_2)

{
  undefined1 auStack_4 [4];
  
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | param_2;
  if ((*(uint *)(param_1 + 0x10) & *(uint *)(param_1 + 0x14)) == 0) {
    return;
  }
  FUN_00029e79(auStack_4);
  return;
}

