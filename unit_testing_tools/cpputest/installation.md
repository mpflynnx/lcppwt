## Installation of CppUTest

- There are a number of options available to install CppUTest


### 1. Installation of CppUTest to local folder

- Open bash prompt in a terminal. NOTE: bash prompt only, fish shell or others require different steps.
```bash
$ bash
$ cd ~
$ git clone https://github.com/cpputest/cpputest.git
```
- NOTE: To use MakefileWorker you need to build from the cpputest home directory.

```bash
$ cd ~/cpputest
$ autoreconf . -i
$ ./configure
$ make tdd
```
- We will use this local folder during compilation
- Creating an environmental variable will help
- Open ~/.bashrc for editing

```bash
$ nano ~/.bashrc
```
- Enter at the last line of file
```bash
export CPPUTEST_HOME="$HOME/cpputest"
```
- Restart any open terminal windows for the update to take effect.
- Use the variable in a cmakelists.txt file as shown.

**cmakelist.txt**
```bash
project(chapterFirstExample)
cmake_minimum_required(VERSION 3.24.1)

# Enable C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Assumes environmental variable CPPUTEST_HOME set in .bashrc
include_directories($ENV{CPPUTEST_HOME}/include)
link_directories($ENV{CPPUTEST_HOME}/lib)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources testmain.cpp SoundexTest.cpp)
add_executable(test ${sources})

target_link_libraries(test CppUTest)
```

**Note:** Using `include_directories` and `link_directories` is generally not considered best practice in modern CMake (versions 3.0 and later). A better approach is detailed below.

### 2. Installation of CppUTest in the project using CMake

- Use the CMake `FetchContent()` as shown in the example.

**cmakelists.txt**
```bash
cmake_minimum_required(VERSION 3.24.1)
project(chapterFirstExample)

# Enable C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

include(FetchContent)
FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG master
)
FetchContent_MakeAvailable(CppUTest)

# Add your test source files to the executable target.
add_executable(test
    testmain.cpp
    SoundexTest.cpp
    # Add any other test files here
)

# Link the executable with the CppUTest libraries.
target_link_libraries(test PRIVATE CppUTest::CppUTest)
```


### External References

- [github.com | cpputest | Integration as external CMake project](https://github.com/cpputest/cpputest#integration-as-external-cmake-project)