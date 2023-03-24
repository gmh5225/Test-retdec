
  cmake_minimum_required(VERSION 3.0.2)
  
  project(LLVMX86Desc)

  set( SOURCE 
  X86AsmBackend.cpp
  X86MCTargetDesc.cpp
  X86MCAsmInfo.cpp
  X86MCCodeEmitter.cpp
  X86MachObjectWriter.cpp
  X86ELFObjectWriter.cpp
  X86WinCOFFObjectWriter.cpp
  X86WinCOFFStreamer.cpp
  X86WinCOFFTargetStreamer.cpp
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
  include_directories(${CMAKE_SOURCE_DIR}/LLVMTarget/X86)
  include_directories(../)
  include_directories(./)

  add_library(${PROJECT_NAME} STATIC ${SOURCE} )

  