cmake_minimum_required(VERSION 3.10)

# Zet de naam van het project en de gebruikte taal
project(SDLPoC)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 14)

# Add your project's include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Vind de SDL2-bibliotheek
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIRS}
    ${SDL2_IMAGE_INCLUDE_DIRS}
)

# Voeg alle bronbestanden toe aan de uitvoerbare bestanden
file(GLOB SOURCES "src/*.cpp")
add_executable(SDLPoC ${SOURCES})

# Link de SDL2-bibliotheek aan het uitvoerbare bestand
target_link_libraries(SDLPoC ${SDL2_LIBRARIES} SDL2_image::SDL2_image)

