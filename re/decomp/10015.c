
void FUN_00010015(void)

{
  DAT_0004031c = DAT_0004031c + 1;
  DAT_00040324 = DAT_00040324 + 1;
  if (DAT_00040324 == 0x46) {
    DAT_00040324 = 0;
    *(undefined4 *)(DAT_00040304 + 0x14) = *(undefined4 *)(DAT_00040304 + 0x10);
    *(undefined4 *)(DAT_00040304 + 0x10) = 0;
  }
  return;
}

