
undefined8 __regparm3
FUN_000309e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_ES;
  undefined2 in_FS;
  undefined2 in_GS;
  byte in_CF;
  byte in_PF;
  byte in_AF;
  byte in_ZF;
  byte in_SF;
  byte in_TF;
  byte in_IF;
  byte in_OF;
  byte in_NT;
  undefined2 unaff_retaddr;
  undefined4 in_stack_00000030;
  undefined4 in_stack_00000038;
  
  *param_5 = param_1;
  *(ushort *)(param_5 + 9) =
       (ushort)(in_NT & 1) * 0x4000 | (ushort)(in_OF & 1) * 0x800 | (ushort)(in_IF & 1) * 0x200 |
       (ushort)(in_TF & 1) * 0x100 | (ushort)(in_SF & 1) * 0x80 | (ushort)(in_ZF & 1) * 0x40 |
       (ushort)(in_AF & 1) * 0x10 | (ushort)(in_PF & 1) * 4 | (ushort)(in_CF & 1);
  param_5[2] = param_3;
  param_5[3] = param_2;
  param_5[5] = unaff_ESI;
  param_5[6] = unaff_EDI;
  param_5[4] = unaff_EBP;
  *(undefined2 *)(param_5 + 7) = unaff_retaddr;
  param_5[1] = param_4;
  *(undefined2 *)((int)param_5 + 0x1e) = in_ES;
  *(undefined2 *)(param_5 + 8) = in_FS;
  *(undefined2 *)((int)param_5 + 0x22) = in_GS;
  return CONCAT44(in_stack_00000030,in_stack_00000038);
}

