
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0001e62e(undefined4 *param_1,undefined4 param_2,undefined4 unaff_EBX,int *param_4)

{
  byte bVar1;
  undefined1 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  short sVar13;
  short sVar14;
  uint uVar15;
  uint uVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  bool bVar19;
  
  _DAT_0003ee24 = 0x19;
  DAT_0003ee2c = unaff_EBX;
  DAT_0003ee30 = param_4;
  DAT_0003ee34 = param_1;
LAB_0001e64a:
  do {
    _DAT_0003ee28 = 0x28;
    do {
      while( true ) {
        iVar5 = (DAT_0003ee30[3] - *DAT_0003ee30) * 0x100;
        iVar6 = iVar5 >> 0xb;
        DAT_0003edd4 = DAT_0003ee30[5] - DAT_0003ee30[2] >> 3;
        uRam0001e78c = iVar6 << 0x10;
        uRam0001e796 = DAT_0003edd4 << 0x10;
        cRam0001e79c = (char)((uint)DAT_0003edd4 >> 0x10);
        iVar7 = (DAT_0003ee30[0x7b] - *DAT_0003ee30) * 0x100;
        iVar10 = DAT_0003ee30[0x7d] - DAT_0003ee30[2] >> 3;
        _DAT_0003eddc = (undefined2)(iVar7 >> 0xb);
        cRam0003eddf = (char)((uint)iVar7 >> 0x18);
        DAT_0003edde = cRam0003eddf >> 3;
        cRam0003eddf = cRam0003eddf >> 7;
        _DAT_0003edec = (undefined2)iVar10;
        DAT_0003edee = (char)((uint)iVar10 >> 0x10);
        cRam0003edef = (char)(DAT_0003ee30[0x7d] - DAT_0003ee30[2] >> 0x1b);
        iVar7 = ((DAT_0003ee30[0x7e] - DAT_0003ee30[0x7b]) * 0x100 >> 0xb) - iVar6;
        iVar11 = (DAT_0003ee30[0x80] - DAT_0003ee30[0x7d] >> 3) - DAT_0003edd4;
        iVar10 = iVar7 >> 3;
        DAT_0003edf2._2_2_ = (undefined2)iVar10;
        DAT_0003edf6 = (char)((uint)iVar10 >> 0x10);
        cRam0003edf7 = (char)(iVar7 >> 0x1b);
        DAT_0003ee02._2_2_ = (undefined2)(iVar11 >> 3);
        DAT_0003ee06._0_2_ = (short)(iVar11 >> 0x13);
        bVar1 = *(byte *)((int)DAT_0003ee30 + 0x202);
        puVar9 = (undefined1 *)
                 CONCAT31((int3)((uint)DAT_0003ee2c >> 8),*(undefined1 *)((int)DAT_0003ee30 + 2));
        iVar7 = CONCAT22((short)((uint)DAT_000402f4 >> 0x10),
                         CONCAT11(*(undefined1 *)((int)DAT_0003ee30 + 10),bVar1));
        uVar16 = *(uint *)((int)DAT_0003ee30 + 6);
        DAT_0003edc4._2_1_ = (byte)(iVar5 >> 0x1b);
        puVar8 = (undefined1 *)
                 CONCAT22((short)((uint)*(undefined4 *)((int)DAT_0003ee30 + -2) >> 0x10),
                          (ushort)DAT_0003edc4._2_1_);
        uRam0001e869 = uRam0001e78c;
        DAT_0003edc4 = iVar6;
        if (((*(byte *)((int)DAT_0003ee30 + 10) == 0 && *(byte *)((int)DAT_0003ee30 + 0x16) == 0) &&
            *(byte *)((int)DAT_0003ee30 + 0x1f6) == 0) && bVar1 == 0) break;
        if ((*(byte *)((int)DAT_0003ee30 + 10) & *(byte *)((int)DAT_0003ee30 + 0x16) &
             *(byte *)((int)DAT_0003ee30 + 0x1f6) & bVar1) == 0xff) {
          sVar13 = 8;
          puVar17 = DAT_0003ee34;
          do {
            sVar14 = 2;
            do {
              puVar18 = puVar17;
              *puVar18 = 0xffffffff;
              puVar4 = DAT_0003ee34;
              piVar3 = DAT_0003ee30;
              sVar14 = sVar14 + -1;
              puVar17 = puVar18 + 1;
            } while (sVar14 != 0);
            puVar17 = puVar18 + 0x4f;
            sVar13 = sVar13 + -1;
          } while (sVar13 != 0);
          DAT_0003ee30 = DAT_0003ee30 + 3;
          DAT_0003ee34 = DAT_0003ee34 + 2;
          _DAT_0003ee28 = _DAT_0003ee28 + -1;
          if (_DAT_0003ee28 == 0) {
            DAT_0003ee30 = piVar3 + 6;
            DAT_0003ee34 = puVar4 + 0x232;
            _DAT_0003ee24 = _DAT_0003ee24 + -1;
            if (_DAT_0003ee24 == 0) {
              return;
            }
            goto LAB_0001e64a;
          }
        }
        else {
          uVar12 = CONCAT22((short)DAT_0003ee06,8);
          puVar17 = DAT_0003ee34;
          do {
            DAT_0003ee06._2_2_ = SUB42(puVar9,0);
            uRam0003ee0a = (undefined2)((uint)puVar9 >> 0x10);
            uVar15 = CONCAT22((short)(uVar16 >> 0x10),8);
            DAT_0003ee0c = puVar8;
            DAT_0003ee10 = uVar12;
            DAT_0003ee14 = iVar7;
            DAT_0003ee18 = uVar16;
            do {
              puVar18 = puVar17;
              uVar2 = *puVar9;
              uVar16 = (uint)iVar7 >> 8;
              bVar19 = (undefined1 *)0xeeeeeeee < puVar8;
              puVar8 = &DAT_11111111 + (int)puVar8;
              puVar9 = (undefined1 *)
                       CONCAT31((int3)((uint)puVar9 >> 8),(char)puVar9 + (char)puVar8 + bVar19);
              iVar7 = (uint)CONCAT21((short)((uint)iVar7 >> 0x10),
                                     (char)((uint)iVar7 >> 8) + '\x11' + (0xeeeeeeee < uVar15)) << 8
              ;
              *(undefined1 *)puVar18 = *(undefined1 *)CONCAT31((int3)uVar16,uVar2);
              puVar4 = DAT_0003ee34;
              piVar3 = DAT_0003ee30;
              sVar13 = (short)(&DAT_11111111 + uVar15) + -1;
              uVar15 = CONCAT22((short)((uint)(&DAT_11111111 + uVar15) >> 0x10),sVar13);
              puVar17 = (undefined4 *)((int)puVar18 + 1);
            } while (sVar13 != 0);
            puVar17 = (undefined4 *)((int)puVar18 + 0x139);
            bVar19 = CARRY4(uRam0001e78c,CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2));
            uRam0001e78c = uRam0001e78c + CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2);
            uVar16 = CONCAT31((int3)((uint)DAT_0003ee0c >> 8),
                              (char)DAT_0003ee0c + DAT_0003edf6 + bVar19);
            bVar19 = CARRY4(uRam0001e796,CONCAT22(DAT_0003ee02._2_2_,(undefined2)DAT_0003ee02));
            uRam0001e796 = uRam0001e796 + CONCAT22(DAT_0003ee02._2_2_,(undefined2)DAT_0003ee02);
            cRam0001e79c = cRam0001e79c + (char)(short)DAT_0003ee06 + bVar19;
            puVar8 = (undefined1 *)(uVar16 + CONCAT22(_DAT_0003eddc,_DAT_0003edda));
            puVar9 = (undefined1 *)
                     CONCAT31((int3)(CONCAT22(uRam0003ee0a,DAT_0003ee06._2_2_) >> 8),
                              (char)DAT_0003ee06._2_2_ + DAT_0003edde +
                              CARRY4(uVar16,CONCAT22(_DAT_0003eddc,_DAT_0003edda)));
            uVar16 = DAT_0003ee18 + CONCAT22(_DAT_0003edec,_DAT_0003edea);
            iVar7 = CONCAT22((short)((uint)DAT_0003ee14 >> 0x10),
                             CONCAT11((char)((uint)DAT_0003ee14 >> 8) + DAT_0003edee +
                                      CARRY4(DAT_0003ee18,CONCAT22(_DAT_0003edec,_DAT_0003edea)),
                                      (char)DAT_0003ee14));
            sVar13 = (short)DAT_0003ee10 + -1;
            uVar12 = CONCAT22((short)((uint)DAT_0003ee10 >> 0x10),sVar13);
          } while (sVar13 != 0);
          DAT_0003ee30 = DAT_0003ee30 + 3;
          DAT_0003ee34 = DAT_0003ee34 + 2;
          _DAT_0003ee28 = _DAT_0003ee28 + -1;
          if (_DAT_0003ee28 == 0) {
            DAT_0003ee30 = piVar3 + 6;
            DAT_0003ee34 = puVar4 + 0x232;
            _DAT_0003ee24 = _DAT_0003ee24 + -1;
            if (_DAT_0003ee24 == 0) {
              return;
            }
            goto LAB_0001e64a;
          }
        }
      }
      uVar12 = CONCAT22((short)DAT_0003ee06,8);
      puVar17 = DAT_0003ee34;
      do {
        DAT_0003ee06._2_2_ = SUB42(puVar9,0);
        uRam0003ee0a = (undefined2)((uint)puVar9 >> 0x10);
        sVar13 = 8;
        DAT_0003ee0c = puVar8;
        DAT_0003ee10 = uVar12;
        do {
          puVar18 = puVar17;
          uVar2 = *puVar9;
          bVar19 = (undefined1 *)0xeeeeeeee < puVar8;
          puVar8 = &DAT_11111111 + (int)puVar8;
          puVar9 = (undefined1 *)
                   CONCAT31((int3)((uint)puVar9 >> 8),(char)puVar9 + (char)puVar8 + bVar19);
          *(undefined1 *)puVar18 = uVar2;
          puVar4 = DAT_0003ee34;
          piVar3 = DAT_0003ee30;
          sVar13 = sVar13 + -1;
          puVar17 = (undefined4 *)((int)puVar18 + 1);
        } while (sVar13 != 0);
        puVar17 = (undefined4 *)((int)puVar18 + 0x139);
        bVar19 = CARRY4(uRam0001e869,CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2));
        uRam0001e869 = uRam0001e869 + CONCAT22(DAT_0003edf2._2_2_,(undefined2)DAT_0003edf2);
        uVar16 = CONCAT31((int3)((uint)DAT_0003ee0c >> 8),(char)DAT_0003ee0c + DAT_0003edf6 + bVar19
                         );
        puVar8 = (undefined1 *)(uVar16 + CONCAT22(_DAT_0003eddc,_DAT_0003edda));
        puVar9 = (undefined1 *)
                 CONCAT31((int3)(CONCAT22(uRam0003ee0a,DAT_0003ee06._2_2_) >> 8),
                          (char)DAT_0003ee06._2_2_ + DAT_0003edde +
                          CARRY4(uVar16,CONCAT22(_DAT_0003eddc,_DAT_0003edda)));
        sVar13 = (short)DAT_0003ee10 + -1;
        uVar12 = CONCAT22((short)((uint)DAT_0003ee10 >> 0x10),sVar13);
      } while (sVar13 != 0);
      DAT_0003ee30 = DAT_0003ee30 + 3;
      DAT_0003ee34 = DAT_0003ee34 + 2;
      _DAT_0003ee28 = _DAT_0003ee28 + -1;
    } while (_DAT_0003ee28 != 0);
    DAT_0003ee30 = piVar3 + 6;
    DAT_0003ee34 = puVar4 + 0x232;
    _DAT_0003ee24 = _DAT_0003ee24 + -1;
    if (_DAT_0003ee24 == 0) {
      return;
    }
  } while( true );
}

