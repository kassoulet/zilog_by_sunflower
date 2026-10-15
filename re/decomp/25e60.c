
void __regparm3 FUN_00025e60(undefined1 *param_1,uint param_2,uint param_3)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  undefined6 uVar3;
  
  if (param_3 != 0) {
    do {
      if (((uint)param_1 & 3) == 0) break;
      *param_1 = (char)param_2;
      param_1 = param_1 + 1;
      param_2 = param_2 >> 8 | param_2 << 0x18;
      param_3 = param_3 - 1;
    } while (param_3 != 0);
    uVar3 = FUN_00025e97();
    puVar1 = (undefined1 *)uVar3;
    param_3 = param_3 & 3;
    if (param_3 != 0) {
      uVar2 = (undefined1)((uint6)uVar3 >> 0x20);
      *puVar1 = uVar2;
      if ((param_3 != 1) && (puVar1[1] = (char)((uint6)uVar3 >> 0x28), param_3 != 2)) {
        puVar1[2] = uVar2;
      }
    }
  }
  return;
}

