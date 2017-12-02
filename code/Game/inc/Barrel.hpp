#pragma once
#include "DestructibleObject.hpp"

namespace Game {

class ObjectOwner;

class Barrel : public DestructibleObject {
public:
    Barrel(Graphics& graphics, ObjectOwner& objectOwner, int centerX, int centerY);

    ~Barrel() {

    }
private:
    ObjectOwner& objectOwner;
};

}
