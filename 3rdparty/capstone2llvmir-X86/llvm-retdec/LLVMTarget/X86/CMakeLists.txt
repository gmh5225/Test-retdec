
cmake_minimum_required(VERSION 3.0.2)

project(LLVMX86CodeGen)


set( SOURCE 
ShadowCallStack.cpp
 X86AsmPrinter.cpp
 X86CallFrameOptimization.cpp
 X86CallingConv.cpp
 X86CallLowering.cpp
 X86CmovConversion.cpp
 X86CondBrFolding.cpp
 X86DomainReassignment.cpp
 X86DiscriminateMemOps.cpp
 X86ExpandPseudo.cpp
 X86FastISel.cpp
 X86FixupBWInsts.cpp
 X86FixupLEAs.cpp
 X86AvoidStoreForwardingBlocks.cpp
 X86FixupSetCC.cpp
 X86FlagsCopyLowering.cpp
 X86FloatingPoint.cpp
 X86FrameLowering.cpp
 X86InstructionSelector.cpp
 X86ISelDAGToDAG.cpp
 X86ISelLowering.cpp
 X86IndirectBranchTracking.cpp
 X86InterleavedAccess.cpp
 X86InsertPrefetch.cpp
 X86InstrFMA3Info.cpp
 X86InstrFoldTables.cpp
 X86InstrInfo.cpp
 X86EvexToVex.cpp
 X86LegalizerInfo.cpp
 X86MCInstLower.cpp
 X86MachineFunctionInfo.cpp
 X86MacroFusion.cpp
 X86OptimizeLEAs.cpp
 X86PadShortFunction.cpp
 X86RegisterBankInfo.cpp
 X86RegisterInfo.cpp
 X86RetpolineThunks.cpp
 X86SelectionDAGInfo.cpp
 X86ShuffleDecodeConstantPool.cpp
 X86SpeculativeLoadHardening.cpp
 X86Subtarget.cpp
 X86TargetMachine.cpp
 X86TargetObjectFile.cpp
 X86TargetTransformInfo.cpp
 X86VZeroUpper.cpp
 X86WinAllocaExpander.cpp
 X86WinEHState.cpp
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

# X86 backend
add_subdirectory(AsmParser)
set_target_properties(LLVMX86AsmParser PROPERTIES FOLDER "X86")

add_subdirectory(Disassembler)
set_target_properties(LLVMX86Disassembler PROPERTIES FOLDER "X86")

add_subdirectory(InstPrinter)
set_target_properties(LLVMX86AsmPrinter PROPERTIES FOLDER "X86")

add_subdirectory(MCTargetDesc)
set_target_properties(LLVMX86Desc PROPERTIES FOLDER "X86")

add_subdirectory(TargetInfo)
set_target_properties(LLVMX86Info PROPERTIES FOLDER "X86")

add_subdirectory(Utils)
set_target_properties(LLVMX86Utils PROPERTIES FOLDER "X86")


target_link_libraries(${PROJECT_NAME} LLVMX86AsmParser)
target_link_libraries(${PROJECT_NAME} LLVMX86Disassembler)
target_link_libraries(${PROJECT_NAME} LLVMX86AsmPrinter)
target_link_libraries(${PROJECT_NAME} LLVMX86Desc)
target_link_libraries(${PROJECT_NAME} LLVMX86Info)
target_link_libraries(${PROJECT_NAME} LLVMX86Utils)
