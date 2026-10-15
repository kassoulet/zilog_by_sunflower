
void FUN_0003978a(undefined1 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  undefined1 in_CF;
  
  DAT_00036450 = 1;
  FUN_00039715(param_1,param_2,0xe1);
  if (!(bool)in_CF) {
    uVar1 = FUN_00039720();
    if (!(bool)in_CF) {
      uVar2 = FUN_00039720();
      if (!(bool)in_CF) {
        uVar3 = CONCAT11(uVar1,uVar2);
        if (uVar3 < 0x200) {
          DAT_00036450 = 1;
        }
        else if (uVar3 == 0x200) {
          DAT_00036450 = 2;
        }
        else if (uVar3 < 0x300) {
          DAT_00036450 = 3;
        }
        else if (uVar3 < 0x400) {
          DAT_00036450 = 4;
        }
        else {
          DAT_00036450 = 5;
        }
        return;
      }
    }
  }
  return;
}

