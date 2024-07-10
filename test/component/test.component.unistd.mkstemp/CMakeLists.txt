
add_executable(test.component.unistd.mkstemp
	test.component.unistd.mkstemp.c
)

target_link_libraries(test.component.unistd.mkstemp
	PRIVATE
		xTests::xTests.core
		UNIXem
)

target_compile_options(test.component.unistd.mkstemp PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4

		/wd4996
	>
)
