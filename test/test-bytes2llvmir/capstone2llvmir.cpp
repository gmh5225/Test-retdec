#include <stdio.h>

#include <gtest/gtest.h>

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

using namespace retdec::utils::io;
using namespace retdec::capstone2llvmir;

TEST(capstone2llvmir, test_1)
{
    // XOR EAX,EAX
    // RET
    auto CODE = retdec::utils::hexStringToBytes("33 C0 C3");

    llvm::LLVMContext ctx;
    llvm::Module module("capstone2llvmir_test_1", ctx);

    auto *f = llvm::Function::Create(
        llvm::FunctionType::get(llvm::Type::getVoidTy(ctx), false),
        llvm::GlobalValue::ExternalLinkage,
        "test_1",
        &module);
    llvm::BasicBlock::Create(module.getContext(), "entry", f);
    llvm::IRBuilder<> irb(&f->front());

    auto *ret = irb.CreateRetVoid();
    irb.SetInsertPoint(ret);

    try
    {
        auto BASEADDR = 0x41F000;
        // create arch (capstone)
        auto c2l = Capstone2LlvmIrTranslator::createArch(CS_ARCH_X86, &module, CS_MODE_64, CS_MODE_LITTLE_ENDIAN);
        c2l->translate(CODE.data(), CODE.size(), BASEADDR, irb, 0, false, false);
    }
    catch (const BaseError &e)
    {
        Log::error() << e.what() << std::endl;
        assert(false);
    }
    catch (...)
    {
        Log::error() << "Some unhandled exception" << std::endl;
    }

    for (auto &F : module)
    {
        // filter declaration
        if (F.isDeclaration())
        {
            continue;
        }

        auto FuncName = std::string(F.getName());
        std::cout << "FuncName=" << FuncName << std::endl;
    }

    std::error_code ec;
    llvm::raw_fd_ostream out(SRC_DIR "/sample/capstone2llvmir_test_1.ll", ec, llvm::sys::fs::F_None);
    module.print(out, nullptr);
}