#!/bin/bash
rm -rf build
mkdir build && cd build
cmake -DCMAKE_BUILD_TYPE=Debug .. --trace-source=CMakeLists.txt
make
./test
