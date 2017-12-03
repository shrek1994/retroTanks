#pragma once

#include <Constants.hpp>
#include "Button.hpp"
#include "InactiveBackground.hpp"
#include "ActiveBackground.hpp"

namespace Menu {

class OptionsButton : public Button {
public:
    OptionsButton(Graphics& graphics, int centerX, int centerY) :
            Button(std::make_unique<InactiveBackground>(graphics),
                   std::make_unique<ActiveBackground>(graphics),
                   std::make_unique<Object>(graphics, "res/menu/options.png", 0, 0, 273, 77),
                   centerX, centerY)
    {
        setHeight(BUTTON_HEIGHT);
        setWight(BUTTON_WEIGHT);
    }
};

}