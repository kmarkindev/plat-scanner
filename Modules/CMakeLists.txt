target_sources(PlatScanner PUBLIC
	ImageTextRecognition.cpp
	ImageTextRecognition.h
	OptionPositionFinder.cpp
	OptionPositionFinder.h
)

target_include_directories(PlatScanner PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})