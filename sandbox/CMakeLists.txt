project(Sandbox)

add_executable(Sandbox main.cpp)
target_link_libraries(Sandbox PRIVATE DeFunBobEngine)

# Add SDL2
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(Sandbox
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

# Add SDL2_gfx
find_package(sdl2-gfx CONFIG REQUIRED)
target_link_libraries(Sandbox PRIVATE SDL2::SDL2_gfx)

# Add SDL2_image
find_package(SDL2_image CONFIG REQUIRED)
target_link_libraries(Sandbox PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)

# Add SDL2_mixer
find_package(SDL2_mixer CONFIG REQUIRED)
target_link_libraries(Sandbox PRIVATE $<IF:$<TARGET_EXISTS:SDL2_mixer::SDL2_mixer>,SDL2_mixer::SDL2_mixer,SDL2_mixer::SDL2_mixer-static>)

# Add SDL2_ttf
find_package(SDL2_ttf CONFIG REQUIRED)
target_link_libraries(Sandbox PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>)

# Add SDL2_net
find_package(SDL2_net CONFIG REQUIRED)
target_link_libraries(Sandbox PRIVATE $<IF:$<TARGET_EXISTS:SDL2_net::SDL2_net>,SDL2_net::SDL2_net,SDL2_net::SDL2_net-static>)

# Add nlohmann_json
find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(DeFunBobEngine PRIVATE nlohmann_json::nlohmann_json)

# Add fmt
find_package(fmt CONFIG REQUIRED)
target_link_libraries(DeFunBobEngine PRIVATE fmt::fmt)

# Add box2d
find_package(box2d CONFIG REQUIRED)
target_link_libraries(Sandbox PRIVATE box2d::box2d)