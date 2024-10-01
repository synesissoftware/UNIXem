
add_executable(test.unit.unistd.getpid
	test.unit.unistd.getpid.c
)

target_link_libraries(test.unit.unistd.getpid
	PRIVATE
		xTests::core
		UNIXem
		$<$<STREQUAL:${STLSOFT_INCLUDE_DIR},>:STLSoft::STLSoft>
)

target_compile_options(test.unit.unistd.getpid PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)
