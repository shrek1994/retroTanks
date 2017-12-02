#pragma once

#include "Object.hpp"

namespace Game {

class DestructibleObject : public Object {
public:
    DestructibleObject(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width,
                       int height);
};

}