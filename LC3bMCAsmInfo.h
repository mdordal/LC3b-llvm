//=====-- LC3bMCAsmInfo.h - LC3b asm properties -------------*- C++ -*--====//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the LC3bMCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LC3BTARGETASMINFO_H
#define LC3BTARGETASMINFO_H

#include "llvm/ADT/StringRef.h"
#include "llvm/MC/MCAsmInfo.h"

namespace llvm {
  class Target;

  struct LC3bELFMCAsmInfo : public MCAsmInfo {
    explicit LC3bELFMCAsmInfo(const Target &T, StringRef TT);
  };

} // namespace llvm

#endif
