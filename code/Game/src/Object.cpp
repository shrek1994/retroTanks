#include <iostream>
#include <Constants.hpp>
#include "debug.hpp"
#include "Object.hpp"

namespace Game {

Object::Object(Graphics& graphics,
               const std::string& filePath,
               int sourceX,
               int sourceY,
               int width,
               int height)
{
    _sourceRect.x = sourceX;
    _sourceRect.y = sourceY;
    _sourceRect.w = width;
    _sourceRect.h = height;

    _objectTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(),
                                                graphics.loadImage(filePath));
    if (_objectTexture == nullptr) {
        ERROR << "Error: Unable to load image: " << filePath << "\n";
        std::exit(EXIT_FAILURE);
    }

}

void Object::draw(Graphics &graphics, int x, int y) {
    SDL_Rect destinationRectangle = { x,
                                      y,
                                      static_cast<int>(_sourceRect.w * SCALE_WIGHT),
                                      static_cast<int>(_sourceRect.h * SCALE_HEIGHT)};
    graphics.render(_objectTexture, &_sourceRect, &destinationRectangle);
}

}
