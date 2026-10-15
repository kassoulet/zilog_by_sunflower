
void func_24e0e(byte param_1)

{
  char *pcVar1;
  uint uVar2;
  uint extraout_EDX;
  char *pcVar3;
  
  uVar2 = (uint)param_1 << 8;
  while( true ) {
    pcVar3 = &DAT_000402d0;
    uVar2 = uVar2 >> 8 & 0xff;
    for (pcVar1 = (char *)0x40282; pcVar1 < &DAT_000402d0; pcVar1 = pcVar1 + 6) {
      if ((*pcVar1 != '\x02') && ((byte)pcVar1[1] <= (byte)uVar2)) {
        uVar2 = (uint)(byte)pcVar1[1];
        pcVar3 = pcVar1;
      }
    }
    if (pcVar3 == &DAT_000402d0) break;
    FUN_00024e02(pcVar3 + 2);
    *pcVar3 = '\x02';
    uVar2 = extraout_EDX;
  }
  return;
}

