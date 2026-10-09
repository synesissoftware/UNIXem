# UNIXem - Installation and Use <!-- omit in toc -->

**UNIXem** is a classic-form C library for Windows, with implementation files
in its **src** directory and header files under **include/** (including
**include/unixem/**). Once installed, include the appropriate headers (e.g.
**unixem/unixem.h**, **unixem/unistd.h**, or the top-level compatibility
headers such as **unistd.h**) and link against the **UNIXem** library.


## Table of Contents <!-- omit in toc -->

- [Platform](#platform)
- [CMake](#cmake)


## Platform

**UNIXem** targets **Windows** only (MSVC and MinGW). Non-Windows hosts are
rejected by **CMake**.


## CMake

The primary choice for installation is by use of **CMake**.

1. Obtain the latest distribution of **UNIXem**, from
   https://github.com/synesissoftware/UNIXem/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/UNIXem/
   ```

2. Prepare the CMake configuration, via the **prepare_cmake.sh** script, as
   in:

   ```bash
   $ cd ~/open-source/UNIXem
   $ ./prepare_cmake.sh -v
   ```

   **NOTE**: if you intend only to build the library then you can eschew
   building of examples (`-E`) and tests (`-T`) and use the command:

   ```bash
   $ ./prepare_cmake.sh -E -T
   ```

   In this case, you do not need to have installed **STLSoft**, **shwild**,
   or **xTests**; otherwise, you will need those test-only dependencies to
   be discoverable by **CMake**.

   **NOTE**: **CMake** selects the generator. To build with **MinGW**
   rather than **MSVC**, provide the flag `--mingw`, which selects the
   "MinGW Makefiles" generator (and is the only means by which **MinGW** is
   selected).

3. Run a build of the generated **CMake**-derived build files via the
   **build_cmake.sh** script, as in:

   ```bash
   $ ./build_cmake.sh
   ```

   (**NOTE**: if you provide the flag `--run-make` (=== `-m`) in step 2 then
   you do not need this step.)

4. As a check, execute the built test programs via **run_all_unit_tests.sh**
   (or **ctest_cmake.sh**), as in:

   ```bash
   $ ./run_all_unit_tests.sh
   ```

   From a native Windows command prompt, use **run_all_unit_tests.cmd**
   (and, likewise, **run_all_component_tests.cmd**,
   **run_all_examples.cmd**, and **run_all_scratch_tests.cmd**), as in:

   ```cmd
   > run_all_unit_tests.cmd
   ```

5. Install the library on the host, via `cmake`, as in:

   ```bash
   $ cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
   ```

6. Then to use the library:

   1. A minimal consumer:

      ```c
      // main.c
      #include <unixem/unixem.h>
      #include <stdio.h>
      #include <stdlib.h>

      int main(void)
      {
        printf("using UNIXem\n");

        return EXIT_SUCCESS;
      }
      ```

   2. Or via **CMake** `find_package`:

      ```cmake
      find_package(unixem REQUIRED)
      target_link_libraries(your_target PRIVATE UNIXem::UNIXem)
      ```


<!-- ########################### end of file ########################### -->
