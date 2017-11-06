#include "debug.hpp"
#include "Constants.hpp"
#include "Map.hpp"
#include "Graphics.hpp"


namespace Game {

Map::Map(std::string mapName, SDL_Point spawnPoint, Graphics& graphics) :
    _mapName(mapName),
    _spawnPoint(spawnPoint),
    _size(SDL_Point{WINDOW_WIGHT, WINDOW_HEIGHT})
{
    loadMap(mapName, graphics);
}

void Map::loadMap(std::string mapName, Graphics& graphics) {
    _background = SDL_CreateTextureFromSurface(
            graphics.getRenderer(),
            graphics.loadImage("res/dirt.png"));
    if (_background == nullptr) {
        ERROR << "Error: Unable to load map: " << mapName << "\n";
        SDL_Quit();
        std::exit(EXIT_FAILURE);
    }
}

void Map::draw(Graphics& graphics) {
    SDL_Rect source = {0, 0, 128, 128};
    SDL_Rect destination;
    for (int x = 0 ; x * AREA_WIGHT < _size.x; ++x) {
        for (int y = 0 ; y  * AREA_HEIGHT< _size.y; ++y) {
            destination.x = x * AREA_WIGHT;
            destination.y = y * AREA_HEIGHT;
            destination.w = AREA_WIGHT;
            destination.h = AREA_HEIGHT;
            graphics.render(_background, &source, &destination);
        }
    }
}


}
