
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e266(byte *param_1,undefined4 param_2,undefined4 unaff_EBX,int *param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined2 uVar14;
  undefined1 *puVar13;
  short sVar15;
  short sVar16;
  uint uVar17;
  uint uVar18;
  byte *pbVar19;
  byte *pbVar20;
  byte *pbVar21;
  byte *pbVar22;
  bool bVar23;
  bool bVar24;
  
  _DAT_0003ee24 = 0x19;
  DAT_0003ee2c = unaff_EBX;
  DAT_0003ee30 = param_4;
  DAT_0003ee34 = param_1;
LAB_0001e282:
  do {
    _DAT_0003ee28 = 0x28;
    do {
      while( true ) {
        iVar3 = (DAT_0003ee30[3] - *DAT_0003ee30) * 0x100;
        iVar4 = iVar3 >> 0xb;
        iVar9 = (DAT_0003ee30[4] - DAT_0003ee30[1]) * 0x100;
        iVar10 = iVar9 >> 0xb;
        DAT_0003edd4 = DAT_0003ee30[5] - DAT_0003ee30[2] >> 3;
        uRam0001e427 = iVar4 << 0x10;
        uRam0001e431 = iVar10 << 0x10;
        uRam0001e439 = DAT_0003edd4 << 0x10;
        cRam0001e43f = (char)((uint)DAT_0003edd4 >> 0x10);
        iVar5 = (DAT_0003ee30[0x7b] - *DAT_0003ee30) * 0x100;
        iVar6 = (DAT_0003ee30[0x7c] - DAT_0003ee30[1]) * 0x100;
        iVar11 = DAT_0003ee30[0x7d] - DAT_0003ee30[2] >> 3;
        _DAT_0003eddc = (undefined2)(iVar5 >> 0xb);
        cRam0003eddf = (char)((uint)iVar5 >> 0x18);
        DAT_0003edde = cRam0003eddf >> 3;
        cRam0003eddf = cRam0003eddf >> 7;
        _DAT_0003ede4 = (undefined2)(iVar6 >> 0xb);
        cRam0003ede7 = (char)((uint)iVar6 >> 0x18);
        DAT_0003ede6 = cRam0003ede7 >> 3;
        cRam0003ede7 = cRam0003ede7 >> 7;
        _DAT_0003edec = (undefined2)iVar11;
        DAT_0003edee = (char)((uint)iVar11 >> 0x10);
        cRam0003edef = (char)(DAT_0003ee30[0x7d] - DAT_0003ee30[2] >> 0x1b);
        iVar5 = ((DAT_0003ee30[0x7e] - DAT_0003ee30[0x7b]) * 0x100 >> 0xb) - iVar4;
        iVar11 = ((DAT_0003ee30[0x7f] - DAT_0003ee30[0x7c]) * 0x100 >> 0xb) - iVar10;
        iVar12 = (DAT_0003ee30[0x80] - DAT_0003ee30[0x7d] >> 3) - DAT_0003edd4;
        iVar6 = iVar5 >> 3;
        iVar7 = iVar11 >> 3;
        DAT_0003edf2._2_2_ = (undefined2)iVar6;
        DAT_0003edf6 = (char)((uint)iVar6 >> 0x10);
        cRam0003edf7 = (char)(iVar5 >> 0x1b);
        DAT_0003edfa._2_2_ = (undefined2)iVar7;
        DAT_0003edfe = (char)((uint)iVar7 >> 0x10);
        cRam0003edff = (char)(iVar11 >> 0x1b);
        DAT_0003ee02._2_2_ = (undefined2)(iVar12 >> 3);
        DAT_0003ee06._0_2_ = (short)(iVar12 >> 0x13);
        bVar1 = *(byte *)((int)DAT_0003ee30 + 0x202);
        pbVar22 = (byte *)CONCAT22((short)((uint)DAT_0003ee2c >> 0x10),
                                   CONCAT11(*(undefined1 *)((int)DAT_0003ee30 + 6),
                                            *(undefined1 *)((int)DAT_0003ee30 + 2)));
        iVar5 = CONCAT22((short)((uint)DAT_000402f8 >> 0x10),
                         CONCAT11(*(undefined1 *)((int)DAT_0003ee30 + 10),bVar1));
        uVar18 = *(uint *)((int)DAT_0003ee30 + 6);
        DAT_0003edc4._2_1_ = (char)(iVar3 >> 0x1b);
        DAT_0003edcc._2_1_ = (char)(iVar9 >> 0x1b);
        puVar8 = (undefined1 *)
                 CONCAT22((short)((uint)*(undefined4 *)((int)DAT_0003ee30 + -2) >> 0x10),
                          CONCAT11(DAT_0003edcc._2_1_,DAT_0003edc4._2_1_));
        uVar14 = (undefined2)((uint)*(undefined4 *)((int)DAT_0003ee30 + 2) >> 0x10);
        uRam0001e52c = uRam0001e427;
        uRam0001e534 = uRam0001e431;
        DAT_0003edc4 = iVar4;
        DAT_0003edcc = iVar10;
        if (((*(byte *)((int)DAT_0003ee30 + 10) == 0 && *(byte *)((int)DAT_0003ee30 + 0x16) == 0) &&
            *(byte *)((int)DAT_0003ee30 + 0x1f6) == 0) && bVar1 == 0) break;
        if ((*(byte *)((int)DAT_0003ee30 + 10) & *(byte *)((int)DAT_0003ee30 + 0x16) &
             *(byte *)((int)DAT_0003ee30 + 0x1f6) & bVar1) == 0xff) {
          sVar15 = 8;
          pbVar22 = DAT_0003ee34;
          do {
            sVar16 = 2;
            do {
              pbVar21 = pbVar22;
              pbVar21[0] = 0;
              pbVar20 = DAT_0003ee34;
              piVar2 = DAT_0003ee30;
              pbVar21[1] = 0;
              pbVar21[2] = 0;
              pbVar21[3] = 0;
              sVar16 = sVar16 + -1;
              pbVar22 = pbVar21 + 4;
            } while (sVar16 != 0);
            pbVar22 = pbVar21 + 0x13c;
            sVar15 = sVar15 + -1;
          } while (sVar15 != 0);
          DAT_0003ee30 = DAT_0003ee30 + 3;
          DAT_0003ee34 = DAT_0003ee34 + 8;
          _DAT_0003ee28 = _DAT_0003ee28 + -1;
          if (_DAT_0003ee28 == 0) {
            DAT_0003ee30 = piVar2 + 6;
            DAT_0003ee34 = pbVar20 + 0x8c8;
            _DAT_0003ee24 = _DAT_0003ee24 + -1;
            if (_DAT_0003ee24 == 0) {
              return;
            }
            goto LAB_0001e282;
          }
        }
        else {
          puVar13 = (undefined1 *)CONCAT22(uVar14,8);
          pbVar20 = DAT_0003ee34;
          do {
            DAT_0003ee06._2_2_ = SUB42(pbVar22,0);
            uRam0003ee0a = (undefined2)((uint)pbVar22 >> 0x10);
            uVar17 = CONCAT22((short)(uVar18 >> 0x10),8);
            DAT_0003ee0c = puVar8;
            DAT_0003ee10 = puVar13;
            DAT_0003ee14 = iVar5;
            DAT_0003ee18 = uVar18;
            do {
              pbVar19 = pbVar20;
              bVar1 = *pbVar22;
              uVar18 = (uint)iVar5 >> 8;
              bVar23 = (undefined1 *)0xeeeeeeee < puVar8;
              puVar8 = &DAT_11111111 + (int)puVar8;
              bVar24 = (undefined1 *)0xeeeeeeee < puVar13;
              puVar13 = &DAT_11111111 + (int)puVar13;
              pbVar22 = (byte *)CONCAT22((short)((uint)pbVar22 >> 0x10),
                                         CONCAT11((char)((uint)pbVar22 >> 8) +
                                                  (char)((uint)puVar8 >> 8) + bVar24,
                                                  (char)pbVar22 + (char)puVar8 + bVar23));
              iVar5 = (uint)CONCAT21((short)((uint)iVar5 >> 0x10),
                                     (char)((uint)iVar5 >> 8) + '\x11' + (0xeeeeeeee < uVar17)) << 8
              ;
              *pbVar19 = *(byte *)CONCAT31((int3)uVar18,bVar1);
              pbVar21 = DAT_0003ee34;
              piVar2 = DAT_0003ee30;
              sVar15 = (short)(&DAT_11111111 + uVar17) + -1;
              uVar17 = CONCAT22((short)((uint)(&DAT_11111111 + uVar17) >> 0x10),sVar15);
              pbVar20 = pbVar19 + 1;
            } while (sVar15 != 0);
            pbVar20 = pbVar19 + 0x139;
            bVar23 = CARRY4(uRam0001e427,CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2));
            uRam0001e427 = uRam0001e427 + CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2);
            bVar24 = CARRY4(uRam0001e431,CONCAT22(DAT_0003edfa._2_2_,(undefined2)DAT_0003edfa));
            uRam0001e431 = uRam0001e431 + CONCAT22(DAT_0003edfa._2_2_,(undefined2)DAT_0003edfa);
            uVar18 = CONCAT22((short)((uint)DAT_0003ee0c >> 0x10),
                              CONCAT11((char)((uint)DAT_0003ee0c >> 8) + DAT_0003edfe + bVar24,
                                       (char)DAT_0003ee0c + DAT_0003edf6 + bVar23));
            bVar23 = CARRY4(uRam0001e439,CONCAT22(DAT_0003ee02._2_2_,(undefined2)DAT_0003ee02));
            uRam0001e439 = uRam0001e439 + CONCAT22(DAT_0003ee02._2_2_,(undefined2)DAT_0003ee02);
            cRam0001e43f = cRam0001e43f + (char)(short)DAT_0003ee06 + bVar23;
            puVar8 = (undefined1 *)(uVar18 + CONCAT22(_DAT_0003eddc,_DAT_0003edda));
            pbVar22 = (byte *)CONCAT22(uRam0003ee0a,
                                       CONCAT11((char)((ushort)DAT_0003ee06._2_2_ >> 8) +
                                                DAT_0003ede6 +
                                                CARRY4((uint)DAT_0003ee10,
                                                       CONCAT22(_DAT_0003ede4,_DAT_0003ede2)),
                                                (char)DAT_0003ee06._2_2_ + DAT_0003edde +
                                                CARRY4(uVar18,CONCAT22(_DAT_0003eddc,_DAT_0003edda))
                                               ));
            uVar18 = DAT_0003ee18 + CONCAT22(_DAT_0003edec,_DAT_0003edea);
            iVar5 = CONCAT22((short)((uint)DAT_0003ee14 >> 0x10),
                             CONCAT11((char)((uint)DAT_0003ee14 >> 8) + DAT_0003edee +
                                      CARRY4(DAT_0003ee18,CONCAT22(_DAT_0003edec,_DAT_0003edea)),
                                      (char)DAT_0003ee14));
            sVar15 = (short)(DAT_0003ee10 + CONCAT22(_DAT_0003ede4,_DAT_0003ede2)) + -1;
            puVar13 = (undefined1 *)
                      CONCAT22((short)((uint)(DAT_0003ee10 + CONCAT22(_DAT_0003ede4,_DAT_0003ede2))
                                      >> 0x10),sVar15);
          } while (sVar15 != 0);
          DAT_0003ee30 = DAT_0003ee30 + 3;
          DAT_0003ee34 = DAT_0003ee34 + 8;
          _DAT_0003ee28 = _DAT_0003ee28 + -1;
          if (_DAT_0003ee28 == 0) {
            DAT_0003ee30 = piVar2 + 6;
            DAT_0003ee34 = pbVar21 + 0x8c8;
            _DAT_0003ee24 = _DAT_0003ee24 + -1;
            if (_DAT_0003ee24 == 0) {
              return;
            }
            goto LAB_0001e282;
          }
        }
      }
      puVar13 = (undefined1 *)CONCAT22(uVar14,8);
      pbVar20 = DAT_0003ee34;
      do {
        DAT_0003ee06._2_2_ = SUB42(pbVar22,0);
        uRam0003ee0a = (undefined2)((uint)pbVar22 >> 0x10);
        sVar15 = 8;
        DAT_0003ee0c = puVar8;
        DAT_0003ee10 = puVar13;
        do {
          pbVar19 = pbVar20;
          bVar1 = *pbVar22;
          bVar23 = (undefined1 *)0xeeeeeeee < puVar8;
          puVar8 = &DAT_11111111 + (int)puVar8;
          bVar24 = (undefined1 *)0xeeeeeeee < puVar13;
          puVar13 = &DAT_11111111 + (int)puVar13;
          pbVar22 = (byte *)CONCAT22((short)((uint)pbVar22 >> 0x10),
                                     CONCAT11((char)((uint)pbVar22 >> 8) + (char)((uint)puVar8 >> 8)
                                              + bVar24,(char)pbVar22 + (char)puVar8 + bVar23));
          *pbVar19 = ~bVar1;
          pbVar21 = DAT_0003ee34;
          piVar2 = DAT_0003ee30;
          sVar15 = sVar15 + -1;
          pbVar20 = pbVar19 + 1;
        } while (sVar15 != 0);
        pbVar20 = pbVar19 + 0x139;
        bVar23 = CARRY4(uRam0001e52c,CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2));
        uRam0001e52c = uRam0001e52c + CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2);
        bVar24 = CARRY4(uRam0001e534,CONCAT22(DAT_0003edfa._2_2_,(undefined2)DAT_0003edfa));
        uRam0001e534 = uRam0001e534 + CONCAT22(DAT_0003edfa._2_2_,(undefined2)DAT_0003edfa);
        uVar18 = CONCAT22((short)((uint)DAT_0003ee0c >> 0x10),
                          CONCAT11((char)((uint)DAT_0003ee0c >> 8) + DAT_0003edfe + bVar24,
                                   (char)DAT_0003ee0c + DAT_0003edf6 + bVar23));
        puVar8 = (undefined1 *)(uVar18 + CONCAT22(_DAT_0003eddc,_DAT_0003edda));
        pbVar22 = (byte *)CONCAT22(uRam0003ee0a,
                                   CONCAT11((char)((ushort)DAT_0003ee06._2_2_ >> 8) + DAT_0003ede6 +
                                            CARRY4((uint)DAT_0003ee10,
                                                   CONCAT22(_DAT_0003ede4,_DAT_0003ede2)),
                                            (char)DAT_0003ee06._2_2_ + DAT_0003edde +
                                            CARRY4(uVar18,CONCAT22(_DAT_0003eddc,_DAT_0003edda))));
        sVar15 = (short)(DAT_0003ee10 + CONCAT22(_DAT_0003ede4,_DAT_0003ede2)) + -1;
        puVar13 = (undefined1 *)
                  CONCAT22((short)((uint)(DAT_0003ee10 + CONCAT22(_DAT_0003ede4,_DAT_0003ede2)) >>
                                  0x10),sVar15);
      } while (sVar15 != 0);
      DAT_0003ee30 = DAT_0003ee30 + 3;
      DAT_0003ee34 = DAT_0003ee34 + 8;
      _DAT_0003ee28 = _DAT_0003ee28 + -1;
    } while (_DAT_0003ee28 != 0);
    DAT_0003ee30 = piVar2 + 6;
    DAT_0003ee34 = pbVar21 + 0x8c8;
    _DAT_0003ee24 = _DAT_0003ee24 + -1;
    if (_DAT_0003ee24 == 0) {
      return;
    }
  } while( true );
}

