add_executable(test.unit.unistd.getpid test.unit.unistd.getpid.c)
target_link_librariestest.unit.unistd.getpid UNIXem.core xTests::xTests.core)
add_test(NAME test.unit.unistd.getpid COMMAND ./test.unit.unistd.getpid)

