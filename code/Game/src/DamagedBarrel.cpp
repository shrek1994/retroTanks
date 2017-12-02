#include "DamagedBarrel.hpp"
#include "ObjectOwner.hpp"
#include "Smoke.hpp"

namespace Game {

DamagedBarrel::DamagedBarrel(Graphics &graphics, ObjectOwner& objectOwner, int centerX, int centerY)
    : DestructibleObject(graphics, "res/barrelGreen_side_damaged.png", 0, 0, 44, 62, centerX, centerY),
      graphics(graphics),
      objectOwner(objectOwner)
{}

DamagedBarrel::~DamagedBarrel() {
    objectOwner.addObject(std::make_unique<Smoke>(graphics, _centerX, _centerY));
}

}
