# the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

project(sort VERSION 1.0)

# C++ standard (C++11, C++14, C++17)
set(CMAKE_CXX_STANDARD 11)

add_library(sort
    sort.cpp
)

add_executable(test
    test.cpp
)

target_link_libraries(test PRIVATE sort)
