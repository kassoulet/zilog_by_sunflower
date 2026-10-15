
byte * __regparm3 FUN_0002e7ea(void)

{
  byte bVar1;
  code *pcVar2;
  undefined4 uVar3;
  byte *pbVar4;
  undefined2 uVar6;
  byte *pbVar5;
  char cVar7;
  uint uVar8;
  int iVar9;
  uint unaff_EBX;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint uVar13;
  byte bVar14;
  byte bVar15;
  undefined8 uVar16;
  byte *local_a8;
  byte local_a4 [144];
  int local_14;
  
  bVar15 = 0;
  uVar16 = FUN_0002e00a();
  if ((int)uVar16 == 0) {
    unaff_EBX = 0x90;
    uVar16 = FUN_000243a3(0x90);
    local_14 = (int)uVar16;
    if (local_14 == 0) {
      uVar3 = 5;
      goto LAB_0002e863;
    }
  }
  pbVar4 = (byte *)((ulonglong)uVar16 >> 0x20);
  local_a8 = (byte *)uVar16;
  if ((pbVar4 == (byte *)0x0) || (*pbVar4 == 0)) {
    pbVar4 = (byte *)FUN_0002eab9(local_a8,unaff_EBX);
    return pbVar4;
  }
  if (2 < unaff_EBX) {
    uVar13 = unaff_EBX - 2;
    if ((((&DAT_0003fda0)[(byte)(*pbVar4 + 1)] & 0xc0) == 0) || (pbVar4[1] != 0x3a)) {
      pcVar2 = (code *)swi(0x21);
      uVar16 = (*pcVar2)();
      pbVar12 = (byte *)((ulonglong)uVar16 >> 0x20);
      cVar7 = (char)uVar16 + '\x01';
      uVar6 = (undefined2)((ulonglong)uVar16 >> 0x10);
      local_a8[1] = 0x3a;
      *local_a8 = (char)uVar16 + 0x41;
    }
    else {
      uVar16 = FUN_00028505(*pbVar4);
      pbVar12 = (byte *)((ulonglong)uVar16 >> 0x20);
      cVar7 = (char)uVar16 + -0x60;
      uVar6 = (undefined2)((ulonglong)uVar16 >> 0x10);
      *local_a8 = *pbVar12;
      pbVar4 = pbVar12 + 2;
      local_a8[1] = pbVar12[1];
    }
    bVar1 = *pbVar4;
    pbVar10 = local_a8 + 2;
    pbVar5 = local_a8;
    if ((bVar1 == 0x2f) || (bVar14 = bVar1 < 0x5c, bVar1 == 0x5c)) {
      uVar8 = 0xffffffff;
      pbVar12 = pbVar4;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        bVar1 = *pbVar12;
        pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
      } while (bVar1 != 0);
      if (~uVar8 <= uVar13) {
        do {
          bVar15 = *pbVar4;
          *pbVar10 = bVar15;
          if (bVar15 == 0) break;
          bVar15 = pbVar4[1];
          pbVar4 = pbVar4 + 2;
          pbVar10[1] = bVar15;
          pbVar10 = pbVar10 + 2;
        } while (bVar15 != 0);
        goto LAB_0002eaa4;
      }
    }
    else {
      pcVar2 = (code *)swi(0x21);
      (*pcVar2)(CONCAT22(uVar6,CONCAT11(0x47,bVar1)),CONCAT31((int3)((uint)pbVar12 >> 8),cVar7));
      if ((bVar14 & 1) != 0) {
        FUN_00027561(local_14);
        uVar3 = 1;
        goto LAB_0002e863;
      }
      uVar8 = 0xffffffff;
      pbVar12 = local_a4;
      do {
        if (uVar8 == 0) break;
        uVar8 = uVar8 - 1;
        bVar1 = *pbVar12;
        pbVar12 = pbVar12 + (uint)bVar15 * -2 + 1;
      } while (bVar1 != 0);
      iVar9 = ~uVar8 - 1;
      if (local_a4[0] != 0x5c) {
        if (uVar13 < 2) goto LAB_0002e852;
        uVar13 = unaff_EBX - 3;
        *pbVar10 = 0x5c;
        pbVar10 = local_a8 + 3;
      }
      if (~uVar8 <= uVar13) {
        uVar13 = uVar13 - iVar9;
        pbVar12 = local_a4;
        pbVar11 = pbVar10 + iVar9;
        do {
          bVar15 = *pbVar12;
          *pbVar10 = bVar15;
          if (bVar15 == 0) break;
          bVar15 = pbVar12[1];
          pbVar12 = pbVar12 + 2;
          pbVar10[1] = bVar15;
          pbVar10 = pbVar10 + 2;
        } while (bVar15 != 0);
        if (pbVar11[-1] != 0x5c) {
          if (uVar13 < 2) goto LAB_0002e852;
          *pbVar11 = 0x5c;
          pbVar11 = pbVar11 + 1;
          uVar13 = uVar13 - 1;
        }
LAB_0002e97f:
        while (*pbVar4 != 0) {
          if (*pbVar4 == 0x2e) {
            bVar1 = pbVar4[1];
            bVar15 = 0x2e;
            if ((bVar1 != 0x2f) && (bVar1 != 0x5c)) {
              if (bVar1 != 0) {
                if (bVar1 == 0x2e) {
                  pbVar12 = pbVar4 + 2;
                  if ((*pbVar12 == 0x2f) || (*pbVar12 == 0x5c)) {
                    pbVar12 = pbVar4 + 3;
                  }
                  if ((pbVar11[-1] == 0x2f) || (pbVar11[-1] == 0x5c)) {
                    for (pbVar11 = pbVar11 + -2; local_a8 <= pbVar11; pbVar11 = pbVar11 + -1) {
                      bVar15 = *pbVar11;
                      if ((bVar15 == 0x2f) || (bVar15 == 0x5c)) goto LAB_0002ea39;
                      if (bVar15 == 0x3a) goto code_r0x0002ea30;
                    }
                  }
                  FUN_00027561(local_14);
                  return (byte *)0x0;
                }
                if (1 < uVar13) goto LAB_0002e9ad;
                goto LAB_0002e852;
              }
              break;
            }
            if ((pbVar11[-1] != 0x2f) && (pbVar11[-1] != 0x5c)) {
              *pbVar11 = 0x5c;
              pbVar11 = pbVar11 + 1;
            }
            pbVar4 = pbVar4 + 2;
          }
          else {
            if (uVar13 < 2) goto LAB_0002e852;
            bVar15 = *pbVar4;
LAB_0002e9ad:
            *pbVar11 = bVar15;
            pbVar11 = pbVar11 + 1;
            pbVar4 = pbVar4 + 1;
            uVar13 = uVar13 - 1;
          }
        }
        *pbVar11 = 0;
LAB_0002eaa4:
        for (; *pbVar5 != 0; pbVar5 = pbVar5 + 1) {
          if (*pbVar5 == 0x2f) {
            *pbVar5 = 0x5c;
          }
        }
        return local_a8;
      }
    }
  }
LAB_0002e852:
  FUN_00027561(local_14);
  uVar3 = 0xe;
LAB_0002e863:
  FUN_000284cf(uVar3);
  return (byte *)0x0;
code_r0x0002ea30:
  pbVar11 = pbVar11 + 1;
  *pbVar11 = 0x5c;
LAB_0002ea39:
  pbVar11 = pbVar11 + 1;
  *pbVar11 = 0;
  pbVar4 = pbVar12;
  goto LAB_0002e97f;
}

