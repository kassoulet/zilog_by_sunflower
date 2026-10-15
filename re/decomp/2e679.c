
void FUN_0002e679(int param_1,uint param_2)

{
  if (param_2 != 0) {
    *(uint *)(DAT_0003fd70 + param_1 * 4) = param_2 | 0x4000;
    return;
  }
  *(undefined4 *)(DAT_0003fd70 + param_1 * 4) = 0;
  return;
}

