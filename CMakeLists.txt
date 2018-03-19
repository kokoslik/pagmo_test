cmake_minimum_required(VERSION 2.6)
project(pagmo_test)
set (CMAKE_CXX_STANDARD 11)
find_package(MPI REQUIRED)
find_package(Boost COMPONENTS thread system signals program_options serialization REQUIRED)
include_directories(${MPI_INCLUDE_PATH})


include_directories(/home/kokos/cpp/libs/pagmo/include/pagmo/src)

add_definitions(-DPAGMO_ENABLE_MPI)

add_executable(pagmo_test main.cpp)
target_link_libraries(pagmo_test ${MPI_LIBRARIES})
target_link_libraries(pagmo_test /home/kokos/cpp/libs/pagmo/lib/libpagmo.a)
target_link_libraries(pagmo_test ${Boost_LIBRARIES})

