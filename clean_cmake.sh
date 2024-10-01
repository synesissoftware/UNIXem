#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    --help)

      cat << EOF
UNIXem is a small and simple library that provides emulation of several popular Unix API functions on the Windows platform. Its primary purpose is to assist Windows programmers who are porting to Unix or are writing multi-platform code
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2002-2019, Matthew Wilson and Synesis Software
Executes CMake-generated artefacts to clean project

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:


    standard flags:

    --help
        displays this help and terminates

EOF

      exit 0
      ;;
    *)

      >&2 echo "$ScriptPath: unrecognised argument '$1'; use --help for usage"

      exit 1
      ;;
  esac

  shift
done


# ##########################################################
# main()

if [ ! -d "$CMakeDir" ]; then

  >&2 echo "$ScriptPath: CMake build directory '$CMakeDir' not found so nothing to do; use script 'prepare_cmake.sh' if you wish to prepare CMake artefacts"

  exit 1
else

  cd $CMakeDir

  if [ ! -f "$CMakeDir/Makefile" ]; then

    >&2 echo "$ScriptPath: CMake build directory '$CMakeDir' does not contain expected file 'Makefile', so a clean cannot be performed. It is recommended that you remove all CMake artefacts using script 'remove_cmake_artefacts.sh' followed by regeneration via 'prepare_cmake.sh'"

    exit 1
  else

    echo "Cleaning build (via command \`make clean\`)"

    make clean
    status=$?

    cd ->/dev/null

    exit $status
  fi
fi


# ############################## end of file ############################# #

