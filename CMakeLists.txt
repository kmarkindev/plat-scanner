cmake_minimum_required(VERSION 3.21)

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

add_subdirectory(Sources)

# wxWidgets doesn't know how to use CMAKE_PREFIX_PATH, so we need to tell it how
set(wxWidgets_ROOT_DIR ${CMAKE_PREFIX_PATH})
set(wxWidgets_LIB_DIR ${CMAKE_PREFIX_PATH}/lib)

find_package(ICU 70.1 REQUIRED COMPONENTS uc)
find_package(wxWidgets 3.1 COMPONENTS core base REQUIRED)
find_package(nlohmann_json 3.10 CONFIG REQUIRED)
find_package(Tesseract 5.1 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED) #0.9.9.8
find_path(STB_INCLUDE_DIRS "stb.h")

target_link_libraries(PlatScanner PUBLIC
	${wxWidgets_LIBRARIES}
	nlohmann_json::nlohmann_json
	libtesseract
	glm::glm
	ICU::uc
)
target_include_directories(PlatScanner PUBLIC
	${wxWidgets_INCLUDE_DIRS}
	${GLM_INCLUDE_DIRS}
	${STB_INCLUDE_DIRS}
)

# Copy Data folder to build location1
add_custom_command(TARGET PlatScanner POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/Data/ $<TARGET_FILE_DIR:PlatScanner>/Data/)