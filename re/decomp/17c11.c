
void FUN_00017c11(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = FUN_00017846(0x60);
  if (iVar2 == 0x39) {
    uVar1 = *(undefined4 *)(DAT_00040304 + 8);
    *(undefined4 *)(DAT_00040304 + 8) = param_1;
    FUN_000206b4();
    FUN_00017641(&DAT_00040578,0,0,DAT_00040354);
    FUN_000206b4();
    FUN_00017641(&DAT_00040578,0,10,DAT_00040354);
    FUN_000206b4();
    FUN_00017641(&DAT_00040578,0,0x14,DAT_00040354);
    *(undefined4 *)(DAT_00040304 + 8) = uVar1;
  }
  if (DAT_00040530 == 0) {
    if (DAT_0004053c == 0xc) {
      FUN_00025b01(param_1);
    }
    if (DAT_0004053c == 8) {
      FUN_0002587b(param_1);
    }
  }
  else if (DAT_00040534 == 0) {
    if (DAT_0004053c == 0x20) {
      FUN_000254ba(param_1,0);
    }
    else if (DAT_0004053c == 0x18) {
      FUN_000257bb(param_1);
    }
    else if (DAT_0004053c == 0x10) {
      FUN_00025649(param_1);
    }
    else if (DAT_0004053c == 0xf) {
      FUN_0002570c(param_1);
    }
    else if (DAT_0004053c == 0xb) {
      FUN_000255b7(param_1);
    }
  }
  else if (DAT_0004053c == 0x20) {
    FUN_0001c48f(DAT_00040534,param_1,&/*c*/20.0);
  }
  else if (DAT_0004053c == 0x18) {
    FUN_00025799(param_1,DAT_00040534);
  }
  else if (DAT_0004053c == 0x10) {
    FUN_0002554c(param_1,DAT_00040534);
  }
  else if (DAT_0004053c == 0xf) {
    FUN_000256d4(param_1,DAT_00040534);
  }
  else if (DAT_0004053c == 0xb) {
    FUN_00025582(param_1,DAT_00040534);
  }
  *(int *)(DAT_00040304 + 0x10) = *(int *)(DAT_00040304 + 0x10) + 1;
  return;
}

