# This file is automatically generated from cmake.toml - DO NOT EDIT
# See https://github.com/build-cpp/cmkr for more information

# Create a configure-time dependency on cmake.toml to improve IDE support
if(CMKR_ROOT_PROJECT)
	configure_file(cmake.toml cmake.toml COPYONLY)
endif()

# Target retdec-common
set(CMKR_TARGET retdec-common)
set(retdec-common_SOURCES "")

list(APPEND retdec-common_SOURCES
	address.cpp
	architecture.cpp
	basic_block.cpp
	calling_convention.cpp
	class.cpp
	file_format.cpp
	file_type.cpp
	function.cpp
	language.cpp
	object.cpp
	pattern.cpp
	storage.cpp
	tool_info.cpp
	type.cpp
	vtable.cpp
)

list(APPEND retdec-common_SOURCES
	cmake.toml
)

set(CMKR_SOURCES ${retdec-common_SOURCES})
add_library(retdec-common STATIC)

if(retdec-common_SOURCES)
	target_sources(retdec-common PRIVATE ${retdec-common_SOURCES})
endif()

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${retdec-common_SOURCES})

target_compile_features(retdec-common PUBLIC
	cxx_std_20
)

target_include_directories(retdec-common PUBLIC
	"../include"
	"../include/retdec"
	"../include/whereami"
)

target_link_libraries(retdec-common PUBLIC
	retdec-utils
)

unset(CMKR_TARGET)
unset(CMKR_SOURCES)

