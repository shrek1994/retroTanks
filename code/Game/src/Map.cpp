#include <ObjectOwner.hpp>
#include <Barrel.hpp>
#include <Sandbag.hpp>
#include "debug.hpp"
#include "Constants.hpp"
#include "Map.hpp"
#include "Graphics.hpp"


namespace Game {

Map::Map(std::string mapName, Graphics& graphics, ObjectOwner& objectOwner) :
    mapName(mapName),
    size(SDL_Point{WINDOW_WIGHT, WINDOW_HEIGHT}),
    objectOwner(objectOwner),
    config(Config::getConfig()),
    mt(std::random_device()())
{
    loadMap(mapName, graphics);
    createObjects(graphics);
}

void Map::createObjects(Graphics& graphics) {
    std::uniform_int_distribution<> weight(0, WINDOW_WIGHT);
    std::uniform_int_distribution<> height(
            static_cast<int>(SCALE_HEIGHT * TANK_HEIGHT * 1.3),
            static_cast<int>(WINDOW_HEIGHT - (SCALE_HEIGHT * TANK_HEIGHT * 1.3)));
    int positionX, positionY;
    for (unsigned i = 0 ; i < config.numberOfTrees; ++i) {
        positionX = weight(mt);
        positionY = height(mt);
        trees.emplace_back(graphics, positionX, positionY);
    }

    for (unsigned i = 0 ; i < config.numberOfBarrels; ++i) {
        positionX = weight(mt);
        positionY = height(mt);
        objectOwner.addObject(std::make_unique<Barrel>(graphics, objectOwner, positionX, positionY));
    }

    for (unsigned i = 0 ; i < config.numberOfSandbags; ++i) {
        positionX = weight(mt);
        positionY = height(mt);
        objectOwner.addObject(std::make_unique<Sandbag>(graphics, positionX, positionY));
    }
}

void Map::loadMap(std::string mapName, Graphics& graphics) {
    background = SDL_CreateTextureFromSurface(
            graphics.getRenderer(),
            graphics.loadImage("res/dirt.png"));
    if (!background) {
        ERROR << "Error: Unable to load map: " << mapName << "\n";
        SDL_Quit();
        std::exit(EXIT_FAILURE);
    }
}

void Map::drawBackground(Graphics& graphics) {
    SDL_Rect source = {0, 0, 128, 128};
    SDL_Rect destination{};
    for (int x = 0 ; x * AREA_WIGHT < size.x; ++x) {
        for (int y = 0 ; y  * AREA_HEIGHT< size.y; ++y) {
            destination.x = x * AREA_WIGHT;
            destination.y = y * AREA_HEIGHT;
            destination.w = AREA_WIGHT;
            destination.h = AREA_HEIGHT;
            graphics.render(background, &source, &destination);
        }
    }
}

void Map::drawTrees(Graphics& graphics){
    for (auto& tree : trees) {
        tree.draw(graphics);
    }
}


}
