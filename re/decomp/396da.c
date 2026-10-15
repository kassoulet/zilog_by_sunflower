
byte FUN_000396da(void)

{
  byte bVar1;
  
  out(DAT_00036456 + 4,0xe);
  bVar1 = in(DAT_00036456 + 5);
  out(DAT_00036456 + 4,0xe);
  out(DAT_00036456 + 5,bVar1 & 0xfd);
  return bVar1 & 0xfd;
}

