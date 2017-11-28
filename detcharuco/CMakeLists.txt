cmake_minimum_required(VERSION 2.6)
project(detcharuco)

add_executable(detcharuco main.cpp)

install(TARGETS detcharuco RUNTIME DESTINATION bin)
find_package( OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(detcharuco ${OpenCV_LIBS} )	 	
