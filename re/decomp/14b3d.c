
void FUN_00014b3d(int param_1,int param_2)

{
  undefined4 local_28;
  undefined4 local_18;
  
  for (local_18 = 0; (int)local_18 < 0x100; local_18 = local_18 + 1) {
    for (local_28 = 0; (int)local_28 < 0x100; local_28 = local_28 + 1) {
      *(ushort *)((local_18 * 0x100 + local_28) * 2 + param_1) =
           (ushort)(byte)((char)local_18 +
                         (*(char *)((local_28 & 0xff) + (local_18 - 1 & 0xff) * 0x100 + param_2) -
                         *(char *)((local_18 + 2 & 0xff) * 0x100 + (local_28 & 0xff) + param_2))) *
           0x100 + (ushort)(byte)((char)local_28 +
                                 (*(char *)((local_18 & 0xff) * 0x100 + (local_28 - 1 & 0xff) +
                                           param_2) -
                                 *(char *)((local_18 & 0xff) * 0x100 + (local_28 + 2 & 0xff) +
                                          param_2)));
    }
  }
  return;
}

