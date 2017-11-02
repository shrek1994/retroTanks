#include "Map.hpp"


namespace GameView {

Map::Map(std::string mapName, Offset spawnPoint, Graphics& graphics) :
    _mapName(mapName),
    _spawnPoint(spawnPoint),
    _size(Offset{WINDOW_WIGHT, WINDOW_HEIGHT})
{
    loadMap(mapName, graphics);
}

void Map::loadMap(std::string mapName, Graphics& graphics) {
    _background = SDL_CreateTextureFromSurface(
            graphics.getRenderer(),
            graphics.loadImage("res/topDownTanks/Environment/sand.png"));
}

void Map::draw(Graphics& graphics) {
    SDL_Rect source = {0, 0, 128, 128};
    SDL_Rect destination;
    for (int x = 0 ; x < _size.x; ++x) {
        for (int y = 0 ; y < _size.y; ++y) {
            destination.x = x * 128;
            destination.y = y * 128;
            destination.w = 128;
            destination.h = 128;
            graphics.render(_background, &source, &destination);
        }
    }
}


}
