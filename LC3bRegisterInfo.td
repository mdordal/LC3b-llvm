//===- LC3bRegisterInfo.td - LC3b Register defs ----------*- tablegen -*-===//
// 
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
// 
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the LC3b register file 
//===----------------------------------------------------------------------===//

class LC3bReg<string n> : Register<n> {
  field bits<3> Num;
  let Namespace = "LC3";
}

class LC3bCtrlReg<string n>: Register<n> {
  let Namespace = "LC3";
}

// Registers are identified with 3-bit ID numbers.
// Ri - 16-bit integer registers
class Ri<bits<3> num, string n> : LC3bReg<n> {
  let Num = num;
}

// FIXME: what are these!// Control Registers
//def ICC : LC3bCtrlReg<"ICC">;
//
//// Y register
//def Y : LC3bCtrlReg<"Y">;

// Integer registers
def R0 : Ri< 0, "R0">, DwarfRegNum<[0]>;
def R1 : Ri< 1, "R1">, DwarfRegNum<[1]>;
def R2 : Ri< 2, "R2">, DwarfRegNum<[2]>; 
def R3 : Ri< 3, "R3">, DwarfRegNum<[3]>;
def R4 : Ri< 4, "R4">, DwarfRegNum<[4]>;
def R5 : Ri< 5, "R5">, DwarfRegNum<[5]>; 
def R6 : Ri< 6, "R6">, DwarfRegNum<[6]>;
def R7 : Ri< 7, "R7">, DwarfRegNum<[7]>;

// Register classes.
//
// FIXME: the register order should be defined in terms of the preferred
// allocation order...
//
def IntRegs : RegisterClass<"LC3", [i16], 16, [
                                     R0, R1, R2, R3, R4, R5,
                                     R6, // stack ptr
                                     R7 // return address
                                     ]> {
  let MethodProtos = [{
    iterator allocation_order_end(const MachineFunction &MF) const;
  }];
  let MethodBodies = [{
    IntRegsClass::iterator
    IntRegsClass::allocation_order_end(const MachineFunction &MF) const {
      // FIXME: These special regs should be taken out of the regclass!
      return end() - 2; // FIXME: r6 and r7 should not be clobbered, I think
                        // unless I misunderstand how this is supposed to work
    }
  }];
}
