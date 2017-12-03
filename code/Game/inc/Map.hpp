#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <list>

#include "Animation.hpp"
#include "Tree.hpp"

class Graphics;
namespace Game {
class Tree;

class Map {
public:
    Map(std::string mapName, SDL_Point spawnPoint, Graphics& graphics);
    void draw(Graphics& graphics);
    void drawTree(Graphics& graphics);

private:
    void loadMap(std::string mapName, Graphics& graphics);

    std::string _mapName;
    SDL_Point _spawnPoint;
    SDL_Point _size;
    SDL_Texture* _background;
    std::list<Tree> trees;
};


}
