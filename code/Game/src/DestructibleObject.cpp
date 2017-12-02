#include "DestructibleObject.hpp"

namespace Game {


DestructibleObject::DestructibleObject(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY,
                                       int width, int height, int centerX, int centerY)
    : IndestructibleObject(graphics, filePath, sourceX, sourceY, width, height, centerX, centerY) {}

bool DestructibleObject::shouldBeRemove() const {
    return isDestroyed;
}

void DestructibleObject::setDestroyed() {
    isDestroyed = true;
}

}
