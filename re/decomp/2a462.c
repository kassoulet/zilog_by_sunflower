
void FUN_0002a462(int param_1,int *param_2,undefined4 unaff_EBX)

{
  byte bVar1;
  undefined6 *puVar2;
  undefined4 *puVar3;
  
  bVar1 = *(byte *)(param_1 + 0x10);
  if ((bVar1 & 1) != 0) {
    if ((bVar1 & 4) == 0) {
      if ((bVar1 & 8) == 0) {
        puVar3 = (undefined4 *)*param_2;
        *param_2 = (int)(puVar3 + 1);
        puVar3 = (undefined4 *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)*param_2;
        *param_2 = (int)(puVar3 + 1);
        puVar3 = (undefined4 *)*puVar3;
      }
    }
    else {
      puVar2 = (undefined6 *)*param_2;
      *param_2 = (int)(puVar2 + 1);
      puVar3 = (undefined4 *)*puVar2;
    }
    if ((*(byte *)(param_1 + 0x10) & 0x10) != 0) {
      *(short *)puVar3 = (short)unaff_EBX;
      return;
    }
    *puVar3 = unaff_EBX;
  }
  return;
}

