
  cmake_minimum_required(VERSION 3.0.2)
  
  project(LLVMGlobalISel)

  set( SOURCE 
  CSEInfo.cpp
        CSEMIRBuilder.cpp
        CallLowering.cpp
        GlobalISel.cpp
        Combiner.cpp
        CombinerHelper.cpp
        GISelChangeObserver.cpp
        IRTranslator.cpp
        InstructionSelect.cpp
        InstructionSelector.cpp
        LegalityPredicates.cpp
        LegalizeMutations.cpp
        Legalizer.cpp
        LegalizerHelper.cpp
        LegalizerInfo.cpp
        Localizer.cpp
        MachineIRBuilder.cpp
        RegBankSelect.cpp
        RegisterBank.cpp
        RegisterBankInfo.cpp
        Utils.cpp
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

  