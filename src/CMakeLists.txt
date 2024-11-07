include_directories(${CMAKE_SOURCE_DIR}/include)
include(FetchContent)
FetchContent_Declare(Matplot++
  GIT_REPOSITORY  https://github.com/alandefreitas/matplotplusplus
  GIT_TAG         v1.2.1
)
FetchContent_MakeAvailable(Matplot++)
link_libraries(Matplot++::matplot)
add_executable(main_zipfs_containers main_zipfs_containers.cpp)
add_executable(main_zipfs_algorithms main_zipfs_algorithms.cpp)
