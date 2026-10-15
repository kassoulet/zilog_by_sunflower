
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00032858(void)

{
  undefined1 uVar1;
  int unaff_EBP;
  undefined1 uVar2;
  
  DAT_0003152f = '\0';
  if (DAT_00031521 != 0) {
    (&DAT_00031530)[unaff_EBP] = (char)DAT_00031521;
    FUN_0003417e();
    DAT_0003152f = '\x01';
    (&DAT_00031db0)[unaff_EBP] = 0;
    if ((_DAT_000314fa & 0x80) == 0) {
      (&DAT_00031d70)[unaff_EBP] = 0;
    }
    if ((byte)(&DAT_000319f0)[unaff_EBP] < 4) {
      (&DAT_00031ab0)[unaff_EBP] = 0;
    }
    if ((byte)(&DAT_00031af0)[unaff_EBP] < 4) {
      (&DAT_00031bb0)[unaff_EBP] = 0;
    }
  }
  if (DAT_00031523 == 0xff) {
    FUN_0003437a();
  }
  else if (DAT_00031523 == 0xfe) {
    FUN_0003435a();
  }
  else if (DAT_00031523 == 0xfd) {
    FUN_00034365();
  }
  else if ((((DAT_00031523 != 0) && (DAT_0003152b != 3)) && (DAT_0003152b != 0x3b)) &&
          (DAT_00031527 != 9)) {
    (&DAT_00031570)[unaff_EBP] = (char)DAT_00031523;
    FUN_00032985((&DAT_00031530)[unaff_EBP]);
  }
  uVar2 = false;
  if (DAT_0003152f != '\0') {
    uVar1 = FUN_00034247();
    if (!(bool)uVar2) {
      (&DAT_00031630)[unaff_EBP] = uVar1;
      FUN_0003432a();
      uVar1 = FUN_0003425a();
      if (!(bool)uVar2) {
        (&DAT_000316f0)[unaff_EBP] = uVar1;
        FUN_00034348();
      }
    }
  }
  if (DAT_00031525 != 0) {
    DAT_00031525 = DAT_00031525 + -0x10;
    (&DAT_00031630)[unaff_EBP] = (char)DAT_00031525;
    FUN_0003432a();
  }
  return;
}

