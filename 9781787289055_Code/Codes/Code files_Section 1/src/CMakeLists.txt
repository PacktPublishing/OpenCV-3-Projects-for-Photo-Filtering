project (GettingStarted)				
cmake_minimum_required(VERSION 3.0)

# find OpenCV
find_package(OpenCV REQUIRED)

add_executable(LoadingImages loading_images.cpp)
target_include_directories(LoadingImages PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(LoadingImages ${OpenCV_LIBS})
