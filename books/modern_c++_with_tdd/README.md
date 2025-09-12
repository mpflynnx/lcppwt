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

### Building book examples and running tests with Googletest

- Note: I have updated the books example code CMakeLists.txt files to reflect my OS dependencies and best practice for using CMake in 2025.

```bash
$ rm -rf build
$ mkdir build && cd build
$ cmake .. --trace-source=CMakeLists.txt
$ make
$ ./test
```
- The above code has been added to file [go.sh](../../unit_testing_tools/go.sh). Copy and use where required.

### Building book examples and running tests with CppUTest

- To install CppUTest refer to document [../../unit_testing_tools/cpputest/installation.md](../../unit_testing_tools/cpputest/installation.md)
- I have also documented the build and testing of the books example code using [CMake and CppUTest](../modern_c++_with_tdd/cpputest/). 

### Book Chapter 1 using GoogleTest

- We will use our own `main()` defined in [main.cpp](../modern_c++_with_tdd/mycode/c2/main.cpp)

**main.cpp**
```c
#include "gmock/gmock.h"

int main(int argc, char** argv) {
   testing::InitGoogleMock(&argc, argv);
   return RUN_ALL_TESTS();
}
```
- Alternatively we could have linked with `gtest_main` (as opposed to with `gtest`)

### Book Chapter 2

- In this chapter we will implement and test-drive a Soundex class, that can improve search capability of an application.
- The rules are soundex are described in file [soundex.md](../modern_c++_with_tdd/soundex.md)
- Commit messages for [source files](../modern_c++_with_tdd/mycode/c2/) act as documentation and should be viewed chronologically.

### External References

- [github.com | googletest](https://github.com/google/googletest)
- [github.com | cpputest](https://github.com/cpputest/cpputest)
- [googletest | primer | main() |](https://google.github.io/googletest/primer.html#writing-the-main-function)
- [wikipedia | Rules of Soundex](https://en.wikipedia.org/wiki/Soundex)
- [googletest | reference | ASSERT_THAT same as EXPECT_THAT](https://google.github.io/googletest/reference/assertions.html#EXPECT_THAT)
- [learncpp.com | Using declarations and using directives](https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/)
