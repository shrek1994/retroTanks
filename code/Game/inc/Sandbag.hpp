#pragma once

#include "IndestructibleObject.hpp"

namespace Game {

class Sandbag : public IndestructibleObject {
public:
    Sandbag(Game::Graphics& graphics, int centerX, int centerY);
};


}
