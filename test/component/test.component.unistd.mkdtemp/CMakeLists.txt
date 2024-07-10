
add_executable(test.component.unistd.mkdtemp
	test.component.unistd.mkdtemp.c
)

target_link_libraries(test.component.unistd.mkdtemp
	PRIVATE
		xTests::xTests.core
		UNIXem
)

target_compile_options(test.component.unistd.mkdtemp PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4

		/wd4996
	>
)
