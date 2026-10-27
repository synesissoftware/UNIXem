define_example_program(test.scratch.versions main.c)

if(TARGET xTests::core)

	target_link_libraries(test.scratch.versions
		PRIVATE
			xTests::core
	)
endif()
