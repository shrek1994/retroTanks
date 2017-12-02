#include "Barrel.hpp"
#include "ObjectOwner.hpp"

namespace Game {

Barrel::Barrel(Graphics& graphics, ObjectOwner& objectOwner, int centerX, int centerY) :
    DestructibleObject(graphics, "res/barrelGreen_side.png", 0, 0, 44, 62, centerX, centerY),
    graphics(graphics),
    objectOwner(objectOwner)
{}

Barrel::~Barrel() {
    //TODO add broken barrel
}


}
