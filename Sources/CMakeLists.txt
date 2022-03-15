target_include_directories(PlatScanner PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(Application)
add_subdirectory(Dto)
add_subdirectory(Services)

target_sources(PlatScanner PUBLIC
	StbImplementations.cpp
)