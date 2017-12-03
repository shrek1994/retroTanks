#pragma once

#include <Constants.hpp>
#include "Button.hpp"
#include "InactiveBackground.hpp"
#include "ActiveBackground.hpp"

namespace Menu {

class QuitButton : public Button {
public:
    QuitButton(Graphics& graphics, int centerX, int centerY) :
            Button(std::make_unique<InactiveBackground>(graphics),
                   std::make_unique<ActiveBackground>(graphics),
                   std::make_unique<Object>(graphics, "res/menu/quit.png", 0, 0, 270, 77),
                   centerX, centerY)
    {
        setHeight(BUTTON_HEIGHT);
        setWight(BUTTON_WEIGHT);
    }
};

}