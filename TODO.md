# UNIXem - TODO <!-- omit in toc -->

Updated: 4th August 2026


## Functional improvements

* [ ] Refactor file-system utilities into separate API functions;
* [ ] Greater unit-testing coverage;
* [ ] Ensure unit-tests (and scratch-tests) do memory checking;
* [ ] Component test(s) for `link`;
* [x] ~~~`stpcpy()`, etc.~~~ - ✅;
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

* [x] ~~~Badges~~~;
* [x] ~~~CMake~~~;
* [x] ~~~Standardise project boilerplate files (to .md)~~~;
* [x] ~~~Remove Visual Studio project/solution/workspace files~~~;
* [ ] Remove custom makefiles under **build/** (retained for now);
* [ ] CMake optional dependencies all marked OFF in **CMakeLists.txt**;
* [ ] Add example programs under **examples/**;
* [ ] Add to Windows-capable package managers:
  * [ ] Chocolatey;
  * [ ] Conan;
  * [ ] MSYS2;
  * [ ] NuGet;
  * [ ] Scoop;
  * [ ] vcpkg;
  * [ ] winget;


<!-- ########################### end of file ########################### -->
