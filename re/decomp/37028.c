
void FUN_00037028(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined1 in_CF;
  
  DAT_00036ffc = (undefined4 *)FUN_00037000();
  if (!(bool)in_CF) {
    puVar2 = DAT_00036ffc;
    for (uVar1 = DAT_00036ff8 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
  }
  return;
}

