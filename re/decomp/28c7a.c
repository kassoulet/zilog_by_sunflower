
void FUN_00028c7a(undefined4 param_1,undefined4 param_2,undefined4 unaff_EBX,undefined4 param_4)

{
  undefined4 uVar1;
  byte bVar2;
  int extraout_EDX;
  undefined4 *puVar3;
  undefined8 uVar4;
  
  FUN_000288da(param_1,param_1,unaff_EBX,param_4,param_2,param_4,unaff_EBX);
  if (*(int *)(extraout_EDX + 0x14) == 0) {
    if ((*(byte *)(extraout_EDX + 0xd) & 2) == 0) {
      if ((*(byte *)(extraout_EDX + 0xd) & 4) == 0) {
        *(undefined4 *)(extraout_EDX + 0x14) = 0x1000;
      }
      else {
        *(undefined4 *)(extraout_EDX + 0x14) = 1;
      }
    }
    else {
      *(undefined4 *)(extraout_EDX + 0x14) = 0x86;
    }
  }
  uVar4 = FUN_000243a3(*(undefined4 *)(extraout_EDX + 0x14));
  puVar3 = (undefined4 *)((ulonglong)uVar4 >> 0x20);
  *(int *)(puVar3[2] + 8) = (int)uVar4;
  if (*(int *)(puVar3[2] + 8) == 0) {
    bVar2 = *(byte *)((int)puVar3 + 0xd) & 0xf8;
    *(byte *)((int)puVar3 + 0xd) = bVar2;
    *(byte *)((int)puVar3 + 0xd) = bVar2 | 4;
    *(undefined4 **)(puVar3[2] + 8) = puVar3 + 6;
    puVar3[5] = 1;
  }
  else {
    *(byte *)(puVar3 + 3) = *(byte *)(puVar3 + 3) | 8;
  }
  uVar1 = *(undefined4 *)(puVar3[2] + 8);
  puVar3[1] = 0;
  *puVar3 = uVar1;
  return;
}

