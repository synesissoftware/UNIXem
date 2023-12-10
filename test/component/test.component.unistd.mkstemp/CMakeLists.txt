add_executable(test.component.unistd.mkstemp test.component.unistd.mkstemp.c)
target_link_libraries(test.component.unistd.mkstemp UNIXem.core xTests::xTests.core)
add_test(NAME test.component.unistd.mkstemp COMMAND ./test.component.unistd.mkstemp)
