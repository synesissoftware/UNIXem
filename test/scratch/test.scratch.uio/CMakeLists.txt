add_executable(test.scratch.uio test.scratch.uio.c)
target_link_libraries(test.scratch.uio UNIXem.core xTests::xTests.core)
add_test(NAME test.scratch.uio COMMAND ./test.scratch.uio)
