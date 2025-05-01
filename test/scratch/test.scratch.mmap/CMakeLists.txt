# This test is deactivated temporarily
# due to compile errors.

# add_executable(test.scratch.mmap.readonly test.scratch.mmap.c)
# target_link_libraries(test.scratch.mmap.readonly UNIXem.core xTests::xTests.core)
# target_compile_definitions(test.scratch.mmap.readonly PRIVATE TEST_READONLY)
# add_test(NAME test.scratch.mmap.readonly COMMAND ./test.scratch.mmap.readonly)

# add_executable(test.scratch.mmap.readwrite test.scratch.mmap.c)
# target_link_libraries(test.scratch.mmap.readwrite UNIXem.core xTests::xTests.core)
# target_compile_definitions(test.scratch.mmap.readwrite PRIVATE TEST_READWRITE)
# add_test(NAME test.scratch.mmap.readwrite COMMAND ./test.scratch.mmap.readwrite)

# add_executable(test.scratch.mmap.paging test.scratch.mmap.c)
# target_link_libraries(test.scratch.mmap.paging UNIXem.core xTests::xTests.core)
# target_compile_definitions(test.scratch.mmap.paging PRIVATE TEST_PAGING)
# add_test(NAME test.scratch.mmap.paging COMMAND ./test.scratch.mmap.paging)
