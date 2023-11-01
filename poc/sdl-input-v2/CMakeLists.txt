cmake_minimum_required(VERSION 3.10)

project(SDLV2Poc)

set(CMAKE_CXX_STANDARD 14)

# Find SDL2 library
find_package(SDL2 REQUIRED)

# Add executable
add_executable(SDLV2Poc main.cpp)

include_directories(${SDL2_INCLUDE_DIRS})

# Link SDL2 library
target_link_libraries(SDLV2Poc ${SDL2_LIBRARIES})
