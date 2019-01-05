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
    "a", "b", "c", "dbr", "d", "k", "pc", "p", "sh", "sl",
    "s", "xl", "xh", "x", "yl", "yh", "y"
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
