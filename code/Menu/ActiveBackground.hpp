#pragma once

#include "Object.hpp"

namespace Menu {

class ActiveBackground : public Object {
public:
    ActiveBackground(Graphics& graphics)
            : Object(graphics, "res/menu/active_yellow_button.png", 0, 0, 190, 45) {}
};

}