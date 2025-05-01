add_executable(test.component.dirent test.component.dirent.c)
target_link_libraries(test.component.dirent UNIXem.core xTests::xTests.core)
add_test(NAME test.component.dirent COMMAND ./test.component.dirent)
