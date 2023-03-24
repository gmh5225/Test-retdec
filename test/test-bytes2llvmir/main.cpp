
#include <stdio.h>

#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Transforms/IPO.h>
#include <llvm/Transforms/IPO/ForceFunctionAttrs.h>
#include <llvm/Transforms/IPO/FunctionAttrs.h>
#include <llvm/Transforms/IPO/InferFunctionAttrs.h>
#include <llvm/Transforms/IPO/PassManagerBuilder.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/InstSimplifyPass.h>
#include <llvm/Transforms/Utils.h>

#include <llvm/Analysis/GlobalsModRef.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>

#include "retdec/common/address.h"
#include "retdec/utils/conversion.h"
#include "retdec/utils/io/log.h"
#include "retdec/utils/string.h"
#include <llvm/CodeGen/CommandFlags.inc>
#include <llvm/IR/Module.h>
#include <llvm/Support/CodeGen.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/ToolOutputFile.h>
#include <llvm/Support/raw_ostream.h>

#include <llvm/Object/COFF.h>

#include <llvm/Target/TargetMachine.h>

#include "retdec/capstone2llvmir/capstone2llvmir.h"

// add byte ptr [0x12345678], 0x11
// add byte ptr [0x00401000], 0xBB
auto CODE = retdec::utils::hexStringToBytes("80 05 78 56 34 12 11 80 05 00 10 40 00 BB");

// je xx
// jne xx
auto CODE2 = retdec::utils::hexStringToBytes("74 00 75 FC");

using namespace retdec::utils::io;
using namespace retdec::capstone2llvmir;

int
main()
{
    system("pause");
    return 0;
}
