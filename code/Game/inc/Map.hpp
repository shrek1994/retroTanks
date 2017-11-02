#pragma once

#include <string>
#include "Animation.hpp"
#include "Graphics.hpp"

namespace Game {

class Map {
public:
    Map(std::string mapName, Offset spawnPoint, Graphics& graphics);
    void draw(Graphics& graphics);

private:
    std::string _mapName;
    Offset _spawnPoint;
    Offset _size;
    SDL_Texture* _background;

    void loadMap(std::string mapName, Graphics& graphics);
};


}
