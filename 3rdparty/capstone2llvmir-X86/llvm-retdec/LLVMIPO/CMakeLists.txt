
cmake_minimum_required(VERSION 3.0.2)

project(LLVMIPO)


set( SOURCE 
AlwaysInliner.cpp
ArgumentPromotion.cpp
BarrierNoopPass.cpp
BlockExtractor.cpp
CalledValuePropagation.cpp
ConstantMerge.cpp
CrossDSOCFI.cpp
DeadArgumentElimination.cpp
ElimAvailExtern.cpp
ExtractGV.cpp
ForceFunctionAttrs.cpp
FunctionAttrs.cpp
FunctionImport.cpp
GlobalDCE.cpp
GlobalOpt.cpp
GlobalSplit.cpp
HotColdSplitting.cpp
IPConstantPropagation.cpp
IPO.cpp
InferFunctionAttrs.cpp
InlineSimple.cpp
Inliner.cpp
Internalize.cpp
LoopExtractor.cpp
LowerTypeTests.cpp
MergeFunctions.cpp
PartialInlining.cpp
PassManagerBuilder.cpp
PruneEH.cpp
#  SampleProfile.cpp
SCCP.cpp
StripDeadPrototypes.cpp
StripSymbols.cpp
SyntheticCountsPropagation.cpp
ThinLTOBitcodeWriter.cpp
WholeProgramDevirt.cpp

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


target_link_libraries(${PROJECT_NAME} LLVMAnalysis)
target_link_libraries(${PROJECT_NAME} LLVMIRReader)