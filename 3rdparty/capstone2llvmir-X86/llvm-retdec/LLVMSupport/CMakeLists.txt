
cmake_minimum_required(VERSION 3.0.2)

project(LLVMSupport)


set( SOURCE 

  AArch64TargetParser.cpp
  ARMTargetParser.cpp
  AMDGPUMetadata.cpp
  APFloat.cpp
  APInt.cpp
  APSInt.cpp
  ARMBuildAttrs.cpp
  ARMAttributeParser.cpp
  ARMWinEH.cpp
  Allocator.cpp
  BinaryStreamError.cpp
  BinaryStreamReader.cpp
  BinaryStreamRef.cpp
  BinaryStreamWriter.cpp
  BlockFrequency.cpp
  BranchProbability.cpp
  BuryPointer.cpp
  CachePruning.cpp
  circular_raw_ostream.cpp
  Chrono.cpp
  COM.cpp
  CodeGenCoverage.cpp
  CommandLine.cpp
  Compression.cpp
  ConvertUTF.cpp
  ConvertUTFWrapper.cpp
  CrashRecoveryContext.cpp
  DataExtractor.cpp
  Debug.cpp
  DebugCounter.cpp
  DeltaAlgorithm.cpp
  DAGDeltaAlgorithm.cpp
  DJB.cpp
  Error.cpp
  ErrorHandling.cpp
  FileCheck.cpp
  FileUtilities.cpp
  FileOutputBuffer.cpp
  FoldingSet.cpp
  FormattedStream.cpp
  FormatVariadic.cpp
  GlobPattern.cpp
  GraphWriter.cpp
  Hashing.cpp
  InitLLVM.cpp
  IntEqClasses.cpp
  IntervalMap.cpp
  JamCRC.cpp
  JSON.cpp
  KnownBits.cpp
  LEB128.cpp
  LineIterator.cpp
  Locale.cpp
  LockFileManager.cpp
  LowLevelType.cpp
  ManagedStatic.cpp
  MathExtras.cpp
  MemoryBuffer.cpp
  MD5.cpp
  NativeFormatting.cpp
  Options.cpp
  Parallel.cpp
  PluginLoader.cpp
  PrettyStackTrace.cpp
  RandomNumberGenerator.cpp
  Regex.cpp
  ScaledNumber.cpp
  ScopedPrinter.cpp
  SHA1.cpp
  SmallPtrSet.cpp
  SmallVector.cpp
  SourceMgr.cpp
  SpecialCaseList.cpp
  Statistic.cpp
  StringExtras.cpp
  StringMap.cpp
  StringPool.cpp
  StringSaver.cpp
  StringRef.cpp
  SystemUtils.cpp
  TarWriter.cpp
  TargetParser.cpp
  ThreadPool.cpp
  Timer.cpp
  ToolOutputFile.cpp
  TrigramIndex.cpp
  Triple.cpp
  Twine.cpp
  Unicode.cpp
  UnicodeCaseFold.cpp
  VersionTuple.cpp
  VirtualFileSystem.cpp
  WithColor.cpp
  YAMLParser.cpp
  YAMLTraits.cpp
  raw_os_ostream.cpp
  raw_ostream.cpp
  regcomp.c
  regerror.c
  regexec.c
  regfree.c
  regstrlcpy.c
  xxhash.cpp
  
  ItaniumManglingCanonicalizer.cpp
  SymbolRemappingReader.cpp
  
  # System
  Atomic.cpp
  DynamicLibrary.cpp
  Errno.cpp
  Host.cpp
  Memory.cpp
  Mutex.cpp
  Path.cpp
  Process.cpp
  Program.cpp
  RWMutex.cpp
  Signals.cpp
  TargetRegistry.cpp
  ThreadLocal.cpp
  Threading.cpp
  Valgrind.cpp
  Watchdog.cpp

  #hdr
  # Windows/COM.inc
  # Windows/DynamicLibrary.inc
  # Windows/explicit_symbols.inc
  # Windows/Host.inc
  # Windows/Memory.inc
  # Windows/Mutex.inc
  # Windows/Path.inc
  # Windows/Process.inc
  # Windows/Program.inc
  # Windows/RWMutex.inc
  # Windows/Signals.inc
  # Windows/Threading.inc
  # Windows/ThreadLocal.inc
  # Windows/Watchdog.inc
  # Windows/WindowsSupport.h

  #../include/llvm/Support/*.*
  #../include/llvm/ADT/*.*
  

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

target_link_libraries(${PROJECT_NAME} LLVMDemangle)
