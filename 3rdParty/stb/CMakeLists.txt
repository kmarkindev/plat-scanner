project(stb)

add_library(stb STATIC)

target_sources(stb PUBLIC
	stb_impl.cpp
)

target_include_directories(stb PUBLIC include)