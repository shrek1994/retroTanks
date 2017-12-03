#include "common/debug.hpp"
#include "common/Constants.hpp"
#include "Object.hpp"
#include "common/Graphics.hpp"

namespace Menu {

Object::Object(Graphics& graphics,
               const std::string& filePath,
               int sourceX,
               int sourceY,
               int width,
               int height)
{
    sourceRect.x = sourceX;
    sourceRect.y = sourceY;
    sourceRect.w = width;
    sourceRect.h = height;

    objectTexture = SDL_CreateTextureFromSurface(graphics.getRenderer(),
                                                 graphics.loadImage(filePath));
    if (objectTexture == nullptr) {
        ERROR << "Error: Unable to load image: " << filePath << "\n";
        std::exit(EXIT_FAILURE);
    }

}

void Object::draw(Graphics &graphics, int centerX, int centerY) {
    SDL_Rect destinationRectangle = {centerX - wight / 2,
                                     centerY - height / 2,
                                     wight,
                                     height};
    graphics.render(objectTexture, &sourceRect, &destinationRectangle);
}

}