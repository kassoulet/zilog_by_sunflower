
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void func_146f9(int param_1)

{
  undefined1 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_20 = 0;
  for (uStack_1c = -0x80; uStack_1c < 0x80; uStack_1c = uStack_1c + 1) {
    for (uStack_28 = -0x80; uStack_28 < 0x80; uStack_28 = uStack_28 + 1) {
      if ((int)SQRT((float)uStack_1c * (float)/*c*/1.17 *
                    (float)uStack_1c * (float)/*c*/1.17 + (float)uStack_28 * (float)uStack_28) <
          0x42f00000) {
        uStack_2c = 0xff;
      }
      else {
        uStack_2c = 0;
      }
      *(undefined1 *)(uStack_20 + param_1) = uStack_2c;
      uStack_20 = uStack_20 + 1;
    }
  }
  return;
}

