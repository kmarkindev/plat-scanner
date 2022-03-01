project(stb)

add_library(stb_image STATIC)

target_sources(stb_image PUBLIC
	stb_image.cpp
)

target_include_directories(stb_image PUBLIC include)