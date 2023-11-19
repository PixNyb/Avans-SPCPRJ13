cmake_minimum_required(VERSION 3.27)

project(DeFunBobEngine-Test)

file(GLOB TEST_SOURCES *.cpp)

set(TEST_EXECUTABLES "")

foreach(_source ${TEST_SOURCES})
    get_filename_component(_executable ${_source} NAME_WE)
    list(APPEND TEST_EXECUTABLES ${_executable})
endforeach()

message(STATUS "Found tests: ${TEST_EXECUTABLES}")

file(GLOB_RECURSE HEADER_LIST ${PROJECT_SOURCE_DIR}/../include/*.hpp)

foreach(_headerFile ${HEADER_LIST})
    get_filename_component(_dir ${_headerFile} PATH)
    list(APPEND HEADER_DIRS ${_dir})
endforeach()

list(REMOVE_DUPLICATES HEADER_DIRS)

foreach(TEST_EXECUTABLE ${TEST_EXECUTABLES})
    add_executable(${TEST_EXECUTABLE} ${TEST_EXECUTABLE}.cpp)

    foreach(_headerDir ${HEADER_DIRS})
        target_include_directories(${TEST_EXECUTABLE} PUBLIC ${_headerDir})
    endforeach()

    target_link_libraries(${TEST_EXECUTABLE} PRIVATE DeFunBobEngine)

    find_package(SDL2 CONFIG REQUIRED)
    target_link_libraries(${TEST_EXECUTABLE} PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    )

    find_package(sdl2-gfx CONFIG REQUIRED)
    target_link_libraries(${TEST_EXECUTABLE} PRIVATE SDL2::SDL2_gfx)

    find_package(SDL2_image CONFIG REQUIRED)
    target_link_libraries(${TEST_EXECUTABLE} PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)

    find_package(SDL2_mixer CONFIG REQUIRED)
    target_link_libraries(${TEST_EXECUTABLE} PRIVATE $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>)

    find_package(SDL2_ttf CONFIG REQUIRED)
    target_link_libraries(${TEST_EXECUTABLE} PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)

    find_package(SDL2_net CONFIG REQUIRED)
    target_link_libraries(${TEST_EXECUTABLE} PRIVATE $<IF:$<TARGET_EXISTS:SDL2_net::SDL2_net>,SDL2_net::SDL2_net,SDL2_net::SDL2_net-static>)

    find_package(GTest CONFIG REQUIRED)
    target_link_libraries(${TEST_EXECUTABLE} PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)

    add_test(NAME ${TEST_EXECUTABLE} COMMAND ${TEST_EXECUTABLE})
endforeach()