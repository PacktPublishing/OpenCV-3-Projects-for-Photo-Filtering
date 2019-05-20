project (Ambiance)
cmake_minimum_required(VERSION 3.3)

# find OpenCV
find_package(OpenCV REQUIRED)
 
add_executable(Ambiance.1 ambiance.1.cpp)
target_include_directories(Ambiance.1 PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ambiance.1 ${OpenCV_LIBS})

add_executable(Ambiance.2 ambiance.2.cpp)
target_include_directories(Ambiance.2 PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ambiance.2 ${OpenCV_LIBS})

add_executable(Ambiance.3 ambiance.3.cpp)
target_include_directories(Ambiance.3 PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(Ambiance.3 ${OpenCV_LIBS})

add_executable(Load.vid load.vid.cpp)
target_include_directories(Load.vid PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(Load.vid ${OpenCV_LIBS})

