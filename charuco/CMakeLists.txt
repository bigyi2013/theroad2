cmake_minimum_required(VERSION 2.6)
project(charuco)

add_executable(charuco main.cpp)

find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(charuco ${OpenCV_LIBS} )	 	
