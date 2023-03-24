
cmake_minimum_required(VERSION 3.0.2)

project(LLVMBinaryFormat)


set( SOURCE 

AMDGPUMetadataVerifier.cpp
Dwarf.cpp
Magic.cpp
MsgPackReader.cpp
MsgPackTypes.cpp
MsgPackWriter.cpp
Wasm.cpp

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

