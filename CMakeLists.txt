cmake_minimum_required(VERSION 3.27)

project(DeFunBobEngine)

option(BUILD_CICD "Build for CICD" OFF)

# Include the test project
option(BUILD_TESTS "Build the tests" OFF)

# If the option is set to true or we're running a debug build, build the tests
if(BUILD_TESTS OR BUILD_CICD OR CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building tests")
    enable_testing()
    add_subdirectory(tests)
endif()

file(COPY ${PROJECT_SOURCE_DIR}/resources DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Generate coverage
option(GENERATE_COVERAGE "Generate coverage" OFF)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add cmake to the path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# Add source files
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Add header directories
file(GLOB_RECURSE HEADER_LIST ${PROJECT_SOURCE_DIR}/include/*.hpp)

foreach(_headerFile ${HEADER_LIST})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND HEADER_DIRS ${_dir})
endforeach()

list(REMOVE_DUPLICATES HEADER_DIRS)

# Add executable
add_library(DeFunBobEngine ${SOURCES})

# If the option is set to true or we're running a debug build, generate coverage
if(GENERATE_COVERAGE OR BUILD_CICD OR CMAKE_BUILD_TYPE STREQUAL "Debug")
    if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        include(ProcessorCount)
        ProcessorCount(N)

        if(NOT N EQUAL 0)
            message(STATUS "Building with coverage")
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g --coverage -fprofile-arcs -ftest-coverage")
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g --coverage -fprofile-arcs -ftest-coverage")
            target_link_libraries(DeFunBobEngine PRIVATE gcov)
        endif()
    endif()
endif()

# Include headers
foreach(_headerDir ${HEADER_DIRS})
    target_include_directories(DeFunBobEngine PUBLIC ${_headerDir})
endforeach()

# Copy the cmake folder to the build directory
file(COPY ${PROJECT_SOURCE_DIR}/cmake DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Install library and header files
install(TARGETS DeFunBobEngine DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include/${PROJECT_NAME})

# Add uninstall target
configure_file(
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/uninstall.cmake"
    IMMEDIATE @ONLY
)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake/uninstall.cmake
)

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

# Add nlohmann_json
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(DeFunBobEngine PRIVATE nlohmann_json::nlohmann_json)

# Add fmt
find_package(fmt CONFIG REQUIRED)

if(APPLE)
    target_link_libraries(DeFunBobEngine PRIVATE fmt::fmt-header-only)
else()
    target_link_libraries(DeFunBobEngine PRIVATE fmt::fmt)
endif()

# Add box2d
find_package(box2d CONFIG REQUIRED)
target_link_libraries(DeFunBobEngine PRIVATE box2d::box2d)

# Add SFML
find_package(SFML COMPONENTS system audio CONFIG REQUIRED)
target_link_libraries(DeFunBobEngine PRIVATE sfml-system sfml-audio)

# Add sandbox
add_subdirectory(sandbox)