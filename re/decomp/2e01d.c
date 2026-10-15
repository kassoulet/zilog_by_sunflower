
uint FUN_0002e01d(undefined1 *param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined2 extraout_var;
  ushort in_SS;
  byte bVar4;
  
  if ((param_1 < &stack0x00000000) &&
     (uVar3 = -((int)param_1 - (int)&stack0x00000000),
     DAT_0003ed24 <= uVar3 && -DAT_0003ed24 != (int)param_1 - (int)&stack0x00000000)) {
    return uVar3;
  }
  if (in_SS != DAT_0003fcf4) {
    return (uint)in_SS;
  }
  uVar2 = FUN_0002e1d0(s_Stack_Overflow__0003fcf6,1);
  uVar3 = (uint)CONCAT11(DAT_0003ed42,uVar2);
  DAT_0003fd90 = 0x8000;
  if ((DAT_0003ed42 < 2) || (8 < DAT_0003ed42)) {
    uVar3 = FUN_0002f6d8();
    if (uVar3 == 1) {
      bVar4 = 0;
      pcVar1 = (code *)swi(0x31);
      (*pcVar1)(0x600,0,0x3b08,CONCAT22(extraout_var,2));
      uVar3 = (uint)(ushort)-(ushort)bVar4;
    }
  }
  return uVar3;
}

