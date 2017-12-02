#pragma once
#include "IndestructibleObject.hpp"

namespace Game {

class Tree : public IndestructibleObject {
public:
    Tree(Graphics& graphics, int centerX, int centerY) :
        IndestructibleObject(graphics, "res/treeLarge.png", 0, 0, 98, 107, centerX, centerY) {}

};

}
