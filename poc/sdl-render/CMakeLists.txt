cmake_minimum_required(VERSION 3.10)

# Zet de naam van het project en de gebruikte taal
project(SdlRenderPoc)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add cmake to the path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Copy the assets folder to the build directory
file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Voeg alle bronbestanden toe aan de uitvoerbare bestanden
file(GLOB SOURCES "src/*.cpp")

# Add your project's include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(SdlRenderPoc ${SOURCES})

# Vind de SDL2-bibliotheek
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(SdlRenderPoc
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

find_package(SDL2_image CONFIG REQUIRED)
target_link_libraries(SdlRenderPoc
    PRIVATE
    $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
)
