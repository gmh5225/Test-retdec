
message("Cmake version: ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}")

cmake_minimum_required(VERSION 3.12)
option(ENABLE_GCOV "Enable gcov (Linux builds only)" OFF)

if (POLICY CMP0043)
  cmake_policy(SET CMP0043 OLD) # suppress cmp0043 warning triggered by cmake/config_module.cmake
endif(POLICY CMP0043)

project(llvm-retdec)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(CMAKE_CL_64)
set(MY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/64)
else(CMAKE_CL_64)
set(MY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib/32)
endif(CMAKE_CL_64)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${MY_OUTPUT_DIRECTORY})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${MY_OUTPUT_DIRECTORY})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${MY_OUTPUT_DIRECTORY})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(LLVMSupport)

add_subdirectory(LLVMCore)
set_target_properties(LLVMCore PROPERTIES FOLDER "IR")

add_subdirectory(LLVMBinaryFormat)

add_subdirectory(LLVMTransformsUtils)
set_target_properties(LLVMTransformsUtils PROPERTIES FOLDER "Transforms")

add_subdirectory(LLVMAnalysis)

add_subdirectory(LLVMIPO)
set_target_properties(LLVMIPO PROPERTIES FOLDER "Transforms")

add_subdirectory(LLVMAggressiveInstCombine)
set_target_properties(LLVMAggressiveInstCombine PROPERTIES FOLDER "Transforms")

add_subdirectory(LLVMInstCombine)
set_target_properties(LLVMInstCombine PROPERTIES FOLDER "Transforms")

add_subdirectory(LLVMScalar)
set_target_properties(LLVMScalarOpts PROPERTIES FOLDER "Transforms")

add_subdirectory(LLVMInstrumentation)
set_target_properties(LLVMInstrumentation PROPERTIES FOLDER "Transforms")

add_subdirectory(LLVMBitcodeReader)

add_subdirectory(LLVMBitcodeWriter)

add_subdirectory(LLVMObject)

add_subdirectory(LLVMIRReader)

add_subdirectory(LLVMMC)

add_subdirectory(LLVMAsmParser)

add_subdirectory(LLVMTarget)

add_subdirectory(LLVMCodeGen)


add_subdirectory(LLVMDebugInfo)

add_subdirectory(LLVMDemangle)

add_subdirectory(LLVMLinker)

add_subdirectory(LLVMProfileData)
set_target_properties(LLVMProfileData PROPERTIES FOLDER "ProfileData")

