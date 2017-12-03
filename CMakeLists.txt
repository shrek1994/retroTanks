cmake_minimum_required(VERSION 3.5)
project(retroTanks)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Werror")
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})


INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image >= 2.0.0)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(
        code
        code/Game/inc
        code/AI/inc
        libs/inc
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
        code/AI/src/Bot.cpp
        code/AI/inc/Bot.hpp
        code/AI/inc/ITankController.hpp
        code/Game/inc/ObjectOwner.hpp
        code/Game/src/Sandbag.cpp
        code/Game/inc/Sandbag.hpp
        code/Game/src/DestructibleObject.cpp
        code/Game/inc/DestructibleObject.hpp
        code/Game/src/IndestructibleObject.cpp
        code/Game/inc/IndestructibleObject.hpp
        code/Game/src/Barrel.cpp
        code/Game/inc/Barrel.hpp
        code/Game/src/DamagedBarrel.cpp
        code/Game/inc/DamagedBarrel.hpp
        code/Game/src/Tree.cpp
        code/Game/inc/Tree.hpp
        code/Config.cpp
        code/Config.hpp
        libs/inc/json.hpp)

add_executable(retroTanks ${SOURCE_FILES})

target_link_libraries(retroTanks ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

FILE(COPY res DESTINATION "${CMAKE_BINARY_DIR}")
