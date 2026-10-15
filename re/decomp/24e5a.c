
void FUN_00024e5a(byte param_1,byte param_2)

{
  byte bVar1;
  char *pcVar2;
  byte bVar3;
  uint uVar4;
  uint extraout_ECX;
  byte extraout_DH;
  char *pcVar5;
  
  uVar4 = (uint)param_1;
  while( true ) {
    pcVar5 = &DAT_000402e2;
    bVar3 = (byte)uVar4;
    for (pcVar2 = &DAT_000402d0; pcVar2 < &DAT_000402e2; pcVar2 = pcVar2 + 6) {
      if (*pcVar2 != '\x02') {
        bVar1 = pcVar2[1];
        uVar4 = (uint)CONCAT11(bVar1,(char)uVar4);
        if (bVar3 <= bVar1) {
          bVar3 = bVar1;
          pcVar5 = pcVar2;
        }
      }
    }
    if (pcVar5 == &DAT_000402e2) break;
    if ((byte)pcVar5[1] <= param_2) {
      FUN_00024e02(pcVar5 + 2);
      uVar4 = extraout_ECX;
      param_2 = extraout_DH;
    }
    *pcVar5 = '\x02';
  }
  return;
}

