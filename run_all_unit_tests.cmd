@echo off

SETLOCAL ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION

SET SCRIPT_DIRECTORY=%~dp0
SET SCRIPT_PATH_DOC=%~n0[%~x0]
IF DEFINED SIS_CMAKE_BUILD_DIR (

	SET "CMAKE_DIR=%SIS_CMAKE_BUILD_DIR%"
) ELSE (

	SET "CMAKE_DIR=%SCRIPT_DIRECTORY%_build"
)

SET ListOnly=0
SET Verbose=0
SET UnitOnly=0
SET ComponentOnly=0
SET status=0

FOR %%a IN (%*) DO (
	IF /I {--help}=={%%a} (
		IF EXIST "%SCRIPT_DIRECTORY%.sis\script_info_lines.txt" (

			type "%SCRIPT_DIRECTORY%.sis\script_info_lines.txt"
		)
		ECHO ^

Runs all ^(matching^) unit-test and/or component-test programs ^

^

%SCRIPT_PATH_DOC% [ ... flags/options ... ] ^

^

Flags/options: ^

    behaviour: ^

^

    -l ^

    --list-only ^

        lists the target programs but does not execute them ^

^

    -M ^

    --no-make ^

        accepted for parity with the .sh script ^(build is not invoked^) ^

^

    --unit-only ^

        runs only unit-test programs ^(test.unit.* / test_unit*^) ^

^

    --component-only ^

        runs only component-test programs ^(test.component.* / test_component*^) ^

^

    -v ^

    --verbose ^

        lists each test program before executing it ^

^

    standard flags: ^

^

        --help ^

            displays this help and terminates ^


		EXIT /B 0
	) ELSE IF /I {-l}=={%%a} (
		SET ListOnly=1
	) ELSE IF /I {--list-only}=={%%a} (
		SET ListOnly=1
	) ELSE IF /I {-M}=={%%a} (
		REM no-op: this .cmd never invokes the build
	) ELSE IF /I {--no-make}=={%%a} (
		REM no-op: this .cmd never invokes the build
	) ELSE IF /I {--unit-only}=={%%a} (
		SET UnitOnly=1
	) ELSE IF /I {--component-only}=={%%a} (
		SET ComponentOnly=1
	) ELSE IF /I {-v}=={%%a} (
		SET Verbose=1
	) ELSE IF /I {--verbose}=={%%a} (
		SET Verbose=1
	) ELSE (
		ECHO %SCRIPT_PATH_DOC%: unrecognised argument '%%a'; use --help for usage 1>&2

		EXIT /B 1
	)
)

IF !UnitOnly! EQU 1 IF !ComponentOnly! EQU 1 (

	ECHO %SCRIPT_PATH_DOC%: --unit-only and --component-only are mutually exclusive 1>&2

	EXIT /B 1
)

IF NOT EXIST "%CMAKE_DIR%" (

	ECHO %SCRIPT_PATH_DOC%: CMake build directory '%CMAKE_DIR%' does not exist 1>&2

	EXIT /B 1
)

SET "ProjectName="
FOR /F "usebackq delims=" %%p IN ("%SCRIPT_DIRECTORY%.sis\project_name.txt") DO SET "ProjectName=%%p"

IF NOT DEFINED ProjectName (

	ECHO %SCRIPT_PATH_DOC%: could not read project name from .sis\project_name.txt 1>&2

	EXIT /B 1
)

IF !UnitOnly! EQU 1 (

	SET "TestKindDescription=unit test"
) ELSE IF !ComponentOnly! EQU 1 (

	SET "TestKindDescription=component test"
) ELSE (

	SET "TestKindDescription=component and unit test"
)

IF !ListOnly! EQU 1 (

	ECHO Listing all !ProjectName! !TestKindDescription! programs
) ELSE (

	ECHO Running all !ProjectName! !TestKindDescription! programs
)

IF !UnitOnly! EQU 1 (

	SET "FindPattern=test\.unit\..*\.exe$"
) ELSE IF !ComponentOnly! EQU 1 (

	SET "FindPattern=test\.component\..*\.exe$"
) ELSE (

	SET "FindPattern=test\.unit\..*\.exe$ test\.component\..*\.exe$"
)

FOR /F "usebackq delims=" %%f IN (`DIR /A:-D /B /S "%CMAKE_DIR%\*.exe" 2^>NUL ^| FINDSTR /I /R "!FindPattern!"`) DO (
	IF !ListOnly! EQU 1 (

		ECHO would execute %%f:
	) ELSE (

		IF !Verbose! EQU 1 (

			ECHO executing %%f:
		)

		"%%f"
		IF ERRORLEVEL 1 (

			SET status=1

			GOTO :done
		)
	)
)

:done
EXIT /B !status!
