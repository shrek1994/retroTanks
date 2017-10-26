#include <iostream>
#include "Player.hpp"

namespace GameView {

Player::Player(Graphics& graphics,
               const std::string& filePath,
               int sourceX,
               int sourceY,
               int width,
               int height, float posX, float posY) :
            _x(posX),
            _y(posY)
{
    _sourceRect.x = sourceX;
    _sourceRect.y = sourceY;
    _sourceRect.w = width;
    _sourceRect.h = height;

    _playerSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(),
                                                graphics.loadImage(filePath));
    if (_playerSheet == nullptr) {
        std::cerr << "Error: Unable to load image\n";
    }

}

void Player::draw(Graphics &graphics, int x, int y) {
    SDL_Rect destinationRectangle = { x,
                                      y,
                                      _sourceRect.w,
                                      _sourceRect.h };
    graphics.blitSurface(_playerSheet, &_sourceRect, &destinationRectangle);
}

void Player::update() {

}


}
