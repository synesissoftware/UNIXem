# UNIXem <!-- omit in toc -->

**Unix**-**em**ulation, for Windows


![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/UNIXem.svg)](https://github.com/synesissoftware/UNIXem/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/UNIXem)](https://github.com/synesissoftware/UNIXem/commits/master)
[![CI](https://github.com/synesissoftware/UNIXem/actions/workflows/ci.yml/badge.svg)](https://github.com/synesissoftware/UNIXem/actions/workflows/ci.yml)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Installation](#installation)
- [Components](#components)
  - [Unix API emulation](#unix-api-emulation)
  - [Atomic operations](#atomic-operations)
  - [Utility APIs](#utility-apis)
  - [Compatibility placeholders](#compatibility-placeholders)
- [Examples](#examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies)
    - [Test-only dependencies](#test-only-dependencies)
  - [Related projects](#related-projects)
  - [License](#license)


## Introduction

**UNIXem** is a small and simple library that provides emulation of several popular Unix API functions on the Windows platform. Its primary purpose is to assist Windows programmers who are porting to Unix or are writing multi-platform code.

**NOTE**: **UNIXem** is a Windows-only library.


## Installation

As of **1.12.7**, **CMake** support is provided, and this is the recommended means of installation. Detailed instructions are provided in [**INSTALL.md**](./INSTALL.md).


## Components

Top-level compatibility headers (e.g. [`dirent.h`](./include/dirent.h), [`unistd.h`](./include/unistd.h)) wrap the corresponding [`unixem/`](./include/unixem/) headers.


### Unix API emulation

| API(s)                                                                       | Header                                                     | Purpose                             | Restrictions             |
| ---------------------------------------------------------------------------- | ---------------------------------------------------------- | ----------------------------------- | ------------------------ |
| `chdir()`, `getcwd()`, `mkdir()`, `rmdir()`                                  | [`unixem/unistd.h`](./include/unixem/unistd.h)             | Working directory; make/remove dirs | —                        |
| `close()`, `getpagesize()`, `link()`, `pathconf()`, `realpath()`, `unlink()` | [`unixem/unistd.h`](./include/unixem/unistd.h)             | FD close; page size; links; paths   | —                        |
| `dlopen()`, `dlclose()`, `dlsym()`, `dlerror()`                              | [`unixem/dlfcn.h`](./include/unixem/dlfcn.h)               | Dynamic library load/lookup         | —                        |
| `gethostname()`, `getpid()`, `usleep()`                                      | [`unixem/unistd.h`](./include/unixem/unistd.h)             | Host name; process id; sleep        | —                        |
| `getrusage()`                                                                | [`unixem/sys/resource.h`](./include/unixem/sys/resource.h) | Process resource usage              | Limited field coverage   |
| `gettimeofday()`                                                             | [`unixem/sys/time.h`](./include/unixem/sys/time.h)         | Wall-clock time of day              | —                        |
| `glob()`, `globfree()`                                                       | [`unixem/glob.h`](./include/unixem/glob.h)                 | Pathname pattern expansion          | Incomplete flag coverage |
| `mkdtemp()`, `mkstemp()`                                                     | [`unixem/unistd.h`](./include/unixem/unistd.h)             | Temporary directory/file creation   | —                        |
| `mmap()`, `munmap()`, `msync()`                                              | [`unixem/sys/mman.h`](./include/unixem/sys/mman.h)         | Memory-map files/regions            | —                        |
| `opendir()`, `readdir()`, `rewinddir()`, `closedir()` (+ `w*` wide forms)    | [`unixem/dirent.h`](./include/unixem/dirent.h)             | Directory iteration                 | —                        |
| `readv()`, `writev()`                                                        | [`unixem/sys/uio.h`](./include/unixem/sys/uio.h)           | Vectored file read/write            | —                        |
| `setenv()`, `unsetenv()`                                                     | [`unixem/setenv.h`](./include/unixem/setenv.h)             | Environment variable set/clear      | —                        |
| `timegm()`                                                                   | [`unixem/time.h`](./include/unixem/time.h)                 | UTC `struct tm` to `time_t`         | —                        |


### Atomic operations

| API(s)                                                  | Header                                                 | Purpose                     | Restrictions |
| ------------------------------------------------------- | ------------------------------------------------------ | --------------------------- | ------------ |
| `unixem_atomic_*` (inc/dec/add/sub/set/read/write/test) | [`unixem/asm/atomic.h`](./include/unixem/asm/atomic.h) | Linux-style atomic integers | —            |


### Utility APIs

| API(s)                                                               | Header                                             | Purpose                            | Restrictions               |
| -------------------------------------------------------------------- | -------------------------------------------------- | ---------------------------------- | -------------------------- |
| `begins_with`, `ends_with`, `stpcpy`, `stpncpy`, `wcpcpy`, `wcpncpy` | [`unixem/util/str.h`](./include/unixem/util/str.h) | **UNIXem.Util.Str** string helpers | Helper API (also internal) |
| `char_is_path_sep`, `directory_exists`, `get_home_directory`         | [`unixem/util/fs.h`](./include/unixem/util/fs.h)   | **UNIXem.Util.FS** path/FS helpers | Helper API (also internal) |


### Compatibility placeholders

| API(s) | Header                                   | Purpose                    | Restrictions      |
| ------ | ---------------------------------------- | -------------------------- | ----------------- |
| —      | [`arpa/inet.h`](./include/arpa/inet.h)   | Compatibility include stub | Empty placeholder |
| —      | [`netinet/in.h`](./include/netinet/in.h) | Compatibility include stub | Empty placeholder |
| —      | [`sys/socket.h`](./include/sys/socket.h) | Compatibility include stub | Empty placeholder |


## Examples

Examples are not yet provided in this distribution. See the component and unit tests under **test/** for usage illustrations.


## Project Information


### Where to get help

[GitHub Issues](https://github.com/synesissoftware/UNIXem/issues)


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/UNIXem.


### Dependencies

There are no dependencies for installation and use of **UNIXem**.


#### Test-only dependencies

The component-/unit-tests depend on:

* [**STLSoft**](https://github.com/synesissoftware/STLSoft);
* [**shwild**](https://github.com/synesissoftware/shwild) (optional);
* [**xTests**](https://github.com/synesissoftware/xTests);


### Related projects

**UNIXem** is used by a number of C/C++ libraries for compilation/linking/testing on Windows, including:

* [**FastFormat**](https://github.com/synesissoftware/FastFormat);
* [**Pantheios**](https://github.com/synesissoftware/Pantheios);
* [**recls**](https://github.com/synesissoftware/recls);


### License

**UNIXem** is released under the 3-clause BSD license. See [**LICENSE**](./LICENSE) for details.


<!-- ########################### end of file ########################### -->
