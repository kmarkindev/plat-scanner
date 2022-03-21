project(superbuild)

include(ExternalProject)
include(cmake/externals_options.cmake)

execute_process(COMMAND ${CMAKE_SOURCE_DIR}/bin/win32/sw.exe setup)

# wxWidgets
ExternalProject_add(wxWidgets_external
	GIT_REPOSITORY "https://github.com/wxWidgets/wxWidgets.git"
	GIT_TAG "v3.1.5"
	TEST_COMMAND ""
	CMAKE_ARGS
		-DwxBUILD_SHARED=OFF
		-DwxUSE_UNICODE=ON
		-DCMAKE_INSTALL_PREFIX=${EXTERNALS_INSTALL_PREFIX}
		-DCMAKE_BUILD_TYPE=Release
	)

# nlohmann-json
ExternalProject_add(nlohmann_json_external
	GIT_REPOSITORY "https://github.com/nlohmann/json.git"
	GIT_TAG "v3.10.5"
	TEST_COMMAND ""
	CMAKE_ARGS
		-DCMAKE_INSTALL_PREFIX=${EXTERNALS_INSTALL_PREFIX}
		-DCMAKE_BUILD_TYPE=Release
	)

# stb
ExternalProject_add(stb_external
	GIT_REPOSITORY "https://github.com/nothings/stb.git"
	GIT_TAG "af1a5bc352164740c1cc1354942b1c6b72eacb8a"
	CONFIGURE_COMMAND ""
	BUILD_COMMAND ""
	INSTALL_COMMAND ""
	TEST_COMMAND ""
	COMMAND ${CMAKE_COMMAND} -E copy
		<SOURCE_DIR>/stb_image.h
		${EXTERNALS_INSTALL_PREFIX}/include/stb_image.h
	COMMAND ${CMAKE_COMMAND} -E copy
		<SOURCE_DIR>/stb_image_resize.h
		${EXTERNALS_INSTALL_PREFIX}/include/stb_image_resize.h
	COMMAND ${CMAKE_COMMAND} -E copy
		<SOURCE_DIR>/stb_image_write.h
		${EXTERNALS_INSTALL_PREFIX}/include/stb_image_write.h
	)

# glm
ExternalProject_add(glm_external
	GIT_REPOSITORY "https://github.com/g-truc/glm.git"
	GIT_TAG "0.9.9.8"
	CONFIGURE_COMMAND ""
	BUILD_COMMAND ""
	INSTALL_COMMAND ""
	TEST_COMMAND ""
	COMMAND ${CMAKE_COMMAND} -E copy_directory
		<SOURCE_DIR>/glm
		${EXTERNALS_INSTALL_PREFIX}/include/glm
	)

# leptonica
ExternalProject_add(leptonica_external
	GIT_REPOSITORY "https://github.com/DanBloomberg/leptonica.git"
	GIT_TAG "1.82.0"
	TEST_COMMAND ""
	CMAKE_ARGS
		-DSW_EXECUTABLE=${CMAKE_SOURCE_DIR}/bin/win32/sw.exe
		-DCMAKE_INSTALL_PREFIX=${EXTERNALS_INSTALL_PREFIX}
		-DBUILD_SHARED_LIBS=OFF
		-DCMAKE_BUILD_TYPE=Release
)

# tesseract-orc
ExternalProject_add(tesseract_orc_external
	GIT_REPOSITORY "https://github.com/tesseract-ocr/tesseract.git"
	GIT_TAG "5.1.0"
	TEST_COMMAND ""
	CMAKE_ARGS
		-DSW_EXECUTABLE=${CMAKE_SOURCE_DIR}/bin/win32/sw.exe
		-DCMAKE_INSTALL_PREFIX=${EXTERNALS_INSTALL_PREFIX}
		-DBUILD_SHARED_LIBS=OFF
		-DCMAKE_BUILD_TYPE=Release
	DEPENDS
		leptonica_external
	)

add_custom_target(all_externals)
add_dependencies(all_externals
	tesseract_orc_external
	glm_external
	stb_external
	nlohmann_json_external
	wxWidgets_external
	leptonica_external
)