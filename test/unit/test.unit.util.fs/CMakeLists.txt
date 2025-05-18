list(APPEND X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED 4996)
define_automated_test_program(test.unit.util.fs entry.cpp)
