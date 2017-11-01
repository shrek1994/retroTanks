cmake_minimum_required(VERSION 3.7)
project(retroTanks)

set(CMAKE_CXX_STANDARD 14)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})


INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(code code/GameView/inc)
set(SOURCE_FILES code/main.cpp
        code/GameView/src/Graphics.cpp
        code/GameView/inc/Graphics.hpp
        code/GameView/src/Input.cpp
        code/GameView/inc/Input.hpp
        code/GameView/src/Game.cpp
        code/GameView/inc/Game.hpp
        code/GameView/src/Player.cpp
        code/GameView/inc/Player.hpp
        code/GameView/src/Object.cpp
        code/GameView/inc/Object.hpp
        code/GameView/src/AnimatedObject.cpp
        code/GameView/inc/AnimatedObject.hpp
        code/Direction.hpp
        code/debug.hpp)
add_executable(retroTanks ${SOURCE_FILES})

target_link_libraries(retroTanks ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})

FILE(COPY res DESTINATION "${CMAKE_BINARY_DIR}")
