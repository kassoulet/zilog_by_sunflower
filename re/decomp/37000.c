
void FUN_00037000(int param_1)

{
  DAT_00036ff8 = param_1 + 3U & 0xfffffffc;
  DAT_00036ffc = FUN_000243a3();
  if (DAT_00036ffc == 0) {
    DAT_00036ffc = 2;
    return;
  }
  return;
}

