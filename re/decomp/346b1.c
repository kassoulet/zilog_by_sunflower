
void FUN_000346b1(void)

{
  int iVar1;
  ulonglong uVar2;
  longlong lVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  sbyte sVar8;
  int iVar9;
  
  iVar9 = 0;
  do {
    iVar1 = (&DAT_000364f2)[iVar9];
    if (((&DAT_00036472)[iVar9] & 0x20) != 0) {
      FUN_0003495d((&DAT_000365f2)[iVar9] + (&DAT_00036e32)[iVar9]);
    }
    if (((&DAT_00036472)[iVar9] & 0x40) != 0) {
      uVar2 = (ulonglong)((uint)(byte)(&DAT_000367b2)[iVar9] * (uint)DAT_0003646d) *
              (ulonglong)(byte)(&DAT_00036772)[iVar9];
      cVar7 = '\r';
      if (((&DAT_00036472)[iVar9] & 8) != 0) {
        iVar6 = (int)(uVar2 * (ushort)(&DAT_00036ab2)[iVar9] >> 0x20);
        uVar2 = CONCAT44(iVar6,(uint)(uVar2 * (ushort)(&DAT_00036ab2)[iVar9]) >> 9 | iVar6 << 0x17);
        cVar7 = '\x13';
      }
      if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0xa4) & 1) != 0)) {
        uVar2 = (uVar2 & 0xffffffff) * (ulonglong)(byte)(&DAT_00036c32)[iVar9];
        cVar7 = cVar7 + '\x06';
      }
      iVar6 = (int)(uVar2 >> 0x20);
      bVar4 = cVar7 - 6U & 0x1f;
      uVar5 = (uint)uVar2 >> bVar4 | iVar6 << 0x20 - bVar4;
      lVar3 = CONCAT44(iVar6,uVar5);
      sVar8 = 6;
      if ((&DAT_000368b2)[iVar9] != 0) {
        lVar3 = (ulonglong)uVar5 * (ulonglong)*(byte *)((&DAT_000368b2)[iVar9] + 0x3b);
        sVar8 = 0xc;
      }
      (&DAT_000367f2)[iVar9] =
           (byte)((uint)lVar3 >> sVar8) | (byte)((int)((ulonglong)lVar3 >> 0x20) << 0x20 - sVar8);
    }
    if (((&DAT_00036472)[iVar9] & 0x80) != 0) {
      bVar4 = (&DAT_00036832)[iVar9];
      if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0xd9) & 1) != 0)) {
        bVar4 = (char)((ushort)((short)(char)((&DAT_00036d72)[iVar9] + -0x20) *
                               (short)(char)(bVar4 ^ (char)bVar4 >> 7)) >> 5) +
                (&DAT_00036832)[iVar9];
      }
      (&DAT_00036872)[iVar9] = bVar4;
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 != DAT_0003646e);
  (**(code **)(DAT_0003398f + 0x18))();
  return;
}

