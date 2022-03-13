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