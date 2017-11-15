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

void Object::draw(Graphics &graphics, double centerX, double centerY) {
    SDL_Rect destinationRectangle = {static_cast<int>(centerX - getWight() / 2),
                                     static_cast<int>(centerY - getHeight() / 2),
                                     static_cast<int>(getWight()),
                                     static_cast<int>(getHeight())};
    graphics.render(objectTexture, &sourceRect, &destinationRectangle);
}

double Object::getWight() const {
    return sourceRect.w * SCALE_WIGHT;
}

double Object::getHeight() const {
    return sourceRect.h * SCALE_HEIGHT;
}

}

bool operator==(const Game::Object& lhs, const Game::Object& rhs) {
    return &lhs == &rhs;
}

bool operator!=(const Game::Object& lhs, const Game::Object& rhs) {
    return !(lhs == rhs);
}