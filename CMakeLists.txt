cmake_minimum_required(VERSION 3.10)

# Project name
project(Karus_hotkeys)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(Karus_hotkeys WIN32 src/main.cpp)
