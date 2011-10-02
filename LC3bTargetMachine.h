//===-- LC3bTargetMachine.h - Define TargetMachine for LC3b ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the LC3b specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef LC3BTARGETMACHINE_H
#define LC3BTARGETMACHINE_H

#include "LC3bInstrInfo.h"
#include "LC3bISelLowering.h"
#include "LC3bFrameLowering.h"
#include "LC3bSelectionDAGInfo.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetData.h"
#include "llvm/Target/TargetFrameLowering.h"

namespace llvm {

class LC3bTargetMachine : public LLVMTargetMachine {
  const TargetData DataLayout;       // Calculates type size & alignment
  LC3bTargetLowering TLInfo;
  LC3bSelectionDAGInfo TSInfo;
  LC3bInstrInfo InstrInfo;
  LC3bFrameLowering FrameLowering;
public:
  LC3bTargetMachine(const Target &T, const std::string &TT,
                     const std::string &FS, bool is64bit);

  virtual const LC3bInstrInfo *getInstrInfo() const { return &InstrInfo; }
  virtual const TargetFrameLowering  *getFrameLowering() const {
    return &FrameLowering;
  }
  virtual const LC3bRegisterInfo *getRegisterInfo() const {
    return &InstrInfo.getRegisterInfo();
  }
  virtual const LC3bTargetLowering* getTargetLowering() const {
    return &TLInfo;
  }
  virtual const LC3bSelectionDAGInfo* getSelectionDAGInfo() const {
    return &TSInfo;
  }
  virtual const TargetData       *getTargetData() const { return &DataLayout; }

  // Pass Pipeline Configuration
  virtual bool addInstSelector(PassManagerBase &PM, CodeGenOpt::Level OptLevel);
  virtual bool addPreEmitPass(PassManagerBase &PM, CodeGenOpt::Level OptLevel);
};

/// LC3bV8TargetMachine - LC3b 32-bit target machine
///
class LC3bV8TargetMachine : public LC3bTargetMachine {
public:
  LC3bV8TargetMachine(const Target &T, const std::string &TT,
                       const std::string &FS);
};

/// LC3bV9TargetMachine - LC3b 64-bit target machine
///
class LC3bV9TargetMachine : public LC3bTargetMachine {
public:
  LC3bV9TargetMachine(const Target &T, const std::string &TT,
                       const std::string &FS);
};

} // end namespace llvm

#endif
