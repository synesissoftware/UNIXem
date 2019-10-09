/* /////////////////////////////////////////////////////////////////////////
 * File:        test.component.glob.cpp
 *
 * Purpose:     Implementation file for the test.component.glob project.
 *
 * Created:     20th May 2012
 * Updated:     9th October 2019
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2012-2019, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <glob.h>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <platformstl/filesystem/current_directory.hpp>
#include <platformstl/system/temporary_directory.hpp>
#include <platformstl/test/filesystem/temporary_directory_contents.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>

/* Standard C header files */
#include <errno.h>
#include <stdlib.h>
#include <string.h>

/* Compiler-specific header files */
#ifdef _WIN32
# include <direct.h>
# if __STDC__
#  define chdir	_chdir
# endif /* __STDC__ */
#endif /* _WIN32 */

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

	static void test_1_0(void);
	static void test_1_1(void);
	static void test_1_2(void);
	static void test_1_3(void);
	static void test_1_4(void);
	static void test_1_5(void);
	static void test_1_6(void);
	static void test_1_7(void);
	static void test_1_8(void);
	static void test_1_9(void);
	static void test_1_10(void);
	static void test_1_11(void);
	static void test_1_12(void);
	static void test_1_13(void);
	static void test_1_14(void);
	static void test_1_15(void);
	static void test_1_16(void);
	static void test_1_17(void);
	static void test_1_18(void);
	static void test_1_19(void);

	static int setup(void*);
	static int teardown(void*);
	struct locations
	{
		char const*	pwd;
		char const* workdir;
	};

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
	int retCode = EXIT_SUCCESS;
	int verbosity = 2;

	XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

	platformstl::current_directory				cwd;
	platformstl::temporary_directory			tempdir;

	platformstl::temporary_directory_contents	workdir(tempdir, "test.component.glob");

	workdir
		.create_directory("dir0")
		.create_directory("dir1")
		.create_directory("dir2")
		.create_file("file0")
		.create_file("file1", 1024)
		.create_file("file2", 10240)
		;

	locations	l = { cwd.c_str(), workdir.c_str() };

	if(XTESTS_START_RUNNER_WITH_SETUP_FNS("test.component.glob", verbosity, setup, teardown, &l))
	{
		XTESTS_RUN_CASE(test_1_0);
		XTESTS_RUN_CASE(test_1_1);
		XTESTS_RUN_CASE(test_1_2);
		XTESTS_RUN_CASE(test_1_3);
		XTESTS_RUN_CASE(test_1_4);
		XTESTS_RUN_CASE(test_1_5);
		XTESTS_RUN_CASE(test_1_6);
		XTESTS_RUN_CASE(test_1_7);
		XTESTS_RUN_CASE(test_1_8);
		XTESTS_RUN_CASE(test_1_9);
		XTESTS_RUN_CASE(test_1_10);
		XTESTS_RUN_CASE(test_1_11);
		XTESTS_RUN_CASE(test_1_12);
		XTESTS_RUN_CASE(test_1_13);
		XTESTS_RUN_CASE(test_1_14);
		XTESTS_RUN_CASE(test_1_15);
		XTESTS_RUN_CASE(test_1_16);
		XTESTS_RUN_CASE(test_1_17);
		XTESTS_RUN_CASE(test_1_18);
		XTESTS_RUN_CASE(test_1_19);

		XTESTS_PRINT_RESULTS();

		XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);

		workdir.cleanup();
	}

	return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{


static int setup(void* param)
{
	locations const* const l = static_cast<locations const*>(param);

	if(0 != ::chdir(l->workdir))
	{
		int const e = errno;

		fprintf(stderr, "could not change to directory '%s': %s (%d)\n", l->workdir, strerror(e), e);

		return 1;
	}

	return 0;
}

static int teardown(void* param)
{
	locations const* const l = static_cast<locations const*>(param);

	if(0 != ::chdir(l->pwd))
	{
		int const e = errno;

		fprintf(stderr, "could not change to directory '%s': %s (%d)\n", l->pwd, strerror(e), e);

		return 1;
	}

	return 0;
}


static void test_1_0()
{
	glob_t		gl;
	int const	flags	=	0;
	int const	r		=	glob("file0", flags, NULL, &gl);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0, r));

	stlsoft::scoped_handle<glob_t*> scoper(&gl, ::globfree);

#ifdef GLOB_LIMIT
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_matchc));
#endif /* GLOB_LIMIT */
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_pathc));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("file0", gl.gl_pathv[0]);
}

static void test_1_1()
{
	glob_t		gl;
	int const	flags	=	0;
	int const	r		=	glob("file?", flags, NULL, &gl);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0, r));

	stlsoft::scoped_handle<glob_t*> scoper(&gl, ::globfree);

#ifdef GLOB_LIMIT
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3, gl.gl_matchc));
#endif /* GLOB_LMIT */
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(3, gl.gl_pathc));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("file0", gl.gl_pathv[0]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("file1", gl.gl_pathv[1]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("file2", gl.gl_pathv[2]);
}

static void test_1_2()
{
	glob_t		gl; gl.gl_offs = 10;
	int const	flags	=	0;
	int const	r		=	glob("file0", flags, NULL, &gl);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0, r));

	stlsoft::scoped_handle<glob_t*> scoper(&gl, ::globfree);

#ifdef GLOB_LIMIT
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_matchc));
#endif /* GLOB_LMIT */
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_pathc));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("file0", gl.gl_pathv[0]);
}

static void test_1_3()
{
#ifdef GLOB_DOOFFS
	glob_t		gl; gl.gl_offs = 10;
	int const	flags	=	GLOB_DOOFFS;
	int const	r		=	glob("file0", flags, NULL, &gl);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0, r));

	stlsoft::scoped_handle<glob_t*> scoper(&gl, ::globfree);

# ifdef GLOB_LIMIT
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_matchc));
# endif /* GLOB_LMIT */
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_pathc));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("file0", gl.gl_pathv[10]);
#endif /* GLOB_DOOFFS */
}

static void test_1_4()
{
	glob_t		gl;
	int const	flags	=	0;
	int const	r		=	glob("xxx", flags, NULL, &gl);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(GLOB_NOMATCH, r));

	stlsoft::scoped_handle<glob_t*> scoper(&gl, ::globfree);
}

static void test_1_5()
{
	glob_t		gl;
	int const	flags	=	GLOB_NOCHECK;
	int const	r		=	glob("xxx", flags, NULL, &gl);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0, r));

	stlsoft::scoped_handle<glob_t*> scoper(&gl, ::globfree);

#ifdef GLOB_LIMIT
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_matchc));
#endif /* GLOB_LMIT */
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_pathc));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("xxx", gl.gl_pathv[0]);
}

static void test_1_6()
{
	glob_t		gl;
	int const	flags	=	GLOB_NOCHECK;
	int const	r		=	glob("x*y", flags, NULL, &gl);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0, r));

	stlsoft::scoped_handle<glob_t*> scoper(&gl, ::globfree);

#ifdef GLOB_LIMIT
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_matchc));
#endif /* GLOB_LMIT */
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_pathc));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("x*y", gl.gl_pathv[0]);
}

static void test_1_7()
{
#ifdef GLOB_LIMIT
	glob_t		gl; gl.gl_matchc = 2;
	int const	flags	=	GLOB_LIMIT;
	int const	r		=	glob("file?", flags, NULL, &gl);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(GLOB_NOSPACE, r));

	stlsoft::scoped_handle<glob_t*> scoper(&gl, ::globfree);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2, gl.gl_matchc));
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2, gl.gl_pathc));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("file0", gl.gl_pathv[0]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("file1", gl.gl_pathv[1]);
#endif /* GLOB_LIMIT */
}

static void test_1_8()
{
#if defined(GLOB_LIMIT) && \
    defined(GLOB_DOOFFS)
	glob_t		gl; gl.gl_matchc = 2; gl.gl_offs = 10;
	int const	flags	=	GLOB_LIMIT | GLOB_DOOFFS;
	int const	r		=	glob("file?", flags, NULL, &gl);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(GLOB_NOSPACE, r));

	stlsoft::scoped_handle<glob_t*> scoper(&gl, ::globfree);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2, gl.gl_matchc));
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(2, gl.gl_pathc));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("file0", gl.gl_pathv[10]);
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("file1", gl.gl_pathv[11]);
#endif /* GLOB_LIMIT && GLOB_DOOFFS */
}

static void test_1_9()
{
}

static void test_1_10()
{
	glob_t		gl;
	int const	flags	=	0;
	int const	r		=	glob(".", flags, NULL, &gl);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0, r));

	stlsoft::scoped_handle<glob_t*> scoper(&gl, ::globfree);

#ifdef GLOB_LIMIT
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_matchc));
#endif /* GLOB_LIMIT */
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_pathc));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL(".", gl.gl_pathv[0]);
}

static void test_1_11()
{
	glob_t		gl;
	int const	flags	=	0;
	int const	r		=	glob("..", flags, NULL, &gl);

	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(0, r));

	stlsoft::scoped_handle<glob_t*> scoper(&gl, ::globfree);

#ifdef GLOB_LIMIT
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_matchc));
#endif /* GLOB_LIMIT */
	XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(1, gl.gl_pathc));
	XTESTS_TEST_MULTIBYTE_STRING_EQUAL("..", gl.gl_pathv[0]);
}

static void test_1_12()
{
}

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
}

static void test_1_16()
{
}

static void test_1_17()
{
}

static void test_1_18()
{
}

static void test_1_19()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
