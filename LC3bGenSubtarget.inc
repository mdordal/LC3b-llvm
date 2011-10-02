//===- TableGen'erated file -------------------------------------*- C++ -*-===//
//
// Subtarget Enumeration Source Fragment
//
// Automatically generated file, do not edit!
//
//===----------------------------------------------------------------------===//

#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/SubtargetFeature.h"
#include "llvm/Target/TargetInstrItineraries.h"

enum {
  FeatureV8Deprecated =  1ULL << 0,
  FeatureV9 =  1ULL << 1,
  FeatureVIS =  1ULL << 2
};

// Sorted (by key) array of values for CPU features.
static const llvm::SubtargetFeatureKV FeatureKV[] = {
  { "deprecated-v8", "Enable deprecated V8 instructions in V9 mode", FeatureV8Deprecated, 0ULL },
  { "v9", "Enable LC3B-V9 instructions", FeatureV9, 0ULL },
  { "vis", "Enable UltraLC3B Visual Instruction Set extensions", FeatureVIS, 0ULL }
};

enum {
  FeatureKVSize = sizeof(FeatureKV)/sizeof(llvm::SubtargetFeatureKV)
};

// Sorted (by key) array of values for CPU subtype.
static const llvm::SubtargetFeatureKV SubTypeKV[] = {
  { "f934", "Select the f934 processor", 0ULL, 0ULL },
  { "generic", "Select the generic processor", 0ULL, 0ULL },
  { "hyperlc3b", "Select the hyperlc3b processor", 0ULL, 0ULL },
  { "lc3blet", "Select the lc3blet processor", 0ULL, 0ULL },
  { "lc3blite", "Select the lc3blite processor", 0ULL, 0ULL },
  { "lc3blite86x", "Select the lc3blite86x processor", 0ULL, 0ULL },
  { "superlc3b", "Select the superlc3b processor", 0ULL, 0ULL },
  { "tsc701", "Select the tsc701 processor", 0ULL, 0ULL },
  { "ultralc3b", "Select the ultralc3b processor", FeatureV9 | FeatureV8Deprecated, 0ULL },
  { "ultralc3b3", "Select the ultralc3b3 processor", FeatureV9 | FeatureV8Deprecated, 0ULL },
  { "ultralc3b3-vis", "Select the ultralc3b3-vis processor", FeatureV9 | FeatureV8Deprecated | FeatureVIS, 0ULL },
  { "v8", "Select the v8 processor", 0ULL, 0ULL },
  { "v9", "Select the v9 processor", FeatureV9, 0ULL }
};

enum {
  SubTypeKVSize = sizeof(SubTypeKV)/sizeof(llvm::SubtargetFeatureKV)
};


enum {
  ItinClassesSize = 1
};

// ParseSubtargetFeatures - Parses features string setting specified
// subtarget options.
std::string llvm::LC3bSubtarget::ParseSubtargetFeatures(const std::string &FS,
                                  const std::string &CPU) {
  DEBUG(dbgs() << "\nFeatures:" << FS);
  DEBUG(dbgs() << "\nCPU:" << CPU);
  SubtargetFeatures Features(FS);
  Features.setCPUIfNone(CPU);
  uint64_t Bits =  Features.getBits(SubTypeKV, SubTypeKVSize,
                                    FeatureKV, FeatureKVSize);
  if ((Bits & FeatureV8Deprecated) != 0) V8DeprecatedInsts = true;
  if ((Bits & FeatureV9) != 0) IsV9 = true;
  if ((Bits & FeatureVIS) != 0) IsVIS = true;
  return Features.getCPU();
}
