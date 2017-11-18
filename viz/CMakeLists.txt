cmake_minimum_required(VERSION 2.6)
project(viz)

add_executable(viz main.cpp )

#install(TARGETS detcharuco RUNTIME DESTINATION bin)
find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(viz ${OpenCV_LIBS} )	 	
