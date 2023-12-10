add_executable(test.scratch.setenv test.scratch.setenv.c)
target_link_libraries(test.scratch.setenv UNIXem.core xTests::xTests.core)
add_test(NAME test.scratch.setenv COMMAND ./test.scratch.setenv)
