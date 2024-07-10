
add_executable(test.scratch.uio
	test.scratch.uio.c
)

target_link_libraries(test.scratch.uio
	PRIVATE
		xTests::xTests.core
		UNIXem
)

target_compile_options(test.scratch.uio PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4

		/wd4996
	>
)
