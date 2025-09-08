## README.md

- Operating System: Slackware Linux version 15
- Compilers: c++ g++ gcc (GCC) 11.2.0
- CMake: cmake version 3.31.3
- IDE: vscode 1.103.2
- IDE extensions: C/C++, C/C++ Include Guard,Clang-Format, CMake
- OS Installed libs: googletest version 1.17.0

### Building Examples and Running Tests

- Note: The books example code CMakeLists.txt files have been updated to reflect my OS dependencies and best practice for using CMake in 2025.

```bash
$ mkdir build && cd build
$ cmake .. --trace-source=CMakeLists.txt
$ make
$ ./test
```