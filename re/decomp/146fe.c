
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_000146fe(int param_1)

{
  undefined1 local_18;
  undefined4 local_14;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  for (local_8 = -0x80; local_8 < 0x80; local_8 = local_8 + 1) {
    for (local_14 = -0x80; local_14 < 0x80; local_14 = local_14 + 1) {
      if ((int)SQRT((float)local_8 * (float)/*c*/1.17 * (float)local_8 * (float)/*c*/1.17 +
                    (float)local_14 * (float)local_14) < 0x42f00000) {
        local_18 = 0xff;
      }
      else {
        local_18 = 0;
      }
      *(undefined1 *)(local_c + param_1) = local_18;
      local_c = local_c + 1;
    }
  }
  return;
}

