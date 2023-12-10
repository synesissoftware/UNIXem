add_library(UNIXem.core
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
	internal/util.c)

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
target_include_directories(UNIXem.core PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

install(TARGETS UNIXem.core
    EXPORT project-targets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/unixem
)
