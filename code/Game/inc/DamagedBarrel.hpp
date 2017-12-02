#pragma once
#include "DestructibleObject.hpp"

namespace Game {

class ObjectOwner;

class DamagedBarrel : public DestructibleObject {
public:
    DamagedBarrel(Graphics& graphics, ObjectOwner& objectOwner, int centerX, int centerY);
    ~DamagedBarrel();

private:
    Graphics& graphics;
    ObjectOwner& objectOwner;
};


}
