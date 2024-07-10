
add_executable(test.scratch.mmap
	test.scratch.mmap.c
)

target_link_libraries(test.scratch.mmap
	PRIVATE
		xTests::xTests.core
		UNIXem
)

target_compile_definitions(test.scratch.mmap
	PRIVATE
		TEST_READONLY=1
)

target_compile_options(test.scratch.mmap PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4

		/wd4996
	>
)
