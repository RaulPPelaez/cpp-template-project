
# Look for headers in the include directory
include_directories(${CMAKE_SOURCE_DIR}/include)
add_library(student SHARED student.cpp)
add_library(dynamic_array SHARED dynamic_array.cpp)
add_executable(rule_of_0 rule_of_0.cpp)
