set(LLVM_TARGET_DEFINITIONS LC3b.td)

tablegen(LC3bGenRegisterInfo.h.inc -gen-register-desc-header)
tablegen(LC3bGenRegisterNames.inc -gen-register-enums)
tablegen(LC3bGenRegisterInfo.inc -gen-register-desc)
tablegen(LC3bGenInstrNames.inc -gen-instr-enums)
tablegen(LC3bGenInstrInfo.inc -gen-instr-desc)
tablegen(LC3bGenAsmWriter.inc -gen-asm-writer)
tablegen(LC3bGenDAGISel.inc -gen-dag-isel)
tablegen(LC3bGenSubtarget.inc -gen-subtarget)
tablegen(LC3bGenCallingConv.inc -gen-callingconv)

add_llvm_target(LC3bCodeGen
  DelaySlotFiller.cpp
  FPMover.cpp
  LC3bAsmPrinter.cpp
  LC3bInstrInfo.cpp
  LC3bISelDAGToDAG.cpp
  LC3bISelLowering.cpp
  LC3bFrameLowering.cpp
  LC3bMCAsmInfo.cpp
  LC3bRegisterInfo.cpp
  LC3bSubtarget.cpp
  LC3bTargetMachine.cpp
  LC3bSelectionDAGInfo.cpp
  )

add_subdirectory(TargetInfo)
