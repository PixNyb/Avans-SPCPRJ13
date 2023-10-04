cmake_minimum_required(VERSION 3.22)

project(SdlInputPoc)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/*.cpp)

# Add SDL2
set(SDL2_BUILDING_LIBRARY ON)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add executable
add_executable(SdlInputPoc ${SOURCES})

# Use SDL_MAIN_NEEDED or SDL_MAIN_AVAILABLE
if(SDL2_FOUND)
    if(SDL2MAIN_LIBRARY)
        target_link_libraries(SdlInputPoc ${SDL2_LIBRARIES} ${SDL2MAIN_LIBRARY})
    else()
        target_link_libraries(SdlInputPoc ${SDL2_LIBRARIES})
        target_compile_definitions(SdlInputPoc PRIVATE SDL_MAIN_NEEDED)
    endif()
else()
    message(FATAL_ERROR "SDL2 not found")
endif()