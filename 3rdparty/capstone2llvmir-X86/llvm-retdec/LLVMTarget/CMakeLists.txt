
cmake_minimum_required(VERSION 3.0.2)

project(LLVMTarget)


set( SOURCE 
Target.cpp
TargetIntrinsicInfo.cpp
TargetLoweringObjectFile.cpp
TargetMachine.cpp
TargetMachineC.cpp

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

#X86 backend
add_subdirectory(X86)
set_target_properties(LLVMX86CodeGen PROPERTIES FOLDER "X86")

target_link_libraries(${PROJECT_NAME} LLVMCodeGen)
target_link_libraries(${PROJECT_NAME} LLVMProfileData)
target_link_libraries(${PROJECT_NAME} LLVMX86CodeGen)
