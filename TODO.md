# UNIXem - TODO <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [Functional improvements](#functional-improvements)
- [Performance improvements](#performance-improvements)
- [Packaging improvements](#packaging-improvements)


## Functional improvements

* [ ] Refactor file-system utilities into separate API functions;
* [ ] Greater unit-testing coverage;
* [ ] Ensure unit-tests (and scratch-tests) do memory checking;
* [ ] Component test(s) for link;
* [ ] `stpcpy()`, etc.;
* [ ] `glob()` - expand functionality and flags coverage:
  * [ ] Proper handling of `errfunc` + `GLOB_ERR`;
  * [ ] Support `GLOB_APPEND`;
  * [ ] Unit-test `GLOB_MARK`;
  * [x] ~~~Cause order to be random when `GLOB_NOSORT`~~~ - ✅;
  * [ ] Reimplement in terms of `stpcpy()` (etc.);
  * [ ] Verify `GLOB_DOOFFS` handled correctly (esp. wrt `gl_matchc` and `gl_pathc`);
  * [ ] Implement escaping (and `UNIXEM_GLOB_NOESCAPE`);
  * [ ] Consider full implementation of tilde (i.e. other users' home directories);
* [ ] All Windows System calls use wide-string form, and translate to UTF-8 internally;


## Performance improvements

* \<none>


## Packaging improvements

* [x] ~~~CMake~~~ - ✅;
* [x] ~~~Remove Visual Studio project/solution files~~~ - ✅;
* [ ] Standardise project boilerplate files (to .md);
* [ ] CMake optional dependencies all marked OFF in CMakeListst.txt;


<!-- ########################### end of file ########################### -->
