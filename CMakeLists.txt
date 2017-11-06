cmake_minimum_required(VERSION 3.7)
project(retroTanks)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Werror")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})


INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image >= 2.0.0)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(
        code
        code/Game/inc
        code/AI/inc
)

set(SOURCE_FILES
        code/main.cpp
        code/Game/src/Graphics.cpp
        code/Game/inc/Graphics.hpp
        code/Game/src/Input.cpp
        code/Game/inc/Input.hpp
        code/Game/src/Game.cpp
        code/Game/inc/Game.hpp
        code/Game/src/Tank.cpp
        code/Game/inc/Tank.hpp
        code/Game/src/Object.cpp
        code/Game/inc/Object.hpp
        code/Game/src/AnimatedObject.cpp
        code/Game/inc/AnimatedObject.hpp
        code/Animation.hpp
        code/debug.hpp
        code/Game/src/Map.cpp
        code/Game/inc/Map.hpp
        code/Game/src/Bullet.cpp
        code/Game/inc/Bullet.hpp
        code/Constants.hpp
        code/Game/src/Smoke.cpp
        code/Game/inc/Smoke.hpp
        code/AI/src/Player.cpp
        code/AI/inc/Player.hpp
        code/AI/inc/ITankController.hpp
        code/Game/inc/ObjectNotifier.hpp
        )

add_executable(retroTanks ${SOURCE_FILES})

target_link_libraries(retroTanks ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

FILE(COPY res DESTINATION "${CMAKE_BINARY_DIR}")
