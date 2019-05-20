project (Minify)
cmake_minimum_required(VERSION 3.3)

# find OpenCV
find_package(OpenCV REQUIRED)
 
add_executable(Minify.1 minify.1.cpp)
target_include_directories(Minify.1 PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(Minify.1 ${OpenCV_LIBS})

add_executable(Minify.2 minify.2.cpp)
target_include_directories(Minify.2 PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(Minify.2 ${OpenCV_LIBS})

add_executable(Minify.3 minify.3.cpp)
target_include_directories(Minify.3 PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(Minify.3 ${OpenCV_LIBS})
