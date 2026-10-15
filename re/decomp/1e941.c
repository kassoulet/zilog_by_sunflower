
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e941(byte *param_1,undefined4 param_2,undefined4 unaff_EBX,int *param_4)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  short sVar10;
  short sVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  bool bVar18;
  
  _DAT_0003ee24 = 0x19;
  DAT_0003ee2c = unaff_EBX;
  DAT_0003ee30 = param_4;
  DAT_0003ee34 = param_1;
LAB_0001e95d:
  do {
    _DAT_0003ee28 = 0x28;
    do {
      while( true ) {
        iVar3 = (DAT_0003ee30[3] - *DAT_0003ee30) * 0x100;
        iVar4 = iVar3 >> 0xb;
        DAT_0003edd4 = DAT_0003ee30[5] - DAT_0003ee30[2] >> 3;
        uRam0001ea9f = iVar4 << 0x10;
        uRam0001eaa9 = DAT_0003edd4 << 0x10;
        cRam0001eaaf = (char)((uint)DAT_0003edd4 >> 0x10);
        iVar5 = (DAT_0003ee30[0x7b] - *DAT_0003ee30) * 0x100;
        iVar7 = DAT_0003ee30[0x7d] - DAT_0003ee30[2] >> 3;
        _DAT_0003eddc = (undefined2)(iVar5 >> 0xb);
        cRam0003eddf = (char)((uint)iVar5 >> 0x18);
        DAT_0003edde = cRam0003eddf >> 3;
        cRam0003eddf = cRam0003eddf >> 7;
        _DAT_0003edec = (undefined2)iVar7;
        DAT_0003edee = (char)((uint)iVar7 >> 0x10);
        cRam0003edef = (char)(DAT_0003ee30[0x7d] - DAT_0003ee30[2] >> 0x1b);
        iVar5 = ((DAT_0003ee30[0x7e] - DAT_0003ee30[0x7b]) * 0x100 >> 0xb) - iVar4;
        iVar8 = (DAT_0003ee30[0x80] - DAT_0003ee30[0x7d] >> 3) - DAT_0003edd4;
        iVar7 = iVar5 >> 3;
        DAT_0003edf2._2_2_ = (undefined2)iVar7;
        DAT_0003edf6 = (char)((uint)iVar7 >> 0x10);
        cRam0003edf7 = (char)(iVar5 >> 0x1b);
        DAT_0003ee02._2_2_ = (undefined2)(iVar8 >> 3);
        DAT_0003ee06._0_2_ = (short)(iVar8 >> 0x13);
        bVar1 = *(byte *)((int)DAT_0003ee30 + 0x202);
        pbVar17 = (byte *)CONCAT31((int3)((uint)DAT_0003ee2c >> 8),
                                   *(undefined1 *)((int)DAT_0003ee30 + 2));
        iVar5 = CONCAT22((short)((uint)DAT_000402f8 >> 0x10),
                         CONCAT11(*(undefined1 *)((int)DAT_0003ee30 + 10),bVar1));
        uVar13 = *(uint *)((int)DAT_0003ee30 + 6);
        DAT_0003edc4._2_1_ = (byte)(iVar3 >> 0x1b);
        puVar6 = (undefined1 *)
                 CONCAT22((short)((uint)*(undefined4 *)((int)DAT_0003ee30 + -2) >> 0x10),
                          (ushort)DAT_0003edc4._2_1_);
        uRam0001eb7e = uRam0001ea9f;
        DAT_0003edc4 = iVar4;
        if (((*(byte *)((int)DAT_0003ee30 + 10) == 0 && *(byte *)((int)DAT_0003ee30 + 0x16) == 0) &&
            *(byte *)((int)DAT_0003ee30 + 0x1f6) == 0) && bVar1 == 0) break;
        if ((*(byte *)((int)DAT_0003ee30 + 10) & *(byte *)((int)DAT_0003ee30 + 0x16) &
             *(byte *)((int)DAT_0003ee30 + 0x1f6) & bVar1) == 0xff) {
          sVar10 = 8;
          pbVar17 = DAT_0003ee34;
          do {
            sVar11 = 2;
            do {
              pbVar16 = pbVar17;
              pbVar16[0] = 0;
              pbVar15 = DAT_0003ee34;
              piVar2 = DAT_0003ee30;
              pbVar16[1] = 0;
              pbVar16[2] = 0;
              pbVar16[3] = 0;
              sVar11 = sVar11 + -1;
              pbVar17 = pbVar16 + 4;
            } while (sVar11 != 0);
            pbVar17 = pbVar16 + 0x13c;
            sVar10 = sVar10 + -1;
          } while (sVar10 != 0);
          DAT_0003ee30 = DAT_0003ee30 + 3;
          DAT_0003ee34 = DAT_0003ee34 + 8;
          _DAT_0003ee28 = _DAT_0003ee28 + -1;
          if (_DAT_0003ee28 == 0) {
            DAT_0003ee30 = piVar2 + 6;
            DAT_0003ee34 = pbVar15 + 0x8c8;
            _DAT_0003ee24 = _DAT_0003ee24 + -1;
            if (_DAT_0003ee24 == 0) {
              return;
            }
            goto LAB_0001e95d;
          }
        }
        else {
          uVar9 = CONCAT22((short)DAT_0003ee06,8);
          pbVar15 = DAT_0003ee34;
          do {
            DAT_0003ee06._2_2_ = SUB42(pbVar17,0);
            uRam0003ee0a = (undefined2)((uint)pbVar17 >> 0x10);
            uVar12 = CONCAT22((short)(uVar13 >> 0x10),8);
            DAT_0003ee0c = puVar6;
            DAT_0003ee10 = uVar9;
            DAT_0003ee14 = iVar5;
            DAT_0003ee18 = uVar13;
            do {
              pbVar14 = pbVar15;
              bVar1 = *pbVar17;
              uVar13 = (uint)iVar5 >> 8;
              bVar18 = (undefined1 *)0xeeeeeeee < puVar6;
              puVar6 = &DAT_11111111 + (int)puVar6;
              pbVar17 = (byte *)CONCAT31((int3)((uint)pbVar17 >> 8),
                                         (char)pbVar17 + (char)puVar6 + bVar18);
              iVar5 = (uint)CONCAT21((short)((uint)iVar5 >> 0x10),
                                     (char)((uint)iVar5 >> 8) + '\x11' + (0xeeeeeeee < uVar12)) << 8
              ;
              *pbVar14 = *(byte *)CONCAT31((int3)uVar13,bVar1);
              pbVar16 = DAT_0003ee34;
              piVar2 = DAT_0003ee30;
              sVar10 = (short)(&DAT_11111111 + uVar12) + -1;
              uVar12 = CONCAT22((short)((uint)(&DAT_11111111 + uVar12) >> 0x10),sVar10);
              pbVar15 = pbVar14 + 1;
            } while (sVar10 != 0);
            pbVar15 = pbVar14 + 0x139;
            bVar18 = CARRY4(uRam0001ea9f,CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2));
            uRam0001ea9f = uRam0001ea9f + CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2);
            uVar13 = CONCAT31((int3)((uint)DAT_0003ee0c >> 8),
                              (char)DAT_0003ee0c + DAT_0003edf6 + bVar18);
            bVar18 = CARRY4(uRam0001eaa9,CONCAT22(DAT_0003ee02._2_2_,(undefined2)DAT_0003ee02));
            uRam0001eaa9 = uRam0001eaa9 + CONCAT22(DAT_0003ee02._2_2_,(undefined2)DAT_0003ee02);
            cRam0001eaaf = cRam0001eaaf + (char)(short)DAT_0003ee06 + bVar18;
            puVar6 = (undefined1 *)(uVar13 + CONCAT22(_DAT_0003eddc,_DAT_0003edda));
            pbVar17 = (byte *)CONCAT31((int3)(CONCAT22(uRam0003ee0a,DAT_0003ee06._2_2_) >> 8),
                                       (char)DAT_0003ee06._2_2_ + DAT_0003edde +
                                       CARRY4(uVar13,CONCAT22(_DAT_0003eddc,_DAT_0003edda)));
            uVar13 = DAT_0003ee18 + CONCAT22(_DAT_0003edec,_DAT_0003edea);
            iVar5 = CONCAT22((short)((uint)DAT_0003ee14 >> 0x10),
                             CONCAT11((char)((uint)DAT_0003ee14 >> 8) + DAT_0003edee +
                                      CARRY4(DAT_0003ee18,CONCAT22(_DAT_0003edec,_DAT_0003edea)),
                                      (char)DAT_0003ee14));
            sVar10 = (short)DAT_0003ee10 + -1;
            uVar9 = CONCAT22((short)((uint)DAT_0003ee10 >> 0x10),sVar10);
          } while (sVar10 != 0);
          DAT_0003ee30 = DAT_0003ee30 + 3;
          DAT_0003ee34 = DAT_0003ee34 + 8;
          _DAT_0003ee28 = _DAT_0003ee28 + -1;
          if (_DAT_0003ee28 == 0) {
            DAT_0003ee30 = piVar2 + 6;
            DAT_0003ee34 = pbVar16 + 0x8c8;
            _DAT_0003ee24 = _DAT_0003ee24 + -1;
            if (_DAT_0003ee24 == 0) {
              return;
            }
            goto LAB_0001e95d;
          }
        }
      }
      uVar9 = CONCAT22((short)DAT_0003ee06,8);
      pbVar15 = DAT_0003ee34;
      do {
        DAT_0003ee06._2_2_ = SUB42(pbVar17,0);
        uRam0003ee0a = (undefined2)((uint)pbVar17 >> 0x10);
        sVar10 = 8;
        DAT_0003ee0c = puVar6;
        DAT_0003ee10 = uVar9;
        do {
          pbVar14 = pbVar15;
          bVar1 = *pbVar17;
          bVar18 = (undefined1 *)0xeeeeeeee < puVar6;
          puVar6 = &DAT_11111111 + (int)puVar6;
          pbVar17 = (byte *)CONCAT31((int3)((uint)pbVar17 >> 8),
                                     (char)pbVar17 + (char)puVar6 + bVar18);
          *pbVar14 = ~bVar1;
          pbVar16 = DAT_0003ee34;
          piVar2 = DAT_0003ee30;
          sVar10 = sVar10 + -1;
          pbVar15 = pbVar14 + 1;
        } while (sVar10 != 0);
        pbVar15 = pbVar14 + 0x139;
        bVar18 = CARRY4(uRam0001eb7e,CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2));
        uRam0001eb7e = uRam0001eb7e + CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2);
        uVar13 = CONCAT31((int3)((uint)DAT_0003ee0c >> 8),(char)DAT_0003ee0c + DAT_0003edf6 + bVar18
                         );
        puVar6 = (undefined1 *)(uVar13 + CONCAT22(_DAT_0003eddc,_DAT_0003edda));
        pbVar17 = (byte *)CONCAT31((int3)(CONCAT22(uRam0003ee0a,DAT_0003ee06._2_2_) >> 8),
                                   (char)DAT_0003ee06._2_2_ + DAT_0003edde +
                                   CARRY4(uVar13,CONCAT22(_DAT_0003eddc,_DAT_0003edda)));
        sVar10 = (short)DAT_0003ee10 + -1;
        uVar9 = CONCAT22((short)((uint)DAT_0003ee10 >> 0x10),sVar10);
      } while (sVar10 != 0);
      DAT_0003ee30 = DAT_0003ee30 + 3;
      DAT_0003ee34 = DAT_0003ee34 + 8;
      _DAT_0003ee28 = _DAT_0003ee28 + -1;
    } while (_DAT_0003ee28 != 0);
    DAT_0003ee30 = piVar2 + 6;
    DAT_0003ee34 = pbVar16 + 0x8c8;
    _DAT_0003ee24 = _DAT_0003ee24 + -1;
    if (_DAT_0003ee24 == 0) {
      return;
    }
  } while( true );
}

