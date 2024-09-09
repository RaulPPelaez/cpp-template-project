# Our C++ project contains a single executable built from main.cpp
# It uses the definitions in my_library.cpp,  which are defined in the header file my_library.h
# Lets compile the library first
add_library(my_library SHARED my_library.cpp)
# Now we compile the executable
# We need to tell CMake that we want to build an executable
add_executable(my_executable main.cpp)
# We need to tell CMake that the executable depends on the library
# This is done by linking the library to the executable
target_link_libraries(my_executable my_library)
