
undefined8 FUN_0002914b(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  undefined2 extraout_var;
  undefined4 extraout_ECX;
  int *piVar3;
  byte bVar4;
  undefined8 uVar5;
  
  uVar5 = CONCAT44(DAT_0003eeb4,param_1);
  while (piVar3 = (int *)((ulonglong)uVar5 >> 0x20), piVar3 != (int *)0x0) {
    if (*(int *)piVar3[9] + 0x2c == *piVar3) {
      FUN_000290e0(piVar3,piVar3,piVar3 + -2,piVar3[2]);
      iVar1 = piVar3[-1];
      bVar4 = 0;
      if (iVar1 == 0) {
        pcVar2 = (code *)swi(0x31);
        uVar5 = (*pcVar2)(CONCAT31((int3)(CONCAT22(extraout_var,0x500) >> 8),2));
      }
      else {
        pcVar2 = (code *)swi(0x21);
        uVar5 = (*pcVar2)(CONCAT22((short)((uint)iVar1 >> 0x10),CONCAT11(0x49,(char)iVar1)),
                          extraout_ECX);
        uVar5 = CONCAT44((int)((ulonglong)uVar5 >> 0x20),
                         ((int)uVar5 << 1 | (uint)bVar4) >> 1 | (uint)((bVar4 & 1) != 0) << 0x1f);
      }
    }
    else {
      uVar5 = CONCAT44(piVar3[2],*(int *)piVar3[9] + 0x2c);
    }
  }
  return CONCAT44(param_2,(int)uVar5);
}

