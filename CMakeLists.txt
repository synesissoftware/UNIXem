
# ######################################################################## #
# File:     /CMakeLists.txt
#
# Purpose:  Top-level CMake lists file for UNIXem
#
# Created:  10th July 2024
# Updated:  10th July 2024
#
# ######################################################################## #


# ##########################################################
# CMake

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

# require out-of-source builds
file(TO_CMAKE_PATH "${CMAKE_CURRENT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")

	message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

# directory for CMake specific extensions and source files.
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})


# ##########################################################
# project

project(UNIXem
	DESCRIPTION "UNIXem is a small and simple library that provides emulation of several popular Unix API functions on the Windows platform. Its primary purpose is to assist Windows programmers who are porting to Unix or are writing multi-platform code."
	HOMEPAGE_URL "https://github.com/synesissoftware/UNIXem"
	LANGUAGES C CXX
)

string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)

# handle version number
set(RX_PROJ_TAG "${PROJECT_NAME_UPPER}")
set(RX_WS "[ \t]")
file(READ "${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/${PROJECT_NAME_LOWER}.h" _header_file)
string(REGEX MATCH "#${RX_WS}*define${RX_WS}+_?${RX_PROJ_TAG}_VER_MAJOR${RX_WS}+([0-9]+)" MAJOR_DUMMY ${_header_file})
set(_VERSION_MAJOR ${CMAKE_MATCH_1})
string(REGEX MATCH "#${RX_WS}*define${RX_WS}+_?${RX_PROJ_TAG}_VER_MINOR${RX_WS}+([0-9]+)" MINOR_DUMMY ${_header_file})
set(_VERSION_MINOR ${CMAKE_MATCH_1})
string(REGEX MATCH "#${RX_WS}*define${RX_WS}+_?${RX_PROJ_TAG}_VER_REVISION${RX_WS}+([0-9]+)" PATCH_DUMMY ${_header_file})
set(_VERSION_PATCH ${CMAKE_MATCH_1})

# set project version number here
set(PROJECT_VERSION_MAJOR ${_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${_VERSION_MINOR})
set(PROJECT_VERSION_PATCH ${_VERSION_PATCH})
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

message(NOTICE "Generating CMake build scripts for ${PROJECT_NAME} ${PROJECT_VERSION}")


# adhere strictly to C and C++ standards plus extensions. These are actually
# useless since we do not compile anything; they merely state our intention.
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON) # GNU extensions and POSIX standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)


# ##########################################################
# install

# provides install directory variables as defined by the GNU Coding Standards.
include(GNUInstallDirs)


# ##########################################################
# STLSoft
#
# We provide flexibility here, as in:
# 1. if a CMake variable STLSOFT is provided then it is used; otherwise
# 2. if an environment variable STLSOFT is provided then it then it is used; otherwise
# 3. if the package STLSoft (via find_package()) is found then it is used; otherwise
# 4. we abort

if(NOT DEFINED STLSOFT AND NOT DEFINED ENV{STLSOFT})

	set(STLSoft_REQUIRED_VERSION_ 1.11)

	find_package(STLSoft ${STLSoft_REQUIRED_VERSION_} REQUIRED)

	message("-- CMake package STLSoft found (version ${STLSoft_VERSION}; ${STLSoft_REQUIRED_VERSION_} requested)")
else()

	if(DEFINED STLSOFT)

		message("-- STLSOFT provided as CMake variable with value ${STLSOFT}")

		set(STLSOFT_INCLUDE_DIR ${STLSOFT}/include)
	else()

		message("-- STLSOFT provided as environment variable with value $ENV{STLSOFT}")

		set(STLSOFT_INCLUDE_DIR $ENV{STLSOFT}/include)
	endif()

	include_directories(${STLSOFT_INCLUDE_DIR})
endif()


# ##########################################################
# build

# load/default `CMAKE_BUILD_TYPE`
include(BuildType)

add_subdirectory(src)


# ##########################################################
# test

include(CTest)

if(BUILD_TESTING)

	set(xTests_REQUIRED_VERSION_ 0.22)

	find_package(xTests ${xTests_REQUIRED_VERSION_} REQUIRED)

	message("-- CMake package xTests found (version ${xTests_VERSION}; ${xTests_REQUIRED_VERSION_} requested)")

	add_subdirectory(test)
endif()


# ##########################################################
# examples

option(BUILD_EXAMPLES "Build examples" ON)
if(BUILD_EXAMPLES)

	add_subdirectory(examples)
endif()


# ##########################################################
# install


# ##########################################################
# export

include(CMakePackageConfigHelpers)

set(EXPORT_NAME ${PROJECT_NAME_LOWER})

configure_package_config_file(
	${CMAKE_CURRENT_SOURCE_DIR}/cmake/${EXPORT_NAME}-config.cmake.in
	${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config.cmake
	INSTALL_DESTINATION ${LIB_INSTALL_DIR}/${EXPORT_NAME}/cmake
)

write_basic_package_version_file(
	${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config-version.cmake
	VERSION ${PROJECT_VERSION}
	COMPATIBILITY AnyNewerVersion
)

export(EXPORT project-targets
	FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-targets.cmake"
	NAMESPACE "${PROJECT_NAME}::"
)

install(EXPORT project-targets
	NAMESPACE "${PROJECT_NAME}::"
	FILE "${EXPORT_NAME}-targets.cmake"
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}
)

install( FILES
	"${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config.cmake"
	"${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config-version.cmake"
	DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}
)


# ############################## end of file ############################# #

