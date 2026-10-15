
void FUN_000288da(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((*(byte *)(param_1 + 0xd) & 0x20) == 0) {
    uVar3 = FUN_0002e69a(*(undefined4 *)(param_1 + 0x10));
    iVar2 = (int)((ulonglong)uVar3 >> 0x20);
    if ((int)uVar3 != 0) {
      bVar1 = *(byte *)(iVar2 + 0xd);
      *(byte *)(iVar2 + 0xd) = bVar1 | 0x20;
      if ((bVar1 & 7) == 0) {
        *(byte *)(iVar2 + 0xd) = bVar1 | 0x22;
      }
    }
  }
  return;
}

