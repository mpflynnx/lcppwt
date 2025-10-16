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

- Build an executable for use with the gdb debugger by setting `CMAKE_BUILD_TYPE` parameter to Debug
```bash
$ rm -rf build
$ mkdir build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug .. --trace-source=CMakeLists.txt
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
- Link to `gtest` in the CMakeLists.txt

```CMakeLists.txt
target_link_libraries(test PRIVATE Threads::Threads GTest::gtest GTest::gmock)
```
- Alternatively we could have linked with `gtest_main` (as opposed to with `gtest`) in the CMakeLists.txt. Therefore the `main.cpp` file would not be needed.

```CMakeLists.txt
target_link_libraries(test PRIVATE Threads::Threads GTest::gtest_main GTest::gmock)
```

### Book Chapter 2 notes

- In this chapter we will implement and test-drive a Soundex class, that can improve search capability of an application.
- The rules are soundex are described in file [soundex.md](../modern_c++_with_tdd/soundex.md)
- Commit messages for [source files](../modern_c++_with_tdd/mycode/c2/) act as documentation and should be viewed chronologically.

### Debugging exceptions using GDB

- By default, Google Test catches exceptions, logs them as a test failure, and then continues running the next test. This behavior is useful for maximizing test coverage in a single run, but it can make it difficult to pinpoint the exact location and cause of a crash.
- You use `--gtest_catch_exceptions=0` primarily when you're debugging an unexpected exception in your code.
- The flag disables Google Test's default exception handling. This allows the debugger to catch the exception first, pausing execution at the point of the throw. This lets you inspect the call stack, local variables, and program state at the moment the exception is thrown.
- Use gdb as shown below to debug executable `test`
```bash
$ gdb test
(gdb) b main // creates breakpoint at main
(gdb) run --gtest_catch_exceptions=0
(gdb) bt // view backtrace
```
-  If an unhandled exception is thrown, GDB will catch it and pause the execution, allowing you to debug the issue.

#### Common exception causes when using std::string
- When calling std::string() with std::string(4, '0') a string is created "0000".
- The maximum size of the string when using this constructor is determined by the member constant std::string::max_size() which is 4611686018427387903 on my laptop.
- Exceeding this number will cause a exception to be thrown.
- The number may be accidentally exceeded as shown below

```c++
  std::string word {abcde}; // length = 5
  static const size_t MaxCodeLength{4};

  auto ZerosRequired = MaxCodeLength - word.length(); // 4 -5 = overflow to 18446744073709551615
  std::string(ZerosRequired, '0'); // exception thrown here
```

## Debugging Soundex Class member functions using GDB

- If debugging a specific test, either comment out all other tests or disable them.
- Using Google Mock, you disable a test by prepending **`DISABLED_`** to its name, as shown below.
```c
TEST_F(SoundexEncoding, DISABLED_IgnoresCaseWhenEncodingConsonants) {
  ASSERT_THAT(soundex.encode("BCDL"), Eq(soundex.encode("Bcdl")));
}
```
- **Best practice:** Don't commit code with disabled (or commented out) tests.
- Ensure your C++ code is compiled with debugging symbols
```bash
$ mkdir build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug .. --trace-source=CMakeLists.txt
$ make
```
- Start GDB:
```bash
$ gdb -q test
```
- Set a breakpoint on the private member function (use the full scope for clarity):
```bash
(gdb) b Soundex::encodedDigits
```
- Alternatively if you wish to set a breakpoint on all Soundex Class member functions use `rbreak` with a regular expression.
```bash
(gdb) rbreak ^Soundex::.*
```
```
`^` Matches the start of the function name string

`Soundex::` Matches the literal class name followed by C++ scope resolution operator

`.*` Matches any character (.) zero or more times (*). This covers all member functions including constructors, deconstructors and overloaded functions

**NOTE** If your class is defined within a namespace, you must include the namespace in the regular expression:

(gdb) rbreak ^MyNamespace::MyClass::.*
```
- Run the program
```bash
(gdb) r
```
- Once the first breakpoint is hit and inside the private member function, use `watch` to break whenever member a variable changes:
```bash
(gdb) watch encoding
```
- Continue execution until next breakpoint
```bash
(gdb) c
```
- GDB will now stop execution immediately whenever the value of `encoding` changes.
- Once the member variable goes out of scope (i.e when the function returns) the watchpoint is deleted.


### External References

- [github.com | googletest](https://github.com/google/googletest)
- [github.com | cpputest](https://github.com/cpputest/cpputest)
- [googletest | primer | main() |](https://google.github.io/googletest/primer.html#writing-the-main-function)
- [wikipedia | Rules of Soundex](https://en.wikipedia.org/wiki/Soundex)
- [googletest | reference | ASSERT_THAT same as EXPECT_THAT](https://google.github.io/googletest/reference/assertions.html#EXPECT_THAT)
- [learncpp.com | Using declarations and using directives](https://www.learncpp.com/cpp-tutorial/using-declarations-and-using-directives/)
- [Clang format style options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)
- [udemy.com | Beginning C++ Programming | Section20 : STL | Associative Containers - Maps](https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/10563510#overview)
