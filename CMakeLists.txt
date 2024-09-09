# Every CMake project needs to start with these two lines
cmake_minimum_required(VERSION 3.20) # This is the minimum version of CMake required
project(MyVeryCoolProject VERSION 1.0) # This is the name of the project and its versino


set(CMAKE_CXX_STANDARD 17) # This sets the C++ standard to C++17
set(CMAKE_CXX_STANDARD_REQUIRED True) # This tells CMake that the stdandard must be available

# We place the executables in the bin directory
set(RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# We place the libraries in the lib directory
set(LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Our C++ project contains a single executable built from src/main.cpp
# It uses the definitions in src/my_library.cpp,  which are defined in the header file src/my_library.h
# We normally have a CMakeLists.txt file in each directory that has something that needs to be built
add_subdirectory(src)
