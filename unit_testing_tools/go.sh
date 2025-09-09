#!/bin/bash
rm -rf build
mkdir build && cd build
cmake .. --trace-source=CMakeLists.txt
make
./test
