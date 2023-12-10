add_executable(test.scratch.link test.scratch.link.c)
target_link_libraries(test.scratch.link UNIXem.core xTests::xTests.core)
add_test(NAME test.scratch.link COMMAND ./test.scratch.link)
