include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Make all targets in this directory look for headers here
include_directories(${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/include)
# Make all targets in this directory link against Gtest
link_libraries(GTest::gtest_main)

add_executable(test_split test_split.cpp)
target_link_libraries(test_split split) # Note that we link against the library
gtest_discover_tests(test_split)

add_executable(test_mytype test_mytype.cpp)
gtest_discover_tests(test_mytype)

add_executable(test_sum test_sum.cpp)
gtest_discover_tests(test_sum)

add_executable(test_pair test_pair.cpp)
gtest_discover_tests(test_pair)

add_executable(test_transform test_transform.cpp) # Compile a test source
gtest_discover_tests(test_transform)            # Register the tests to gtest

add_executable(test_raw_pointer test_raw_pointer.cpp)
gtest_discover_tests(test_raw_pointer)

add_executable(test_flexible_container test_flexible_container.cpp)
gtest_discover_tests(test_flexible_container)
