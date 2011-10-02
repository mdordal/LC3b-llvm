//===- LC3bCallingConv.td - Calling Conventions LC3b -----*- tablegen -*-===//
// 
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
// 
//===----------------------------------------------------------------------===//
//
// This describes the calling conventions for the LC3b architectures.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Return Value Calling Conventions
//===----------------------------------------------------------------------===//

// LC3b 16-bit C return-value convention.
def RetCC_LC3b16 : CallingConv<[
  CCIfType<[i16], CCAssignToReg<[R0, R1, R2, R3]>>
  ]>;

// LC3b 32-bit C Calling convention.
def CC_LC3b16 : CallingConv<[
  // FIXME: maybe we need floating point somehow?
  // i16 arguments get passed in integer registers if there is space.
  CCIfType<[i16], CCAssignToReg<[R0, R1, R2, R3]>>,

  // strictly speaking, will this ever get hit? I think there's only i16...
  // Alternatively, they are assigned to the stack in 2-byte aligned units.
  CCAssignToStack<2, 2>
  ]  >;
