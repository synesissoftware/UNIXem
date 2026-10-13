# Hand-maintained: prefer-underscore twin exercises
# UNIXEM_PREFER_COMPILER_UNDERSCORE_FORM (VC++ / Intel CRT).

define_automated_test_program(test.unit.unistd.getpid entry.c)

if(MSVC)

	define_automated_test_program(test.unit.unistd.getpid.prefer_underscore entry.c)
	target_compile_definitions(test.unit.unistd.getpid.prefer_underscore
		PRIVATE
			UNIXEM_PREFER_COMPILER_UNDERSCORE_FORM
	)
endif()
