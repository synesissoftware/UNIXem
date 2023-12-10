add_executable(test.scratch.syslog test.scratch.syslog.c)
target_link_libraries(test.scratch.syslog UNIXem.core xTests::xTests.core)
add_test(NAME test.scratch.syslog COMMAND ./test.scratch.syslog)
