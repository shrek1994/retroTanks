cmake_minimum_required(VERSION 3.7)
project(retroTanks)

set(CMAKE_CXX_STANDARD 17)


find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})


INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(GameView)
set(SOURCE_FILES main.cpp GameView/Graphics.cpp GameView/Graphics.hpp GameView/Input.cpp GameView/Input.hpp GameView/Game.cpp GameView/Game.hpp)
add_executable(retroTanks ${SOURCE_FILES})

target_link_libraries(retroTanks ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
