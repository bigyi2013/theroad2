cmake_minimum_required(VERSION 2.6)
project(pcl_test)

find_package(PCL 1.7 REQUIRED COMPONENTS common io)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcl_test main.cpp)

install(TARGETS pcl_test RUNTIME DESTINATION bin)
