# UNIXem - FAQ <!-- omit in toc -->

The FAQ list is under (constant) development. If you post a question on the
[Issues](https://github.com/synesissoftware/UNIXem/issues) forum it will be
used to create one.

- [Q1: "How do I build UNIXem?"](#q1-how-do-i-build-unixem)
- [Q2: "Does UNIXem run on Linux or macOS?"](#q2-does-unixem-run-on-linux-or-macos)
- [Q3: "Does UNIXem have its own unit-tests?"](#q3-does-unixem-have-its-own-unit-tests)


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


<!-- ########################### end of file ########################### -->
