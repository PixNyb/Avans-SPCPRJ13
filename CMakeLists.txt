cmake_minimum_required(VERSION 3.22)

project(DeFunBobEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Add header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add executable
add_executable(DeFunBobEngine ${SOURCES})