
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0003299e(void)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_0003151d;
  if (*(ushort *)(DAT_000314f6 + 0x36) <= DAT_0003151d) {
    DAT_000314f5 = 1;
    uVar2 = (uint)*(ushort *)(DAT_000314f6 + 0x38);
  }
  DAT_00031514 = (short)uVar2;
  bVar1 = *(byte *)(DAT_000314f6 + 0x3e + uVar2);
  _DAT_00031516 = (ushort)bVar1;
  DAT_0003150c = *(int *)(DAT_000314f6 + 0x1be + (uint)bVar1 * 4);
  if (DAT_0003150c == 0) {
    DAT_0003151a = 0x40;
  }
  else {
    DAT_0003151a = *(undefined2 *)(DAT_0003150c + 10);
  }
  DAT_0003151d = 0xffff;
  return;
}

