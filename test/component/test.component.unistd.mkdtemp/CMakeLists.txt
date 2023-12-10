add_executable(test.component.unistd.mkdtemp test.component.unistd.mkdtemp.c)
target_link_libraries(test.component.unistd.mkdtemp UNIXem.core xTests::xTests.core)
add_test(NAME test.component.unistd.mkdtemp COMMAND ./test.component.unistd.mkdtemp)
