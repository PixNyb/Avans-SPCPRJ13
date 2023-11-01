cmake_minimum_required(VERSION 3.22)

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


# Add POC's
file(GLOB SUBDIR_LIST RELATIVE ${PROJECT_SOURCE_DIR}/poc ${PROJECT_SOURCE_DIR}/poc/*)
foreach(SUBDIR ${SUBDIR_LIST})
    if(IS_DIRECTORY ${PROJECT_SOURCE_DIR}/poc/${SUBDIR})
        add_subdirectory(${PROJECT_SOURCE_DIR}/poc/${SUBDIR})
    endif()
endforeach()

message("Include directory: ${PROJECT_SOURCE_DIR}/include")
message("API directory: ${PROJECT_SOURCE_DIR}/include/API")
