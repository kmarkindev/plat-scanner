cmake_minimum_required(VERSION 3.21)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "Cmake generation in source dir is not allowed. Make an out of source build instead.")
endif()

set(RUN_SUPERBUILD ON)
if(RUN_SUPERBUILD)
	include(cmake/superbuild.cmake)
	return()
endif()

project(plat-scanner LANGUAGES CXX)

include(cmake/externals_options.cmake)
set(CMAKE_PREFIX_PATH "${EXTERNALS_INSTALL_PREFIX}")

if(WIN32)
	add_executable(PlatScanner WIN32)
else()
	add_executable(PlatScanner superbuild/dummy.cpp)
endif()

#target_link_libraries(PlatScanner PUBLIC externals)
#add_dependencies(PlatScanner externals)
set_target_properties(PlatScanner PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED NO
	CXX_EXTENSIONS NO
	CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
	CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

add_subdirectory(Sources)

# wxWidgets doesn't know how to use CMAKE_PREFIX_PATH, so we need to tell it how
set(wxWidgets_ROOT_DIR ${CMAKE_PREFIX_PATH})
set(wxWidgets_LIB_DIR ${CMAKE_PREFIX_PATH}/lib)

find_package(wxWidgets 3.1 COMPONENTS core base REQUIRED)
#find_package(ICU 70.1 REQUIRED COMPONENTS uc)
find_package(nlohmann_json 3.10 CONFIG REQUIRED)
find_package(Tesseract 5.1 REQUIRED)
find_path(GLM_INCLUDE_DIRS "glm/glm.hpp" REQUIRED)
find_path(STB_INCLUDE_DIRS
	NAMES "stb_image.h" "stb_image_write.h" "stb_image_resize.h"
	REQUIRED
)

target_link_libraries(PlatScanner PUBLIC
	${wxWidgets_LIBRARIES}
	nlohmann_json::nlohmann_json
	${Tesseract_LIBRARIES}
)
target_include_directories(PlatScanner PUBLIC
	${wxWidgets_INCLUDE_DIRS}
	${Tesseract_INCLUDE_DIRS}
	${GLM_INCLUDE_DIRS}
	${STB_INCLUDE_DIRS}
)

# Copy Data folder to build location
add_custom_command(TARGET PlatScanner POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/Data/ $<TARGET_FILE_DIR:PlatScanner>/Data/)