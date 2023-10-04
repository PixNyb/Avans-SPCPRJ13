cmake_minimum_required(VERSION 3.22)

project(SdlRenderPoc)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)

# Add executable
add_executable(SdlRenderPoc ${SOURCES})