
#[====[
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/arpa/inet.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/asm/atomic.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/netonet/in.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/sys/mman.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/sys/resource.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/sys/socket.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/sys/time.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/sys/uio.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/arpa/inet.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/asm/atomic.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/netonet/in.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/sys/mman.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/sys/resource.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/sys/socket.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/sys/time.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/sys/uio.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/arpa/inet.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/dirent.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/dlfcn.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/glob.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/setenv.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/time.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/unistd.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unixem/unixem.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/dirent.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/dlfcn.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/glob.h")
list(APPEND public_headers "${CMAKE_SOURCE_DIR}/include/unistd.h")

list(APPEND private_headers "${CMAKE_SOURCE_DIR}/include/unixem/internal/safestr.h")
list(APPEND private_headers "${CMAKE_SOURCE_DIR}/include/unixem/internal/util.h")
list(APPEND private_headers "${CMAKE_SOURCE_DIR}/include/unixem/internal/winsock.h")

set_target_properties(UNIXem.core PROPERTIES
    OUTPUT_NAME "UNIXem"
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PRIVATE_HEADER "${private_headers}"
    PUBLIC_HEADER "${public_headers}")

#]====]

# ######################################################################## #
# File:     /src/CMakeLists.txt
#
# Purpose:  CMake lists file for UNIXem library
#
# Created:  ...
# Updated:  27th November 2024
#
# ######################################################################## #


if(WIN32)

	if(CMAKE_SIZEOF_VOID_P EQUAL 8)

		message(STATUS "Compiling for 64-bit Windows")

		add_definitions(-DWIN64)
	else()

		message(STATUS "Compiling for 32-bit Windows")

		add_definitions(-DWIN32)
	endif()
else(WIN32)

	message(FATAL_ERROR "Not compatible with non-Windows operating system(s)")
endif(WIN32)

if((MSVC) AND (MSVC_VERSION GREATER_EQUAL 1914))

	add_compile_options("/Zc:__cplusplus")
endif()


set(CORE_SRCS
	atomic.c
	dirent.c
	dlfcn.c
	glob.c
	hostname.c
	mktemp.c
	mmap.c
	resource.c
	setenv.c
	time.c
	uio.c
	unistd.c
	internal/util.c
	util_fs.c
	util_str.c
)

add_library(UNIXem
	${CORE_SRCS}
)

# specify the primary public headers for the library, which controls whether
# they'll be installed
#
# NOTE: it is not yet known (to me, at least) how to include additional
# header files from sub-directories, so this is done below in an additional
# `install()` step
set(CORE_PUBLIC_HEADERS
	"${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${PROJECT_NAME_LOWER}.h"
)

set_target_properties(UNIXem PROPERTIES
	OUTPUT_NAME "UNIXem"
	PUBLIC_HEADER "${CORE_PUBLIC_HEADERS}"
)

target_include_directories(UNIXem
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_compile_options(UNIXem
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ##########################################################
# install

install(TARGETS UNIXem
	EXPORT project-targets
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME_LOWER}
)

# install the include/unixem/*/ subdirectories here, as do not (yet) know how to do so via PUBLIC_HEADER property
install(
	DIRECTORY ${CMAKE_SOURCE_DIR}/include/
	DESTINATION include/
	FILES_MATCHING
	PATTERN "*.h*"
)


# ############################## end of file ############################# #

