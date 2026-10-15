
undefined8 __regparm2 FUN_000259ff(void)

{
  short sVar1;
  code *pcVar2;
  byte bVar3;
  undefined1 uVar4;
  undefined4 in_ECX;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  byte bVar8;
  undefined4 unaff_retaddr;
  
  bVar8 = 0;
  pcVar2 = (code *)swi(0x10);
  (*pcVar2)(0x13);
  FUN_00025a7f();
  out(0x3d4,0x11);
  bVar3 = in(0x3d5);
  out(0x3d4,0x11);
  out(0x3d5,bVar3 & 0x7f);
  uVar6 = 0;
  do {
    sVar1 = *(short *)((int)&DAT_0003f8ea + uVar6);
    bVar3 = (byte)*(undefined2 *)((int)&DAT_0003f8ec + uVar6);
    uVar4 = (undefined1)((ushort)*(undefined2 *)((int)&DAT_0003f8ec + uVar6) >> 8);
    if (sVar1 == 0x3c0) {
      in(0x3da);
      out(0x3c0,bVar3 | 0x20);
      out(0x3c0,uVar4);
    }
    else if (sVar1 == 0x3c2) {
      out(0x3c2,uVar4);
    }
    else {
      out(sVar1,bVar3);
      out(sVar1 + 1,uVar4);
    }
    uVar6 = uVar6 + 4;
  } while (uVar6 < 0x61);
  puVar7 = (undefined4 *)&DAT_000a0000;
  for (iVar5 = 0x4000; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0;
    puVar7 = puVar7 + (uint)bVar8 * -2 + 1;
  }
  return CONCAT44(in_ECX,unaff_retaddr);
}

