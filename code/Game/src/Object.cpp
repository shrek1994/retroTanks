#include "debug.hpp"
#include "Constants.hpp"
#include "Object.hpp"
#include "Graphics.hpp"

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

void Object::draw(Graphics &graphics, double centerX, double centerY) {
    SDL_Rect destinationRectangle = {static_cast<int>(centerX - getWight() / 2),
                                     static_cast<int>(centerY - getHeight() / 2),
                                     static_cast<int>(getWight()),
                                     static_cast<int>(getHeight())};
    graphics.render(_objectTexture, &_sourceRect, &destinationRectangle);
}

double Object::getWight() {
    return _sourceRect.w * SCALE_WIGHT;
}

double Object::getHeight() {
    return _sourceRect.h * SCALE_HEIGHT;
}

bool Object::operator==(const Object& obj) {
    return this == &obj;
}

}
