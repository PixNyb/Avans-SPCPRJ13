cmake_minimum_required(VERSION 3.10)

project(SDLV2Poc)

set(CMAKE_CXX_STANDARD 14)

# Add executable
add_executable(SDLV2Poc main.cpp)

# Find SDL2 library
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(SDLV2Poc
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)
