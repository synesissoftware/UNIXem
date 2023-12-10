add_executable(test.unit.unistd.pathconf test.unit.unistd.pathconf.c)
target_link_librariestest.unit.unistd.pathconf UNIXem.core xTests::xTests.core)
add_test(NAME test.unit.unistd.pathconf COMMAND ./test.unit.unistd.pathconf)
