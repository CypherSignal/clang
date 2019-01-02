//===--- WDC65816.cpp - Implement WDC65816 target feature support -------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements WDC65816 TargetInfo objects.
//
//===----------------------------------------------------------------------===//

#include "WDC65816.h"
#include "clang/Basic/MacroBuilder.h"

using namespace clang;
using namespace clang::targets;

const char *const WDC65816TargetInfo::GCCRegNames[] = {
    "r0", "r1", "r2",  "r3",  "r4",  "r5",  "r6",  "r7",
    "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
};

ArrayRef<const char *> WDC65816TargetInfo::getGCCRegNames() const {
  return llvm::makeArrayRef(GCCRegNames);
}

void WDC65816TargetInfo::getTargetDefines(const LangOptions &Opts,
                                        MacroBuilder &Builder) const {
  Builder.defineMacro("WDC65816");
  Builder.defineMacro("__WDC65816__");
  // FIXME: defines for different 'flavours' of MCU
}
