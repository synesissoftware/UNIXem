# UNIXem - TODO

Updated:    12th May 2025


## UNIXem 1.12 TODOs:

 * [x] CMake
 * [ ] Refactor file-system utilities into separate API functions;
 * [ ] Greater unit-testing coverage;
 * [ ] Ensure unit-tests (and scratch-tests) do memory checking;
 * [ ] Remove Visual Studio project/solution files;
 * [ ] Component test(s) for link;
 * [ ] Standardise project boilerplate files (to .md);
 * [ ] CMake optional dependencies all marked OFF in CMakeListst.txt;


## UNIXem 1.13 TODOs:

 * [ ] `stpcpy()`, etc.;
 * [ ] `glob()` - expand functionality and flags coverage:
  * [ ] Proper handling of `errfunc` + `GLOB_ERR`;
  * [ ] Support `GLOB_APPEND`;
  * [ ] Unit-test `GLOB_MARK`;
  * [x] Cause order to be random when `GLOB_NOSORT`;
  * [ ] Reimplement in terms of `stpcpy()` (etc.);
  * [ ] Verify `GLOB_DOOFFS` handled correctly (esp. wrt `gl_matchc` and `gl_pathc`);
  * [ ] Implement escaping (and `UNIXEM_GLOB_NOESCAPE`);
  * [ ] Consider full implementation of tilde (i.e. other users' home directories);
  * [ ] ;
 * ;


## UNIXem 1.14 TODOs:

 * [ ] All Windows System calls use wide-string form, and translate to UTF-8 internally;
 * ;


<!-- ########################### end of file ########################### -->

