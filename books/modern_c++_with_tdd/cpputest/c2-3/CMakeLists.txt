cmake_minimum_required(VERSION 3.24.1)
project(chapterFirstExample)

# Enable C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

# find_package(Threads REQUIRED)

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
# The `PRIVATE` keyword means that the CppUTest libraries are an implementation detail
# of the 'test' executable and not exposed to other targets that might link to 'test'.
target_link_libraries(test PRIVATE CppUTest::CppUTest)
