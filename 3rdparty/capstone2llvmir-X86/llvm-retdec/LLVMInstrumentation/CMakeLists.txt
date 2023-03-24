
cmake_minimum_required(VERSION 3.0.2)

project(LLVMInstrumentation)


set( SOURCE 
AddressSanitizer.cpp
BoundsChecking.cpp
CGProfile.cpp
ControlHeightReduction.cpp
DataFlowSanitizer.cpp
GCOVProfiling.cpp
MemorySanitizer.cpp
IndirectCallPromotion.cpp
Instrumentation.cpp
InstrProfiling.cpp
PGOInstrumentation.cpp
PGOMemOPSizeOpt.cpp
SanitizerCoverage.cpp
ThreadSanitizer.cpp
EfficiencySanitizer.cpp
HWAddressSanitizer.cpp
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

