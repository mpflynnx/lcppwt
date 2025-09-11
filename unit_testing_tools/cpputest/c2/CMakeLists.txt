project(chapterFirstExample)
cmake_minimum_required(VERSION 3.24.1)

#function(print)
    #foreach(var ${ARGN})
        #message("${var} = ${${var}}")
    #endforeach()
#endfunction()

#print(PROJECT_NAME)

find_package(Threads REQUIRED)

# Enable C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories($ENV{CPPUTEST_HOME}/include)
link_directories($ENV{CPPUTEST_HOME}/lib)

#print(include_directories $ENV{CPPUTEST_HOME}/include)

set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(sources testmain.cpp SoundexTest.cpp)
add_executable(test ${sources})

target_link_libraries(test CppUTest)
target_link_libraries(test pthread)
