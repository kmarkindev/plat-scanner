add_subdirectory(ImageProcessors)
add_subdirectory(RelicDatabase)

target_sources(PlatScanner PUBLIC
	ImageScanner.cpp
	ImageScanner.h
	ImageWriter.cpp
	ImageWriter.h
	ImageReader.cpp
	ImageReader.h
	ScreenshotTaker.cpp
	ScreenshotTaker.h
	RelicPartPositionsFinder.cpp
	RelicPartPositionsFinder.h
	RelicScanner.cpp
	RelicScanner.h
	WarframeMarketApi.cpp
	WarframeMarketApi.h
	HttpClient.cpp
	HttpClient.h
	ItemOrdersJsonParser.cpp
	ItemOrdersJsonParser.h
	ItemOrdersFilter.cpp
	ItemOrdersFilter.h
	BestPricesFinder.cpp
	BestPricesFinder.h
)