cmake_minimum_required (VERSION 3.0)
project (machineLearningExample)
set(CMAKE_CXX_FLAGS "-std=c++11 -g")
find_package(OpenCV 3.3 REQUIRED)

LINK_LIBRARIES(${OpenCV_LIBS})

add_executable(example example.cpp)
