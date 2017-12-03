#include <array>
#include "Sandbag.hpp"

namespace Game {

namespace {
const std::string BEIGE_SANDBAG = "res/sandbagBeige.png";
const std::string BROWN_SANDBAG = "res/sandbagBrown.png";
const std::array<std::string, 2> colorsSandbags = {BROWN_SANDBAG,
                                                   BEIGE_SANDBAG};

std::string getBarrelName() {
    static char color = 0;
    return colorsSandbags[color++ % colorsSandbags.size()];
}
}

Sandbag::Sandbag(Graphics& graphics, int centerX, int centerY)
        : IndestructibleObject(graphics, getBarrelName(), 0, 0, 66, 44, centerX, centerY)
{}

}
