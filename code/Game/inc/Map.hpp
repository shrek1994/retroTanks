#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <list>
#include <random>
#include <Config.hpp>

#include "Animation.hpp"
#include "Tree.hpp"

class Graphics;
namespace Game {
class Tree;

class Map {
public:
    Map(std::string mapName, Graphics& graphics, ObjectOwner& objectOwner);
    void drawBackground(Graphics& graphics);
    void drawTrees(Graphics& graphics);


private:
    void loadMap(std::string mapName, Graphics& graphics);
    void createObjects(Graphics& graphics);

    std::string mapName;
    SDL_Point size;
    SDL_Texture* background;
    ObjectOwner& objectOwner;
    const Config& config;
    std::mt19937 mt;
    std::list<Tree> trees;
};


}
