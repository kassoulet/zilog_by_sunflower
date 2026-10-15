
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001d6a4(uint *param_1,undefined4 param_2,int unaff_EBX,int *param_4)

{
  byte bVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int *piVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined3 uVar9;
  int iVar10;
  int iVar11;
  undefined1 *puVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined2 uVar18;
  undefined1 *puVar17;
  short sVar19;
  short sVar20;
  uint uVar21;
  uint uVar22;
  uint *puVar23;
  uint *puVar24;
  bool bVar25;
  bool bVar26;
  
  _DAT_0003ee24 = 0x19;
  DAT_0003ee2c = unaff_EBX;
  DAT_0003ee30 = param_4;
  DAT_0003ee34 = param_1;
LAB_0001d6c0:
  do {
    _DAT_0003ee28 = 0x28;
    do {
      while( true ) {
        iVar6 = (DAT_0003ee30[3] - *DAT_0003ee30) * 0x100;
        iVar7 = iVar6 >> 0xb;
        iVar13 = (DAT_0003ee30[4] - DAT_0003ee30[1]) * 0x100;
        iVar14 = iVar13 >> 0xb;
        DAT_0003edd4 = DAT_0003ee30[5] - DAT_0003ee30[2] >> 3;
        uRam0001d86f = iVar7 << 0x10;
        uRam0001d87b = iVar14 << 0x10;
        uRam0001d891 = DAT_0003edd4 << 0x10;
        cRam0001d897 = (char)((uint)DAT_0003edd4 >> 0x10);
        iVar8 = (DAT_0003ee30[0x7b] - *DAT_0003ee30) * 0x100;
        iVar10 = (DAT_0003ee30[0x7c] - DAT_0003ee30[1]) * 0x100;
        iVar15 = DAT_0003ee30[0x7d] - DAT_0003ee30[2] >> 3;
        _DAT_0003eddc = (undefined2)(iVar8 >> 0xb);
        cRam0003eddf = (char)((uint)iVar8 >> 0x18);
        DAT_0003edde = cRam0003eddf >> 3;
        cRam0003eddf = cRam0003eddf >> 7;
        _DAT_0003ede4 = (undefined2)(iVar10 >> 0xb);
        cRam0003ede7 = (char)((uint)iVar10 >> 0x18);
        DAT_0003ede6 = cRam0003ede7 >> 3;
        cRam0003ede7 = cRam0003ede7 >> 7;
        _DAT_0003edec = (undefined2)iVar15;
        DAT_0003edee = (char)((uint)iVar15 >> 0x10);
        cRam0003edef = (char)(DAT_0003ee30[0x7d] - DAT_0003ee30[2] >> 0x1b);
        iVar8 = ((DAT_0003ee30[0x7e] - DAT_0003ee30[0x7b]) * 0x100 >> 0xb) - iVar7;
        iVar15 = ((DAT_0003ee30[0x7f] - DAT_0003ee30[0x7c]) * 0x100 >> 0xb) - iVar14;
        iVar16 = (DAT_0003ee30[0x80] - DAT_0003ee30[0x7d] >> 3) - DAT_0003edd4;
        iVar10 = iVar8 >> 3;
        iVar11 = iVar15 >> 3;
        DAT_0003edf2._2_2_ = (undefined2)iVar10;
        DAT_0003edf6 = (char)((uint)iVar10 >> 0x10);
        cRam0003edf7 = (char)(iVar8 >> 0x1b);
        DAT_0003edfa._2_2_ = (undefined2)iVar11;
        DAT_0003edfe = (char)((uint)iVar11 >> 0x10);
        cRam0003edff = (char)(iVar15 >> 0x1b);
        DAT_0003ee02._2_2_ = (undefined2)(iVar16 >> 3);
        DAT_0003ee06._0_2_ = (short)(iVar16 >> 0x13);
        bVar1 = *(byte *)((int)DAT_0003ee30 + 0x202);
        iVar10 = CONCAT22((ushort)(DAT_0003ee2c + (uint)*(byte *)((int)DAT_0003ee30 + 3) * 0x40000
                                  >> 0x12),
                          CONCAT11(*(undefined1 *)((int)DAT_0003ee30 + 6),
                                   *(undefined1 *)((int)DAT_0003ee30 + 2)));
        iVar8 = CONCAT22((short)((uint)DAT_000402f4 >> 0x10),
                         CONCAT11(*(undefined1 *)((int)DAT_0003ee30 + 10),bVar1));
        uVar22 = *(uint *)((int)DAT_0003ee30 + 6);
        DAT_0003edc4._2_1_ = (char)(iVar6 >> 0x1b);
        DAT_0003edcc._2_1_ = (char)(iVar13 >> 0x1b);
        puVar12 = (undefined1 *)
                  CONCAT22((short)((uint)*(undefined4 *)((int)DAT_0003ee30 + -2) >> 0x10),
                           CONCAT11(DAT_0003edcc._2_1_,DAT_0003edc4._2_1_));
        uVar18 = (undefined2)((uint)*(undefined4 *)((int)DAT_0003ee30 + 2) >> 0x10);
        uRam0001d989 = uRam0001d86f;
        uRam0001d991 = uRam0001d87b;
        DAT_0003edc4 = iVar7;
        DAT_0003edcc = iVar14;
        if (((*(byte *)((int)DAT_0003ee30 + 10) == 0 && *(byte *)((int)DAT_0003ee30 + 0x16) == 0) &&
            *(byte *)((int)DAT_0003ee30 + 0x1f6) == 0) && bVar1 == 0) break;
        if ((*(byte *)((int)DAT_0003ee30 + 10) & *(byte *)((int)DAT_0003ee30 + 0x16) &
             *(byte *)((int)DAT_0003ee30 + 0x1f6) & bVar1) == 0xff) {
          sVar19 = 8;
          puVar23 = DAT_0003ee34;
          do {
            sVar20 = 8;
            do {
              puVar24 = puVar23;
              *puVar24 = 0xffffff;
              puVar5 = DAT_0003ee34;
              piVar4 = DAT_0003ee30;
              sVar20 = sVar20 + -1;
              puVar23 = puVar24 + 1;
            } while (sVar20 != 0);
            puVar23 = puVar24 + 0x139;
            sVar19 = sVar19 + -1;
          } while (sVar19 != 0);
          DAT_0003ee30 = DAT_0003ee30 + 3;
          DAT_0003ee34 = DAT_0003ee34 + 8;
          _DAT_0003ee28 = _DAT_0003ee28 + -1;
          if (_DAT_0003ee28 == 0) {
            DAT_0003ee30 = piVar4 + 6;
            DAT_0003ee34 = puVar5 + 0x8c8;
            _DAT_0003ee24 = _DAT_0003ee24 + -1;
            if (_DAT_0003ee24 == 0) {
              return;
            }
            goto LAB_0001d6c0;
          }
        }
        else {
          puVar17 = (undefined1 *)CONCAT22(uVar18,8);
          puVar23 = DAT_0003ee34;
          do {
            DAT_0003ee06._2_2_ = (undefined2)iVar10;
            uRam0003ee0a = (undefined2)((uint)iVar10 >> 0x10);
            uVar21 = CONCAT22((short)(uVar22 >> 0x10),8);
            DAT_0003ee0c = puVar12;
            DAT_0003ee10 = puVar17;
            DAT_0003ee14 = iVar8;
            DAT_0003ee18 = uVar22;
            do {
              puVar24 = puVar23;
              uVar3 = *(undefined4 *)(iVar10 * 4);
              bVar25 = (undefined1 *)0xeeeeeeee < puVar12;
              puVar12 = &DAT_11111111 + (int)puVar12;
              uVar9 = (undefined3)((uint)iVar8 >> 8);
              bVar26 = (undefined1 *)0xeeeeeeee < puVar17;
              puVar17 = &DAT_11111111 + (int)puVar17;
              iVar10 = CONCAT22((short)((uint)iVar10 >> 0x10),
                                CONCAT11((char)((uint)iVar10 >> 8) + (char)((uint)puVar12 >> 8) +
                                         bVar26,(char)iVar10 + (char)puVar12 + bVar25));
              uVar2 = *(undefined1 *)CONCAT31(uVar9,(char)((uint)uVar3 >> 8));
              iVar8 = (uint)CONCAT21((short)((uint)iVar8 >> 0x10),
                                     (char)((uint)iVar8 >> 8) + '\x11' + (0xeeeeeeee < uVar21)) << 8
              ;
              *puVar24 = CONCAT22((ushort)((uint)uVar3 >> 0x18),
                                  CONCAT11(*(undefined1 *)
                                            CONCAT31(uVar9,(char)((uint)uVar3 >> 0x10)),uVar2)) << 8
                         | CONCAT11(uVar2,*(undefined1 *)CONCAT31(uVar9,(char)uVar3)) & 0xff;
              puVar5 = DAT_0003ee34;
              piVar4 = DAT_0003ee30;
              sVar19 = (short)(&DAT_11111111 + uVar21) + -1;
              uVar21 = CONCAT22((short)((uint)(&DAT_11111111 + uVar21) >> 0x10),sVar19);
              puVar23 = puVar24 + 1;
            } while (sVar19 != 0);
            puVar23 = puVar24 + 0x139;
            bVar25 = CARRY4(uRam0001d86f,CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2));
            uRam0001d86f = uRam0001d86f + CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2);
            bVar26 = CARRY4(uRam0001d87b,CONCAT22(DAT_0003edfa._2_2_,(undefined2)DAT_0003edfa));
            uRam0001d87b = uRam0001d87b + CONCAT22(DAT_0003edfa._2_2_,(undefined2)DAT_0003edfa);
            uVar22 = CONCAT22((short)((uint)DAT_0003ee0c >> 0x10),
                              CONCAT11((char)((uint)DAT_0003ee0c >> 8) + DAT_0003edfe + bVar26,
                                       (char)DAT_0003ee0c + DAT_0003edf6 + bVar25));
            bVar25 = CARRY4(uRam0001d891,CONCAT22(DAT_0003ee02._2_2_,(undefined2)DAT_0003ee02));
            uRam0001d891 = uRam0001d891 + CONCAT22(DAT_0003ee02._2_2_,(undefined2)DAT_0003ee02);
            cRam0001d897 = cRam0001d897 + (char)(short)DAT_0003ee06 + bVar25;
            puVar12 = (undefined1 *)(uVar22 + CONCAT22(_DAT_0003eddc,_DAT_0003edda));
            iVar10 = CONCAT22(uRam0003ee0a,
                              CONCAT11((char)((ushort)DAT_0003ee06._2_2_ >> 8) + DAT_0003ede6 +
                                       CARRY4((uint)DAT_0003ee10,
                                              CONCAT22(_DAT_0003ede4,_DAT_0003ede2)),
                                       (char)DAT_0003ee06._2_2_ + DAT_0003edde +
                                       CARRY4(uVar22,CONCAT22(_DAT_0003eddc,_DAT_0003edda))));
            uVar22 = DAT_0003ee18 + CONCAT22(_DAT_0003edec,_DAT_0003edea);
            iVar8 = CONCAT22((short)((uint)DAT_0003ee14 >> 0x10),
                             CONCAT11((char)((uint)DAT_0003ee14 >> 8) + DAT_0003edee +
                                      CARRY4(DAT_0003ee18,CONCAT22(_DAT_0003edec,_DAT_0003edea)),
                                      (char)DAT_0003ee14));
            sVar19 = (short)(DAT_0003ee10 + CONCAT22(_DAT_0003ede4,_DAT_0003ede2)) + -1;
            puVar17 = (undefined1 *)
                      CONCAT22((short)((uint)(DAT_0003ee10 + CONCAT22(_DAT_0003ede4,_DAT_0003ede2))
                                      >> 0x10),sVar19);
          } while (sVar19 != 0);
          DAT_0003ee30 = DAT_0003ee30 + 3;
          DAT_0003ee34 = DAT_0003ee34 + 8;
          _DAT_0003ee28 = _DAT_0003ee28 + -1;
          if (_DAT_0003ee28 == 0) {
            DAT_0003ee30 = piVar4 + 6;
            DAT_0003ee34 = puVar5 + 0x8c8;
            _DAT_0003ee24 = _DAT_0003ee24 + -1;
            if (_DAT_0003ee24 == 0) {
              return;
            }
            goto LAB_0001d6c0;
          }
        }
      }
      puVar17 = (undefined1 *)CONCAT22(uVar18,8);
      puVar23 = DAT_0003ee34;
      do {
        DAT_0003ee06._2_2_ = (undefined2)iVar10;
        uRam0003ee0a = (undefined2)((uint)iVar10 >> 0x10);
        sVar19 = 8;
        DAT_0003ee0c = puVar12;
        DAT_0003ee10 = puVar17;
        do {
          puVar24 = puVar23;
          puVar23 = (uint *)(iVar10 * 4);
          bVar25 = (undefined1 *)0xeeeeeeee < puVar12;
          puVar12 = &DAT_11111111 + (int)puVar12;
          bVar26 = (undefined1 *)0xeeeeeeee < puVar17;
          puVar17 = &DAT_11111111 + (int)puVar17;
          iVar10 = CONCAT22((short)((uint)iVar10 >> 0x10),
                            CONCAT11((char)((uint)iVar10 >> 8) + (char)((uint)puVar12 >> 8) + bVar26
                                     ,(char)iVar10 + (char)puVar12 + bVar25));
          *puVar24 = *puVar23;
          puVar5 = DAT_0003ee34;
          piVar4 = DAT_0003ee30;
          sVar19 = sVar19 + -1;
          puVar23 = puVar24 + 1;
        } while (sVar19 != 0);
        puVar23 = puVar24 + 0x139;
        bVar25 = CARRY4(uRam0001d989,CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2));
        uRam0001d989 = uRam0001d989 + CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2);
        bVar26 = CARRY4(uRam0001d991,CONCAT22(DAT_0003edfa._2_2_,(undefined2)DAT_0003edfa));
        uRam0001d991 = uRam0001d991 + CONCAT22(DAT_0003edfa._2_2_,(undefined2)DAT_0003edfa);
        uVar22 = CONCAT22((short)((uint)DAT_0003ee0c >> 0x10),
                          CONCAT11((char)((uint)DAT_0003ee0c >> 8) + DAT_0003edfe + bVar26,
                                   (char)DAT_0003ee0c + DAT_0003edf6 + bVar25));
        puVar12 = (undefined1 *)(uVar22 + CONCAT22(_DAT_0003eddc,_DAT_0003edda));
        iVar10 = CONCAT22(uRam0003ee0a,
                          CONCAT11((char)((ushort)DAT_0003ee06._2_2_ >> 8) + DAT_0003ede6 +
                                   CARRY4((uint)DAT_0003ee10,CONCAT22(_DAT_0003ede4,_DAT_0003ede2)),
                                   (char)DAT_0003ee06._2_2_ + DAT_0003edde +
                                   CARRY4(uVar22,CONCAT22(_DAT_0003eddc,_DAT_0003edda))));
        sVar19 = (short)(DAT_0003ee10 + CONCAT22(_DAT_0003ede4,_DAT_0003ede2)) + -1;
        puVar17 = (undefined1 *)
                  CONCAT22((short)((uint)(DAT_0003ee10 + CONCAT22(_DAT_0003ede4,_DAT_0003ede2)) >>
                                  0x10),sVar19);
      } while (sVar19 != 0);
      DAT_0003ee30 = DAT_0003ee30 + 3;
      DAT_0003ee34 = DAT_0003ee34 + 8;
      _DAT_0003ee28 = _DAT_0003ee28 + -1;
    } while (_DAT_0003ee28 != 0);
    DAT_0003ee30 = piVar4 + 6;
    DAT_0003ee34 = puVar5 + 0x8c8;
    _DAT_0003ee24 = _DAT_0003ee24 + -1;
    if (_DAT_0003ee24 == 0) {
      return;
    }
  } while( true );
}

