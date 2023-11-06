cmake_minimum_required(VERSION 3.27)

project(DeFunBobEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add cmake to the path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Add source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/apps/*.cpp)

# Add header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add executable
add_executable(DeFunBobEngine ${SOURCES})

target_include_directories(DeFunBobEngine PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(DeFunBobEngine PRIVATE ${PROJECT_SOURCE_DIR}/include/API)

# Add SDL2
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(DeFunBobEngine
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

# Add SDL2_gfx
find_package(sdl2-gfx CONFIG REQUIRED)
target_link_libraries(DeFunBobEngine PRIVATE SDL2::SDL2_gfx)

# Add SDL2_image
find_package(SDL2_image CONFIG REQUIRED)
target_link_libraries(DeFunBobEngine PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)

# Add SDL2_mixer
find_package(SDL2_mixer CONFIG REQUIRED)
target_link_libraries(DeFunBobEngine PRIVATE $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>)

# Add SDL2_ttf
find_package(SDL2_ttf CONFIG REQUIRED)
target_link_libraries(DeFunBobEngine PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)

# Add SDL2_net
find_package(SDL2_net CONFIG REQUIRED)
target_link_libraries(DeFunBobEngine PRIVATE $<IF:$<TARGET_EXISTS:SDL2_net::SDL2_net>,SDL2_net::SDL2_net,SDL2_net::SDL2_net-static>)