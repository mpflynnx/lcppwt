project(chapterFirstExample)
cmake_minimum_required(VERSION 3.24.1)

find_package(GTest 1.17.0 REQUIRED)
find_package(Threads REQUIRED)

# Enable C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources 
   main.cpp 
   SoundexTest.cpp)
add_executable(test ${sources})
#target_link_libraries(test pthread)
#target_link_libraries(test gmock)
#target_link_libraries(test gtest)

target_link_libraries(test PRIVATE Threads::Threads GTest::gtest GTest::gmock)
