
void FUN_00027ba2(ushort param_1,undefined4 param_2,char *unaff_EBX)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = (byte)param_1;
  cVar1 = (char)(param_1 >> 8);
  if (9 < bVar2) {
    cVar1 = (char)(param_1 / 10);
    bVar2 = (byte)(param_1 % 10);
  }
  *unaff_EBX = cVar1 + '0';
  unaff_EBX[1] = bVar2 + 0x30;
  return;
}

