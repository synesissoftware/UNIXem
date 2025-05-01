add_executable(test.scratch.getrusage test.scratch.getrusage.c)
target_link_libraries(test.scratch.getrusage UNIXem.core xTests::xTests.core)
add_test(NAME test.scratch.getrusage COMMAND ./test.scratch.getrusage)
