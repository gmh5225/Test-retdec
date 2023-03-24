
  cmake_minimum_required(VERSION 3.0.2)
  
  project(LLVMSelectionDAG)

  set( SOURCE 
    DAGCombiner.cpp
  FastISel.cpp
  FunctionLoweringInfo.cpp
  InstrEmitter.cpp
  LegalizeDAG.cpp
  LegalizeFloatTypes.cpp
  LegalizeIntegerTypes.cpp
  LegalizeTypes.cpp
  LegalizeTypesGeneric.cpp
  LegalizeVectorOps.cpp
  LegalizeVectorTypes.cpp
  ResourcePriorityQueue.cpp
  ScheduleDAGFast.cpp
  ScheduleDAGRRList.cpp
  ScheduleDAGSDNodes.cpp
  ScheduleDAGVLIW.cpp
  SelectionDAGBuilder.cpp
  SelectionDAG.cpp
  SelectionDAGAddressAnalysis.cpp
  SelectionDAGDumper.cpp
  SelectionDAGISel.cpp
  SelectionDAGPrinter.cpp
  SelectionDAGTargetInfo.cpp
  StatepointLowering.cpp
  TargetLowering.cpp
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

  add_library(${PROJECT_NAME} STATIC ${SOURCE} )

  