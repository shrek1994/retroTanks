#pragma once

#include <SDL2/SDL.h>
#include <string>

#include "Animation.hpp"

namespace Game {
class Graphics;

class Map {
public:
    Map(std::string mapName, SDL_Point spawnPoint, Graphics& graphics);
    void draw(Graphics& graphics);

private:
    std::string _mapName;
    SDL_Point _spawnPoint;
    SDL_Point _size;
    SDL_Texture* _background;

    void loadMap(std::string mapName, Graphics& graphics);
};


}
