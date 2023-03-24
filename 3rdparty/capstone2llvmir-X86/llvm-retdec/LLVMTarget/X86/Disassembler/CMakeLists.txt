
  cmake_minimum_required(VERSION 3.0.2)
  
  project(LLVMX86Disassembler)

  set( SOURCE 
  X86Disassembler.cpp
  X86DisassemblerDecoder.cpp
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

  