project(chapterFirstExample)

cmake_minimum_required(VERSION 3.24.1)

find_package(GTest 1.17.0 REQUIRED)
find_package(Threads REQUIRED)

#include_directories($ENV{GMOCK_HOME} $ENV{GTEST_HOME})
#link_directories($ENV{GMOCK_HOME}/mybuild $ENV{GTEST_HOME}/gtest/mybuild)
#add_definitions(-std=c++0x)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(sources 
   main.cpp 
   CharUtil.cpp
   StringUtil.cpp)
set(testSources
    CharUtilTest.cpp
    SoundexTest.cpp
    StringUtilTest.cpp)
add_executable(test ${testSources} ${sources})

#target_link_libraries(test pthread)
#target_link_libraries(test gmock)
#target_link_libraries(test gtest)

target_link_libraries(test PRIVATE Threads::Threads GTest::gtest GTest::gmock)
