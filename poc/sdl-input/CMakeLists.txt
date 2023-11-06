cmake_minimum_required(VERSION 3.27)

project(SdlInputPoc)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(SdlInputPoc main.cpp)

# Add SDL2
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(SdlInputPoc
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)