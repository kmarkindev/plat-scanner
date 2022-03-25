cmake_minimum_required(VERSION 3.21)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "Cmake generation in source dir is not allowed. Make an out of source build instead.")
endif()

project(plat-scanner LANGUAGES CXX)

# Setup conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Setup plat-scanner target
if(WIN32)
	# wxWidgets wants to use WinMain entry point when running on Windows
	add_executable(PlatScanner WIN32)
else()
	add_executable(PlatScanner Sources/Services/HttpClient.cpp Sources/Services/HttpClient.h Sources/Models/HttpResponse.cpp Sources/Models/HttpResponse.h Sources/Models/HttpRequest.cpp Sources/Models/HttpRequest.h)
endif()
set_target_properties(PlatScanner PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED NO
	CXX_EXTENSIONS NO
	CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plat-scanner-bin"
)

add_subdirectory(Sources)

target_link_libraries(PlatScanner PUBLIC ${CONAN_LIBS})

# Copy Data folder to build location
add_custom_command(TARGET PlatScanner POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_SOURCE_DIR}/Data/ $<TARGET_FILE_DIR:PlatScanner>/data/)