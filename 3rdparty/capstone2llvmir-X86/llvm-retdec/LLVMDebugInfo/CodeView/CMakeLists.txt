
cmake_minimum_required(VERSION 3.0.2)

project(LLVMDebugInfoCodeView)


set( SOURCE 
AppendingTypeTableBuilder.cpp
  CodeViewError.cpp
  CodeViewRecordIO.cpp
  ContinuationRecordBuilder.cpp
  CVSymbolVisitor.cpp
  CVTypeVisitor.cpp
  DebugChecksumsSubsection.cpp
  DebugCrossExSubsection.cpp
  DebugCrossImpSubsection.cpp
  DebugFrameDataSubsection.cpp
  DebugInlineeLinesSubsection.cpp
  DebugLinesSubsection.cpp
  DebugStringTableSubsection.cpp
  DebugSubsection.cpp
  DebugSubsectionRecord.cpp
  DebugSubsectionVisitor.cpp
  DebugSymbolRVASubsection.cpp
  DebugSymbolsSubsection.cpp
  EnumTables.cpp
  Formatters.cpp
  GlobalTypeTableBuilder.cpp
  LazyRandomTypeCollection.cpp
  Line.cpp
  MergingTypeTableBuilder.cpp
  RecordName.cpp
  RecordSerialization.cpp
  SimpleTypeSerializer.cpp
  StringsAndChecksums.cpp
  SymbolDumper.cpp
  SymbolRecordHelpers.cpp
  SymbolRecordMapping.cpp
  SymbolSerializer.cpp
  TypeDumpVisitor.cpp
  TypeIndex.cpp
  TypeIndexDiscovery.cpp
  TypeHashing.cpp
  TypeRecordHelpers.cpp
  TypeRecordMapping.cpp
  TypeStreamMerger.cpp
  TypeTableCollection.cpp

  

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
include_directories(${CMAKE_SOURCE_DIR}/include/DebugInfo/CodeView)

add_library(${PROJECT_NAME} STATIC ${SOURCE} )
