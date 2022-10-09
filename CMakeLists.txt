cmake_minimum_required(VERSION 2.6)
project(2)
file(GLOB CPP "*.cpp")
add_executable(${PROJECT_NAME} ${CPP})
