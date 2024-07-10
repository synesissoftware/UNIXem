
add_executable(test.component.glob
	test.component.glob.cpp
)

target_link_libraries(test.component.glob
	PRIVATE
		xTests::xTests.core
		# UNIXem
		# $<$<STREQUAL:${STLSOFT_INCLUDE_DIR},>:STLSoft::STLSoft>
)

target_compile_options(test.component.glob PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4

		/wd4996
	>
)
