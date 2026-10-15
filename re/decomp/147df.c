
void FUN_000147df(int param_1)

{
  undefined4 local_1c;
  
  for (local_1c = 0; local_1c < 0x10000; local_1c = local_1c + 1) {
    *(uint *)(local_1c * 4 + param_1) = ~*(uint *)(local_1c * 4 + param_1) & 0xffffff;
  }
  return;
}

