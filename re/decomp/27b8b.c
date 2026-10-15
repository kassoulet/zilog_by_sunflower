
void FUN_00027b8b(uint param_1,undefined4 param_2,char *unaff_EBX)

{
  undefined2 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (99 < param_1) {
    uVar2 = (param_1 & 0xffff) / 100;
    param_1 = (param_1 & 0xffff) % 100;
  }
  FUN_00027ba2(uVar2);
  uVar1 = (undefined2)CONCAT31((int3)param_1,(char)(param_1 >> 8));
  if (9 < (byte)param_1) {
    uVar1 = CONCAT11((char)((ushort)param_1 % 10),(char)((ushort)param_1 / 10));
  }
  *unaff_EBX = (char)uVar1 + '0';
  unaff_EBX[1] = (char)((ushort)uVar1 >> 8) + '0';
  return;
}

