
void FUN_00014834(void)

{
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  for (local_1c = 0; local_1c < 0x100; local_1c = local_1c + 1) {
    for (local_24 = 0; local_24 < 0x100; local_24 = local_24 + 1) {
      *(char *)(DAT_000402f4 + local_20) =
           -1 - (char)((uint)((0xff - local_1c) * (0xff - local_24)) >> 8);
      *(byte *)(DAT_000402f8 + local_20) = ~*(byte *)(DAT_000402f4 + local_20);
      local_20 = local_20 + 1;
    }
  }
  return;
}

