# UNIXem - FAQ <!-- omit in toc -->

The FAQ list is under (constant) development. If you post a question on the
[Issues](https://github.com/synesissoftware/UNIXem/issues) forum it will be
used to create one.

- [Q1: "How do I build UNIXem?"](#q1-how-do-i-build-unixem)
- [Q2: "Does UNIXem run on Linux or macOS?"](#q2-does-unixem-run-on-linux-or-macos)
- [Q3: "Does UNIXem have its own unit-tests?"](#q3-does-unixem-have-its-own-unit-tests)
- [Q4: "Why does `getpid` not use the CRT `getpid` on Visual C++?"](#q4-why-does-getpid-not-use-the-crt-getpid-on-visual-c)
- [Q5: "What does `UNIXEM_PREFER_COMPILER_UNDERSCORE_FORM` do?"](#q5-what-does-unixem_prefer_compiler_underscore_form-do)


# FAQs: <!-- omit in toc -->


## Q1: "How do I build UNIXem?"

See instructions in [**INSTALL.md**](./INSTALL.md).


## Q2: "Does UNIXem run on Linux or macOS?"

No. **UNIXem** emulates selected Unix APIs on **Windows**. On Unix hosts you
use the native APIs instead.


## Q3: "Does UNIXem have its own unit-tests?"

Yes. Component and unit tests live under **test/** and depend on
[**xTests**](https://github.com/synesissoftware/xTests) (and **STLSoft**;
**shwild** is optional). Build with testing enabled and run
**run_all_unit_tests.sh** (or **run_all_unit_tests.cmd** on Windows).


## Q4: "Why does `getpid` not use the CRT `getpid` on Visual C++?"

Visual C++ still declares a deprecated POSIX-name `getpid` in **process.h**,
but **UNIXem** does not treat that as a “compiler-provided” POSIX API for
binding. By default **unistd.h** maps `getpid` to `unixem_getpid`, after
including **process.h** first so a later inclusion cannot clash with that
macro. Prefer calling `unixem_getpid` directly, or see Q5 if you want the
CRT `_getpid` binding for the POSIX name.


## Q5: "What does `UNIXEM_PREFER_COMPILER_UNDERSCORE_FORM` do?"

When defined **before** including UNIXem shim headers in a translation unit,
and the CRT provides `_<API>` while **UNIXem** does not treat the POSIX name
`<API>` as provided, the shim maps `<API>` to `_<API>` instead of to
`unixem_<API>`. For example, with the flag set on Visual C++, `getpid`
maps to `_getpid`. Omit the flag (the default) to keep `getpid` →
`unixem_getpid`. See [**INSTALL.md**](./INSTALL.md) and the API binding
policy in [**README.md**](./README.md).


<!-- ########################### end of file ########################### -->
