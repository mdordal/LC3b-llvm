//===- LC3bRegisterInfo.cpp - LC3B Register Information -------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the LC3B implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#include "LC3b.h"
#include "LC3bRegisterInfo.h"
#include "LC3bSubtarget.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineLocation.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Target/TargetInstrInfo.h"
#include "llvm/Type.h"
#include "llvm/ADT/BitVector.h"
#include "llvm/ADT/STLExtras.h"
using namespace llvm;

LC3bRegisterInfo::LC3bRegisterInfo(LC3bSubtarget &st,
                                     const TargetInstrInfo &tii)
  : LC3bGenRegisterInfo(SP::ADJCALLSTACKDOWN, SP::ADJCALLSTACKUP),
    Subtarget(st), TII(tii) {
}

const unsigned* LC3bRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF)
                                                                         const {
  static const unsigned CalleeSavedRegs[] = { 0 };
  return CalleeSavedRegs;
}

BitVector LC3bRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());
  Reserved.set(SP::G2);
  Reserved.set(SP::G3);
  Reserved.set(SP::G4);
  Reserved.set(SP::O6);
  Reserved.set(SP::I6);
  Reserved.set(SP::I7);
  Reserved.set(SP::G0);
  Reserved.set(SP::G5);
  Reserved.set(SP::G6);
  Reserved.set(SP::G7);
  return Reserved;
}

void LC3bRegisterInfo::
eliminateCallFramePseudoInstr(MachineFunction &MF, MachineBasicBlock &MBB,
                              MachineBasicBlock::iterator I) const {
  MachineInstr &MI = *I;
  DebugLoc dl = MI.getDebugLoc();
  int Size = MI.getOperand(0).getImm();
  if (MI.getOpcode() == SP::ADJCALLSTACKDOWN)
    Size = -Size;
  if (Size)
    BuildMI(MBB, I, dl, TII.get(SP::ADDri), SP::O6).addReg(SP::O6).addImm(Size);
  MBB.erase(I);
}

void
LC3bRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                       int SPAdj, RegScavenger *RS) const {
  assert(SPAdj == 0 && "Unexpected");

  unsigned i = 0;
  MachineInstr &MI = *II;
  DebugLoc dl = MI.getDebugLoc();
  while (!MI.getOperand(i).isFI()) {
    ++i;
    assert(i < MI.getNumOperands() && "Instr doesn't have FrameIndex operand!");
  }

  int FrameIndex = MI.getOperand(i).getIndex();

  // Addressable stack objects are accessed using neg. offsets from %fp
  MachineFunction &MF = *MI.getParent()->getParent();
  int Offset = MF.getFrameInfo()->getObjectOffset(FrameIndex) +
               MI.getOperand(i+1).getImm();

  // Replace frame index with a frame pointer reference.
  if (Offset >= -4096 && Offset <= 4095) {
    // If the offset is small enough to fit in the immediate field, directly
    // encode it.
    MI.getOperand(i).ChangeToRegister(SP::I6, false);
    MI.getOperand(i+1).ChangeToImmediate(Offset);
  } else {
    // Otherwise, emit a G1 = SETHI %hi(offset).  FIXME: it would be better to 
    // scavenge a register here instead of reserving G1 all of the time.
    unsigned OffHi = (unsigned)Offset >> 10U;
    BuildMI(*MI.getParent(), II, dl, TII.get(SP::SETHIi), SP::G1).addImm(OffHi);
    // Emit G1 = G1 + I6
    BuildMI(*MI.getParent(), II, dl, TII.get(SP::ADDrr), SP::G1).addReg(SP::G1)
      .addReg(SP::I6);
    // Insert: G1+%lo(offset) into the user.
    MI.getOperand(i).ChangeToRegister(SP::G1, false);
    MI.getOperand(i+1).ChangeToImmediate(Offset & ((1 << 10)-1));
  }
}

void LC3bRegisterInfo::
processFunctionBeforeFrameFinalized(MachineFunction &MF) const {}

unsigned LC3bRegisterInfo::getRARegister() const {
  return SP::I7;
}

unsigned LC3bRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  return SP::I6;
}

unsigned LC3bRegisterInfo::getEHExceptionRegister() const {
  llvm_unreachable("What is the exception register");
  return 0;
}

unsigned LC3bRegisterInfo::getEHHandlerRegister() const {
  llvm_unreachable("What is the exception handler register");
  return 0;
}

int LC3bRegisterInfo::getDwarfRegNum(unsigned RegNum, bool isEH) const {
  return LC3bGenRegisterInfo::getDwarfRegNumFull(RegNum, 0);
}

#include "LC3bGenRegisterInfo.inc"

