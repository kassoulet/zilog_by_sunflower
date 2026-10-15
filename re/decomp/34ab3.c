
void FUN_00034ab3(undefined2 param_1,undefined4 param_2,int unaff_EBX)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  undefined2 *unaff_EDI;
  
  uVar2 = (undefined1)((ushort)param_1 >> 8);
  *unaff_EDI = CONCAT11(uVar2,0xba);
  puVar1 = unaff_EDI + 1;
  for (; unaff_EBX != 0; unaff_EBX = unaff_EBX + -1) {
    *puVar1 = CONCAT11(uVar2,0x20);
    puVar1 = puVar1 + 1;
  }
  *puVar1 = CONCAT11(uVar2,0xba);
  FUN_00034aa7();
  return;
}

