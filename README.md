# UNIXem <!-- omit in toc -->

![Language](https://img.shields.io/badge/C-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

**Unix**-**em**ulation, for Windows

## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Installation](#installation)
- [Components](#components)
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


## Installation

As of **1.12.8**, **CMake** support is provided, and this is the recommended means of installation. Detailed instructions are provided in [INSTALL.md](./INSTALL.md).


## Components

API functions include:

- ``opendir()``, ``readdir()``, ``rewinddir()``, ``closedir()``;
- ``glob()``, ``globfree()``;
- ``readv()``, ``writev()``;
- ``pathconf()``;
- ``realpath()``;
- ``mmap()``, ``munmap()``, ``msync()``;
- ``dlopen()``, ``dlclose()``, ``dlsym()``, ``dlerror()``;
- ``gettimeofday()``;
- ``getpagesize()``;
- ``mkdtemp()``, ``mkstemp()``;
- ``mkdir()``, ``rmdir()``;
- ``getcwd()``;
- ``getpid()``;
- ``gethostname()``;
- ``usleep()``;
- ``getrusage()``;
- ``setenv()``, ``unsetenv()``;
- ``link()``,  ``unlink()``;
- ``timegm()``;


## Examples

T.B.C.


## Project Information


### Where to get help

[GitHub Page](https://github.com/synesissoftware/UNIXem "GitHub Page")


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/UNIXem.


### Dependencies

There are no dependencies for installation and use of **STLSoft**.

#### Test-only dependencies

The component-/unit-tests depend on the **xTests** project:

 * [STLSoft](http://github.com/synesissoftware/STLSoft-1.11/);
 * [shwild](http://github.com/synesissoftware/shwild/);
 * [xTests](http://github.com/synesissoftware/xTests/);


### Related projects

**UNIXem** is used by a number of C/C++ libraries for compilation/linking/testing on Windows, including:

 * [**FastFormat**](https://github.com/synesissoftware/FastFormat/)
 * [**Pantheios**](https://github.com/synesissoftware/Pantheios/)
 * [**recls**](https://github.com/synesissoftware/recls/)


### License

**UNIXem** is released under the 3-clause BSD license. See LICENSE for details.


<!-- ########################### end of file ########################### -->

