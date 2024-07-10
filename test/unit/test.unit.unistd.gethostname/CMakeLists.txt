
add_executable(test.unit.unistd.gethostname
	test.unit.unistd.gethostname.c
)

target_link_libraries(test.unit.unistd.gethostname
	PRIVATE
		xTests::xTests.core
		UNIXem
)

target_compile_options(test.unit.unistd.gethostname PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)
