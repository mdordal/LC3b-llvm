//===-- LC3bTargetMachine.cpp - Define TargetMachine for LC3b -----------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//
//===----------------------------------------------------------------------===//

#include "LC3b.h"
#include "LC3bMCAsmInfo.h"
#include "LC3bTargetMachine.h"
#include "llvm/PassManager.h"
#include "llvm/Target/TargetRegistry.h"
using namespace llvm;

//Conceivably one could define the two major variants of LC3 here, so you get
//both the LC3 compiler and LC3b. I'm just focusing on LC3b at the moment

extern "C" void LLVMInitializeLC3bTarget() {
  // Register the target.
  RegisterTargetMachine<LC3bV8TargetMachine> X(TheLC3bTarget);

//  This looks like elf stuff, that lc3 doesn't (yet) deal with
//  RegisterAsmInfo<LC3bELFMCAsmInfo> A(TheLC3bTarget);

}

/// LC3bTargetMachine ctor - Create an ILP32 architecture model
///
LC3bTargetMachine::LC3bTargetMachine(const Target &T, const std::string &TT, 
                                       const std::string &FS, bool is64bit)
  : LLVMTargetMachine(T, TT),
    DataLayout("e-p:16:16-a16:16"),
    TLInfo(*this), TSInfo(*this), InstrInfo(Subtarget)
    {
}

bool LC3bTargetMachine::addInstSelector(PassManagerBase &PM,
                                         CodeGenOpt::Level OptLevel) {
  PM.add(createLC3bISelDag(*this));
  return false;
}

/// addPreEmitPass - This pass may be implemented by targets that want to run
/// passes immediately before machine code is emitted.  This should return
/// true if -print-machineinstrs should print out the code after the passes.
bool LC3bTargetMachine::addPreEmitPass(PassManagerBase &PM,
                                        CodeGenOpt::Level OptLevel){
  return true;
}
