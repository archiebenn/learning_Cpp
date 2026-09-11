cmake_minimum_required(VERSION 3.10.0)

# set compiler to be g++-14 BEFORE project call
set(CMAKE_CXX_COMPILER g++-14)

#project name
project (hello_cmake)

# require it to use c++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# adds an executable target named hello_age that is built from the specified source files (ie main.cpp and age.cpp)
add_executable(hello_age main.cpp age.cpp)

# navigate to build_unix and run cmake ..
# this then builds projects and creates a Makefile in the folder
# then can run 'make' to compile and link the full project