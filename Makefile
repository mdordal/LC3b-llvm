##===- lib/Target/LC3b/Makefile ---------------------------*- Makefile -*-===##
#
#                     The LLVM Compiler Infrastructure
#
# This file is distributed under the University of Illinois Open Source
# License. See LICENSE.TXT for details.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../..
LIBRARYNAME = LLVMLC3bCodeGen
TARGET = LC3b

# Make sure that tblgen is run, first thing.
BUILT_SOURCES = LC3bGenRegisterInfo.h.inc LC3bGenRegisterNames.inc \
                LC3bGenRegisterInfo.inc LC3bGenInstrNames.inc \
                LC3bGenInstrInfo.inc LC3bGenAsmWriter.inc \
                LC3bGenDAGISel.inc LC3bGenSubtarget.inc LC3bGenCallingConv.inc

DIRS = TargetInfo

include $(LEVEL)/Makefile.common

