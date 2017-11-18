cmake_minimum_required(VERSION 2.6)
project(pnp)

add_executable(pnp main.cpp)

find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(pnp ${OpenCV_LIBS} )	 	
