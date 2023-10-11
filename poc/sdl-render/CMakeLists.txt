cmake_minimum_required(VERSION 3.10)

# Zet de naam van het project en de gebruikte taal
project(SdlRenderPoc)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add cmake to the path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Copy the assets folder to the build directory
file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/poc/sdl-render)

# Vind de SDL2-bibliotheek
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
    )

# Add your project's include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Voeg alle bronbestanden toe aan de uitvoerbare bestanden
file(GLOB SOURCES "src/*.cpp")
add_executable(SdlRenderPoc ${SOURCES})

# Link de SDL2-bibliotheek aan het uitvoerbare bestand
target_link_libraries(SdlRenderPoc ${SDL2_LIBRARIES} SDL2_image)