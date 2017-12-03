#pragma once

#include "Object.hpp"

namespace Menu {

class InactiveBackground : public Object {
public:
    InactiveBackground(Graphics& graphics)
            : Object(graphics, "res/menu/blue_button.png", 0, 0, 190, 45) {}
};

}