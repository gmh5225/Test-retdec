
cmake_minimum_required(VERSION 3.0.2)

project(LLVMProfileData)


set( SOURCE 
  GCOV.cpp
  InstrProf.cpp
  InstrProfReader.cpp
  InstrProfWriter.cpp
  ProfileSummaryBuilder.cpp
  SampleProf.cpp
  SampleProfReader.cpp
  SampleProfWriter.cpp
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
include_directories(${CMAKE_SOURCE_DIR}/include/ProfileData)

add_library(${PROJECT_NAME} STATIC ${SOURCE} )

add_subdirectory(Coverage)
set_target_properties(LLVMCoverage PROPERTIES FOLDER "ProfileData")
