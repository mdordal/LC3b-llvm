//===-- LC3bTargetInfo.cpp - LC3b Target Implementation -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "LC3b.h"
#include "llvm/Module.h"
#include "llvm/Target/TargetRegistry.h"
using namespace llvm;

Target llvm::TheLC3bTarget;
Target llvm::TheLC3bV9Target;

extern "C" void LLVMInitializeLC3bTargetInfo() { 
  RegisterTarget<Triple::lc3b> X(TheLC3bTarget, "lc3b", "LC3b");
  RegisterTarget<Triple::lc3bv9> Y(TheLC3bV9Target, "lc3bv9", "LC3b V9");
}
