cmake_minimum_required(VERSION 2.6)
project(aruco)

add_executable(aruco main.cpp)

find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(aruco ${OpenCV_LIBS} )	 	
