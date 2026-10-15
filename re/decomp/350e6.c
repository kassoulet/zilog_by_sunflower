
void FUN_000350e6(int param_1)

{
  code *pcVar1;
  undefined1 uVar2;
  char cVar4;
  uint uVar3;
  undefined2 uVar5;
  undefined *puVar6;
  
  if (param_1 == 0) {
    uVar3 = 0;
    puVar6 = &DAT_00034e14;
  }
  else {
    uVar3 = param_1 - 1;
    cVar4 = (char)(uVar3 >> 8);
    uVar2 = (undefined1)uVar3;
    uVar5 = (undefined2)(uVar3 >> 0x10);
    if (cVar4 == '\0') {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(CONCAT22(uVar5,CONCAT11(9,uVar2)),&DAT_00034e36);
      uVar3 = uVar3 & 0xff;
      if (uVar3 < 4) {
        puVar6 = *(undefined **)(&DAT_00034e45 + uVar3 * 4);
        goto LAB_00035212;
      }
    }
    else if (cVar4 == '\x01') {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(CONCAT22(uVar5,CONCAT11(9,uVar2)),&DAT_00034ea5);
      uVar3 = uVar3 & 0xff;
      if (uVar3 < 2) {
        puVar6 = (&PTR_DAT_00034eb3)[uVar3];
        goto LAB_00035212;
      }
    }
    else if (cVar4 == '\x02') {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(CONCAT22(uVar5,CONCAT11(9,uVar2)),&DAT_00034ef8);
      uVar3 = uVar3 & 0xff;
      if (uVar3 < 7) {
        puVar6 = *(undefined **)(&DAT_00034f05 + uVar3 * 4);
        goto LAB_00035212;
      }
    }
    else if (cVar4 == '\x03') {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(CONCAT22(uVar5,CONCAT11(9,uVar2)),&DAT_00034f82);
      uVar3 = uVar3 & 0xff;
      if (uVar3 < 3) {
        puVar6 = *(undefined **)(&DAT_00034f97 + uVar3 * 4);
        goto LAB_00035212;
      }
    }
    else if (cVar4 == '\x04') {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(CONCAT22(uVar5,CONCAT11(9,uVar2)),&DAT_00034ff4);
      uVar3 = uVar3 & 0xff;
      puVar6 = PTR_DAT_0003500a;
      if (uVar3 == 0) goto LAB_00035212;
    }
    else if (cVar4 == '\x05') {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(CONCAT22(uVar5,CONCAT11(9,uVar2)),&DAT_00035026);
      uVar3 = uVar3 & 0xff;
      if (uVar3 < 3) {
        puVar6 = *(undefined **)(&DAT_00035039 + uVar3 * 4);
        goto LAB_00035212;
      }
    }
    else if (cVar4 == '\x06') {
      pcVar1 = (code *)swi(0x21);
      (*pcVar1)(CONCAT22(uVar5,CONCAT11(9,uVar2)),&DAT_0003508e);
      uVar3 = uVar3 & 0xff;
      if (uVar3 < 3) {
        puVar6 = *(undefined **)(&DAT_000350a2 + uVar3 * 4);
        goto LAB_00035212;
      }
    }
    puVar6 = &DAT_00034e26;
  }
LAB_00035212:
  pcVar1 = (code *)swi(0x21);
  (*pcVar1)(CONCAT11(9,(char)uVar3),puVar6);
  return;
}

