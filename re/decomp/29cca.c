
int FUN_00029cca(int param_1)

{
  int extraout_ECX;
  
  *(undefined ***)(param_1 + 0x28) = &PTR_FUN_0003ec80;
  if ((*(byte *)(param_1 + 0x24) & 2) == 0) {
    return param_1;
  }
  thunk_FUN_00027561(*(undefined4 *)(param_1 + 4));
  return extraout_ECX;
}

