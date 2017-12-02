#pragma once

#include "IndestructibleObject.hpp"

namespace Game {

class DestructibleObject : public IndestructibleObject {
public:
    DestructibleObject(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width,
                       int height, int centerX, int centerY);

    bool shouldBeRemove() const override;
    void setDestroyed() override;

private:
    bool isDestroyed = false;
};

}
