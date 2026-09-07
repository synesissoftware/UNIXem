# UNIXem - Changes <!-- omit in toc -->


## 1.14.0-beta1 - 9th August 2026

* added `stpcpy()`;


## 1.13.0-beta1 - 4th August 2026

* added modular GitHub Actions CI (**ci.yml** / **ci-cell.yml**) for Windows (MSVC + MinGW) with install-smoke coverage;
* converted **CHANGES.txt** to **CHANGES.md** and removed **HISTORY.md**;
* expanded **FAQ.md**, **INSTALL.md**, and **README.md** (incl. CI badges and Components tables);
* fixed **CMakeLists.txt** so **STLSoft** is required only when **BUILD_TESTING** is enabled (removed erroneous **NO_B64_CPP_API** guard);
* **CMake** now fails early on non-Windows hosts (`${PROJECT_NAME} targets Windows only`);
* removed Visual Studio project/solution/workspace files (**unixem.vc10.sln**, **unixem.vc6.dsw**, **projects/**, per-test **vc6**/**vc10** trees);
* project boilerplate canonicalisation (**AUTHORS.md**, **NEWS.md**, **TODO.md**, **.sis/**, **.vimrc**);
* CMake helper-script enhancements (**ProjectName** from **.sis/project_name.txt**; modernised **run_all_unit_tests.sh** / **run_all_unit_tests.cmd** with `--unit-only` / `--component-only`);
* added **LanguageFullVersion.cmake** and related CMake tidy;
* added **ctest_cmake.sh**;
* scratch programs **test.scratch.dlfcn**, **test.scratch.link**, and **test.scratch.uio** now smoke successfully with no arguments (defaults / self-path);


## 1.13.0-alpha1 - 7th September 2025

* version bump to **1.13.0**;
* project boilerplate canonicalisation begun (markdown docs, helper scripts, **LICENSE**);


## 1.12.8 - 19th May 2025

* `glob()` now provides a pseudo-random order when `GLOB_NOSORT` flag is specified;
* Added **UNIXem.Util.FS** API, and applied in refactoring some API functions;
* Added **UNIXem.Util.Str** API, and applied in refactoring some API functions;
* Expanded **test.component.dirent**;
* Expanded **test.component.glob**;
* Miscellaneous consistency improvements;
* CMake optional dependency on **shwild**;
* Standard names of implementation files of unit/component tests;


## 1.12.7 - 1st May 2025

* CMake support;
* MinGW support;
* `usleep()` now sleeps for (at least) 1ms when given sleep time in range 1-999 nanoseconds;
* Simplying `glob()` API;
* Simplified implementation of `unixem__setenv__putenv_()` (and avoided warnings w MinGW);
* Refactored discrimination of integer types;
* Refactored in terms of `unixem_internal_Windows_HANDLE_from_file_handle()`;
* Added **test.component.unistd.usleep**;
* **test.component.unistd.mkdtemp** ensures created temporary directories and temporary files are removed;
* **test.scratch.getrusage** ensures created temporary files are removed;
* Visual C++ warnings;
* VS Code settings;
* Removed support for Comeau compiler;
* Miscellaneous tidying and consistency fixes;
* Added .gitattributes;


## 1.12.6 - 17th December 2020

* compatibility with Visual Studio 2019 (16.8.2);


## 1.12.5 - 19th July 2020

* added support for Visual C++ 15 and 16;


## 1.12.4 - 19th July 2020

* refactored makefiles (in auto-generation);


## 1.12.3 - 14th October 2019

* added GCC 4.9 (MinGW) compatibility;


## 1.12.2 - 14th October 2019

* fixing generated library names to match implicit-link;
* fixed invalid value of 1.11.4's UNIXEM_VER by bumping minor version;
* added GCC 8.1 (MinGW) compatibility;


## 1.11.4 - 9th October 2019

* fixing up setenv() / unsetenv();
* incorporating latest changes from GitHub repo;
* fleshing out README.md for the GitHub site;


## 1.11.2 - 2nd January 2017

* fixed name of built library prefix from "unixem.core.1.*" to "unixem.1.core.*";
* moved build/vc6/unixem.dsp => projects/core/vc6/unixem.core.dsp;
* added VC++10 project and props files;


## 1.11.1 - 7th October 2015

* built library name prefix changes from "unixem" to "unixem.core";
* added mkdtemp();
* added mkstemp();
* added VC++14 support;


## 1.10.2 - 25th September 2015

* minor fix to unixem_gettimeofday();


## 1.10.1 - 30th July 2015

* added unixem_timegm() / timegm();
* added VC++11 and VC++12 support;


## 1.9.3 - 16th June 2012

* GLOB_ONLYFILE => GLOB_ONLYREG;
* glob() now preserves dots directories when included in leaf-most pattern part;
* fix to definition of WIN32 when using WinSock;


## 1.9.2 - 4th February 2011

* removed include/sys/select.h (which was vestigial);
* various tidyings;
* handling EZERO, ERROR_FILE_TOO_LARGE, ERROR_DISK_TOO_FRAGMENTED (in unixem_internal_errno_from_Win32());


## 1.9.1 - 12th August 2010

* reworked the API such that all functions are prefixed with unixem_(), and defined to the UNIX functions via macros;
* 64-bit compatibility fixes;


## 1.8.5 - 13th August 2010

* gettimeofday() now returns int (instead of void);
* added VC++ 10 implicit-link support;


## 1.8.4 - 4th April 2010

* fixed erroneous library name in implicit link file;
* added VC++ 10 support;


## 1.8.3 - 6th February 2010

* refactored headers to resolve conflict(s) between unistd.h and winsock(2).h withouth using #define to prevent subsequent inclusion of winsock(2).h;
* added empty (placeholder) files: arpa/inet.h, netinet/in.h, sys/socket.h;
* fixed _M_X86 implicit link defect;
* added implicit link support for Borland 5.9+, 6.1+ and Intel C/C++ 9, 10, 11;
* changed library name/implicit link directives for VC++ x64/IA64 targets;
* added Synesis-standard make targets: compile.libs.core, compile.libs, compile, build.libs.core, build.libs, build;
* various other minor changes;


## 1.8.2 - 13th May 2008

* Win64 compatibility;


## 1.8.1 - 22nd April 2008

* added gethostname();
* added getpid();
* changed 2nd param of gettimeofday() to void*;
* improved semantics for glob() when a pattern search in an existing directory matches no entries;


## 1.7.5 - 20th April 2008

* the distribution is now rooted at unixem-1.7.5/;
* makefiles for VC++ 8 & 9;
* implicit linking for Borland C/C++ 5.82;
* implicit linking for VC++ 9;
* bundles shwild 0.9.13;
* bundles xTests 0.6.1;
* makefiles for Visual C++ 8 & 9;


## 1.7.4 - 24th February 2008

* include/unixem/internal/safestr.h;
* safe string library for src/glob.c;
* improved handling of offsets and errors in src/mmap.c;
* safe string library for src/setenv.c;
* fixed bug in gettimeofday(), which was showing local time, rather than the required system time;


## 1.7.3 - 12th March 2007

* fixed gettimeofday() - was returning local and not system time;
* library now compatible with Secure Library string functions;


<!-- ########################### end of file ########################### -->
