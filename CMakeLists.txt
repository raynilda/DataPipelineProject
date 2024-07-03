cmake_minimum_required(VERSION 3.10)

project(DataPipelineProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(DataPipelineProject main.cpp MovingAverages.cpp)

target_include_directories(DataPipelineProject PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
