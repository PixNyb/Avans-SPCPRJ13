cmake_minimum_required(VERSION 3.22)

project(SdlInputPoc)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)

# Add SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add executable
add_executable(SdlInputPoc main.cpp)
target_link_libraries(SdlInputPoc ${SDL2_LIBRARIES})