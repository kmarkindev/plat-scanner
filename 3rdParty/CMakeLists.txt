add_subdirectory(tesseract)
add_subdirectory(stb)

set(wxBUILD_SAMPLES OFF)
set(wxBUILD_TESTS OFF)
set(wxBUILD_DEMOS OFF)
set(wxBUILD_BENCHMARKS OFF)
set(wxBUILD_MONOLITHIC OFF)
set(wxBUILD_SHARED OFF)
add_subdirectory(wxWidgets)

add_subdirectory(glm)

add_subdirectory(json)

#need to config fuzzywyzzy manually
#because it uses old cmake versions of functions
add_library(fuzzywuzzy STATIC)
target_sources(fuzzywuzzy PUBLIC
	fuzzywuzzy/src/fuzzywuzzy.cpp
	fuzzywuzzy/src/levenshtein.c
	fuzzywuzzy/src/process.cpp
	fuzzywuzzy/src/string_matcher.cpp
	fuzzywuzzy/src/utils.cpp
	fuzzywuzzy/src/wrapper.cpp
)
target_include_directories(fuzzywuzzy PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/fuzzywuzzy/include")