cmake_minimum_required(VERSION 2.6)
 
PROJECT(Moments)

# OpenCV
FIND_PACKAGE(OpenCV REQUIRED)
 
ADD_EXECUTABLE(Moments main.cpp)
 
TARGET_LINK_LIBRARIES(Moments ${OpenCV_LIBS})
