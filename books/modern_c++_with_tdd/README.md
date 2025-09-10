## Modern C++ Programming with Test-Driven Development by Jeff Langr released 2013

- Operating System: Slackware Linux version 15
- Compilers: c++ g++ gcc (GCC) 11.2.0
- CMake: cmake version 3.31.3
- IDE: vscode 1.103.2
- IDE extensions: C/C++, C/C++ Include Guard, Clang-Format, CMake
- OS Installed libs: [GoogleTest](https://github.com/google/googletest) version 1.17.0

## Installing GoogleTest version 1.17.0 using a custom slackbuild package
- [slackbuilds.org](https://slackbuilds.org/repository/15.0/development/gtest/) has a script for building an older verison of a gtest package
- My updated scripts are located [here](../../unit_testing_tools/googletest/slackbuild/gtest/)
- Follow instructions detailed on [slackbuilds.org](https://slackbuilds.org/howto/) to build and install the gtest package

### Building Book Examples and Running Tests

- Note: The books example code CMakeLists.txt files have been updated to reflect my OS dependencies and best practice for using CMake in 2025.

```bash
$ mkdir build && cd build
$ cmake .. --trace-source=CMakeLists.txt
$ make
$ ./test
```
- The above code has been added to file [go.sh](../../unit_testing_tools/go.sh). Copy and use as required.