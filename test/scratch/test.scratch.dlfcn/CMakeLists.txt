add_executable(test.scratch.dlfcn test.scratch.dlfcn.c)
target_link_libraries(test.scratch.dlfcn UNIXem.core xTests::xTests.core)
add_test(NAME test.scratch.dlfcn COMMAND ./test.scratch.dlfcn)
