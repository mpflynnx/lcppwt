cmake_minimum_required(VERSION 3.24.1)
project(chapterFirstExample)

# Enable C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

find_package(Threads REQUIRED)

# Get the CppUTest path from an environment variable.
set(CPPUTEST_HOME $ENV{CPPUTEST_HOME})

if(NOT CPPUTEST_HOME)
    message(FATAL_ERROR "CPPUTEST_HOME environment variable is not set.")
endif()

# Create the INTERFACE imported library for CppUTest.
add_library(CppUTest::CppUTest INTERFACE IMPORTED)
set_target_properties(CppUTest::CppUTest PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CPPUTEST_HOME}/include"

)

add_executable(test
    testmain.cpp
    SoundexTest.cpp
)

target_link_libraries(test PRIVATE CppUTest::CppUTest)
