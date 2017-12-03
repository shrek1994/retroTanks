#pragma once

#include <Constants.hpp>
#include "Button.hpp"
#include "InactiveBackground.hpp"
#include "ActiveBackground.hpp"

namespace Menu {

class StatisticsButton : public Button {
public:
    StatisticsButton(Graphics& graphics, int centerX, int centerY) :
            Button(std::make_unique<InactiveBackground>(graphics),
                   std::make_unique<ActiveBackground>(graphics),
                   std::make_unique<Object>(graphics, "res/menu/statistics.png", 0, 0, 343, 73),
                   centerX, centerY)
    {
        setHeight(BUTTON_HEIGHT);
        setWight(BUTTON_WEIGHT);
    }
};

}