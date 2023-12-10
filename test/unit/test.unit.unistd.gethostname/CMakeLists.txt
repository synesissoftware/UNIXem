add_executable(test.unit.unistd.gethostname test.unit.unistd.gethostname.c)
target_link_libraries(test.unit.unistd.gethostname UNIXem.core xTests::xTests.core)
add_test(NAME test.unit.unistd.gethostname COMMAND ./test.unit.unistd.gethostname)

