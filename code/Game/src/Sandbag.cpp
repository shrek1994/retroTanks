#include "Sandbag.hpp"

namespace Game {

Sandbag::Sandbag(Graphics& graphics, int centerX, int centerY)
        : IndestructibleObject(graphics, "res/sandbagBrown.png", 0, 0, 66, 44, centerX, centerY)
{}

}