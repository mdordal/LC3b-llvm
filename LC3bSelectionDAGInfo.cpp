//===-- LC3bSelectionDAGInfo.cpp - LC3b SelectionDAG Info ---------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the LC3bSelectionDAGInfo class.
//
//===----------------------------------------------------------------------===//

#define DEBUG_TYPE "lc3b-selectiondag-info"
#include "LC3bTargetMachine.h"
using namespace llvm;

LC3bSelectionDAGInfo::LC3bSelectionDAGInfo(const LC3bTargetMachine &TM)
  : TargetSelectionDAGInfo(TM) {
}

LC3bSelectionDAGInfo::~LC3bSelectionDAGInfo() {
}
