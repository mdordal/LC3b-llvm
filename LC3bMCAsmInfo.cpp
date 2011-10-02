//===-- LC3bMCAsmInfo.cpp - LC3b asm properties -------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declarations of the LC3bMCAsmInfo properties.
//
//===----------------------------------------------------------------------===//

#include "LC3bMCAsmInfo.h"
using namespace llvm;

LC3bELFMCAsmInfo::LC3bELFMCAsmInfo(const Target &T, StringRef TT) {
  Data16bitsDirective = "\t.half\t";
  Data32bitsDirective = "\t.word\t";
  Data64bitsDirective = 0;  // .xword is only supported by V9.
  ZeroDirective = "\t.skip\t";
  CommentString = "!";
  HasLEB128 = true;
  SupportsDebugInformation = true;
  
  SunStyleELFSectionSwitchSyntax = true;
  UsesELFSectionDirectiveForBSS = true;

  WeakRefDirective = "\t.weak\t";

  PrivateGlobalPrefix = ".L";
}


