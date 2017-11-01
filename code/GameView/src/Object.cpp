#include <iostream>
#include "debug.hpp"
#include "Object.hpp"

namespace GameView {

Object::Object(Graphics& graphics,
               const std::string& filePath,
               int sourceX,
               int sourceY,
               int width,
               int height,
               int posX,
               int posY) :
            _x(posX),
            _y(posY)
{
    _sourceRect.x = sourceX;
    _sourceRect.y = sourceY;
    _sourceRect.w = width;
    _sourceRect.h = height;

    _objectSheet = SDL_CreateTextureFromSurface(graphics.getRenderer(),
                                                graphics.loadImage(filePath));
    if (_objectSheet == nullptr) {
        ERROR << "Error: Unable to load image\n";
    }

}

void Object::draw(Graphics &graphics, int x, int y) {
    SDL_Rect destinationRectangle = { x,
                                      y,
                                      _sourceRect.w,
                                      _sourceRect.h };
    graphics.render(_objectSheet, &_sourceRect, &destinationRectangle);
}

void Object::update() {

}


}
