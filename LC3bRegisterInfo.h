//===- LC3bRegisterInfo.h - LC3b Register Information Impl ----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the LC3b implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LC3BREGISTERINFO_H
#define LC3BREGISTERINFO_H

#include "llvm/Target/TargetRegisterInfo.h"
#include "LC3bGenRegisterInfo.h.inc"

namespace llvm {

class LC3bSubtarget;
class TargetInstrInfo;
class Type;

struct LC3bRegisterInfo : public LC3bGenRegisterInfo {
  LC3bSubtarget &Subtarget;
  const TargetInstrInfo &TII;

  LC3bRegisterInfo(LC3bSubtarget &st, const TargetInstrInfo &tii);

  /// Code Generation virtual methods...
  const unsigned *getCalleeSavedRegs(const MachineFunction *MF = 0) const;

  BitVector getReservedRegs(const MachineFunction &MF) const;

  void eliminateCallFramePseudoInstr(MachineFunction &MF,
                                     MachineBasicBlock &MBB,
                                     MachineBasicBlock::iterator I) const;

  void eliminateFrameIndex(MachineBasicBlock::iterator II,
                           int SPAdj, RegScavenger *RS = NULL) const;

  void processFunctionBeforeFrameFinalized(MachineFunction &MF) const;

  // Debug information queries.
  unsigned getRARegister() const;
  unsigned getFrameRegister(const MachineFunction &MF) const;

  // Exception handling queries.
  unsigned getEHExceptionRegister() const;
  unsigned getEHHandlerRegister() const;

  int getDwarfRegNum(unsigned RegNum, bool isEH) const;
};

} // end namespace llvm

#endif
