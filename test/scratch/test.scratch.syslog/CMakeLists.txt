#[====[
list(APPEND X_GCC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED unused-variable)
#]====]
list(APPEND X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED 4996)
define_example_program(test.scratch.syslog test.scratch.syslog.c)
