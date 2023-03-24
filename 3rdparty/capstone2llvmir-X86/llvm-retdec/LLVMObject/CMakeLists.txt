
cmake_minimum_required(VERSION 3.0.2)

project(LLVMObject)


set( SOURCE 
Archive.cpp
ArchiveWriter.cpp
Binary.cpp
COFFImportFile.cpp
COFFModuleDefinition.cpp
COFFObjectFile.cpp
Decompressor.cpp
ELF.cpp
ELFObjectFile.cpp
Error.cpp
IRObjectFile.cpp
IRSymtab.cpp
MachOObjectFile.cpp
MachOUniversal.cpp
ModuleSymbolTable.cpp
Object.cpp
ObjectFile.cpp
RecordStreamer.cpp
SymbolicFile.cpp
SymbolSize.cpp
WasmObjectFile.cpp
WindowsResource.cpp
  

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

target_link_libraries(${PROJECT_NAME} LLVMMC)
target_link_libraries(${PROJECT_NAME} LLVMMCParser)