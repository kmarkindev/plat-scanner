add_subdirectory(ImageProcessors)

target_sources(PlatScanner PUBLIC
	ImageScanner.cpp
	ImageScanner.h
	ImageWriter.cpp
	ImageWriter.h
	ImageReader.cpp
	ImageReader.h
)