
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_000246a1(void)

{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort *puVar6;
  
  uVar1 = DAT_0003eede;
  LOCK();
  DAT_0003eede = DAT_0003eede + DAT_0003eed0;
  UNLOCK();
  uVar4 = (ushort)uVar1 & 7;
  puVar6 = (ushort *)((uVar1 >> 3) + _DAT_0003eec0);
  uVar5 = *puVar6;
  uVar3 = CONCAT31((int3)(CONCAT22((ushort)(uVar1 >> 0x13),uVar5) >> 8),(char)puVar6[1]);
  if ((uVar1 & 7) != 0) {
    do {
      bVar2 = (byte)uVar3;
      uVar3 = CONCAT31((int3)((uint)uVar3 >> 8),bVar2 >> 1);
      uVar5 = uVar5 >> 1 | (ushort)(bVar2 & 1) << 0xf;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  return CONCAT22((short)((uint)uVar3 >> 0x10),uVar5 & (&DAT_0003eed6)[(ushort)(DAT_0003eed0 - 9)]);
}

