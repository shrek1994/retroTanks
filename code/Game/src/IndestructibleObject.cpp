#include "IndestructibleObject.hpp"

namespace Game {


IndestructibleObject::IndestructibleObject(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY,
                                       int width, int height,int centerX, int centerY)
        : Object(graphics, filePath, sourceX, sourceY, width,height),
          _centerX(centerX), _centerY(centerY) {}


void IndestructibleObject::update(int) {

}

bool IndestructibleObject::shouldBeRemove() const {
    return false;
}

void IndestructibleObject::draw(Graphics& graphics) {
    Object::draw(graphics, _centerX, _centerY);
}

SDL_Rect IndestructibleObject::getRectangle() const {
    return SDL_Rect{static_cast<int>(_centerX - getWight() / 2),
                    static_cast<int>(_centerY - getHeight() / 2),
                    static_cast<int>(getWight()),
                    static_cast<int>(getHeight())};
}

}
