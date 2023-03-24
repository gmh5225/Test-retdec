cmake_minimum_required(VERSION 3.0.2)

project( LLVMCore )

set( SOURCE 
  
  AsmWriter.cpp
  Attributes.cpp
  AutoUpgrade.cpp
  BasicBlock.cpp
  Comdat.cpp
  ConstantFold.cpp
  ConstantRange.cpp
  Constants.cpp
  Core.cpp
  DIBuilder.cpp
  DataLayout.cpp
  DebugInfo.cpp
  DebugInfoMetadata.cpp
  DebugLoc.cpp
  DiagnosticHandler.cpp
  DiagnosticInfo.cpp
  DiagnosticPrinter.cpp
  Dominators.cpp
  DomTreeUpdater.cpp
  Function.cpp
  GVMaterializer.cpp
  Globals.cpp
  IRBuilder.cpp
  IRPrintingPasses.cpp
  InlineAsm.cpp
  Instruction.cpp
  Instructions.cpp
  IntrinsicInst.cpp
  LLVMContext.cpp
  LLVMContextImpl.cpp
  LegacyPassManager.cpp
  MDBuilder.cpp
  Mangler.cpp
  Metadata.cpp
  Module.cpp
  ModuleSummaryIndex.cpp
  Operator.cpp
  OptBisect.cpp
  Pass.cpp
  PassInstrumentation.cpp
  PassManager.cpp
  PassRegistry.cpp
  PassTimingInfo.cpp
  SafepointIRVerifier.cpp
  ProfileSummary.cpp
  Statepoint.cpp
  Type.cpp
  TypeFinder.cpp
  Use.cpp
  User.cpp
  Value.cpp
  ValueSymbolTable.cpp
  Verifier.cpp

  AttributesCompatFunc.inc

  ../include/llvm/IR/Attributes.inc
  ../include/llvm/IR/IntrinsicImpl.inc
  ../include/llvm/IR/IntrinsicEnums.inc

  ../include/llvm/IR/Argument.h
  ../include/llvm/IR/AssemblyAnnotationWriter.h
  ../include/llvm/IR/AttributeImpl.h
  ../include/llvm/IR/Attributes.h
  ../include/llvm/IR/AutoUpgrade.h
  ../include/llvm/IR/BasicBlock.h
  ../include/llvm/IR/CallingConv.h
  ../include/llvm/IR/CallSite.h
  ../include/llvm/IR/CFG.h
  ../include/llvm/IR/CFGDiff.h
  ../include/llvm/IR/Comdat.h
  ../include/llvm/IR/Constant.h
  ../include/llvm/IR/ConstantFold.h
  ../include/llvm/IR/ConstantFolder.h
  ../include/llvm/IR/ConstantRange.h
  ../include/llvm/IR/Constants.h
  ../include/llvm/IR/ConstantsContext.h
  ../include/llvm/IR/DataLayout.h
  ../include/llvm/IR/DebugInfo.h
  ../include/llvm/IR/DebugInfoMetadata.h
  ../include/llvm/IR/DebugLoc.h
  ../include/llvm/IR/DerivedTypes.h
  ../include/llvm/IR/DerivedUser.h
  ../include/llvm/IR/DiagnosticHandler.h
  ../include/llvm/IR/DiagnosticInfo.h
  ../include/llvm/IR/DiagnosticPrinter.h
  ../include/llvm/IR/DIBuilder.h
  ../include/llvm/IR/Dominators.h
  ../include/llvm/IR/DomTreeUpdater.h
  ../include/llvm/IR/Function.h
  ../include/llvm/IR/GetElementPtrTypeIterator.h
  ../include/llvm/IR/GlobalAlias.h
  ../include/llvm/IR/GlobalIFunc.h
  ../include/llvm/IR/GlobalIndirectSymbol.h
  ../include/llvm/IR/GlobalObject.h
  ../include/llvm/IR/GlobalValue.h
  ../include/llvm/IR/GlobalVariable.h
  ../include/llvm/IR/GVMaterializer.h
  ../include/llvm/IR/InlineAsm.h
  ../include/llvm/IR/InstIterator.h
  ../include/llvm/IR/InstrTypes.h
  ../include/llvm/IR/Instruction.h
  ../include/llvm/IR/Instructions.h
  ../include/llvm/IR/InstVisitor.h
  ../include/llvm/IR/IntrinsicInst.h
  ../include/llvm/IR/Intrinsics.h
  ../include/llvm/IR/IRBuilder.h
  ../include/llvm/IR/IRPrintingPasses.h
  ../include/llvm/IR/LegacyPassManager.h
  ../include/llvm/IR/LegacyPassManagers.h
  ../include/llvm/IR/LegacyPassNameParser.h
  ../include/llvm/IR/LLVMContext.h
  ../include/llvm/IR/LLVMContextImpl.h
  ../include/llvm/IR/Mangler.h
  ../include/llvm/IR/MDBuilder.h
  ../include/llvm/IR/Metadata.h
  ../include/llvm/IR/MetadataImpl.h
  ../include/llvm/IR/Module.h
  ../include/llvm/IR/ModuleSummaryIndex.h
  ../include/llvm/IR/ModuleSummaryIndexYAML.h
  ../include/llvm/IR/NoFolder.h
  ../include/llvm/IR/OperandTraits.h
  ../include/llvm/IR/Operator.h
  ../include/llvm/IR/OptBisect.h
  ../include/llvm/IR/PassInstrumentation.h
  ../include/llvm/IR/PassManager.h
  ../include/llvm/IR/PassManagerInternal.h
  ../include/llvm/IR/PassTimingInfo.h
  ../include/llvm/IR/PatternMatch.h
  ../include/llvm/IR/PredIteratorCache.h
  ../include/llvm/IR/ProfileSummary.h
  ../include/llvm/IR/SafepointIRVerifier.h
  ../include/llvm/IR/Statepoint.h
  ../include/llvm/IR/SymbolTableListTraits.h
  ../include/llvm/IR/SymbolTableListTraitsImpl.h
  ../include/llvm/IR/TrackingMDRef.h
  ../include/llvm/IR/Type.h
  ../include/llvm/IR/TypeFinder.h
  ../include/llvm/IR/Use.h
  ../include/llvm/IR/UseListOrder.h
  ../include/llvm/IR/User.h
  ../include/llvm/IR/Value.h
  ../include/llvm/IR/ValueHandle.h
  ../include/llvm/IR/ValueMap.h
  ../include/llvm/IR/ValueSymbolTable.h
  ../include/llvm/IR/Verifier.h


)


#set win32/win64
if(MSVC)
if(CMAKE_CL_64)
add_definitions(-DWIN64)
else()
add_definitions(-DWIN32)
endif()
endif()

#include
include_directories(${CMAKE_SOURCE_DIR}/include)


add_library(${PROJECT_NAME} STATIC ${SOURCE} )

target_link_libraries(${PROJECT_NAME} LLVMSupport)
target_link_libraries(${PROJECT_NAME} LLVMBinaryFormat)


