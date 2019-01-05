//===--- WDC65816.h - Declare WDC65816 target feature support -------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares WDC65816 TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_CLANG_LIB_BASIC_TARGETS_WDC65816_H
#define LLVM_CLANG_LIB_BASIC_TARGETS_WDC65816_H

#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "llvm/ADT/Triple.h"
#include "llvm/Support/Compiler.h"

namespace clang {
namespace targets {

class LLVM_LIBRARY_VISIBILITY WDC65816TargetInfo : public TargetInfo {
  static const char *const GCCRegNames[];

public:
  WDC65816TargetInfo(const llvm::Triple &Triple, const TargetOptions &)
      : TargetInfo(Triple) {
    TLSSupported = false;
    // WDC65816-TODO are these definitions correct? esp. IntMaxType?
    IntWidth = 16;
    IntAlign = 8;
    LongWidth = 32;
    LongLongWidth = 64;
    LongAlign = LongLongAlign = 8;
    PointerWidth = 16; // WDC65816-TODO will need to expand this
    PointerAlign = 8;
    SuitableAlign = 16;
    SizeType = UnsignedShort;
    IntMaxType = SignedLongLong;
    IntPtrType = SignedInt;
    PtrDiffType = SignedShort;
    SigAtomicType = SignedLong;
    resetDataLayout("e-p:16:8-i16:8-a:8-n8:16-S8");
  }
  void getTargetDefines(const LangOptions &Opts,
                        MacroBuilder &Builder) const override;

  ArrayRef<Builtin::Info> getTargetBuiltins() const override {
    // FIXME: Implement.
    return None;
  }

  bool hasFeature(StringRef Feature) const override {
    return Feature == "WDC65816";
  }

  ArrayRef<const char *> getGCCRegNames() const override;

  ArrayRef<TargetInfo::GCCRegAlias> getGCCRegAliases() const override {
    // No aliases.
    return None;
  }

  bool validateAsmConstraint(const char *&Name,
                             TargetInfo::ConstraintInfo &info) const override {
    // FIXME: implement
    // No target constraints for now.
    return false;
  }

  const char *getClobbers() const override {
    // FIXME: Is this really right?
    return "";
  }

  BuiltinVaListKind getBuiltinVaListKind() const override {
    // FIXME: implement
    return TargetInfo::CharPtrBuiltinVaList;
  }
};

} // namespace targets
} // namespace clang
#endif // LLVM_CLANG_LIB_BASIC_TARGETS_WDC65816_H
