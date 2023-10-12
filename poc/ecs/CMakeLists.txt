cmake_minimum_required(VERSION 3.26)
project(ECS)

set(CMAKE_CXX_STANDARD 17)

set (CMAKE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/core")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_OUTPUT_DIRECTORY})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_OUTPUT_DIRECTORY})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_OUTPUT_DIRECTORY})

# Executables
## Core
add_executable(${PROJECT_NAME}
        src/core/main.cpp
        src/core/app.cpp
        src/renderer/render_system.cpp
        src/systems/movement_system.cpp
        src/systems/player_control_system.cpp
        src/core/input_manager.cpp
        src/scene/scene_manager.cpp
        src/scene/scene.cpp
        src/entities/game_object.cpp
        src/renderer/render_system.cpp
        src/systems/scene_system.cpp)

## Includes
target_include_directories(${PROJECT_NAME} PUBLIC
        include/components
        include/core
        include/entities
        include/systems
        include/scene
        include/renderer)

# Linking libs
## EnTT
find_package(EnTT CONFIG REQUIRED)
target_link_libraries(ECS PRIVATE EnTT::EnTT)

## SDL2
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(ECS
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)