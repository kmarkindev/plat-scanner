cmake_minimum_required(VERSION 3.18)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "Cmake generation in source dir is not allowed. Make an out of source build instead.")
endif()

project(plat-scanner)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if(WIN32)
	add_executable(PlatScanner WIN32)
else()
	add_executable(PlatScanner)
endif()

add_subdirectory(3rdParty)
add_subdirectory(Sources)

target_link_libraries(PlatScanner PUBLIC
	stb
	libtesseract
	wx::core
	wx::base
)

# tesseract generates version.h header
# we need to include it
get_target_property(TESSERACT_BINARY_DIR libtesseract BINARY_DIR)
target_include_directories(PlatScanner PUBLIC "${TESSERACT_BINARY_DIR}/include")

add_custom_command(TARGET PlatScanner POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/TessData/ $<TARGET_FILE_DIR:PlatScanner>/TessData/)